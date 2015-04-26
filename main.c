#include <stdio.h>
#include <stdlib.h>

// Definisci le costanti
#define MAX_STRLEN 30

// Definisci il tipo di dato struct s_studente
struct s_studente {
    char nome [MAX_STRLEN +1];
    char cognome [MAX_STRLEN +1];
    unsigned int eta;
    char classe [MAX_STRLEN +1];
};

// Definisci studente come struct s_studente
struct s_studente studente;


int main(int argc, char** argv) {
    // Dichiara le variabili locali
    FILE *puntaFile;
    char nomeFile [MAX_STRLEN +1];
    
    // Codice per la richiesta del nome del file
    printf("Inserisci il nome del file che vuoi aprire in lettura: ");
    scanf("%s", nomeFile);
    
    // Codice per l'apertura del file, la lettura e la stampa a schermo
    puntaFile = fopen(nomeFile,"rb");
    if(puntaFile == NULL) {
        printf("Non sono riuscito ad aprire il file");
    }
    
    fread(&studente,sizeof(studente),1,puntaFile);
    while(!feof(puntaFile)){
        printf("%s; %s; %d; %s; \n", studente.nome, studente.cognome, studente.eta, studente.classe);
        fread(&studente,sizeof(studente),1,puntaFile);
    }
    
    
    return (EXIT_SUCCESS);
}