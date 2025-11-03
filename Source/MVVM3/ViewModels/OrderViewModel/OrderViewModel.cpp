
#include "MVVM3/ViewModels/OrderViewModel/OrderViewModel.h"

#include "Kismet/KismetSystemLibrary.h"

#include "MVVM3/ViewModels/VM_OrderItem/VM_OrderItem.h"
#include "MVVM3/ViewModels/VM_OrderAddon/VM_OrderAddon.h"

void UOrderViewModel::ExecuteOrderConfirmation()
{
	OnOrderConfirmed.Broadcast();
}

void UOrderViewModel::SetAvailableDrinks(TArray<FText> newAvailableDrinks)
{
	UE_MVVM_SET_PROPERTY_VALUE(AvailableDrinks, newAvailableDrinks);
}

void UOrderViewModel::SetAvailableAddons(TArray<FText> newAvailableAddons)
{
	UE_MVVM_SET_PROPERTY_VALUE(AvailableAddons, newAvailableAddons);
}

void UOrderViewModel::SetSelectedDrink(FText newSelectedDrink)
{
	UE_MVVM_SET_PROPERTY_VALUE(SelectedDrink, newSelectedDrink);
}

void UOrderViewModel::SetSelectedAddons(TArray<FText> newSelectedAddons)
{
	UE_MVVM_SET_PROPERTY_VALUE(SelectedAddons, newSelectedAddons);
}

void UOrderViewModel::SetOrderSummary(FText newOrderSummary)
{
	UE_MVVM_SET_PROPERTY_VALUE(OrderSummary, newOrderSummary);
}

void UOrderViewModel::CreateOrderSummary()
{
	if (!(SelectedDrink.IsEmpty()))
	{
		FString SummaryString;
		FText StaticText_YouOrdered = FText::FromString(TEXT("Вы заказали: "));

		SummaryString.Append(StaticText_YouOrdered.ToString());
		SummaryString.Append(TEXT(" "));
		SummaryString.Append(SelectedDrink.ToString());

		if (SelectedAddons.Num() == 0)
		{
			SummaryString.Append(TEXT("."));
		}
		else if (SelectedAddons.Num() == 1)
		{
			SummaryString.Append(TEXT(" с"));
			SummaryString.Append(CreateAddonInOrderSum(SelectedAddons[0]));
			SummaryString.Append(TEXT("."));
		}
		else if (SelectedAddons.Num() == 2)
		{
			SummaryString.Append(TEXT(" с"));
			SummaryString.Append(CreateAddonInOrderSum(SelectedAddons[0]));

			SummaryString.Append(TEXT("и"));
			SummaryString.Append(CreateAddonInOrderSum(SelectedAddons[1]));
			SummaryString.Append(TEXT("."));
		}
		else if (SelectedAddons.Num() == 3)
		{
			SummaryString.Append(TEXT(" с"));
			SummaryString.Append(CreateAddonInOrderSum(SelectedAddons[0]));
			SummaryString.Append(TEXT(","));

			SummaryString.Append(CreateAddonInOrderSum(SelectedAddons[1]));
			SummaryString.Append(TEXT("и"));

			SummaryString.Append(CreateAddonInOrderSum(SelectedAddons[2]));
			SummaryString.Append(TEXT("."));
		}

		SetOrderSummary(FText::FromString(SummaryString));
		OpenConfirmation();
	}
}

FString UOrderViewModel::CreateAddonInOrderSum(FText text)
{
	FString ResultString = (text.ToString());

	int32 StringLength = ResultString.Len();

	const TCHAR lastChar = ResultString[StringLength - 1];

	if (lastChar == TEXT('о'))
	{
		ResultString += TEXT("м");
	}
	else
	{
		ResultString += TEXT("ом");
	}
	return TEXT(" ") + (ResultString) + TEXT(" ");
}

void UOrderViewModel::SetInitializedDrinks(TArray<UVM_OrderItem*> newInitializedDrinks)
{
	UE_MVVM_SET_PROPERTY_VALUE(InitializedDrinks, newInitializedDrinks);
}

void UOrderViewModel::SetInitializedAddons(TArray<UVM_OrderAddon*> newInitializedAddons)
{
	UE_MVVM_SET_PROPERTY_VALUE(InitializedAddons, newInitializedAddons);
}

void UOrderViewModel::RequestQuit()
{
	UKismetSystemLibrary::QuitGame(GetWorld(), nullptr, EQuitPreference::Quit, true);
}

void UOrderViewModel::SetWidgetPageIndex(int32 newPageIndex)
{
	UE_MVVM_SET_PROPERTY_VALUE(WidgetPageIndex, newPageIndex);
}

void UOrderViewModel::OpenOrdersScreen()
{
	SetWidgetPageIndex(1);
}

void UOrderViewModel::OpenMainMenu()
{
	SetSelectedAddons(TArray<FText>());
	SetSelectedDrink(FText::GetEmpty());
	SetWidgetPageIndex(0);

	for (UVM_OrderItem* OrderItem : InitializedDrinks)
	{
		if (IsValid(OrderItem))
		{
			OrderItem->ResetData();
		}
	}

	for (UVM_OrderAddon* OrderAddon : InitializedAddons)
	{
		if (IsValid(OrderAddon))
		{
			OrderAddon->ResetData();
		}
	}
}

void UOrderViewModel::OpenConfirmation()
{
	SetWidgetPageIndex(2);
}
