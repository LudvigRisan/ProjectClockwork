// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "AttackPattern.h"
#include "AP1CoalBall.generated.h"

UCLASS()
class PROJECTCLOCKWORK_API AAP1CoalBall : public AAttackPattern
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAP1CoalBall();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame

	virtual void Tick(float DeltaTime) override;

	virtual void beginAttack() override;

	virtual void endAttack() override;

	UPROPERTY(EditAnywhere)
		FVector StartLocation;

	UPROPERTY(EditAnywhere)
		TSubclassOf<AActor> actor;


};
