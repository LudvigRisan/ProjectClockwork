// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "PlayerCharacter.h"
#include "Bullet.h"
#include "CoalBall.generated.h"

UCLASS()
class PROJECTCLOCKWORK_API ACoalBall : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ACoalBall();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void move(float DeltaTime);

	void fire();								//Used if the coalball should leave a firetrail

	void end();
	
	APlayerCharacter * player = nullptr;

	UShapeComponent * CollisionBox = nullptr;

	float fireTimer = 0;						//Timer used to controll how often the coalball leaves fire (if enabled
	
	UPROPERTY(EditAnywhere)						//The amount of force applied to the coalball each frame
		float speed;

	UPROPERTY(EditAnywhere)						//How much the coal ball should damage the boss if it hits
		float damage;

	UPROPERTY(EditAnywhere)						//Should the coalball stop the current attackpattern on ending?
		bool endAttack = true;

	UPROPERTY(EditAnywhere, Category = "Flame")	//Should it leave a firetrail?
		bool burning = false;

	UPROPERTY(EditAnywhere, Category = "Flame")	//How often should it spawn fire
		float fireAmount = 1;

	UPROPERTY(EditAnywhere, Category = "Flame")	//How much should the fire spread out
		float fireSpread = 1;
	
	UPROPERTY(EditAnywhere, Category = "Flame")	//Where in relation to the coalball should the fire spawn
		FVector fireOffset;

	UPROPERTY(EditAnywhere, Category = "Flame")	
		TSubclassOf<ABullet> Blueprint;

	UFUNCTION()
		void OnOverlap(AActor * SelfActor, AActor * OtherActor, FVector NormalImpulse, const FHitResult& Hit);
};
