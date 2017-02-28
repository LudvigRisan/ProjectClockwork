// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectClockwork.h"
#include "PlayerCharacter.h"

#include "PlayerBullet.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	UE_LOG(LogTemp, Warning, TEXT("BeginPlay"));

	


	APlayerController* MyController = GetWorld()->GetFirstPlayerController();

	if (MyController) {
		MyController->bShowMouseCursor = true;
		MyController->bEnableClickEvents = true;
	}
	else {

		UE_LOG(LogTemp, Warning, TEXT("Missing playercontroller"));

	}
}

// Called every frame
void APlayerCharacter::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	if (rolling) {
		APlayerCharacter::rollMove(DeltaTime);
	} else {
		APlayerCharacter::move(DeltaTime);
	}

	if (damaged) {
		InvulTimer += DeltaTime;
		if (InvulTimer >= damageInvulTime) {
			damaged = false;
			invulnerable = false;
			InvulTimer = 0;
		}
	}

	APlayerCharacter::trackMouse();

	APlayerCharacter::pointToMouse();

}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	UE_LOG(LogTemp, Warning, TEXT("SetupInput"));

	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAxis("InputX", this, &APlayerCharacter::xInput);
	InputComponent->BindAxis("InputY", this, &APlayerCharacter::yInput);

	InputComponent->BindAction("Attack", IE_Pressed, this, &APlayerCharacter::attack);
	InputComponent->BindAction("Roll", IE_Pressed, this, &APlayerCharacter::roll);
}

void APlayerCharacter::xInput(float axis) {
	xIn = axis;
}

void APlayerCharacter::yInput(float axis) {
	yIn = axis;
}

void APlayerCharacter::move(float DeltaTime) {

	FVector movement = { xIn, yIn, 0 };
	

	AddMovementInput(movement * DeltaTime * speed);
}

void APlayerCharacter::trackMouse() {
	if (APlayerController* PC = Cast<APlayerController>(GetController()))
	{
		FHitResult TraceHitResult;
		PC->GetHitResultUnderCursor(ECC_GameTraceChannel1, true, TraceHitResult);
		cursorLocation = TraceHitResult.Location;

	}
}

void APlayerCharacter::pointToMouse() {
	FVector mouseDist = {cursorLocation.X - GetActorLocation().X, cursorLocation.Y - GetActorLocation().Y, 0};
	FRotator mouseRot = mouseDist.Rotation();
	SetActorRotation(mouseRot.Quaternion());
}

bool APlayerCharacter::damage() {
	if (!invulnerable) {
		health--;
		UE_LOG(LogTemp, Warning, TEXT("OUCH!"));
		if (health <= 0) {
			APlayerCharacter::die();
		}
		invulnerable = true;
		damaged = true;
		return true;
	}
	return false;
}

void APlayerCharacter::die() {
	UE_LOG(LogTemp, Warning, TEXT("DED!"));
}

void APlayerCharacter::roll() {
	if (!rolling) {
		UE_LOG(LogTemp, Warning, TEXT("Swish!"));
		rollDirection = { cursorLocation.X - GetActorLocation().X, cursorLocation.Y - GetActorLocation().Y, 0 };
		rollDirection.Normalize();

		rolling = true;
		invulnerable = true;
	}
}

void APlayerCharacter::rollMove(float deltaTime) {
	if (rollingTimer >= rollTime) {
		rolling = false;
		rollingTimer = 0;
	} else if (rollingTimer >= rollInvulTime && invulnerable) {
		invulnerable = false;

		rollingTimer += deltaTime;
		SetActorLocation(GetActorLocation() + rollDirection * deltaTime * rollSpeed, true);
		//AddMovementInput(rollDirection, deltaTime * rollSpeed);
	} else {
		rollingTimer += deltaTime;

		SetActorLocation(GetActorLocation() + rollDirection * deltaTime * rollSpeed, true);
	}
}

void APlayerCharacter::attack() {
	if (ammo) {
		APlayerCharacter::shoot();
	} else {
		APlayerCharacter::hit();
	}
}

void APlayerCharacter::shoot() {
	UE_LOG(LogTemp, Warning, TEXT("Boff!"));
	UWorld* world = GetWorld();
	if (world) {
		FVector direction = { cursorLocation.X - GetActorLocation().X, cursorLocation.Y - GetActorLocation().Y, 0 };
		direction.Normalize();

		APlayerBullet* bullet = world->SpawnActor<APlayerBullet>(BulletBlueprint, GetActorLocation() + bulletOffset, GetActorRotation());

		bullet->launch(direction);

		ammo = false;
	}
}

void APlayerCharacter::hit() {
	UE_LOG(LogTemp, Warning, TEXT("Swing!"));
}