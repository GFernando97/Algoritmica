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

vector<int> joinVector(vector<int> &vIzq, vector<int> &vDer){
    int i = 0;
    int j = 0;
    bool fin = false;
    vector<int> Vfinal;

    while(!fin){

        if(vIzq[i] < vDer[j]){
            Vfinal.push_back(vIzq[i]);

            if(i == (vIzq.size()-1)){
                fin = true;

                for(int h = j; h < vDer.size(); h++){
                    Vfinal.push_back(vDer[h]);
                }
            }

            else i++;
        }

        else if(vIzq[i] > vDer[j]){
            Vfinal.push_back(vDer[j]);

            if(j == (vDer.size()-1)){
                fin = true;

                for(int h = i; h < vIzq.size(); h++){
                    Vfinal.push_back(vIzq[h]);
                }
            }

            else j++;
        }

        else {
            Vfinal.push_back(vIzq[i]);

            if(i == (vIzq.size()-1)){
                fin = true;

                for(int h = j+1; h < vDer.size(); h++){
                    Vfinal.push_back(vDer[h]);
                }
            }



            else if(j == (vDer.size()-1)){
                fin = true;

                for(int h = i+1; h < vIzq.size(); h++){
                    Vfinal.push_back(vIzq[h]);
                }
            }

            else {i++;j++;}

        }

    }
    return Vfinal;

}

// A utility function to swap two elements  
void swap(int* a, int* b)  
{  
    int t = *a;  
    *a = *b;  
    *b = t;  
}  
  
/* This function takes last element as pivot, places  
the pivot element at its correct position in sorted  
array, and places all smaller (smaller than pivot)  
to left of pivot and all greater elements to right  
of pivot */
int partition (vector<int> &arr, int low, int high)  
{  
    int pivot = arr[high]; // pivot  
    int i = (low - 1); // Index of smaller element  
  
    for (int j = low; j <= high - 1; j++)  
    {  
        // If current element is smaller than the pivot  
        if (arr[j] < pivot)  
        {  
            i++; // increment index of smaller element  
            swap(&arr[i], &arr[j]);  
        }  
    }  
    swap(&arr[i + 1], &arr[high]);  
    return (i + 1);  
}  
  
/* The main function that implements QuickSort  
arr[] --> Array to be sorted,  
low --> Starting index,  
high --> Ending index */
void quickSort(vector<int> &arr, int low, int high)  
{  

    if (low < high)  
    {  
        /* pi is partitioning index, arr[p] is now  
        at right place */
        int pi = partition(arr, low, high);  
  
        // Separately sort elements before  
        // partition and after partition  
        quickSort(arr, low, pi - 1);  
        quickSort(arr, pi + 1, high);  
    }  
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

vector<int> alternativaPropuesta(vector<int> &V){
  vector<int> vAux;
  int k = 0;
  
  quickSort(V, 0, V.size()-1);
  
  vAux.push_back(V[0]);



  for(int i=1; i<V.size(); i++){
    if(V[i] != vAux[k]){
      vAux.push_back(V[i]);
      k++;
    }
  }

  return vAux;
}

vector<int> divideyVenceras(vector<int> &V){
    int tam = V.size();
    if(tam==1)
        return V;


    int mitadPos = tam/2;
    vector<int> vMitadIzq;
    vector<int> vMitadDer;
    vMitadIzq.assign(V.begin(), V.end()-mitadPos);
    vMitadDer.assign(V.end()-mitadPos, V.end());

    vMitadIzq = divideyVenceras(vMitadIzq);
    vMitadDer = divideyVenceras(vMitadDer);
    V = joinVector(vMitadIzq, vMitadDer);


   return V;

}



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
  vector<int> ordenado = alternativaPropuesta(Voriginal);
  
  for(int i= 0; i< ordenado.size(); i++)
      cout << ordenado[i];

}