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

}

void ABullet::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor *OtherActor,
	UPrimitiveComponent *OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult) {
	if (OtherActor->IsA(APlayerCharacter::StaticClass())) {
		APlayerCharacter * thePlayer = Cast<APlayerCharacter>(OtherActor);

		if (thePlayer->damage()) {
			Destroy();
		}
	}

}