// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectClockwork.h"
#include "AP1FurnaceVomit.h"

#include "Bullet.h"

// Sets default values
AAP1FurnaceVomit::AAP1FurnaceVomit()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAP1FurnaceVomit::BeginPlay()
{
	Super::BeginPlay();
	

	AAP1FurnaceVomit::beginAttack();
}

// Called every frame
void AAP1FurnaceVomit::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (ready) {
		shootingTimer += DeltaTime;
		for (shootingTimer; shootingTimer >= 1 / fireRate; shootingTimer -= 1/fireRate) {
			AAP1FurnaceVomit::aim(DeltaTime);
			AAP1FurnaceVomit::shoot(direction);
		}
	}

	age += DeltaTime;
	if (age >= lifeTime) {
		AAP1FurnaceVomit::endAttack();
	}

}

void AAP1FurnaceVomit::beginAttack() {
	TArray<AActor*> getBoss;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ADoomFurnace::StaticClass(), getBoss);
	boss = Cast<class ADoomFurnace>(getBoss[0]);

	FVector loc = {boss->GetActorLocation().X, boss->GetActorLocation().Y, 150 };

	SetActorLocation(loc);

	wave = waveOrigin;

	ready = true;
}

void AAP1FurnaceVomit::endAttack() {
	boss->chooseAttack();
	Destroy();
}

void AAP1FurnaceVomit::aim(float DeltaTime) {
	if (waveDir) {
		wave += waveSpeed * DeltaTime;
		if (wave >= waveOrigin + waveWidth) {
			waveDir = false;
		}
	} else {
		wave -= waveSpeed * DeltaTime;
		if (wave <= waveOrigin - waveWidth) {
			waveDir = true;
		}
	}
	direction = {sinf(wave), cosf(wave), 0};
	offset = direction * shootingTimer * projectileSpeed;
}

void AAP1FurnaceVomit::shoot(FVector dir) {
	UWorld* world = GetWorld();
	if (world) {
		ABullet* bullet = world->SpawnActor<ABullet>(BulletBlueprint, GetActorLocation() + offset, dir.Rotation());
		if (bullet) {
			bullet->launch(dir * projectileSpeed);
		}
	}
}