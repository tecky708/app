def is_palindrome(s):
    # Remove spaces and convert the string to lowercase for case-insensitive comparison
    s = s.replace(" ", "").lower()
    
    # Check if the string is equal to its reverse
    return s == s[::-1]

# Input from the user
user_input = input("Enter a string: ")
result = is_palindrome(user_input)
if result:
    print("The string is a palindrome.")
else:
    print("The string is not a palindrome.")
