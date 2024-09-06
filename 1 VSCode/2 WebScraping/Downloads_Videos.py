# from pytube import YouTube

# link = input("Cole o link do vídeo aqui: ")

# yt=YouTube(link)

# print("Baixando", yt.title)

# resolucao = yt.streams.filter(progressive=True, file_extension="mp4").order_by("resolution").desc().first()

# resolucao.download()

# print("Download Concluído")




from pytubefix import YouTube
from pytubefix.cli import on_progress
 
url = input("Cole o link do vídeo aqui: ")
 
yt = YouTube(url, on_progress_callback = on_progress)
print(yt.title)
 
ys = yt.streams.get_highest_resolution()
ys.download()