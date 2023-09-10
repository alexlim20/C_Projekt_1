#include <stdio.h>
#include <stdlib.h>
struct AnzahlundRest berechneAnzahl(float G, float S);
struct AnzahlundRest
{
    int anzahlEinheit;
    float Rest;
};
int main()
{
    float Summe;
    scanf("%f", &Summe);
    struct AnzahlundRest Geldeinheit[15];
    float Stueckelung[15] = {500.0, 200.0, 100.0, 50.0, 20.0, 10.0, 5.0, 2.0, 1.0, 0.5, 0.2, 0.1, 0.05, 0.02, 0.01};
    int Schein, Muenze = 0;
    for(int i = 0 ; i < sizeof(Stueckelung)/sizeof(Stueckelung[0]) ; i++)
    {
        Geldeinheit[i] = berechneAnzahl(Summe, Stueckelung[i]);
        Summe = Geldeinheit[i].Rest;
        if(i < 9)
        {
            Schein = Schein + Geldeinheit[i].anzahlEinheit*Stueckelung[i];
        }else
        {
            Muenze = Muenze + Geldeinheit[i].anzahlEinheit*Stueckelung[i]*100;
        }
    }
    printf("Der Gesamtbetrag von %d Euro und %d Cent kann aus\n", Schein, Muenze);
    for(int i = 0 ; i < sizeof(Stueckelung)/sizeof(Stueckelung[0]) ; i++)
    {
        if(i < 9)
        {
            printf("%d mal %.0f-Euro-Schein\n", Geldeinheit[i].anzahlEinheit, Stueckelung[i]);
        }else
        {
            printf("%d mal %.0f-Cent-Muenze\n", Geldeinheit[i].anzahlEinheit, Stueckelung[i]*100);
        }
    }
    printf("zusammengesetzt werden.");
}

struct AnzahlundRest berechneAnzahl(float G, float S)
{
    struct AnzahlundRest k;
    if(G/S >= 1)
    {
        k.anzahlEinheit = G/S;
    }else
    {
        k.anzahlEinheit = 0;
    }
    k.Rest = G - k.anzahlEinheit*S;
    return k;
}


