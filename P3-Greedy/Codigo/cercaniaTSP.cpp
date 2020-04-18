/*ES:   Asignatura: Algoritmica
        Practica 3 - Greedy
        TSP con método de Cercanía */ 

//  LIBRERIAS
//      Entrada/Salida
#include <iostream>
//      Abrir archivos
#include <fstream>
//      Procesado de Cadenas
#include <string>
#include <sstream>
//      Hacer operaciones matematicas
#include <cmath>
//      Obtener el MAX_FLT
#include <cfloat>

using namespace std;

// CLASES

// FUNCIONES
void entrada()
{

}

void tspCercania(float **&matrizIN, float **&matrizOUT, int dim)
{
    float nodoInicio,nodoFin,nodoVecino,distActual,distanciaMin;
    float caminoMin = 0;
    nodoInicio = 0;
    nodoFin = nodoInicio;

    matrizOUT[0][0] = matrizIN[(int)nodoInicio][0];
    matrizOUT[0][1] = matrizIN[(int)nodoInicio][1];
    matrizOUT[0][2] = matrizIN[(int)nodoInicio][2];

    matrizIN[(int)nodoInicio][0] = -1;

    for (int i = 0; i < dim-1; i++)
    {  
   //     cout <<"iteracion= "<<i<<endl;
        distanciaMin = FLT_MAX;
        for (int j = 0; j < dim; j++)
        {
            distActual = round((sqrt(pow(matrizIN[j][1]-matrizIN[(int)nodoInicio][1],2)+pow(matrizIN[j][2]-matrizIN[(int)nodoInicio][2],2))));
  //          cout<<"dAct:"<<nodoInicio+1<<" - "<<j+1<<": "<<distActual<<endl;
            if (matrizIN[j][0] >= 0 &&  distActual <= distanciaMin)
            {
                distanciaMin = distActual;
                nodoVecino = j;
   //             cout <<"nodo=" <<j+1<<" distanciaMin= "<<distanciaMin<<endl;
            }
        }
        caminoMin = caminoMin + distanciaMin;
        matrizOUT[i+1][0] = matrizIN[(int)nodoVecino][0];
        matrizOUT[i+1][1] = matrizIN[(int)nodoVecino][1];
        matrizOUT[i+1][2] = matrizIN[(int)nodoVecino][2];
   //     cout<<"i+1="<<i+1<<endl;
        matrizIN[(int)nodoVecino][0] = -1;

    //    cout<<"dMin:"<<nodoInicio<<" - "<<nodoVecino<<": "<<distanciaMin<<endl<<"--------"<<endl;;

        nodoInicio = nodoVecino;
    /*    cout<<"FIN ITERACION "<<i<<endl<<"ENTRADA: "<<endl;
        for (int i = 0; i < dim; i++)
        {
            cout <<"Nodo: "<<matrizIN[i][0]<<" x=" <<matrizIN[i][1]<<" y="<<matrizIN[i][2]<<endl;
        }
        cout<<"SALIDA: "<<endl;
        for (int i = 0; i < dim; i++)
        {
            cout <<"Nodo: "<<matrizOUT[i][0]<<" x=" <<matrizOUT[i][1]<<" y="<<matrizOUT[i][2]<<endl;
        }
        cout <<"Camino Min: "<<caminoMin<<endl;*/
    }

        cout <<caminoMin<<endl;
        for (int i = 0; i < dim; i++)
        {
            cout <<matrizOUT[i][0]<<" " <<matrizOUT[i][1]<<" "<<matrizOUT[i][2]<<endl;
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
        matrizOUT = new float*[dim+2];
        float a,b,c;
        for(int i=0; i<dim; i++)
        {
            archivo >> a >> b >> c;
            matriz[i] = new float[3];
            matriz[i][0] =a;
            matriz[i][1] =b;
            matriz[i][2] =c;
            //cout << matriz[i][0] << " "<<matriz[i][1]<<" "<<matriz[i][2]<<endl;
            matrizOUT[i] = new float[3];
            matrizOUT[i][0] = 0;
            matrizOUT[i][1] = 0;
            matrizOUT[i][2] = 0;
            
        }
        archivo.close();
    }

    else cout << "No se puede abrir el archivo."; 


  /*    for(int i=0; i<dim; i++)
        {
            cout << matriz[i][0] << " "<<matriz[i][1]<<" "<<matriz[i][2]<<endl;
        }
*/

    tspCercania(matriz,matrizOUT,dim);

// Eliminar la matriz.
 for (int i = 0; i < dim; i++)
 {
    delete [] matriz[i];
    delete [] matrizOUT[i];
 }

  delete [] matriz;
  delete [] matrizOUT;
}
