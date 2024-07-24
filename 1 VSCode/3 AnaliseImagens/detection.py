from ultralytics import YOLO

modelo = YOLO('yolov8n.pt')

while True:
	modelo.predict(source='cars.mp4',show=True)