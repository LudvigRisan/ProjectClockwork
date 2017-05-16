// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectClockwork.h"
#include "FireBlob.h"


// Sets default values
AFireBlob::AFireBlob()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFireBlob::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFireBlob::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	movement.X = FMath::Lerp(movement.X, float(0), speedDecay * DeltaTime);
	movement.Y = FMath::Lerp(movement.Y, float(0), speedDecay * DeltaTime);
	movement.Z = FMath::Lerp(movement.Z, float(0), speedDecay * DeltaTime);
}

