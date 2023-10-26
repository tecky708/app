def is_armstrong_number(n):
    num_str = str(n)
    num_digits = len(num_str)
    total = sum(int(digit) ** num_digits for digit in num_str)
    
    return n == total

# Input from the user
user_input = int(input("Enter a number: "))
result = is_armstrong_number(user_input)
if result:
    print("It's an Armstrong number.")
else:
    print("It's not an Armstrong number.")
