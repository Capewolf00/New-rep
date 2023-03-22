#include <stdio.h>
#include "drone.h"

int main(){
struct drone d1, d2;
char A[30], x; // A buffer per memorizzare i nomi, x per leggere le operazioni
float a, o, q; // queste sono le 3 coordinate per la posizione dei droni
printf("scrivi le informazioni sul primo drone:\n");
printf("nome del drone: ");
scanf("%s", A);
printf("ascissa iniziale del drone: ");
scanf("%f", &a);
printf("ordinata iniziale del drone: ");
scanf("%f", &o);
printf("quota iniziale del drone: ");
scanf("%f", &q);
d1 = nuovo_drone(A, a, o, q);
printf("scrivi le informazioni sul secondo drone:\n");
printf("nome del drone: ");
scanf("%s", A);
printf("ascissa iniziale del drone: ");
scanf("%f", &a);
printf("ordinata iniziale del drone: ");
scanf("%f", &o);
printf("quota iniziale del drone: ");
scanf("%f", &q);
d2 = nuovo_drone(A, a, o, q);
printf("operazioni possibili: p = stampa informazioni sui droni;\n");
printf("1 = aggiornamento della posizione del primo drone;\n");
printf("2 = aggiornamento della posizione del secondo drone;\n");
printf("e = uscita dal programma.\n");
printf("scrivi l’operazione che vuoi fare: ");
while (isspace(x = getchar()));
while (x != 'e') {
switch (x) {
case 'p':
nome_drone(d1, A);
printf("nome drone: %s\n", A);
printf("ascissa del drone: %f\n", ascissa(&d1));
printf("ordinata del drone: %f\n", ordinata(&d1));
printf("quota del drone: %f\n", quota(&d1));
printf("=========================\n");
nome_drone(d2, A);
printf("nome drone: %s\n", A);
printf("ascissa del drone: %f\n", ascissa(&d2));
printf("ordinata del drone: %f\n", ordinata(&d2));
printf("quota del drone: %f\n", quota(&d2));
break;
case '1':
printf("scrivi la nuove coordinate del primo drone: ");
scanf("%f %f %f", &a, &o, &q);
update_position(&d1, a, o, q);
if (distanza(&d1, &d2) < 100) printf("RISCHIO COLLISIONE!\n");
break;
case '2':
printf("scrivi la nuove coordinate del secondo drone: ");
scanf("%f %f %f", &a, &o, &q);
update_position(&d2, a, o, q);
if (distanza(&d1, &d2) < 100) printf("RISCHIO COLLISIONE!\n");
break;
default: break;
}
printf("scrivi la prossima operazione: ");
while(isspace(x = getchar()));
}
return 0;
}
