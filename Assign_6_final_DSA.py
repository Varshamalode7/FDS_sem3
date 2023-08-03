'''Write a python program to store first year percentage of students in array. Write function
for sorting array of floating point numbers in ascending order using quick sort and
display top five scores.'''
                # for pivot as low
class Assignment_6:
   
    def Partition(self,percentage,low,high):
        pivot=percentage[low]
        i=low+1
        j=high
        while True:
            while i<=j and percentage[i]<=pivot:
                i=i+1
            while i<=j and percentage[j]>=pivot:
                j=j-1
            if i<=j:
                percentage[i],percentage[j]=percentage[j],percentage[i]
            else:
                break
        percentage[low],percentage[j]=percentage[j],percentage[low]
        return j
   
    def QuickSort(self,percentage,low,high):
        if(low<high):
            pi=self.Partition(percentage,low,high)
            self.QuickSort(percentage,low,pi-1)
            self.QuickSort(percentage,pi+1,high)

ob=Assignment_6()
       
def InputPercentage():
    percentage=[]
    n=int(input("Enter the number of students: "))
    print("Enter the percentage of students: ")
    for i in range(n):
        r=float(input())
        percentage.append(r)
   
    ob.QuickSort(percentage,0,n-1)
   
    list1=[]
    print("List of top five scorers is :")
    for i in range(-1,-6,-1):
        list1.append(percentage[i])
    print(list1)

while(True):
    print("1. Using Quick Sort to display the list of top five scorers.")
    print("2. Exit.")
   
    choice=int(input("Enter your choice: "))
   
    if(choice==1):
        InputPercentage()
       
    elif(choice==2):
        break
   
    else:
        print("Invalid choice. Please enter a number from 1 to 2.")

       
            #    for pivot as high
# class Assignment_6:
   
#     def __init__(self):
#         print("This is the code of Assignment 6.")
       
           
#     def Partition(self,percentage,low,high):
#         i = low-1
#         pivot = percentage[high]
#         for j in range(low , high):
#             if percentage[j] <= pivot:
#                 i = i+1
#                 percentage[i],percentage[j] = percentage[j],percentage[i]
#         percentage[i+1],percentage[high] = percentage[high],percentage[i+1]
#         return i+1
   
   
   
#     def QuickSort(self,percentage,low,high):
#         if(low<high):
#             pi=self.Partition(percentage,low,high)
#             self.QuickSort(percentage,low,pi-1)
#             self.QuickSort(percentage,pi+1,high)
           
       
       
# ob=Assignment_6()
       
# def InputPercentage():
#     percentage=[]
#     n=int(input("Enter the number of students: "))
#     print("Enter the percentage of students: ")
#     for i in range(n):
#         r=float(input())
#         percentage.append(r)
   
#     ob.QuickSort(percentage,0,n-1)
   
#     list1=[]
#     print("List of top five scorers is :")
#     for i in range(-1,-6,-1):
#         list1.append(percentage[i])
#     print(list1)

# while(True):
#     print("1. Using Quick Sort to display the list of top five scorers.")
#     print("2. Exit.")
   
#     choice=int(input("Enter your choice: "))
   
#     if(choice==1):
#         InputPercentage()
       
#     elif(choice==2):
#         break
   
#     else:
#         print("Invalid choice. Please enter a number from 1 to 2.")

       
               
           
   
           
   
           
       
       
           
   
           
   
           
