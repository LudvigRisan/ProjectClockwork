// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "DamageTarget.generated.h"

UCLASS()
class PROJECTCLOCKWORK_API ADamageTarget : public AActor				//Base class for damageable objects (Prefix: DF)
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADamageTarget();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void shoot();												//On getting shot by player

	virtual void hit();													//On gettin hit by player mele attack

	virtual bool other(float amount);									//Other damage sources
	
};
