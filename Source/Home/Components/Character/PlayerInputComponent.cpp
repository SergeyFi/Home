// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerInputComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/Character.h"

// Sets default values for this component's properties
UPlayerInputComponent::UPlayerInputComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

// Called when the game starts
void UPlayerInputComponent::BeginPlay()
{
	Super::BeginPlay();

	BindToInputComponent();
}

void UPlayerInputComponent::BindToInputComponent()
{
	auto InputComponent = GetOwner()->FindComponentByClass<UInputComponent>();

	OwnerCharacter = Cast<ACharacter>(GetOwner());

	if (InputComponent && OwnerCharacter)
	{
		InputComponent->BindAxis("MoveForward", this, &UPlayerInputComponent::MoveForward);
		InputComponent->BindAxis("MoveRight", this, &UPlayerInputComponent::MoveRight);
		InputComponent->BindAxis("Turn", this, &UPlayerInputComponent::Turn);
		InputComponent->BindAxis("LookUp", this, &UPlayerInputComponent::LookUp);
	}
}

void UPlayerInputComponent::MoveForward(float Value)
{
	OwnerCharacter->AddMovementInput(OwnerCharacter->GetActorForwardVector() * Value);
}

void UPlayerInputComponent::MoveRight(float Value)
{
	OwnerCharacter->AddMovementInput(OwnerCharacter->GetActorRightVector() * Value);
}

void UPlayerInputComponent::Turn(float Value)
{
	OwnerCharacter->AddControllerYawInput(Value);
}

void UPlayerInputComponent::LookUp(float Value)
{
	OwnerCharacter->AddControllerPitchInput(Value);
}
