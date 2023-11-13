// Jensonian


#include "Player/AuraPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"

AAuraPlayerController::AAuraPlayerController()
{
	bReplicates = true;
}

void AAuraPlayerController::BeginPlay()
{
	Super::BeginPlay();
	// assert if AuraContext mapping variable is set if not will crash
	check(AuraContext);

	// need to get the enhanced input subsystem in order to add the mapping context
	// get it from localplayer using getsubstyem template function
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	// assert to check subsystem is valid if not crash
	check(Subsystem);
	// adds the map context
	Subsystem->AddMappingContext(AuraContext, 0);

	// mouse settings
	bShowMouseCursor = true;

	DefaultMouseCursor = EMouseCursor::Default;
	// input data variable and settings
	FInputModeGameAndUI DataInputMode;
	DataInputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	DataInputMode.SetHideCursorDuringCapture(false);
	// assign the data input 
	SetInputMode(DataInputMode);
}

// function for setting up input on controller
void AAuraPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	// need enhanced input component using assert cast so crash if can't cast
	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

	// bind the input action to the call back function
	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AAuraPlayerController::Move);
	
}

// call back function to be binded to input action
void AAuraPlayerController::Move(const FInputActionValue& InputActionValue)
{
	// need to convert the input struct to the form we want it in for our input action: vector 2d
	// use Get template function to get the form
	const FVector2d InputDataVector = InputActionValue.Get<FVector2D>();

	// need the controller rotation to get the correct direction
	// rotation is from the camera to character
	const FRotator ControllerRotation = GetControlRotation();
	// we only want that flat x,y plane without any pitch or roll.  So get just the yaw
	const FRotator YawRotation = FRotator(0.f, ControllerRotation.Yaw, 0.f);

	// we want the unit vector of the yaw rotation
	// use a rotation matrix to get the X for forward since that is what we set x to be in the input action
	// same thing but for rightdirection
	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	// need the pawn to add movement
	// wrap in if check so it is only doing when the pawn is valid
	// adds the movement based on the input from the function
	if(APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddMovementInput(ForwardDirection, InputDataVector.Y);
		ControlledPawn->AddMovementInput(RightDirection, InputDataVector.X);
	}

	

	
}