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
myMotor.setSpeed(1)
myMotor.run(Adafruit_MotorHAT.FORWARD);
# turn on motor
myMotor.run(Adafruit_MotorHAT.RELEASE);

gearkey = DEFINE_HERE
gearsecret = DEFINE_HERE
appid = DEFINE_HERE

client.create(gearkey,gearsecret,appid)

mode = 0

def connection():
    print "Now I am connected with netpie"

def subscription(topic,message):
    print topic+" "+message
    if message=="STOP":
    	stop()
    elif message=="LEFT":
    	left()
    elif message=="RIGHT":
    	right()

def right():
	myMotor.run(Adafruit_MotorHAT.BACKWARD)
	for i in range(255):
		print "RIGHT"+str(i)
		myMotor.setSpeed(i)
		time.sleep(0.001)

def left():
	myMotor.run(Adafruit_MotorHAT.FORWARD)
	for i in range(255):
		print "LEFT"+str(i)
		myMotor.setSpeed(i)
		time.sleep(0.001)


def stop():
	mode = 0
	turnOffMotors()

client.setname("remote")
client.setalias("raspberrypi")
client.on_connect = connection
client.on_message = subscription
client.subscribe("/remote2")

client.connect(True)
