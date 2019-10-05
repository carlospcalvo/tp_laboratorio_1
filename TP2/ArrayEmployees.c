#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "ArrayEmployees.h"

/** \brief Muestra las opciones para el alta, baja y modificacion de empleados,
 *         asi como la posibilidad de pedir informes o salir del programa
 *
 * \return int - (1...5) Opcion elegida por el usuario
 *
 */

int menu()
{
    int option;

    system("cls");
    printf("****** Empleados *******\n\n");
    printf("1-Altas\n");
    printf("2-Modificar\n");
    printf("3-Baja\n");
    printf("4-Informar\n");
    printf("5-Salir\n\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &option);

    return option;
}

/** \brief Inicializa el vector de empleados (le asigna valor 0 a isEmpty)
 *
 * \param vec[] Employee
 * \param length int
 *
 */

void initEmployees(Employee vec[], int length)
{
    for(int i = 0; i < length; i++)
    {
        vec[i].isEmpty = 1;
    }
}

/** \brief Muestra en consola un solo emplado con sus datos correspondientes.
 *
 * \param x Employee
 *
 */

void printEmployee(Employee x)
{
    printf(" %2d   %51s %51s    %8.2f    %2d\n",
           x.id,
           x.name,
           x.lastName,
           x.salary,
           x.sector);
}

/** \brief Muestra en consola el listado de empleados con los datos correspondientes.
 *
 * \param vec[] Employee
 * \param length int
 *
 */

void printEmployees(Employee vec[], int length)
{

    int flag = 0;
    system("cls");

    printf("  ID                                               Nombre                                             Apellido    Salario   Sector\n\n");

    for(int i=0; i < length; i++)
    {
        if( vec[i].isEmpty == 0)
        {
            printEmployee(vec[i]);
            flag = 1;
        }
    }

    if( flag == 0)
    {
        printf("\nNo hay empleados que mostrar\n");
    }

    printf("\n\n");
}

/** \brief Pide los parametros para crear un nuevo empleado.
 *
 * \param vec[] Employee
 * \param length int
 * \param id int
 * \return int - (-1) En caso de error
 *               (0) Si funciona
 *
 */

int newEmployee(Employee vec[], int length, int id)
{
    int check = -1;
    int index;
    char auxStr[100];
    char name[51];
    char lastName[51];
    float salary;
    int sector;

    system("cls");

    printf("*****Alta Empleado*****\n\n");

    index = findFreeSlot(vec, length);
    id = index + id;

    if( index == -1)
    {
        printf("\nSistema completo\n\n");
    }
    else
    {
        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(auxStr);
        while(strlen(auxStr) > 51)
        {
            printf("Error. Nombre demasiado largo, reingrese: ");
            gets(auxStr);
        }
        strcpy(name, auxStr);

        printf("Ingrese apellido: ");
        fflush(stdin);
        gets(auxStr);
        while(strlen(auxStr) > 51)
        {
            printf("Error. Apellido demasiado largo, reingrese: ");
            gets(auxStr);
        }
        strcpy(lastName, auxStr);

        printf("Ingrese salario: ");
        fflush(stdin);
        scanf("%f", &salary);
        while(salary < 1)
        {
            printf("Error. Reingrese: ");
            fflush(stdin);
            scanf("%f", &salary);
        }

        printf("Ingrese sector: ");
        fflush(stdin);
        scanf("%d", &sector);

        vec[index] = addEmployee(id, name, lastName, salary, sector);
        check = 0;
        printf("Alta exitosa!\n\n");
    }

    return check;
}

/** \brief Crea una variable de tipo Employee para asignar al vector de empleados.
 *
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return Employee - Nuevo empleado
 *
 */

Employee addEmployee(int id, char name[], char lastName[], float salary, int sector)
{

    Employee empleado;
    empleado.id = id;
    strcpy( empleado.name, name);
    strcpy( empleado.lastName, lastName);
    empleado.salary = salary;
    empleado.sector = sector;
    empleado.isEmpty = 0;

    return empleado;
}

/** \brief Busca un lugar libre en el vector para asignarle un nuevo empleado.
 *
 * \param vec[] Employee
 * \param length int
 * \return int - (-1) En caso de no haber espacio en el vector
 *               (0...1000) Posicion libre en el vector
 *
 */

int findFreeSlot(Employee vec[], int length)
{
    int index = -1;

    for(int i=0; i < length; i++)
    {
        if( vec[i].isEmpty == 1 )
        {
            index = i;
            break;
        }
    }
    return index;
}

/** \brief Busca la posicion en el array de un empleado en base a su id.
 *
 * \param vec[] Employee
 * \param length int
 * \param id int
 * \return int - posicion del empleado en el array
 *
 */

int findEmployeeById(Employee vec[], int length, int id)
{

    int index = -1;
    for(int i=0; i < length; i++)
    {
        if( vec[i].id == id )
        {
            index = i;
            break;
        }
    }
    return index;
}

/** \brief Permite modificar un empleado indicado por id,
 *         seleccionando en un menu que campo se quiere cambiar.
 *
 * \param vec[] Employee
 * \param length int
 * \return int - (-1) En caso de error
 *               (0) Si funciona
 *
 */

int modifyEmployee(Employee vec[], int length)
{

    int check = -1;
    int id;
    int index;
    char auxStr[100];

    system("cls");

    if(checkEmployees(vec, length))
    {
        printf("***** Modificar empleado *****\n\n");
        printf("---Para salir, presione 0---\n");
        printf("Ingrese id: ");
        scanf("%d", &id);
        int option;

        index = findEmployeeById(vec, length, id);

        if(id == 0)
        {
            printf("\n\n");
        }
        else
        {

            if( index == -1)
            {
                printf("No existe un empleado con ese id.\n\n");

            }
            else
            {
                printf("\n\n  ID                                                Nombre                                            Apellido    Salario   Sector\n\n");
                printEmployee(vec[index]);
                printf("\n\n");
                printf("1- Modificar nombre\n");
                printf("2- Modificar apellido\n");
                printf("3- Modificar salario\n");
                printf("4- Modificar sector\n");
                printf("5- Salir\n\n");
                printf("Ingrese opcion: ");
                scanf("%d", &option);
                switch(option)
                {
                case 1:
                    printf("Ingrese nuevo nombre: ");
                    fflush(stdin);
                    gets(auxStr);
                    while(strlen(auxStr) > 51)
                    {
                        printf("Error. Nombre demasiado largo, reingrese: ");
                        gets(auxStr);
                    }
                    strcpy(vec[index].name, auxStr);
                    check = 0;
                    break;

                case 2:
                    printf("Ingrese nuevo apellido: ");
                    fflush(stdin);
                    gets(auxStr);
                    while(strlen(auxStr) > 51)
                    {
                        printf("Error. Apellido demasiado largo, reingrese: ");
                        gets(auxStr);
                    }
                    strcpy(vec[index].lastName, auxStr);
                    check = 0;
                    break;
                case 3:
                    printf("Ingrese nuevo salario: ");
                    fflush(stdin);
                    scanf("%f", &vec[index].salary);
                    while(vec[index].salary < 1)
                    {
                        printf("Error. Reingrese el salario: ");
                        fflush(stdin);
                        scanf("%f", &vec[index].salary);
                    }
                    check = 0;
                    break;
                case 4:
                    printf("Ingrese nuevo sector: ");
                    scanf("%d", &vec[index].sector);
                    while(vec[index].sector <= 0)
                    {
                        printf("Error. Reingrese el sector: ");
                        fflush(stdin);
                        scanf("%d", &vec[index].sector);
                    }
                    check = 0;
                    break;
                case 5:
                    printf("Se ha cancelado la modificacion.\n");
                    check = 0;
                    break;
                default:
                    printf("Opcion invalida.\n");
                }
            }
        }
    }
    return check;
}

/** \brief Realiza una baja logica al empleado indicado por id.
 *         (isEmpty pasa de 0 a 1).
 *
 * \param vec[] Employee
 * \param length int
 * \return int - (-1) En caso de error
 *               (0) Si funciona
 *
 */

int removeEmployee(Employee vec[], int length)
{
    int check = -1;
    int id;
    int index;
    char confirm;
    system("cls");

    if(checkEmployees(vec, length)==1)
    {
        printf("***** Baja Empleado *****\n\n");
        printf("---Para salir, presione 0---\n");
        printf("Ingrese id: ");
        scanf("%d", &id);

        if(id == 0)
        {
            printf("\n\n");
        }
        else
        {

            index = findEmployeeById(vec, length, id);

            if( index == -1)
            {
                printf("No existe un empleado con ese id\n\n");

            }
            else
            {
                printEmployee(vec[index]);

                printf("\nConfirma la baja? (y/n): ");
                fflush(stdin);
                scanf("%c", &confirm);

                if( confirm == 'y')
                {
                    vec[index].isEmpty = 1;
                    check = 0;
                    printf("Baja exitosa!\n\n");
                }
                else
                {
                    printf("Se ha cancelado la baja.\n\n");
                }
            }
        }
    }
    return check;
}

/** \brief Muestra un menu para seleccionar de que forma se quiere
 *         ordenar el listado de empleados.
 *
 * \param vec[] Employee
 * \param length int
 * \return int - (0) Orden Descendente
 *               (1) Orden Ascendente
 *
 */

int sortMenu(Employee vec[], int length)
{
    int order;

    system("cls");

    if(checkEmployees(vec, length)==1)
    {

        printf("Seleccione un criterio para ordenar: \n\n");
        printf("0- Descendente\n");
        printf("1- Ascendente\n");

        fflush(stdin);
        scanf("%d", &order);

        while(!(order == 0 || order == 1))
        {
            printf("Opcion invalida. Reingrese: ");
            fflush(stdin);
            scanf("%d", &order);
        }

        sortEmployees(vec, length, order);
    }

    return order;
}

/** \brief Ordena por burbujeo los empleados por sector y alfabeticamente,
 *         indicando el parametro order si es de forma ascendiente o
 *         descendiente (en el caso del sector).
 *
 * \param vec[] Employee
 * \param length int
 * \param order int
 * \return int - (-1) En caso de error
 *               (0) Si funciona
 *
 */

int sortEmployees(Employee vec[], int length, int order)
{
    int check = -1;
    Employee auxEmployee;

    if(order == 0)
    {
        for(int i= 0; i < length-1 ; i++)
        {
            for(int j= i+1; j < length; j++)
            {
                if(strcmp(vec[i].lastName, vec[j].lastName) > 0)
                {
                    auxEmployee = vec[i];
                    vec[i] = vec[j];
                    vec[j] = auxEmployee;
                }
                if(vec[i].sector > vec[j].sector)
                {
                    auxEmployee = vec[i];
                    vec[i] = vec[j];
                    vec[j] = auxEmployee;
                }
                check = 0;
            }
        }
        printEmployees(vec, length);
    }
    else if (order == 1)
    {
        for(int i= 0; i < length-1 ; i++)
        {
            for(int j= i+1; j < length; j++)
            {
                if(strcmp(vec[i].lastName, vec[j].lastName) > 0)
                {
                    auxEmployee = vec[i];
                    vec[i] = vec[j];
                    vec[j] = auxEmployee;
                }
                if(vec[i].sector < vec[j].sector)
                {
                    auxEmployee = vec[i];
                    vec[i] = vec[j];
                    vec[j] = auxEmployee;
                }
                check = 0;
            }
        }
        printEmployees(vec, length);
    }

    return check;
}

/** \brief Verifica que haya al menos un empleado dado de alta
 *
 * \param vec[] Employee
 * \param length int
 * \return int - (1) Si hay al menos un empleado cargado en sistema
 *               (0) Si no hay empleados cargados en sistema
 *
 */

int checkEmployees( Employee vec[], int length)
{
    int check = 0;
    int flag = 0;

    for (int i=0; i< length; i++)
    {
        if(vec[i].isEmpty == 0)
        {
            flag = 1;
        }
    }

    if(flag == 0)
    {
        printf("***No hay empleados dados de alta todavia.***\n\n");
    }
    else
    {
        check = 1;
    }
    return check;
}

/** \brief Obtiene la suma de los salarios de todos los empleados.
 *
 * \param vec[] Employee
 * \param length int
 * \return int - suma de los salarios de todos los empleados
 *
 */

float getSalariesTotal( Employee vec[], int length)
{

    float total = 0;

    for (int i=0; i< length; i++)
    {
        if(vec[i].isEmpty == 0)
        {
            total = (float) total + vec[i].salary;
        }
    }
    return total;
}

/** \brief Permite obtener el promedio de los salarios de todos los empleados.
 *
 * \param vec[] Employee
 * \param length int
 * \return float - promedio de los salarios de todos los empleados
 *
 */

float getSalariesAvg(Employee vec[], int length)
{

    float promedio;
    float total;
    int cont = 0;

    for(int i = 0; i<length; i++)
    {
        if(vec[i].isEmpty == 0)
        {
            cont++;
        }
    }

    total = getSalariesTotal(vec, length);
    promedio = (float) total / cont;

    return promedio;
}

/** \brief Permite obtener la cantidad de empleados con un salario mayor al promedio.
 *
 * \param vec[] Employee
 * \param length int
 * \return int - cantidad de empleados con un salario mayor al promedio
 *
 */

int getSalariesOverAvg(Employee vec[], int length)
{

    int cont = 0;
    float promedio = getSalariesAvg(vec, length);

    for(int i = 0; i<length; i++)
    {
        if(vec[i].isEmpty == 0 && vec[i].salary > promedio)
        {
            cont++;
        }
    }
    return cont;
}
