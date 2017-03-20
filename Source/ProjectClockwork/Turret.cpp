// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectClockwork.h"
#include "Turret.h"
#include "Bullet.h"


// Sets default values
ATurret::ATurret()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATurret::BeginPlay()
{
	Super::BeginPlay();							//unless given a target, aim for player
	if (!target) {
		TArray<AActor*> getplayer;
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), APlayerCharacter::StaticClass(), getplayer);
		target = getplayer[0];
	}
}

// Called every frame
void ATurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	ATurret::aim();

	shootingTimer += DeltaTime;

	if (shootingTimer > 1 / fireRate) {
		shootingTimer = 0;
		shoot(direction);
	}

}


void ATurret::shoot(FVector dir) {
		UWorld* world = GetWorld();
		if (world) {
			ABullet* bullet = world->SpawnActor<ABullet>(BulletBlueprint, GetActorLocation(), dir.Rotation());
			if (bullet) {
				bullet->launch(dir * projectileSpeed);
			}
		}
}

void ATurret::aim() {
	if (target) {
		direction = target->GetActorLocation() - GetActorLocation();
		direction.Normalize();
		direction.Z = 0;
		SetActorRotation(direction.Rotation());
	}
}