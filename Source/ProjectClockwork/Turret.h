// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "PlayerCharacter.h"
#include "Turret.generated.h"

UCLASS()
class PROJECTCLOCKWORK_API ATurret : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATurret();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
		TSubclassOf<class ABullet> BulletBlueprint;

	void shoot(FVector dir);

	FVector direction = { 0, 0, 0 };

	float shootingTimer = 0;										//Timer used for firerate
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool ready = false;

	void aim();

	UPROPERTY(EditAnywhere)											//What to aim for
		AActor* target;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float fireRate = 1;

	UPROPERTY(EditAnywhere)
		float ActivationSpeed = 1;

	UPROPERTY(EditAnywhere)
		float targetZ = 150;

	UPROPERTY(EditAnywhere)
		float projectileSpeed = 300;

	UPROPERTY(EditAnywhere)											//Where the bullets are spawned in relation to the turret
		FVector bulletOffset;
};
