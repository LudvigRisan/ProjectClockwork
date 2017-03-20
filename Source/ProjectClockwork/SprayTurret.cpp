// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectClockwork.h"
#include "SprayTurret.h"

#include "Bullet.h"

// Sets default values
ASprayTurret::ASprayTurret()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASprayTurret::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASprayTurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	shootingTimer += DeltaTime;
	while (shootingTimer >= (1/fireRate)) {
		ASprayTurret::aim();
		ASprayTurret::shoot(direction);
		shootingTimer -= (1 / fireRate);
	}

}

void ASprayTurret::aim() {
	float randRot = FMath::FRand() * 360;
	float randSpeed = FMath::FRandRange(randSpeedMin, randSpeedMax);
	direction = { sinf(randRot) * randSpeed, cosf(randRot) * randSpeed, 0 };
}

void ASprayTurret::shoot(FVector dir) {
	UWorld* world = GetWorld();
	if (world) {
		ABullet* bullet = world->SpawnActor<ABullet>(BulletBlueprint, GetActorLocation(), dir.Rotation());
		if (bullet) {
			bullet->launch(dir * projectileSpeed);
		}
	}
}