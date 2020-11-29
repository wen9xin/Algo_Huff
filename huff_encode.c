
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
        /* A COMPLETER */
        fap file=creer_fap_vide();
        for(int i =0; i<256; i++) {
                Arbre k;
                k=NouveauNoeud(NULL,i,NULL);
                //    k->etiq=i;
                inserer(file,k,TableOcc->tab[i]);
        }
          printf("Programme realise (InitHuffman)\n");
        return file;
}

Arbre ConstruireArbre(fap file) {
        Arbre x,y,z,res;
        int xp,yp,zp,resp;
        fap backup = file;
        int len;
        while(file->prochain != NULL){
            file = file->prochain;
            len++;
        }
        file = backup;
        if(est_fap_vide(file)){
          len = 0;
        }
      //      printf("Nombre total de caracteres differents : %d\n", len+1);
        for(int i=1; i< len; i++) {
                x=NouveauNoeud(ArbreVide(),0,ArbreVide());
                y=NouveauNoeud(ArbreVide(),0,ArbreVide());
                xp=0;yp=0;
                file=extraire(file,&x,&xp);
                file=extraire(file,&y,&yp);
                z=NouveauNoeud(x,0,y);
                zp=xp+yp;
                file=inserer(file,z,zp);
                printf("inserer (%d)\n", zp);
        }
      //  printf("(ConstruireArbre72)\n");
         res = NouveauNoeud(NULL, 0, NULL);
        resp = 0;
        file = extraire(file, &res, &resp);
        if(!est_fap_vide(file)){
          printf("Erreur ConstruireArbre()\n");
        }
        else printf("ConstruireArbre() executed.\n");
       printf("Programme realise (ConstruireArbre)\n");
        return res;
}
/*

Arbre ConstruireArbre(fap file) {
    int length = getLength(file)-1;
    printf("Nombre total de caracteres differents : %d\n", length+1);

    for(int i=0; i<length; i++){
        Arbre x = NouveauNoeud(NULL, 0, NULL);
        int xPrio = 0;
        Arbre y = NouveauNoeud(NULL, 0, NULL);
        int yPrio = 0;
        file = extraire(file, &x, &xPrio);
        file = extraire(file, &y, &yPrio);
        printf("x = %c, y = %c, xPrio = %d, yPrio = %d ; ", x->etiq, y->etiq, xPrio, yPrio);
        Arbre z = NouveauNoeud(x, 0, y);
        int zPrio = xPrio + yPrio;
        file = inserer(file, z, zPrio);
        printf("Inserted (%d)\n", zPrio);
    }

    Arbre res = NouveauNoeud(NULL, 0, NULL);
    int resPrio = 0;
    file = extraire(file, &res, &resPrio);
    if(!est_fap_vide(file)) perror("Error Occured At ConstruireArbre()");
    else printf("ConstruireArbre() executed.\n");

    return res;
}
*/

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
