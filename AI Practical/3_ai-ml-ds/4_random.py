import random

rand = random.randrange(5, 15, 2)     #   random between 5 and 15 with gap of 2
print(rand)

rand = random.random()                #   random float number between 0 and 1
print(rand)

rand = random.uniform(5, 15)          #   random float between 5 and 15
print(rand)

rand = random.randint(5, 15)          #   random int between 5 and 15
print(rand)