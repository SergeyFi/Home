// Fill out your copyright notice in the Description page of Project Settings.


#include "Spawner.h"

// Sets default values for this component's properties
USpawner::USpawner()
{

	PrimaryComponentTick.bCanEverTick = false;

}

void USpawner::StartSpawn()
{
	GetWorld()->GetTimerManager().SetTimer(TimerSpawn, this, &USpawner::Spawn, SpawnRate, bIsLoop);
}

void USpawner::StopSpawn()
{
	GetWorld()->GetTimerManager().ClearTimer(TimerSpawn);	
}

// Called when the game starts
void USpawner::BeginPlay()
{
	Super::BeginPlay();
}

void USpawner::Spawn()
{
	if (ActorToSpawn)
	{
		FActorSpawnParameters SpawnParams;
		SpawnParams.Instigator = GetOwner()->GetInstigator();
		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		
		auto SpawnedActor = GetWorld()->SpawnActor<AActor>(ActorToSpawn, GetComponentTransform(), SpawnParams);

		OnActorSpawned.Broadcast(SpawnedActor);
	}
}
