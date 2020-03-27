//Programa que muestra la matriz traspuesta de una dada por entrada estandar
//Este programa se ha compilado con la orden g++ -o matrizTraspuestaFB matrizTraspuestaFB.cpp 


#include<iostream>
using namespace std;

int main(){
    const int TOPE=1000; //Numero de elementos que vamos a reservar para cada dimension de la matriz (la suponemos estatica)
	int numeros[TOPE][TOPE];
    int util; //Numero de filas y columnas que queremos para la matriz (Es cuadrada)
    cin >> util;
	
	for(int i=0;i<util;i++){ //Introducir datos a la matriz
		for(int j=0;j<util;j++){
			cout<<"numeros["<<i<<"]["<<j<<"]: ";
			cin>>numeros[i][j];
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