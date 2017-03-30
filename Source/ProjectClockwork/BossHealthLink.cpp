// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectClockwork.h"
#include "BossHealthLink.h"


// Sets default values
ABossHealthLink::ABossHealthLink()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABossHealthLink::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABossHealthLink::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABossHealthLink::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


void ABossHealthLink::updateHealth(float health) {
	bossHealth = health;
}