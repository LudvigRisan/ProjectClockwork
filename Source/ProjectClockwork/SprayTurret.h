// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "SprayTurret.generated.h"

UCLASS()
class PROJECTCLOCKWORK_API ASprayTurret : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASprayTurret();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	void Tick(float DeltaTime);

	void aim();
	
	void shoot(FVector dir);

	FVector direction = { 0, 0, 0 };

	float shootingTimer = 0;

	UPROPERTY(EditAnywhere)											//Limits on how fast the bullets can move (controlling a randomizer)
		float randSpeedMax;

	UPROPERTY(EditAnywhere)
		float randSpeedMin;
	
	UPROPERTY(EditAnywhere)
		float fireRate = 1;

	UPROPERTY(EditAnywhere)											//Base speed of bullets
		float projectileSpeed = 300;

	UPROPERTY(EditAnywhere)
		TSubclassOf<class ABullet> BulletBlueprint;

};
