# USAGE
# python webcam.py --face cascades/haarcascade_frontalface_default.xml

# import the necessary packages
from pyimagesearch.facedetector import FaceDetector
from pyimagesearch import imutils
from picamera.array import PiRGBArray
from picamera import PiCamera
import numpy as np
import argparse
import time
import cv2

# initialize the current frame of the video, along with the list of
# ROI points along with whether or not this is input mode
frame = None
frame2 = (0,0)
roiPts = []
inputMode = False

def selectROI(event, x, y, flags, param):
	# if we are in ROI selection mode, the mouse was clicked,
	# and we do not already have four points, then update the
	# list of ROI points with the (x, y) location of the click
	# and draw the circle
	if inputMode and event == cv2.EVENT_LBUTTONDOWN and len(roiPts) < 4:
		roiPts.append((x, y))
		cv2.circle(frame, (x, y), 4, (0, 255, 0), 2)
		cv2.imshow("frame", frame)



#set threshold pixel
threshold = 10
cSX = 111
cSY = 76
cEX = 187
cEY = 153
mode = 0

def checkFace(startX, startY):
	#print "center="+cSX
	if cSX-threshold<=startX and startX<=cSX+threshold and cSY-threshold<=startY and startY<=cSY+threshold:
		return True;
	else:
		return False;

def track(color,termination,roiBox):
	
	# if the see if the ROI has been computed
	if roiBox is not None:
		hsv = color
		backProj = cv2.calcBackProject([hsv], [0], roiHist, [0, 180], 1)

		# apply cam shift to the back projection, convert the
		# points to a bounding box, and then draw them
		(r, roiBox) = cv2.CamShift(backProj, roiBox, termination)
		pts = np.int0(cv2.boxPoints(r))
		cv2.polylines(frame, [pts], True, (0, 255, 0), 2)

	# show the frame and record if the user presses a key
	cv2.imshow("frame", color)

	

# construct the argument parse and parse the arguments
ap = argparse.ArgumentParser()
ap.add_argument("-f", "--face", required = True,
	help = "path to where the face cascade resides")
ap.add_argument("-v", "--video",
	help = "path to the (optional) video file")
args = vars(ap.parse_args())




# initialize the camera and grab a reference to the raw camera
# capture
camera = PiCamera()
camera.resolution = (640, 480)
camera.framerate = 64
camera.vflip = False
camera.hflip = True

rawCapture = PiRGBArray(camera, size=(640, 480))


# construct the face detector and allow the camera to warm
# up
fd = FaceDetector(args["face"])
time.sleep(0.1)

checkOK = False

		
# capture frames from the camera
for f in camera.capture_continuous(rawCapture, format="bgr", use_video_port=True):
	# grab the raw NumPy array representing the image
	frame = f.array

	# resize the frame and convert it to grayscale
	frame = imutils.resize(frame, width = 300)
	gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
	color = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)


	# detect faces in the image and then clone the frame
	# so that we can draw on it
	faceRects = fd.detect(gray, scaleFactor = 1.1, minNeighbors = 5,
		minSize = (30, 30))
	frameClone = frame.copy()

	
	# loop over the face bounding boxes and draw them
	fX=0
	fY=0
	fW=0
	fH=0
	for (fX, fY, fW, fH) in faceRects:
		cv2.rectangle(frameClone, (fX, fY), (fX + fW, fY + fH), (0, 255, 0), 2)

	text = "("+str(fX)+","+str(fY)+")"
	cv2.putText(frameClone, text, (5,25), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0,255,0))

	status = "MODE:"+str(mode)
	cv2.putText(frameClone, status, (5,200), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0,255,0))

	if checkFace(fX, fY)==True and checkOK==False:
		mode=1
		text = "OK!"
		cv2.putText(frameClone, text, (130,55), cv2.FONT_HERSHEY_SIMPLEX, 0.50, (0,255,0))
		checkOK = True
		
	elif checkFace(fX, fY)==False and checkOK==False:
		mode=0
		text = "Input face Here"
		cv2.rectangle(frameClone, (cSX,cSY), (cEX,cEY), (137,137,137), threshold/2)
		cv2.putText(frameClone, text, (90,55), cv2.FONT_HERSHEY_SIMPLEX, 0.50, (0,255,0))
		
	if mode==1:
		frame2 = frame
		frame2 = imutils.resize(frame2, width = 300)
		color = cv2.cvtColor(frame2, cv2.COLOR_BGR2HSV)
		
    	# setup initial location of window
    	r,h,c,w = 250,90,400,125  # simply hardcoded the values
    	track_window = (c,r,w,h)

    	# set up the ROI for tracking
    	roi = frame2[r:r+h, c:c+w]
    	#hsv_roi =  cv2.cvtColor(roi, cv2.COLOR_BGR2HSV)
    	#mask = cv2.inRange(hsv_roi, np.array((0., 60.,32.)), np.array((180.,255.,255.)))
    	#roi_hist = cv2.calcHist([hsv_roi],[0],mask,[180],[0,180])
    	#cv2.normalize(roi_hist,roi_hist,0,255,cv2.NORM_MINMAX)

    	# Setup the termination criteria, either 10 iteration or move by atleast 1 pt
    	#term_crit = ( cv2.TERM_CRITERIA_EPS | cv2.TERM_CRITERIA_COUNT, 10, 1 )

    	#while(1):
    	#	ret,frame = camera.read()
    	#	if ret == True:
    	#		hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
    	#		dst = cv2.calcBackProject([hsv],[0],roi_hist,[0,180],1)
#
 #   			# apply meanshift to get the new location
  #  			ret, track_window = cv2.CamShift(dst, track_window, term_crit)
#
 #   			# Draw it on image
  #  			pts = cv2.boxPoints(ret)
   # 			pts = np.int0(pts)
    #			img2 = cv2.polylines(frame,[pts],True, 255,2)
    #			cv2.imshow('img2',img2)

    #			k = cv2.waitKey(60) & 0xff
   # 			if k == 27:
   # 				break
   # 			else:
   # 				cv2.imwrite(chr(k)+".jpg",img2)
   # 		else:
   # 			break
    	
   # 	cv2.destroyAllWindows()
   		#camera2.release()



	# show our detected faces, then clear the frame in
	# preparation for the next frame
	cv2.imshow("Face", frameClone)
	rawCapture.truncate(0)
	
	cv2.imwrite("output.jpg", frameClone)	

	# if the 'q' key is pressed, stop the loop
	if cv2.waitKey(1) & 0xFF == ord("q"):
		break
