// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"
#include "Engine/World.h"

void UTankTurret::Rotate(float PercentOfRotationSpeed)
{
	// move the turret the right amount this frame
	// given rotation speed per frame and frame time
	auto ClampedPercentOfRotationSpeed = FMath::Clamp<float>(PercentOfRotationSpeed, -1, 1);
	auto RotationChange = ClampedPercentOfRotationSpeed * MaxRotationDegreesPerSec * GetWorld()->DeltaTimeSeconds;
	auto NewRotation = RelativeRotation.Yaw + RotationChange;

	SetRelativeRotation(FRotator(0, NewRotation, 0));
}



