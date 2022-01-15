#include <gtk/gtk.h>

typedef struct
{
    int jour;
    int mois;
    int annee;
}Naissance;
typedef struct
{
    char username[20];
    char password[20];
}compt;

typedef struct
{
    char nom[20];
    char prenom[20];
    char sexe[20];
    Naissance date_naissance;
    char cin[20];
    char gsm[20];
    int id;
    compt compt;
}Employe;

typedef struct
{
	Employe employe;
	Naissance date;
	char etat[30];
	
}Pointage;


void  ajouter_employe(Employe e);
void afficher_employe(GtkWidget *liste);
void supprimer_employe(Employe e, char cin[]);
void modifier_employe(Employe h, char cin[]);
void chercher_employe(Employe e, char cin[20], int *ok);//pointeur ok pour verifier eistance du utilisateur recherché
void afficher_employeModif(GtkWidget *liste);
void afficher_employeSupp(GtkWidget *liste);
void afficher_taux(GtkWidget *liste, char id[]);
void chercher_employe_taux(Employe e, char id[20], int *ok);
void pointage(Pointage p);
int  tauxABS();
void check(Pointage p, char ident[], int *ok1);
int premier(int id);
void deuxieme(int id, int *total);
void afficher_meilleur_employe(GtkWidget *liste, char ident[30]);

int id_supprimer_employe(Employe e, char cin[]); //Return la valeur de l'id qui va être supprimer
void supprimer_pointage(Pointage e, int id);//supprimer les pointage de l'employé qui a l'id retourné par la fonction precedente





