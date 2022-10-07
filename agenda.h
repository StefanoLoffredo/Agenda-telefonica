#ifndef AGENDA_H_
#define AGENDA_H_

#define N 255
#define MAX_CONTATTI 500

typedef char stringa[N];

typedef struct{
	stringa nome;
	stringa cognome;
	stringa cell;
} Anagrafica;
typedef Anagrafica elenco[MAX_CONTATTI];

void creaFile();
void caricamento(elenco dati);
void ricerca(elenco dati);
void stampa(elenco dati);

#endif