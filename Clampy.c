#pragma config(Sensor, in2,    poten,          sensorPotentiometer)
#pragma config(Motor,  port1,           arm,           tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           frontR,        tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port3,           frontL,        tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port4,           hback,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           back,          tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port6,           swerve,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          hfront,        tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "JoystickDriver.c";
int output;

int loge (int joystickvalue) {
	if (joystickvalue >= 0) {
		output = (joystickvalue * joystickvalue) /127;
} else {
		output = (joystickvalue * joystickvalue) / -127;
	}
	return output;
}

task main()
{
	while (true) {
    if (vexRT[Btn7U] == 1) { //arm up
				motor[arm] = 100;
		} else if (vexRT[Btn7D] == 1) { //arm down
				motor[arm] = -100;
		} else if (vexRT[Btn6U] == 1) { // log up
			motor[hback] = 50;
			motor[hfront] = 50;
		} else if (vexRT[Btn6D] == 1) {
			motor[hback] = -50;
			motor[hfront] = -50;
		} else if (vexRT[Btn5U] == 1) {
			motor[hback] = 20;
			motor[hfront] = -20;
		} else {
			motor[arm] = 0;
			motor[hfront] = 0;
			motor[hback] = 0;
		}







	getJoystickSettings(joystick);
	motor[frontR] = loge(vexRT[Ch1]-vexRT[Ch2]); //joystick control works fine
	motor[frontL] = loge(vexRT[Ch1]+vexRT[Ch2]);
	motor[back] = loge(vexRT[Ch2]);
	motor[swerve] = -loge(vexRT[Ch4]); //new


}

}
