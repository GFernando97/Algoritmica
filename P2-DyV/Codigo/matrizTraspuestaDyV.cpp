
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
int matriz_traspuesta_DyV(int ** m, int d) {

  int ** m1;
  int ** m2;
  int ** m3;
  int ** m4;

  // El problema mínimo es que sea 1x1
  if (d == 1)
  {
    return 0;
  }
  else
  {
    // Creo cuatro matrices
    m1 = new int * [d/2];
    assert(m1);
    m2 = new int * [d/2];
    assert(m2);
    m3 = new int * [d/2];
    assert(m3);
    m4 = new int * [d/2];
    assert(m4);
    for (int i = 0; i < d/2; i++)
    {
      m1[i] = new int[d];
      assert(m1[i]);
      m2[i] = new int[d];
      assert(m2[i]);
      m3[i] = new int[d];
      assert(m3[i]);
      m4[i] = new int[d];
      assert(m4[i]);
    }

    // Divido la matriz original en esas cuatro matrices
    for (int i = 0; i < d/2; i++)
    {
      for (int j = 0; j < d/2; j++)
      {
        // m1 m2
        // m3 m4
        m1[i][j] = m[i][j];
        m2[i][j] = m[i+d/2][j];
        m3[i][j] = m[i][j+d/2];
        m4[i][j] = m[i+d/2][j+d/2];
      }
    }

    // Divide y venceras
    matriz_traspuesta_DyV(m1, d/2);
    matriz_traspuesta_DyV(m2, d/2);
    matriz_traspuesta_DyV(m3, d/2);
    matriz_traspuesta_DyV(m4, d/2);

    // Recompongo la matriz con su transpuesta
    for (int i = 0; i < d/2; i++)
    {
      for (int j = 0; j < d/2; j++)
      {
        // m1 m3
        // m2 m4
        m[i][j] = m1[i][j];
        m[i+d/2][j] = m3[i][j];
        m[i][j+d/2] = m2[i][j];
        m[i+d/2][j+d/2] = m4[i][j];
      }
    }

    // Liberar espacio de
    for (int i = 0; i < d/2; i++) {
      delete [] m1[i];
      delete [] m2[i];
      delete [] m3[i];
      delete [] m4[i];
    }
    delete [] m1;
    delete [] m2;
    delete [] m3;
    delete [] m4;

    return 0;
  } //else
}

// FUNCION GENERAL DE LA MATRIZ
//    De aquí se elige por medio del umbral si utiliza la version fuerza bruta o la version DyV dependiendo de la dimensión.
int matriz_transpuesta(int ** matriz, int d)
{
  int err;
  //if(d>???)
  //{
    //err = matriz_traspuesta_FB(matriz,d);
  //}
  //else
  {
    err = matriz_traspuesta_DyV(matriz,d);
  }

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

  // Muestro la matriz original
/*  for (int i = 0; i < dim; i++)
  {
    for (int j = 0; j < dim; j++)
    {
      cout << matriz[i][j] << " ";
      if (j == dim-1)
        cout << endl;
    }
  }
  cout << endl << endl;
*/

  tantes = clock();

  // Llamada a la función de trasponer
  err = matriz_transpuesta(matriz, dim);

  tdespues = clock();
  tiempo_transcurrido = (double)(tdespues-tantes) / CLOCKS_PER_SEC;

  // Muestro la matriz traspuesta
/*  for (int i = 0; i < dim; i++)
  {
    for (int j = 0; j < dim; j++)
    {
      cout << matriz[i][j] << " ";
      if (j == dim-1)
        cout << endl;
    }
  }

  cout << endl << endl;
*/
  cout << dim << "\t" << tiempo_transcurrido << endl;

  //Liberar memoria de la matriz
  for (int i = 0; i < dim; i++)
    delete [] matriz[i];

  delete [] matriz;
}
