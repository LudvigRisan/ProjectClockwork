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

	FVector direction = { 0, 0, 0 };

	FVector offset = { 0, 0, 0 };

	float shootingTimer = 0;

	bool ready = false;

	ADoomFurnace * boss;

	float wave = 0;

	bool waveDir = false;

	float age = 0;
	
	UPROPERTY(EditAnywhere)
		float fireRate = 1;

	UPROPERTY(EditAnywhere)
		float projectileSpeed = 300;

	UPROPERTY(EditAnywhere)
		TSubclassOf<class ABullet> BulletBlueprint;
	
	UPROPERTY(EditAnywhere)
		float waveSpeed = 1;

	UPROPERTY(EditAnywhere)
		float waveOrigin = 0;

	UPROPERTY(EditAnywhere)
		float waveWidth = 45;

	UPROPERTY(EditAnywhere)
		float lifeTime = 1;
};
