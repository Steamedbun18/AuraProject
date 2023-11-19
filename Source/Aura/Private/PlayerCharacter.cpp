// Jensonian


#include "PlayerCharacter.h"

#include "AbilitySystemComponent.h"
#include "AuraPlayerState.h"
#include "GameFramework/CharacterMovementComponent.h"


APlayerCharacter::APlayerCharacter()
{
	// since the camera is fixed we want these all false
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 400.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	// don't want to use the controller rotation since the camera should be fixed for top down
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

	
}

void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void APlayerCharacter::InitAbilitySystem()
{
	// template function to get player state
	AAuraPlayerState* AuraPlayerState = GetPlayerState<AAuraPlayerState>();
	AuraPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(AuraPlayerState, this);
	AbilitySystemComponent = AuraPlayerState->GetAbilitySystemComponent();
	AttributeSet = AuraPlayerState->GetAttributeSet();
}

void APlayerCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	
	// init ability actor info for server
	InitAbilitySystem();

}

void APlayerCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
	// init ability actor info on client
	InitAbilitySystem();
}
