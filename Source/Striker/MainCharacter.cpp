// Fill out your copyright notice in the Description page of Project Settings.


#include "MainCharacter.h"
#include "Camera/CameraComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "InputAction.h"
#include "InputActionValue.h"


DEFINE_LOG_CATEGORY(CharacterLog);



AMainCharacter::AMainCharacter()
{
 	
	PrimaryActorTick.bCanEverTick = false;

	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComp"));
	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp"));

	GetMesh()->SetRelativeLocationAndRotation(FVector(0.f, 0.f, -90.f), FQuat(FRotator(0.f, -90.f, 0.f)));

	SpringArmComp->SetupAttachment(GetMesh());
	CameraComp->SetupAttachment(SpringArmComp, USpringArmComponent::SocketName);

	SpringArmComp->bUsePawnControlRotation = true;

	SpringArmComp->TargetArmLength = 0.f;

	GetCharacterMovement()->bOrientRotationToMovement = true;

	GetCharacterMovement()->bUseControllerDesiredRotation = true;

	GetCharacterMovement()->bIgnoreBaseRotation = true;

	bUseControllerRotationYaw = false;
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;

	GetCharacterMovement()->JumpZVelocity = 50.f;
	
	
	
}

float AMainCharacter::GetSpeedPlayer() 
{
	return 0.0f;
}



void AMainCharacter::BeginPlay()
{
	Super::BeginPlay();
	SpringArmComp->SetRelativeLocation(FVector(0.0, 0.0, 150.0));
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* SubSystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			SubSystem->AddMappingContext(IMC_Default, 0);
			GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, TEXT("Sucsess Load Mapping Context"));
		}
	}
	
}


void AMainCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void AMainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	if (UEnhancedInputComponent* EInput = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EInput->BindAction(IA_MoveAction, ETriggerEvent::Triggered, this, &AMainCharacter::Move);
		EInput->BindAction(IA_LookAction, ETriggerEvent::Triggered, this, &AMainCharacter::Look);
		EInput->BindAction(IA_Jump, ETriggerEvent::Started, this, &AMainCharacter::OnStartJump);
		EInput->BindAction(IA_Jump, ETriggerEvent::Completed, this, &AMainCharacter::OnStopJump);
		EInput->BindAction(IA_Jump, ETriggerEvent::Canceled, this, &AMainCharacter::OnStopJump);
		GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, TEXT("Find The MoveAction"));
	}
	

	
}


void AMainCharacter::Move(const FInputActionValue& Instance)
{
	GEngine->AddOnScreenDebugMessage(2, 0.2f, FColor::Red, TEXT("Move"));
	const FVector2D MovementValue = Instance.Get<FVector2D>();
	if (Controller)
	{

		const FRotator YawRotation(0, Controller->GetControlRotation().Yaw, 0);


		const FVector Right = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		const FVector Forward = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

		AddMovementInput(Right, MovementValue.X);
		AddMovementInput(Forward, MovementValue.Y);
		UE_LOG(LogTemp, Warning, TEXT("%f %f"), MovementValue.X, MovementValue.Y);
	}
}

void AMainCharacter::Look(const FInputActionValue& Instance)
{
	GEngine->AddOnScreenDebugMessage(3, 0.2f, FColor::Red, TEXT("Looking"));
	const FVector2D MovementValue = Instance.Get<FVector2D>();
	if (Controller)
	{
		AddControllerYawInput(MovementValue.X);
		AddControllerPitchInput(MovementValue.Y);
	}
}

void AMainCharacter::OnStartJump()
{
	GEngine->AddOnScreenDebugMessage(5, 1.f, FColor::Cyan, TEXT("Jumping"));
	bPressedJump = true;
}

void AMainCharacter::OnStopJump()
{
	bPressedJump = false;
}

void AMainCharacter::Aim()
{
	//UE_LOG(ChcaracterLog, Warning, TEXT("You Aiming");
}








