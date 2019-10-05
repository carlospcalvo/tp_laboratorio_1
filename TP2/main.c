#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "ArrayEmployees.h"

#define LENGTH 1000

/** \brief Permite al usuario dar de alta un empleado, de baja un empleado,
 *         modificar un empleado, solicitar informes o salir del programa.
 *
 * \return int (0) En caso de funcionar.
 *
 */


int main()
{
    Employee list[LENGTH];
    char salir = 'n';
    int id = 1;

    initEmployees(list, LENGTH);

    do
    {
        switch(menu())
        {
        case 1:
            newEmployee(list, LENGTH, id);
            break;
        case 2:
            modifyEmployee(list, LENGTH);
            break;
        case 3:
            removeEmployee(list, LENGTH);
            break;
        case 4:
            sortMenu(list, LENGTH);
            printf("\nSuma de los salarios: %8.2f \n", getSalariesTotal(list, LENGTH));
            printf("Promedio de los salarios: %8.2f \n", getSalariesAvg(list, LENGTH));
            printf("Empleados con salario mayor al promedio: %d \n\n", getSalariesOverAvg(list, LENGTH));
            break;
        case 5:
            printf("Confirma salir? (y/n): ");
            fflush(stdin);
            salir = getche();
            printf("\n\n");
            break;
        default:
            printf("Opcion invalida. Reingrese.\n");
        }
        system("pause");
    }
    while (salir == 'n');
    return 0;
}
