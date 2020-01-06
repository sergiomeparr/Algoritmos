#include <vector>
#include <iostream>

using namespace std;

void Ordenar(int *cadena, int indice, int tamano){
	int division = (indice + tamano) / 2;
	int temp;
	if(indice < tamano){
		for(int i = 0; i < tamano; i++){
			if(cadena[i] > cadena[i+1]){
				temp = 	cadena[i];
				cadena[i] = cadena[i + 1];
				cadena[i + 1] = temp;
			}
		} 
	}
	else if(indice == tamano)
		return;
}

void Dividir(int *Cadena, int indice, int tamano, int divisiones, int espacio){
	int resultado = (indice + tamano) / divisiones;
	int *aux = new int[resultado];
	int *aux2 = new int[resultado];
	int *aux3 = new int[espacio];
	do{
		Ordenar(Cadena, indice, resultado);
		resultado ++;
	}while(resultado <= tamano);
	for(int i = 0; i < tamano; i ++)
		cout << Cadena[i] << " ";	
}

int *Random(int *cadena, int tamano){
	for(int i = 0; i < tamano; i++) {
		cadena[i] = rand() % 100;
	}
	return cadena;
}	

int main(){
    int tamano, divisiones;
	int indice = 0;
	cout << "\t" << "Cuantos elementos quieres: ";
	cin >> tamano; 
	cout << "\t" << "Indica el num. de divisiones: ";
	cin >> divisiones;
	int *Cadena_Numeros = new int[tamano];
	int *Numeros = new int[tamano];
	int *Respuesta = new int[tamano];
	Cadena_Numeros = Random(Numeros, tamano);
	cout << "\n\t" << "cadena desordenada: \t";
	for(int i = 0; i < tamano; i++) {
		cout << Cadena_Numeros[i] << " ";
	}
	cout << "\n\t" << "cadena desordenada: \t";
	Dividir(Cadena_Numeros, indice, tamano, divisiones, tamano);
	return 0;
}


