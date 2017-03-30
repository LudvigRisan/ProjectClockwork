// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "DamageTarget.h"
#include "DoomFurnace.h"
#include "DFBodyHitbox.generated.h"

UCLASS()
class PROJECTCLOCKWORK_API ADFBodyHitbox : public ADamageTarget
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADFBodyHitbox();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void shoot() override;

	virtual bool other(float amount) override;

	UPROPERTY(EditAnywhere)
		float damageAmountShoot;

	UPROPERTY(EditAnywhere)
		float damageMultiplierOther;
	
	ADoomFurnace* boss;

};
