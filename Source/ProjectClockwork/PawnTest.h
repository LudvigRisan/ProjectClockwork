// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "PawnTest.generated.h"

UCLASS()
class PROJECTCLOCKWORK_API APawnTest : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APawnTest();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	UPROPERTY(EditAnywhere)
		float speed = 10;
	
};