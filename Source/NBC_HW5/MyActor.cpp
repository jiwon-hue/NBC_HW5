// Fill out your copyright notice in the Description page of Project Settings.

#include "MyActor.h"
#include "CoreMinimal.h"

void AMyActor::Move(FVector& InVector, float moveX, float moveY)
{
	InVector = GetActorLocation();
	InVector.X += moveX;
	InVector.Y += moveY;
	SetActorLocation(InVector);
}

void AMyActor::Turn(FRotator& InRotator, float turnPitch, float turnYaw)
{
	InRotator = GetActorRotation();
	InRotator.Pitch += turnPitch;
	InRotator.Yaw += turnYaw;
	SetActorRotation(InRotator);
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
	FVector CubeVector = FVector(0.f, 50.0f, 0.f);

	for (int i = 0; i < 10; i++)
	{
		FMath::FRandRange(0.f, 10.0f);
		AMyActor::Move()
	}
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

