//Programa que muestra la matriz traspuesta de una dada por entrada estandar
//Este programa se ha compilado con la orden g++ -o matrizTraspuestaFB matrizTraspuestaFB.cpp 


#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;


//Funcion que devuelve la traspuesta de una matriz dinamica dada
int **trasponer(int **m, int dim){
    //Reserva de espacio para la matriz traspuesta
    int **mt = new int*[dim];
    for(int i=0; i<dim; i++ ){
        mt[i] = new int [dim];
    }
    //Bucles que trasponen la matriz dada
    for(int i=0; i<dim; i++){
        for(int j=0; j<dim; j++){
            mt[i][j]=m[j][i];
        }
    }
    return mt;
}

int main(int argc, char ** argv){

    int util = atoi(argv[1]);

    if(argc != 2){
        cout << "El programa solo recibe un parametro\n";
        return 1;
    }

    if (!(util & (util - 1)) == 0)
    {
      cout << "Numero no es potencia de dos. Fin\n"<<endl;
      return 1;
    }
    
    clock_t tantes, tdespues;
    //Reserva de espacio para la matriz dinamica
    int **matriz = new  int*[util];
    for(int i=0; i<util; i++ ){
        matriz[i] = new int [util];
    }
    srand(time(NULL));
    //Rellenamos la matriz con numeros aleatorios
    for(int i=0; i<util; i++){
        for(int j=0; j<util; j++){
            matriz[i][j]=random() % 10;
        }
    }


/*  for (int i = 0; i < util; i++)
  {
    for (int j = 0; j < util; j++)
    {
      cout << matriz[i][j] << " ";
      if (j == util-1)
        cout << endl;
    }
  }
  cout << endl << endl;
*/


    tantes=clock();
    matriz=trasponer(matriz, util);
    tdespues=clock();

    cout << util << "\t" << (double)(tdespues-tantes) / CLOCKS_PER_SEC << endl;

    //Liberar memoria de la matriz


/* for (int i = 0; i < util; i++)
  {
    for (int j = 0; j < util; j++)
    {
      cout << matriz[i][j] << " ";
      if (j == util-1)
        cout << endl;
    }
  }
  cout << endl << endl;
*/


    for (int i = 0; i < util; i++)
        delete [] matriz[i];

    delete [] matriz;
}
