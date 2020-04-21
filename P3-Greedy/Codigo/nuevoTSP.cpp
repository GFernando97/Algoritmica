#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <vector>
#include <math.h>
#include <limits>
#include <cfloat>

using namespace std;

float calcular_distancia(float x1, float x2, float y1, float y2) {
  return sqrt(pow(x1-x2, 2)+pow(y1-y2,2));
}

int main() {

  ifstream infile("ulysses16.tsp");
  string line, text;
  int dimension, err, menordistancia_n1, menordistancia_n2, arista_union;
  float var1, var2, var3, menordistancia;
  vector<int> n, n_aux, aristas;
  vector<float> x, y, distancias_aristas;
  vector< vector<float> > distancia;
  bool repetidas, encontrado;

  if (!getline(infile, line))
    return 0;

  if (!getline(infile, line))
    return 0;

  if (!getline(infile, line))
    return 0;

  infile >> text >> dimension;

  if (!getline(infile, line))
    return 0;

  if (!getline(infile, line))
    return 0;

  if (!getline(infile, line))
    return 0;

  if (!getline(infile, line))
    return 0;

  for (int i = 0; i < dimension && getline(infile, line); i++) {
    istringstream ss(line);

    ss >> var1 >> var2 >> var3;
    n.push_back(var1);
    x.push_back(var2);
    y.push_back(var3);
  }

  distancia.resize( dimension, vector<float>(dimension) );

  // Cálculo de todas las distancias
  for (int i = 0; i < dimension; i++) {
    for (int j = i; j < dimension; j++) {
      distancia[i][j] = calcular_distancia(x[i],x[j],y[i],y[j]);
    }
  }

  // Ordenas aristas de menos a mayor
  while (aristas.size() < pow(dimension, 2) - dimension) {

    menordistancia = 999.9;
    menordistancia_n1 = -1;
    menordistancia_n2 = -1;
    repetidas = false;

    for (int i = 0; i < dimension; i++) {
      for (int j = i; j < dimension; j++) {

        if (distancia[i][j] < menordistancia && i != j) {

          for (int k = 0; k < aristas.size(); k += 2) {
            if ( (aristas[k] == i || aristas[k] == j) && (aristas[k+1] == i || aristas[k+1] == j) ) {
                repetidas = true;
            }
          }

          if (!repetidas) {
            menordistancia = distancia[i][j];
            menordistancia_n1 = i;
            menordistancia_n2 = j;
          }
          else repetidas = false;
        }
      }
    }

    aristas.push_back(menordistancia_n1);
    aristas.push_back(menordistancia_n2);
    distancias_aristas.push_back(menordistancia);
  }

  n_aux.push_back(aristas[0]);
  n_aux.push_back(aristas[1]);
  aristas.erase(aristas.begin());
  aristas.erase(aristas.begin());

  while (n_aux.size() < dimension) {

    encontrado = false;

    for (int i = 0; i < aristas.size() && !encontrado; i += 2) {

      if (aristas[i] == n_aux.front()) {
        encontrado = true;
        arista_union = aristas[i];
        n_aux.insert(n_aux.begin(), aristas[i+1]);
      }
      else if (aristas[i] == n_aux.back()) {
        encontrado = true;
        arista_union = aristas[i];
        n_aux.push_back(aristas[i+1]);
      }
      else if (aristas[i+1] == n_aux.front()) {
        encontrado = true;
        arista_union = aristas[i+1];
        n_aux.insert(n_aux.begin(), aristas[i]);
      }
      else if (aristas[i+1] == n_aux.back()) {
        encontrado = true;
        arista_union = aristas[i+1];
        n_aux.push_back(aristas[i]);
      }
    } // end for

    // Borrado de aristas
    for (int i = 0; i < aristas.size(); i+=2) {
      if (aristas[i] == arista_union || aristas[i+1] == arista_union) {
        aristas.erase(aristas.begin()+i,aristas.begin()+i+2);
        i-=2;
      }
      else if ( (aristas[i] == n_aux.front() && aristas[i+1] == n_aux.back()) || (aristas[i+1] == n_aux.front() && aristas[i] == n_aux.back()) ) {
        aristas.erase(aristas.begin()+i,aristas.begin()+i+2);
        i-=2;
      }
    } // end for
  }//end while

  for (int i = 0; i < n_aux.size(); i++) {
    cout << n_aux[i]+1 << '\t' << x[n_aux[i]] << '\t' << y[n_aux[i]] << endl;
  }
}
