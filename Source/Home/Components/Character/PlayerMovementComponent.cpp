// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerMovementComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/Character.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values for this component's properties
UPlayerMovementComponent::UPlayerMovementComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

	PlayerWalkMode = EWalkMode::Walk;
}

FVector UPlayerMovementComponent::GetDesiredVelocity()
{
	using UKismet = UKismetMathLibrary;
	
	const auto& ControlRotation = PlayerCharacter->GetControlRotation();

	auto DesiredVelocity =
		UKismet::GetForwardVector(ControlRotation) * MoveForwardValue
		+ UKismet::GetRightVector(ControlRotation) * MoveRightValue;

	DesiredVelocity.Normalize();
	
	return DesiredVelocity;
}

// Called when the game starts
void UPlayerMovementComponent::BeginPlay()
{
	Super::BeginPlay();

	BindToInputComponent();
}

void UPlayerMovementComponent::BindToInputComponent()
{	auto InputComponent = GetOwner()->FindComponentByClass<UInputComponent>();

	PlayerCharacter = Cast<ACharacter>(GetOwner());

	if (InputComponent && PlayerCharacter)
	{
		InputComponent->BindAction("Sprint", IE_Pressed, this, &UPlayerMovementComponent::OnSprint);
		InputComponent->BindAction("Sprint", IE_Released, this, &UPlayerMovementComponent::OnSprintStop);

		InputComponent->BindAction("Crouch", IE_Pressed, this, &UPlayerMovementComponent::OnCrouch);
		InputComponent->BindAction("Crouch", IE_Released, this, &UPlayerMovementComponent::OnCrouchStop);
		
		InputComponent->BindAxis("MoveForward", this, &UPlayerMovementComponent::OnMoveForward);
		InputComponent->BindAxis("MoveRight", this, &UPlayerMovementComponent::OnMoveRight);
		
		InputComponent->BindAxis("Turn", this, &UPlayerMovementComponent::OnTurn);
		InputComponent->BindAxis("LookUp", this, &UPlayerMovementComponent::OnLookUp);
	}
}

void UPlayerMovementComponent::OnSprint()
{
	if (!SprintIsBlocked)
	{
		PlayerWalkMode = EWalkMode::Sprint;
	}
}

void UPlayerMovementComponent::OnSprintStop()
{
	PlayerWalkMode = EWalkMode::Walk;
}

void UPlayerMovementComponent::OnCrouch()
{
	PlayerWalkMode = EWalkMode::Crouch;
}

void UPlayerMovementComponent::OnCrouchStop()
{
	PlayerWalkMode = EWalkMode::Walk;
}

void UPlayerMovementComponent::OnMoveForward(float Value)
{
	MoveForwardValue = Value;
}

void UPlayerMovementComponent::OnMoveRight(float Value)
{
	MoveRightValue = Value;
}

void UPlayerMovementComponent::OnTurn(float Value)
{
	TurnValue = Value;
}

void UPlayerMovementComponent::OnLookUp(float Value)
{
	LookUpValue = Value;
}
