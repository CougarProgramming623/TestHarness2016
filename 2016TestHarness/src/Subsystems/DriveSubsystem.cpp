#include "DriveSubsystem.h"
#include "../Commands/DriveCommand.h"
#include "RobotMap.h"

DriveSubsystem::DriveSubsystem() :
		Subsystem("DriveSubsystem")
{

	drive = new RobotDrive(PWM_DRIVE_FL, PWM_DRIVE_BL, PWM_DRIVE_FR, PWM_DRIVE_BR);
	drive->SetInvertedMotor(RobotDrive::MotorType::kFrontLeftMotor, true);
	drive->SetInvertedMotor(RobotDrive::MotorType::kRearLeftMotor, true);
	drive->SetInvertedMotor(RobotDrive::MotorType::kFrontRightMotor, true);
	drive->SetInvertedMotor(RobotDrive::MotorType::kRearRightMotor, true);
}

void DriveSubsystem::InitDefaultCommand()
{
	SetDefaultCommand(new DriveCommand());
}

void DriveSubsystem::Drive(Joystick *joyL1, Joystick *joyR2)
{
	drive->TankDrive(joyL1, joyR2);
}

void DriveSubsystem::Drive(double left, double right)
{
	drive->TankDrive(left, right);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
