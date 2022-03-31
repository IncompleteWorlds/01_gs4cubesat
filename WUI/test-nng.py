import pynng
from pynng import Pub0, Sub0, Timeout

cam_path = "tcp://127.0.0.1:9001"

with Sub0(dial=cam_path,recv_timeout=2000, topics=b'') as sub:
    sub.recv_max_size = 0 #recieve msg of any size
    while(1):
        try:
            print("waiting for msg")
            img = sub.recv()
            print(img)
        except pynng.exceptions.Timeout as e:
            print('Timed out, retrying...')
