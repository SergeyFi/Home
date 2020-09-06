// Fill out your copyright notice in the Description page of Project Settings.


#include "SprintComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values for this component's properties
USprintComponent::USprintComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

	SprintSpeedIncrease = 300.0f;
}


// Called when the game starts
void USprintComponent::BeginPlay()
{
	Super::BeginPlay();

	BindToInputComponent();
}

void USprintComponent::BindToInputComponent()
{
	UInputComponent* InputComp = GetOwner()->FindComponentByClass<UInputComponent>();

	CharacterMovementComp = GetOwner()->FindComponentByClass<UCharacterMovementComponent>();

	if (InputComp && CharacterMovementComp)
	{
		InputComp->BindAction("Sprint", IE_Pressed, this, &USprintComponent::Sprint);
		InputComp->BindAction("Sprint", IE_Released, this, &USprintComponent::SprintStop);
	}


}

void USprintComponent::Sprint()
{
	if (CharacterMovementComp)
	{
		CharacterMovementComp->MaxWalkSpeed += SprintSpeedIncrease;
	}
}

void USprintComponent::SprintStop()
{
	if (CharacterMovementComp)
	{
		CharacterMovementComp->MaxWalkSpeed -= SprintSpeedIncrease;
	}
}
