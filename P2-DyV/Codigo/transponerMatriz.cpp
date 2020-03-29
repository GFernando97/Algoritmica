//  ALGORITMICA
//    PRACTICA 2 
//    Transponer una matriz de dimensión n=2^k por medio de Divide y Vencerás.

// LIBRERIAS
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <climits>
#include <cassert>

using namespace std;

// FUNCIONES

//  Función Main
int main(int argc, char **argv)
{
  int dim, err;
  int **matriz;
  clock_t tantes, tdespues;
  long double tiempo_transcurrido;

  if (!(dim & (dim - 1)) == 0)
  {
    cout << "Error: número no es potencia de dos\n"<<endl;
    return 1;
  }

}