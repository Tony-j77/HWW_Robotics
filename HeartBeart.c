#pragma config(Sensor, in1,    log,            sensorLineFollower)
#pragma config(Sensor, in2,    pot,            sensorPotentiometer)
#pragma config(Sensor, in3,    or,             sensorLineFollower)
#pragma config(Sensor, in4,    rlog,           sensorLineFollower)
#pragma config(Sensor, dgtl1,  leftTouch,      sensorTouch)
#pragma config(Sensor, dgtl2,  rightTouch,     sensorTouch)
#pragma config(Sensor, dgtl3,  leftL,          sensorLEDtoVCC)
#pragma config(Sensor, dgtl4,  midL,           sensorLEDtoVCC)
#pragma config(Sensor, dgtl5,  rightL,         sensorLEDtoVCC)
#pragma config(Sensor, dgtl6,  rightSwitch,          sensorTouch)
#pragma config(Motor,  port1,           arm,           tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           frontR,        tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port3,           frontL,        tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port4,           hback,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           back,          tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port6,           swerve,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          hfront,        tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "JoystickDriver.c";
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

//scale for joystick motor control

task main() {
	while (1 == 1) {

	//joystick controls
	getJoystickSettings(joystick);

	motor[frontR] = vexRT[Ch1]-vexRT[Ch2];
	motor[frontL] = vexRT[Ch1]+vexRT[Ch2];
	motor[back] = vexRT[Ch2];
	motor[swerve] = -vexRT[Ch4]; //new

		if (vexRT[Btn8U] == 1 && vexRT[Btn5D] == 0) {
			motor[back] = 127;
			motor[frontL] = 127;
			motor[frontR] = -127;
		} else if (vexRT[Btn8U] == 1 && vexRT[Btn5D] == 1) {
			motor[back] = -0;
			motor[frontL] = 30;
			motor[frontR] = -30;
		} else if (vexRT[Btn8D] == 1 && vexRT[Btn5D] == 0) {
			motor[back] = -127;
			motor[frontL] = -127;
			motor[frontR] = 127;
		} else if (vexRT[Btn8D] == 1 && vexRT[Btn5D] == 1) {
			motor[back] = -30;
			motor[frontL] = -30;
			motor[frontR] = 30;
		} else if (vexRT[Btn8R] == 1 && vexRT[Btn5D] == 0) {
			motor[frontL] = 127;
			motor[frontR] = 127;
		} else if (vexRT[Btn8R] == 1 && vexRT[Btn5D] == 1) {
			motor[frontL] = 30;
			motor[frontR] = 30;
		} else if (vexRT[Btn8L] == 1 && vexRT[Btn5D] == 0) {
			motor[frontL] = -127;
			motor[frontR] = -127;
		} else if (vexRT[Btn8L] == 1 && vexRT[Btn5D] == 1) {
			motor[frontL] = -30;
			motor[frontR] = -30;
		} else if (vexRT[Btn7L] == 1 && vexRT[Btn5D] == 0) {
			motor[swerve] = -127;
		} else if (vexRT[Btn7L] == 1 && vexRT[Btn5D] == 1){
			motor[swerve] = -50;
		} else if (vexRT[Btn7R] == 1 && vexRT[Btn5D] == 0){
			motor[swerve] = 127;
		} else if (vexRT[Btn7R] == 1 && vexRT[Btn5D] == 1) {
			motor[swerve] = 50;
		} else if (vexRT[Btn7U] == 1) { //arm up needs work

				motor[arm] = 100;


		} else if (vexRT[Btn7D] == 1) { //arm down
			//if (SensorValue[pot] > 50 ) {
				motor[arm] = -100;
			//} else {
				//motor[arm] = 0;
					//if (SensorValue[pot] < 1000) {
						//motor[arm] = 100;
					//} else {
						//motor[arm] = 0;
				//}
			//}


		} else if (vexRT[Btn6U] == 1) {
			motor[hback] = 50;
			motor[hfront] = 50;
		} else if (vexRT[Btn6D] == 1) {
			motor[hback] = -50;
			motor[hfront] = -50;
		} else if (vexRT[Btn5U] == 1) {
			motor[hback] = 20;
			motor[hfront] = -20;
		} else {
			motor[back] = 0;
			motor[frontL] = 0;
			motor[frontR] = 0;
			motor[swerve] = 0;
			motor[arm] = 0;
			motor[hfront] = 0;
			motor[hback] = 0;
			SensorValue[dgtl3] = 0;
		}
		if (SensorValue[dgtl2] == 1) { //bumper
			SensorValue[dgtl5] = 1;
		} else {
			SensorValue[dgtl5] = 0;
		}
		if (SensorValue[dgtl1] == 1) { //bumper
			SensorValue[dgtl3] = 1;
		} else {
			SensorValue[dgtl3] = 0;
		}

		if (SensorValue[in1] < 700) {
			SensorValue[dgtl3] = 1;
		} else {
			SensorValue[dgtl3] = 0;
		}

		if(SensorValue[in4] < 2500) {
			SensorValue[dgtl4] = 1;
		} else {
			SensorValue[dgtl4] = 0;
		}

		if (vexRT[Btn7D] == 1) {
			while (SensorValue[in4] < 3000) {

			}
		} else {

	}


		//if (SensorValue[in3] < 3000 ) {
			//SensorValue[dgtl4] = 0;
		//} else {
			//SensorValue[dgtl4] = 1;
		//}


		//if (SensorValue[in4] < 1000) {
			///motor[swerve] = 30;
			//SensorValue[dgtl4] = 1;
		//} else {
			//motor[swerve] = 0;
			//SensorValue[dgtl4] = 0;
		//}

	}
}
