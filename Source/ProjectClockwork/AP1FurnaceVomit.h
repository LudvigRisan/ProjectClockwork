// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "AttackPattern.h"
#include "DoomFurnace.h"
#include "AP1FurnaceVomit.generated.h"

UCLASS()
class PROJECTCLOCKWORK_API AAP1FurnaceVomit : public AAttackPattern
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAP1FurnaceVomit();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void aim(float DeltaTime);

	void shoot(FVector dir);

	virtual void beginAttack() override;

	virtual void endAttack() override;

	FVector direction = { 0, 0, 0 };				//Firing direction

	FVector offset = { 0, 0, 0 };					//Bullet offset, dependent on direction, shooting timer, and projectile speed.

	float shootingTimer = 0;						//Timer variable to controll firerate

	bool ready = false;

	ADoomFurnace * boss;

	float wave = 0;									//Variable to controll firing direction

	bool waveDir = false;							//Direction of the rotation of the firing direction

	float age = 0;									//Self destruct timer
	
	UPROPERTY(EditAnywhere)
		float fireRate = 1;							//shots per second

	UPROPERTY(EditAnywhere)
		float projectileSpeed = 300;

	UPROPERTY(EditAnywhere)
		TSubclassOf<class ABullet> BulletBlueprint;
	
	UPROPERTY(EditAnywhere)
		float waveSpeed = 1;						//How far the direction should rotate per shot

	UPROPERTY(EditAnywhere)
		float waveOrigin = 0;						//Initial fire direction and middle of the roating cycle

	UPROPERTY(EditAnywhere)
		float waveWidth = 45;						//How far it should rotate before changing direction

	UPROPERTY(EditAnywhere)
		float lifeTime = 1;
};
