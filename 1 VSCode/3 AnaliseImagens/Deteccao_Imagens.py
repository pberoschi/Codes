import cv2
#captura = cv2.VideoCapture(0)
#captura = cv2.VideoCapture('rtsp://admin:@192.168.1.105:554/Streaming/Channels/401')
captura = cv2.VideoCapture(0, cv2.CAP_DSHOW) #notebook win7


while(1):
    ret, frame = captura.read()
    cv2.imshow("Video", frame)
   
    k = cv2.waitKey(30) & 0xff
    if k == 27:
        break

captura.release()
cv2.destroyAllWindows()