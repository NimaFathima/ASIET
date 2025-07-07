str=input("Enter the string: ")
c=0
for i in str:
       if i.isspace()==False:
              c=c+1
print("no of characters: ",c)
print("UPPERCASE: ",str.upper())
print("LOWERCASE: ",str.lower())
for i in str:
       str.replace(" ","_")
w=str.split()
for i in w :
       if i=="Python":
              print(" word 'Python' is present in sentence.")
