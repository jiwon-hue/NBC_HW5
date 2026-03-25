// Fill out your copyright notice in the Description page of Project Settings.

#include "MyActor.h"

void AMyActor::Move(FVector& InVector, float moveX, float moveY)
{
	InVector.X += moveX;
	InVector.Y += moveY;
	SetActorLocation(InVector);
	GEngine->AddOnScreenDebugMessage(
		-1,
		3.0f,
		FColor::White,
		FString::Printf(TEXT("Location: %f, %f"), InVector.X, InVector.Y)
	);
}

void AMyActor::Turn(FRotator& InRotator, float turnPitch, float turnYaw)
{
	InRotator.Pitch += turnPitch;
	InRotator.Yaw += turnYaw;
	SetActorRotation(InRotator);
	GEngine->AddOnScreenDebugMessage(
		-1,
		3.0f,
		FColor::White,
		FString::Printf(TEXT("Rotation: %f, %f"), InRotator.Pitch, InRotator.Yaw)
	);
}


// Sets default values
AMyActor::AMyActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	FVector CubeVector;
	CubeVector = GetActorLocation();

	FRotator CubeRotator;
	CubeRotator = GetActorRotation();

	for (int i = 0; i < 10; i++)
	{
		float randNum1 = FMath::FRandRange(0.f, 100.0f);
		float randNum2 = FMath::FRandRange(0.f, 100.0f);
		Move(CubeVector, randNum1, randNum2);
		randNum1 = FMath::FRandRange(0.f, 100.0f);
		randNum2 = FMath::FRandRange(0.f, 100.0f);
		Turn(CubeRotator, randNum1, randNum2);
	}
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

