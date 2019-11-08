#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"

/** \brief Muestra el menu de opciones
 *
 * \param int* option
 * \param
 * \return int 1-10 segun opcion elegida.
 *
 */


int menu(int* option)
{
    system("cls");
    printf("****Menu de opciones****\n\n");
    printf("1-Cargar los datos de los empleados (Modo texto)\n");
    printf("2-Cargar los datos de los empleados (Modo binario)\n");
    printf("3-Alta de empleado\n");
    printf("4-Modificar datos de empleado\n");
    printf("5-Baja de empleado\n");
    printf("6-Listar empleados\n");
    printf("7-Ordenar empleados\n");
    printf("8-Guardar los datos (Modo texto)\n");
    printf("9-Guardar los datos (Modo binario)\n");
    printf("10-Salir\n\n");
    scanf("%d", option);

    return *option;
}

/** \brief Guarda una estructura Employee inicializada y devuelve un puntero a dicha estructura
 *
 * \param
 * \param
 * \return Employee* puntero a la estructura inicialiada
 *
 */

Employee* employee_new()
{
    Employee* nuevo = (Employee*) malloc(sizeof(Employee));
    if(nuevo != NULL)
    {
        nuevo->id = 0;
        strcpy(nuevo->nombre, " ");
        nuevo->horasTrabajadas = 0;
        nuevo->sueldo = 0;
    }
    return nuevo;
}

/** \brief Recibe como string el id, el nombre, las horas trabajadas y el sueldo de un empleado para crearlo.
 *
 * \param char* idStr
 * \param char* nombreStr
 * \param char* horasTrabajadasStr
 * \param char* sueldoStr
 * \return Employee* nuevo empleado
 *
 */

Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldoStr)
{
    Employee* nuevo = employee_new();
    if( nuevo != NULL)
    {
        if(!(employee_setId(nuevo, atoi(idStr))
        && employee_setNombre(nuevo, nombreStr)
        && employee_setHorasTrabajadas(nuevo, atoi(horasTrabajadasStr))
        && employee_setSueldo(nuevo, atoi(sueldoStr))))
        {
            nuevo = NULL;
        }
    }

    return nuevo;
}

/** \brief Muestra los datos de un empleado
 *
 * \param Employee*
 * \param
 * \return int 1 si se ejecutó correctamente, 0 si error.
 *
 */

int employee_print(Employee* this)
{
    int todoOk = 0;

    if(this != NULL)
    {
        printf("%04d  %20s          %4d           %7d\n", this->id, this->nombre, this->horasTrabajadas, this->sueldo);
        todoOk = 1;
    }

    return todoOk;

}

/** \brief Asigna el id al empleado
 *
 * \param Employee*
 * \param int
 * \return int 1 si se ejecutó correctamente, 0 si error.
 *
 */

int employee_setId(Employee* this, int id)
{
    int todoOk = 0;

    if(this != NULL && id > 0)
    {
        this->id = id;
        todoOk = 1;
    }
    return todoOk;
}

/** \brief Asigna el nombre al empleado
 *
 * \param Employee*
 * \param char*
 * \return int 1 si se ejecutó correctamente, 0 si error.
 *
 */

int employee_setNombre(Employee* this, char* nombre)
{
    int todoOk = 0;
    if(this != NULL && nombre != NULL && strlen(nombre) < 128)
    {
        strcpy(this->nombre, nombre);
        todoOk = 1;
    }
    return todoOk;
}

/** \brief Asigna las horas trabajadas al empleado
 *
 * \param Employee*
 * \param int
 * \return int 1 si se ejecutó correctamente, 0 si error.
 *
 */

int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas)
{
    int todoOk = 0;

    if( this != NULL && horasTrabajadas > 0)
    {
        this->horasTrabajadas = horasTrabajadas;
        todoOk = 1;
    }
    return todoOk;
}

/** \brief Asigna el sueldo al empleado
 *
 * \param Employee*
 * \param int
 * \return int 1 si se ejecutó correctamente, 0 si error.
 *
 */

int employee_setSueldo(Employee* this, int sueldo)
{
    int todoOk = 0;

    if(this != NULL && sueldo > 0)
    {
        this->sueldo = sueldo;
        todoOk = 1;
    }
    return todoOk;
}

/** \brief Obtiene el id del empleado
 *
 * \param Employee*
 * \param int
 * \return int 1 si se ejecutó correctamente, 0 si error.
 *
 */

int employee_getId(Employee* this, int* id)
{
    int todoOk = 0;

    if( this != NULL && id != NULL)
    {
        *id = this->id;
        todoOk = 1;
    }

    return todoOk;
}

/** \brief Obtiene el nombre del empleado
 *
 * \param Employee*
 * \param char*
 * \return int 1 si se ejecutó correctamente, 0 si error.
 *
 */

int employee_getNombre(Employee* this, char* nombre)
{
    int todoOk = 0;

    if( this != NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre);
        todoOk = 1;
    }
    return todoOk;
}

/** \brief Obtiene las horas trabajadas del empleado
 *
 * \param Employee*
 * \param int
 * \return int 1 si se ejecutó correctamente, 0 si error.
 *
 */

int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas)
{
    int todoOk = 0;

    if(this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        todoOk = 1;
    }

    return todoOk;
}

/** \brief Obtiene el sueldo del empleado
 *
 * \param Employee*
 * \param int
 * \return int 1 si se ejecutó correctamente, 0 si error.
 *
 */

int employee_getSueldo(Employee* this, int* sueldo)
{
    int todoOk = 0;

    if( this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        todoOk = 1;
    }

    return todoOk;
}

/** \brief Compara el id de dos empleados
 *
 * \param void*
 * \param void*
 * \return int 1 si el primer id de empleado es mayor al segundo id de empleado,
 *            -1 si el segundo id es mayor al primero,
 *             0 si son iguales.
 *
 */

int employee_sortId(void* e1, void* e2)
{
    int todoOk = 0;

    Employee* emp1 = (Employee*) e1;
    Employee* emp2 = (Employee*) e2;

    if(emp1 != NULL && emp2 != NULL)
    {
        if(emp1->id > emp2->id)
        {
            todoOk = 1;
        }
        else if(emp1->id < emp2->id)
        {
            todoOk = -1;
        }
    }

    return todoOk;
}

/** \brief Compara el nombre de dos empleados
 *
 * \param void*
 * \param void*
 * \return int 1 si el nombre del primer empleado es mayor al del segundo empleado,
 *            -1 si el nombre del segundo es mayor al nombre del primero,
 *             0 si son iguales.
 *
 */

int employee_sortNombre(void* e1, void* e2)
{
    int todoOk = 0;

    Employee* emp1 = (Employee*) e1;
    Employee* emp2 = (Employee*) e2;

    if(emp1 != NULL && emp2 != NULL)
    {
        if((strcmp(emp1->nombre, emp2->nombre)) > 0)
        {
            todoOk = 1;
        }
        else if((strcmp(emp1->nombre, emp2->nombre)) < 0)
        {
            todoOk = -1;
        }
    }

    return todoOk;
}

/** \brief Compara las horas trabajadas de dos empleados
 *
 * \param void*
 * \param void*
 * \return int 1 si la cantidad de horas trabajadas del primer empleado es mayor a la del segundo empleado,
 *            -1 si la cantidad de horas trabajadas del segundo empleado es mayor a la del primer empleado,
 *             0 si son iguales.
 *
 */

int employee_sortHorasTrabajadas(void* e1, void* e2)
{
    int todoOk = 0;

    Employee* emp1 = (Employee*) e1;
    Employee* emp2 = (Employee*) e2;

    if(emp1 != NULL && emp2 != NULL)
    {
        if(emp1->horasTrabajadas > emp2->horasTrabajadas)
        {
            todoOk = 1;
        }
        else if(emp1->horasTrabajadas < emp2->horasTrabajadas)
        {
            todoOk = -1;
        }
    }

    return todoOk;
}

/** \brief Compara el sueldo de dos empleados
 *
 * \param void*
 * \param void*
 * \return int 1 si el sueldo del primer empleado es mayor al del segundo empleado,
 *            -1 si el sueldo del segundo empleado es mayor al del primer empleado,
 *             0 si son iguales.
 *
 */

int employee_sortSueldo(void* e1, void* e2)
{
    int todoOk = 0;

    Employee* emp1 = (Employee*) e1;
    Employee* emp2 = (Employee*) e2;

    if(emp1 != NULL && emp2 != NULL)
    {
        if(emp1->sueldo > emp2->sueldo)
        {
            todoOk = 1;
        }
        else if(emp1->sueldo < emp2->sueldo)
        {
            todoOk = -1;
        }
    }

    return todoOk;
}
