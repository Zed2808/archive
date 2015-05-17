#!/usr/bin/python

import Image
from random import choice

def MakeKey():
    img = Image.new('RGB', (256, 256), 'white') # create new white image (256x256)
    pixels = img.load() # create the pixel map

    for i in range(img.size[0]): # for every pixel:
        for j in range(img.size[1]):
            pixels[i, j] = (choice([(0, 0, 0), (255, 255, 255)])) # make pixel either black or white

    img.show()

