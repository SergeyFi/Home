// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "Spawner.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSpawnDelegate, AActor*, SpawnedActor);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class HOME_API USpawner : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USpawner();

	void StartSpawn();

	void StopSpawn();

	FSpawnDelegate OnActorSpawned;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> ActorToSpawn;

	UPROPERTY(EditAnywhere)
	bool bIsLoop;

	UPROPERTY(EditAnywhere)
	int SpawnRate;

	FTimerHandle TimerSpawn;

	void Spawn();

};
