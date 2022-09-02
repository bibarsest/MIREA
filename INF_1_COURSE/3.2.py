#   Objective:   Запрограммируйте вычисление энтропии по Шеннону для систем из двух состояний. Вероятности вводятся с клавиатуры.
import math
p1 = float(input())
p2 = float(input())
h1 = -p1 * math.log(p1,2)
h2 = -p2 * math.log(p2,2)
h = h1+h2
print(str(h1)[:5], str(h2)[:5], str(h)[:5])