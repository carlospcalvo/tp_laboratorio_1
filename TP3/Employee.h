#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldoStr);

int employee_setId(Employee* this, int id);
int employee_getId(Employee* this, int* id);
int employee_sortId(void* e1, void* e2);

int employee_setNombre(Employee* this, char* nombre);
int employee_getNombre(Employee* this, char* nombre);
int employee_sortNombre(void* e1, void* e2);

int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas);
int employee_sortHorasTrabajadas(void* e1, void* e2);

int employee_setSueldo(Employee* this, int sueldo);
int employee_getSueldo(Employee* this, int* sueldo);
int employee_sortSueldo(void* e1, void* e2);

int menu(int* option);
int employee_print(Employee* this);

#endif // employee_H_INCLUDED
