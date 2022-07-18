#include "agenda.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void creaFile()
{
	FILE *f;
	
	f = fopen("agenda.txt", "a+");				
	
	if(f == NULL)								                                //Se non trova il file, lo crea e si mette in modalita' scrittura
	{
		f = fopen("agenda.txt", "w");
		if (f == NULL)
			printf("Errore nell' apertura del file.\n");
	}
	else
	{
		fclose(f);
	}
}

void caricamento(elenco dati)
{
	int contatti, i;
	
	FILE *f;
	
	f = fopen("agenda.txt", "a+");                                              //Modalita a+ sta per "append" (inserisce in fondo al file)
	if(f == NULL)  
	{
		printf("File non trovato, uscita...\n");
	}
	 
	else 
	{
		printf("Quanti contatti vuoi inserire?\n");
		scanf("%d", &contatti);
		
		for(i=0; i < contatti; i++)
		{
			printf("Nome: ");
			scanf("%s", dati[i].nome);											// Prendo in input nome, cognome e cellulare del contatto
			fprintf(f, "%s ", dati[i].nome);								    // e li inserisco sul file con la funzione fprintf
			printf("\n");
			
			printf("Cognome: ");
			scanf("%s", dati[i].cognome);
			fprintf(f, "%s ", dati[i].cognome);
			printf("\n");
			
			printf("Cellulare: ");
			scanf("%s", dati[i].cell);
			fprintf(f, "%s ", dati[i].cell);
			fprintf(f, "\n");
			printf("\n\n");
		}
		fclose(f);
	}
	
	contatti_totali = contatti_totali + contatti;
}

void ricerca(elenco dati)
{
	
	stringa nome;
	int found = 0, i;
	
	FILE *f;
	
	f = fopen("agenda.txt", "r+"); 
	if(f == NULL) 
	{
		printf("File non trovato, uscita...\n");
	}
	
	else 
	{

		printf("Inserisci il nome del contatto da cercare: ");
		scanf("%s", nome);
		for (i = 0; i < MAX_CONTATTI; i++) {
			fscanf(f, "%s", dati[i].nome);
			if (strcmp(nome, dati[i].nome) == 0) {
			    fscanf(f, "%s", dati[i].cognome);
			    fscanf(f, "%s", dati[i].cell);
				printf("Nome: %s \nCognome: %s \nCellulare: %s \n\n\n", dati[i].nome, dati[i].cognome, dati[i].cell);
				
				found = 1;
			}
		}
		
		if (!found)
		{
		    printf("Nessun contatto trovato.\n\n\n");
		}
		
		fclose(f);	
	}	
}

void stampa(elenco dati)
{
    
    int i = 0;
    FILE *f;
    char end;
	
	f = fopen("agenda.txt", "r");
	if(f == NULL) 
	{
		printf("File non trovato, uscita...\n");
	}
	
	else
	{
	    printf("**********LISTA CONTATTI**********\n\n");
	    printf("NOME     COGNOME     CELLULARE\n");
	    
	    do {
	        
	        fscanf(f, "%s", dati[i].nome);
	        fscanf(f, "%s", dati[i].cognome);
	        fscanf(f, "%s", dati[i].cell);
	        
	        printf("%s     %s     %s\n", dati[i].nome, dati[i].cognome, dati[i].cell);
	        
	        end = fgetc(f);
	        i++;
	        
	    } while(end != EOF);
	    
	    fclose(f);
	}
    
}

