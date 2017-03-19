// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectClockwork.h"
#include "AP1CornerTurret.h"
#include "Turret.h"

// Sets default values
AAP1CornerTurret::AAP1CornerTurret()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAP1CornerTurret::BeginPlay()
{
	Super::BeginPlay();
	AAP1CornerTurret::beginAttack();
}

// Called every frame
void AAP1CornerTurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	age += DeltaTime;											//Lifespan timer
	if (age > lifeTime) {
		AAP1CornerTurret::endAttack();
	}

}

void AAP1CornerTurret::beginAttack() {
	UWorld* world = GetWorld();									//Spawn one turret for each position and store a reference to each
	if (world) {
		for (int i = 0; i < positions.Num(); i++) {
			ATurret * turret = world->SpawnActor<ATurret>(turretBlueprint, positions[i], GetActorRotation());
			turrets.Add(turret);
		}
	}
}

void AAP1CornerTurret::endAttack() {							//Delete all spawned turrets
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
	Destroy();
}