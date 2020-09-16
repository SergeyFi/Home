// Fill out your copyright notice in the Description page of Project Settings.


#include "PropertiesComponent.h"

// Sets default values for this component's properties
UPropertiesComponent::UPropertiesComponent()
{

	PrimaryComponentTick.bCanEverTick = false;

	PropertyValueMin = 0.0f;
	PropertyValueMax = 100.0f;

	PropertyName = TEXT("Property");

}

void UPropertiesComponent::AddPropertyValue(float Value)
{
	PropertyValue += Value;

	if (PropertyValue > PropertyValueMax)
	{
		PropertyValue = PropertyValueMax;
	}
}

void UPropertiesComponent::RemovePropertyValue(float Value)
{
	PropertyValue -= Value;
	
	if (PropertyValue < PropertyValueMin)
	{
		PropertyValue = PropertyValueMin;
	}
}

float UPropertiesComponent::GetPropertyValue()
{
	return PropertyValue;
}

FName UPropertiesComponent::GetPropertyName()
{
	return PropertyName;
}

