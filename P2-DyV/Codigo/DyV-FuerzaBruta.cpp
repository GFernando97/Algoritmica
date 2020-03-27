
#include <iostream>
#include <vector>

using namespace std;

void Generar(vector<int> &v){
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(7);
    v.push_back(2);
    v.push_back(5);
    v.push_back(5);
    v.push_back(3);
}

vector<int> fuerzaBruta(vector<int> &V){
    vector<int> Vaux;
	int k=0;
	bool encontrado;


    Vaux.push_back(V[0]);
	
	for(int i = 1; i < V.size(); i++){
		int j =0;
		encontrado = false;

		while(j <= k and !encontrado){
			if(V[i] == Vaux[j])
				encontrado=true;
			else j++;
		}

		if(!encontrado){
			k++;
			Vaux.push_back(V[i]);
		}

	}
	
	return Vaux;  
}

int main(){

	vector<int> Voriginal;
	Generar(Voriginal);
	vector<int> ordenado = fuerzaBruta(Voriginal);
	
	for(int i= 0; i< ordenado.size(); i++)
	    cout << ordenado[i];



}