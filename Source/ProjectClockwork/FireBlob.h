// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Bullet.h"
#include "FireBlob.generated.h"

UCLASS()
class PROJECTCLOCKWORK_API AFireBlob : public ABullet
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFireBlob();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
		float speedDecay = 1;
	
};
