
	public class Ordenamiento {    
	static long acum = 1;	
    public static void main(String[] args) throws Exception{
        long inicio = System.nanoTime();
		int tam;                                                                //tamaño del arreglo
        int n = 5;                                                              //numero de divisiones
        int arr[] = {1,2,3,4,5,6,7,8,9,10};
        System.out.println("Número de divisiones: " + n);
        merge(arr, n);                                                          //Ordena arreglo
        System.out.println("El Resultado es: "+acum);
		long fin = System.nanoTime();
		double diferencia = (double) (fin - inicio) * 1.0e-9;
		System.out.println("El programa dura: "+ diferencia + "s");
    }
    
    public static void merge(int[] arr, int n){
        if(arr.length >= n){                                                    //mientras no se llegue a un caso base (n-1, n-2, ... , 1)
            int t = (arr.length / n);                                           //numero de elementos dentro de cada nuevo arreglo
            int[][] arrX = new int[n][];                                        //matriz que va a contener las el arreglo dividido en n partes
            for(int i = 0; i < n-1; i++){                                       //crea n-1 arreglos de tamaño n
                arrX[i] = new int[t];
            }
            arrX[n-1] = new int[t + (arr.length % n)];                          //arreglo final que contiene los elementos restantes
            int inicio = 0;                                                     //para saber donde se empezará a copiar el arreglo
            int off = 0;                                                        //para saber hasta que elemento se va a copiar
            for(int q = 0; q < n - 1; q++){                                     //para llenar los arreglos del 0 al n-2
                    off += t;                                                   //para copiar hasta off + t
                    int j = 0;                                                  //indice para escribir en el nuevo arreglo
                    for(int i = inicio; i < off; i++){                          //copia los elementos del arreglo original hacia el que le corresponde en la matriz
                        arrX[q][j] = arr[i];
                        j++;
                    }
					merge(arrX[q], n);
                    inicio += t;                                                //Para iniciar la sig iteracion copiando desde inicio + t
            }
            int j = 0;                                                          //indice para escribir en el nuevo arreglo
			for(int i = inicio; i < arr.length; i++){                           //copia los elementos del arreglo original hacia el último arreglo de la matriz
				arrX[n-1][j] = arr[i];
				j++;
            }
			merge(arrX[n-1], n);
		}
        else{                                                                   //si se llega a un caso base (n-1, n-2, ... , 1)
            int[][] arrX = new int[arr.length][1];                              //Se crea una matriz de arreglos de tamaño 1
            for(int i = 0; i < arr.length; i++){                                //Se llena la matriz con los elementos del arreglo original
                arrX[i][0] = arr[i];
				acum *= arrX[i][0];
            }
        }
    }
}