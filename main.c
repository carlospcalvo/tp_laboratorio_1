#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/* PREGUNTAR:
1- Comentarios
2- Default no ejecuta cuando se elige una opcion correcta
3- Biblioteca de funciones
*/

int menu();
int suma ();
int resta();
int multiplicar();
int factorial();
float dividir();
char finalizar();

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

    do{

        printf("\nIngrese el primer operando: A=");
        fflush(stdin);
        scanf("%d",&num1);
        printf("Ingrese el segundo operando: B=");
        fflush(stdin);
        scanf("%d",&num2);

        menu();
        printf("\nSeleccione una opcion: ");
        fflush(stdin);
        opcion = getche();


        switch(opcion){
            case 'a':
                suma(num1, num2);
                salir = finalizar();
                break;
            case 'b':
                resta(num1, num2);
                salir = finalizar();
                break;
            case 'c':
                dividir(num1, num2);
                salir = finalizar();
                break;
            case 'd':
                multiplicar(num1, num2);
                salir = finalizar();
                break;
            case 'e':
                factorial(num1, num2);
                salir = finalizar();
                break;
            case 'f':
                printf("\nSeguro? (y/n)\n");
                fflush(stdin);
                salir = getchar();
                break;
            default:
                while(!(opcion == 'a' || opcion == 'b' || opcion == 'c' || opcion == 'd' || opcion == 'e' || opcion == 'f')){
                    printf("\n Error. Ingrese una opcion nuevamente.\n");
                    fflush(stdin);
                    opcion = getche();
                }
                break;
        }
    }while(!(salir == 'y'));



    return 0;
}

/** \brief Funcion Menu --- Permite visualizar el menu de opciones en la consola
 *
 * \param
 * \param
 * \return Menu de opciones
 *
 */

int menu(){

    printf("\n-----Menu de opciones-----\n\n");
    printf("a) Sumar \n");
    printf("b) Restar \n");
    printf("c) Dividir \n");
    printf("d) Multiplicar \n");
    printf("e) Factorial \n");
    printf("f) Salir \n");

    return 0;
}

/** \brief Funcion Suma --- Permite sumar los numeros ingresados
 *
 * \param num1 (main) --- Numero A
 * \param num2 (main) --- Numero B
 * \return Suma --- A+B
 *
 */

int suma(int a, int b){
    int resultado;
    resultado = a + b;
    printf("\n\nEl resultado de A+B es %d \n", resultado);
    return 0;
}

/** \brief Funcion Resta --- Permite restar los numeros ingresados
 *
 * \param num1 (main) --- Numero A
 * \param num2 (main) --- Numero B
 * \return Suma --- A-B
 *
 */

int resta(int a, int b){
    int resultado;
    resultado = a - b;
    printf("\n\nEl resultado de A-B es %d \n", resultado);
    return 0;
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
    if (b != 0)
    {
        resultado = (float) a / b;
        printf("\n\nEl resultado de A/B es %.2f \n", resultado);
    }
    else
    {
        printf("\n No es posible dividir por cero\n");
    }
    return 0;
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
    printf("\n\nEl resultado de A*B es %d \n", resultado);
    return 0;
}

/** \brief Funcion Factorizar --- Permite factorizar los numeros ingresados
 *
 * \param num1 (main) --- Numero A
 * \param num2 (main) --- Numero B
 * \return Factorizacion --- A!, B!
 *
 */

int factorial(int a, int b){
    int resultadoA=1;
    int resultadoB=1;

    for(int c = 1; c <= a; c++){
        resultadoA = resultadoA * c;
    }
    for(int c = 1; c <= b; c++){
        resultadoB = resultadoB * c;
    }
    printf("\n\nEl factorial de A es: %d y el factorial de B es: %d\n", resultadoA, resultadoB);
    return 0;
}

char finalizar(){
    char salir;
    printf("\nDesea salir? (y/n)\n");
    fflush(stdin);
    salir = getchar();
    return salir;
}
