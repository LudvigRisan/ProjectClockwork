// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectClockwork.h"
#include "PawnTest.h"


// Sets default values
APawnTest::APawnTest()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APawnTest::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APawnTest::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	AddMovementInput(FVector(1, 0, 0), speed * DeltaTime);

}

// Called to bind functionality to input
void APawnTest::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

