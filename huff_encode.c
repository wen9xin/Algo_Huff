
#include "arbrebin.h"
#include "bfile.h"
#include "fap.h"
#include "huffman_code.h"
#include <assert.h>
#include <stdio.h>

typedef struct {
        int tab[256];
} TableOcc_t;

struct code_char HuffmanCode[256];

void ConstruireTableOcc(FILE *fichier, TableOcc_t *TableOcc) {

        int c;

        /* A COMPLETER ... */
        for(int i =0; i<256; i++) {
                TableOcc->tab[i]=0;
        }

        //printf("Programme non realise (ConstruireTableOcc)\n");

        c = fgetc(fichier);
        while (c != EOF) {
                /* A COMPLETER ... */
                TableOcc->tab[c]++;
                c = fgetc(fichier);
        };


        int i;
        for (i = 0; i < 256; i++) {
                if (TableOcc->tab[i] != 0)
                        printf("Occurences du caractere %c (code %d) : %d\n", i, i,
                               TableOcc->tab[i]);
        }
}

fap InitHuffman(TableOcc_t *TableOcc) {
    int i;
    Arbre z;
    fap F = creer_fap_vide();

    for(i=0; i<256; i++){
        z = NouveauNoeud(ArbreVide(), i, ArbreVide());
        F = inserer(F, z, TableOcc->tab[i]);
    }
    printf("Programme non realise (InitHuffman)\n");
    return F;

    //return NULL;
}

Arbre ConstruireArbre(fap file) {
    int i;
    int p1 = 0, p2 = 0;
    int xp = 0, yp = 0;
    Arbre x, y, z;
    Arbre a, b;

    for (i = 0; i < 254; i++){

        x = NouveauNoeud(ArbreVide(), 0, ArbreVide());
        y = NouveauNoeud(ArbreVide(), 0, ArbreVide());
        z = NouveauNoeud(ArbreVide(), 0, ArbreVide());

        x = file->element; xp = file->priorite;
        file = extraire(file, &a, &p1);
        y = file->element; yp = file->priorite;
        file = extraire(file, &b, &p2);
        z = NouveauNoeud(x, Etiq(z), y);
        inserer(file, z, (xp + yp));
    }
    return z;
}

void ConstruireCode(Arbre huff) {
        /* A COMPLETER */


        printf("Programme non realise (ConstruireCode)\n");
}

void Encoder(FILE *fic_in, FILE *fic_out, Arbre ArbreHuffman) {
        /* A COMPLETER */

        printf("Programme non realise (Encoder)\n");
}

int main(int argc, char *argv[]) {

        TableOcc_t TableOcc;
        FILE *fichier;
        FILE *fichier_encode;

        fichier = fopen(argv[1], "r");
        /* Construire la table d'occurences */
        ConstruireTableOcc(fichier, &TableOcc);
        fclose(fichier);

        /* Initialiser la FAP */
        fap file = InitHuffman(&TableOcc);

        /* Construire l'arbre d'Huffman */
        Arbre ArbreHuffman = ConstruireArbre(file);

        AfficherArbre(ArbreHuffman);

        /* Construire la table de codage */
        ConstruireCode(ArbreHuffman);

        /* Encodage */
        fichier = fopen(argv[1], "r");
        fichier_encode = fopen(argv[2], "w");

        Encoder(fichier, fichier_encode, ArbreHuffman);

        fclose(fichier_encode);
        fclose(fichier);

        return 0;
}
