// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "DoorController.h"
#include "DoorStateTemplate.generated.h"

UCLASS()
class PROJECTCLOCKWORK_API ADoorStateTemplate : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADoorStateTemplate();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	ADoorController * controller;

	UPROPERTY(EditAnywhere)
		TArray<int32> doors;
	
};
