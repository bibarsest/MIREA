#   Objective:   Напишите программу для вычисления {( )}, где x вводит пользователь с клавиатуры.
import math
x = float(input())
if x == 0:
    print('Нельзя делить на ноль')
else:
    y = (math.tan((math.cos(x)*math.sin(2*x))/(x*math.e**x)))**math.log(x,7)
    print(y)
    print('1')
