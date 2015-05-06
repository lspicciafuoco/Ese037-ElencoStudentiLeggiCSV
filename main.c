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
    studente a;
    int i;
    FILE *puntaFile;
    char elenco[MAX_FNAMELEN+1];
    
    // Codice per la richiesta del nome del file
    printf("Inserisci il nome del file da cui leggere i dati: ");
    scanf("%s", elenco);
    
    // Codice per l'apertura del file, la lettura e la stampa a schermo
    puntaFile = fopen(elenco, "r");
    if(puntaFile == NULL) {
        fprintf(stderr, "ERRORE: Impossibile aprire il file %s", elenco);
        exit(1);
    }
    
       
    // La prima riga contiene l'instestazione: la leggo e non ne faccio nulla
    fscanf(puntaFile, "%[^;];%[^;];%[^;];%[^;\n]\n", a.nome, a.cognome, a.nome, a.classe);
    
    i=0;
    fscanf(puntaFile, "%[^;];%[^;];%d;%[^;\n]\n", a.nome, a.cognome, &(a.eta), a.classe);
    while(!feof(puntaFile)) {
        i++;
        printf("Studente %d\nNome: %s\nCognome: %s\nEta': %d\nClasse: %s\n\n", i, a.nome, a.cognome, a.eta, a.classe);
        fscanf(puntaFile, "%[^;];%[^;];%d;%[^;\n]\n", a.nome, a.cognome, &(a.eta), a.classe);
    }
    fclose(puntaFile);
    
    return (EXIT_SUCCESS);
}

