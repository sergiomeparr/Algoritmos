#include <iostream>

using namespace std;

int x, y, ColumnaA = 1;

int **Crear(int fila, int columna);
int **Llenar(int **Aux, int fila, int columna);
int **PonerDatos(int dato, int fila, int columna);
int **EliminarCeros(int **Resultado, int fila, int columna);
int **MatrizCuadrada(int ** Matriz, int fila_max, int columna_max, int fila, int columna);

//Funcion que crea matrices
int **Crear(int fila, int columna){
	int **Matriz = new int *[fila];
	for(int i = 0; i < fila; i++)
		Matriz[i] = new int [columna];
	return Matriz;
}

//Funcion que elimina ceros de la matriz resultado
int **EliminarCeros(int **Resultado, int fila, int columna){
	int **Aux = Crear(fila, columna);
	Aux = PonerDatos(0, fila, columna);
	for(int i = 0; i < fila; i++){
		for(int j = 0; j < columna; j++)
			Aux[i][j] = Resultado[i][j];
	}
	return Aux;
}

//Funcion que añade ceros a una matriz para que sea cuadrada
int **MatrizCuadrada(int ** Matriz, int fila_max, int columna_max, int fila, int columna){
	int **Aux = Crear(fila_max, columna_max);
	Aux = PonerDatos(0, fila_max, columna_max);
	for(int i = 0; i < fila; i++){
		for(int j = 0; j < columna; j++)
			Aux[i][j] = Matriz[i][j];
	}
	return Aux;
}

//Funcion que pone datos en una matriz
int **PonerDatos(int dato, int fila, int columna){
	int **Matriz = Crear(fila, columna);
	for(int i = 0; i < fila; i++){
		for(int j = 0; j < columna; j++)
			Matriz[i][j] = dato;
	}
	return Matriz;
}

//Funcion que copia los datos de una matriz a otra
int **Llenar(int **Aux, int fila, int columna){
	int **Matriz = new int *[fila];
	for(int i = 0; i < fila; i++)
		Matriz[i] = new int [columna];
	for(int i = 0; i < fila; i++){
		for(int j = 0; j < columna; j++){	
			Matriz[i][j] = Aux[i][j];
		}
	}
	return Matriz;
}

int **PDyV(int **MatrizA, int **MatrizB, int filaA, int columnaA, int filaB, int columnaB){
	if(ColumnaA = 1 || filaB == 1){
		int **Aux1 = Crear(filaA, columnaB);
		int **Aux2 = Crear(filaA, columnaB);
		int **Aux3 = Crear(filaA, columnaB);
		Aux1 = PonerDatos(0, filaA, columnaB);
		Aux2 = PonerDatos(0, filaA, columnaB);
		Aux1 = MatrizCuadrada(MatrizA, filaA, columnaB, filaA, columnaA);
		Aux2 = MatrizCuadrada(MatrizB, filaA, columnaB, filaB, columnaB);
		//Multiplicacion de las matrices resultante
		for(int i = 0; i < filaA; i++){
			for(int j = 0; j < columnaB; j++){
				Aux3[i][j] = 0;
				for(int k = 0; k < columnaB; k++)
					Aux3[i][j] = Aux3[i][j] + (Aux1[i][k] * Aux2[k][j]);
			}
		}
		return Aux3;
	}
	else{
		int vertical = (columnaA / 2);
		int horizontal = (filaB / 2);
		int **A = Llenar(MatrizA, filaA, vertical);
		int **B = Llenar(MatrizA, filaA, columnaA - vertical);
		int **C = Llenar(MatrizB, horizontal, columnaB);
		int **D = Llenar(MatrizB, filaB - horizontal, columnaB);
		int **AC = Crear(filaA, columnaB);
		int **BD = Crear(filaA, columnaB);
		int **Resultado = Crear(filaA, columnaB);
		Resultado = PonerDatos(0, filaA, columnaB);
		AC = PonerDatos(0, filaA, columnaB);
		BD = PonerDatos(0, filaA, columnaB);
		//LLamadas a funcion para el producto de matrices con DyV
		AC = PDyV(A, C, filaA, vertical, horizontal, columnaB);
		BD = PDyV(B, D, filaA, columnaA - vertical, filaB - horizontal, columnaB);
		//Suma de las matrices resultado
		for(int i = 0; i < filaA; i++){
			for(int j = 0; j < columnaB; j++){
				Resultado[i][j] = AC[i][j] + BD[i][j];
			}
		}
		return Resultado;
	}
}

int main(void){
	system("cls");
	int n, m, k, n1, max;
	cout << "MatrizA \n";
	cout << "tamano de fila: ";
	cin >> m;
	cout << "tamano de columna: ";
	cin >> n;
	cout << "\n\nMatrizB \n";
	cout << "tamano de fila: ";
	cin >> n1;
	cout << "tamano de columna: ";
	cin >> k;
	if(n != n1){
		cout << "No se puede resolver la matriz";
		exit(0);
	}
	else if(n == n1){
		cout << "\nIngresa valor de x: ";
		cin >> x;
		cout << "\nIngresa valor de y: ";
		cin >> y;
		if(n > m && n > k){
			int **Aux1 = Crear(n, n);
			int **Aux2 = Crear(n, n);
			int **MatrizA = Crear(m, n);
			int **MatrizB = Crear(k, n);
			int **Resultado = Crear(n, n);
			int **Corte = Crear(m, k);
			MatrizA = PonerDatos(x, m, n);
			MatrizB = PonerDatos(y, n, k);
			Resultado = PonerDatos(0, n, n);
			Aux1 = MatrizCuadrada(MatrizA, n, n, m, n);
			Aux2 = MatrizCuadrada(MatrizB, n, n, n, k);
			Corte = PonerDatos(0, m, k);
			Resultado = PDyV(Aux1, Aux2, n, n, n1, n);
			//Elimina los ceros contenidos en la matriz resultado
			Corte = EliminarCeros(Resultado, m, k);
			for(int i = 0; i < m; i++){
				cout << "\n";
				for(int j = 0; j < k; j++){	
					cout << Corte[i][j] << " ";
				}
			}
		}
		else{
			if(m > k)
				max = m;
			else{
				max = k;
			}
			int **Aux1 = Crear(max, max);
			int **Aux2 = Crear(max, max);
			int **MatrizA = Crear(m, n);
			int **MatrizB = Crear(k, n);
			int **Resultado = Crear(max, max);
			int **Corte = Crear(m, k);
			MatrizA = PonerDatos(x, m, n);
			MatrizB = PonerDatos(y, n, k);
			Aux1 = MatrizCuadrada(MatrizA, max, max, m, n);
			Aux2 = MatrizCuadrada(MatrizB, max, max, n, k);
			Corte = PonerDatos(0, m, k);
			Resultado = PDyV(Aux1, Aux2, max, max, max, max);
			//Elimina los ceros contenidos en la matriz resultado
			Corte = EliminarCeros(Resultado, m, k);
			for(int i = 0; i < m; i++){
				cout << "\n";
				for(int j = 0; j < k; j++){	
					cout << Corte[i][j] << " ";
				}
			}
		}
	}
}
