#!/usr/bin/python

from Tkinter import *
from subprocess import call

class Soundboard:
    def __init__(self, master):
        frame = Frame(master)
        frame.pack()

        self.button_rearcenter = Button(frame, text='Rear Center', command=self.rearcenter)
        self.button_rearcenter.pack()

        self.button_quack = Button(frame, text='Quack', command=self.quack)
        self.button_quack.pack()

    def rearcenter(self):
        call(['aplay', '/usr/share/sounds/alsa/Rear_Center.wav'])

    def quack(self):
        call(['aplay', 'quack.wav'])

root = Tk()
app = Soundboard(root)
root.mainloop()
