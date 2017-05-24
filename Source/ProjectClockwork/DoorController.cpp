// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectClockwork.h"
#include "DoorController.h"


// Sets default values
ADoorController::ADoorController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADoorController::BeginPlay()
{
	Super::BeginPlay();
	
	running = true;
}

// Called every frame
void ADoorController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADoorController::openDoor(int32 index) {
	if (running) {
		if (doorOpenState.IsValidIndex(index)) {
			doorOpenState[index] = true;
		}
	}
}

void ADoorController::closeDoor(int index) {
	if (running) {
		if (doorOpenState.IsValidIndex(index)) {
			doorOpenState[index] = false;
		}
	}
}