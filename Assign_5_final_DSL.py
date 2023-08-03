'''
Write a python program to store second year percentage of students in array. Write
function for sorting array of floating-point numbers in ascending order using a)
Insertion sort b) Shell Sort and display top five scores'''

class Sorting:

    def shellSort(self):
        gap = n // 2
        while gap > 0:
            j = gap
            while j < n:
                i = j - gap

                while i >= 0:
                    if A[i + gap] < A[i]:
                        A[i + gap], A[i] = A[i], A[i + gap]
                    else:
                        break
                    i = i - gap
                j =j+1
            gap = gap // 2
       
        print(A)
        list1=[]
        for i in range(-1,-6,-1):
            list1.append (A[i])
        print (list1)  

    def insertion_sort(self):
        for i in range(n - 1):
            if A[i] > A[i + 1]:
                temp = A[i]
                A[i] = A[i + 1]
                A[i + 1] = temp
                if i > 0:
                    for j in range(i):
                        if A[j] > A[j + 1]:
                            temp1 = A[j]
                            A[j] = A[j + 1]
                            A[j + 1] = temp1
                else:
                    pass
        print(A)
        list=[]
        for i in range(-1,-6,-1):
            list.append (A[i])
        print (list)        
    

sorting_obj=Sorting()

n = int(input("Enter the number of students: "))
A = []
print("Enter the marks of students:")
for i in range(0,n):
    marks = int(input())
    A.append(marks)
    print(A)

while True:
    
    print("1.Shell sort")
    print("2.Inertion sort")

    choice=int(input("Enter your Choice:"))
    if choice==1:
        sorting_obj.shellSort()
    elif choice==2:
        sorting_obj.insertion_sort()
    else:
        print(" Your choice is Invalid. Please enter a number from 1 to 5.")

print("Finally completed")
