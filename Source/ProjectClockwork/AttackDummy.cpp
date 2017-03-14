// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectClockwork.h"
#include "AttackDummy.h"


// Sets default values
AAttackDummy::AAttackDummy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAttackDummy::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAttackDummy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

