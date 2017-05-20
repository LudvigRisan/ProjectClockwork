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
	
	

	TArray<AActor*> getplayer;													//Get pointer to the player
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APlayerCharacter::StaticClass(), getplayer);
	player = Cast<APlayerCharacter>(getplayer[0]);

	
	OnActorHit.AddDynamic(this, &ACoalBall::OnOverlap);
	
}

// Called every frame
void ACoalBall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(burning) {
		fireTimer += DeltaTime;
		if (fireTimer >= 1 / fireAmount) {
			ACoalBall::fire();
			fireTimer = 0;
		}
	}

	ACoalBall::move(DeltaTime);

	if (GetActorLocation().Z <= -100) {											//End if the ball has fallen of the stage
		ACoalBall::end();
	}
}

// Called to bind functionality to input
void ACoalBall::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ACoalBall::move(float DeltaTime) {											//Push the ball towards the player, using momentum and physics to create a rubberbanding effect
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
	if (OtherActor->IsA(APlayerCharacter::StaticClass())) {						//On collission with either a valid damage target or the player: damage the target and then run end
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
	if (endAttack) {
		TArray<AActor*> getpattern;
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), AAttackPattern::StaticClass(), getpattern);
		AAttackPattern* pattern = Cast<AAttackPattern>(getpattern[0]);

		if (pattern) {															//End the current attack pattern
			pattern->endAttack();
		}
	}
	Destroy();
}

void ACoalBall::fire() {														//Spawn a bullet (fire) and send it moving in a random direction
	float dir = FMath::FRandRange(0, 360);
	float force = FMath::FRandRange(0, fireSpread);
	FVector fireMove = {sinf(dir) * force, cosf(dir) * force, 0};
	UWorld* world = GetWorld();
	if (world) {
		ABullet* bullet = world->SpawnActor<ABullet>(Blueprint, GetActorLocation() + fireOffset, fireMove.Rotation());
		if (bullet) {
			bullet->launch(fireMove);
		}
	}
}