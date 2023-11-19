// Jensonian

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Actor.h"
#include "AttributeAffector.generated.h"

UCLASS()
class AURA_API AAttributeAffector : public AActor
{
	GENERATED_BODY()
	
public:	

	AAttributeAffector();

	UFUNCTION()
	virtual void OnComponentOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

protected:

	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UStaticMeshComponent> Mesh;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USphereComponent> Sphere;

	UPROPERTY(EditAnywhere, Category = "Healing")
	float HealingAmount = 25.f;

	



};
