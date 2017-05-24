// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectClockwork.h"
#include "DoorStateTemplate.h"


// Sets default values
ADoorStateTemplate::ADoorStateTemplate()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADoorStateTemplate::BeginPlay()
{
	Super::BeginPlay();
	
	TArray<AActor*> getcontroller;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ADoorController::StaticClass(), getcontroller);
	controller = Cast<ADoorController>(getcontroller[0]);

	for (int32 i = 0; i < doors.Num(); i++) {
		controller->openDoor(doors[i]);
	}

}

// Called every frame
void ADoorStateTemplate::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADoorStateTemplate::EndPlay(const EEndPlayReason::Type EndPlayReason) {

	for (int32 i = 0; i < doors.Num(); i++) {
		controller->closeDoor(doors[i]);
	}

}