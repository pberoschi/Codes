#'rtsp://admin:embasa123@192.168.0.145:554/onvif1'

import numpy as np
import cv2, os

cap = cv2.VideoCapture(0)


cap.isOpened(); #prints True, and program. Program continues.
while(True):
    ret, frame = cap.read()
    #print(frame)
    cv2.imshow('frame',frame)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break
cap.release()
cv2.destroyAllWindows()

