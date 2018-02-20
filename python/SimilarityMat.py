# -*- coding: utf-8 -*-

from PIL import Image
import numpy as np

w, h = 512, 512
# data = np.zeros((h, w, 3), dtype=np.uint8)
# data[256, 256] = [255, 0, 0]
# img = Image.fromarray(data, 'RGB')
#img.save('my.png')

data = np.zeros((h, w))
img = Image.fromarray(data)
img.show()

class Marker(object):
    """docstring for Marker."""
    def __init__(self, marker_data = None):
        super(Marker, self).__init__()
        self.translate_x = marker_data[0]
        self.translate_y = marker_data[1]
        self.translate_z = marker_data[2]
        self.rotate_x = marker_data[3]
        self.rotate_y = marker_data[4]
        self.rotate_z = marker_data[5]

class MotionClip(object):
    """docstring for MotionClip."""
    def __init__(self, clip_data = None):
        super(MotionClip, self).__init__()
        self.head = Marker()
        self.chest = Marker()
        self.right_shoulder = Marker()
        self.left_shoulder = Marker()
        self.right_hand = Marker()
        self.left_hand = Marker()
        self.right_foot = Marker()
        self.left_foot = Marker()

path = "markers.td"
with open(path) as database:
    lines = database.readlines()
    # print(lines[0])
    data = [[float(x) for x in line.split()] for line in lines[1:]]
    print(data[0])
