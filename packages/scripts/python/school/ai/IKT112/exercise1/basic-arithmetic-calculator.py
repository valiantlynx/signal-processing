# Task: Create a Python program that takes two numbers as input and allows the user to choose to add, subtract, multiply, or divide them.

# class for the calculator
class Calculator:
    def __init__(self, num1, num2) -> None:
        self.num1 = num1
        self.num2 = num2
    
    def add(self):
        return  self.num1 + self.num2
    def subtract(self):
        return  self.num1 - self.num2
    def multiply(self):
        return  self.num1 * self.num2
    def divide(self):
        return  self.num1 / self.num2

# input from user for two numbers
print("Welcome to the basic calculator?")
num1 = int(input("input the first number: "))
num2 = int(input("input the second number: "))

# input from user for operation
operation = input(f"Please choose the operation: \n1. add\n2. subtract\n3. multiply\n4. divide")

# do the operation
Calculate = Calculator(num1, num2)
print(Calculate.add())