// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PropertiesComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(IsBlueprintBase="true") )
class HOME_API UPropertiesComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPropertiesComponent();

	UFUNCTION(BlueprintCallable)
	void AddPropertyValue(float Value);

	UFUNCTION(BlueprintCallable)
	void RemovePropertyValue(float Value);

	UFUNCTION(BlueprintCallable)
	float GetPropertyValue();

	UFUNCTION(BlueprintCallable)
	FName GetPropertyName();

private:

	UPROPERTY(EditAnywhere)
	float PropertyValue;

	UPROPERTY(EditAnywhere)
	FName PropertyName;

	UPROPERTY(EditAnywhere)
	float PropertyValueMin;

	UPROPERTY(EditAnywhere)
	float PropertyValueMax;
		
};
