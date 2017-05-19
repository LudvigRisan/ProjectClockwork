// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectClockwork.h"
#include "Bullet.h"
#include "DirectionalTurret.h"


// Sets default values
ADirectionalTurret::ADirectionalTurret()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADirectionalTurret::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADirectionalTurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	shootingTimer += DeltaTime;

	if (shootingTimer > 1 / fireRate) {					//Fire one bullet per direction
		shootingTimer = 0;
		for (int32 i = 0; i < direction.Num(); i++) {
			shoot(direction[i]);
		}
	}
}

void ADirectionalTurret::shoot(FVector dir) {
	UWorld* world = GetWorld();
	if (world) {
		ABullet* bullet = world->SpawnActor<ABullet>(BulletBlueprint, GetActorLocation(), dir.Rotation());
		if (bullet) {
			bullet->launch(dir * projectileSpeed);
		}
	}
}