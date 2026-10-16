#include <stdio.h>

#define MAX_STUDENTS 100

struct Student {
    int rollNo;
    char name[50];
    float mark1, mark2, mark3;
    float average;
};

struct Student students[MAX_STUDENTS];
int totalStudents = 0;

// Add a new student's details
void addStudent() {
    if (totalStudents == MAX_STUDENTS) {
        printf("\nSorry, the student list is full!\n");
        return;
    }

    struct Student *s = &students[totalStudents];

    printf("\nEnter roll number: ");
    if (scanf("%d", &s->rollNo) != 1) {
        printf("Invalid roll number!\n");
        return;
    }

    // Prevent duplicate roll numbers
    for (int i = 0; i < totalStudents; i++) {
        if (students[i].rollNo == s->rollNo) {
            printf("This roll number already exists!\n");
            return;
        }
    }

    printf("Enter student name (no spaces): ");
    scanf("%49s", s->name);

    printf("Enter marks for 3 subjects: ");
    if (scanf("%f %f %f",
              &s->mark1, &s->mark2, &s->mark3) != 3) {
        printf("Please enter valid marks!\n");
        return;
    }

    if (s->mark1 < 0 || s->mark1 > 100 ||
        s->mark2 < 0 || s->mark2 > 100 ||
        s->mark3 < 0 || s->mark3 > 100) {
        printf("Marks must be between 0 and 100!\n");
        return;
    }

    s->average = (s->mark1 + s->mark2 + s->mark3) / 3.0f;
    totalStudents++;

    printf("\nStudent added successfully!\n");
}

// Display all students
void displayStudents() {
    if (totalStudents == 0) {
        printf("\nNo student records yet. Add a student first!\n");
        return;
    }

    printf("\n========== STUDENT RECORDS ==========\n");

    for (int i = 0; i < totalStudents; i++) {
        printf("\nRoll Number : %d\n", students[i].rollNo);
        printf("Name        : %s\n", students[i].name);
        printf("Marks       : %.2f, %.2f, %.2f\n",
               students[i].mark1,
               students[i].mark2,
               students[i].mark3);
        printf("Average     : %.2f / 100\n",
               students[i].average);
    }
}

// Find a student using their roll number
void searchStudent() {
    int rollNo;

    printf("\nEnter roll number to search: ");
    if (scanf("%d", &rollNo) != 1) {
        printf("Invalid input!\n");
        return;
    }

    for (int i = 0; i < totalStudents; i++) {
        if (students[i].rollNo == rollNo) {
            printf("\nStudent found!\n");
            printf("Name    : %s\n", students[i].name);
            printf("Average : %.2f\n", students[i].average);
            return;
        }
    }

    printf("\nSorry, no student with that roll number was found.\n");
}

int main() {
    int choice;

    do {
        printf("\n====================================\n");
        printf("       STUDENT MANAGEMENT SYSTEM\n");
        printf("====================================\n");
        printf("1. Add a student\n");
        printf("2. View all students\n");
        printf("3. Search for a student\n");
        printf("4. Exit\n");
        printf("------------------------------------\n");
        printf("Choose an option: ");

        if (scanf("%d", &choice) != 1) {
            printf("Please enter a valid menu number.\n");
            return 1;
        }

        switch (choice) {
            case 1:
                addStudent();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                printf("\nThanks for using the program. Goodbye!\n");
                break;

            default:
                printf("\nThat option doesn't exist. Try again!\n");
        }

    } while (choice != 4);

    return 0;
}
