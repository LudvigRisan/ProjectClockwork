// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectClockwork.h"
#include "AP1CoalBall.h"

#include "DoomFurnace.h"

// Sets default values
AAP1CoalBall::AAP1CoalBall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAP1CoalBall::BeginPlay()
{
	Super::BeginPlay();
	AAP1CoalBall::beginAttack();
}

// Called every frame
void AAP1CoalBall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AAP1CoalBall::beginAttack() {
	UWorld* world = GetWorld();									//Spawn one turret for each position and store a reference to each

	if (world) {
		world->SpawnActor<AActor>(actor, StartLocation, GetActorRotation());
	}
}

void AAP1CoalBall::endAttack() {

	TArray<AActor*> getBoss;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ADoomFurnace::StaticClass(), getBoss);
	ADoomFurnace * boss = Cast<class ADoomFurnace>(getBoss[0]);
	boss->chooseAttack();
	Destroy();

}