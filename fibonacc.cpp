#include <stdio.h>
#include <stdlib.h>

long cache[100];

int cont_cache = 0;
int contador=0;

long fibonacci(int numero){
  contador ++;
    if(numero == 0 || numero == 1){
        return 1;
    }else{
        return fibonacci(numero-1) + fibonacci(numero-2);
    }
}

long f_fibo_cache(long numero){
        
		
		cont_cache ++;
        long valor = cache[numero];
        if (valor <= 0){
                cache[numero] = f_fibo_cache(numero - 1) + f_fibo_cache(numero - 2);
                valor = cache[numero];
        }
        return valor;
}

int main (int no_de_argumentos, char **valores){
        long termino_n = 0;
        cache[0] = 1;
        cache[1] = 1;
        int i;
        for (i = 1; i < no_de_argumentos; i ++){
                termino_n = atoi(valores[i]);
                printf("no. %ld\tfuncion Fibonacci: %ld\n", termino_n, fibonacci(termino_n));
        }
        printf("La funcion fibonacci fue llamada %d veces\n",contador);

        for (i = 1; i < no_de_argumentos; i ++){
                termino_n = atoi(valores[i]);
                printf("no. %ld\t funcion fibonacci Cache: %ld\n", termino_n, f_fibo_cache(termino_n));
        }
        printf("La funcion fibonacci fue llamada %d veces\n",cont_cache);
        return 0;
}

