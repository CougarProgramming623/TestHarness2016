#ifndef LiftSubsystem_H
#define LiftSubsystem_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class LiftSubsystem: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Relay *hookRelay;
	Talon *winch;
	Counter *winchRevCounter;

	bool hookReleased;

public:
	LiftSubsystem();
	void InitDefaultCommand();
	void ReleaseHook();
	void SecureHook();
	void LiftWinch();
	void StopWinch();
};

#endif
