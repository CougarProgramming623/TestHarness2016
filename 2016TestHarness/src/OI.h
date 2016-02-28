#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
private:
	Joystick *joyL1;
	Joystick *joyR2;
	Joystick *bboard;

	JoystickButton *scale;
	JoystickButton *ballOut;
	JoystickButton *ballIn;
	JoystickButton *shoot;
	JoystickButton *fullUpShooter;
	JoystickButton *storeShooter;
	JoystickButton *aimShooter;
	JoystickButton *pickupShooter;
	JoystickButton *portupShooter;
	JoystickButton *portdnShooter;
	JoystickButton *armsUp;
	JoystickButton *raiseShooter;
	JoystickButton *lowerShooter;

public:
	OI();
	Joystick *getJoystickL1();
	Joystick *getJoystickR2();
};

#endif
