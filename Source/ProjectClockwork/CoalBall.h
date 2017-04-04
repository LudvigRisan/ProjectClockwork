// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "PlayerCharacter.h"
#include "Bullet.h"
#include "CoalBall.generated.h"

UCLASS()
class PROJECTCLOCKWORK_API ACoalBall : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ACoalBall();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void move(float DeltaTime);

	void fire();

	void end();
	
	APlayerCharacter * player = nullptr;

	UShapeComponent * CollisionBox = nullptr;

	float fireTimer = 0;
	
	UPROPERTY(EditAnywhere)
		float speed;

	UPROPERTY(EditAnywhere)
		float damage;

	UPROPERTY(EditAnywhere)
		bool endAttack = true;

	UPROPERTY(EditAnywhere, Category = "Flame")
		bool burning = false;

	UPROPERTY(EditAnywhere, Category = "Flame")
		float fireAmount = 1;

	UPROPERTY(EditAnywhere, Category = "Flame")
		float fireSpread = 1;

	UPROPERTY(EditAnywhere, Category = "Flame")
		TSubclassOf<ABullet> Blueprint;

	UFUNCTION()
		void OnOverlap(AActor * SelfActor, AActor * OtherActor, FVector NormalImpulse, const FHitResult& Hit);
};
