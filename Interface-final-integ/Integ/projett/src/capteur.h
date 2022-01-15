#include <gtk/gtk.h>

typedef struct
{
    int jour;
    int mois;
    int annee;
}creation;

typedef struct
{
    char id[20];
    creation date_creation;
    char type[20];
    char valeur[20];
    char marque[20];
}Capteur;


void  ajouter_capteur(Capteur c);
void afficher_capteur(GtkWidget *liste);
void supprimer_capteur(Capteur c, char id[],char type[]);
void modifier_capteur(Capteur r, char id[]);
void chercher_capteur_supp(Capteur c, char id[20],char type[20],int *ok);
void afficher_capteurModif(GtkWidget *liste);
void afficher_capteur_alarmant(GtkWidget *liste);
int nbre_alarmants(float max1, float min1, float max2, float min2);
