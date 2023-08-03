# '''
# Write a Python program to compute following operations on String:
# a) To display word with the longest length
# b) To determine the frequency of occurrence of particular character in the string
# c) To check whether given string is palindrome or not
# d) To display index of first appearance of the substring
# e) To count the occurrences of each word in a given string
# (Do not use string built-in functions)
# '''

class Assignment_2:

    def longest_length(self,string1):
        word=" "
        list1=[]
        string1=string1+" "
        long_length=0
        long_word=None
        for i in string1:
            if(i==" "):
                list1.append(word)
                word=" "
            else:
                word=word+i
        for i in list1:
            length=0
            for j in i:
                length=length+1
            if(length>long_length):
                long_length=length
                long_word=i
        return long_word
    
    def frequency(self,string1, ch):
        count=0
        for i in string1:
            if(ch==i):
                count=count+1
        return count

    def palindrome(self,string1):
        new_string = ""
        for i in string1 :
            new_string = i+new_string
        if(new_string == string1) :
            print("The given string is palindrome.")
        else :
            print("The given string is not palindrome.")

    def index_first(self,string1, string2):
        length1=0
        for i in string1:
            length1=length1+1
        length2=0
        for i in string2:
            length2=length2+1
        for i in range(0,length1):
            if(string1[i:i+length2]==string2):
                print("The index of first appearance of the substring is:",i)
    
    def word_count(self,string1):
        list1=[]
        word=" "
        string1=string1+" "
        for i in string1:
            if(i==" "):
                list1.append(word)
                word=" "
            else:
                word=word+i
        counts={}
        for i in list1:
            if i in counts:
                counts[i]+=1
            else:
                counts[i]=1
        return counts

ob=Assignment_2()
string1=input("Enter a string:")

while(True):
   
    print("1. To display word with the longest length.")
    print("2. To determine the frequency of occurrence of particular character in the string.")
    print("3. To check whether given string is palindrome or not.")
    print("4. To display index of first appearance of the substring.")
    print("5. To count the occurrences of each word in a given string.")
    print("6. Exit.")

    choice=int(input("Enter your choice:"))

    if(choice==1):

        print("The word with the longest length is:",ob.longest_length(string1))

    elif(choice==2):

        ch=input("Enter a character for its frequency:")
        print("The frequency of occurrence of the character is:",ob.frequency(string1,ch))

    elif(choice==3):
        
        ob.palindrome(string1)

    elif(choice==4):

        string2=input("Enter a substring to be found in the string:")
        ob.index_first(string1,string2)

    elif(choice==5):

        print("The frequency of occurrences of each word in the string is:",ob.word_count(string1))

    elif(choice==6):
        break

    else:
        print("Invalid choice. Please enter a number from 1 to 6.")

