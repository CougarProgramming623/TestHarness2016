#include "ShooterSubsystem.h"
#include "../Commands/RaiseShooter.h"
#include "../Commands/LowerShooter.h"
#include "RobotMap.h"

const double RAISE_SPEED = -0.3;
const double LOWER_SPEED = 0.3;

ShooterSubsystem::ShooterSubsystem() :
		Subsystem("ShooterSubsystem")
{
	raiseLower = new Talon(PWM_SHOOTER_TILT);
	wheelLeft = new Talon(PWM_SHOOTER_L);
	wheelRight = new Talon(PWM_SHOOTER_R);
	kicker = new Relay(REL_SHOOTER_KICK);

	//shooterUpperLimit = new DigitalInput(DI_SHOOTER_UPPER);
	shooterLowerLimit = new DigitalInput(DI_SHOOTER_LOWER);
	kickerCocked = new DigitalInput(DI_SHOOTER_KICK_COCKED);

	shooterAngle = new AnalogPotentiometer(AI_SHOOTER_ANGLE);

	wheelLeft->SetInverted(true);
	wheelLeft->SetSafetyEnabled(false);
	wheelRight->SetSafetyEnabled(false);
}

void ShooterSubsystem::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new RaiseShooter());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void ShooterSubsystem::Raise()
{
	raiseLower->SetSpeed(RAISE_SPEED);
}

void ShooterSubsystem::Lower()
{
	if (shooterAngle->Get() > SHOOTER_POT_0) {
		raiseLower->SetSpeed(LOWER_SPEED);
	} else {
		raiseLower->SetSpeed(LOWER_SPEED / 2);
	}
}

void ShooterSubsystem::Stop()
{
	raiseLower->StopMotor();
}

void ShooterSubsystem::RunShooter(double speed)
{
	wheelLeft->SetSpeed(speed);
	wheelRight->SetSpeed(speed);
}

void ShooterSubsystem::StopShooter()
{
	wheelLeft->StopMotor();
	wheelRight->StopMotor();
}

//bool ShooterSubsystem::isShooterUpperLimit()
//{
//	return shooterUpperLimit->Get();
//}

bool ShooterSubsystem::isShooterLowerLimit()
{
	return shooterLowerLimit->Get();
}

double ShooterSubsystem::getShooterAngle()
{
	return shooterAngle->Get();
}

bool ShooterSubsystem::isAngleOverride()
{
	return angleOverride;
}

void ShooterSubsystem::setAngleOverride(bool override)
{
	angleOverride = override;
}

bool ShooterSubsystem::isCocked()
{
	return kickerCocked->Get();
}

void ShooterSubsystem::runKickerForward()
{
	kicker->Set(Relay::Value::kForward);
}

void ShooterSubsystem::runKickerReverse()
{
	kicker->Set(Relay::Value::kReverse);
}

void ShooterSubsystem::stopKicker()
{
	kicker->Set(Relay::Value::kOff);
}
