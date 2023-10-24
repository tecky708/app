# Define an empty dictionary to store user registration information
user_data = {}

# Function to get user registration input
def get_user_info():
    print("User Registration Form")
    username = input("Enter your username: ")
    email = input("Enter your email address: ")
    password = input("Create a password: ")
    
    # Store the information in the dictionary
    user_data['username'] = username
    user_data['email'] = email
    user_data['password'] = password

# Function to display user registration information
def display_user_info():
    print("\nUser Registration Information:")
    print(f"Username: {user_data['username']}")
    print(f"Email: {user_data['email']}")
    # For security reasons, you should not print the password directly
    # Instead, you can print a message like "Password saved securely."
    print("Password: Password saved securely.")

# Get user registration information
get_user_info()

# Display user registration information
display_user_info()
