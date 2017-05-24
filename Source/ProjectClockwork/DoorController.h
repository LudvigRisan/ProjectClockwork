// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "DoorController.generated.h"

UCLASS()
class PROJECTCLOCKWORK_API ADoorController : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADoorController();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<bool> doorOpenState;
	
	void openDoor(int32 index);

	void closeDoor(int32 index);
	
	bool running = false;
};
