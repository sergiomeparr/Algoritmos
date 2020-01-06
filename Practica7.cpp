#include <iostream>

using namespace std;

int **Crear_Matriz(int numero){
	int **aux = new int*[numero + 2];
	for(int i = 0; i < 4; i++){
		aux[i] = new int[i];
	}
	return aux;
}

int main(void){
	string camino;
	int estaciones;
	cout << "Ingresa el numero de estaciones: ";
	cin >> estaciones;
	int **Matriz = Crear_Matriz(estaciones);
	for(int i = 0; i < estaciones + 2; i ++){
		cout << "\n";
		for(int j = 0; j < 4; j++){
			if((i == 1 && j == 0) || (i == 1 && j == 1))
		}
	}
	
}