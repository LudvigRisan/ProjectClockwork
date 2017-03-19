// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectClockwork.h"
#include "AttackPattern.h"


// Sets default values
AAttackPattern::AAttackPattern() {
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAttackPattern::BeginPlay() {
	Super::BeginPlay();

}

// Called every frame
void AAttackPattern::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

}

void AAttackPattern::beginAttack(){}

void AAttackPattern::endAttack(){}
