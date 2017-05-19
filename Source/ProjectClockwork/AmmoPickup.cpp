// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectClockwork.h"
#include "AmmoPickup.h"

#include "PlayerCharacter.h"

// Sets default values
AAmmoPickup::AAmmoPickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAmmoPickup::BeginPlay()
{
	Super::BeginPlay();
	
	CollisionBox = this->FindComponentByClass<USphereComponent>();		//For collision

	if (CollisionBox) {													//Set up collission event
		CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &AAmmoPickup::OnOverlap);
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("I need a collider you lazy bum!"));
	}

}

// Called every frame
void AAmmoPickup::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void AAmmoPickup::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor *OtherActor,
	UPrimitiveComponent *OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult) {
	if (OtherActor->IsA(APlayerCharacter::StaticClass())) {			//If the colliding actor is the player, pick up
		APlayerCharacter * thePlayer = Cast<APlayerCharacter>(OtherActor);

		thePlayer->ammo = true;
		if (!infinity) {											//Check if the ammo pickup is one time use only.
			Destroy();
		}
	}
}
