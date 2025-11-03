
#include "MVVM3/ViewModels/VM_OrderAddon/VM_OrderAddon.h"


#include "MVVM3/ViewModels/OrderViewModel/OrderViewModel.h"

UVM_OrderAddon::UVM_OrderAddon()
{
	SetIsSelected(false);
	UpdateVisualState();
}

void UVM_OrderAddon::UpdateVisualState()
{
	FLinearColor NewColor = IsSelected ? GREEN_COLOR : DEFAULT_COLOR;

	UE_MVVM_SET_PROPERTY_VALUE(ButtonOrderAddonBackgroundColor, NewColor);
}

void UVM_OrderAddon::SelectedAddon()
{

	if (IsSelected == false)
	{
		this->SetIsSelected(true);
		UpdateVisualState();
		if (UOrderViewModel* OrderViewModel = Cast<UOrderViewModel>(GetOuter()))
		{
			OrderViewModel->SelectedAddons.Add(this->AddonName);
		}
	}
	else if (IsSelected == true)
	{
		this->SetIsSelected(false);
		UpdateVisualState();
		if (UOrderViewModel* OrderViewModel = Cast<UOrderViewModel>(GetOuter()))
		{
			TArray<FText> CurrentAddons = OrderViewModel->SelectedAddons;
			int32 FoundIndex = INDEX_NONE;
			for (int32 index = 0; index < CurrentAddons.Num(); ++index)
			{
				if (CurrentAddons[index].EqualTo(this->AddonName))
				{
					FoundIndex = index;
					break;
				}
			}

			CurrentAddons.RemoveAt(FoundIndex);
			OrderViewModel->SetSelectedAddons(CurrentAddons);
		}
	}


}

void UVM_OrderAddon::SetAddonName(FText newAddonName)
{
	UE_MVVM_SET_PROPERTY_VALUE(AddonName, newAddonName);
}

void UVM_OrderAddon::SetIsSelected(bool newIsSelected)
{
	UE_MVVM_SET_PROPERTY_VALUE(IsSelected, newIsSelected);
}

void UVM_OrderAddon::ResetData()
{
	SetIsSelected(false);
	if (UOrderViewModel* OrderViewModel = Cast<UOrderViewModel>(GetOuter()))
	{
		TArray<FText> EmptyAddons;
		OrderViewModel->SetSelectedAddons(EmptyAddons);
	}
	UpdateVisualState();
}
