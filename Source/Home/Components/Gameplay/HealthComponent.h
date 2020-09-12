// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FHealthDelegate, float, Value, AActor*, Instigator);

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class HOME_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UHealthComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float Health;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float MaxHealth;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float RegHealth;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float RegRate;
public:
	void  SetHealth(float Live);
	float GetCurrentHealth();
	void  SetMaxHealth(float Mlive);
	float GetCurrentMaxHealth();
	void  Heal(float Heal, AActor* Instigator = nullptr);
	void  Regeneration();
	void  StartRegeneration();
	void  StopRegeneration();
	void  TakeDamage(float Damage, AActor* Instigator = nullptr);
	FHealthDelegate OnDamage;
	FHealthDelegate OnHealthEnd;
	FHealthDelegate OnHealed;
private:
	FTimerHandle TimerRegHealth;
};