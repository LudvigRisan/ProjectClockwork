// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectClockwork.h"
#include "PlayerBullet.h"
#include "DamageTarget.h"


// Sets default values
APlayerBullet::APlayerBullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayerBullet::BeginPlay()
{
	Super::BeginPlay();
	
	CollisionBox = this->FindComponentByClass<USphereComponent>();		//For collision

	if (CollisionBox) {
		CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &APlayerBullet::OnOverlap);
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("I need a collider you lazy bum!"));
	}


}

// Called every frame
void APlayerBullet::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	if (launched) {										//Don't move before ready
		APlayerBullet::move(DeltaTime);
	}

	age += DeltaTime;
	if (age >= lifespan) {
		Destroy();
	}

}

void APlayerBullet::launch(FVector direction) {
	movement = direction;
	launched = true;
}

void APlayerBullet::move(float DeltaTime) {
	SetActorLocation(GetActorLocation() + (movement * projectileSpeed * DeltaTime), true);
}


void APlayerBullet::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor *OtherActor,
	UPrimitiveComponent *OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult) {
	if (OtherActor->IsA(ADamageTarget::StaticClass())) {
		ADamageTarget * hit = Cast<ADamageTarget>(OtherActor);
		hit->shoot();
		Destroy();
	}
}