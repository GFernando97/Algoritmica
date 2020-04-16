/*ES:   Asignatura: Algoritmica
        Practica 3 - Greedy
        TSP con método de Inserción
        Autor: Valentino Lugli */ 

//  LIBRERIAS
//      Entrada/Salida
#include <iostream>
//      Abrir archivos
#include <fstream>
//      
#include <string>
#include <sstream>


using namespace std;

// CLASES

// FUNCIONES
void entrada()
{

}

void tspInsercion(float **&matrizIN, float **&matrizOUT, int dim)
{
    cout << "dim="<<dim<<endl;
    delete [] matrizIN [1];
    for (int i = 0; i < dim; i++)
    {
        cout << matrizIN[i][0]<<endl;
    }
}

int main(int argc, char * argv[])
{

    if (argc != 2)
    {
      cerr << "Formato: ./" << argv[0] << " <rutaArchivo.tsp>" << endl;
      return -1;
    }

    float **matriz,**matrizOUT;
    int dim;
    string linea = "";
    istringstream aux2;
    ifstream archivo (argv[1]);

    if (archivo.is_open())
    {
        int aux;
        while (linea.compare("NODE_COORD_SECTION") != 0)
        {
            getline(archivo,linea);
            aux = linea.find("DIMENSION");
            if(aux != -1)
            {
                aux = linea.find(":");
                aux2.str(linea.substr(aux+1,-1));
                aux2 >> dim;
            }
        }
        matriz = new float*[dim];
        matrizOUT = new float*[dim];
        float a,b,c;
        for(int i=0; i<dim; i++)
        {
            archivo >> a >> b >> c;
            matriz[i] = new float[3];
            matriz[i][0] =a;
            matriz[i][1] =b;
            matriz[i][2] =c;
            //cout << matriz[i][0] << " "<<matriz[i][1]<<" "<<matriz[i][2]<<endl;
            matrizOUT[i] = new float[1];
            matrizOUT[i] = 0;
        }
        archivo.close();
    }

    else cout << "No se puede abrir el archivo."; 


      for(int i=0; i<dim; i++)
        {
            cout << matriz[i][0] << " "<<matriz[i][1]<<" "<<matriz[i][2]<<endl;
        }


    tspInsercion(matriz,matrizOUT,dim);

// Eliminar la matriz.
 for (int i = 0; i < dim; i++)
 {
    delete [] matriz[i];
    delete [] matrizOUT[i];
 }

  delete [] matriz;
  delete [] matrizOUT;
}