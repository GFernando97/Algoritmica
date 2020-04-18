//Uso ./<nombre_ejecutable> <arhchivo.tsp>

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct nodo{
    float node, coord, section;
};


int main(int argc, char **argv){
    if(argc != 2){
        cout << "Argumentos incorrectos\n";
        return -1;
    }
    string linea="";
    vector<nodo> v;
    ifstream f(argv[1]);
    int dim;
    if(!f.is_open()){
        cout << "Error al abrir el archivo\n";
        return -2;
    }
    else{
        int aux1, aux2;
        string prov;
        while(linea.compare("NODE_COORD_SECTION")!=0){
            getline(f, linea);
            aux1=linea.find("DIMENSION");
            if(aux1 != -1){
                aux1= linea.find(":");
                aux2= linea.find("\n");
                prov=linea.substr(aux1+1, aux2);
                dim = atoi(prov.c_str());
            }
        }
        v.resize(dim);
        float n, c, s;
        for(vector<nodo>::iterator i= v.begin(); i != v.end(); ++i){
            f >> n >> c >> s;
            i->node = n;
            i ->coord = c; 
            i ->section = s;
        }
        f.close();

         for(vector<nodo>::iterator i= v.begin(); i != v.end(); ++i)
            cout << i->node << " " <<i ->coord  << " " <<  i ->section<< endl;   
            
    }
}