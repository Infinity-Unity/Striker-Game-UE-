// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAnimation.h"
#include "MainCharacter.h"






void UMyAnimation::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	myCharacter = TryGetPawnOwner();
	UE_LOG(LogTemp, Warning, TEXT("Load Anim"));
}

void UMyAnimation::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	if (myCharacter)
	{
		SpeedAnimationCharacter = myCharacter->GetVelocity().Size();
		//UE_LOG(LogTemp, Warning, TEXT("You use Update Animation"));

	}
}



UMyAnimation::UMyAnimation()
{
	
}


