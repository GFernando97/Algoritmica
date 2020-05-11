#include <iostream>
#include <vector>
#include<climits>

using namespace std;

void defineM(vector<vector<int>> &dist, vector <vector <int>> &visited, vector<int> &nodosEx){
  dist[0][0]=0;  
  dist[0][1]=10;
  dist[0][2]=15;
  dist[0][3]=20;
  dist[1][0]=5;
  dist[1][1]=0;
  dist[1][2]=9;
  dist[1][0]=10;
  dist[2][0]=6;
  dist[2][1]=13;
  dist[2][2]=0;
  dist[2][3]=12;
  dist[3][0]=8;
  dist[3][1]=8;
  dist[3][2]=9;
  dist[3][3]=0;

  for(int i = 0; i < 4; i++){
  	for(int j = 0; j < 4; j++)
    	visited[i][j] = -1;
  }


  nodosEx.push_back(0);
  nodosEx.push_back(1);
  nodosEx.push_back(2);
  nodosEx.push_back(3);

}

int funcionG( int node, vector<int>&nodosEx, vector<vector<int>> &vec, vector<vector <int>> &visited ){
  int masCorto = 9999999;

  if(nodosEx.empty()){
  	return vec[node][0];
  }

  else{
  	cout << "valor node " << node << endl;
  	cout << "Valor en nodos ex " << nodosEx[0] << endl;
  	if(visited[node][nodosEx[0]]>= 0){
  		return visited[node][nodosEx[0]];
  	}

  	else{
  		for(int i = 0; i < nodosEx.size(); i++){
        nodosEx.erase(nodosEx.begin()+i);

  			int distancia = vec[node][nodosEx[i]] + funcionG(nodosEx[i], nodosEx, vec, visited);

  			if(distancia < masCorto)
  				masCorto = distancia;
  		}

  		visited[node][nodosEx.back()];
  	}
  }
  		return masCorto;

}


int g(int nodo, vector<int> s, vector< vector<int> > distancias) {
    
    int distancia_min, distancia_min_aux;
    int nodo_distancia_min;
    vector<int> s_aux;
    
    distancia_min = INT_MAX;
    nodo_distancia_min = -1;

    // Calcula la distancia mínima entre 'nodo' y todos los nodos de 'nodos'
    if (s.size() > 0) {
        
        for (int i = 0; i < (int) s.size(); i++) {
            
            s_aux = s;
            s_aux.erase(s_aux.begin()+i);
            // Llamada Recursiva
            distancia_min_aux = distancias[nodo][s[i]] + g(s[i], s_aux, distancias);
            
            if (distancia_min_aux < distancia_min) {
                distancia_min = distancia_min_aux;
                nodo_distancia_min = i;
            }
        }
    }
    // 'nodos' está vacío
    else {
        
        distancia_min = distancias[nodo][0];
        nodo_distancia_min = 0;
    }
    
    return nodo_distancia_min;
}

int main() {
	const int RR = 4;
	vector<vector <int>> longitudes(RR);
	vector<vector <int>> memoria(RR);
	vector<int> nodosExistentes;


	for ( int i = 0 ; i < RR ; i++ ){
   		longitudes[i].resize(RR);
   		memoria[i].resize(RR);

	}

	cout << "Asignando valores..." << endl;
	defineM(longitudes, memoria, nodosExistentes);

	cout << "Pasa la fase de definicion de valores." << endl;

	int resultadoFinal = funcionG(0,nodosExistentes, longitudes, memoria);

  //int resultadoFinal = g(1,nodosExistentes, longitudes);
	cout << resultadoFinal;

}