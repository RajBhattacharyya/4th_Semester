class User:
    def __init__(self, username, password, role):
        self.username = username
        self.password = password
        self.role = role

class Course:
    def __init__(self, name, schedule):
        self.name = name
        self.schedule = schedule

users = []
courses = []

def login():
    username = input("Enter username: ")
    password = input("Enter password: ")

    # Check if user exists and password matches
    for user in users:
        if user.username == username and user.password == password:
            print("Login successful!")
            print(f"Welcome, {username}")
            # Call appropriate function based on user role
            if user.role == 1:
                # Student functions
                print("Viewing your schedule...")
            elif user.role == 2:
                # Teacher functions
                print("Managing your schedule...")
            elif user.role == 3:
                # Administrator functions
                print("Managing the system...")
            return
    print("Invalid username or password. Please try again.")

def add_user(username, password, role):
    users.append(User(username, password, role))
    print("User added successfully.")

def add_course(name, schedule):
    courses.append(Course(name, schedule))
    print("Course added successfully.")

# Initialize users and courses (dummy data)
add_user("student1", "12345", 1)
add_user("teacher1", "teacherpass", 2)
add_user("admin1", "adminpass", 3)

math_schedule = [
    "Monday: 9:00 AM - 11:00 AM",
    "Tuesday: 10:00 AM - 12:00 PM",
    "Wednesday: 9:00 AM - 11:00 AM",
    "Thursday: 10:00 AM - 12:00 PM",
    "Friday: 9:00 AM - 11:00 AM",
    "", # No classes on Saturday
    ""  # No classes on Sunday
]
add_course("Mathematics", math_schedule)

login()
