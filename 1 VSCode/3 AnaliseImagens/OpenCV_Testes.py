import cv2, os


os.environ["OPENCV_FFMPEG_CAPTURE_OPTIONS"] = "rtsp_transport;0"

cap = cv2.VideoCapture('rtsp://admin:embasa123@192.168.0.107:554/onvif1', cv2.CAP_FFMPEG)  

while(cap.isOpened()):
    ret, frame = cap.read()
    #print(frame)
    cv2.imshow('frame', frame)
    if cv2.waitKey(20) & 0xFF == ord('q'):
        break
cap.release()
cv2.destroyAllWindows()






# import cv2
# import imutils
# import os

# os.environ["OPENCV_FFMPEG_CAPTURE_OPTIONS"] = "rtsp_transport;udp"


# cap = cv2.VideoCapture('rtsp://admin:embasa123@192.168.0.107:554/onvif1', cv2.CAP_FFMPEG)                             # Gourmet 
# # cap = cv2.VideoCapture('rtsp://admin:embasa123@192.168.0.127:554/onvif1')                             # Gourmet                       
# # cap = cv2.VqideoCapture(0)               # Frente

# while(cap.isOpened()):
#     ret, frame = cap.read()

#     frame = imutils.resize(frame, width=680)
#     gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

#     cv2.imshow('Frente', frame)                      # COLORIDO
#     # cv2.imshow('frame', gray)
#     if cv2.waitKey(1) & 0xff == ord('q'):
#         break

# cap.release()
# cv2.destroyAllWindows()






# ## MULTIPLES CAM ##

# import numpy as np 
# import cv2
# import imutils

# video_capture_0 = cv2.VideoCapture('rtsp://aysm:43emrb@192.168.0.100:554/onvif1')
# video_capture_1 = cv2.VideoCapture('rtsp://admin:@192.168.0.106:554')

# while True:
#     #Capture frame-by-frame
#     ret0, frame0 = video_capture_0.read()
#     frame0 = imutils.resize(frame0, width=680)

#     ret1, frame1 = video_capture_1.read()
#     frame1 = imutils.resize(frame1, width=680)

#     if (ret0):
#         # Display the resulting frame
#         cv2.imshow('Frente', frame0)

#     if (ret1):
#         # display te resulting frame
#         cv2.imshow('Gourmet', frame1)

#     if cv2.waitKey(1) & 0xFF == ord('q'):
#         break

# # when everything is done, release the capture
# video_capture_0.release()
# video_capture_1.release()
# cv2.destroyAllWindows()