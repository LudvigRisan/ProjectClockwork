// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectClockwork.h"
#include "PlayerCharacter.h"


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
}

// Called every frame
void APlayerCharacter::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	APlayerCharacter::move(DeltaTime);

	
}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	UE_LOG(LogTemp, Warning, TEXT("SetupInput"));

	Super::SetupPlayerInputComponent(PlayerInputComponent);

	

	InputComponent->BindAxis("InputX", this, &APlayerCharacter::xInput);
	InputComponent->BindAxis("InputY", this, &APlayerCharacter::yInput);
}

void APlayerCharacter::xInput(float axis) {
	xIn = axis;
}

void APlayerCharacter::yInput(float axis) {
	yIn = axis;
}

void APlayerCharacter::move(float DeltaTime) {

	targetMovement = { xIn, yIn, 0 };
	targetMovement.Normalize();
	
	movement = {FMath::Lerp(movement.X, targetMovement.X, acelleration * DeltaTime), FMath::Lerp(movement.Y, targetMovement.Y, acelleration * DeltaTime), 0};
	

	AddMovementInput(movement, DeltaTime * speed);
}