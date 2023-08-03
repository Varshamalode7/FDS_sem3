
Cricket=[]
Badminton=[]
Football=[]

NC=int (input("Enter the number of students who play Cricket:"))
print("Enter the name of students who play Cricket:")
for i in range(0,NC):
    name=str(input())
    Cricket.append(name)
print(Cricket)

NB=int (input("Enter the number of students who play Badminton:"))
print("Enter the name of students who play Badminton:")
for i in range(0,NB):
    name=str(input())
    Badminton.append(name)
print(Badminton)

NF=int (input("Enter the number of students who play Football:"))
print("Enter the name of students who play Football:")
for i in range(0,NF):
    name=str(input())
    Football.append(name)
print(Football)

class setoperation:

    def Cricket_Badminton(self):
        Cricket_Badminton=[]
        for name in Cricket:
            if name  in Badminton:
                Cricket_Badminton.append(name)
        print ("list of students playing cricket and badminton : ",Cricket_Badminton)

    def Cricket_or_Badminton(self):
        Cricket_or_Badminton=[]
        for name in Cricket:
            if name not in Badminton:
                Cricket_or_Badminton.append(name)
        for name in Badminton:
            if(name not in Cricket):
                Cricket_or_Badminton.append(name)
        print("Name of students who play either Cricket or Badminton but not both : ",Cricket_or_Badminton)

    def Football(self):
        Only_Football=[]
        for name in Football:
            if name not in Badminton:
                if(name not in Cricket):
                    Only_Football.append(name)
        print("Name of students who  neither play Cricket nor Badminton : ",Only_Football)

    def Cricket_Football(self):
        Cricket_Football=[]
        for name in Cricket:
            if(name in Football):
                if(name not in Badminton):
                    Cricket_Football.append(name)
        print("Name of students who play Cricket and Football but not Badminton : ",Cricket_Football)

obj=setoperation()

while(True):
    print("1.Name of students who play both Cricket and Badminton.")
    print("2.Name of students who play either Cricket or Badminton but not both.")
    print("3.Name of students who  neither play Cricket nor Badminton.")
    print("4.Name of students who play Cricket and Football but not Badminton.")
    print("5.Exit.\n")
    choice=int(input("Enter the choices from 1 to 5: ")) 

    if (choice==1):
        obj.Cricket_Badminton()
    elif(choice==2): 
        obj.Cricket_or_Badminton()
    elif(choice==3):    
        obj.Football()
        # print("Number of students who neither play Cricket nor Badmintion:",len(Football))
    elif(choice==4):    
        obj.Cricket_Football()
        # print("Number of students who play Cricket and Football but not Badminton:",len(Cricket_Football))
    elif(choice==5):    
        print("Exit")
    else:
        print("Your choice is invalid,please enter a number from 1 to 5")  

    print("finish Assignment no 1")




# withous class set operation perform
# NC=int (input("Enter the number of students who play Cricket:"))
# NB=int (input("Enter the number of students who play Badminton:"))
# NF=int (input("Enter the number of students who play Football:"))

# Cricket=[]
# Badminton=[]
# Football=[]

# print("Enter the name of students who play Cricket:")
# for i in range(0,NC):
#     name=str(input())
#     Cricket.append(name)

# print("Enter the name of students who play Badminton:")
# for i in range(0,NB):
#     name=str(input())
#     Badminton.append(name)

# print("Enter the name of students who play Football:")
# for i in range(0,NF):
#     name=str(input())
#     Football.append(name)

# def intersection(lst1,lst2):
#     result=[]
#     for name in lst1:
#         if name  in lst2:
#             result.append(name)
#     return result

# def union(lst1,lst2):
#     result=lst2.copy()
#     for name in lst1:
#         if name not in lst2:
#             result.append(name)
#     return result

# def diff(lst1,lst2):
#     result=[]
#     for name in lst1:
#         if name not in lst2:
#             result.append(name)
#     return result

# while(True):
#     print("1.Number of students who play both Cricket and Badminton.")
#     print("2.Number of students who play either Cricket or Badminton but not both.")
#     print("3.Number of students who  neither play Cricket nor Badminton.")
#     print("4.Number of students who play Cricket and Football but not Badminton.")
#     print("5.Exit.\n")
#     choice=int(input("Enter the choices(from 1 to 5:")) 

#     if (choice==1):
#         print(union(Cricket,Badminton))
#     elif(choice==2): 
#         print(diff(union(Cricket,Badminton),intersection(Cricket,Badminton)))
#     elif(choice==3):    
#         print(diff(Football,union(Cricket,Badminton)))
#         print("Number of students who neither play Cricket nor Badmintion:",len(diff(Football,union(Cricket,Badminton))))
#     elif(choice==4):    
#         print(diff(union(Cricket,Football),Badminton))
#         print("Number of students who play Cricket and Football but not Badminton:",len(diff(union(Cricket,Football),Badminton)))
#     elif(choice==5):    
#         print("Exit")
#     else:
#         print("Your choice is invalid,please enter a number from 1 to 5")  

#     print("finish Assignment no 1")



