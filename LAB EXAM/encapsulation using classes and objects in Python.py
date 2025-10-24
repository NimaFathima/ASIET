# A simpler class to demonstrate encapsulation

class Student:
    def __init__(self):
        """
        Initializes the Student with a private name attribute.
        """
        self.__name = ""  # Private attribute

    def set_name(self, name):
        """
        Public "setter" method to update the private name.
        We could add validation logic here (e.g., check if name is a string).
        """
        self.__name = name

    def get_name(self):
        """
        Public "getter" method to read the private name.
        """
        return self.__name

# --- Main part of the program ---

if __name__ == "__main__":
    # Create an instance of the Student class
    s = Student()
    
    # Use the public "setter" method to set the name
    s.set_name("Alice")
    
    # Use the public "getter" method to retrieve and print the name
    print("Student Name:", s.get_name())

    # This would cause an AttributeError because __name is private:
    # print(s.__name)

