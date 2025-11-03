
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "WBP_RootWidget.generated.h"

class UOrderViewModel;

UCLASS()
class MVVM3_API UWBP_RootWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "MVVM")
	TSubclassOf<UOrderViewModel> ViewModelClassRef;

	UFUNCTION(BlueprintCallable)
	void EnableMainVM();
	
};
