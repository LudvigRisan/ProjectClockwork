// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "AttackPattern.h"
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

	UPROPERTY(EditAnywhere)
		float lifespan = 1;

	UPROPERTY(EditAnywhere)
		TSubclassOf<class ATurret> turretBlueprint;

	UPROPERTY(EditAnywhere)
		TArray<FVector> positions;

	TArray<class ATurret*> turrets;

	float age;
};
