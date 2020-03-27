#include <iostream>
#include <vector>
#include <cstdlib>
#include <cassert>

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

double uniforme() 
{
	int t = rand();
	double f = ((double)RAND_MAX+1.0);
	return (double)t/f;
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

//vector<int> divideYVenceras(vector<int> &V){}

int main(int argc, char * argv[])
{
	vector<int> Voriginal;

// GENERAR VECTOR

 	if (argc != 2)
    {
    	cerr << "Formato " << argv[0] << " <num_elem>" << endl;
    	return -1;
    }
  	int n = atoi(argv[1]);

  	int * T = new int[n];
  	assert(T);

	srand(time(0));

	for (int j=0; j<n; j++) 
	{
		double u=uniforme();
		int k=(int)(n*u);
		T[j]=k;
	}

	for (int j=0; j<n; j++) 
	{
		cout << T[j] << " ";
		Voriginal.push_back(T[j]);
	}

// INICIO CODIGO
	//Generar(Voriginal);
	vector<int> ordenado = fuerzaBruta(Voriginal);
	
	for(int i= 0; i< ordenado.size(); i++)
	    cout << ordenado[i];

}