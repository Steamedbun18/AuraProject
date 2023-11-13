// Jensonian

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ITargetedInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UITargetedInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class AURA_API IITargetedInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void Highlight() = 0;
	virtual void Unhighlight() = 0;
};
