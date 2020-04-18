/*ES:   Asignatura: Algoritmica
        Trabajo: Practica 3 - Greedy
        Descripción: Procesar archivo opt.tour para hacerlo visualizable con gnuplot
		*/ 



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


int main(int argc, char * argv[])
{

    if (argc != 3)
    {
      cerr << "Formato: ./" << argv[0] << " <rutaArchivo.tsp>" << " <rutaArchivo.opt.tour"<< endl;
      return -1;
    }

    float **matrizTSP,**matrizOPT;
    int dim;
    string lineaTSP = "";
	string lineaOPT = "";
    istringstream aux2;
    ifstream archivoTSP (argv[1]);
	ifstream archivoOPT (argv[2]);

    if (archivoTSP.is_open() && archivoOPT.is_open())
    {
        int aux;
        while (lineaTSP.compare("NODE_COORD_SECTION") != 0)
        {
            getline(archivoTSP,lineaTSP);
            aux = lineaTSP.find("DIMENSION");
            if(aux != -1)
            {
                aux = lineaTSP.find(":");
                aux2.str(lineaTSP.substr(aux+1,-1));
                aux2 >> dim;
            }
        }
		
      	while (lineaOPT.compare("TOUR_SECTION") != 0)
        {
            getline(archivoOPT,lineaOPT);
        }

        matrizTSP = new float*[dim];
        matrizOPT = new float*[dim];
        float a,b,c,d;
        for(int i=0; i<dim; i++)
        {
            archivoTSP >> a >> b >> c;
			archivoOPT >> d;
            matrizTSP[i] = new float[3];
            matrizTSP[i][0] =a;
            matrizTSP[i][1] =b;
            matrizTSP[i][2] =c;
            
            matrizOPT[i] = new float[1];
            matrizOPT[i][0] = d; 
       //     cout << matrizTSP[i][0] << " "<<matrizTSP[i][1]<<" "<<matrizTSP[i][2]<<" "<<matrizOPT[i][0]<<endl;
        }
        archivoTSP.close();
		archivoOPT.close();
    }
    else cout << "No se puede abrir el archivo."; 

	float target;

	for (int i = 0; i < dim; i++)
	{
		target = matrizOPT[i][0];
		for (int j = 0; j < dim; j++)
		{
			if (target == matrizTSP[j][0])
			{
				cout << matrizTSP[j][0] <<" "<<matrizTSP[j][1]<<" "<<matrizTSP[j][2]<<endl;
			}
		}
	}
	cout << matrizTSP[0][0] <<" "<<matrizTSP[0][1]<<" "<<matrizTSP[0][2]<<endl;

// Eliminar la matriz.
 for (int i = 0; i < dim; i++)
 {
    delete [] matrizTSP[i];
    delete [] matrizOPT[i];
 }

  delete [] matrizTSP;
  delete [] matrizOPT;
}