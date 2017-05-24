// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "DamageTarget.h"
#include "DoomFurnace.h"
#include "BossHealthLink.h"
#include "DFMelePipe.generated.h"

UCLASS()
class PROJECTCLOCKWORK_API ADFMelePipe : public ADamageTarget
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADFMelePipe();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void hit() override;

	ADoomFurnace* boss;

	ABossHealthLink* health;						//Used to reduce the damage taken based on the bosses remaining health

	UPROPERTY(EditAnywhere)
		float damageAmount;
	
	UPROPERTY(EditAnywhere)
		TSubclassOf<AActor> broken;
};
