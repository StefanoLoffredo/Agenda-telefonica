#include <stdio.h>
#include <stdlib.h>
#include "agenda.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	
	int menu;
	elenco dati;

	
	creaFile();
	
	printf("Benvenuto nella rubrica. \n\n");
	
	do {
		printf("+------------------------+\n");
		printf("|     Cosa vuoi fare?    |\n");
		printf("+------------------------+\n");
		printf("| 1) Caricamento         |\n");
		printf("| 2) Ricerca             |\n");
		printf("| 3) Visualizza rubrica  |\n");
		printf("| 4) Esci                |\n");
		printf("+------------------------+\n");
		printf(">");
		
		scanf("%d", &menu);
	
			switch (menu) {
				case 1:
					caricamento(dati);
					break;
				
				case 2:
					ricerca(dati);
					break;
					
				case 3:
				    stampa(dati);
					break;
					
				case 4:
					printf("Uscita...\n");
					break;
			}
	} while (menu != 4);

	
	return 0;
}