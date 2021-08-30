#include <stdio.h>

int main()
{
   int numero, contador, suma;

   printf( "Introduzca un numero entero: " );
   scanf( "%d", &numero );

   contador = 0;
   suma = 0;

   while ( numero != 0 )
   {
      if ( numero > 0 )
      {
         contador++;
         suma += numero;
      }

      printf( "Introduzca un numero entero: " );
      scanf( "%d", &numero );
   }

   printf( "Ha introducido %d numero(s) mayor(es) que cero.",
           contador );
   printf( "\nLa suma es %d", suma );

   return 0;
}