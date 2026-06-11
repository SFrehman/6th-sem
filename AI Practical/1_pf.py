# Single line comment
"""Multi-line Comments"""

# --------------"""Variables"""----------------
a = 20
b = 12

# --------------"""if-elif-else"""----------------
if a > b:
    print("a is greater than b")  # Fixed a minor typo in your original print statement
elif a < b:
    print("a is less than b")
else:
    print("both are equal")

# --------------"""loops"""----------------
# For loop with range
for i in range(5):
    print(i)

# For loop with list
fruits = ["apple", "banana", "cherry"]
for fruit in fruits:
    print(fruit)

# While loop 
count = 0
while count < 3:
    print(count)
    count += 1


# --------------"""functions"""----------------
def mul():
    print(a * b)
mul()

# --------------"""Indentation"""----------------
# Python uses indentation (spaces/tabs) to define blocks of code instead of curly braces {}
def indentation_example():
    if True:
        print("This is inside the 'if' block")
        print("This is also inside the 'if' block because it shares the same indentation")
    print("This is outside the 'if' block, back inside the function block")

indentation_example()

# --------------"""Input-output"""----------------
# 1. input (default to string)
name = input("Enter your name: ")
age = int(input("Enter your age: "))

# 2. output
print(f"Hello {name}, you are {age} years old.")

# --------------"""operators"""----------------
# 1. Arithmetic
# + , - , * , / , % (modulus)

# 2. Relational (Comparison)
# ==, !=, >, <, >=, <=

# 3. Logical
# AND , OR , NOT
