// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectClockwork.h"
#include "DoomFurnace.h"

#include "AttackPattern.h"

// Sets default values
ADoomFurnace::ADoomFurnace() {
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADoomFurnace::BeginPlay() {
	Super::BeginPlay();

	health = MaxHealth;

	healthlink->updateHealth(health);

	ADoomFurnace::chooseAttack();
}

// Called every frame
void ADoomFurnace::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

}

void ADoomFurnace::chooseAttack() {
	if (health > stageTwoLimit) {
		bool randomCheck = false;
		while (!randomCheck) {
			int32 randomselect = rand() % stageOneAttacks.Num();
			if (randomselect != lastAttack) {
				randomCheck = true;
				lastAttack = randomselect;
				UWorld* world = GetWorld();
				if (world) {
					world->SpawnActor<AAttackPattern>(stageOneAttacks[randomselect], GetActorLocation(), GetActorRotation());
				}
			}
		}
	} else if (health > stageThreeLimit) {
		bool randomCheck = false;
		while (!randomCheck) {
			int32 randomselect = rand() % stageTwoAttacks.Num();
			if (randomselect != lastAttack) {
				randomCheck = true;
				lastAttack = randomselect;
				UWorld* world = GetWorld();
				if (world) {
					world->SpawnActor<AAttackPattern>(stageTwoAttacks[randomselect], GetActorLocation(), GetActorRotation());
				}
			}
		}
	} else {
		bool randomCheck = false;
		while (!randomCheck) {
			int32 randomselect = rand() % stageThreeAttacks.Num();
			if (randomselect != lastAttack) {
				randomCheck = true;
				lastAttack = randomselect;
				UWorld* world = GetWorld();
				if (world) {
					world->SpawnActor<AAttackPattern>(stageThreeAttacks[randomselect], GetActorLocation(), GetActorRotation());
				}
			}
		}

	}
}

void ADoomFurnace::damage(float amount) {
	health -= amount;
	healthlink->updateHealth(health);
	if (health <= 0) {
		diePlease();
	}
}

void ADoomFurnace::diePlease() {

}