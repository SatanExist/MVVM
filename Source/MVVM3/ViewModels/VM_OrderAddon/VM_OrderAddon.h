
#pragma once

#include "CoreMinimal.h"
#include "MVVMViewModelBase.h"
#include "VM_OrderAddon.generated.h"


UCLASS()
class MVVM3_API UVM_OrderAddon : public UMVVMViewModelBase
{
	GENERATED_BODY()

public:

	UVM_OrderAddon();

	// Color parameters

	UPROPERTY(BlueprintReadOnly, FieldNotify, Category = "Visuals")
	FLinearColor ButtonOrderAddonBackgroundColor;

	const FLinearColor GREEN_COLOR = FLinearColor(0.2f, 0.8f, 0.2f); // Зеленый
	const FLinearColor DEFAULT_COLOR = FLinearColor(0.5f, 0.5f, 0.5f); // Серый

	// MVVM variables and their setters

	UPROPERTY(BlueprintReadWrite, FieldNotify, Setter, Category = "ItemData_ADDON")
	FText AddonName;
	UFUNCTION(BlueprintSetter)
	void SetAddonName(FText newAddonName);

	UPROPERTY(BlueprintReadWrite, FieldNotify, Setter, Category = "ItemData_ADDON")
	bool IsSelected = false;
	UFUNCTION(BlueprintSetter)
	void SetIsSelected(bool newIsSelected);


	// Functions

	UFUNCTION(BlueprintCallable)
	void ResetData();

	void UpdateVisualState();

	UFUNCTION(BlueprintCallable)
	void SelectedAddon();

	
};
