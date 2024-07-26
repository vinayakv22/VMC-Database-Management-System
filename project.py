import pickle

class Student:
    def __init__(self):
        self.name = ""
        self.add = ""
        self.email = ""
        self.tel = ""
        self.coursen = ""
        self.fees = 0.0
        self.test1 = 0
        self.test2 = 0
        self.cc = 0
        self.course = 0
        self.course2 = 0

    def calculate(self):
        self.conc()
        bfee = [350000, 300000, 225000, 175000, 150000]
        self.fees = bfee[self.course - 1] * (1 - (0.01 * self.cc))

    def assign(self):
        courses = [
            "4 year program(9th)",
            "3 year program(10th)",
            "2 year program(11th)",
            "1 year program(12th)",
            "1 year program(12th Pass)"
        ]
        self.coursen = courses[self.course - 1]
        if self.course >= 3:
            if self.course2 == 1:
                self.coursen += ": Engineering"
            else:
                self.coursen += ": Medical"

    def conc(self):
        if self.test2 >= 200:
            self.cc = 90
        elif 180 <= self.test2 <= 200:
            self.cc = 70
        elif 150 <= self.test2 < 180:
            self.cc = 50
        elif 100 <= self.test2 < 150:
            self.cc = 30
        elif 80 <= self.test2 < 100:
            self.cc = 25
        else:
            self.cc = 0

    def phn(self):
        while True:
            self.tel = input("Enter phone number: ")
            if len(self.tel) == 10 and self.tel.isdigit():
                break
            else:
                print("**wrong number** Enter correct number.")

    def input(self):
        self.name = input("Enter Name of Student: ")
        self.add = input("Enter Address: ")
        self.email = input("Enter E-mail: ")
        while True:
            self.test1 = int(input("Enter %age in previous class (rounded off to nearest whole no.): "))
            if 0 <= self.test1 <= 100:
                break
            else:
                print("**wrong %age input** Enter correct %age")
        while True:
            self.test2 = int(input("Enter marks in scholarship test (out of 360): "))
            if 0 <= self.test2 <= 360:
                break
            else:
                print("**wrong marks input** Enter correct %age")
        self.phn()

    def crs(self):
        while True:
            self.course = int(input("Select Course:\n\n1) 4 year program (9th)\n2) 3 year program (10th)\n3) 2 year program (11th)\n4) 1 year program (12th)\n5) 1 year program (12th Pass)\n"))
            if 1 <= self.course <= 5:
                break
            else:
                print("**wrong choice**")
        self.course2 = 0
        if 3 <= self.course <= 5:
            while True:
                self.course2 = int(input("Choose stream:\n1) Engineering\n2) Medical\n"))
                if 1 <= self.course2 <= 2:
                    break
                else:
                    print("**wrong choice**")
        self.assign()

    def display(self):
        print(f"Name: {self.name}")
        print(f"Phone No.: {self.tel}")
        print(f"Address: {self.add}")
        print(f"E-mail: {self.email}")
        print(f"Course: {self.coursen}")
        print(f"Fees: {self.fees}")
        print(f"\nStudent Report:\n\t%age in previous class: {self.test1}%\n\tMarks in scholarship test: {self.test2}/360\n\tScholarship offered: {self.cc}%")

    def modify(self):
        while True:
            print(f"What do you wish to modify?\n1) Name: {self.name}\n2) Phone No.: {self.tel}\n3) Address: {self.add}\n4) E-mail: {self.email}\n5) Course: {self.coursen}\n6) %age in previous class: {self.test1}\n7) Marks in scholarship test: {self.test2}/360\n")
            choice = int(input())
            if choice == 1:
                self.name = input("Enter Name of Student: ")
            elif choice == 2:
                self.phn()
            elif choice == 3:
                self.add = input("Enter Address: ")
            elif choice == 4:
                self.email = input("Enter E-mail: ")
            elif choice == 5:
                self.crs()
            elif choice == 6:
                self.test1 = int(input("Enter %age in previous class (rounded off to nearest whole no.): "))
            elif choice == 7:
                self.test2 = int(input("Enter marks in scholarship test (out of 360): "))
                self.calculate()
            else:
                print("**wrong choice**")
            self.display()
            ch = input("Do you still wish to make changes? (Y or N): ")
            if ch.lower() != 'y':
                break

    def search(self, tel1):
        return self.tel == tel1


def main():
    students = []
    try:
        with open("record.dat", "rb") as f:
            students = pickle.load(f)
    except FileNotFoundError:
        pass

    while True:
        print("\t\t\tVIDYAMANDIR CLASSES\n")
        choice = int(input("Choose:\n1) Admission\n2) Search for a student's details\n3) Cancellation of Admission\n4) Modify details\n5) Student details for particular course\n6) Exit\n"))
        if choice == 1:
            s = Student()
            s.crs()
            s.input()
            s.calculate()
            students.append(s)
            with open("record.dat", "wb") as f:
                pickle.dump(students, f)
        elif choice == 2:
            tel = input("Enter phone number of student: ")
            for s in students:
                if s.search(tel):
                    s.display()
                    break
            else:
                print("**no match found**")
        elif choice == 3:
            tel = input("Enter phone number of student: ")
            students = [s for s in students if not s.search(tel)]
            with open("record.dat", "wb") as f:
                pickle.dump(students, f)
            print("DELETED" if len(students) < len(pickle.load(open("record.dat", "rb"))) else "NO MATCH FOUND")
        elif choice == 4:
            tel = input("Enter phone number of student: ")
            for s in students:
                if s.search(tel):
                    s.modify()
                    with open("record.dat", "wb") as f:
                        pickle.dump(students, f)
                    break
            else:
                print("**no match found**")
        elif choice == 5:
            c = int(input("Select Course:\n\n1) 4 year program (9th)\n2) 3 year program (10th)\n3) 2 year program (11th)\n4) 1 year program (12th)\n5) 1 year program (12th Pass)\n"))
            c2 = 0
            if 3 <= c <= 5:
                c2 = int(input("Choose stream:\n1) Engineering\n2) Medical\n"))
            for s in students:
                if s.course == c and (c < 3 or s.course2 == c2):
                    s.display()
        elif choice == 6:
            break
        else:
            print("**wrong choice**")
        ch = input("Do you wish to continue? (Y or N): ")
        if ch.lower() != 'y':
            break

if __name__ == "__main__":
    main()
