// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"
#include "Engine/World.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	Health = 100.f;
	MaxHealth = Health;
    RegHealth = 1.f;
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();	
}

void UHealthComponent::SetHealth(float Live)
{
	Health = Live;
}

float UHealthComponent::GetCurrentHealth()
{
	return Health;
}

void UHealthComponent::SetMaxHealth(float Mlive)
{
	MaxHealth = Mlive;
}

float UHealthComponent::GetCurrentMaxHealth()
{
	return MaxHealth;
}

void UHealthComponent::Heal(float Heal, AActor* Instigator)
{
	OnHealed.Broadcast(Heal, Instigator);
	Health = Health + Heal;
	if (Health > MaxHealth) {
		Health = MaxHealth;
	}
}

void UHealthComponent::Regeneration()
{
	Heal(RegHealth);
	if (Health == MaxHealth) {
		StopRegeneration();
	}
}

void UHealthComponent::StartRegeneration()
{
	GetWorld()->GetTimerManager().SetTimer(TimerRegHealth, this, &UHealthComponent::Regeneration, RegRate, true);
}

void UHealthComponent::StopRegeneration()
{
	GetWorld()->GetTimerManager().ClearTimer(TimerRegHealth);
}

void UHealthComponent::TakeDamage(float Damage, AActor* Instigator)
{
	OnDamage.Broadcast(Damage, Instigator);

	Health -= Damage;

	if (Health < 0) {
		Health = 0;
	}
	if (Health == 0) {
		OnHealthEnd.Broadcast(Damage, Instigator);
	}
}
