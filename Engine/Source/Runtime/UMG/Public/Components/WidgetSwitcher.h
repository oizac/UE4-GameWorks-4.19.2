// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "WidgetSwitcher.generated.h"

/**
 * A widget switcher is like a tab control, but without tabs. At most one widget is visible at time.
 */
UCLASS()
class UMG_API UWidgetSwitcher : public UPanelWidget
{
	GENERATED_UCLASS_BODY()

public:
	/** The slot index to display */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Switcher", meta=( UIMin=0, ClampMin=0 ))
	int32 ActiveWidgetIndex;

public:

	/** Gets the number of widgets that this switcher manages. */
	UFUNCTION(BlueprintCallable, Category="Switcher")
	int32 GetNumWidgets() const;

	/** Gets the slot index of the currently active widget */
	UFUNCTION(BlueprintCallable, Category="Switcher")
	int32 GetActiveWidgetIndex() const;

	/** Activates the widget at the specified index. */
	UFUNCTION(BlueprintCallable, Category="Switcher")
	void SetActiveWidgetIndex( int32 Index );

	/** Activates the widget and makes it the active index. */
	UFUNCTION(BlueprintCallable, Category="Switcher")
	void SetActiveWidget(UWidget* Widget);

	// UObject interface
	virtual void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent) override;
	// End of UObject interface
	
	// UWidget interface
	virtual void SynchronizeProperties() override;
	virtual void ReleaseSlateResources(bool bReleaseChildren) override;
	// End of UWidget interface

#if WITH_EDITOR
	virtual const FSlateBrush* GetEditorIcon() override;
	virtual const FText GetPaletteCategory() override;
	virtual void OnDescendantSelected(UWidget* DescendantWidget) override;
	virtual void OnDescendantDeselected(UWidget* DescendantWidget) override;
#endif

protected:

	// UPanelWidget
	virtual UClass* GetSlotClass() const override;
	virtual void OnSlotAdded(UPanelSlot* Slot) override;
	virtual void OnSlotRemoved(UPanelSlot* Slot) override;
	// End UPanelWidget

protected:

	TSharedPtr<class SWidgetSwitcher> MyWidgetSwitcher;

protected:
	// UWidget interface
	virtual TSharedRef<SWidget> RebuildWidget() override;
	// End of UWidget interface
};
