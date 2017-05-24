// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"

UCLASS()
class PROJECTCLOCKWORK_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
	FVector cursorLocation = { 0, 0, 0 };
	FVector rollDirection = { 0, 0, 0 };
	FVector originLocation;													//Spawn location of character, used to reset location on falling off stage

	float xIn = 0;															//Variable storing player input
	float yIn = 0;
	float rollingTimer = 0;													//Timer used to controll rolling
	float InvulTimer = 0;													//Timer used for invulnerability
	float meleTimer = 0;													//Timer for mele attack
	float deathTimer = 0;

	UShapeComponent* AttackBox = nullptr;									//Hitbox used for mele attack

	bool invulnerable = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool dying = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool attacking = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool rolling = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool damaged = false;												//Invulnerability on taking damage

	UPROPERTY(BlueprintReadWrite)											//Rotataion towards the mouse
		FRotator mouseRot;

	UPROPERTY(EditAnywhere, Category = "PlayerMovement")					//Movement speed (Not working as intended due to built in playermovement from unreal)
		float speed = 1;

	UPROPERTY(EditAnywhere, Category = "PlayerMovement")					//Movement speed when rolling
		float rollSpeed = 1;

	UPROPERTY(EditAnywhere, Category = "PlayerMovement")					//How lon the roll movement lasts for
		float rollTime = 1;

	UPROPERTY(EditAnywhere, Category = "PlayerMovement")					//How long the player is invulnerable when rolling
		float rollInvulTime = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HUD")
		int health = 3;

	UPROPERTY(EditAnywhere, Category = "Life")								//How long the player is invulnerable upon taking damage
		float damageInvulTime = 1;

	UPROPERTY(EditAnywhere)
		float deathDelay = 1;

	UPROPERTY(EditAnywhere)													//How long the mele attacks last for
		float meleTime = 1;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HUD")			//If the player has a bullet loaded
	    bool ammo = true;

	UPROPERTY(EditAnywhere)
		TSubclassOf<class APlayerBullet> BulletBlueprint;

	UPROPERTY(EditAnywhere)
		FVector bulletOffset = { 0, 0, 0 };									//Where the bullet is

	void xInput(float axis);

	void yInput(float axis);
	
	void move(float DeltaTime);

	void trackMouse();

	void pointToMouse();													//Get the rotation vlaue towards the mouse

	bool damage();															//Take damage
	
	void die();

	void roll();

	void rollMove(float deltaTime);

	void attack();

	void shoot();

	void hit();

	void endHit();

	UFUNCTION()
		void hitDetect(UPrimitiveComponent* OverlappedComponent, AActor *OtherActor,
		UPrimitiveComponent *OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult);
};
