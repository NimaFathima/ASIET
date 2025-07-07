while True:
    c = int(input("1.ADDITION \n2.SUBTRACTION \n3.MULTIPLICATION \n4.DIVISION \n5.Exit \nEnter your choice:  "))
    if c in [1, 2, 3, 4]:
        a = eval(input("Enter the first number: "))
        b = eval(input("Enter the second number: "))
        if c == 1:
            print("RESULT AFTER ADDITION: ", a + b)
        elif c == 2:
            print("RESULT AFTER SUBTRACTION: ", a - b)
        elif c == 3:
            print("RESULT AFTER MULTIPLICATION: ", a * b)
        elif c == 4:
            if b == 0:
                print("ERROR! DIVISION BY ZERO NOT POSSIBLE")
            else:
                print("RESULT AFTER DIVISION (float): ", a / b)
    elif c == 5:
        print("Exiting the program....")
        break
    else:
        print("Sorry, Invalid choice try again!")
