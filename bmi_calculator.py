# Simple BMI Calculator
weight = float(input("Enter your weight in kg: "))
height = float(input("Enter your height in meters: "))

bmi = weight / (height ** 2)

print(f"Your Body Mass Index is: {bmi:.2f}")

if bmi < 18.5:
    print("Category: Underweight")
elif 18.5 <= bmi < 25:
    print("Category: Normal weight")
else:
    print("Category: Overweight")
  
