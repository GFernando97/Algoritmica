/*ES:   Asignatura: Algoritmica
        Trabajo: Practica 3 - Greedy
        Descripcion: TSP con método de Cercanía */ 

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

//  CONTENEDOR
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

//      Funcion TSP Greedy por Cercania
void tspCercania(vector<nodo> ciudades, vector<nodo> &tour, int inicio, int &camino)
{
    int dim = ciudades.size(),
        distanciaMin,
        distanciaAct,
        indiceCiudad;

    nodo nodoIni = ciudades[inicio],
         nodoVec, 
         nodoFin = nodoIni;

    tour.push_back(ciudades[inicio]);

    ciudades.erase(ciudades.begin() + inicio);

    while (!ciudades.empty())
    {
        distanciaMin = INT_MAX;
        for (int i = 0; i < (int)ciudades.size(); i++)
        {
            distanciaAct = calcularDistancia(ciudades[i].x, nodoIni.x, ciudades[i].y, nodoIni.y);   
            if(distanciaMin >= distanciaAct)
            {
                distanciaMin = distanciaAct;
                nodoVec = ciudades[i];
                indiceCiudad = i;
            }
        }

        camino += distanciaMin;

        tour.push_back(nodoVec);
        nodoIni = nodoVec;
        
        ciudades.erase(ciudades.begin() + indiceCiudad);
    }

    camino += calcularDistancia(tour[dim-1].x, nodoFin.x, tour[dim-1].y, nodoFin.y);
    tour.push_back(nodoFin);
    
}

//      Funcion Main
int main(int argc, char * argv[])
{

    if (argc != 2)
    {
      cerr << "Formato: ./" << argv[0] << " <rutaArchivo.tsp>" << endl;
      return -1;
    }

    int dim;
    vector<nodo> ciudades, tour;
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

    int camino = 0;
    tspCercania(ciudades,tour, 0, camino);

    cout <<"CAMINO: "<< camino << endl
            <<"INICIO_CAMINO_CERCANIA"<< endl;

    for (int i = 0; i < (int)tour.size(); i++)
    {
        cout <<tour[i].indice<<"\t" <<tour[i].x<<"\t"<<tour[i].y<<endl;
    }

  return 0;
}
