#include "LowerShooter.h"
#include "Robot.h"

LowerShooter::LowerShooter() : Command("LowerShooter")
{
	// Use Requires() here to declare subsystem dependencies
	Requires(Robot::shooter.get());
}

// Called just before this Command runs the first time
void LowerShooter::Initialize()
{
	Robot::shooter->setAngleOverride(true);
}

// Called repeatedly when this Command is scheduled to run
void LowerShooter::Execute()
{
	if (Robot::shooter->isShooterLowerLimit()) {
		Robot::shooter->Lower();
	} else {
		Robot::shooter->Stop();
	}
	DriverStation::ReportError("Shooter Pot: " + std::to_string(Robot::shooter->getShooterAngle()));
}

// Make this return true when this Command no longer needs to run execute()
bool LowerShooter::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void LowerShooter::End()
{
	Robot::shooter->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LowerShooter::Interrupted()
{
	End();
}
