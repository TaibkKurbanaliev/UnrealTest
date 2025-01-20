// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "BaseActor.generated.h"

UENUM(BlueprintType)
enum class EMovementType : uint8
{
	Sin,
	Static,
};

UCLASS()
class TEST_API ABaseActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseActor();
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* BaseMesh;

protected:
	UPROPERTY(EditAnywhere, Category = "Movement")
	float Amplitude = 50.0f;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float Frequency = 2.0f;

	UPROPERTY(EditAnywhere, Category = "Movement")
	EMovementType MoveType = EMovementType::Static;
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
private:
	FVector InitialLocation;
};
