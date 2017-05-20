// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "AttackPattern.h"
#include "AmmoPickup.h"
#include "AP1PlacedObjects.generated.h"

USTRUCT(BlueprintType)
struct FObjectGroup {													//Struct containing information about what to spawn where

	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditAnywhere, Category = "Turrets")						//What object should be spawned
		TSubclassOf<class AActor> blueprint;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Turrets")	//What locations should it be spawned (Adding multiple locations places one object on each location)
		TArray<FVector> locations;
};

UCLASS()
class PROJECTCLOCKWORK_API AAP1PlacedObjects : public AAttackPattern
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAP1PlacedObjects();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	

	virtual void beginAttack() override;

	virtual void endAttack() override;

	UPROPERTY(EditAnywhere, Category = "Turrets")						//Should the attack stop after a certain amount of time?
		bool timed = true;

	UPROPERTY(EditAnywhere, Category = "Turrets")						//How long should the attack last for
		float lifeTime = 1;

	UPROPERTY(EditAnywhere, Category = "Turrets")						//Array containing the structs, allowing you to select multiple object types and have each of them
		TArray<FObjectGroup> groups;									//spawn in multiple locations

	UPROPERTY(EditAnywhere, Category = "Pickup")						//Should the attack drop a piece of ammo on completion?
		bool ammoDrop = false;

	UPROPERTY(EditAnywhere, Category = "Pickup")						//Object type of the ammo pickup
		TSubclassOf<class AAmmoPickup> pickupBlueprint;

	UPROPERTY(EditAnywhere, Category = "Pickup")						//Where the pickup should spawn
		FVector ammoLocation;

	TArray<class AActor*> turrets;										//Array of pointers to all spawned parts for the attack, used for removing the parts

	class ADoomFurnace* boss;

	float age;															//Self destruct timer
	
};
