// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "PlayerBullet.generated.h"

UCLASS()
class PROJECTCLOCKWORK_API APlayerBullet : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlayerBullet();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;
	
	FVector movement;
	
	UShapeComponent* CollisionBox = nullptr;

	bool launched = false;

	float age = 0;

	UPROPERTY(EditAnywhere)
		float projectileSpeed = 1;

	UPROPERTY(EditAnywhere)
		float lifespan = 20;

	void launch(FVector direction);
	
	void move(float DeltaTime);

	UFUNCTION()				//For collision
		void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor *OtherActor, 
			UPrimitiveComponent *OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult);

};
