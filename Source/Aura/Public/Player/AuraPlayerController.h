// Jensonian

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "AuraPlayerController.generated.h"

// Forward declares
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

/**
 * 
 */
UCLASS()
class AURA_API AAuraPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	// constructor
	AAuraPlayerController();

protected:
	// begin play
	virtual void BeginPlay() override;
	
	// function to setup input
	virtual void SetupInputComponent() override;

private:
	// pointer for the input mapping
	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputMappingContext> AuraContext;

	// pointer for input action
	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputAction> MoveAction;

	// call back function to be called when our input action is triggered
	// requires input of the FInputAction value struct ref 
	void Move(const FInputActionValue& InputActionValue);
};
