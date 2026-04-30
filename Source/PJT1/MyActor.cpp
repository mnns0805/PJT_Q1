// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"
#include "Engine.h"

const int IndexCount = 10;


// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}





// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	
	//0,0,50에서 시작
	SetActorLocation(FVector(0, 0, 50));
	TriggerEvent();


	for (int32 i = 0; i < IndexCount; ++i)
	{
		Turn();
	}	
}


void AMyActor::TriggerEvent()
{
	double DisSum = 0;
	int32 Event = 0;

	for (int32 i = 0; i < IndexCount; ++i)
	{
		if (FMath::RandRange(0, 1) == 1)
		{
			
			DisSum = DisSum + VectorDistance(); //리턴 LocationDist
			Event = Event + 1;

			if (GEngine)
			{

				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Now is = %d"), (i + 1)));
			}
		}
	}

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Purple, FString::Printf(TEXT("AllDis = %lf"), (DisSum)));
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("AllEvent = %d"), (Event)));
}




FVector AMyActor::Move()
{
	
	FVector Target;

	//-50~50까지 random
	Target.X = FMath::FRandRange(-50.0, 50.0);
	Target.Y = FMath::FRandRange(-50.0, 50.0);
	Target.Z = 0;
	AddActorWorldOffset(Target);
	FVector CurentLocation = GetActorLocation();

	
	if (GEngine) //2차 검증(없어도 무방한데 좀 더 안전하게 실행시키기 위한 증복 검증문)
	{

		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, CurentLocation.ToString());
	}
	UE_LOG(LogTemp, Warning, TEXT("Location=%s"), *CurentLocation.ToString());
	
	return CurentLocation;

}


void AMyActor::Turn()
{
	FRotator DeltaRotation;
	DeltaRotation.Yaw = FMath::FRandRange(-180.0, 180.0);
	DeltaRotation.Pitch = 0;
	DeltaRotation.Roll = 0;

	AddActorWorldRotation(DeltaRotation);

	FRotator CurrentRotaion = GetActorRotation();
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Blue, CurrentRotaion.ToString());

	}
	UE_LOG(LogTemp, Warning, TEXT("Rotation = %s"), *CurrentRotaion.ToString());

}


double AMyActor::VectorDistance()
{
	FVector OriginLocation = GetActorLocation();
	FVector CurrentLocation = GetActorLocation() + Move();
	double LocationDist = FVector::Dist(OriginLocation, CurrentLocation);


	return LocationDist;
}



