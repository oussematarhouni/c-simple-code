#include <stdio.h>
#include <string.h>
#define MAX_ETUDIANTS 50

struct notes {
    float analyse, algebre, c, python, algorithme, reseau, moyenne;
};

struct classe{
    char groupe[5];
    int td, tp;
};

struct insert{
    char firstname[20];
    char lastname[50];
    char educationlevel[20];
    int phonenumber, age;
    struct classe classe;
    struct notes moyenne;
};

void displayMenu() {
    printf("\n===== STUDENT MANAGEMENT SYSTEM =====\n");
    printf("1. Add Student\n");
    printf("2. Remove Student\n");
    printf("3. Display All Students\n");
    printf("4. Search Student by Name and Lastname\n");
    printf("5. Display Students by Group\n");
    printf("6. Display Students by TD\n");
    printf("7. Display Students by TP\n");
    printf("8. Exit\n");
    printf("=====================================\n");
}

float calculateAverage(struct notes n) {
    return (n.analyse + n.algebre + n.c + n.python + n.algorithme + n.reseau) / 6.0;
}

void addStudent(struct insert etudiants[], int numofstudents) {
    if (numofstudents >= MAX_ETUDIANTS) {
        printf("Cannot add more students. Maximum limit (%d) reached!\n", MAX_ETUDIANTS);
        return;
    }
    
    printf("\n--- Add New Student ---\n");
    
    printf("Enter first name: ");
    scanf("%s", etudiants[numofstudents].firstname);
    
    printf("Enter last name: ");
    scanf("%s", etudiants[numofstudents].lastname);
    
    printf("Enter phone number (8 digits): ");
    scanf("%d", &etudiants[numofstudents].phonenumber);
    while (etudiants[numofstudents].phonenumber < 10000000 || etudiants[numofstudents].phonenumber > 99999999) {
        printf("Invalid! Enter a valid 8-digit phone number: ");
        scanf("%d", &etudiants[numofstudents].phonenumber);
    }
    
    printf("Enter age: ");
    scanf("%d", &etudiants[numofstudents].age);
    while (etudiants[numofstudents].age > 30 || etudiants[numofstudents].age < 1) {
        printf("Invalid age! Enter age (1-30): ");
        scanf("%d", &etudiants[numofstudents].age);
    }
    
    printf("Enter education level: ");
    scanf("%s", etudiants[numofstudents].educationlevel);
    
    printf("Enter class group: ");
    scanf("%s", etudiants[numofstudents].classe.groupe);
    
    printf("Enter TD number (1-10): ");
    scanf("%d", &etudiants[numofstudents].classe.td);
    while (etudiants[numofstudents].classe.td < 1 || etudiants[numofstudents].classe.td > 10) {
        printf("Invalid! Enter TD number (1-10): ");
        scanf("%d", &etudiants[numofstudents].classe.td);
    }
    
    printf("Enter TP number (1-20): ");
    scanf("%d", &etudiants[numofstudents].classe.tp);
    while (etudiants[numofstudents].classe.tp < 1 || etudiants[numofstudents].classe.tp > 20) {
        printf("Invalid! Enter TP number (1-20): ");
        scanf("%d", &etudiants[numofstudents].classe.tp);
    }
    
    printf("\n--- Enter Grades (0-20) ---\n");
    
    printf("Analyse grade: ");
    scanf("%f", &etudiants[numofstudents].moyenne.analyse);
    while (etudiants[numofstudents].moyenne.analyse < 0 || etudiants[numofstudents].moyenne.analyse > 20) {
        printf("Invalid! Enter grade (0-20): ");
        scanf("%f", &etudiants[numofstudents].moyenne.analyse);
    }
    
    printf("Algebre grade: ");
    scanf("%f", &etudiants[numofstudents].moyenne.algebre);
    while (etudiants[numofstudents].moyenne.algebre < 0 || etudiants[numofstudents].moyenne.algebre > 20) {
        printf("Invalid! Enter grade (0-20): ");
        scanf("%f", &etudiants[numofstudents].moyenne.algebre);
    }
    
    printf("C grade: ");
    scanf("%f", &etudiants[numofstudents].moyenne.c);
    while (etudiants[numofstudents].moyenne.c < 0 || etudiants[numofstudents].moyenne.c > 20) {
        printf("Invalid! Enter grade (0-20): ");
        scanf("%f", &etudiants[numofstudents].moyenne.c);
    }
    
    printf("Algorithme grade: ");
    scanf("%f", &etudiants[numofstudents].moyenne.algorithme);
    while (etudiants[numofstudents].moyenne.algorithme < 0 || etudiants[numofstudents].moyenne.algorithme > 20) {
        printf("Invalid! Enter grade (0-20): ");
        scanf("%f", &etudiants[numofstudents].moyenne.algorithme);
    }
    
    printf("Reseau grade: ");
    scanf("%f", &etudiants[numofstudents].moyenne.reseau);
    while (etudiants[numofstudents].moyenne.reseau < 0 || etudiants[numofstudents].moyenne.reseau > 20) {
        printf("Invalid! Enter grade (0-20): ");
        scanf("%f", &etudiants[numofstudents].moyenne.reseau);
    }
    
    printf("Python grade: ");
    scanf("%f", &etudiants[numofstudents].moyenne.python);
    while (etudiants[numofstudents].moyenne.python < 0 || etudiants[numofstudents].moyenne.python > 20) {
        printf("Invalid! Enter grade (0-20): ");
        scanf("%f", &etudiants[numofstudents].moyenne.python);
    }
    
    etudiants[numofstudents].moyenne.moyenne = calculateAverage(etudiants[numofstudents].moyenne);
    
    printf("\nStudent added successfully!\n");
    printf("Average: %.2f\n", etudiants[numofstudents].moyenne.moyenne);
}

void removeStudent(struct insert etudiants[], int numofstudents) {
    if (numofstudents == 0) {
        printf("\nNo students to remove!\n");
        return;
    }
    
    char firstname[20], lastname[50];
    int found = -1;
    int i;
    
    printf("\n--- Remove Student ---\n");
    printf("Enter first name: ");
    scanf("%s", firstname);
    printf("Enter last name: ");
    scanf("%s", lastname);
    
    for (i = 0; i < numofstudents; i++) {
        if (strcmp(etudiants[i].firstname, firstname) == 0 && 
            strcmp(etudiants[i].lastname, lastname) == 0) {
            found = i;
            break;
        }
    }
    
    if (found == -1) {
        printf("\nStudent not found!\n");
        return;
    }
    
    for (i = found; i < numofstudents - 1; i++) {
        etudiants[i] = etudiants[i + 1];
    }
    
    printf("\nStudent removed successfully!\n");
}

void displayAllStudents(struct insert etudiants[], int numofstudents) {
    int i;
    
    if (numofstudents == 0) {
        printf("\nNo students to display!\n");
        return;
    }
    
    printf("\n===== ALL STUDENTS =====\n");
    printf("Total students: %d\n\n", numofstudents);
    
    for (i = 0; i < numofstudents; i++) {
        printf("--- Student #%d ---\n", i + 1);
        printf("Name: %s %s\n", etudiants[i].firstname, etudiants[i].lastname);
        printf("Phone: %d\n", etudiants[i].phonenumber);
        printf("Age: %d\n", etudiants[i].age);
        printf("Education Level: %s\n", etudiants[i].educationlevel);
        printf("Class: Group %s | TD: %d | TP: %d\n", 
               etudiants[i].classe.groupe, 
               etudiants[i].classe.td, 
               etudiants[i].classe.tp);
        
        printf("\nGrades:\n");
        printf("  Analyse: %.2f\n", etudiants[i].moyenne.analyse);
        printf("  Algebre: %.2f\n", etudiants[i].moyenne.algebre);
        printf("  C: %.2f\n", etudiants[i].moyenne.c);
        printf("  Algorithme: %.2f\n", etudiants[i].moyenne.algorithme);
        printf("  Reseau: %.2f\n", etudiants[i].moyenne.reseau);
        printf("  Python: %.2f\n", etudiants[i].moyenne.python);
        printf("  Overall Average: %.2f\n", etudiants[i].moyenne.moyenne);
        
        if (etudiants[i].moyenne.moyenne >= 10) {
            printf("  Status: PASSING\n");
        } else {
            printf("  Status: FAILING\n");
        }
        printf("------------------------\n\n");
    }
}

void searchByName(struct insert etudiants[], int numofstudents) {
    char searchFirst[20], searchLast[50];
    int found = 0;
    int i;
    
    if (numofstudents == 0) {
        printf("\nNo students to search!\n");
        return;
    }
    
    printf("\n--- Search Student by Name and Lastname ---\n");
    printf("Enter first name: ");
    scanf("%s", searchFirst);
    printf("Enter last name: ");
    scanf("%s", searchLast);
    
    printf("\n--- Search Results ---\n");
    for (i = 0; i < numofstudents; i++) {
        if (strcmp(etudiants[i].firstname, searchFirst) == 0 && 
            strcmp(etudiants[i].lastname, searchLast) == 0) {
            
            printf("\nStudent Found!\n");
            printf("Name: %s %s\n", etudiants[i].firstname, etudiants[i].lastname);
            printf("Phone: %d\n", etudiants[i].phonenumber);
            printf("Age: %d\n", etudiants[i].age);
            printf("Education Level: %s\n", etudiants[i].educationlevel);
            printf("Class: Group %s | TD: %d | TP: %d\n", 
                   etudiants[i].classe.groupe, 
                   etudiants[i].classe.td, 
                   etudiants[i].classe.tp);
            
            printf("\nGrades:\n");
            printf("  Analyse: %.2f\n", etudiants[i].moyenne.analyse);
            printf("  Algebre: %.2f\n", etudiants[i].moyenne.algebre);
            printf("  C: %.2f\n", etudiants[i].moyenne.c);
            printf("  Algorithme: %.2f\n", etudiants[i].moyenne.algorithme);
            printf("  Reseau: %.2f\n", etudiants[i].moyenne.reseau);
            printf("  Python: %.2f\n", etudiants[i].moyenne.python);
            printf("  Overall Average: %.2f\n", etudiants[i].moyenne.moyenne);
            
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("\nStudent not found!\n");
    }
}

void displayByGroup(struct insert etudiants[], int numofstudents) {
    char group[5];
    int found = 0;
    int i;
    
    if (numofstudents == 0) {
        printf("\nNo students to display!\n");
        return;
    }
    
    printf("\nEnter group name: ");
    scanf("%s", group);
    
    printf("\n===== STUDENTS IN GROUP %s =====\n", group);
    for (i = 0; i < numofstudents; i++) {
        if (strcmp(etudiants[i].classe.groupe, group) == 0) {
            printf("%s %s - TD: %d | TP: %d | Average: %.2f\n", 
                   etudiants[i].firstname, etudiants[i].lastname,
                   etudiants[i].classe.td, etudiants[i].classe.tp,
                   etudiants[i].moyenne.moyenne);
            found = 1;
        }
    }
    
    if (!found) {
        printf("No students found in group %s!\n", group);
    }
}

void displayByTD(struct insert etudiants[], int numofstudents) {
    int tdNumber;
    int found = 0;
    int i;
    
    if (numofstudents == 0) {
        printf("\nNo students to display!\n");
        return;
    }
    
    printf("\nEnter TD number (1-10): ");
    scanf("%d", &tdNumber);
    
    while (tdNumber < 1 || tdNumber > 10) {
        printf("Invalid! Enter TD number (1-10): ");
        scanf("%d", &tdNumber);
    }
    
    printf("\n===== STUDENTS IN TD %d =====\n", tdNumber);
    for (i = 0; i < numofstudents; i++) {
        if (etudiants[i].classe.td == tdNumber) {
            printf("%s %s - Group: %s | TP: %d | Average: %.2f\n", 
                   etudiants[i].firstname, etudiants[i].lastname,
                   etudiants[i].classe.groupe, etudiants[i].classe.tp,
                   etudiants[i].moyenne.moyenne);
            found = 1;
        }
    }
    
    if (!found) {
        printf("No students found in TD %d!\n", tdNumber);
    }
}

void displayByTP(struct insert etudiants[], int numofstudents) {
    int tpNumber;
    int found = 0;
    int i;
    
    if (numofstudents == 0) {
        printf("\nNo students to display!\n");
        return;
    }
    
    printf("\nEnter TP number (1-20): ");
    scanf("%d", &tpNumber);
    
    while (tpNumber < 1 || tpNumber > 20) {
        printf("Invalid! Enter TP number (1-20): ");
        scanf("%d", &tpNumber);
    }
    
    printf("\n===== STUDENTS IN TP %d =====\n", tpNumber);
    for (i = 0; i < numofstudents; i++) {
        if (etudiants[i].classe.tp == tpNumber) {
            printf("%s %s - Group: %s | TD: %d | Average: %.2f\n", 
                   etudiants[i].firstname, etudiants[i].lastname,
                   etudiants[i].classe.groupe, etudiants[i].classe.td,
                   etudiants[i].moyenne.moyenne);
            found = 1;
        }
    }
    
    if (!found) {
        printf("No students found in TP %d!\n", tpNumber);
    }
}

int main() {
    struct insert etudiants[MAX_ETUDIANTS];
    int numofstudents = 0;
    int choice;
    
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addStudent(etudiants, numofstudents);
                numofstudents++;
                break;
            case 2:
                removeStudent(etudiants, numofstudents);
                if (numofstudents > 0) {
                    numofstudents--;
                }
                break;
            case 3:
                displayAllStudents(etudiants, numofstudents);
                break;
            case 4:
                searchByName(etudiants, numofstudents);
                break;
            case 5:
                displayByGroup(etudiants, numofstudents);
                break;
            case 6:
                displayByTD(etudiants, numofstudents);
                break;
            case 7:
                displayByTP(etudiants, numofstudents);
                break;
            case 8:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice != 8);
    
    return 0;
}
