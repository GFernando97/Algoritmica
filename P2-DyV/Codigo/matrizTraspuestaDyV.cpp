
#include <iostream>
using namespace std;
#include <ctime>
#include <cstdlib>
#include <climits>
#include <cassert>

// VERSION FB
void matriz_traspuesta_FB()
{

}

// VERSION DYV
int mtdyv (int **m, int ci, int cf, int fi, int ff) {

  int aux, d;

  d = cf - ci + 1;

  // Caso base matriz 2x2
  if (d == 2) {

    aux = m[cf][fi];
    m[cf][fi] = m[ci][ff];
    m[ci][ff] = aux;
  }
  else {

    // Divido la matriz en en cuatro matrices
    // m1 m2
    // m3 m4
    mtdyv(m, ci, ci+d/2-1, fi, fi+d/2-1);
    mtdyv(m, ci+d/2, cf, fi, fi+d/2-1);
    mtdyv(m, ci, ci+d/2-1, fi+d/2, ff);
    mtdyv(m, ci+d/2, cf, fi+d/2, ff);

    // Inetrcambio posiciones
    // m1 m3
    // m2 m4
    for (int i = 0; i < d/2; i++) {
      for (int j = 0; j < d/2; j++) {
        aux = m[ci+d/2+i][fi+j];
        m[ci+d/2+i][fi+j] = m[ci+i][fi+d/2+j];
        m[ci+i][fi+d/2+j] = aux;
      }
    }
  } //else

  return 0;
}

// FUNCION GENERAL DE LA MATRIZ
//    De aquí se elige por medio del umbral si utiliza la version fuerza bruta o la version DyV dependiendo de la dimensión.
int matriz_transpuesta(int ** matriz, int d)
{
  int err;


  return err;
}

int main(int argc, char **argv) {

  int dim, err;
  int **matriz;
  clock_t tantes, tdespues;
  long double tiempo_transcurrido;

  err = 0;

  // Lectura de los parametros de entrada
  if (argc != 2)
  {
    cout << "Parametros de entrada: " << endl
    << "1.- Dimension de la matriz" << endl << endl;
    return 1;
  }

  srand(time(0));

  // Creación de la matriz
  dim = atoi(argv[1]);
  matriz = new int*[dim];
  assert(matriz);
  for (int i = 0; i < dim; i++)
  {
    matriz[i] = new int[dim];
    assert(matriz[i]);
  }

  // Rellenar matriz de elementos aleatorios
  for (int i = 0; i < dim; i++)
  {
    for (int j = 0; j < dim; j++)
    {
      matriz[i][j] = rand() % 10;
    }
  }

  tantes = clock();

  // Llamada a la función de trasponer
  err = mtdyv(matriz, 0, dim-1, 0, dim-1);

  tdespues = clock();

  tiempo_transcurrido = (double)(tdespues-tantes) / CLOCKS_PER_SEC;

  cout << dim << "\t" << tiempo_transcurrido << endl;

  //Liberar memoria de la matriz
  for (int i = 0; i < dim; i++)
    delete [] matriz[i];

  delete [] matriz;
}
