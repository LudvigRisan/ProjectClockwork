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
	AAP1PlacedObjects::beginAttack();
}

// Called every frame
void AAP1PlacedObjects::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	if (timed) {
		age += DeltaTime;											//Lifespan timer
		if (age > lifeTime) {
			AAP1PlacedObjects::endAttack();
		}
	}
}

void AAP1PlacedObjects::beginAttack() {
	UWorld* world = GetWorld();									//Spawn one of the specified object type at every specified location
	if (world) {												//for every instance of the Object group struct and add them to the array of
		for (int i = 0; i < groups.Num(); i++) {				//pointers
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

	TArray<AActor*> getBoss;									//Tell the boss to launch its next attack
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ADoomFurnace::StaticClass(), getBoss);
	boss = Cast<class ADoomFurnace>(getBoss[0]);
	boss->chooseAttack();
	Destroy();
}