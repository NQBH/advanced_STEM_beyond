import turtle
from random import random

for i in range(100):
    steps = int(random() * 100)
    angle = int(random() * 360)
    turtle.right(angle)
    turtle.fd(steps)