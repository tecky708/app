def sum_of_evens(numbers):
    even_sum = sum(num for num in numbers if num % 2 == 0)
    return even_sum

# Input from the user
user_input = input("Enter a list of numbers separated by spaces: ")
number_list = [int(num) for num in user_input.split()]
result = sum_of_evens(number_list)
print("Sum of even numbers:", result)
