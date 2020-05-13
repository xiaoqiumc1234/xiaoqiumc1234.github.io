import ctypes
player = ctypes.windll.kernel32


import time
cisu = int(input("次数>>>"))
for i in range(cisu):
    time.sleep(1)
    player.Beep(1000,200)
