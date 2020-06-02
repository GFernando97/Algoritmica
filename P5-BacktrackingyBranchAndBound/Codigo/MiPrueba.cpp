#include <iostream>
#include <vector>
#include <climits>
#include <fstream>
#include <math.h>
#include <sstream>
#include <ctime>
#include <queue>
#include <utility>

using namespace std;

//Clase implementada para poder alterar la prioridad de la cola
//con prioridades implementada
class Compare
{
public:

   bool operator() (const pair<int,int> &C1, const pair<int,int> &C2)
    {
        return C1.second > C2.second ;
    }
};



class TSP {

private:

  vector< vector<int> > distancias;
  priority_queue<pair<int,int>, vector<pair<int,int>>, Compare>ColaNodos;
  int distancia_sol;
  vector<int> camino_sol;
  int nodos_expandidos;
  int n_podas;
  int tam_max_cola = 0; 

public:

  int calcular_distancia(float x1, float x2, float y1, float y2) {
    return (int) round((sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2))));
  }

  int menor_arista(int nodo) {
    int arista_menor;
    arista_menor = INT_MAX;
    for (int i = 0; i < (int) distancias[nodo].size(); i++) {
      if (arista_menor > distancias[nodo][i]) {
        arista_menor = distancias[nodo][i];
      }
    }
    return arista_menor;
  }

  int get_nodos_expandidos() {
    return nodos_expandidos;
  }

  int get_n_podas() {
    return n_podas;
  }

  int get_distancia_sol() {
    return distancia_sol;
  }

  vector<int> get_camino_sol() {
    return camino_sol;
  }


  void rellenaCola(int &actual, vector<int> &nodos_sinvisitar){
    ColaNodos = priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> ();
    pair<int,int> nuevaDist;
    cout << "num nodos sin visitar: " << nodos_sinvisitar.size() << endl;

    for(int i = 0; i < (int) nodos_sinvisitar.size(); i++){
      nuevaDist.first = i;
      nuevaDist.second = distancias[actual][nodos_sinvisitar[i]];
      ColaNodos.push(nuevaDist);
    }

    if(ColaNodos.size() > tam_max_cola)
      tam_max_cola = ColaNodos.size();
    

    priority_queue <pair<int,int>, vector<pair<int,int>>, Compare> g = ColaNodos; 
    while (!g.empty()) { 
      pair<int,int> NAux;
      NAux.first = g.top().first;
      NAux.second  = g.top().second;
      g.pop(); 
      cout << NAux.first << "----" << NAux.second << endl; 
    } 
    cout << endl; 
  }


  TSP (vector<float> x, vector<float> y, vector<int> ciudades) {

    int dimension;

    camino_sol.clear();

    distancias.clear();

    dimension = (int) x.size();
    distancias.resize(dimension);

    for (int i = 0; i < dimension; i++) {
      for (int j = 0; j < dimension; j++) {
        distancias[i].push_back(calcular_distancia(x[i], x[j], y[i], y[j]));
      }
    }

    distancia_sol = greedy(ciudades);

    cout<<"Distancia Inicial:"<<distancia_sol<<endl;

    nodos_expandidos = 0;
    n_podas = 0;
  }

  int resolver(vector<int> ciudades_visitadas, vector<int> ciudades_sinvisitar, int distancia_visitadas, int distancia_estimada_opt) {

    vector<int> aux_ciudades_visitadas, aux_ciudades_sinvisitar;
    int distancia_total, aux_distancia_estimada_opt;

    if (!ciudades_sinvisitar.empty()) {

      aux_ciudades_visitadas = ciudades_visitadas;

      for (int i = 0; i < (int) ciudades_sinvisitar.size(); i++) {

        distancia_total = 0;

        rellenaCola(ciudades_visitadas.back(), ciudades_sinvisitar);
        int indiceProm = ColaNodos.top().first;

        aux_ciudades_visitadas = ciudades_visitadas;
        aux_ciudades_visitadas.push_back(ciudades_sinvisitar[indiceProm]);
        aux_ciudades_sinvisitar = ciudades_sinvisitar;
        aux_ciudades_sinvisitar.erase(aux_ciudades_sinvisitar.begin()+indiceProm);
        distancia_total += distancia_visitadas + distancias[ciudades_visitadas.back()][aux_ciudades_visitadas.back()];
        aux_distancia_estimada_opt = distancia_estimada_opt - menor_arista(aux_ciudades_visitadas.back());

        cout << "Nueva Ciudad " << aux_ciudades_visitadas.back() << endl;

        if (distancia_total  + aux_distancia_estimada_opt < distancia_sol) {

          cout << "Dist Total vs Dist Sol " << distancia_total +aux_distancia_estimada_opt<< " ------- " << distancia_sol << endl;

          nodos_expandidos++;
          resolver(aux_ciudades_visitadas, aux_ciudades_sinvisitar, distancia_total, aux_distancia_estimada_opt);
        }
        else {
          n_podas++;
        }
      }
    }
    else {

      distancia_total = 0;

      for (int i = 0; i < (int) ciudades_visitadas.size()-1; i++) {
        distancia_total += distancias[ciudades_visitadas[i]][ciudades_visitadas[i+1]];
      }
      distancia_total += distancias[ciudades_visitadas.front()][ciudades_visitadas.back()];

      if (distancia_total < distancia_sol) {
        distancia_sol = distancia_total;
        camino_sol = ciudades_visitadas;
      }
    }

    return 0;
  }


int greedy(vector<int> ciudades)
  {
  //  Declaración de variables auxiliares para Greedy.
      int dim = (int) ciudades.size(),
          distanciaMin,
          distanciaAct,
          indiceCiudad,
          camino = 0;

  //  Declaración de los nodos (ciudades) auxiliares para Greedy
      int nodoIni = ciudades[0],
          nodoVec,
          nodoFin = nodoIni;

  //  El vector Ciudades es la lista de Candidatos, se elimina el vector de inicio.
      ciudades.erase(ciudades.begin());

  //  Mientras queden Candidatos
      while (!ciudades.empty())
      {
  //      Tomando la ciudad actualmente elegida, se itera en el vector de Candidatos buscando otra ciudad que tiene la distancia más corta hacia ella.
  //      Si existen dos o más con la misma distancia, se toma la primera.
          distanciaMin = INT_MAX;
          for (int i = 0; i < (int) ciudades.size(); i++)
          {
              distanciaAct = distancias[nodoIni][ciudades[i]];

              if(distanciaMin > distanciaAct && nodoIni != i)
              {
  //              Se actualiza la distancia minima hasta obtener la mas pequeña de todas y también el nodo asociado a ella.
                  distanciaMin = distanciaAct;
                  nodoVec = ciudades[i];
                  indiceCiudad = i;
              }
          }
  //      Se suma la distancia mínima en al camino
          camino += distanciaMin;

  //      Se añade la ciudad más cercana a la solución y ahora se busca otra ciudad cercana a esta última.
          nodoIni = nodoVec;

  //      Se elimina la ciudad más cercana de los candidatos, para evitar pasar por el mismo sitio dos veces.
          ciudades.erase(ciudades.begin() + indiceCiudad);
      }

  //  Calcular el camino de la ultima ciudad elegida y el comienzo, lo que finaliza el recorrido y se almacena también en la solución.
      camino += distancias[nodoIni][nodoFin];

      return camino;
    }

};

int main(int argc, char const *argv[]) {

  // Lectura de los parametros de entrada
  if (argc != 2)
  {
    cout << "Parametros de entrada: " << endl << "1.- Nombre del fichero TSP" << endl << endl;
    return 1;
  }

  ifstream infile(argv[1]);
  istringstream aux_stringstream;
  string line, text;
  int aux, dimension;
  float var1, var2, var3;
  vector<float> x, y;
  vector<int> n;
  vector<int> ciudades_visitadas, ciudades_sinvisitar;

  if (infile.is_open()) {
    while (line.compare("NODE_COORD_SECTION") != 0) {
      getline(infile, line);
      aux = line.find("DIMENSION");
      if (aux != -1) {
        aux = line.find(":");
        aux_stringstream.str(line.substr(aux+1,-1));
        aux_stringstream >> dimension;
      }
    }
  }
  else {
    cout << "Archivo no encontrado" << endl;
  }

  // Lectura del número del nodo, su posición x e y
  for (int i = 0; i < dimension; i++) {
    infile >> var1 >> var2 >> var3;
    n.push_back(var1-1);
    x.push_back(var2);
    y.push_back(var3);
  }

  infile.close();

  srandom(time(0));

  ciudades_sinvisitar = n;
  ciudades_sinvisitar.pop_back();
  ciudades_visitadas.push_back(n.back());
  int distancia_estimada_opt;
  distancia_estimada_opt = 0;

  TSP tsp(x, y, n);
  for (int i = 0; i < (int) ciudades_sinvisitar.size(); i++) {
    distancia_estimada_opt += tsp.menor_arista(ciudades_sinvisitar[i]);
  }



  cout << distancia_estimada_opt << endl;

  clock_t t_inicial = clock();

  tsp.resolver(ciudades_visitadas, ciudades_sinvisitar, 0, distancia_estimada_opt);

  clock_t t_final = clock();

  cout << "Tiempo Ejecucion: " << ((double)(t_final - t_inicial)) / CLOCKS_PER_SEC << endl;
  cout << "Nodos expandidos: " << tsp.get_nodos_expandidos() << '\n';
  cout << "Numero de podas: " << tsp.get_n_podas() << '\n';
  cout << "Distancia solucion: " << tsp.get_distancia_sol() << '\n';
  ciudades_visitadas = tsp.get_camino_sol();
  for (int i = 0; i < (int) ciudades_visitadas.size(); i++) {
    cout << ciudades_visitadas[i]+1 << ' ';
  }

  return 0;
}
