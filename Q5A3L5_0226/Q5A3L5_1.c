#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    FILE *fp;
    char ch;
    char fnev[50];
    printf("Filenev: "); //A felhasználótól bekérünk egy fájlnevet (fnev).
    scanf("%s", fnev); //Fájlnév bekérése -egy szóként olvassa be a fájlnevet

    fp = fopen(fnev, "w"); //A fájl megnyitása írásra
    printf("Uzenet: "); //A program beolvassa a karaktereket és a beírja a fájlba

    while( (ch = getchar())  != '#') {
        putc{ch, fp};
    }                  // A user a # írbe, majd vége
    fclose(fp);

    fp = fopen(fnev, "r");  // A fájlt újra megnyitjuk olvasásra
    while ( (ch = getc(fp))  != EOF ) {
        printf("%c", toupper(ch)); // Nagybetűre alakítjuk, kiírjuk a képernyőre.
    }
    fclose(fp);

    char nev2[50] = "atmeneti"; // létrehozunk egy ideiglenes fájlt, a módosított tartalmat kiír
    FILE *fpp = fopen(nev2, "w"); // A módosított tartalmat kiírjuk a képernyőre

    fp = fopen(fnev, "r");  //Megnyitjuk a fájlt olvasásra
    fseek(fp, 0L, SEEK_END);  //Megkeressük a fájl végét
    int pos = ftell(fp);  //Lekérdezzük a pozíciót (ftell (fp)), ami a fájl méretét adja meg
    fseek(fp, 0L, SEEK_SET);   //Visszaugrunk a fájl elejére (SEEK_SET).

    while(pos--)
    {
        ch = fgetc(fp);  //Végigmegyünk a fájl minden karakterén 
        fputc(toupper(ch), fpp);  //Azokat nagybetűvel írjuk az ideiglenes fájlba.
    }

    fclose(fp);    // Mindkét fájlt bezárjuk
    fclose(fpp);

    remove(fnev);  // Az eredeti fájlt töröljük

    rename(nev2, fnev);  // Az ideiglenes fájlt átnevezzük az eredeti fájl nevére

    return 0;
}