#include <gtk/gtk.h>
typedef struct
{
char type[20];
char designation[20];
char marque[20];
char ref[20];
char prixachat[20];
char stock[20];
char etat[20];
char situation[20];
}equipement;
void ajouterequipement(equipement P);
void liste(GtkWidget *lista);
void cherchereq(equipement P,char ref1[20], int *verif);
void listeModif(GtkWidget *lista);
void listeficher(GtkWidget *fiche);
void supprimer(char ref1[20]);
void modif_eq(equipement e,char ref1[20]);
void supprimert2(char ref1[20]);
int calcul_defaillement();
void listedefaillant(GtkWidget *fiche);
void listeut(GtkWidget *uti);
int calcul_utilisation();
void modif_eq2(equipement P,char ref1[20]);

