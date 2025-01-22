// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseActor.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "TimerManager.h"

DEFINE_LOG_CATEGORY_STATIC(LogBaseGeometry, All, All)

// Sets default values
ABaseActor::ABaseActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>("BaseMesh");
	SetRootComponent(BaseMesh);
}

// Called when the game starts or when spawned
void ABaseActor::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(TimerHandle,this, &ABaseActor::OnTimerFired, TimerRate, true);

	FTransform Transform = GetActorTransform();
	FVector Location = Transform.GetLocation();
	FRotator Rotator = Transform.Rotator();

	UE_LOG(LogTemp, Error, TEXT("Actor name %s"), *GetName());
	UE_LOG(LogTemp, Error, TEXT("Actor name %s"), *Transform.ToString());
	UE_LOG(LogTemp, Error, TEXT("Actor name %s"), *Rotator.ToString());

	InitialLocation = GetActorLocation();
	

}

// Called every frame
void ABaseActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	float time = GetWorld()->GetTimeSeconds();

	switch (MoveType)
	{
	case EMovementType::Sin:
		FVector CurrentLocation = GetActorLocation();
		CurrentLocation.Z = InitialLocation.Z + Amplitude * FMath::Sin(Frequency * time);
		SetActorLocation(CurrentLocation);
		break;
	case EMovementType::Static:
		break;
	default:
		break;
	}
}

void ABaseActor::OnTimerFired()
{
	const FLinearColor NewColor = FLinearColor::MakeRandomColor();
	UMaterialInstanceDynamic* DynMaterial = BaseMesh->CreateAndSetMaterialInstanceDynamic(0);

	if (DynMaterial)
	{
		DynMaterial->SetVectorParameterValue("Color", NewColor);
	}
}

