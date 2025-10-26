#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "MainCharacter.generated.h"

class UInputAction;
class UInputMappingContext;
class USpringArmComponent;
class UCameraComponent;



UCLASS()
class STRIKER_API AMainCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AMainCharacter();
	

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* SpringArmComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* CameraComp;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputMappingContext* IMC_Default;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* IA_MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* IA_LookAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* IA_Jump;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "BP_Weapon", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<AActor> BP_WeaponClass;

	AActor* Weapon;


	void Move(const FInputActionValue& Instance);
	void Look(const FInputActionValue& Instance);
	void OnStartJump();
	void OnStopJump();

	

	

	UPROPERTY(BlueprintReadOnly, Category = "Boolean", meta = (AllowPrivateAccess = "true"))
	bool bIsJumping;

	UPROPERTY(BlueprintReadOnly, Category = "Boolean", meta = (AllowPrivateAccess = "true"))
	bool bIsAiming;

	UPROPERTY(BlueprintReadOnly, Category = "Boolean", meta = (AllowPrivateAccess = "true"))
	bool bIsTakeGun;

	UPROPERTY(BlueprintReadOnly, Category = "Boolean", meta = (AllowPrivateAccess = "true"))
	bool bIsFire;

	UPROPERTY(BlueprintReadOnly, Category = "Boolean", meta = (AllowPrivateAccess = "true"))
	bool bIsNeedTotalAmmo;

	UPROPERTY(BlueprintReadOnly, Category = "Boolean", meta = (AllowPrivateAccess = "true"))
	bool bIsNeedAmmo;

	UPROPERTY(BlueprintReadOnly, Category = "Boolean", meta = (AllowPrivateAccess = "true"))
	bool bIsSprint;



	UPROPERTY(BlueprintReadOnly, Category = "Ammo", meta = (AllowPrivateAccess = "true"))
	float AmmoCount;

	UPROPERTY(BlueprintReadOnly, Category = "Ammo", meta = (AllowPrivateAccess = "true"))
	float TotalAmmo;

	UPROPERTY(BlueprintReadOnly, Category = "Ammo", meta = (AllowPrivateAccess = "true"))
	float MaxAmmo;












	void Aim();
};