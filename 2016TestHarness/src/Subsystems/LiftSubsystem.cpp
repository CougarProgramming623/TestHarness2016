#include "LiftSubsystem.h"
#include "../RobotMap.h"

const double WINCH_SPEED = 0.5;
const int WINCH_REVS_MAX = 10;

LiftSubsystem::LiftSubsystem() :
		Subsystem("LiftSubsystem")
{
	hookRelay = new Relay(REL_HOOK_RELEASE);
	winch = new Talon(PWM_WINCH);
	winchRevCounter = new Counter(DI_WINCH_REV_COUNTER);

	hookRelay->Set(Relay::Value::kReverse);
	winchRevCounter->SetUpDownCounterMode();
	hookReleased = false;
}

void LiftSubsystem::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void LiftSubsystem::ReleaseHook()
{
	hookRelay->Set(Relay::Value::kForward);
	hookReleased = true;
}

void LiftSubsystem::SecureHook()
{
	hookRelay->Set(Relay::Value::kReverse);
}

void LiftSubsystem::LiftWinch()
{
	if (!hookReleased) {
		DriverStation::ReportError("Tried to lift winch but hook is not released!");
		return;
	}
	DriverStation::ReportWarning("Winch Revs: " + std::to_string(winchRevCounter->Get()));
	if (winchRevCounter->Get() >= WINCH_REVS_MAX) {
		winch->StopMotor();
	} else {
		winch->SetSpeed(WINCH_SPEED);
	}
}

void LiftSubsystem::StopWinch()
{
	winch->StopMotor();
}
