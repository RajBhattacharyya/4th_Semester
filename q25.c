#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_COURSES 100
#define MAX_NAME_LENGTH 50
#define MAX_COURSE_NAME_LENGTH 100

typedef struct {
    char username[MAX_NAME_LENGTH];
    char password[MAX_NAME_LENGTH];
    int role; // 1: student, 2: teacher, 3: administrator
} User;

typedef struct {
    char name[MAX_COURSE_NAME_LENGTH];
    char schedule[7][100]; // Assuming a weekly schedule with 7 days
} Course;

User users[MAX_USERS];
Course courses[MAX_COURSES];
int num_users = 0;
int num_courses = 0;

void login() {
    char username[MAX_NAME_LENGTH];
    char password[MAX_NAME_LENGTH];
    int role;
    
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    // Check if user exists and password matches
    for (int i = 0; i < num_users; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            role = users[i].role;
            printf("Login successful!\n");
            printf("Welcome, %s\n", username);
            // Call appropriate function based on user role
            if (role == 1) {
                // Student functions
                printf("Viewing your schedule...\n");
            } else if (role == 2) {
                // Teacher functions
                printf("Managing your schedule...\n");
            } else if (role == 3) {
                // Administrator functions
                printf("Managing the system...\n");
            }
            return;
        }
    }
    printf("Invalid username or password. Please try again.\n");
}

void add_user(char *username, char *password, int role) {
    if (num_users < MAX_USERS) {
        strcpy(users[num_users].username, username);
        strcpy(users[num_users].password, password);
        users[num_users].role = role;
        num_users++;
        printf("User added successfully.\n");
    } else {
        printf("Maximum number of users reached.\n");
    }
}

void add_course(char *name, char schedule[7][100]) {
    if (num_courses < MAX_COURSES) {
        strcpy(courses[num_courses].name, name);
        for (int i = 0; i < 7; i++) {
            strcpy(courses[num_courses].schedule[i], schedule[i]);
        }
        num_courses++;
        printf("Course added successfully.\n");
    } else {
        printf("Maximum number of courses reached.\n");
    }
}

int main() {
    // Initialize users and courses (dummy data)
    add_user("student1", "12345", 1);
    add_user("teacher1", "teacherpass", 2);
    add_user("admin1", "adminpass", 3);

    char math_schedule[7][100] = {
        "Monday: 9:00 AM - 11:00 AM",
        "Tuesday: 10:00 AM - 12:00 PM",
        "Wednesday: 9:00 AM - 11:00 AM",
        "Thursday: 10:00 AM - 12:00 PM",
        "Friday: 9:00 AM - 11:00 AM",
        "", // No classes on Saturday
        ""  // No classes on Sunday
    };
    add_course("Mathematics", math_schedule);

    login();
    return 0;
}
