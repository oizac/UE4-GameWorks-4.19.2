// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#pragma once
#include "BehaviorTree/BTDecorator.h"
#include "BTDecorator_DoesPathExist.generated.h"

UENUM()
namespace EPathExistanceQueryType
{
	enum Type
	{
		NavmeshRaycast2D UMETA(ToolTip = "Really Fast"),
		HierarchicalQuery UMETA(ToolTip = "Fast"),
		RegularPathFinding UMETA(ToolTip = "Slow"),
	};
}

/**
 * Cooldown decorator node.
 * A decorator node that bases its condition on whether a path exists between two points from the Blackboard.
 */
UCLASS()
class AIMODULE_API UBTDecorator_DoesPathExist : public UBTDecorator
{
	GENERATED_UCLASS_BODY()

protected:

	/** blackboard key selector */
	UPROPERTY(EditAnywhere, Category=Condition)
	struct FBlackboardKeySelector BlackboardKeyA;

	/** blackboard key selector */
	UPROPERTY(EditAnywhere, Category=Condition)
	struct FBlackboardKeySelector BlackboardKeyB;

public:

	// deprecated, set value of blackboard key A on initialization
	UPROPERTY()
	uint32 bUseSelf:1;

	UPROPERTY(EditAnywhere, Category=Condition)
	TEnumAsByte<EPathExistanceQueryType::Type> PathQueryType;

	/** "None" will result in default filter being used */
	UPROPERTY(Category=Node, EditAnywhere)
	TSubclassOf<class UNavigationQueryFilter> FilterClass;

	virtual bool CalculateRawConditionValue(class UBehaviorTreeComponent* OwnerComp, uint8* NodeMemory) const override;
	virtual FString GetStaticDescription() const override;
	virtual void InitializeFromAsset(class UBehaviorTree* Asset) override;

#if WITH_EDITOR
	virtual FName GetNodeIconName() const override;
#endif // WITH_EDITOR
};
