// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectClockwork.h"
#include "PlayerCharacter.h"

#include "PlayerBullet.h"
#include "DamageTarget.h"

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
	

	
	originLocation = GetActorLocation();										//Origin used to respawn player on fall of stage

	APlayerController* MyController = GetWorld()->GetFirstPlayerController();	//For enabling the cursor

	if (MyController) {
		MyController->bShowMouseCursor = true;
		MyController->bEnableClickEvents = true;
	}
	else {

		UE_LOG(LogTemp, Warning, TEXT("Missing playercontroller"));	

	}

	AttackBox = this->FindComponentByClass<USphereComponent>();		//Used for mele attack

	if (AttackBox) {
		AttackBox->OnComponentBeginOverlap.AddDynamic(this, &APlayerCharacter::hitDetect);
		AttackBox->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	} else {
		UE_LOG(LogTemp, Warning, TEXT("I need a collider you lazy bum!"));
	}
}


// Called every frame
void APlayerCharacter::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	if (!dying) {
		if (rolling) {
			APlayerCharacter::rollMove(DeltaTime);
		} else {
			APlayerCharacter::move(DeltaTime);
			APlayerCharacter::trackMouse();
		}

		if (damaged) {																//invulnerable on taking damage
			InvulTimer += DeltaTime;
			if (InvulTimer >= damageInvulTime) {
				damaged = false;
				invulnerable = false;
				InvulTimer = 0;
			}
		}

		if (attacking) {
			meleTimer += DeltaTime;
			if (meleTimer >= meleTime) {
				APlayerCharacter::endHit();
				meleTimer = 0;
			}
		}

		if (GetActorLocation().Z <= 0) {											//Respawn on fall of stage, will add a uproperty variable for
			SetActorLocation(originLocation);										//fall of limit
			APlayerCharacter::damage();
		}



		APlayerCharacter::pointToMouse();
	} else {
		deathTimer += DeltaTime;
		if (deathTimer >= deathDelay) {
			UGameplayStatics::OpenLevel(GetWorld(), FName(*GetWorld()->GetName()));
		}
	}
}


// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	UE_LOG(LogTemp, Warning, TEXT("SetupInput"));

	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAxis("InputX", this, &APlayerCharacter::xInput);		//movement input
	InputComponent->BindAxis("InputY", this, &APlayerCharacter::yInput);
																				//mousebuttons for roll/attack
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

	FVector movement = { xIn, yIn, 0 };											//Make movement vector from input
	movement.Normalize();

	AddMovementInput(movement * DeltaTime * speed);
}


void APlayerCharacter::trackMouse() {
	if (APlayerController* PC = Cast<APlayerController>(GetController()))		//Set cursorLocation to where the cursor is pointing
	{
		FHitResult TraceHitResult;
		PC->GetHitResultUnderCursor(ECC_GameTraceChannel1, true, TraceHitResult);
		cursorLocation = TraceHitResult.Location;

	}
}


void APlayerCharacter::pointToMouse() {											//Rotate player towards mouse
	FVector mouseDist = {cursorLocation.X - GetActorLocation().X, cursorLocation.Y - GetActorLocation().Y, 0};
	mouseRot = mouseDist.Rotation();
	SetActorRotation(mouseRot.Quaternion());
}


bool APlayerCharacter::damage() {												//Damage returns bool to let bullets pass through on no damage taken
	if (!invulnerable) {
		health--;
		UE_LOG(LogTemp, Warning, TEXT("OUCH!"));
		if (health <= 0) {
			APlayerCharacter::die();
		}
		invulnerable = true;													//Start invulnerable time
		damaged = true;
		return true;
	}
	return false;
}


void APlayerCharacter::die() {
	UE_LOG(LogTemp, Warning, TEXT("DED!"));										//Currently resets the map
	dying = true;
}


void APlayerCharacter::roll() {
	if (!rolling) {
		UE_LOG(LogTemp, Warning, TEXT("Swish!"));								//Get the direction of the roll and start rolling
		rollDirection = { cursorLocation.X - GetActorLocation().X, cursorLocation.Y - GetActorLocation().Y, 0 };
		rollDirection.Normalize();

		rolling = true;
		invulnerable = true;
	}
}


void APlayerCharacter::rollMove(float deltaTime) {
	if (rollingTimer >= rollTime) {												//stopp rolling
		rolling = false;
		rollingTimer = 0;
	} else if (rollingTimer >= rollInvulTime && invulnerable && !damaged) {					//Stop the invulnerability towards the end of the roll
		invulnerable = false;

		rollingTimer += deltaTime;
		SetActorLocation(GetActorLocation() + rollDirection * deltaTime * rollSpeed, true);
		//AddMovementInput(rollDirection, deltaTime * rollSpeed);
	} else {																	//The rolling motion
		rollingTimer += deltaTime;

		SetActorLocation(GetActorLocation() + rollDirection * deltaTime * rollSpeed, true);
	}
}


void APlayerCharacter::attack() {
	if (ammo) {																	//Use the ranged attack if the player has ammo,
		APlayerCharacter::shoot();
	} else {																	//Use a mele attack
		APlayerCharacter::hit();
	}
}


void APlayerCharacter::shoot() {
	UE_LOG(LogTemp, Warning, TEXT("Boff!"));
	UWorld* world = GetWorld();
	if (world) {																//Create bullet and set it to move the direction you are pointing.
		FVector direction = { cursorLocation.X - GetActorLocation().X, cursorLocation.Y - GetActorLocation().Y, 0 };
		direction.Normalize();

		APlayerBullet* bullet = world->SpawnActor<APlayerBullet>(BulletBlueprint, GetActorLocation() + bulletOffset, GetActorRotation());

		if (bullet != nullptr) {
			bullet->launch(direction);
		}

		ammo = false;
	}
}


void APlayerCharacter::hit() {													//Function for starting mele attack
	if (AttackBox) {
		AttackBox->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
		attacking = true;
	}
}


void APlayerCharacter::hitDetect(UPrimitiveComponent* OverlappedComponent, AActor *OtherActor,
	UPrimitiveComponent *OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult) {
	UE_LOG(LogTemp, Warning, TEXT("Swing!"));									//Detection for when the mele attack hits
	if (OtherActor->IsA(ADamageTarget::StaticClass())) {
		
		ADamageTarget * hit = Cast<ADamageTarget>(OtherActor);
		hit->hit();
		APlayerCharacter::endHit();
	}
}


void APlayerCharacter::endHit() {												//Finish the mele attack
	if (AttackBox) {
		AttackBox->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		attacking = false;
	}
}