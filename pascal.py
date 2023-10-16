#PASCAL TRIANGLE


# Q1: FIND THE NUMBER AT A PARTICULAR POSITION IN PASCAL TRIANGLE 
#where n and r is given that is row and column number
#Use the formula nCr = n!// r!(n-r)! 
#5c3 = 4/1*3/2
def find_number(n,r):
    res = 1
    n -= 1
    r -= 1

    for i in range(r):
        res = res * (n-i) # (4-0) = 4 --> (4-1) = 3 (stops here) --> (4-2) = 2
        res = res // (i+1) # (4//1) --> (3//2) --> (2//3)-- not valid
    return res

print(f"Output1: {find_number(5,3)}") # output: 6



# Q2: Generate a particular row for pascal triangle 
#where r is given that is row
def generate_row(row):
    res = 1
    print(res)
    for i in range(1, row):
        res = res * (row - i)
        res = res // i 
        print(res)

generate_row(5)
# 1, 5//1 , 4//2, 3//3, 2//4, 1//5

# Q3: Generate the Pascal Triangle
def generate(numRows):
    res = [[1]]

    for i in range(numRow-1):
        temp = [0] + res[-1] + [0]
        row = []
        for j in range(len(res[-1])+1):
            row.append(temp[j] + temp[j+1])
        res.append(row)
    print(res)


numRow = int(input("Enter a Number  "))
generate(numRow)