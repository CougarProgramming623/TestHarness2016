#ifndef DriveSubsystem_H
#define DriveSubsystem_H

#include "WPILib.h"

class DriveSubsystem: public Subsystem
{
private:
	RobotDrive *drive;

public:
	DriveSubsystem();
	void InitDefaultCommand();
	void Drive(double left, double right);
	void Drive(Joystick *joyL1, Joystick *joyR2);
};

#endif
