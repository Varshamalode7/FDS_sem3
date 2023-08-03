'''
Write a Python program to compute following computation on matrix:
a) Addition of two matrices
b) Subtraction of two matrices
c) Multiplication of two matrices
d) Transpose of a matrix
'''

class Matrix:      #creation of class

    def Addition(self):
        result=[[0,0,0], [0,0,0], [0,0,0]]
        for i in range(rows):
            for j in range(column):
                result[i][j] = M1[i][j] + M2[i][j]
                print(result[i][j], end=" ")
            print()

    def Subtraction(self):
        result=[[0,0,0], [0,0,0], [0,0,0]]
        for i in range(rows):
            for j in range(column):
                result[i][j] = M1[i][j] - M2[i][j]
                print(result[i][j], end=" ")
            print()

    def Multiplication(self):
        result=[[0,0,0], [0,0,0], [0,0,0]]
        for i in range(len(M1)):
            for j in range(len(M2[0])):
                for k in range(len(M2)):
                    result[i][j] = result[i][j] + (M1[i][k] * M2[k][j])
                print(result[i][j], end=" ")
            print()

    def Transpose(self):
        result=[[0,0,0], [0,0,0], [0,0,0]]
        for i in range(rows):
            for j in range(column):
                result[i][j] = result[i][j] + M1[j][i]
                print(result[i][j], end=" ")
            print()

matrix = Matrix() #creation of object

rows = int(input("Enter the Number of rows : "))
column = int(input("Enter the Number of Columns: "))
print("Enter the elements of First Matrix:")
M1 = [[int(input()) for i in range(column)] for i in range(rows)]
print("First Matrix M1 is: ")
for i in M1: #for creation of matrix
    print(i)

rows = int(input("Enter the Number of rows : "))
column = int(input("Enter the Number of Columns: "))
print("Enter the elements of Second Matrix:")
M2 = [[int(input()) for i in range(column)] for i in range(rows)]
print("Second Matrix M2 is:")
for i in M2: #for creation of matrix
    print(i)

while True:
    print("1. Addition of two matrices")
    print("2. Subtraction of two matrices")
    print("3. Multiplication of two matrices")
    print("4. Transpose of a matrix")
    print("5. Exit")
    
    choice = int(input("Enter your choice:"))
    if choice == 1:
        matrix.Addition()
    elif choice == 2:
        matrix.Subtraction()
    elif choice == 3:
        matrix.Multiplication()
    elif choice == 4:
        matrix.Transpose()
    else:
        print(" Your choice is Invalid. Please enter a number from 1 to 5.")

print("Finally completed")
           
       
     
