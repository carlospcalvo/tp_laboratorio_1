#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "calvo.h"

/** \brief Funcion Menu --- Permite visualizar el menu de opciones en la consola
 *
 * \param
 * \param
 * \return Menu de opciones
 *
 */

int menu(int num1, int num2, int flag1, int flag2){

    printf("\n\n----------------Menu de opciones----------------\n\n");
    if (flag1 == 0){
        printf("\na)Ingrese el primer operando: (A=x)");
    }
    else{
        printf("\na)Ingrese el primer operando: (A=%d)", num1);
    }
    if (flag2 == 0){
        printf("\nb)Ingrese el segundo operando: (B=y)");
    }
    else{
        printf("\nb)Ingrese el segundo operando: (B=%d)", num2);
    }
    printf("\nc)Calcular las operaciones e informar resultados" );
    printf("\nd)Salir \n");

    return 0;
}

/** \brief Funcion Suma --- Permite sumar los numeros ingresados
 *
 * \param num1 (main) --- Numero A
 * \param num2 (main) --- Numero B
 * \return Suma --- A+B
 *
 */

int sumar(int a, int b){

    int resultado;

    resultado = a + b;

    return resultado;
}

/** \brief Funcion Resta --- Permite restar los numeros ingresados
 *
 * \param num1 (main) --- Numero A
 * \param num2 (main) --- Numero B
 * \return Suma --- A-B
 *
 */

int restar(int a, int b){

    int resultado;

    resultado = a - b;

    return resultado;
}

/** \brief Funcion Dividir --- Permite dividir los numeros ingresados
 *
 * \param num1 (main) --- Numero A
 * \param num2 (main) --- Numero B
 * \return Division --- A/B
 *
 */

float dividir(int a, int b){

    float resultado;

    if (b != 0){
        resultado = (float) a / b;
    }

    return resultado;
}

/** \brief Funcion Multiplicar --- Permite multiplicar los numeros ingresados
 *
 * \param num1 (main) --- Numero A
 * \param num2 (main) --- Numero B
 * \return Multiplicacion --- A*B
 *
 */

int multiplicar(int a, int b){

    int resultado;

    resultado = a * b;

    return resultado;
}

/** \brief Funcion Factorial --- Permite factorizar los numeros ingresados
 *
 * \param num1 (main) --- Numero A
 * \param num2 (main) --- Numero B
 * \return Factorizacion --- A!, B!
 *
 */

int factorial(int a){

    int factorial=1;

    for(int i = 1; i <= a; i++){

        factorial = factorial * i;

    }

    return factorial;
}
/** \brief Funcion Finalizar -- Permite elegir si se quiere continuar o salir del programa
 *
 * \param
 * \param
 * \return
 *
 */

char finalizar(){

    char salir;

    printf("\nDesea salir? (y/n): ");
    fflush(stdin);
    salir = getche();
    while(!(salir == 'n' || salir == 'y')){
        printf("\nPresione 'y' si desea salir, si desea continuar presione 'n': ");
        fflush(stdin);
        salir = getche();
    }

    return salir;
}
