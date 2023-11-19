// Jensonian

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "AuraAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

/**
 * 
 */
UCLASS()
class AURA_API UAuraAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
public:
	
	UAuraAttributeSet();
	// must override this function to register variables you want to replicate
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	// Health attribute
	// must have replicatedusing 
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = On_RepHealth, Category="MainResourceStats")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Health);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = On_RepMaxHealth, Category="MainResourceStats")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, MaxHealth);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = On_RepMana, Category="MainResourceStats")
	FGameplayAttributeData Mana;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Mana);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = On_RepMaxMana, Category="MainResourceStats")
	FGameplayAttributeData MaxMana;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, MaxMana);


	// health on rep function must be ufunction
	UFUNCTION()
	void On_RepHealth(const FGameplayAttributeData& OldHealth) const;

	UFUNCTION()
	void On_RepMaxHealth(const FGameplayAttributeData& OldMaxHealth) const;

	UFUNCTION()
	void On_RepMana(const FGameplayAttributeData& OldMana) const;

	UFUNCTION()
	void On_RepMaxMana(const FGameplayAttributeData& OldMaxMana) const;
};
