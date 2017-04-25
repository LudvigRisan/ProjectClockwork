// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectClockwork.h"
#include "Bullet.h"

#include "PlayerCharacter.h"
#include "PlayerBullet.h"

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

	if (CollisionBox) {
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

	if (killtimer >= lifespan) {										//Destroy bullet after a certain time
		Destroy();
	}

}

void ABullet::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor *OtherActor,
	UPrimitiveComponent *OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult) {
	if (OtherActor->IsA(APlayerCharacter::StaticClass())) {				//Damage player on hitting
		APlayerCharacter * thePlayer = Cast<APlayerCharacter>(OtherActor);

		if (thePlayer->damage()) {										//Self destruct if it's able to damage the player
			Destroy();
		}
	}																	//destroy on hit if it's had enough time to be launched, ignore other bullets
	else if (killtimer >= 0.1f && !OtherActor->IsA(ABullet::StaticClass())) {
		Destroy();
	}

}

void ABullet::launch(FVector direction) {
	movement = direction;
}

void ABullet::move(float DeltaTime) {
	SetActorLocation(GetActorLocation() + movement * DeltaTime);
}