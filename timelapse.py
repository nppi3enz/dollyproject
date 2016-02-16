#!/usr/bin/python
from Adafruit_MotorHAT import Adafruit_MotorHAT, Adafruit_DCMotor

import atexit
import microgear.client as client
import time

# create a default object, no changes to I2C address or frequency
mh = Adafruit_MotorHAT(addr=0x70)

# recommended for auto-disabling motors on shutdown!
def turnOffMotors():
	mh.getMotor(1).run(Adafruit_MotorHAT.RELEASE)
	mh.getMotor(2).run(Adafruit_MotorHAT.RELEASE)
	mh.getMotor(3).run(Adafruit_MotorHAT.RELEASE)
	mh.getMotor(4).run(Adafruit_MotorHAT.RELEASE)

atexit.register(turnOffMotors)

################################# DC motor test!
myMotor = mh.getMotor(3)

# set the speed to start, from 0 (off) to 255 (max speed)
myMotor.setSpeed(100)
myMotor.run(Adafruit_MotorHAT.FORWARD);
# turn on motor
myMotor.run(Adafruit_MotorHAT.RELEASE);

mode = 0

def right(sec):
	myMotor.run(Adafruit_MotorHAT.BACKWARD)
	myMotor.setSpeed(255)
	time.sleep(sec)

def left(sec):
	myMotor.run(Adafruit_MotorHAT.FORWARD)
	myMotor.setSpeed(255)
	time.sleep(sec)


def stop(sec):
	mode = 0
	turnOffMotors()
	time.sleep(sec)

iSecond = input('Input interval for 1 round (sec): ')
iRound =  input('Input amount of round: ')
iStop = input('Input interval stop (sec): ')
iMode =  input('1-LEFT 2-RIGHT: ')
for x in range(iRound):
	print "Round "+str(x+1)
	if iMode==1:
		left(iSecond)
		stop(iStop)
	else:
		right(iSecond)
		stop(iStop)

print "Complete!"
