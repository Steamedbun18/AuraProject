// Jensonian


#include "CharacterBase.h"

#include "AbilitySystem/AuraAbilitySystemComponent.h"
#include "AbilitySystem/AuraAttributeSet.h"

// Sets default values
ACharacterBase::ACharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// create the skeletal mesh component
	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("weapon");

	// attach the skeletal mesh
	Weapon->SetupAttachment(GetMesh(), FName("MainWeaponSocket"));

	// sets no collision
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);


}

UAbilitySystemComponent* ACharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

// Called when the game starts or when spawned
void ACharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}


