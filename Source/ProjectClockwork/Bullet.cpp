// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectClockwork.h"
#include "Bullet.h"

#include "PlayerCharacter.h"

// Sets default values
ABullet::ABullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABullet::BeginPlay()
{
	Super::BeginPlay();
	
	CollisionBox = this->FindComponentByClass<USphereComponent>();		//For collision

	if (CollisionBox) {													//Set up collission event
		CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &ABullet::OnOverlap);
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("I need a collider you lazy bum!"));
	}
}

// Called every frame
void ABullet::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	ABullet::move(DeltaTime);

	killtimer += DeltaTime;

	if (killtimer >= lifespan) {										//Destroy bullet after a certain amount of time
		Destroy();
	}

}

void ABullet::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor *OtherActor,
	UPrimitiveComponent *OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult) {
	if (OtherActor->IsA(APlayerCharacter::StaticClass())) {				//If the other actor is a player: run the damage function
		APlayerCharacter * thePlayer = Cast<APlayerCharacter>(OtherActor);

		if (thePlayer->damage()) {										//If the player can take damage: self destruct
			Destroy();
		}
	}																	//If it has had a chance to spawn properly and then collides: self destruct
	else if (killtimer >= 0.1f && !OtherActor->IsA(ABullet::StaticClass())) {
		Destroy();
	}

}

void ABullet::launch(FVector direction) {								//Function used by turret to set the movement of the bullet
	movement = direction;
}

void ABullet::move(float DeltaTime) {
	SetActorLocation(GetActorLocation() + movement * DeltaTime);		//Move based on the given movement vector and delta time
}