
#pragma once

#include "CoreMinimal.h"
#include "MVVMViewModelBase.h"
#include "VM_OrderItem.generated.h"


UCLASS()
class MVVM3_API UVM_OrderItem : public UMVVMViewModelBase
{
	GENERATED_BODY()

public:

	UVM_OrderItem();

	// Color parameters

	UPROPERTY(BlueprintReadOnly, FieldNotify, Category = "Visuals")
	FLinearColor ButtonOrderItemBackgroundColor;

	const FLinearColor GREEN_COLOR = FLinearColor(0.2f, 0.8f, 0.2f); // Зеленый
	const FLinearColor DEFAULT_COLOR = FLinearColor(0.5f, 0.5f, 0.5f); // Серый

	// MVVM variables and their setters

	UPROPERTY(BlueprintReadWrite, FieldNotify, Setter, Category = "ItemData_DRINK")
	FText ItemName;
	UFUNCTION(BlueprintSetter)
	void SetItemName(FText newItemName);

	UPROPERTY(BlueprintReadWrite, FieldNotify, Setter, Category = "ItemData_DRINK")
	bool IsSelected = false;
	UFUNCTION(BlueprintSetter)
	void SetIsSelected(bool newIsSelected);

	// Functions

	UFUNCTION(BlueprintCallable)
	void ResetData();

	void UpdateVisualState();

	UFUNCTION(BlueprintCallable)
	void SelectedOrder();
	
};
