// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectClockwork.h"
#include "DFMelePipe.h"


// Sets default values
ADFMelePipe::ADFMelePipe()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADFMelePipe::BeginPlay()
{
	Super::BeginPlay();

	TArray<AActor*> getBoss;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ADoomFurnace::StaticClass(), getBoss);
	boss = Cast<class ADoomFurnace>(getBoss[0]);

	TArray<AActor*> getHealth;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABossHealthLink::StaticClass(), getHealth);
	health = Cast<class ABossHealthLink>(getHealth[0]);
	
}

// Called every frame
void ADFMelePipe::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADFMelePipe::hit() {
	if (boss) {
		boss->damage(damageAmount * health->bossHealth);
		Destroy();
	}
}