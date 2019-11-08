#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int 1 si se ejecutó correctamente, 0 si error
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    char buffer[4][30];
    int cant;
    Employee* auxEmpleado = NULL;

    if( pFile != NULL && pArrayListEmployee != NULL)
    {
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);

        while( !feof(pFile))
        {
            cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
            if( cant == 4)
            {
                auxEmpleado = employee_newParametros(buffer[0], buffer[1], buffer[2], buffer[3]);

                if(auxEmpleado != NULL)
                {
                    ll_add(pArrayListEmployee, auxEmpleado);
                    todoOk = 1;
                }
            }
            else
            {
                break;
            }
        }
    }

    return todoOk;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int 1 si se ejecutó correctamente, 0 si error
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    int cant;
    Employee* auxEmpleado = NULL;

    if( pFile != NULL && pArrayListEmployee != NULL)
    {
        while( !feof(pFile))
        {
            auxEmpleado = employee_new();
            if( auxEmpleado != NULL)
            {
                cant = fread(auxEmpleado, sizeof(Employee), 1, pFile);
                if(cant == 1)
                {
                    ll_add(pArrayListEmployee, auxEmpleado);
                    todoOk = 1;
                }
                else
                {
                    break;
                }
            }
        }
    }

    return todoOk;
}
