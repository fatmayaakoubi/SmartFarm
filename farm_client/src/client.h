
#include<gtk/gtk.h>
typedef struct
{ 
     int jour;
     int mois;
     int annee;
 }date;

typedef struct
{
    char nom[20];
    char prenom[20];
    char sexe[20];
    char gouvernement[50];
    char adresse[100];
    char cin[20];
    char gsm[20];
    char mail[100];
    date date_de_naissance;
}client;

typedef struct
{
	client c;
 	date date_de_paiement;
	char livraison[20];
	int quantite_veaux;
	int quantite_brebis;
	int quantite_yaourt;
	int quantite_rigouta;
	char brebi[20];
	char veau[20];
         char yaourt[20];
	char rigouta[20];
	float somme;
}achat;
 
typedef struct
{ 
  client c;
  date date_de_reservation;
  char type_reservation[100];
  int num;
}reservation;

void ajouter_client(client c);

void afficher_liste_clients(GtkWidget *liste);

void rechercher_client(client c, char cin[],int *verif);

void supprimer_client( client c, char cin[]);

void afficher_client_supprimer(GtkWidget *liste);

void modifier_client(client m, char cin[]);

void afficher_client_modifier(GtkWidget *liste);

void ajouter_achat(achat a);

void afficher_achat(GtkWidget *liste);

void ajouter_reservation(reservation r);

void afficher_reservation(GtkWidget *liste);
 
