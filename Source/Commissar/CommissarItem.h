// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "CommissarItem.generated.h"

UCLASS()
class COMMISSAR_API ACommissarItem : public AActor
{
	GENERATED_BODY()

		// Properties
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = ItemText)
		FString ItemName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = ItemText)
		FString ItemDescription;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Statistic)
		int32 Value;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Interaction)
		int InventorySquaresOccupied;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Mesh)
		UStaticMeshComponent* Mesh;

	UPROPERTY(EditDefaultsOnly, Category = Sound)
		USoundBase* PickupSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Assets)
		UTexture2D* BigIcon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Assets)
		UTexture2D* SmallIcon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Interaction)
		bool bCanBePickedUp;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Uses)
		bool bHasInfiniteUses;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Uses)
		bool bHasInfiniteMaxUses;

	// In other words how many shots are in one "clip"
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Uses)
		int MaxUses;

	// Count of how many uses are left
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Uses)
		int Uses;

	// Methods
public:
	// Sets default values for this actor's properties
	ACommissarItem();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Interaction

	UFUNCTION(BlueprintCallable, Category = Interaction)
		virtual void OnUsed();

	UFUNCTION(BlueprintCallable, Category = Interaction)
		virtual void PickedUp();

	UFUNCTION(BlueprintCallable, Category = Interaction)
		virtual void Dropped();

	/* Player is looking at */
	virtual void OnBeginFocus();

	/* Player is no longer looking at */
	virtual void OnEndFocus();

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

};
