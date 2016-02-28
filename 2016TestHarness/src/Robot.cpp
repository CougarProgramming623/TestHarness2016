#include "Robot.h"

std::shared_ptr<DriveSubsystem> Robot::drivetrain;
std::shared_ptr<ShooterSubsystem> Robot::shooter;

std::unique_ptr<OI> Robot::oi;

void Robot::RobotInit()	{
	drivetrain.reset(new DriveSubsystem());
	shooter.reset(new ShooterSubsystem());

	oi.reset(new OI());

	CameraServer::GetInstance()->SetQuality(25);
	//the camera name (ex "cam0") can be found through the roborio web interface
	CameraServer::GetInstance()->StartAutomaticCapture("cam1");
}

void Robot::AutonomousInit() {

}

void Robot::AutonomousPeriodic() {
	//Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
	// This makes sure that the autonomous stops running when
	// teleop starts running. If you want the autonomous to
	// continue until interrupted by another command, remove
	// this line or comment it out.
	//if (autonomousCommand != NULL)
	//	autonomousCommand->Cancel();
}

void Robot::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::TestPeriodic() {
	LiveWindow::GetInstance()->Run();
}

START_ROBOT_CLASS(Robot)
