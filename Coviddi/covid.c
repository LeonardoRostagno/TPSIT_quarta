#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 1000

void apri_file (FILE *ptr_file);
void leggi_stampa_file (FILE *ptr_file);

int main () {
    FILE *ptr_file;

    apri_file (ptr_file);
    leggi_stampa_file (ptr_file);

    fclose(ptr_file);
    return 0;
}

void apri_file (FILE *ptr_file) {
    ptr_file = fopen ("rna.txt", "r");

    if (ptr_file) {
        printf("FILE OK!\n");
    }
    else {
        printf("Errore FILE...\n");
    }
}

void leggi_stampa_file (FILE *ptr_file) {
    int adenina = 0; 
    int citosina = 0; 
    int guanina = 0; 
    int timina = 0; 
    int cont = 0;

    char riga[max];

    //scorre a righe, ogni riga del file 
    while (fgets(riga, max, ptr_file)) { 
        while (riga[cont] = '\0') { //analizzo riga x riga 
            switch (riga[cont])
            {
            case 'a':
                adenina++;
                break;

            case 'c':
                citosina++;
                break;

            case 'g':
                guanina++;
                break;

            case 't':
                timina++;
                break;
            
            default:
                break;
            }
            printf("Alla riga %d -->\n\tadenina: %d\n\tcitosina: %d\n\tguanina: %d\n\ttimina: %d\n", cont, adenina, citosina, guanina, timina);
            cont++;
        }
    }
    printf("In totale -->\n\tadenina: %d\n\tcitosina: %d\n\tguanina: %d\n\ttimina: %d\n", adenina, citosina, guanina, timina);
}