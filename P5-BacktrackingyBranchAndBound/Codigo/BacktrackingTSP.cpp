// LIBRERIAS
//      Entrada/Salida
#include <iostream>
//      Vectores
#include <vector>
//      Abrir archivos
#include <fstream>
//      Procesado de Cadenas
#include <string>
#include <sstream>
//      Hacer operaciones matematicas
#include <cmath>
//      Obtener el MAX_INT
#include <climits>

using namespace std;

struct nodo
{
    int indice;
    double x;
    double y;
};

//  FUNCIONES
//      Funcion auxiliar para calcular distancia euclidea entre dos puntos.
int calcularDistancia(double x2, double x1, double y2, double y1)
{
    return  (int)round( ( sqrt( pow(x2 - x1, 2) + pow(y2 - y1, 2) ) ) ) ;
}

void TSPBactraking(nodo ciudAct, vector<nodo> &ciudades, vector<nodo> &tour)
{

    while (!ciudades.empty())
    {
        
    }
}

int main(int argc, char * argv[])
{
        // Verificacion de que está el archivo de entrada
    if (argc != 2)
    {
      cerr << "Formato: ./" << argv[0] << " <rutaArchivo.tsp>" << endl;
      return -1;
    }

    //      Lectura de archivo:
    // Cantidad de nodos.
    int dim;
    // Estructura para contener las ciudades de entrada y el resultado.
    vector<nodo> ciudades, tour;
    // Cadenas para procesar entrada.
    string linea = "";
    istringstream aux2;
    // Abrir el archivo.
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

        ciudades.resize(dim);
        int a;
        double b,c;
        for(int i=0; i<dim; i++)
        {
            archivo >> a >> b >> c;
            ciudades[i].indice = a;
            ciudades[i].x = b;
            ciudades[i].y = c;
        }
        archivo.close();
    }
    else cout << "No se puede abrir el archivo."; 

    TSPbacktracking(ciudades.front(),ciudades.erase(0),tour);



}
