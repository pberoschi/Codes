from pytubefix import YouTube
from pytubefix.cli import on_progress
 
url = input("Cole o link do vídeo aqui: ")
 
yt = YouTube(url, on_progress_callback = on_progress)
print(yt.title)
 
ys = yt.streams.get_highest_resolution()
ys.download()