#include "PickupCommand.h"
#include "Robot.h"
#include "../RobotMap.h"

PickupCommand::PickupCommand() : Command("PickupCommand")
{
	// Use Requires() here to declare subsystem dependencies
	Requires(Robot::shooter.get());
}

// Called just before this Command runs the first time
void PickupCommand::Initialize()
{
	Robot::shooter->setAngleOverride(false);
}

// Called repeatedly when this Command is scheduled to run
void PickupCommand::Execute()
{
	double angle = Robot::shooter->getShooterAngle();

	if ((angle + SHOOTER_POT_SLOP) > OI_LB_SHOOTER_PICKUP) {
		Robot::shooter->Lower();
	} else if ((angle - SHOOTER_POT_SLOP) < OI_LB_SHOOTER_PICKUP) {
		Robot::shooter->Raise();
	} else {
		Robot::shooter->Stop();
	}
	Robot::shooter->RunShooter(SHOOTER_IN_SPEED);
}

// Make this return true when this Command no longer needs to run execute()
bool PickupCommand::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void PickupCommand::End()
{
	Robot::shooter->StopShooter();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void PickupCommand::Interrupted()
{
	End();
}
