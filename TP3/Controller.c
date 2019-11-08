#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int 1 si se ejecutó correctamente, 0 si error
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int todoOk = 0;

    system("cls");

    if(path != NULL && pArrayListEmployee != NULL && ll_isEmpty(pArrayListEmployee))
    {
        FILE* f = fopen(path, "r");

        if(parser_EmployeeFromText(f, pArrayListEmployee))
        {
            todoOk = 1;
        }
    }

    if(todoOk == 1)
    {
        printf("Datos guardados en data.csv exitosamente.\n");
    }
    else
    {
        printf("No se pudo guardar los datos en data.csv.\n");
    }

    system("pause");

    return todoOk;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int 1 si se ejecutó correctamente, 0 si error
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int todoOk = 0;

    system("cls");

    if(path != NULL && pArrayListEmployee != NULL && ll_isEmpty(pArrayListEmployee))
    {
        FILE* f = fopen(path, "rb");
        if(parser_EmployeeFromBinary(f, pArrayListEmployee))
        {
            todoOk = 1;
        }
    }

    if(todoOk == 1)
    {
        printf("Datos guardados en data.csv exitosamente.\n");
    }
    else
    {
        printf("No se pudo guardar los datos en data.csv.\n");
    }

    system("pause");

    return todoOk;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int 1 si se ejecutó correctamente, 0 si error en la carga del empleado, -1 si aun no se cargó ningún archivo
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk = -1;
    int idAux = 0;
    char nombreAux[200];
    int horasAux;
    int sueldoAux;
    char idStr[20];
    char horasTrabajadasStr[20];
    char sueldoStr[20];
    Employee* nuevo = NULL;

    system("cls");

    if(pArrayListEmployee != NULL && !(ll_isEmpty(pArrayListEmployee)))
    {
        nuevo = employee_new();

        printf("*****Nuevo empleado*****\n\n");

        idAux = ll_len(pArrayListEmployee) + 1;

        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(nombreAux);
        while(!(strlen(nombreAux)<128))
        {
            printf("Nombre demasiado largo. Reingrese: ");
            fflush(stdin);
            gets(nombreAux);
        }

        printf("Ingrese cantidad de horas trabajadas: ");
        fflush(stdin);
        scanf("%d", &horasAux);
        while(horasAux <= 0)
        {
            printf("La cantidad de horas trabajadas debe ser igual o menor a 0(cero). Reingrese: ");
            fflush(stdin);
            scanf("%d", &horasAux);
        }

        printf("Ingrese sueldo: ");
        fflush(stdin);
        scanf("%d", &sueldoAux);
        while(sueldoAux <= 0)
        {
            printf("El sueldo debe ser igual o menor a 0(cero). Reingrese: ");
            fflush(stdin);
            scanf("%d", &sueldoAux);
        }

        itoa(idAux, idStr, 10);
        itoa(horasAux,horasTrabajadasStr, 10);
        itoa(sueldoAux,sueldoStr, 10);

        nuevo = employee_newParametros(idStr, nombreAux, horasTrabajadasStr, sueldoStr);

        if(nuevo != NULL)
        {
            ll_add(pArrayListEmployee, nuevo);
            todoOk = 1;
        }
        else
        {
            todoOk = 0;
        }
    }

    if(todoOk == 1)
    {
        printf("Empleado agregado exitosamente.\n");
        system("pause");
    }
    else if(todoOk == 0)
    {
        printf("No se pudo agregar el empleado. \n");
        system("pause");
    }
    else
    {
        printf("Cargue un archivo antes de agregar nuevos empleados. \n");
        system("pause");
    }
    return todoOk;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int 1 si se ejecutó correctamente, 0 si error, -1 si se canceló la modificación
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    int idAux;
    Employee* empleadoAux = NULL;
    int option;
    char nombreAux[200];
    int horasAux;
    int sueldoAux;

    system("cls");
    printf("*****Modificar empleado*****\n\n");

    if(pArrayListEmployee != NULL && !(ll_isEmpty(pArrayListEmployee)))
    {
        printf("Ingrese id de empleado a modificar: ");
        fflush(stdin);
        scanf("%d", &idAux);
        while(idAux < 0)
        {
            printf("El numero de id debe ser mayor a 0 (cero). Reingrese: ");
            fflush(stdin);
            scanf("%d", &idAux);
        }
        while(idAux > ll_len(pArrayListEmployee))
        {
            printf("No hay empleados con ese numero de id, reingrese: ");
            fflush(stdin);
            scanf("%d", &idAux);
        }

        empleadoAux = ll_get(pArrayListEmployee, (idAux-1));
        printf("\nId                  Nombre    Horas Trabajadas      Sueldo\n");
        employee_print(empleadoAux);
        printf("\n\n");

        printf("1- Modificar nombre\n");
        printf("2- Modificar horas trabajadas\n");
        printf("3- Modificar sueldo\n");
        printf("4- Salir\n\n");
        printf("Ingrese opcion: ");
        fflush(stdin);
        scanf("%d", &option);

        switch(option)
        {
        case 1:
            printf("Ingrese nuevo nombre: ");
            fflush(stdin);
            gets(nombreAux);
            while(!(strlen(nombreAux) < 128))
            {
                printf("Nombre demasiado largo, reingrese: ");
                gets(nombreAux);
            }

            if(employee_setNombre(empleadoAux, nombreAux))
            {
                todoOk = 1;
            }
            break;

        case 2:
            printf("Ingrese nueva cantidad de horas trabajadas: ");
            fflush(stdin);
            scanf("%d", &horasAux);
            while(horasAux <= 0)
            {
                printf("La cantidad de horas trabajadas debe ser igual o menor a 0(cero). Reingrese: ");
                fflush(stdin);
                scanf("%d", &horasAux);
            }
            if(employee_setHorasTrabajadas(empleadoAux, horasAux))
            {
                todoOk = 1;
            }
            break;

        case 3:
            printf("Ingrese nuevo sueldo: ");
            fflush(stdin);
            scanf("%d", &sueldoAux);
            while(sueldoAux < 0)
            {
                printf("El salario debe ser mayor o igual a 0 (cero). Reingrese: ");
                fflush(stdin);
                scanf("%d", &sueldoAux);
            }
            if(employee_setSueldo(empleadoAux, sueldoAux))
            {
                todoOk = 1;
            }
            break;

        case 4:
            todoOk = -1;
            break;

        default:
            printf("Opcion invalida.\n");
        }
    }

    if(todoOk == 1)
    {
        printf("Empleado modificado exitosamente.\n");
    }
    else if(todoOk == 0)
    {
        system("cls");
        printf("No se pudo modificar el empleado. Debe cargar un archivo si aun no lo hizo.\n");
        system("pause");
    }
    else
    {
        system("cls");
        printf("La modificacion fue cancelada.\n");
        system("pause");
    }
    return todoOk;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int  1 si se ejecutó correctamente, 0 si error, -1 si se canceló la modificación
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    int idAux;
    Employee* empleadoAux = NULL;
    char option;

    system("cls");

    if(pArrayListEmployee != NULL && !(ll_isEmpty(pArrayListEmployee)))
    {
        printf("*****Eliminar empleado*****\n\n");
        printf("Ingrese id de empleado a eliminar: ");
        fflush(stdin);
        scanf("%d", &idAux);
        while(idAux < 0)
        {
            printf("El numero de id debe ser mayor a 0 (cero). Reingrese: ");
            fflush(stdin);
            scanf("%d", &idAux);
        }
        while(idAux > ll_len(pArrayListEmployee))
        {
            printf("No hay empleados con ese numero de id, reingrese: ");
            fflush(stdin);
            scanf("%d", &idAux);
        }

        empleadoAux = ll_get(pArrayListEmployee, (idAux-1));
        printf("\nId                  Nombre    Horas Trabajadas      Sueldo\n");
        employee_print(empleadoAux);
        printf("\n\nSe eliminara el empleado. Desea continuar? (y/n): ");
        fflush(stdin);
        option = getche();
        while(!(option == 'y' || option == 'n'))
        {
            printf("\nIngrese 'y' para eliminar el empleado, 'n' para salir: ");
                   fflush(stdin);
                   option = getche();
        }
        if(option == 'y')
        {
            ll_remove(pArrayListEmployee, (idAux-1));
            todoOk = 1;
            printf("\nEl empleado se elimino correctamente. \n");
        }
        if(option == 'n')
        {
            todoOk = -1;
            printf("\nSe ha cancelado la eliminacion. \n");
        }
    }

    if(ll_isEmpty(pArrayListEmployee))
    {
        printf("No hay empleados cargados todavia.\n");
        system("pause");
    }
    return todoOk;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int  1 si se ejecutó correctamente, 0 si error
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    Employee* empleadoAux = NULL;

    system("cls");

    if(pArrayListEmployee != NULL && ll_len(pArrayListEmployee) > 0)
    {
        printf("Id                  Nombre    Horas Trabajadas      Sueldo\n\n");
        for(int i=0; i < ll_len(pArrayListEmployee); i++)
        {
            empleadoAux = (Employee*) ll_get(pArrayListEmployee, i);
            employee_print(empleadoAux);
        }
        todoOk = 1;
    }
    else
    {
        printf("No hay empleados que mostrar. \n");
    }

    system("pause");

    return todoOk;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int 1 si se ejecutó correctamente, 0 si error
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    int option;

    system("cls");

    if(pArrayListEmployee != NULL && !(ll_isEmpty(pArrayListEmployee)))
    {
        printf("*****Ordenar empleados*****\n\n");
        printf("1- Ordenar por id ascendiente\n");
        printf("2- Ordenar por id descendiente\n");
        printf("3- Ordenar por nombre ascendiente\n");
        printf("4- Ordenar por nombre descendiente\n");
        printf("5- Ordenar por horas trabajadas ascendiente\n");
        printf("6- Ordenar por horas trabajadas descendiente\n");
        printf("7- Ordenar por sueldo ascendiente\n");
        printf("8- Ordenar por sueldo descendiente\n");
        printf("9- Salir\n\n");
        printf("Ingrese opcion: ");
        fflush(stdin);
        scanf("%d", &option);

        switch(option)
        {
        case 1:
            ll_sort(pArrayListEmployee, employee_sortId, 1);
            todoOk = 1;
            break;

        case 2:
            ll_sort(pArrayListEmployee, employee_sortId, 0);
            todoOk = 1;
            break;

        case 3:
            ll_sort(pArrayListEmployee, employee_sortNombre, 1);
            todoOk = 1;
            break;

        case 4:
            ll_sort(pArrayListEmployee, employee_sortNombre, 0);
            todoOk = 1;
            break;

        case 5:
            ll_sort(pArrayListEmployee, employee_sortHorasTrabajadas, 1);
            todoOk = 1;
            break;

        case 6:
            ll_sort(pArrayListEmployee, employee_sortHorasTrabajadas, 0);
            todoOk = 1;
            break;

        case 7:
            ll_sort(pArrayListEmployee, employee_sortSueldo, 1);
            todoOk = 1;
            break;

        case 8:
            ll_sort(pArrayListEmployee, employee_sortSueldo, 0);
            todoOk = 1;
            break;

        case 9:
            todoOk = -1;
            break;

        default:
            printf("Opcion invalida.\n");
        }
    }
    if(ll_isEmpty(pArrayListEmployee))
    {
        printf("No se han cargado empleados todavia.\n");
    }

    if(todoOk == 1)
    {
        printf("Empleados ordenados.\n");
    }
    system("pause");

    return todoOk;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int  1 si se ejecutó correctamente, 0 si error
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    int cant;
    int tam = ll_len(pArrayListEmployee);
    FILE* f;
    Employee* auxEmp;

    system("cls");

    if(pArrayListEmployee != NULL && path != NULL && tam > 0)
    {
        f = fopen(path, "w");
        if(f == NULL)
        {
            return todoOk;
        }

        fprintf(f, "ID,Nombre,Horas trabajadas,Sueldo\n");

        for(int i=0; i<tam; i++)
        {
            auxEmp = (Employee*) ll_get(pArrayListEmployee, i);
            cant = fprintf(f, "%d, %s, %d, %d\n",
                           auxEmp->id,
                           auxEmp->nombre,
                           auxEmp->horasTrabajadas,
                           auxEmp->sueldo);

            if (cant < 1)
            {
                return todoOk;
            }
        }
        todoOk = 1;
    }
    fclose(f);

    if(todoOk == 1)
    {
        printf("Datos guardados en data.csv exitosamente.\n");
    }
    else
    {
        printf("No se pudo guardar los datos en data.csv.\n");
    }

    system("pause");

    return todoOk;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int 1 si se ejecutó correctamente, 0 si error
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    int cant;
    int tam = ll_len(pArrayListEmployee);
    FILE* f;

    system("cls");

    if(pArrayListEmployee != NULL && path != NULL && tam > 0)
    {
        f = fopen(path, "wb");
        if(f == NULL)
        {
            return todoOk;
        }
        for(int i=0; i<tam; i++)
        {
            cant = fwrite(ll_get(pArrayListEmployee, i), sizeof(Employee), 1, f);

            if (cant < 1)
            {
                return todoOk;
            }
        }
        fclose(f);
        todoOk = 1;
    }

    if(todoOk == 1)
    {
        printf("Datos guardados en data.csv exitosamente.\n");
    }
    else
    {
        printf("No se pudo guardar los datos en data.csv.\n");
    }

    system("pause");

    return todoOk;
}
