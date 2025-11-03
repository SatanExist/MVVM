
#include "MVVM3/ViewModels/VM_OrderItem/VM_OrderItem.h"

#include "MVVM3/ViewModels/OrderViewModel/OrderViewModel.h"

UVM_OrderItem::UVM_OrderItem()
{
	SetIsSelected(false);
	UpdateVisualState();
}

void UVM_OrderItem::UpdateVisualState()
{
	FLinearColor NewColor = IsSelected ? GREEN_COLOR : DEFAULT_COLOR;

	UE_MVVM_SET_PROPERTY_VALUE(ButtonOrderItemBackgroundColor, NewColor);
}

void UVM_OrderItem::SetItemName(FText newItemName)
{
	UE_MVVM_SET_PROPERTY_VALUE(ItemName, newItemName);
}

void UVM_OrderItem::SetIsSelected(bool newIsSelected)
{
	UE_MVVM_SET_PROPERTY_VALUE(IsSelected, newIsSelected);
}

void UVM_OrderItem::ResetData()
{
	if (IsSelected == true)
	{
		SelectedOrder(); 
	}
}

void UVM_OrderItem::SelectedOrder()
{
	if (IsSelected == false)
	{
		if (UOrderViewModel* OrderViewModel = Cast<UOrderViewModel>(GetOuter()))
		{
			for (UVM_OrderItem* orderItem : OrderViewModel->InitializedDrinks)
			{
				orderItem->SetIsSelected(false);
				orderItem->UpdateVisualState();
			}
		}

		this->SetIsSelected(true);
		UpdateVisualState();
		if (UOrderViewModel* OrderViewModel = Cast<UOrderViewModel>(GetOuter()))
		{
			OrderViewModel->SetSelectedDrink(this->ItemName);
		}

	}
	else if (IsSelected == true)
	{
		SetIsSelected(false);
		UpdateVisualState();
		if (UOrderViewModel* OrderViewModel = Cast<UOrderViewModel>(GetOuter()))
		{
			OrderViewModel->SetSelectedDrink(FText::GetEmpty());
		}
	}
	

	
}
