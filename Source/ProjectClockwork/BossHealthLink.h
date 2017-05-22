// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "BossHealthLink.generated.h"

UCLASS()
class PROJECTCLOCKWORK_API ABossHealthLink : public APawn			//Object used to store the health in a format that lets the UI and other similar parts access it
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABossHealthLink();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HUD")
		float bossHealth = 0;

	
	void updateHealth(float health);
	
};
