import numpy
r = int(input("请输入圆的半径："))
s = numpy.pi*r*r
l = 2*numpy.pi*r
print("圆的面积：",s)
print("圆的直径：",2*r)
print("圆的周长：",l)