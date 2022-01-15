#include<gtk/gtk.h>
typedef struct
{
int jour;
int mois;
int annee;
}DATE;
typedef struct {
char type[20];
char sexe[20];
char identifiant[20];
int poids;
int taille;
int id;
DATE date;
}ANIMAL;

typedef struct {
ANIMAL animal;
char age[30];

char nombre[30];
int lait ;
int laine;
//char identif[20];faux
}
Production;


void ajouter_animal(ANIMAL a);
void liste_animaux(GtkWidget *liste);
void supprimer_animal(ANIMAL a,char identifiant[]);
void rechercher_animal(ANIMAL a,char identifiant[20],int *ok);
void afficher_troupeauModif(GtkWidget *liste);
void modifier_animal(ANIMAL t,char identifiant[]);
int nombre_veau();
int nombre_brebi();
void production (Production p);
void chercher_production(ANIMAL a, int *ok);
void afficher_production(GtkWidget *liste,char identif[20]);

