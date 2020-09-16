// Fill out your copyright notice in the Description page of Project Settings.


#include "MovementBaseComponent.h"
#include "Components/InputComponent.h"

// Sets default values for this component's properties
UMovementBaseComponent::UMovementBaseComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

}


// Called when the game starts
void UMovementBaseComponent::BeginPlay()
{
	Super::BeginPlay();

	BindToInputComponent();
	
}

void UMovementBaseComponent::BindToInputComponent()
{
	OwnerPawn = Cast<APawn>(GetOwner());

	if (OwnerPawn)
	{
		InputComponent = OwnerPawn->FindComponentByClass<UInputComponent>();

		if (InputComponent)
		{
			InputComponent->BindAxis("MoveForward", this, &UMovementBaseComponent::MoveForward);
			InputComponent->BindAxis("MoveRight", this, &UMovementBaseComponent::MoveRight);

			InputComponent->BindAxis("Turn", this, &UMovementBaseComponent::Turn);
			InputComponent->BindAxis("LookUp", this, &UMovementBaseComponent::LookUp);
		}
	}
}

void UMovementBaseComponent::MoveForward(float Value)
{
	OwnerPawn->AddMovementInput(GetOwner()->GetActorForwardVector(), Value);
}

void UMovementBaseComponent::MoveRight(float Value)
{
	OwnerPawn->AddMovementInput(GetOwner()->GetActorRightVector(), Value);
}

void UMovementBaseComponent::Turn(float Value)
{
	OwnerPawn->AddControllerYawInput(Value);
}

void UMovementBaseComponent::LookUp(float Value)
{
	OwnerPawn->AddControllerPitchInput(Value);
}

