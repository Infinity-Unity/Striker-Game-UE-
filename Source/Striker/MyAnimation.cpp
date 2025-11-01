// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAnimation.h"
#include "MainCharacter.h"






void UMyAnimation::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	UE_LOG(LogTemp, Warning, TEXT("Load Anim"));
}

void UMyAnimation::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	myCharacter = TryGetPawnOwner();
	if (myCharacter)
	{
		FVector velocity = myCharacter->GetVelocity();
		FRotator rotation = myCharacter->GetActorRotation();
		SpeedAnimationCharacter = velocity.Size();
		DirectionAnimCharacter = CalculateDirection(velocity, rotation);
		//bIsSprinting = Cast<AMainCharacter>(myCharacter)->GetIsSprint();

		
	}
}



UMyAnimation::UMyAnimation()
{
	
}


