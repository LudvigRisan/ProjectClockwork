// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "DirectionalTurret.generated.h"

UCLASS()
class PROJECTCLOCKWORK_API ADirectionalTurret : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADirectionalTurret();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;



	void shoot(FVector dir);

	UPROPERTY(EditAnywhere)
		TSubclassOf<class ABullet> BulletBlueprint;
	
	UPROPERTY(EditAnywhere)
		float fireRate = 1;

	UPROPERTY(EditAnywhere)
		float projectileSpeed = 300;

	UPROPERTY(EditAnywhere)							//Array of directions, one bullet will be fired per direction
		TArray<FVector> direction;

	float shootingTimer = 0;						//Timer to controll firerate
};
