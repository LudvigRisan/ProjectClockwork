// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectClockwork.h"
#include "DoomFurnace.h"


// Sets default values
ADoomFurnace::ADoomFurnace()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADoomFurnace::BeginPlay()
{
	Super::BeginPlay();

	health = MaxHealth;
	
}

// Called every frame
void ADoomFurnace::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADoomFurnace::chooseAttack() {
	if (health > stageTwoLimit) {
		bool randomCheck = false;
		do {
			int32 randomselect = rand() % stageOneAttacks.Num();
		} while (!randomCheck);
	}
	else if (health > stageThreeLimit) {

	}
	else {

	}
}

void ADoomFurnace::damage(float amount) {
	health -= amount;
	if (health <= 0) {
		diePlease();
	}
}

void ADoomFurnace::diePlease() {

}