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

	
	FVector cursorLocation = { 0, 0, 0 };
	FVector rollDirection = { 0, 0, 0 };
	FVector originLocation;

	float xIn = 0;
	float yIn = 0;
	float rollingTimer = 0;
	float InvulTimer = 0;

	bool invulnerable = false;
	bool rolling = false;
	bool ammo = true;
	bool damaged = false;

	UPROPERTY(EditAnywhere, Category = "PlayerMovement")
		float speed = 1;

	UPROPERTY(EditAnywhere, Category = "PlayerMovement")
		float rollSpeed = 1;

	UPROPERTY(EditAnywhere, Category = "PlayerMovement")
		float rollTime = 1;

	UPROPERTY(EditAnywhere, Category = "PlayerMovement")
		float rollInvulTime = 1;

	UPROPERTY(EditAnywhere, Category = "Life")
		int health = 3;

	UPROPERTY(EditAnywhere, Category = "Life")
		float damageInvulTime = 1;

	UPROPERTY(EditAnywhere)
		TSubclassOf<class APlayerBullet> BulletBlueprint;

	UPROPERTY(EditAnywhere)
		FVector bulletOffset = { 0, 0, 0 };

	void xInput(float axis);

	void yInput(float axis);
	
	void move(float DeltaTime);

	void trackMouse();

	void pointToMouse();

	bool damage();
	
	void die();

	void roll();

	void rollMove(float deltaTime);

	void attack();

	void shoot();

	void hit();
};
