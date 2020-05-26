//vector de nodos
//vector de adyacencia booleano


void Backtracking(int nodoAct){
	if(nodoAct == NumeroNodos){
		for(int i = 0; i < NumeroNodos; i++){
			cout << vectorNodos[i] << " ";
		}
		cout << endl;

	}

	else{
		do{
			vectorNodos[nodoAct] = siguienteValor(nodoAct);
			if(vectorNodos[nodoAct] != 0){
				Backtracking(nodoAct+1);
			}
		}while(vectorNodos[nodoAct] != 0);
	}
}

int siguienteValor(int k){

	do{
		vectorNodos[k]++;

		if(adyacencia[vectorNodos[k-1]][vectorNodos[k]]
		and vectorNodos[k] noEsta en vectorNodos
		and (k < NumeroNodos or (k==NumeroNodos and adyacencia[vectorNodos[k]][vectorNodos[k]])))
			return vectorNodos[k];
	}while(vectorNodos[k] < NumeroNodos);

	vectorNodos[k] = 0;
	return 0;

}