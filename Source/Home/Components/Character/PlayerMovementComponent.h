// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PlayerMovementComponent.generated.h"


UENUM(BlueprintType)
enum class EWalkMode : uint8
{
    Walk UMETA(DisplayName = "Walk"),
    Sprint UMETA(DisplayName = "Sprint"),
	Crouch UMETA(DisplayName = "Crouch")
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class HOME_API UPlayerMovementComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPlayerMovementComponent();

	UFUNCTION(BlueprintCallable)
	FVector GetDesiredVelocity();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	EWalkMode PlayerWalkMode;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float MoveForwardValue;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float MoveRightValue;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float TurnValue;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float LookUpValue;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool SprintIsBlocked;

private:
	class ACharacter* PlayerCharacter;
	
	void BindToInputComponent();

	UFUNCTION()
	void OnSprint();

	UFUNCTION()
	void OnSprintStop();

	UFUNCTION()
	void OnCrouch();

	void OnCrouchStop();

	UFUNCTION()
	void OnMoveForward(float Value);

	UFUNCTION()
	void OnMoveRight(float Value);

	UFUNCTION()
	void OnTurn(float Value);

	UFUNCTION()
	void OnLookUp(float Value);
};
