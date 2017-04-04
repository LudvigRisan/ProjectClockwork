// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "AttackPattern.h"
#include "AmmoPickup.h"
#include "AP1PlacedObjects.generated.h"

USTRUCT(BlueprintType)
struct FObjectGroup {

	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditAnywhere, Category = "Turrets")
		TSubclassOf<class AActor> blueprint;
	
	UPROPERTY(EditAnywhere, Category = "Turrets")
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

	UPROPERTY(EditAnywhere, Category = "Turrets")
		float lifeTime = 1;

	UPROPERTY(EditAnywhere, Category = "Turrets")
		TArray<FObjectGroup> groups;

	UPROPERTY(EditAnywhere, Category = "Pickup")
		bool ammoDrop = false;

	UPROPERTY(EditAnywhere, Category = "Pickup")
		TSubclassOf<class AAmmoPickup> pickupBlueprint;

	UPROPERTY(EditAnywhere, Category = "Pickup")
		FVector ammoLocation;

	TArray<class AActor*> turrets;

	class ADoomFurnace* boss;

	float age;
	
};
