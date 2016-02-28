#include "RaiseShooter.h"
#include "Robot.h"

RaiseShooter::RaiseShooter() : Command("RaiseShooter")
{
	// Use Requires() here to declare subsystem dependencies
	Requires(Robot::shooter.get());
}

// Called just before this Command runs the first time
void RaiseShooter::Initialize()
{
	Robot::shooter->setAngleOverride(true);
}

// Called repeatedly when this Command is scheduled to run
void RaiseShooter::Execute()
{
	//if (Robot::shooter->isShooterUpperLimit()) {
		Robot::shooter->Raise();
	//} else {
	//	Robot::shooter->Stop();
	//}
	//DriverStation::ReportError("Shooter Pot: " + std::to_string(Robot::shooter->getShooterAngle()));
}

// Make this return true when this Command no longer needs to run execute()
bool RaiseShooter::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void RaiseShooter::End()
{
	Robot::shooter->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RaiseShooter::Interrupted()
{
	End();
}
