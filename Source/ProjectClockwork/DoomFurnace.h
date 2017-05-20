// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "BossHealthLink.h"
#include "DoomFurnace.generated.h"

UCLASS()
class PROJECTCLOCKWORK_API ADoomFurnace : public AActor						//Controller for the boss
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ADoomFurnace();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = "Life")								//How much health the boss starts with
		float MaxHealth = 1;

	UPROPERTY(EditAnywhere, Category = "Attacks")							//How long it should wait before launching an attack
		float attackDelay = 1;

	UPROPERTY(EditAnywhere, Category = "Attacks")							//List of attacks for the first part of the fight
		TArray<TSubclassOf<class AAttackPattern>> stageOneAttacks;

	UPROPERTY(EditAnywhere, Category = "Attacks")							//At what point does the second stage start
		float stageTwoLimit = 1;

	UPROPERTY(EditAnywhere, Category = "Attacks")							//What attacks are available for the second stage
		TArray<TSubclassOf<class AAttackPattern>> stageTwoAttacks;

	UPROPERTY(EditAnywhere, Category = "Attacks")							//When does the third stage start
		float stageThreeLimit = 1;

	UPROPERTY(EditAnywhere, Category = "Attacks")							//What attacks are available for the third stage
		TArray<TSubclassOf<class AAttackPattern>> stageThreeAttacks;

	float health = 99999999;												//Health is set ot of normal range to begin with to prevent certain issues

	float attackTimer = 0;

	int32 lastAttack = 500;													//Remembers the last used attack to prevent launching the same attack multiple times

	bool loadAttack = false;												//if the timmer for the next attack should count up

	UPROPERTY(EditAnywhere)													//pointer to the health link object used by some other parts
		ABossHealthLink * healthlink;

	void chooseAttack();													//Start the timer for the next attack

	void damage(float amount);

	void startAttack();														//Launch the next attack

	void diePlease();
};
