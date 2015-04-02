#include <stdio.h>
#include <stdlib.h>

// Definisci le costanti
#define MAX_STRLEN 30
#define MAX_FNAMELEN 255

// Definisci il tipo di dato struct s_studente
struct s_studente {
    char nome[MAX_STRLEN+1];
    char cognome[MAX_STRLEN+1];
    int eta;
    char classe[MAX_STRLEN+1];
};

// Definisci studente come struct s_studente
typedef struct s_studente studente;


int main(int argc, char** argv) {
    // Dichiara le variabili locali
    studente s;
    FILE *inf;
    char fileName[MAX_FNAMELEN+1];    
    
    // Codice per la richiesta del nome del file
    printf("Inserisci il nome del file da cui leggere i dati: ");
    scanf("%s", fileName);
    
    // Codice per l'apertura del file, la lettura e la stampa a schermo
    inf = fopen(fileName, "rb");
    if(inf == NULL) {
        fprintf(stderr, "ERRORE: Impossibile aprire il file %s in lettura\n", fileName);
        exit(1);
    }
    
    fread(&s, sizeof(studente), 1, inf);
    while(!feof(inf)) {
        printf("%s; %s; %d; %s\n", 
                s.nome,
                s.cognome,
                s.eta,
                s.classe);
        fread(&s, sizeof(studente), 1, inf);
    }
    fclose(inf);
    
    return (EXIT_SUCCESS);
}