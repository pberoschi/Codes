from winotify import Notification, audio

# Crie uma instância da classe Notification
# notificacao = Notification(app_id="Meu Script Python", title="Notificação Personalizada")
notificacao = Notification(app_id="MERCADO",
                           title="ALERTAS DE PREÇO",
                           msg="Rompimento de suporte e/ou resistência.",
                           icon=r"C:\Users\Johnny\Downloads\Scooby-Doo.jpg",
                           duration='long' )

# Exiba a notificação
notificacao.set_audio(audio.LoopingAlarm, loop=False)
notificacao.show()
