// Fill out your copyright notice in the Description page of Project Settings.


#include "Study1.h"

// Sets default values
AStudy1::AStudy1()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AStudy1::BeginPlay()
{
	Super::BeginPlay();
	int Start = 1; //정수 자료형 변수 선언과 동시에 1 대입
	int End = 30; //정수 자료형 변수 선언과 동시에 30 대입
	
	for (int i = Start; i <= End; ++i) // Start 지점에서 End 지점까지 반복실행
	{
		FString Number = FString::FromInt(i); //출력문자열 Number 안에 정수문자 i를 대입하여 출력
		bool blsClap = false; //Clap 즉 '짝' 박수 소리를 출력할지 여부를 나타내는 플래그

		for (TCHAR Char : Number)//TCHAR를 사용해 플랫폼 독립 문자처리

			if (Char == '3' || Char == '6' || Char == '9')
			//'3' '6' '9' 중 하나라도 포함하면(OR)....
			{
				blsClap = true; // '짝'이 참으로 변경되면서 출력
				break; // 이 후 검사 종료되면서 중괄호 탈출
			}
		if (blsClap)
		{
			
			UE_LOG(LogTemp, Warning, TEXT("짝"))
		}
		else
		{

			UE_LOG(LogTemp, Warning, TEXT("% d"), i)

		}
	}
	
	


	

	UE_LOG(LogTemp, Warning, TEXT("Hellow, World!"))
	
}

// Called every frame
void AStudy1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

