// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "PlayerCharacter.h"
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

	void end();
	
	APlayerCharacter * player = nullptr;

	UShapeComponent * CollisionBox = nullptr;
	
	UPROPERTY(EditAnywhere)
		float speed;

	UPROPERTY(EditAnywhere)
		float damage;


	UFUNCTION()
		void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor *OtherActor,
			UPrimitiveComponent *OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult);
};
