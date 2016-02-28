#include "OI.h"
#include "RobotMap.h"

#include "Commands/RaiseShooter.h"
#include "Commands/LowerShooter.h"
#include "Commands/ShootCommand.h"

OI::OI()
{
	joyL1 = new Joystick(OI_JOYSTICK_DRIVER_L1);
	joyR2 = new Joystick(OI_JOYSTICK_DRIVER_R2);
	bboard = new Joystick(OI_BUTTONBOARD);

	scale = new JoystickButton(bboard, OI_BB_SCALE);
	ballOut = new JoystickButton(bboard, OI_BB_BALL_OUT);
	ballIn = new JoystickButton(bboard, OI_BB_BALL_IN);
	shoot = new JoystickButton(bboard, OI_BB_SHOOT);
	fullUpShooter = new JoystickButton(bboard, OI_BB_SHOOTER_FULL_UP);
	storeShooter = new JoystickButton(bboard, OI_BB_SHOOTER_STORE);
	aimShooter = new JoystickButton(bboard, OI_BB_SHOOTER_AIM);
	pickupShooter = new JoystickButton(bboard, OI_BB_SHOOTER_PICKUP);
	portupShooter = new JoystickButton(bboard, OI_BB_SHOOTER_PORT_UP);
	portdnShooter = new JoystickButton(bboard, OI_BB_SHOOTER_PORT_DN);
	armsUp = new JoystickButton(bboard, OI_BB_ARMS_UP);
	raiseShooter = new JoystickButton(bboard, OI_BB_SHOOTER_MAN_UP);
	lowerShooter = new JoystickButton(bboard, OI_BB_SHOOTER_MAN_DN);

	//ballOut->WhenPressed();
	//ballOut->WhenReleased();
	shoot->WhileHeld(new ShootCommand());
	//fullUpShooter->WhileHeld();
	//storeShooter->WhenPressed();
	//aimShooter->WhileHeld();
	//pickupShooter->WhileHeld();
	//portupShooter->WhileHeld();
	//portdnShooter->WhileHeld();
	//armsUp->WhenPressed();
	raiseShooter->WhileHeld(new RaiseShooter());
	lowerShooter->WhileHeld(new LowerShooter());
}

Joystick *OI::getJoystickL1()
{
	return joyL1;
}

Joystick *OI::getJoystickR2()
{
	return joyR2;
}
