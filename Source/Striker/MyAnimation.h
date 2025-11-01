// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
//#include "KismetAnimationLibrary.h"
#include "MyAnimation.generated.h"


UCLASS()
class STRIKER_API UMyAnimation : public UAnimInstance
{
	GENERATED_BODY()
	


protected:

	UPROPERTY(BlueprintReadOnly,Category=CharacterProperties)
	float SpeedAnimationCharacter;
	
	UPROPERTY(BlueprintReadOnly, Category = CharacterProperties)
	float DirectionAnimCharacter;

	UPROPERTY(BlueprintReadOnly, Category = CharacterProperties)
	bool bIsSprinting;

	UPROPERTY(BlueprintReadOnly, Category = CharacterProperties)
	bool bIsJumping;

	UPROPERTY(BlueprintReadOnly, Category = CharacterProperties)
	bool bIsAiming;

	


	APawn* myCharacter;


	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
	
	



public:
	UMyAnimation();

};
