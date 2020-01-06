#include <iostream>
#include <stdlib.h>

using namespace std;

long long *Fibonacci(int numero);
long long **Triangulo_de_Pascal(int nivel);

long long **Triangulo_de_Pascal(int nivel){
	long long **Aux = new long long *[nivel + 1];
	for(int i = 0; i < nivel; i ++)
		Aux[i] = new long long[nivel + 1];
	
	for(int i = nivel; i >= 0; i--){
		for(int j = i; j < nivel; j++){
			if(i == j || j == nivel - 1)
				Aux[i][j] = 1;
			else
				Aux[i][j] = Aux[i + 1][j] + Aux[i + 1][j + 1];
		}
	}
	return Aux;
}

long long *Fibonacci(int numero){
	long long *Aux = new long long[numero + 2];
	Aux[0] = 0;
	Aux[1] = 1;
	for(int i = 2; i <= numero + 2; i++)
		Aux[i] = Aux[i - 1] + Aux[i - 2]; 
	return Aux;
}

int main(void){
	system("cls");
	fflush(stdin);
	int numero;
	int nivel;
	int opcion;
	cout << "1.- Fibonacci\n";
	cout << "2.- Triangulo de Pascal\n";
	cout << "3.- Salir\n";
	cin >> opcion;
	if(opcion == 1){
		cout << "Ingresa el numero de Fibonacci: ";
		cin >> numero;
		//Creacion del Arreglo para Fibonacci
		long long *Respuesta = new long long[numero + 2];
		//fflush(stdin);
		//Funcion para el calculo de Fibonacci
		Respuesta = Fibonacci(numero);
	
		cout << "\nFibonacci de \tResultado\n\n";
		for(int i = 0; i <= numero ; i++)
			cout << "\t" << i << "\t\t" << Respuesta[i] << "\n";

		system("pause");	
	}
	if(opcion == 2){
		cout << "Ingresa el nivel del Triangulo de Pascal: ";
		cin >> nivel;
		cout << "\n\n";
		//Creacion de la Matriz para el Triangulo de Pascal
		long long **Triangulo = new long long*[nivel + 1];
		for(int i = 0; i < nivel; i ++)
			Triangulo[i] = new long long[nivel + 1];
		//Funcion para el calculo de Triangulo de Pascal
		Triangulo = Triangulo_de_Pascal(nivel);
		cout << "     Nivel\tTriangulo de Pascal";
		for(int i = nivel; i >= 0; i--){
			cout << "\n";
			for(int j = i; j < nivel; j++){
				if(i == j)
					cout << "\t" << nivel - i << "\t";
				cout << " " << Triangulo[i][j];
			}
		}
	}
	else
		exit(0);
	
	cout << "\n";
	system("pause");
}
