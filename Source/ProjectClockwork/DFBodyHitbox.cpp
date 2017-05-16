// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectClockwork.h"
#include "DFBodyHitbox.h"


// Sets default values
ADFBodyHitbox::ADFBodyHitbox()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADFBodyHitbox::BeginPlay()
{
	Super::BeginPlay();

	TArray<AActor*> getBoss;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ADoomFurnace::StaticClass(), getBoss);
	boss = Cast<class ADoomFurnace>(getBoss[0]);
	
}

// Called every frame
void ADFBodyHitbox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void ADFBodyHitbox::shoot() {
	if (boss) {
		boss->damage(damageAmountShoot);
	}
}

bool ADFBodyHitbox::other(float amount) {
	if (boss) {
		boss->damage(amount * damageMultiplierOther);
		return true;
	} else {
		return false;
	}
}