// Jensonian


#include "NpcBase.h"

#include "Aura/Aura.h"

ANpcBase::ANpcBase()
{
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
}

void ANpcBase::Highlight()
{
	isTargeted = true;
	GetMesh()->SetRenderCustomDepth(true);
	GetMesh()->SetCustomDepthStencilValue(CUSTOM_DEPTH);
	
	Weapon->SetRenderCustomDepth(true);
	Weapon->SetCustomDepthStencilValue(CUSTOM_DEPTH);
}

void ANpcBase::Unhighlight()
{
	isTargeted = false;
	GetMesh()->SetRenderCustomDepth(false);
	
	Weapon->SetRenderCustomDepth(false);

}
