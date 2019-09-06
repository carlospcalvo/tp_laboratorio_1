/*****************************************************************************************
*Programa: Trabajo Practico 1
*
*Objetivo: Ingresar 2 numeros, realizar las siguientes operaciones e imprimirlas:
                        a)Sumar
                        b)Restar
                        c)Dividir
                        d)Multiplicar
                        e)Factorizar
*
*Version: 0.1 - 06/09/2019
*Autor: Carlos Pedro Calvo Nazabal
*
******************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "calvo.h"


/** \brief Funcion Main --- Permite elegir calcular la suma, resta, division, multiplicacion o factorizacion de dos numeros.
 *
 * \param num1 --- Numero A
 * \param num2 --- Numero B
 * \return Resultado de la operacion elegida
 *
 */


int main(){
    char opcion;
    char salir;
    int num1;
    int num2;
    int flag1 = 0;
    int flag2 = 0;

    do{
        menu(num1, num2, flag1, flag2);
        printf("\n\nSeleccione una opcion: ");
        fflush(stdin);
        opcion = getche();
        switch(opcion){
            case 'a':
                printf("\nIngrese el primer operando: ");
                fflush(stdin);
                scanf("%d",&num1);
                flag1 = 1;
                break;
            case 'b':
                printf("\nIngrese el segundo operando: ");
                fflush(stdin);
                scanf("%d",&num2);
                flag2 = 1;
                break;
            case 'c':
                if(flag1 != 1 || flag2 != 1){
                    printf("\n\nNo ha ingresado dos numeros.");
                    fflush(stdin);
                    break;
                }
                else{
                    printf("\n\nEl resultado de A+B es %d \n", sumar(num1, num2));
                    printf("\n\nEl resultado de A-B es %d \n", restar(num1, num2));
                    if (num2 == 0){
                        printf("\n\nNo es posible dividir por cero\n");
                    }
                    else{
                        printf("\n\nEl resultado de A/B es %.2f \n", dividir(num1,num2));
                    }
                    printf("\n\nEl resultado de A*B es %d \n", multiplicar(num1, num2));
                    if (num1 >= 1){
                        printf("\n\nEl factorial de A es: %d", factorial(num1));
                    }
                    else{
                        printf("\n\nEl factorial de A no existe.");
                    }
                    if(num2 >= 1){
                        printf(" y el factorial de B es: %d\n\n", factorial(num2));
                    }
                    else{
                        printf(" y el factorial de B no existe.\n");
                    }
                }
                salir = finalizar();
                if(salir == 'n'){
                    flag1--;
                    flag2--;
                }
                break;
            case 'd':
                printf("\nSeguro? (y/n): ");
                fflush(stdin);
                salir = getchar();
                break;
            default:
                printf("\nError. Ingrese una opcion nuevamente.\n");
                break;
        }
    }while(!(salir == 'y'));
    return 0;
}
