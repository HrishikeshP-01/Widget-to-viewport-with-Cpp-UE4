// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MyGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class SIMPLEMENUSYSTEM_API UMyGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	// Create a constructor
	UMyGameInstance(const FObjectInitializer& ObjectInitializer);

	// function to debug on console to manually check if the reference to widget class is correct
	virtual void Init();

	// The BlueprintCallable parameter gives us the ability to call ShowWidget via BPs
	UFUNCTION(BlueprintCallable)
	void ShowWidget();

private:
	// Variable to store reference to widget class
	TSubclassOf<class UUserWidget>MainMenuWidgetClass;
};
