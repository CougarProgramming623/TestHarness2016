#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */
 
const int PWM_UNUSED0 = 0;
const int PWM_WINCH = 1;
const int PWM_SHOOTER_L = 2;
const int PWM_SHOOTER_R = 3;
const int PWM_SHOOTER_TILT = 4;
const int PWM_DRIVE_FL = 5;
const int PWM_DRIVE_BR = 6;
const int PWM_DRIVE_FR = 7;
const int PWM_DRIVE_BL = 8;
const int PWM_UNUSED9 = 9;

const int REL_HOOK_RELEASE = 0;
const int REL_SHOOTER_KICK = 1;
const int REL_UNUSED2 = 2;
const int REL_UNUSED3 = 3;

const int AI_GYRO = 0;
const int AI_SHOOTER_ANGLE = 1;
const int AI_UNUSED2 = 2;
const int AI_UNUSED3 = 3;

const int DI_UNUSED0 = 0;
const int DI_UNUSED1 = 1;
const int DI_SHOOTER_KICK_COCKED = 2;
const int DI_SHOOTER_LOWER = 3;
//const int DI_SHOOTER_UPPER = 4;
const int DI_WINCH_REV_COUNTER = 5;
const int DI_UNUSED6 = 6;
const int DI_UNUSED7 = 7;
const int DI_UNUSED8 = 8;
const int DI_UNUSED9 = 9;

const int OI_JOYSTICK_DRIVER_L1 = 0;
const int OI_JOYSTICK_DRIVER_R2 = 1;
const int OI_BUTTONBOARD = 2;

const int OI_BB_SCALE = 1;
const int OI_BB_BALL_OUT = 2;
const int OI_BB_BALL_IN = 3;
const int OI_BB_SHOOT = 4;
const int OI_BB_SHOOTER_FULL_UP = 5;
const int OI_BB_SHOOTER_STORE = 6;
const int OI_BB_SHOOTER_AIM = 7;
const int OI_BB_SHOOTER_PICKUP = 8;
const int OI_BB_SHOOTER_PORT_UP = 9;
const int OI_BB_SHOOTER_PORT_DN = 10;
const int OI_BB_ARMS_UP = 11;
const int OI_BB_SHOOTER_MAN_UP = 12;
const int OI_BB_SHOOTER_MAN_DN = 13;

const int OI_LB_SHOOTER_PORT_DOWN = 1;
const int OI_LB_SHOOTER_PORT_UP = 2;
const int OI_LB_SHOOTER_PICKUP = 3;
const int OI_LB_SHOOTER_AIM = 4;
const int OI_LB_SHOOTER_STORE = 5;
const int OI_LB_SHOOTER_UP = 6;

const double SHOOTER_POT_SLOP = 0.02;
const double SHOOTER_POT_ALL_IN = 0.52;
const double SHOOTER_POT_90 = 0.43;
const double SHOOTER_POT_45 = 0.25;
const double SHOOTER_POT_SHOOT = SHOOTER_POT_45;
const double SHOOTER_POT_0 = 0.07;
const double SHOOTER_POT_ALL_OUT = 0.05;
const double SHOOTER_POT_PORT_UP = SHOOTER_POT_45;
const double SHOOTER_POT_PORT_DN = SHOOTER_POT_0;

const double SHOOTER_IN_SPEED = 0.25;
const double SHOOTER_OUT_SPEED = 0.25;
const double SHOOTER_SHOOT_SPEED = 0.5;

#endif
