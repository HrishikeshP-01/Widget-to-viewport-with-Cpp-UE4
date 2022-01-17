// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"
// For widget
#include "Blueprint/UserWidget.h"
// For getting references
#include "UObject/ConstructorHelpers.h"

UMyGameInstance::UMyGameInstance(const FObjectInitializer& ObjectInitializer)
{
	// Create a temp. widget variable for null checking purposes
	static ConstructorHelpers::FClassFinder<UUserWidget> MainMenuWidget(TEXT("/Game/Menu/MenuHUD"));
	//Check for null ptr
	if (!ensure (MainMenuWidget.Class != nullptr)) return;

	// If the temp widget variable isn't null then store it in the main widget variable
	MainMenuWidgetClass = MainMenuWidget.Class;
}

void UMyGameInstance::Init()
{
	UE_LOG(LogTemp, Warning, TEXT("Hrishi! : Found class %s"), *MainMenuWidgetClass->GetName());
}

void UMyGameInstance::ShowWidget()
{
	// Create widget
	UUserWidget* MainMenu = CreateWidget<>(this, MainMenuWidgetClass);
	// Add it to viewport
	MainMenu->AddToViewport();

	// Get reference to player controller
	APlayerController* playerController = GetFirstLocalPlayerController();

	/*Setup input parameters for the SetInputMode function*/
	FInputModeUIOnly InputModeData;
	InputModeData.SetWidgetToFocus(MainMenu->TakeWidget());
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);

	// SetInputMode
	playerController->SetInputMode(InputModeData);

	// Show mouse cursor
	playerController->bShowMouseCursor = true;
}