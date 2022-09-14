'''   
Objective:
    С помощью Python найдите такие значения x и y, которые обратят
    выражение в значение True.
    Выражение:
'''
for x in range(2):
    for y in range(2):
        if (x or y) and (not(x) or y) and (not(x and y)) == True:
            print(x,y)  # 0 1