
#pragma once

#include "CoreMinimal.h"
#include "MVVMViewModelBase.h"
#include "OrderViewModel.generated.h"

class UVM_OrderItem;
class UVM_OrderAddon;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnOrderConfirmedSimple);

UCLASS()
class MVVM3_API UOrderViewModel : public UMVVMViewModelBase
{
	GENERATED_BODY()

	
public:

	// Bind Event for OnOrderConfirmed

	UPROPERTY(BlueprintAssignable, Category = "Order Events")
	FOnOrderConfirmedSimple OnOrderConfirmed;

	UFUNCTION(BlueprintCallable, Category = "Order Logic")
	void ExecuteOrderConfirmation();

	// Main MVVM variables and their setters

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, FieldNotify, Setter, Category = "Data Setup")
	TArray<FText> AvailableDrinks;
		UFUNCTION(BlueprintSetter)
		void SetAvailableDrinks(TArray<FText> newAvailableDrinks);


	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, FieldNotify, Setter, Category = "Data Setup")
	TArray<FText> AvailableAddons;
		UFUNCTION(BlueprintSetter)
		void SetAvailableAddons(TArray<FText> newAvailableAddons);


	UPROPERTY(BlueprintReadOnly, FieldNotify, Setter, Category = "Data Setup")
	FText SelectedDrink;
		UFUNCTION(BlueprintSetter)
		void SetSelectedDrink(FText newSelectedDrink);

	UPROPERTY(BlueprintReadOnly, FieldNotify, Setter, Category = "Data Setup")
	TArray<FText> SelectedAddons;
		UFUNCTION(BlueprintSetter)
		void SetSelectedAddons(TArray<FText> newSelectedAddons);


	UPROPERTY(BlueprintReadOnly, FieldNotify, Setter, Category = "Data Setup")
	FText OrderSummary;
		UFUNCTION(BlueprintSetter)
		void SetOrderSummary(FText newOrderSummary);


	// WidgetSwitcher

	UPROPERTY(BlueprintReadOnly, FieldNotify, Setter, Category = "Navigation")
	int32 WidgetPageIndex = 0;
		UFUNCTION(BlueprintSetter)
		void SetWidgetPageIndex(int32 newPageIndex);


	// Functions

	UFUNCTION(BlueprintCallable)
	void CreateOrderSummary();

	UFUNCTION()
	FString CreateAddonInOrderSum(FText text);

	/////////////////   WBP_RootWidget   //////////////////

	// Items

	UPROPERTY(BlueprintReadOnly, FieldNotify, Setter, Category = "ItemData")
	TArray<UVM_OrderItem*> InitializedDrinks;
		UFUNCTION(BlueprintSetter)
		void SetInitializedDrinks(TArray<UVM_OrderItem*> newInitializedDrinks);

	UPROPERTY(BlueprintReadOnly, FieldNotify, Setter, Category = "ItemData")
	TArray<UVM_OrderAddon*> InitializedAddons;
		UFUNCTION(BlueprintSetter)
		void SetInitializedAddons(TArray<UVM_OrderAddon*> newInitializedAddons);

	///////////////////////////////////////////////////////

	
	// ButtonBindingsForWidgetSwitcher

	UFUNCTION(BlueprintCallable, Category = "Actions")
	void RequestQuit();

	UFUNCTION(BlueprintCallable, Category = "Actions")
	void OpenOrdersScreen();

	UFUNCTION(BlueprintCallable, Category = "Actions")
	void OpenMainMenu(); // Помимо открытия главного меню вызывает очистку данных, вводимых пользователем

	UFUNCTION(BlueprintCallable, Category = "Actions")
	void OpenConfirmation();

};
