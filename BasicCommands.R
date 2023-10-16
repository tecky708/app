# This is a comment in R. Comments are preceded by a '#' symbol and are used for documentation.

# Basic Arithmetic Operations
x <- 5 + 3   # Addition
y <- 10 - 2  # Subtraction
z <- 4 * 6   # Multiplication
w <- 15 / 3  # Division
v <- 11 %% 4 # Modulo (remainder)

# Variables
my_variable <- "Hello, World!"  # Assign a string to a variable
age <- 30                        # Assign an integer to a variable
height <- 1.75                   # Assign a floating-point number to a variable

# Printing Values
print(my_variable)  # Print the value of a variable
cat("Age is", age)  # Concatenate and print a message with a variable

# Data Types
is_integer <- is.integer(age)  # Check if a variable is an integer
is_character <- is.character(my_variable)  # Check if a variable is a character

# Data Structures
my_vector <- c(1, 2, 3, 4, 5)  # Create a numeric vector
my_list <- list(name = "John", age = 25, city = "New York")  # Create a list

# Indexing and Slicing
element_3 <- my_vector[3]  # Access the third element of a vector
john_age <- my_list$age   # Access a list element by name

# Conditional Statements
if (age >= 18) {
  cat("You are an adult.\n")
} else {
  cat("You are not an adult.\n")
}

# Loops
for (i in 1:5) {
  cat("Iteration", i, "\n")
}

# Functions
square <- function(x) {
  return(x^2)
}

# Calling a Function
result <- square(4)
cat("The square of 4 is", result, "\n")
