// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "AttackPattern.h"
#include "AmmoPickup.h"
#include "AP1CornerTurret.generated.h"

UCLASS()
class PROJECTCLOCKWORK_API AAP1CornerTurret : public AAttackPattern
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAP1CornerTurret();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	virtual void beginAttack() override;

	virtual void endAttack() override;

	UPROPERTY(EditAnywhere, Category = "Turrets")
		float lifeTime = 1;

	UPROPERTY(EditAnywhere, Category = "Turrets")
		TSubclassOf<class AActor> turretBlueprint;

	UPROPERTY(EditAnywhere, Category = "Turrets")
		TArray<FVector> positions;

	UPROPERTY(EditAnywhere, Category = "Pickup")
		bool ammoDrop = false;

	UPROPERTY(EditAnywhere, Category = "Pickup")
		TSubclassOf<class AAmmoPickup> pickupBlueprint;

	UPROPERTY(EditAnywhere, Category = "Pickup")
		FVector ammoLocation;

	TArray<class AActor*> turrets;

	class ADoomFurnace* boss;

	float age;
};
