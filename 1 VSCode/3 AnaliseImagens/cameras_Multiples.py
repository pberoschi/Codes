import numpy as np 
import cv2
import imutils

resol = int(input('Qual a resolução das imagens? 320/640/720/960/1280 '))

video_capture_0 = cv2.VideoCapture('rtsp://aysm:7ctxne@192.168.0.106:554/onvif1')
video_capture_1 = cv2.VideoCapture('rtsp://admin:@192.168.0.105:554')


def cam():
    try:
        while True:
        #Capture frame-by-frame
            ret0, frame0 = video_capture_0.read()
            frame0 = imutils.resize(frame0, width=resol) #320 640 720 960 

            ret1, frame1 = video_capture_1.read()
            frame1 = imutils.resize(frame1, width=resol)

            if (ret0):
                # Display the resulting frame
                cv2.imshow('Frente', frame0)

            if (ret1):
                # display te resulting frame
                cv2.imshow('Gourmet', frame1)


            if cv2.waitKey(1) & 0xFF == ord('q'):
                break

        # when everything is done, release the capture
        video_capture_0.release()
        video_capture_1.release()
        cv2.destroyAllWindows()

    except:
        print('Reinciando a execução')
        return

while True:
    cam()


