//Programa que muestra la matriz traspuesta de una dada por entrada estandar
//Este programa se ha compilado con la orden g++ -o matrizTraspuestaFB matrizTraspuestaFB.cpp 


#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;


//Funcion que devuelve la traspuesta de una matriz dinamica dada
int **trasponer(int **m, int dim){
    //Reserva de la matriz traspuesta
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
    if(argc != 2){
        cout << "El programa solo recibe un parametro\n";
        return 1;
    }
    clock_t tantes, tdespues;
    int util = atoi(argv[1]);
    //Reserva de la matriz dinamica
    int **matriz = new  int*[util];
    for(int i=0; i<util; i++ ){
        matriz[i] = new int [util];
    }
    srand(time(NULL));
    //Rellenamos la matriz con numeros aleatorios
    for(int i=0; i<util; i++){
        for(int j=0; j<util; j++){
            matriz[i][j]=random();
        }
    }

    tantes=clock();
    matriz=trasponer(matriz, util);
    tdespues=clock();

    cout << util << "\t" << (double)(tdespues-tantes) / CLOCKS_PER_SEC << endl;

    //Liberar memoria de la matriz
    for (int i = 0; i < util; i++)
        delete [] matriz[i];

    delete [] matriz;
}