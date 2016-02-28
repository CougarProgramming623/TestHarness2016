#include "ShootCommand.h"
#include "Robot.h"
#include "RobotMap.h"

ShootCommand::ShootCommand() : Command("ShootCommand")
{
	// Use Requires() here to declare subsystem dependencies
	Requires(Robot::shooter.get());
}

// Called just before this Command runs the first time
void ShootCommand::Initialize()
{
	done = false;
	shot = false;
}

// Called repeatedly when this Command is scheduled to run
void ShootCommand::Execute()
{
	DriverStation::ReportError("Cocked: " + std::to_string(Robot::shooter->isCocked()));
	if (!shot) {
		if (Robot::shooter->isCocked()) {
			shot = true;
			Robot::shooter->runKickerReverse();
			Robot::shooter->StopShooter();
		} else {
			Robot::shooter->RunShooter(SHOOTER_SHOOT_SPEED);
			Robot::shooter->runKickerForward();
		}
	} else {
		if (!Robot::shooter->isCocked()) {
			Robot::shooter->stopKicker();
		}
	}
}

// Make this return true when this Command no longer needs to run execute()
bool ShootCommand::IsFinished()
{
	return done;
}

// Called once after isFinished returns true
void ShootCommand::End()
{
	Robot::shooter->stopKicker();
	Robot::shooter->StopShooter();
	return;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShootCommand::Interrupted()
{
	End();
}
