#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"



float suma (float numeroUno, float numeroDos)

{
    float total;
    total = numeroUno + numeroDos;
    return total;
}




float resta (float numeroUno, float numeroDos)

{
    float total;
    total = numeroUno - numeroDos;
    return total;
}


 float multiplicacion (float numeroUno, float numeroDos)
 {

    float total;
    total = numeroUno * numeroDos;
    return total;

 }





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












