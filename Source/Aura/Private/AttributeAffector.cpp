// Jensonian


#include "AttributeAffector.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystem/AuraAttributeSet.h"


// Sets default values
AAttributeAffector::AAttributeAffector()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);

	Sphere = CreateDefaultSubobject<USphereComponent>("Sphere");
	Sphere->SetupAttachment(Mesh);

	

	

}

void AAttributeAffector::OnComponentOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// TODO: switch to better system using gameplay effects for now changing using const cast hack
	if (IAbilitySystemInterface* AbilityInterface = Cast<IAbilitySystemInterface>(OtherActor))
	{
		const UAuraAttributeSet* AuraAttributes = Cast<UAuraAttributeSet>(AbilityInterface->GetAbilitySystemComponent()->GetAttributeSet(UAuraAttributeSet::StaticClass()));
		UAuraAttributeSet* MutableAttributeSet = const_cast<UAuraAttributeSet*>(AuraAttributes);

		MutableAttributeSet->SetHealth(MutableAttributeSet->GetHealth() + HealingAmount);
		Destroy();
	}
}

// Called when the game starts or when spawned
void AAttributeAffector::BeginPlay()
{
	Super::BeginPlay();

	Sphere->OnComponentBeginOverlap.AddDynamic(this, &AAttributeAffector::OnComponentOverlap);
	
	
}
