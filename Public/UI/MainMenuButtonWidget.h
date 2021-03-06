// � 2015 Mark Vatsel

#pragma once

#include "Manipulators_01.h"
#include "MainMenuHUD.h"


class SMainMenuButton : public SCompoundWidget
{
	TWeakObjectPtr<class AMainMenuHUD> OwnerHud;
	
	bool inactive = false; //greyed out
	bool hoverMode = false;	

	TAttribute<FText> buttonText;
	TAttribute<FSlateFontInfo> font;
	TAttribute<TOptional<bool>> inactiveInput;
	TAttribute<TOptional<FLinearColor>> inactiveTextColour;
	TAttribute<TOptional<FLinearColor>> textColour;
	TAttribute<TOptional<FLinearColor>> hoverTextColour;
	
	FSlateColor GetTextColour() const;
	virtual FReply OnMouseButtonDown(const FGeometry& aGeometry, const FPointerEvent& mouseEvent) override;
	virtual void OnMouseEnter(const FGeometry& aGeometry, const FPointerEvent& mouseEvent) override;
	virtual void OnMouseLeave(const FPointerEvent& mouseEvent) override;
	SLATE_BEGIN_ARGS(SMainMenuButton)
	{}
	SLATE_ARGUMENT(TWeakObjectPtr<class AMainMenuHUD>, OwnerHud)
	SLATE_ARGUMENT(FText, buttonText)
	SLATE_ARGUMENT(FSlateFontInfo, font)
	SLATE_ARGUMENT(TOptional<bool>, inactiveInput)
	SLATE_ARGUMENT(TOptional<FLinearColor>, inactiveTextColour)
	SLATE_ARGUMENT(TOptional<FLinearColor>, textColour)
	SLATE_ARGUMENT(TOptional<FLinearColor>, hoverTextColour)

	SLATE_EVENT(FOnClicked, buttonClickedEvent)

	SLATE_END_ARGS()
public:
	

	FOnClicked buttonClickedEvent;
	void Construct(const FArguments& inArgs);
};