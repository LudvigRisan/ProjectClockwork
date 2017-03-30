// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "BossHealthLink.generated.h"

UCLASS()
class PROJECTCLOCKWORK_API ABossHealthLink : public APawn
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

	float bossHealth = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HUD")
		void updateHealth(float health);
	
};
