// Jensonian

#pragma once

#include "CoreMinimal.h"
#include "CharacterBase.h"
#include "Interfaces/ITargetedInterface.h"
#include "NpcBase.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API ANpcBase : public ACharacterBase, public IITargetedInterface
{
	GENERATED_BODY()


public:

	virtual void Highlight() override;
	virtual void Unhighlight() override;
	
};
