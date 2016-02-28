#include "DriveCommand.h"
#include "Robot.h"

DriveCommand::DriveCommand() : Command("DriveCommand")
{
	// Use Requires() here to declare subsystem dependencies
	Requires(Robot::drivetrain.get());
}

// Called just before this Command runs the first time
void DriveCommand::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void DriveCommand::Execute()
{
	Robot::drivetrain->Drive(Robot::oi->getJoystickL1(), Robot::oi->getJoystickR2());
}

// Make this return true when this Command no longer needs to run execute()
bool DriveCommand::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void DriveCommand::End()
{
	Robot::drivetrain->Drive((double)0, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveCommand::Interrupted()
{
	End();
}
