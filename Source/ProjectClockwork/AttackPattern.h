// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "AttackPattern.generated.h"

UCLASS()
class PROJECTCLOCKWORK_API AAttackPattern : public AActor				//Base class for attack patterns (Prefix AP[boss number])
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AAttackPattern();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void beginAttack();

	virtual void endAttack();

	
};
