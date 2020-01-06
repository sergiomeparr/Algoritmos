#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int acum = 1;

void DyV(int inicio, int numero, int divisiones){
    if(numero != inicio){
		int particion = numero / divisiones;
		
		do{
			DyV(inicio, particion, divisiones);
			inicio += particion;
			particion += particion;
		}
	}
    if(numero == inicio){
        acum *= numero;
    }
}

int main(){
    int divisiones, numero, inicio = 1;    
    cout << "ingresa un numero: ";
    cin >> numero;
    cout << "\nIngresa divisiones: ";
    cin >> divisiones;
    DyV(inicio, numero, divisiones);
    cout << acum;
    return 0;
}
