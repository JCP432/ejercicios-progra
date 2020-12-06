#include <stdio.h>
#include <stdio.h>
#include <string.h>


typedef struct{
    char Matricula[15];
    int primerparcial;
    int segundoparcial;
    int PIA;
    float Final;
}Evaluacion;

void funcion_captura(Evaluacion *, int *);
int main(){
    FILE *fp;
   int contador_1, i, num_max_struct = 3;
   fp = fopen("/home/radical-ab/Escritorio/Archivos/EvaluacionesConFunciones.csv", "w+");
   Evaluacion Evaluaciones[4];

   for (contador_1 = 0; contador_1 < num_max_struct; contador_1 ++){
          funcion_captura (Evaluaciones, &contador_1);
        
   }

   fprintf(fp, "matrcula, primerparcial, segundoparcial, PIA, Final\n");
   for(i = 0; i < 3; i++){
       Evaluaciones[i].Final = (float) (Evaluaciones[i].primerparcial + Evaluaciones[i].segundoparcial + Evaluaciones[i].PIA) / 3;
       fflush(stdin);
       fprintf(fp, "%s, %d, %d, %d, %.2f\n", Evaluaciones[i].Matricula, Evaluaciones[i].primerparcial, Evaluaciones[i].segundoparcial, Evaluaciones[i].PIA, Evaluaciones[i].Final);
   }

   fclose(fp);
   printf("Archivo guardado");
 return 0;}

 void funcion_captura(Evaluacion A[], int *contador_1){

         printf("\n\talumno %d\n", *contador_1 + 1);
         printf("\nIngrese numero de matricula: ");
         fflush(stdin);
         scanf("%s", A[*contador_1].Matricula);
         printf("\nprimer parcial: ");
         fflush(stdin);
         scanf("%d", &A[*contador_1].primerparcial);
         printf("\nsegundo parcial: ");
         fflush(stdin);
         scanf("%d", &A[*contador_1].segundoparcial);
         printf("\nCalificacion del PIA: ");
         fflush(stdin);
         scanf("%d", &A[*contador_1].PIA);

 }
