// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectClockwork.h"
#include "LoadLevelTrigger.h"

#include "PlayerCharacter.h"
// Sets default values
ALoadLevelTrigger::ALoadLevelTrigger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ALoadLevelTrigger::BeginPlay()
{
	Super::BeginPlay();
	

	CollisionBox = this->FindComponentByClass<UCapsuleComponent>();		//For collision

	if (CollisionBox) {													//Set up collission event
		CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &ALoadLevelTrigger::OnOverlap);
	} else {
		UE_LOG(LogTemp, Warning, TEXT("I need a collider you lazy bum!"));
	}
}

// Called every frame
void ALoadLevelTrigger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALoadLevelTrigger::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor *OtherActor,
	UPrimitiveComponent *OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult) {
	if (OtherActor->IsA(APlayerCharacter::StaticClass())) {
		UGameplayStatics::OpenLevel(GetWorld(), mapName);

	}
}