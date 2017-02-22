// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"

UCLASS()
class PROJECTCLOCKWORK_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void xInput(float axis);

	void yInput(float axis);

	void move(float DeltaTime);
	
	FVector movement = { 0, 0, 0 };
	FVector targetMovement = { 0, 0, 0 };

	float xIn = 0;
	float yIn = 0;

	UPROPERTY(EditAnywhere)
		float speed = 1;

	UPROPERTY(EditAnywhere)
		float acelleration = 1;

	
};
