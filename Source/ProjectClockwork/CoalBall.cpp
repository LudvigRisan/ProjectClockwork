// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectClockwork.h"
#include "CoalBall.h"

#include "DamageTarget.h"
#include "AttackPattern.h"

// Sets default values
ACoalBall::ACoalBall()
{

	
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACoalBall::BeginPlay()
{
	Super::BeginPlay();
	
	

	TArray<AActor*> getplayer;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APlayerCharacter::StaticClass(), getplayer);
	player = Cast<APlayerCharacter>(getplayer[0]);

	
	OnActorHit.AddDynamic(this, &ACoalBall::OnOverlap);
	
}

// Called every frame
void ACoalBall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	ACoalBall::move(DeltaTime);

	if (GetActorLocation().Z <= -100) {
		ACoalBall::end();
	}
}

// Called to bind functionality to input
void ACoalBall::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ACoalBall::move(float DeltaTime) {
	if (player) {
		FVector moveForce = player->GetActorLocation() - GetActorLocation();
		moveForce.Normalize();
		moveForce = moveForce * speed * DeltaTime;
		moveForce.Z = 0;

		UMeshComponent* mover = Cast<UMeshComponent>(RootComponent);
		mover->AddImpulse(moveForce);
	}
}

void ACoalBall::OnOverlap(AActor * SelfActor, AActor * OtherActor, FVector NormalImpulse, const FHitResult& Hit) {
	UE_LOG(LogTemp, Warning, TEXT("BOING!"));
	if (OtherActor->IsA(APlayerCharacter::StaticClass())) {
		if (player->damage()) {
			ACoalBall::end();
		}
	} else if (OtherActor->IsA(ADamageTarget::StaticClass())) {
		ADamageTarget * hit = Cast<ADamageTarget>(OtherActor);
		if (hit->other(damage)) {
			ACoalBall::end();
		}
	}


}

void ACoalBall::end() {
	TArray<AActor*> getpattern;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AAttackPattern::StaticClass(), getpattern);
	AAttackPattern* pattern = Cast<AAttackPattern>(getpattern[0]);

	if (pattern) {
		pattern->endAttack();
	}

	Destroy();
}