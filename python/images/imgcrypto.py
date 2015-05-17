#!/usr/bin/python

import Image
from random import choice

def MakeKey():
    img = Image.new('RGB', (256, 256), 'white') # create new white image (64x64)
    pixels = img.load() # create the pixel map

    for i in range(img.size[0]): # for every pixel:
        for j in range(img.size[1]):
            pixels[i, j] = (choice([(0, 0, 0), (255, 255, 255)])) # make pixel either black or white

    img.save('key.png', 'PNG')
    print 'New key image saved to key.png'

def ImgXor(img1, img2):
    pixels1 = img1.load()
    pixels2 = img2.load()

    for i in range(img1.size[0]):
        for j in range(img1.size[1]):
            if pixels1[i, j] == (0, 0, 0, 255):
                pixels1[i, j] = pixels2[i, j]
            elif pixels1[i, j] == (255, 255, 255, 255):
                if pixels2[i, j] == (0, 0, 0, 255):
                    pixels1[i, j] = (255, 255, 255, 255)
                elif pixels2[i, j] == (255, 255, 255, 255):
                    pixels1[i, j] = (0, 0, 0, 255)
