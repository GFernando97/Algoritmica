//Programa que muestra la matriz traspuesta de una dada por entrada estandar
//Este programa se ha compilado con la orden g++ -o matrizTraspuestaFB matrizTraspuestaFB.cpp 


#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main(int argc, char**argv){

    if(argc !=2){
        cout << "El programa recibe solo un argumento como paramentro \n";
        return 1;
    }

    const int TOPE=1000; //Numero de elementos que vamos a reservar para cada dimension de la matriz (la suponemos estatica)
	int numeros[TOPE][TOPE];
    int util=atoi(argv[1]); //Numero de filas y columnas que queremos para la matriz (Es cuadrada)
    
	
	for(int i=0;i<util;i++){
		for(int j=0;j<util;j++){
			numeros[i][j]=random();
		}
	}
	
	cout<<"\nMatriz Normal\n"; //Mostrar la matriz
	for(int i=0;i<util;i++){
		for(int j=0;j<util;j++){
			cout<<numeros[i][j]<<" ";
		}
		cout<<"\n";
	}
	
	cout<<"\nMatriz Transpuesta\n"; //Mostrar la traspuesta
	for(int i=0;i<util;i++){
		for(int j=0;j<util;j++){
			cout<<numeros[j][i]<<" ";
		}
		cout<<"\n";
	}
}