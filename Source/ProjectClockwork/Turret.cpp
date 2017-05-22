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
	Super::BeginPlay();							//unless given a target, aim for the player
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
	if (ready) {
		ATurret::aim();

		shootingTimer += DeltaTime;

		if (shootingTimer > 1 / fireRate) {
			shootingTimer = 0;
			shoot(direction);
		}
	} else {
		SetActorLocation(GetActorLocation() + FVector{ 0, 0, ActivationSpeed * DeltaTime});
		if (GetActorLocation().Z >= targetZ) {
			FVector zSetter = GetActorLocation();
			zSetter.Z = targetZ;
			SetActorLocation(zSetter);
			ready = true;
		}
	}

}


void ATurret::shoot(FVector dir) {
		UWorld* world = GetWorld();
		if (world) {
			ABullet* bullet = world->SpawnActor<ABullet>(BulletBlueprint, GetActorLocation() + GetActorRotation().RotateVector(bulletOffset), dir.Rotation());
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