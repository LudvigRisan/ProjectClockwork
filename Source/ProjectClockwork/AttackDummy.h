// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "DamageTarget.h"
#include "AttackDummy.generated.h"

UCLASS()
class PROJECTCLOCKWORK_API AAttackDummy : public ADamageTarget
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAttackDummy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void shoot() override;

	virtual void hit() override;

	virtual bool other(float amount) override;
	
};
