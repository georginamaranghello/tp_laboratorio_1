#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
    float numeroUno;
    float numeroDos;
    int flagA = 0;
    int flagB = 0;
    float resultado;

    while(seguir=='s')
    {
        printf("\n1- Ingresar 1er operando (A=x)\n");
        printf("2- Ingresar 2do operando (B=y)\n");
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:

                system("cls");
                printf("Ingrese el primer numero: ");
                scanf("%f", &numeroUno);
                seguir = 's';
                flagA = 1;
                break;

            case 2:
                system("cls");
                printf("Ingrese el segundo numero: ");
                scanf("%f", &numeroDos);
                seguir = 's';
                flagB = 1;
                break;

            case 3:

                if (flagA == 1 && flagB == 1)
                {
                    resultado = suma(numeroUno, numeroDos);
                    printf("\nla suma de %.2f + %.2f = %.2f \n", numeroUno, numeroDos, resultado);

                }

                else
                {

                    printf("Para realizar la suma primero debe cargar los dos operandos.");

                }
                break;

            case 4:

                 if (flagA == 1 && flagB == 1)
                {
                    resultado = resta(numeroUno, numeroDos);
                    printf("\nla resta de %.2f - %.2f = %.2f \n", numeroUno, numeroDos, resultado);

                }

                else
                {

                    printf("Para realizar la resta primero debe cargar los dos operandos.");

                }
                break;

            case 5:

                 if (flagA == 1 && flagB == 1)
                {
                    resultado = division(numeroUno, numeroDos);
                    printf("\nla division de %.2f / %.2f = %.2f", numeroUno, numeroDos, resultado);

                }

                else
                {

                    printf("Para realizar la division primero debe cargar los dos operandos.");

                }

                break;

            case 6:

                 if (flagA == 1 && flagB == 1)
                {
                    resultado = multiplicacion(numeroUno, numeroDos);
                    printf("\nla multiplicacion de %.2f * %.2f = %.2f", numeroUno, numeroDos, resultado);

                }

                else
                {

                    printf("Para realizar la multiplicacion primero debe cargar los dos operandos.");

                }

                break;


            case 7:

                if (flagA==1)
                {
                    resultado = factorial(numeroUno);
                    printf("\nEl factorial de %.2f = %.2f ", numeroUno, resultado);
                }

                else
                {

                    printf("Para realizar la operacion primero debe el operando A.");

                }
                break;

            case 8:


                 if (flagA == 1 && flagB == 1)

                 {


                    printf("La suma es: %.2f\n", suma(numeroUno, numeroDos));
                    printf("\nLa resta es: %.2f\n", resta(numeroUno, numeroDos));
                    printf("\nLa division da: %.2f\n", division(numeroUno, numeroDos));
                    printf("\nLa multiplicacion da: %.2f\n", multiplicacion(numeroUno, numeroDos));
                    printf("\nEl factorial del primer operando es: %.2f\n", factorial(numeroUno));

                 }

                else
                {

                    printf("\nPara realizar la operacion primero debe el operando A.");

                }


                break;


            case 9:

                seguir = 'n';

                break;
        }



}

 return 0;
}
