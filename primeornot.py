def is_prime(n):
    if n <= 1:
        return False
    if n <= 3:
        return True
    
    if n % 2 == 0 or n % 3 == 0:
        return False
    
    i = 5
    while i * i <= n:
        if n % i == 0 or n % (i + 2) == 0:
            return False
        i += 6
    
    return True

# Input from the user
user_input = int(input("Enter a number: "))
result = is_prime(user_input)
if result:
    print("It's a prime number.")
else:
    print("It's not a prime number.")
