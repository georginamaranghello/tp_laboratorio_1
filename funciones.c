#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

/** \brief funcion que realiza la suma
 *
 * \param float numeroUno para el operando A
 * \param float numeroDos para el operando B
 * \return retorna la suma de numeroUno y numeroDos
 *
 */

float suma (float numeroUno, float numeroDos)

{
    float total;
    total = numeroUno + numeroDos;
    return total;
}

/** \brief funcion que realiza la resta
 *
 * \param float numeroUno para el operando A
 * \param float numeroDos para el operando B
 * \return retorna la resta de numeroUno y numeroDos
 *
 */


float resta (float numeroUno, float numeroDos)

{
    float total;
    total = numeroUno - numeroDos;
    return total;
}

/** \brief funcion que realiza la multiplicacion
 *
 * \param float numeroUno para el operando A
 * \param float numeroDos para el operando B
 * \return retorna la multiplicacion de numeroUno y numeroDos
 *
 */


 float multiplicacion (float numeroUno, float numeroDos)
 {

    float total;
    total = numeroUno * numeroDos;
    return total;

 }


 /** \brief funcion que realiza la division
  *
  * \param float numeroUno para el operando A
  * \param float numeroDos para el operando B
  * \return retorna la division de numeroUno y numeroDos
  *
  */


  float division (float numeroUno, float numeroDos)
  {

      while (numeroDos == 0)
      {
        printf("No esta permitido dividir por 0. Reingrese el segundo operando: ");
        scanf("%f", &numeroDos);
      }

    float total;
    total = numeroUno / numeroDos;
    return total;


  }


  /** \brief funcion que realiza el factorial
   *
   * \param float numeroUno para el operando A
   * \return retorna el factorial del operando A
   */

   float factorial(float numeroUno)
   {

       int i;
       float total = 1;

        if(numeroUno!= 0)
        {
            for (i=1; i<=numeroUno; i++)
            {
                total = total *i;
            }
        }

        return total;

   }












