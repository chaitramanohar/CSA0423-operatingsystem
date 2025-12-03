#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee {
    int id;
    char name[30];
    float salary;
};

void addEmployee(FILE *fp) {
    struct Employee e;

    printf("Enter Employee ID: ");
    scanf("%d", &e.id);

    printf("Enter Name: ");
    scanf("%s", e.name);

    printf("Enter Salary: ");
    scanf("%f", &e.salary);

    fseek(fp, (e.id - 1) * sizeof(struct Employee), SEEK_SET);
    fwrite(&e, sizeof(struct Employee), 1, fp);

    printf("\nEmployee record added successfully!\n");
}

void displayEmployee(FILE *fp) {
    struct Employee e;
    int id;

    printf("Enter Employee ID to search: ");
    scanf("%d", &id);

    fseek(fp, (id - 1) * sizeof(struct Employee), SEEK_SET);

    if (fread(&e, sizeof(struct Employee), 1, fp)) {
        if (e.id != 0) {
            printf("\nID: %d\nName: %s\nSalary: %.2f\n", e.id, e.name, e.salary);
        } else {
            printf("\nNo record found!\n");
        }
    } else {
        printf("\nError reading file!\n");
    }
}

void displayAllEmployees(FILE *fp) {
    struct Employee e;
    rewind(fp);

    printf("\n--- Employee List ---\n");

    while (fread(&e, sizeof(struct Employee), 1, fp)) {
        if (e.id != 0) {
            printf("ID: %d | Name: %s | Salary: %.2f\n", e.id, e.name, e.salary);
        }
    }
}

int main() {
    FILE *fp;
    struct Employee empty = {0, "", 0.0};
    int i;

    fp = fopen("employees.dat", "rb+");

    if (fp == NULL) {
        fp = fopen("employees.dat", "wb+");

        for (i = 0; i < 100; i++) {
            fwrite(&empty, sizeof(struct Employee), 1, fp);
        }
    }

    int choice;

    while (1) {
        printf("\n==== Employee Menu ====\n");
        printf("1. Add Employee\n");
        printf("2. Display Employee by ID\n");
        printf("3. Display All Employees\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee(fp);
                break;
            case 2:
                displayEmployee(fp);
                break;
            case 3:
                displayAllEmployees(fp);
                break;
            case 4:
                fclose(fp);
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

