#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 200
#define OVER 100000000

typedef struct tipo {
    char data[MAX]; // data di aggiornamento
    char stato[MAX]; // stato
    int cod_reg; // codice regionale
    char nome_reg[MAX]; // denominazione regionale
    float lat; // latitudine
    float longi; // longitudine
    int ricoverati; // ricoverati con sintomi
    int terapia_int; // terapia intensiva
    int tot_osped; // totale ospedalizzati
    int isolamento; // isolamento domiciliare
    int tot_pos; // totale positivi
    int var_tot_pos; // variazione totale positivi
    int new_pos; // nuovi positivi
    int dim_guar; // dimessi guariti
    int dec; // deceduti
    int casi_sosp; // casi da sospetto diagnostico
    int casi_screen; // casi da screening
    int tot_casi; // totale casi 
    int tamp; // tamponi 
    int casi_test; // casi testati
} Regione;

// funzione per una semplificazione visiva da terminale
void spazia () {

    for (size_t a = 0; a < 50; a++) {
        printf("-");
    }
    printf("\n\n");
}

int leggi (FILE *ptr_file, Regione *regione); // funzione per la lettura nel file
void stampa (Regione *regione, int count); //funzione per la stampa del file
void top_reg_terapia_int (Regione *regione, int count); // funzione per la top 3 regioni con + terapia intensiva
void top_reg_meno_pos(Regione *regione, int count); // funzione per la top 3 regioni con - casi positivi
void tot_ricov (Regione *regione, int count); // funzione per il calcolo del totale dei ricoverati in terapia intensiva

int main () {
    FILE *ptr_file;
    Regione *regione;
    
    int scelta = 0; // usato per lo switch
    
    char cicla[MAX]; //usato per la malloc di regione
    int cont = 0; // usato per la malloc di regione

    ptr_file = fopen ("contagio.csv", "rt");

    if (ptr_file) {
        printf("FILE OK...\n");
    }
    else {
        printf("Errore FILE...\n");
    }

    spazia();

    // ciclo che conta il numero di righe del file, usato per la malloc di regione
    while (fgets(cicla, MAX, ptr_file)) {
        cont++;
    } 
    regione = (Regione*) malloc ((cont - 1) * sizeof(Regione)); // allocamento dinamico in memoria di regione

    ptr_file = fopen ("contagio.csv", "rt"); // riapro il file perchè nel ciclo per la malloc il puntatore era arrivato al fondo

    int count = leggi(ptr_file, regione);
    spazia();

    do {
        printf ("Prego inserire l'operazione desiderata\n\t"
                "1 -> Stampa\n\t"
                "2 -> Top 3 regioni con piu' ricoverati in terapia intensiva\n\t"
                "3 -> Top 3 regioni con meno casi positivi\n\t"
                "4 -> Totale ricoverati in terapia intensiva\n\t"
                "5 -> Exit\n");
        scanf ("%d", &scelta);
        
        spazia();

        switch (scelta)
        {
        case 1: // stampa
            printf("Stampa...\n");

            stampa(regione, count);
            spazia();
            break;
        
        case 2: // Top 3 regioni con piu' ricoverati in terapia intensiva
            printf("Calcolo...\n");

            top_reg_terapia_int(regione, count);
            spazia();
            break;
        
        case 3: // Top 3 regioni con meno casi positivi
            printf("Calcolo...\n");

            top_reg_meno_pos(regione, count);
            spazia();
            break;

        case 4: // totale ricoverati in terapia intensiva
            printf("Calcolo...\n");

            tot_ricov (regione, count);
            spazia();
            break;
            
        case 5: // terminazione del programma
            printf("Exit...");
            break;

        default:
            break;
        }
    } while (scelta != 5);

    free(regione);
    fclose (ptr_file);
    return 0;
}

int leggi (FILE *ptr_file, Regione *regione){

    int count = 0;
    char riga[MAX]; // array usato per strtok
    char delimitatore[] = ","; // delimitatore del file csv, usato per strtok
    char *token; //token usato per strtok
    char first_line[MAX]; //array usato per contenere la prima riga del file
    
    fgets(first_line, MAX, ptr_file); // "salto" la prima riga del file, perchè non ci interessa

    // il ciclo scorre riga per riga tutto il file 
    while (fgets(riga, MAX, ptr_file)) {
        token = strtok(riga, delimitatore);         
        strcpy((regione + count)->data, token); //inserisco il valore letto dalla riga precedente in (regione + count)->data
        printf("Data -> %s\n", (regione + count)->data);

        token = strtok(NULL, delimitatore);
        strcpy((regione + count)->stato, token); //inserisco il valore letto dalla riga precedente in (regione + count)->stato
        printf("Stato -> %s\n", (regione + count)->stato);

        token = strtok(NULL, delimitatore);
        (regione + count)->cod_reg = atoi(token); //inserisco il valore letto dalla riga precedente in (regione + count)->cod_reg
        printf("Codice regione -> %d\n", (regione + count)->cod_reg);

        token = strtok(NULL, delimitatore);
        strcpy((regione + count)->nome_reg, token); //inserisco il valore letto dalla riga precedente in (regione + count)->nome_reg
        printf("Nome regione -> %s\n", (regione + count)->nome_reg);

        token = strtok(NULL, delimitatore);
        (regione + count)->lat = atof(token); //inserisco il valore letto dalla riga precedente in (regione + count)->lat
        printf("Latitudine -> %f\n", (regione + count)->lat);

        token = strtok(NULL, delimitatore);
        (regione + count)->longi = atof(token); //inserisco il valore letto dalla riga precedente in (regione + count)->longi
        printf("Longitudine -> %f\n", (regione + count)->longi);

        token = strtok(NULL, delimitatore);
        (regione + count)->ricoverati = atoi(token); //inserisco il valore letto dalla riga precedente in (regione + count)->ricoverati
        printf("Ricoverati -> %d\n", (regione + count)->ricoverati);

        token = strtok(NULL, delimitatore);
        (regione + count)->terapia_int = atoi(token); //inserisco il valore letto dalla riga precedente in (regione + count)->terapia_int
        printf("Terapia intensiva -> %d\n", (regione + count)->terapia_int);

        token = strtok(NULL, delimitatore);
        (regione + count)->tot_osped = atoi(token); //inserisco il valore letto dalla riga precedente in (regione + count)->tot_osped
        printf("Totale ospedalizzati -> %d\n", (regione + count)->tot_osped);

        token = strtok(NULL, delimitatore);
        (regione + count)->isolamento = atoi(token); //inserisco il valore letto dalla riga precedente in (regione + count)->isolamento
        printf("Isolamento -> %d\n", (regione + count)->isolamento);

        token = strtok(NULL, delimitatore);
        (regione + count)->tot_pos = atoi(token); //inserisco il valore letto dalla riga precedente in (regione + count)->tot_pos
        printf("Totale positivi -> %d\n", (regione + count)->tot_pos);

        token = strtok(NULL, delimitatore);
        (regione + count)->var_tot_pos = atoi(token); //inserisco il valore letto dalla riga precedente in (regione + count)->var_tot_pos
        printf("Variazione totale positivi -> %d\n", (regione + count)->var_tot_pos);

        token = strtok(NULL, delimitatore);
        (regione + count)->new_pos = atoi(token); //inserisco il valore letto dalla riga precedente in (regione + count)->new_pos
        printf("Nuovi positivi -> %d\n", (regione + count)->new_pos);

        token = strtok(NULL, delimitatore);
        (regione + count)->dim_guar = atoi(token); //inserisco il valore letto dalla riga precedente in (regione + count)->dim_guar
        printf("Dimessi Guariti -> %d\n", (regione + count)->dim_guar);

        token = strtok(NULL, delimitatore);
        (regione + count)->dec = atoi(token); //inserisco il valore letto dalla riga precedente in (regione + count)->dec 
        printf("Deceduti -> %d\n", (regione + count)->dec);   

        token = strtok(NULL, delimitatore);
        (regione + count)->casi_sosp = atoi(token); //inserisco il valore letto dalla riga precedente in (regione + count)->casi_sosp
        printf("Casi sospetti -> %d\n", (regione + count)->casi_sosp);

        token = strtok(NULL, delimitatore);
        (regione + count)->casi_screen = atoi(token); //inserisco il valore letto dalla riga precedente in (regione + count)->casi_screen
        printf("Casi da screening -> %d\n", (regione + count)->casi_screen);

        token = strtok(NULL, delimitatore);
        (regione + count)->tot_casi = atoi(token); //inserisco il valore letto dalla riga precedente in (regione + count)->tot_casi
        printf("Totale casi -> %d\n", (regione + count)->tot_casi);

        token = strtok(NULL, delimitatore);
        (regione + count)->tamp = atoi(token); //inserisco il valore letto dalla riga precedente in (regione + count)->tamp
        printf("Tamponi -> %d\n", (regione + count)->tamp);

        token = strtok(NULL, delimitatore);
        (regione + count)->casi_test = atoi(token); //inserisco il valore letto dalla riga precedente in (regione + count)->casi_test
        printf("Casi testati -> %d\n\n", (regione + count)->casi_test);

        count++; // aggiorno di 1 il contatore 
    }

    printf("Lettura FILE completata...\n");

    return count;
}

void stampa (Regione *regione, int count) {
    // ciclo per la stampa del file per regioni
    for (size_t a = 0; a < count; a++) {
        printf("%s - %s - %s\n", (regione + a)->stato, (regione + a)->nome_reg, (regione + a)->data);
        printf("Nuovi positivi -> %d\nTotale positivi -> %d\nVariazione positivi -> %d\nTamponi effettutati -> %d\n\n", (regione + a)->new_pos, (regione + a)->tot_pos, (regione + a)->var_tot_pos, (regione + a)->tamp);
        printf("Dimessi guariti -> %d\nDeceduti -> %d\n\n", (regione + a)->dim_guar, (regione + a)->dec);
        printf("Ricoverati -> %d\nTerapia intensiva -> %d\nTotale ospedalizzati -> %d\nIsolamento domiciliare -> %d\n", (regione + a)->ricoverati, (regione + a)->terapia_int, (regione + a)->tot_osped, (regione + a)->isolamento);
        printf("Casi da sospetto diagnostico -> %d\nCasi da screening -> %d\nCasi testati -> %d\nCasi totali -> %d\n\n\n", (regione + a)->casi_sosp, (regione + a)->casi_screen, (regione + a)->casi_test, (regione + a)->tot_casi);
    }

    printf("Stampa FILE completata...\n");
}

void top_reg_terapia_int (Regione *regione, int count) {
    int p1 = 0; // numero in terapia della 1°
    int p2 = 0; // numero in terapia della 2°
    int p3 = 0; // numero in terapia della 3°
    char *nome1; // nome della 1°
    char *nome2; // nome della 2°
    char *nome3; // nome della 3°
    int co = 0;

    // ciclo in cui scorro ogni singola regione
    for (size_t b = 0; b < count; b++) {
        if ((regione + b)->terapia_int > p3) { // se il numero di terapia intensiva della regione è > di p3 continuo

            if ((regione + b)->terapia_int > p2) { // se il numero di terapia intensiva della regione è > di p2 continuo altrimenti salvo

                if ((regione + b)->terapia_int > p1) { // se il numero di terapia intensiva della regione è > di p1 salvo 
                    p1 = (regione + b)->terapia_int; // salvo il numero di terapia intensiva della regione 
                    nome1 = (regione + b)->nome_reg; // salvo il nome della regione
                }
                else {
                    p2 = (regione + b)->terapia_int; // salvo il numero di terapia intensiva della regione 
                    nome2 = (regione + b)->nome_reg; // salvo il nome della regione
                }
            }
            else {
                p3 = (regione + b)->terapia_int; // salvo il numero di terapia intensiva della regione 
                nome3 = (regione + b)->nome_reg; // salvo il nome della regione 
            }
        }
        co++;
    }
    printf("Posizione 1 - %s -> %d\n", *nome1, p1); // stampo a video la 1°
    printf("Posizione 2 - %s -> %d\n", *nome2, p2); // stampo a video la 2°
    printf("Posizione 3 - %s -> %d\n", *nome3, p3); // stampo a video la 3°

    printf("Top 3 regioni terapia intensiva completata...\n");
}

void top_reg_meno_pos(Regione *regione, int count) {
    int p1 = OVER; //numero positivi della 1°
    int p2 = OVER; //numero positivi della 2°
    int p3 = OVER; //numero positivi della 3°

    char *nome1; //nome della 1°
    char *nome2; //nome della 2°
    char *nome3; //nome della 3°

    // ciclo che scorro ogni singolo regione
    for (size_t c = 0; c < count; c++) {
        if ((regione + c)->tot_pos < p3) { //se il numero di positivi della regione è < di p3 continuo

            if ((regione + c)->tot_pos < p2) { //se il numero di positivi della regione è < di p2 continuo altrimenti salvo

                if ((regione + c)->tot_pos < p1) { //se il numero di positivi della regione è < di p1 salvo
                    p1 = (regione + c)->tot_pos; // salvo il numero di positivi della regione
                    nome1 = (regione + c)->nome_reg; // salvo il nome della regione
                }
                else {
                    p2 = (regione + c)->tot_pos; // salvo il numero di positivi della regione
                    nome2 = (regione + c)->nome_reg; // salvo il nome della regione
                }
            }
            else {
                p3 = (regione + c)->tot_pos; // salvo il numero di positivi della regione
                nome3 = (regione + c)->nome_reg; // salvo il nome della regione
            }
        }
    }
    printf("Posizione 1 - %s -> %d\n", *nome1, p1); // stampo a video la 1°
    printf("Posizione 2 - %s -> %d\n", *nome2, p2); // stampo a video la 2°
    printf("Posizione 3 - %s -> %d\n", *nome3, p3); // stampo a video la 3°

    printf("Top 3 regioni con meno positivi completata...\n");
}

void tot_ricov (Regione *regione, int count) {
    int somma = 0;

    // ciclo che scorre tutte le regioni
    for (size_t d = 0; d < count; d++) {
        somma = somma + (regione + d)->terapia_int; // sommo al valore precedente di somma il numero di terapia intensiva della regione
    }

    printf("In totale ci sono %d persone in terapia intensiva\n\n", somma);

    printf("Somma di tutti le persone in terapia intensiva completato...\n");
}