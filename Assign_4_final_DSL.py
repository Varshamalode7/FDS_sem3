'''
a) Write a Python program to store roll numbers of student in array who attended training program in random
order. Write function for searching whether particular student attended training program or not, using 
Linear search and Sentinel search.
b) Write a Python program to store roll numbers of student in array who attended training program in sorted
order. Write function for searching whether particular student attended training program or not, using
Binary search and Fibonacci search.
''' 

class Assignment_4:
    
    def LinearSearch(self):
        pos=-1
        s=int(input("Enter the roll number of student to be searched for: "))
        for i in range(n):
            if(roll_numbers[i]==s):
                pos=i
                break
        if(pos==-1):
            print("Student has not attended training program.")
        else:
            print("Student at index",pos,"has attended training program.")
    
    def SentinelSearch(self):
        s=int(input("Enter the roll number of student to be searched for: "))
        last = roll_numbers[n - 1]
        roll_numbers[n-1]=s
        i = 0
 
        while (roll_numbers[i] != s):
            i += 1
 
        roll_numbers[n - 1] = last
 
        if ((i < n - 1) or (roll_numbers[n - 1] == s)):
            print("Student at index",i,"has attended training program.")
        else:
            print("Student has not attended training program.")
           
    def BinarySearch(self):
        roll_numbers.sort()
        s=int(input("Enter the roll number of student to be searched for: "))
        low=0
        high=n-1
        pos=-1
        while(low<=high):
            mid=(low+high)//2
            if(roll_numbers[mid]==s):
                pos=mid
                break
            elif(s<roll_numbers[mid]):
                high=mid-1
            else:
                low=mid+1
               
        if(pos==-1):
            print("Student has not attended training program.")
        else:
            print("Student at index",pos,"has attended training program.")
           
    def FibonacciSearch(self):
        roll_numbers.sort()
        s=int(input("Enter the roll number of student to be searched for: "))
        fibm2=0
        fibm1=1
        fibm=fibm1+fibm2
        while(fibm<n):
            fibm2=fibm1
            fibm1=fibm
            fibm=fibm2+fibm1
        offset=-1
       
        while(fibm>1):
            i=min(offset+fibm2,n-1)
            if(roll_numbers[i]<s):
                fibm=fibm1
                fibm1=fibm2
                fibm2=fibm-fibm1
                offset=i
            elif(roll_numbers[i]>s):
                fibm=fibm2
                fibm1=fibm1-fibm2
                fibm2=fibm-fibm1
            else:
                return i
        if(fibm and  roll_numbers[n-1]==s):
            return n-1
        return -1

ob=Assignment_4()

roll_numbers=[]
n=int(input("Enter the number of students: "))
print("Enter the roll numbers of students: ")
for i in range(n):
    roll_numbers.append(int(input()))
       
while(True):
    print("1. Searching using Linear Search.")
    print("2. Searching using Sentinel Search.")
    print("3. Searching using Binary Search.")
    print("4. Searching using Fibonacci Search.")
    print("5. Exit.")
   
    choice=int(input("Enter your choice: "))
    if(choice==1):
        ob.LinearSearch()
       
    elif(choice==2):
        ob.SentinelSearch()
       
    elif(choice==3):
        ob.BinarySearch()
       
    elif(choice==4):
        a=ob.FibonacciSearch()
        if(a>=0):
            print("Student at index",a,"has attended training program.")
        else:
            print("Student has not attended training program.")
       
    elif(choice==5):
        break
   
    else:
        print("Invalid choice. Please enter a number from 1 to 5.")

     
