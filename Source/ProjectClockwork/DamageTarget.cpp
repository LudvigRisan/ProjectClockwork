// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectClockwork.h"
#include "DamageTarget.h"


// Sets default values
ADamageTarget::ADamageTarget()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADamageTarget::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADamageTarget::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADamageTarget::shoot() {

}

void ADamageTarget::hit() {

}

bool ADamageTarget::other(float amount) {			//Returns false to tell the damage source that nothing was damaged
	return false;
}