#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
} Employee;

#endif // ARRAYEMPLOYEES_H_INCLUDED

int menu();
int newEmployee(Employee vec[], int length, int id);
int findFreeSlot(Employee vec[], int length);
int findEmployeeById(Employee vec[], int length, int id);
int modifyEmployee(Employee vec[], int length);
int removeEmployee(Employee vec[], int length);
int sortEmployees(Employee vec[], int length, int order);
int sortMenu(Employee vec[], int length);
int checkEmployees( Employee vec[], int length);
int getSalariesOverAvg(Employee vec[], int length);
float getSalariesTotal( Employee vec[], int length);
float getSalariesAvg(Employee vec[], int length);
void initEmployees(Employee vec[], int length);
void printEmployee(Employee x);
void printEmployees(Employee vec[], int length);
Employee addEmployee(int id, char name[], char lastName[], float salary, int sector);
