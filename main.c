//Group 21 class A
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include "define.h"
#include "highest_GPA.h"
#include "lowest_GPA.h"
#include "highest_BP.h"
#include "oldest_student.h"
#include "youngest_student.h"

int main() {
    
    int numOfStudents;
    do
    {
        printf("Enter number of students (maximum 1000): ");
        scanf("%d", &numOfStudents);
    } while (numOfStudents > MAXIMUM_STUDENTS);

    struct Student students[numOfStudents];
    
    for (int i = 0; i < numOfStudents; i++) {
        printf("Enter information for student %d:\n", i+1);
        printf("\nStudent ID: ");
        scanf("%s", students[i].studentID);
        printf("\n");
        printf("Last Name: ");
        scanf(" %s", students[i].lastName);
        printf("\n");
        printf("First Name: ");
        scanf(" %s", students[i].firstName);
        printf("\n");
        printf("Birthdate (dd/mm/yyyy) \n"); 
        printf("EX: 21 10 2003: ");
        printf("\n"); 
        scanf("%s %s %s", students[i].bir, students[i].thd, students[i].ate);
        printf("\n");
        printf("Algebra grade: ");
        scanf("%f", &students[i].algebraGrade);
        printf("Calculus grade: ");
        scanf("%f", &students[i].calculusGrade);
        printf("Programming grade: ");
        scanf("%f", &students[i].programmingGrade);
        printf("\n");
        // calculate GPA
        students[i].gpa = (students[i].algebraGrade + students[i].calculusGrade + students[i].programmingGrade) / 3.0;
    }

    printf("\n");
    printf("-----------------------------------------------------------------------------");
    printf("\n\n");

    //Print student list as a table to screen
    printf("+-------------+----------------------------+-----------------+---------+---------+-------------------+--------+\n");
    printf("|  Student ID |          Full Name         |    Birthdate    | Algebra | Calculus| Basic Programming |   GPA  |\n");
    printf("+-------------+----------------------------+-----------------+---------+---------+-------------------+--------+\n");

    for (int i = 0; i < numOfStudents; i++) {
    char fullName[50];
    strcpy(fullName, students[i].lastName);
    strcat(fullName, " ");
    strcat(fullName, students[i].firstName);

    printf("| %5s    | %-26s |    %1s/%2s/%3s   | %6.2f  | %6.2f  |%12.2f       | %6.2f |\n",
        students[i].studentID,
        fullName,
        students[i].bir,
        students[i].thd,
        students[i].ate,
        students[i].algebraGrade,
        students[i].calculusGrade,
        students[i].programmingGrade,
        students[i].gpa);
    printf("+-------------+----------------------------+-----------------+---------+---------+-------------------+--------+\n");
}
    
    printf("\n");

    //Print the student with highest GPA
    struct Student highestGPAStudent = findHighestGPA(students, numOfStudents);
    for (int i = 0; i < numOfStudents; i++) {
        if ( students[i].gpa == highestGPAStudent.gpa ) {
    printf("Student with highest GPA:\n");  
    printf("ID: %s\n", students[i].studentID);
    printf("Name: %s %s\n", students[i].firstName, students[i].lastName);
    printf("GPA: %.2f\n", students[i].gpa);
    printf("\n");}
    }
    
    //Print the student with lowest GPA
    struct Student lowestGPAStudent = findLowestGPA(students, numOfStudents);
    for (int i = 0; i < numOfStudents; i++) {
        if ( students[i].gpa == lowestGPAStudent.gpa ) {    
    printf("Student with lowest GPA:\n");
    printf("ID: %s\n", students[i].studentID);
    printf("Name: %s %s\n", students[i].firstName, students[i].lastName);
    printf("GPA: %.2f\n", students[i].gpa);
    printf("\n");}
    }

    //Print the student with highest BP grade
    struct Student highestBPStudent = findHighestBP(students, numOfStudents);
    for (int i = 0; i < numOfStudents; i++) {
        if ( students[i].programmingGrade == highestBPStudent.programmingGrade ){
    printf("Student with highest BP grade:\n");
    printf("ID: %s\n", students[i].studentID);
    printf("Name: %s %s\n", students[i].firstName, students[i].lastName);
    printf("Basic Programming grade: %.2f\n", students[i].programmingGrade);
    printf("\n");}
    }

    //Print the oldest student with ID, full name, and birthdate
    struct Student oldestStudent = findOldestStudent(students, numOfStudents);
    for (int i = 0; i < numOfStudents; i++) {
        if ( strcmp(students[i].thd, oldestStudent.thd)==0 && strcmp(students[i].ate, oldestStudent.ate)==0 && strcmp(students[i].bir, oldestStudent.bir)==0 ){
    printf("Oldest student:\n");
    printf("ID: %s\n", students[i].studentID);
    printf("Name: %s %s\n", students[i].firstName, students[i].lastName);
    printf("Birthdate: %s/%s/%s\n", students[i].bir, students[i].thd, students[i].ate);
    printf("\n");
        }
    }

    //Print the youngest student
    struct Student youngestStudent = findYoungestStudent(students, numOfStudents);
    for (int i = 0; i < numOfStudents; i++) {
        if ( strcmp(students[i].thd, youngestStudent.thd)==0 && strcmp(students[i].ate, youngestStudent.ate)==0 && strcmp(students[i].bir, youngestStudent.bir)==0 ){
    printf("Youngest student:\n");
    printf("ID: %s\n", students[i].studentID);
    printf("Name: %s %s\n", students[i].firstName, students[i].lastName);
    printf("Birthdate: %s/%s/%s\n", students[i].bir, students[i].thd, students[i].ate);
    printf("\n");
        }
    }

    // Print student list as a table to a text file
    FILE *file = fopen("student_list.txt", "w");
    fprintf(file, "+-------------+----------------------------+-----------------+---------+---------+-------------------+--------+\n");
    fprintf(file, "|  Student ID |          Full Name         |    Birthdate    | Algebra | Calculus| Basic Programming |   GPA  |\n");
    fprintf(file, "+-------------+----------------------------+-----------------+---------+---------+-------------------+--------+\n");

    for (int i = 0; i < numOfStudents; i++) {
        fprintf(file, "| %5s   | %-26s |    %1s/%2s/%3s   | %6.2f  | %6.2f  |%12.2f       | %6.2f |\n",
            students[i].studentID,
            strcat(strcat(students[i].lastName, " "), students[i].firstName),
            students[i].bir,
            students[i].thd,
            students[i].ate,
            students[i].algebraGrade,
            students[i].calculusGrade,
            students[i].programmingGrade,
            students[i].gpa);
        fprintf(file, "+-------------+----------------------------+-----------------+---------+---------+-------------------+--------+\n");
    }

    fclose(file);

    return 0;
}