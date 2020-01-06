int acum = 1;

void DyV(int inicio, int numero){
    int mitad = (inicio + numero) / 2;
    if(numero != inicio){
        DyV(inicio, mitad);
        DyV(mitad+1, numero);
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
    DyV(inicio, numero);
    cout << acum;
    return 0;
}