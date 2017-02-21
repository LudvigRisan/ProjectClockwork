// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectClockwork.h"
#include "ProjectClockworkGameModeBase.h"


APlayerController* MyController = GetWorld()->GetFirstPlayerController();

MyController->bShowMouseCursor = true;
MyController->bEnableClickEvents = true;

