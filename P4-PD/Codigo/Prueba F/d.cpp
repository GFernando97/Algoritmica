#include <iostream>
#include <vector>
#include<climits>

using namespace std;


void defineM(vector<vector<int>> &dist, vector <vector <int>> &visited, vector<int> &nodosEx){
 /* dist[0][0]=0;  
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
  dist[3][3]=0;*/

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

int funcionG(int i, vector<int>&nodosEx, vector<vector<int>>&distancias, vector<vector<int>>&memoria){
	int distMenor = 9999999;
	vector<int> nodosAux;

	//cout << "nodo analizado " << i << endl;

	if(nodosEx.empty()){
		//cout << "weee" << endl;
		return distancias[i][0];
	}

	else{
		if(memoria[i][nodosEx.back()] >= 0){
		//	cout << "NOOOOOOOO" << endl;
			return memoria[i][nodosEx[0]];
		}

		else{
			for(int j = 0; j < nodosEx.size(); j++){
				nodosAux = nodosEx;
				nodosAux.erase(nodosAux.begin()+j);

				int distancia = distancias[i][nodosEx[j]] + funcionG(nodosEx[j], nodosAux, distancias, memoria);
				cout << distancia << endl;
				if(distancia < distMenor)
					distMenor = distancia;
			}
			memoria[i][nodosEx.front()];
			return distMenor;

			
		}
	}
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