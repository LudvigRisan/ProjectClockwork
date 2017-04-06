// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "BossHealthLink.h"
#include "DoomFurnace.generated.h"

UCLASS()
class PROJECTCLOCKWORK_API ADoomFurnace : public AActor
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

	UPROPERTY(EditAnywhere, Category = "Life")
		float MaxHealth = 1;

	UPROPERTY(EditAnywhere, Category = "Attacks")
		float attackDelay = 1;

	UPROPERTY(EditAnywhere, Category = "Attacks")
		TArray<TSubclassOf<class AAttackPattern>> stageOneAttacks;

	UPROPERTY(EditAnywhere, Category = "Attacks")
		float stageTwoLimit = 1;

	UPROPERTY(EditAnywhere, Category = "Attacks")
		TArray<TSubclassOf<class AAttackPattern>> stageTwoAttacks;

	UPROPERTY(EditAnywhere, Category = "Attacks")
		float stageThreeLimit = 1;

	UPROPERTY(EditAnywhere, Category = "Attacks")
		TArray<TSubclassOf<class AAttackPattern>> stageThreeAttacks;

	float health = 99999999;

	float attackTimer = 0;

	int32 lastAttack = 500;

	bool loadAttack = false;

	UPROPERTY(EditAnywhere)
		ABossHealthLink * healthlink;

	void chooseAttack();

	void damage(float amount);

	void startAttack();

	void diePlease();
};
