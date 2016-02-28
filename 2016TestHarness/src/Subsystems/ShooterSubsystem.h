#ifndef ShooterSubsystem_H
#define ShooterSubsystem_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class ShooterSubsystem: public Subsystem
{
private:
	Talon *raiseLower;
	Talon *wheelLeft;
	Talon *wheelRight;
	Relay *kicker;

	DigitalInput *shooterUpperLimit;
	DigitalInput *shooterLowerLimit;
	DigitalInput *kickerCocked;

	AnalogPotentiometer *shooterAngle;

	bool angleOverride;
	double targetAngle;

public:
	ShooterSubsystem();
	void InitDefaultCommand();
	void RaiseShooter();
	void LowerShooter();
	void Raise();
	void Lower();
	void Stop();
	void RunShooter(double speed);
	void StopShooter();
//	bool isShooterUpperLimit();
	bool isShooterLowerLimit();
	double getShooterAngle();
	bool isAngleOverride();
	void setAngleOverride(bool override);
	bool isCocked();
	void runKickerForward();
	void runKickerReverse();
	void stopKicker();
};

#endif
