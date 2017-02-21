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
	
	InputComponent->BindAxis("MoveX", this, &APlayerCharacter::xInput);
	InputComponent->BindAxis("MoveY", this, &APlayerCharacter::yInput);
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
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void APlayerCharacter::xInput(float axis) {
	xIn = axis;
}

void APlayerCharacter::yInput(float axis) {
	yIn = axis;
}

void APlayerCharacter::move(float DeltaTime) {

	movement = { xIn * speed, yIn * speed, 0 };

	UE_LOG(LogTemp, Warning, TEXT("xIn: %f"), this->xIn);

	AddMovementInput(movement, DeltaTime);
}