// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectClockwork.h"
#include "AP1PlacedObjects.h"

#include "DoomFurnace.h"

// Sets default values
AAP1PlacedObjects::AAP1PlacedObjects()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAP1PlacedObjects::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAP1PlacedObjects::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	age += DeltaTime;											//Lifespan timer
	if (age > lifeTime) {
		AAP1PlacedObjects::endAttack();
	}
}

void AAP1PlacedObjects::beginAttack() {
	UWorld* world = GetWorld();									//Spawn one turret for each position and store a reference to each
	if (world) {
		for (int i = 0; i < groups.Num(); i++) {
				for (int32 j = 0; j < groups[i].locations.Num(); j++) {
				AActor * turret = world->SpawnActor<AActor>(groups[i].blueprint, groups[i].locations[j], GetActorRotation());
				turrets.Add(turret);
			}
		}
	}
}

void AAP1PlacedObjects::endAttack() {							//Delete all spawned turrets
	for (int i = 0; i < turrets.Num(); i++) {
		if (turrets[i]) {
			turrets[i]->Destroy();
		}
	}

	if (ammoDrop) {												//Spawn an ammo pickup if called for
		UWorld* world = GetWorld();
		if (world) {
			world->SpawnActor<AAmmoPickup>(pickupBlueprint, ammoLocation, GetActorRotation());
		}
	}

	TArray<AActor*> getBoss;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ADoomFurnace::StaticClass(), getBoss);
	boss = Cast<class ADoomFurnace>(getBoss[0]);
	boss->chooseAttack();
	Destroy();
}