// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "DamageTarget.h"
#include "DoomFurnace.h"
#include "DFBodyHitbox.generated.h"

UCLASS()
class PROJECTCLOCKWORK_API ADFBodyHitbox : public ADamageTarget		//Damage hitbox for the main body of the first boss
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

	UPROPERTY(EditAnywhere)											//How much damage should be dealt when shot by the player
		float damageAmountShoot;

	UPROPERTY(EditAnywhere)											//Multiplyer for damage dealt by other sources
		float damageMultiplierOther;
	
	ADoomFurnace* boss;

};
