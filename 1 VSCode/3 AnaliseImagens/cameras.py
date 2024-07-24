import cv2
import imutils

# cap = cv2.VideoCapture('rtsp://admin:@192.168.0.105:554')                             # Gourmet                        
cap = cv2.VideoCapture('rtsp://aysm:7ctxne@192.168.0.106:554/onvif1')               # Frente



while(cap.isOpened()):    
    ret, frame = cap.read()

    frame = imutils.resize(frame, width=680)
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

    cv2.imshow('Frente', frame)                      # COLORIDO
    # cv2.imshow('frame', gray)
    if cv2.waitKey(1) & 0xff == ord('q'):
        break


cap.release()
cv2.destroyAllWindows()



## MULTIPLES CAM ##

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


















## ________________________________________________________________________________________________________________##

## EXEMPLO 1 (SIMPLES)
# import cv2 as cv 

# camera = cv.VideoCapture(0, cv.CAP_DSHOW) 

# camera.set(cv.CAP_PROP_FRAME_WIDTH, 1280)        #1280/720 // 640/480
# camera.set(cv.CAP_PROP_FRAME_HEIGHT, 720)


# while camera.isOpened():

#     ret, frame = camera.read()
#     cv.imshow('frame',frame)

#     if cv.waitKey(1) & 0xff == ord('q'):
#         break

# camera.release()
# cv.destroyAllWindows()

## ----------------------------------------------------------------------------------------------------------##

## EXEMPLO 2 (COMPLETO)
# import cv2

# FRAME_WIDTH=3
# FRAME_HEIGHT=4
# FRAME_RATE=5
# BRIGHTNESS=10
# CONTRAST=11
# SATURATION=12
# HUE=13
# GAIN=14
# EXPOSURE=15

# #Opens the first imaging device
# cap = cv2.VideoCapture(0) 

# #Check whether user selected camera is opened successfully.
# if not (cap.isOpened()):
#  print("Could not open video device")

# #To set the resolution
# cap.set(cv2.CAP_PROP_FOURCC, cv2.VideoWriter_fourcc('M', 'J', 'P', 'G'))
# #cap.set(cv2.CAP_PROP_FOURCC, cv2.VideoWriter_fourcc('U', 'Y', 'V', 'Y'))

# cap.set(cv2.CAP_PROP_FRAME_WIDTH, 640)
# cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 480)

# print("Width = ",cap.get(cv2.CAP_PROP_FRAME_WIDTH))
# print("Height = ",cap.get(cv2.CAP_PROP_FRAME_HEIGHT))
# print("Framerate = ",cap.get(cv2.CAP_PROP_FPS))
# print("Format = ",cap.get(cv2.CAP_PROP_FORMAT))

# Brightness=cap.get(cv2.CAP_PROP_BRIGHTNESS)
# Contrast=cap.get(cv2.CAP_PROP_CONTRAST)
# Saturation=cap.get(cv2.CAP_PROP_SATURATION)
# Gain=cap.get(cv2.CAP_PROP_GAIN)
# Hue=cap.get(cv2.CAP_PROP_HUE)
# Exposure=cap.get(cv2.CAP_PROP_EXPOSURE)
# while(True):
#     # Capture frame-by-frame
#     ret, frame = cap.read()

#     # Display the resulting frame
#     cv2.imshow('preview',frame)
# #Waits for a user input to quit the application
#     k = cv2.waitKey(1)
#     if (k == 27):#Esc key to quite the application 
#         break
#     elif k == ord('g'):
#         print("******************************")
#         print("Width = ",cap.get(FRAME_WIDTH))
#         print("Height = ",cap.get(FRAME_HEIGHT))
#         print("Framerate = ",cap.get(FRAME_RATE))
#         print("Brightness = ",cap.get(BRIGHTNESS))
#         print("Contrast = ",cap.get(CONTRAST))
#         print("Saturation = ",cap.get(SATURATION))
#         print("Gain = ",cap.get(GAIN))
#         print("Hue = ",cap.get(HUE))
#         print("Exposure = ",cap.get(EXPOSURE))
#         print("******************************")  

#     elif k == ord('w'):
#         if(Brightness <= 0):
#             Brightness = 0
#         else:
#             Brightness-=1
#         cap.set(BRIGHTNESS,Brightness)
#         print(Brightness)
#     elif k == ord('s'):
#         if(Brightness >= 255):
#             Brightness = 255
#         else:
#             Brightness+=1
#         cap.set(BRIGHTNESS,Brightness)
#         print(Brightness)   

# # When everything done, release the capture
# cap.release()
# cv2.destroyAllWindows() 

## ----------------------------------------------------------------------------------------##





# import cv2 as cv 

# camera = cv.VideoCapture('rtsp://admin:@192.168.0.106:554')                           # Área Gourmet
# # camera = cv.VideoCapture('rtsp://aysm:43emrb@192.168.0.109:554/onvif2')                 # Entrada
# rodando = True

# while rodando:

#     status, frame = camera.read()

#     if not status or cv.waitKey(1) & 0xff == ord('q'):
#         rodando = False

#     cv.imshow("Camera", frame)








# camera = cv.VideoCapture('rtsp://admin:@192.168.0.106:554', cv.CAP_DSHOW)                           # Área Gourmet

# import cv2

# cap = cv2.VideoCapture(0)

# # cap.set(3, 176)
# # cap.set(4, 144)



