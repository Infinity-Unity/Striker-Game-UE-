// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "MyAnimation.generated.h"


UCLASS()
class STRIKER_API UMyAnimation : public UAnimInstance
{
	GENERATED_BODY()
	


protected:

	UPROPERTY(BlueprintReadOnly,Category=CharacterProperties)
	float SpeedAnimationCharacter;
	APawn* myCharacter;
	
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
	
	



public:
	UMyAnimation();

};
