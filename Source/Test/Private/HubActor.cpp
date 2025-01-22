// Fill out your copyright notice in the Description page of Project Settings.


#include "HubActor.h"

// Sets default values
AHubActor::AHubActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AHubActor::BeginPlay()
{
	Super::BeginPlay();
	
	UWorld* World = GetWorld();

	if (World)
	{
		for (size_t i = 0; i < 10; i++)
		{
			const FTransform GeometryTransform = FTransform(FRotator::ZeroRotator, FVector(0.0, 110.0 * i, 110.0 * i));
			auto Actor = World->SpawnActor<ABaseActor>(BaseClass, GeometryTransform);

			if (Actor)
				Actor->SetMoveType(EMovementType::Sin);
		}

		for (size_t i = 0; i < 10; i++)
		{
			const FTransform GeometryTransform = FTransform(FRotator::ZeroRotator, FVector(0.0, -110.0 * i, -110.0 * i));
			auto Actor = World->SpawnActorDeferred<ABaseActor>(BaseClass, GeometryTransform);

			if (Actor)
			{
				Actor->SetMoveType(EMovementType::Sin);
				Actor->FinishSpawning(GeometryTransform);
			}
				
		}
	}
}

// Called every frame
void AHubActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

