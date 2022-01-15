#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fonction.h"
#include "equipement.h"
#include "animal.h"
#include "client.h"
#include "capteur.h"

void
on_buttonListeEmployes_clicked         (GtkWidget       *button,
                                        gpointer         user_data)
{

GtkWidget *treeview;
GtkWidget *listeemp;
GtkWidget *window;
listeemp = create_windowListeEmployes();
gtk_widget_show(listeemp);
treeview = lookup_widget(listeemp, "treeview");
afficher_employe(treeview);
window = lookup_widget(button,"windowGestionEmployes");
gtk_widget_destroy(window);




}


void
on_buttonSupprimeEmploye_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowSupprimer;
GtkWidget *windowMenu;
GtkWidget *liste;
windowMenu = lookup_widget(button, "windowGestionEmployes");
gtk_widget_destroy(windowMenu);
windowSupprimer = create_windowSupprimerEmploye();
gtk_widget_show(windowSupprimer);

liste = lookup_widget (windowSupprimer, "treeview5");
afficher_employe(liste);

}





void
on_buttonDeconnexion_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowSupprimer;
GtkWidget *windowLogin;
GtkWidget *windowGestionEmp;
GtkWidget *windowAjoutEmploye;
GtkWidget *windowModifier;
GtkWidget *windowListeEmployes;
GtkWidget *windowpointage;
windowSupprimer = lookup_widget(button, "windowSupprimerEmploye");
gtk_widget_destroy(windowSupprimer);

windowGestionEmp = lookup_widget(button, "windowGestionEmployes");
gtk_widget_destroy(windowGestionEmp);

windowModifier = lookup_widget(button, "windowModifierEmploye");
gtk_widget_destroy(windowModifier);

windowAjoutEmploye = lookup_widget(button, "windowAjoutEmploye");
gtk_widget_destroy(windowAjoutEmploye);


windowListeEmployes = lookup_widget(button, "windowListeEmployes");
gtk_widget_destroy(windowListeEmployes);
windowpointage = lookup_widget(button, "windowPointage");
gtk_widget_destroy(windowpointage);


windowLogin = create_windowLogin();
gtk_widget_show(windowLogin);

}


void
on_buttonAjoutEmploye_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowAjout;
GtkWidget *windowMenu;
windowMenu = lookup_widget(button,"windowGestionEmployes");
gtk_widget_destroy(windowMenu);

windowAjout = lookup_widget(button,"windowAjoutEmploye");
windowAjout = create_windowAjoutEmploye();
gtk_widget_show(windowAjout);






}


void
on_buttonModifEmploye_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowModifier;
GtkWidget *windowMenu;
GtkWidget *liste;

windowMenu = lookup_widget(button, "windowGestionEmployes");
gtk_widget_destroy(windowMenu);
windowModifier = create_windowModifierEmploye();
gtk_widget_show(windowModifier);

liste = lookup_widget (windowModifier, "treeview4");
afficher_employe(liste);


}

int choixseif[] = {0,0}; //Homme ou femme pour la fonction ajout employe
int choix1seif[] = {0,0};//Homme ou femme pour la fonction Modifier Employe

int i; //variable pour savoir le numero d'identifiant 
void
on_buttonAjouter_clicked               (GtkWidget       *button,
                                        gpointer         user_data)
{
Employe p;
Employe e;
int fail=0;
FILE *fp1;
fp1 = fopen("utilisateurs.bin", "rb");
if (fp1==NULL)
    {
	i = 0; //Id = 0 si le fichier n'existe pas (pas d'employe ajouté)
    }
    
 
    else
    {
	while (fread(&p,sizeof(p),1,fp1))
	{
		i = p.id; // i prends la valeur du dernier employe ajouté
	}
    fclose(fp1);
    }

i++; // si le dernier employe ajouté à un id=5 donc i=6 ou si il nya pas d'employe, i commence de 1

GtkWidget *input1;
GtkWidget *input2;
GtkWidget *input3;
GtkWidget *input4;
GtkWidget *Jour;
GtkWidget *Mois;
GtkWidget *Annee;
GtkWidget *windowErreur;
GtkWidget *windowSuccees;
GtkWidget *dialog;


input1 = lookup_widget(button, "entryNom");
input2 = lookup_widget(button, "entryPrenom");
input3 = lookup_widget(button, "entryCin");
input4 = lookup_widget(button, "entryGsm");
Jour = lookup_widget(button, "spinbuttonJours");
Mois = lookup_widget(button, "spinbuttonMois");
Annee = lookup_widget(button, "spinbuttonAnnees");


strcpy(p.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(p.prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(p.cin,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(p.gsm,gtk_entry_get_text(GTK_ENTRY(input4)));

if (choixseif[0]==1)
strcpy(p.sexe,"Homme");
else if (choixseif[1]==1)
strcpy(p.sexe,"Femme");


p.date_naissance.jour= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Jour));
p.date_naissance.mois= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Mois));
p.date_naissance.annee= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Annee));
p.id = i;
if(((choixseif[0]==1) && (choixseif[1]==1)) || ((choixseif[0]==0) && (choixseif[1]==0)) || (strcmp(p.nom,"")==0) || (strcmp(p.prenom,"")==0) || (strcmp(p.cin,"")==0) || (strcmp(p.gsm,"")==0))
{
windowErreur = create_windowChampsseif();
gtk_widget_show(windowErreur);
fail=1;
return;
}
/*fp1 = fopen("utilisateurs.bin", "rb");
if(fp1==NULL)
{
	return;
}
else
{
while (fread(&e, sizeof(e), 1, fp1))
{
	if(strcmp(e.cin, p.cin)==0)
	{
		dialog = create_dialog6seif();
		gtk_widget_show(dialog);
		fail = 1;
		break;
		return;
	}
}
fclose(fp1);
}*/

if (fail==0)
{
ajouter_employe(p);
windowSuccees = create_dialog1seif();
gtk_widget_show(windowSuccees);
}

}


void
on_buttonRechercher_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *treeview1;
GtkWidget *liste1;
GtkWidget *input;
GtkWidget *buttonEnable;
GtkWidget *window;
int ok; //variable de la fonction chercher_employe (1 si existe 0 si existe pas)
Employe e;
char cin[30];
input = lookup_widget(button, "entryUsername");
buttonEnable = lookup_widget(button, "buttonModif"); //Pointeur sur bouton Modifier
strcpy(cin,gtk_entry_get_text(GTK_ENTRY(input)));

window = lookup_widget(button, "windowModifierEmploye");
treeview1 = lookup_widget(window, "treeview1");
chercher_employe(e, cin, &ok);
if (ok)
gtk_widget_set_sensitive(buttonEnable, TRUE); //Set Sensitivity to TRUE
else
gtk_widget_set_sensitive(buttonEnable, FALSE); //Set Sensitivity to FALSE


afficher_employeModif(treeview1);

}


void
on_buttonSupprimer_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
char cin[30];
int id;
GtkWidget *windowSuccees;
Employe p;
Pointage e;
GtkWidget *input;
input = lookup_widget(button, "entryUsername");
strcpy(cin, gtk_entry_get_text(GTK_ENTRY(input)));
id = id_supprimer_employe(p, cin);
supprimer_employe(p,cin);
supprimer_pointage(e, id);
windowSuccees = create_dialog3seif();
gtk_widget_show(windowSuccees);
}


/*void
on_treeview_row_activated              (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{



}
*/

void
on_checkbuttonMale_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choixseif[0] = 1;
else
choixseif[0] = 0;
}


void
on_checkbuttonFemelle_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choixseif[1] = 1;
else
choixseif[1] = 0;

}





gboolean
on_treeview_start_interactive_search   (GtkTreeView     *treeview,
                                        gpointer         user_data)
{

  return FALSE;
}


void
on_buttonRefresh_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *treeview;
GtkWidget *listeemp;
listeemp = create_windowListeEmployes();
treeview = lookup_widget(listeemp, "treeview");
afficher_employe(treeview);


}

char tmps[30];// stocker dans la variable tmps le cin de l'utilisateur a modifier pour l'utiliser dans l'affichage
void
on_buttonModif_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{

Employe e;
GtkWidget *input1;
GtkWidget *windowModification;
//char cin[30];
FILE *fp;
fp = fopen("temp1.bin", "rb");
input1 = lookup_widget(button, "entryUsername");
strcpy(tmps,gtk_entry_get_text(GTK_ENTRY(input1)));
windowModification = create_ModifierEmploye();
gtk_widget_show(windowModification);
// *********************************	SET TEXT TO ENTRIES	***************************
GtkWidget *output1, *output2, *output3, *output4, *output5, *output6, *output7;
if(fp!=NULL)
{
while (fread(&e, sizeof(e), 1, fp))
{
	output1 = lookup_widget(windowModification, "entryModifierNom");
	gtk_entry_set_text(GTK_ENTRY(output1), e.nom);

	output2 = lookup_widget(windowModification, "entryModifierPrenom");
	gtk_entry_set_text(GTK_ENTRY(output2), e.prenom);

	output3 = lookup_widget(windowModification, "entryModifierCin");
	gtk_entry_set_text(GTK_ENTRY(output3), e.cin);

	output4 = lookup_widget(windowModification, "entryModifierGsm");
	gtk_entry_set_text(GTK_ENTRY(output4), e.gsm);

	output5 = lookup_widget(windowModification, "spinbuttonModifierJour");
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(output5), e.date_naissance.jour);


	output6 = lookup_widget(windowModification, "spinbuttonModifierMois");
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(output6), e.date_naissance.mois);


	output7 = lookup_widget(windowModification, "spinbuttonModifierAnnee");
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(output7), e.date_naissance.annee);

}
}
////////////////////////////////////////////////////////
fclose(fp);
}


void
on_buttonConfirmerModif_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{

Employe p;
FILE *fp1;
fp1 = fopen("utilisateurs.bin", "rb");
if (fp1==NULL)
    {
	i = 0;
    }
    
 
    else
    {
	while (fread(&p,sizeof(p),1,fp1))
	{
		if (strcmp(p.cin,tmps)==0){
		i = p.id; // i prends la valeur de l'employe qui a la cin à rechercher
		break;}
	}
    }

GtkWidget *input1;
GtkWidget *input2;
GtkWidget *input3;
GtkWidget *input4;
GtkWidget *Jour;
GtkWidget *Mois;
GtkWidget *Annee;
GtkWidget *windowErreur;
GtkWidget *windowSuccees;
GtkWidget *windowM;


input1 = lookup_widget(button, "entryModifierNom");
input2 = lookup_widget(button, "entryModifierPrenom");
input3 = lookup_widget(button, "entryModifierCin");
input4 = lookup_widget(button, "entryModifierGsm");
Jour = lookup_widget(button, "spinbuttonModifierJour");
Mois = lookup_widget(button, "spinbuttonModifierMois");
Annee = lookup_widget(button, "spinbuttonModifierAnnee");


strcpy(p.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(p.prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(p.cin,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(p.gsm,gtk_entry_get_text(GTK_ENTRY(input4)));

if (choix1seif[0]==1)
strcpy(p.sexe,"Homme");
else if (choix1seif[1]==1)
strcpy(p.sexe,"Femme");


p.date_naissance.jour= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Jour));
p.date_naissance.mois= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Mois));
p.date_naissance.annee= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Annee));
p.id = i;

if(((choix1seif[0]==1) && (choix1seif[1]==1)) || ((choix1seif[0]==0) && (choix1seif[1]==0)) || (strcmp(p.nom,"")==0) || (strcmp(p.prenom,"")==0) || (strcmp(p.cin,"")==0) || (strcmp(p.gsm,"")==0))
{
windowErreur = create_windowChampsseif();
gtk_widget_show(windowErreur);
}
else
{
modifier_employe(p, tmps);  
windowSuccees = create_dialog2seif();
gtk_widget_show(windowSuccees);
windowM = lookup_widget(button, "ModifierEmploye");
gtk_widget_destroy(windowM);
}




}


void
on_checkbuttonModifierMale_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choix1seif[0] = 1;
else
choix1seif[0] = 0;

}


void
on_checkbuttonModifierFemelle_toggled  (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choix1seif[1] = 1;
else
choix1seif[1] = 0;

}


void
on_RechercherSupp_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *treeview2;
GtkWidget *liste1;
GtkWidget *input;
GtkWidget *buttonEnable;
GtkWidget *window;
int ok; //variable de la fonction chercher_employe (1 si existe 0 si existe pas)
Employe e;
char cin[30];
input = lookup_widget(button, "entryUsername");
buttonEnable = lookup_widget(button, "buttonSupprimer"); //Pointeur sur bouton Modifier
strcpy(cin,gtk_entry_get_text(GTK_ENTRY(input)));

window = lookup_widget(button, "windowSupprimerEmploye");
treeview2 = lookup_widget(window, "treeview2");
chercher_employe(e, cin, &ok);
if (ok)
gtk_widget_set_sensitive(buttonEnable, TRUE); //Set Sensitivity to TRUE
else
gtk_widget_set_sensitive(buttonEnable, FALSE); //Set Sensitivity to FALSE


afficher_employeModif(treeview2);

}


void
on_buttonPointage_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowPointage;
GtkWidget *windowMain;
GtkWidget *combobox;//pointeur combobox dynamique
GtkWidget *combobox1;
GtkWidget *buttonEnable;
FILE *fp, *fp2;
Employe e;
char id[30];
fp = fopen("utilisateurs.bin", "rb");
windowMain = lookup_widget(button, "windowGestionEmployes");
gtk_widget_destroy(windowMain);
windowPointage = create_windowPointage();
gtk_widget_show(windowPointage);

buttonEnable = lookup_widget(windowPointage, "buttonChercherTaux");
combobox = lookup_widget(windowPointage, "comboboxentryID");
combobox1 = lookup_widget(windowPointage, "comboboxentryIDTaux");
if(fp!=NULL)
{
while (fread(&e,sizeof(e),1,fp))
{
sprintf(id,"%d",e.id); //convert employe id from int to char 
gtk_combo_box_append_text(GTK_COMBO_BOX(combobox), id); //append id's in combobox from user file(window de Pointage)
gtk_combo_box_append_text(GTK_COMBO_BOX(combobox1), id); //append id's in combobox from user file(window de TAUX)
}
fclose(fp);
}
fp2 = fopen("pointage.bin","rb");
if(fp2==NULL)
{
	gtk_widget_set_sensitive(buttonEnable, FALSE);
}
//fclose(fp2);

}


void
on_buttonCofirmerPointage_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{


Pointage p;
GtkWidget *identifiant;
GtkWidget *spin1, *spin2, *spin3;
GtkWidget *etat;
GtkWidget *dialog;
GtkWidget *buttonEnable;
char tmp[30];

identifiant = lookup_widget(button, "comboboxentryID");
spin1 = lookup_widget(button,"spinbuttonJourPoint");
spin2 = lookup_widget(button,"spinbuttonMoisPoint");
spin3 = lookup_widget(button,"spinbuttonAnneePoint");
etat = lookup_widget(button,"comboboxentryEtat");
buttonEnable = lookup_widget(button, "buttonChercherTaux");

dialog = create_windowChampsseif();

p.date.jour = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spin1));
p.date.mois = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spin2));
p.date.annee = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spin3));


if((gtk_combo_box_get_active_text(GTK_COMBO_BOX(identifiant))==NULL) || (gtk_combo_box_get_active_text(GTK_COMBO_BOX(etat))==NULL))
{
	gtk_widget_show(dialog);

}
else
{
strcpy(tmp, gtk_combo_box_get_active_text(GTK_COMBO_BOX(identifiant)));
p.employe.id = atoi(tmp);
strcpy(p.etat,gtk_combo_box_get_active_text(GTK_COMBO_BOX(etat)));
gtk_widget_set_sensitive(buttonEnable, TRUE);
pointage(p);

}
}


void
on_buttonConsulter_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{

Pointage p;
int res;
int x1,x2;
char res1[30];

char id[30];
char ident[30];
GtkWidget *identifiant;
GtkWidget *treeview3;
GtkWidget *label;
label = lookup_widget(button, "labelTaux");
identifiant = lookup_widget(button, "comboboxentryIDTaux");
strcpy(id,gtk_combo_box_get_active_text(GTK_COMBO_BOX(identifiant)));
//treeview3 = lookup_widget(button, "treeview3");
//afficher_taux(treeview3);

	res = tauxABS();
	sprintf(res1, "Taux d'absenteisme : %d%%", res);

gtk_label_set_text(GTK_LABEL(label),res1);


}


void
on_buttonChercherTaux_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *treeview3;
GtkWidget *liste1;
GtkWidget *input;
GtkWidget *buttonEnable;
GtkWidget *dialog;
FILE *fp1, *fp;
fp = fopen("pointage.bin","rb");
fp1 = fopen("calc.bin","wb");
int ok; //variable de la fonction chercher_employe (1 si existe 0 si existe pas)
int ok1;
Employe e;
Pointage p;
char ident[30];
char id[30];
input = lookup_widget(button, "comboboxentryIDTaux");
buttonEnable = lookup_widget(button, "buttonConsulter"); //Pointeur sur bouton Consulter
dialog = create_dialog5seif();
if(gtk_combo_box_get_active_text(GTK_COMBO_BOX(input))==NULL)
{
	gtk_widget_show(dialog);
}
else
{
strcpy(ident,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input)));
treeview3 = lookup_widget(button, "treeview3");
chercher_employe_taux(e, ident, &ok);
check(p, ident, &ok1);
if ((ok) && (ok1))
gtk_widget_set_sensitive(buttonEnable, TRUE); //Set Sensitivity to TRUE
else
gtk_widget_set_sensitive(buttonEnable, FALSE); //Set Sensitivity to FALSE
if((fp1==NULL))
{
return;
}
else
{
	while (fread(&p,sizeof(p),1,fp))
	{
		sprintf(id, "%d", p.employe.id);
		if(strcmp(id,ident)==0)
		{
		fwrite(&p, sizeof(p), 1 ,fp1);
		}	
	}

}
fclose(fp);
fclose(fp1);

afficher_taux(treeview3, ident);

}
}


void
on_buttonRefreshTaux_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *labelMeilleur;
GtkWidget *liste;
GtkWidget *img;
int identifiantFinal;
int x1, x2;
int res;
int meilleurEmp=100;
int id;
char meilleurCh[100];
labelMeilleur = lookup_widget(button, "label66");
img = lookup_widget(button, "image52");
FILE *fp;
Pointage p;
fp = fopen("pointage.bin", "rb");
if(fp==NULL)
{
	return;
}
else
{
while (fread(&p, sizeof(p), 1, fp))
{
	x1 = premier(p.employe.id);
	deuxieme(p.employe.id, &x2);
	if(x2==0)
	{
		gtk_label_set_text(GTK_LABEL(labelMeilleur), "Erreur!");
		break;
	}
	else
	{
	res = (x1*100)/x2;
	}
	if(res<meilleurEmp)
	{
		meilleurEmp = res;
		id = p.employe.id;
	}
}
sprintf(meilleurCh, "Meilleur Taux : %d%%", meilleurEmp);
gtk_label_set_text(GTK_LABEL(labelMeilleur), meilleurCh);
}
fclose(fp);
liste = lookup_widget(button, "treeview6");
afficher_meilleur_employe(liste, id);
gtk_widget_show(img);


}


void
on_okbutton1_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
window = lookup_widget(button, "dialog1seif");
gtk_widget_destroy(window);


}


void
on_okbutton2_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
window = lookup_widget(button, "dialog2seif");
gtk_widget_destroy(window);

}


void
on_okbutton3_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
window = lookup_widget(button, "dialog3seif");
gtk_widget_destroy(window);

}


void
on_okbutton4_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
window = lookup_widget(button, "windowChampsseif");
gtk_widget_destroy(window);

}


void
on_okbutton5_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
window = lookup_widget(button, "dialog5seif");
gtk_widget_destroy(window);

}


void
on_okbutton6_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
window = lookup_widget(button, "dialog6seif");
gtk_widget_destroy(window);

}


void
on_buttonGenererPire_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *labelPire;
GtkWidget *liste;
GtkWidget *img;
int identifiantFinal;
int x1, x2;
int res;
int pireEmp=0;
int id;
char pireCh[100];
labelPire = lookup_widget(button, "label79");
img = lookup_widget(button, "image53");
FILE *fp;
Pointage p;
fp = fopen("pointage.bin", "rb");
if(fp==NULL)
{
	return;
}
else
{
while (fread(&p, sizeof(p), 1, fp))
{
	x1 = premier(p.employe.id);
	deuxieme(p.employe.id, &x2);
	if(x2==0)
	{
		gtk_label_set_text(GTK_LABEL(labelPire), "Erreur!");
		break;
	}
	else
	{
	res = (x1*100)/x2;
	}
	if(res>pireEmp)
	{
		pireEmp = res;
		id = p.employe.id;
	}
}
sprintf(pireCh, "Pire Taux : %d%%", pireEmp);
gtk_label_set_text(GTK_LABEL(labelPire), pireCh);
}
fclose(fp);
liste = lookup_widget(button, "treeview7");
afficher_meilleur_employe(liste, id);
gtk_widget_show(img);


}
/*******************************************************************************************************************************************/
/*******************************************************************************************************************************************/
/*******************************************************************************************************************************************/
/*******************************************************************************************************************************************/
/*******************************************************************************************************************************************/


/*********************************************Acceuil button*********************************************/

void
on_acceuil_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *gesteq;
GtkWidget *windowmenu1;
GtkWidget *windowmenu2;
GtkWidget *windowmenu3;
GtkWidget *windowmenu4;
GtkWidget *windowmenu5;
gesteq = create_gesteq ();
gtk_widget_show (gesteq);
windowmenu1=lookup_widget(button,"Recheq");
gtk_widget_destroy(windowmenu1);
windowmenu5=lookup_widget(button,"tache2");
gtk_widget_destroy(windowmenu5);
windowmenu2=lookup_widget(button,"supeq");
gtk_widget_destroy(windowmenu2);
windowmenu3=lookup_widget(button,"listeq");
gtk_widget_destroy(windowmenu3);
windowmenu4=lookup_widget(button,"ajoutereq");
gtk_widget_destroy(windowmenu4);
}
/*********************************************Retour**********************************************************/

void
on_retour_clicked                      (GtkButton       *button,
                                        gpointer         user_data)
{

}

/************************************************Deco*******************************************************/
void
on_deco_clicked                        (GtkButton       *button,
                                        gpointer         user_data)
{

}

/**************************************************Ajout window show*****************************************************/
void
on_ajout_clicked                       (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *ajoutereq;
GtkWidget *windowmenu;
ajoutereq = create_ajoutereq ();
gtk_widget_show (ajoutereq);
windowmenu=lookup_widget(objet,"gesteq");
gtk_widget_destroy(windowmenu);

}

/************************************************Modif window show*******************************************************/
void
on_modif_clicked                       (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *recheq;
GtkWidget *windowmenu;
GtkWidget *treeview5;
GtkWidget *treev;
recheq = create_Recheq ();
gtk_widget_show (recheq);
windowmenu=lookup_widget(button,"gesteq");
gtk_widget_destroy(windowmenu);

treev=lookup_widget(recheq,"treev");
listeModif(treev);
treeview5=lookup_widget(recheq,"treeview5");
liste(treeview5);

}

/*************************************************Supp window show******************************************************/
void
on_supp_clicked                        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *treeview6;
GtkWidget *supeq;
GtkWidget *windowmenu;
GtkWidget *treesupp;
supeq = create_supeq ();
gtk_widget_show (supeq);
windowmenu=lookup_widget(button,"gesteq");
gtk_widget_destroy(windowmenu);
treesupp=lookup_widget(supeq,"treev");
listeModif(treesupp);
treeview6=lookup_widget(supeq,"treeview6");
liste(treeview6);

}

/***********************************************Liste d'equipement********************************************************/
void
on_list_clicked                        (GtkWidget      *button,
                                        gpointer         user_data)
{
GtkWidget *windowmenu;
GtkWidget *listeq;
GtkWidget *treeview1;
GtkWidget *combo;
FILE *f;
FILE *f1;
equipement e;
equipement c;
listeq = create_listeq ();
gtk_widget_show (listeq);
windowmenu=lookup_widget(button,"gesteq");
gtk_widget_destroy(windowmenu);
treeview1=lookup_widget(listeq,"treeview1");
liste(treeview1);
combo=lookup_widget(listeq,"combobox1");
//gtk_combo_box_append_text(GTK_COMBO_BOX(combo),_(c.marque));


/*f=fopen("equipement.bin","rb");
f1=fopen("test1.bin","a+b");
 if (f==NULL)
{return;}
while(fread(&e,sizeof(e),1,f))
	{	
	 		
  	 		fwrite(&c,sizeof(c),1,f1);
			fclose(f1);
			f1=fopen("test1.bin","rb");
			while(fread(&c,sizeof(c),1,f1))
			if(strcmp(e.marque,c.marque)==1)
			{fwrite(&e,sizeof(e),1,f1);
				
			}

		 gtk_combo_box_append_text(GTK_COMBO_BOX(combo),_(e.marque));
	}



fclose(f); */
		   /****************************OO******DOUTE*********OO*****************************/
 	 	/*************************OO*********DOUTE***********OO***************************/
		/***********************OO***********DOUTE*************OO*************************/
		/*********************OO*************DOUTE***************OO***********************/
}


/*********************************************Ajouter eqiupement**********************************************************/
void
on_ajouteq_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
equipement P;
GtkWidget *output=NULL;
GtkWidget *ajoutereq;
GtkWidget *type;
GtkWidget *design;
GtkWidget *ref;
GtkWidget *marque;
GtkWidget *prix;
GtkWidget *stock;
GtkWidget *dialog1;
GtkWidget *dialog3;
FILE *f;
char reference[30];
equipement h;
int fail=0;
int pass=0;

type=lookup_widget(objet,"entrytyp");
design=lookup_widget(objet,"entrydesign");
ref=lookup_widget(objet,"entryref");
marque=lookup_widget(objet,"entrymarq");
prix=lookup_widget(objet,"entryprix");
stock=lookup_widget(objet,"stockentry");
strcpy(P.type,gtk_entry_get_text(GTK_ENTRY(type)));
strcpy(P.designation,gtk_entry_get_text(GTK_ENTRY(design)));
strcpy(P.marque,gtk_entry_get_text(GTK_ENTRY(marque)));
strcpy(P.prixachat,gtk_entry_get_text(GTK_ENTRY(prix)));
strcpy(P.stock,gtk_entry_get_text(GTK_ENTRY(stock)));           
strcpy(reference,gtk_entry_get_text(GTK_ENTRY(ref)));
strcpy(P.ref,gtk_entry_get_text(GTK_ENTRY(ref)));
f=fopen("equipement.bin","a+b");
if(f==NULL)
	{return;}
else { 
while(fread(&h,sizeof(h),1,f) )
{ fail=0;
		if(strcmp(h.ref,reference)==0)
		{
		/*dialog1=create_dialog1();
		gtk_widget_show(dialog1);*/
		fail=1;
		}
		if(fail==1)
		{pass=1;}
 

	
}

 
if((strcmp(P.type,"")==0)||(strcmp(P.designation,"")==0) || (strcmp(P.ref,"")==0)  || (strcmp(P.marque,"")==0) || (strcmp(P.prixachat,"")==0) || (strcmp(P.stock,"")==0)||(pass==1))
{

dialog1=create_dialog1has();
gtk_widget_show(dialog1);
return;

}
else {

ajouterequipement(P);
dialog3=create_dialog3has();
gtk_widget_show(dialog3);

}
}
}



/**********************************************Interactive search*********************************************************/
gboolean
on_treeview1_start_interactive_search  (GtkTreeView     *treeview,
                                        gpointer         user_data)
{

  return TRUE;
}
/****************************************************Supprimer l'equipement***************************************************/

void
on_supbut_clicked                      (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *input;  
  GtkWidget *output;
  GtkWidget *dialog4;

  equipement P;
                                        
char ref1[20];
 input=lookup_widget(button,"chersupp");
 strcpy(ref1,gtk_entry_get_text(GTK_ENTRY(input)));
supprimer(ref1);
supprimert2(ref1);
dialog4=create_dialog3has();
gtk_widget_show(dialog4);

}
/**********************************************Chercher ref*********************************************************/
void
on_refrechbut_clicked                      (GtkButton       *button,
                                        gpointer         user_data)
{ GtkWidget *treev;
  GtkWidget *treeview5;
  GtkWidget *buttonactiv;
 GtkWidget *input;  
GtkWidget *Recheq;
  equipement P;
int verif;
 char ref1[50];
 input=lookup_widget(button,"rechref");
buttonactiv= lookup_widget(button,"mod");
 strcpy(ref1,gtk_entry_get_text(GTK_ENTRY(input)));
Recheq=lookup_widget(button,"Recheq");
treev=lookup_widget(Recheq,"treev");
cherchereq(P,ref1,&verif);
if(verif)
gtk_widget_set_sensitive(buttonactiv, TRUE);
else
gtk_widget_set_sensitive(buttonactiv, FALSE);
listeModif(treev);
treeview5=lookup_widget(button,"treeview5");
liste(treeview5);



}

/*******************************************************************************************************/
void
on_treeview1_set_scroll_adjustments    (GtkTreeView     *treeview,
                                        GtkAdjustment   *hadjustment,
                                        GtkAdjustment   *vadjustment,
                                        gpointer         user_data)
{

}

/*********************************************actualiser**********************************************************/
void
on_Actualiser_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{


}
/**************************************************window modif+entry*****************************************************/
char ref1[30];

void
on_mod_clicked                         (GtkButton       *button,
                                        gpointer         user_data)
{
equipement P;
GtkWidget *window;
GtkWidget *input;
GtkWidget *type;
GtkWidget *design;
GtkWidget *ref;
GtkWidget *marque;
GtkWidget *prix;
GtkWidget *stock;
GtkWidget *recheq;
GtkWidget *buttonactiv;

FILE *f;

input=lookup_widget(button,"rechref");
strcpy(ref1,gtk_entry_get_text(GTK_ENTRY(input)));
window=create_modificationwindow();
gtk_widget_show(window);

/* Reading entries */
f=fopen("modtemp.bin","rb");
while(fread(&P,sizeof(P),1,f))
{
type=lookup_widget(window,"type");
gtk_entry_set_text(GTK_ENTRY(type),P.type);
design=lookup_widget(window,"designation");
gtk_entry_set_text(GTK_ENTRY(design),P.designation);
ref=lookup_widget(window,"refrence");
gtk_entry_set_text(GTK_ENTRY(ref),P.ref);
marque=lookup_widget(window,"marque");
gtk_entry_set_text(GTK_ENTRY(marque),P.marque);
prix=lookup_widget(window,"prixachat");
gtk_entry_set_text(GTK_ENTRY(prix),P.prixachat);
stock=lookup_widget(window,"stock");
gtk_entry_set_text(GTK_ENTRY(stock),P.stock);
}
recheq=lookup_widget(button,"Recheq");
buttonactiv= lookup_widget(recheq,"mod");
gtk_widget_set_sensitive(buttonactiv, FALSE);

fclose(f);




}

/*******************************************************************************************************/

void
on_treev_row_activated                 (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}
/*******************************************Confirmer modif************************************************************/

void
on_confirm_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
equipement P;
//equipement h;
GtkWidget *output=NULL;
GtkWidget *ajoutereq;
GtkWidget *type;
GtkWidget *design;
GtkWidget *ref;
GtkWidget *marque;
GtkWidget *prix;
GtkWidget *stock;
GtkWidget *dialog1;
GtkWidget *windowmenu;
GtkWidget *buttonactiv;

GtkWidget *tache2;
GtkWidget *radiobutton1;
GtkWidget *radiobutton2;
GtkWidget *radiobutton3;
GtkWidget *radiobutton4;

tache2=create_tache2();
radiobutton1=lookup_widget(tache2,"radiobutton1");
radiobutton2=lookup_widget(tache2,"radiobutton2");
radiobutton3=lookup_widget(tache2,"radiobutton3");
radiobutton4=lookup_widget(tache2,"radiobutton4");
    

type=lookup_widget(button,"type");
design=lookup_widget(button,"designation");
ref=lookup_widget(button,"refrence");
marque=lookup_widget(button,"marque");
prix=lookup_widget(button,"prixachat");
stock=lookup_widget(button,"stock");
strcpy(P.type,gtk_entry_get_text(GTK_ENTRY(type)));
strcpy(P.designation,gtk_entry_get_text(GTK_ENTRY(design)));
strcpy(P.ref,gtk_entry_get_text(GTK_ENTRY(ref)));
strcpy(P.marque,gtk_entry_get_text(GTK_ENTRY(marque)));
strcpy(P.prixachat,gtk_entry_get_text(GTK_ENTRY(prix)));
strcpy(P.stock,gtk_entry_get_text(GTK_ENTRY(stock)));


if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radiobutton1))==TRUE)
     {
             strcpy(P.situation,"libre");
       }

                else if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radiobutton2))==TRUE)
                 {
               strcpy(P.situation,"ocuppe");
                 }
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radiobutton3))==TRUE)
     {
             strcpy(P.etat,"fonctionel");
       }

                else if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radiobutton4))==TRUE)
                 {
               strcpy(P.etat,"defaillant");
                 }


if((strcmp(P.type,"")==0)||(strcmp(P.designation,"")==0) || (strcmp(P.ref,"")==0)  || (strcmp(P.marque,"")==0) || (strcmp(P.prixachat,"")==0) || (strcmp(P.stock,"")==0))
{
dialog1=create_dialog1has();
gtk_widget_show(dialog1);
}
else {
modif_eq(P,ref1);
modif_eq2(P,ref1);

windowmenu=lookup_widget(button,"modificationwindow");
gtk_widget_destroy(windowmenu);

}



}
/***********************************etat window + new collumns**********************************************/

void
on_etateq_clicked                      (GtkButton       *button,
                                        gpointer         user_data)
{
char refer[30];
equipement e;
FILE *f;
GtkWidget *combo;
GtkWidget *tache2;
GtkWidget *windowmenu;

f=fopen("equipement.bin","rb");
tache2=create_tache2();
gtk_widget_show(tache2);
windowmenu=lookup_widget(button,"gesteq");
gtk_widget_destroy(windowmenu);
combo=lookup_widget(tache2,"comboboxentry2");
if(f==NULL)
{
return;
}
while(fread(&e,sizeof(e),1,f))
{

gtk_combo_box_append_text(GTK_COMBO_BOX(combo),_(e.ref));
}
fclose(f);



GtkWidget *treeview2;



//gtk_widget_destroy(windowmenu);
treeview2=lookup_widget(tache2,"treeview2");
listeficher(treeview2);
}


/********************************************Dialog***********************************************************/
void
on_format_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *dialog2 ;
dialog2=create_dialog2has();
gtk_widget_show(dialog2);
}

/**********************************************Dialog sure*********************************************************/
void
on_sure_clicked                        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *dialog2 ;
remove("equipement.bin");
remove("modtemp.bin");
remove("eq.bin");
dialog2=lookup_widget(button,"dialog2has");
gtk_widget_destroy(dialog2);
}

/*************************************************Dialog non******************************************************/
void
on_notsure_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *dialog2 ;
dialog2=lookup_widget(button,"dialog2has");
gtk_widget_destroy(dialog2);

}

/*************************************************Supp reference cherch******************************************************/
void
on_chersup_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{ GtkWidget *treesupp;
  GtkWidget *buttonactiv;
 GtkWidget *input;  
GtkWidget *supeq;
GtkWidget *treeview6;
  equipement P;
int verif;
 char ref1[50];
 input=lookup_widget(button,"chersupp");
buttonactiv= lookup_widget(button,"supbut");
 strcpy(ref1,gtk_entry_get_text(GTK_ENTRY(input)));
supeq=lookup_widget(button,"supeq");
treesupp=lookup_widget(supeq,"treesupp");
cherchereq(P,ref1,&verif);
if(verif)
gtk_widget_set_sensitive(buttonactiv, TRUE);
else
gtk_widget_set_sensitive(buttonactiv, FALSE);
listeModif(treesupp);
treeview6=lookup_widget(button,"treeview6");
liste(treeview6);




}



/**************************************************************************************/
void
on_sauv_clicked                        (GtkButton       *button,
                                        gpointer         user_data)
{ char item[20];
GtkWidget *combo;
GtkWidget *tache2;
GtkWidget *radiobutton1;
GtkWidget *radiobutton2;
GtkWidget *radiobutton3;
GtkWidget *radiobutton4;
GtkWidget *treeview2;
equipement P;
radiobutton1=lookup_widget(button,"radiobutton1");
radiobutton2=lookup_widget(button,"radiobutton2");
radiobutton3=lookup_widget(button,"radiobutton3");
radiobutton4=lookup_widget(button,"radiobutton4");

FILE *f,*f1;
tache2=create_tache2();
combo=lookup_widget(button,"comboboxentry2");
if(gtk_combo_box_get_active_text(GTK_COMBO_BOX(combo))==NULL)
{return;}
else
{
strcpy(item,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combo)));
}
f=fopen("equipement.bin","rb");
f1=fopen("eq.bin","ab+");


while(fread(&P,sizeof(P),1,f))
{
if(strcmp(item,P.ref)==0)
{


if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radiobutton1))==TRUE)
     {
             strcpy(P.situation,"libre");
       }

                else if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radiobutton2))==TRUE)
                 {
               strcpy(P.situation,"ocuppe");
                 }
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radiobutton3))==TRUE)
     {
             strcpy(P.etat,"fonctionel");
       }

                else if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radiobutton4))==TRUE)
                 {
               strcpy(P.etat,"defaillant");
                 }
fwrite(&P,sizeof(P),1,f1);

}


}
fclose(f);
fclose(f1);
treeview2=lookup_widget(button,"treeview2");
listeficher(treeview2);




}




void
on_closebutton1has_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{ GtkWidget *close;
close=lookup_widget(button,"dialog1has");
gtk_widget_destroy(close);
}


void
on_stat1_clicked                       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *tache2;
GtkWidget *lablebi;
GtkWidget *defaille;
GtkWidget *fois;

GtkWidget *treeview3;
int def;
char text[20]="";
tache2=lookup_widget(button,"tache2");
def=calcul_defaillement();
sprintf(text,"%d",def);
lablebi=lookup_widget(button,"testlab");
gtk_label_set_text(lablebi,text);
defaille=lookup_widget(button,"label69");
gtk_label_set_text(defaille,"Defaillé");
fois=lookup_widget(button,"label70");
gtk_label_set_text(fois,"fois");


treeview3=lookup_widget(button,"treeview3");
listedefaillant(treeview3);
}


void
on_stat2_clicked                       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *tache2;
GtkWidget *utilise;
GtkWidget *fois1;
GtkWidget *treeview4;
GtkWidget *utilisation; 
int ut;
char text1[20]="";
tache2=lookup_widget(button,"tache2");
ut=calcul_utilisation();
sprintf(text1,"%d",ut);
utilisation=lookup_widget(button,"label72");
gtk_label_set_text(utilisation,text1);
utilise=lookup_widget(button,"label71");
gtk_label_set_text(utilise,"Utilisé");
fois1=lookup_widget(button,"label73");
gtk_label_set_text(fois1,"fois");


treeview4=lookup_widget(tache2,"treeview4");
listeut(treeview4);
}







void
on_succeshas_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *dialogsuc;
dialogsuc=lookup_widget(button,"dialog3has");
gtk_widget_destroy(dialogsuc);

}





gboolean
on_eventbox1_button_press_event        (GtkWidget       *widget,
                                        GdkEventButton  *event,
                                        gpointer         user_data)
{

GtkWidget *windowHsan;
GtkWidget *window;
windowHsan = create_gesteq();
gtk_widget_show(windowHsan);
window = lookup_widget(widget, "windowHome");
gtk_widget_destroy(window);
  return FALSE;
}


gboolean
on_eventbox2_button_press_event        (GtkWidget       *widget,
                                        GdkEventButton  *event,
                                        gpointer         user_data)
{
GtkWidget *windowSeif;
GtkWidget *window;
windowSeif = create_windowGestionEmployes();
gtk_widget_show(windowSeif);
window = lookup_widget(widget, "windowHome");
gtk_widget_destroy(window);
  return FALSE;
}

/**********************************************************************************************/ 
void
on_AccueilM_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowsupprimer;
GtkWidget *windowMenu;
GtkWidget *windowajouter;
GtkWidget *windowmodification;
GtkWidget *windowliste;
GtkWidget *windowp;

windowsupprimer = lookup_widget(button, "Windowsupprimer");
gtk_widget_destroy(windowsupprimer);

windowmodification = lookup_widget(button, "windowModification");
gtk_widget_destroy(windowmodification);

windowajouter = lookup_widget(button, "Windowajouter");
gtk_widget_destroy(windowajouter);


windowliste = lookup_widget(button, "Windowliste");
gtk_widget_destroy(windowliste);

windowp = lookup_widget(button, "windowproduction");
gtk_widget_destroy(windowp);



windowMenu = create_WindowMenu();
gtk_widget_show(windowMenu);
}





void
on_button1_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
FILE *fp;
fp=fopen("animaux.bin","rb");
GtkWidget *windowMenu;
GtkWidget *Windowcalcul;
GtkWidget *combobox1;
GtkWidget *combobox2;
ANIMAL e;
windowMenu = lookup_widget(button,"WindowMenu");
gtk_widget_destroy(windowMenu);
Windowcalcul = create_windowproduction();
gtk_widget_show(Windowcalcul);

/*GtkWidget *labelVeau;
GtkWidget *labelBrebi;
labelVeau=lookup_widget(Windowcalcul,"labelVeau");
labelBrebi=lookup_widget(Windowcalcul,"labelBrebi");
int veau,brebi;
char veauCh[30], brebiCh[30];
brebi = nombre_brebi();
veau = nombre_veau();
sprintf(veauCh, "%d", veau);
sprintf(brebiCh, "%d", brebi);
gtk_label_set_text(GTK_LABEL(labelVeau), veauCh);
gtk_label_set_text(GTK_LABEL(labelBrebi), brebiCh);*/
combobox1=lookup_widget(Windowcalcul,"combobox3");
combobox2=lookup_widget(Windowcalcul,"combobox4");
if(fp!=NULL)
{
while (fread(&e,sizeof(e),1,fp))
{

gtk_combo_box_append_text(GTK_COMBO_BOX(combobox1), e.identifiant); 
gtk_combo_box_append_text(GTK_COMBO_BOX(combobox2), e.identifiant);
}

fclose(fp);
}
}


void
on_supprimer_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowMenu;
GtkWidget *windowsupprimer;
GtkWidget *liste;
windowMenu = lookup_widget(button, "WindowMenu");
gtk_widget_destroy(windowMenu);
windowsupprimer = create_Windowsupprimer();
gtk_widget_show(windowsupprimer);
liste = lookup_widget (windowsupprimer, "treeview4Mer");
liste_animaux(liste);
}


void
on_modifier_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowmodification;
GtkWidget *windowMenu;
GtkWidget *liste;
windowMenu = lookup_widget(button,"WindowMenu");
gtk_widget_destroy(windowMenu);

windowmodification = create_windowModification();
gtk_widget_show(windowmodification);

liste = lookup_widget (windowmodification, "treeview6Mer");
liste_animaux(liste);
}


void
on_ajouter_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowajouter;
GtkWidget *windowMenu;

windowMenu = lookup_widget(button,"WindowMenu");
gtk_widget_destroy(windowMenu);

windowajouter = create_Windowajouter();
gtk_widget_show(windowajouter);
}


void
on_liste_clicked                       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *treeview1;
GtkWidget *windowMenu;
GtkWidget *windowliste;

windowliste = create_Windowliste();
gtk_widget_show(windowliste);

treeview1= lookup_widget(windowliste, "treeview1Mer");
liste_animaux(treeview1);

windowMenu = lookup_widget(button,"WindowMenu");
gtk_widget_destroy(windowMenu);
}

int choix1[] = {0,0}; 
int choix[] = {0,0}; 
void
on_ajouter1_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
ANIMAL p;
ANIMAL a;

GtkWidget *input1;
GtkWidget *Jour;
GtkWidget *Mois;
GtkWidget *Annee;
GtkWidget *Poids;
GtkWidget *Taille;
GtkWidget *windowErreur;
GtkWidget *comboboxentrytype;
GtkWidget *windowSucc;
GtkWidget *dialog;

comboboxentrytype= lookup_widget(button, "comboboxentrytype");

input1 = lookup_widget(button, "entryidentifiant");
Jour = lookup_widget(button, "spinbuttonJour");
Mois = lookup_widget(button, "spinbutton2Mois");
Annee = lookup_widget(button, "spinbutton3Annee");
Poids = lookup_widget(button, "spinbutton4Poids");
Taille = lookup_widget(button, "spinbutton5Taille");


strcpy(p.identifiant,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(p.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxentrytype)));

if (choix1[0]==1)
strcpy(p.sexe,"Male");
else if (choix1[1]==1)
strcpy(p.sexe,"Femelle");


p.date.jour= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Jour));
p.date.mois= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Mois));
p.date.annee= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Annee));
p.poids= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Poids));
p.taille= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Taille));


if(((choix1[0]==1) && (choix1[1]==1)) || ((choix1[0]==0) && (choix1[1]==0))|| (strcmp(p.identifiant,"")==0 ) || (strcmp(p.type,"")==0 ))
{
windowErreur = create_windowChampsmer();
gtk_widget_show(windowErreur);

}
else 
{
ajouter_animal(p);
windowSucc = create_dialog1mer();
gtk_widget_show(windowSucc);
}
}





void
on_checkbutton2Male_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choix1[0] = 1;
else
choix1[0] = 0;
}


void
on_checkbutton1femelle_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choix1[1] = 1;
else
choix1[1] = 0;
}


void
on_buttonsupre_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *treeview5;
GtkWidget *liste1;
GtkWidget *input;
GtkWidget *buttonEnable;
GtkWidget *window;
int ok; 
ANIMAL a;
char identifiant[20];
input = lookup_widget(button, "entry3Identifiant");
buttonEnable = lookup_widget(button, "supprimer1"); 
strcpy(identifiant,gtk_entry_get_text(GTK_ENTRY(input)));

window = lookup_widget(button, "Windowsupprimer");
treeview5 = lookup_widget(window, "treeview5Mer");
rechercher_animal(a,identifiant,&ok);

if (ok)
gtk_widget_set_sensitive(buttonEnable, TRUE); 
else
gtk_widget_set_sensitive(buttonEnable, FALSE); 
afficher_troupeauModif(treeview5);
}


void
on_supprimer1_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
char identifiant[30];
ANIMAL p;
GtkWidget *input;
GtkWidget *windowsuccesup;
input = lookup_widget(button, "entry3Identifiant");
strcpy(identifiant, gtk_entry_get_text(GTK_ENTRY(input)));
supprimer_animal(p,identifiant);
windowsuccesup = create_dialog4mer();
gtk_widget_show(windowsuccesup);
}




void
on_confirmer2_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
ANIMAL p;



GtkWidget *input1;
GtkWidget *Jour;
GtkWidget *Mois;
GtkWidget *Annee;
GtkWidget *Poids;
GtkWidget *Taille;
GtkWidget *comboboxentrytype2;
GtkWidget *windowErreur;
GtkWidget *windowSuccees;
GtkWidget *windowM;

comboboxentrytype2= lookup_widget(button, "comboboxentrytype2");

input1 = lookup_widget(button, "entryidentifiant2");
Jour = lookup_widget(button, "spinbuttonJour1");
Mois = lookup_widget(button, "spinbutton3Mois");
Annee = lookup_widget(button, "spinbutton4Annee");
Poids = lookup_widget(button, "spinbutton5Poids");
Taille = lookup_widget(button, "spinbutton6Taille");


strcpy(p.identifiant,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(p.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxentrytype2)));

if (choix[0]==1)
strcpy(p.sexe,"Male");
else if (choix[1]==1)
strcpy(p.sexe,"Femelle");


p.date.jour= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Jour));
p.date.mois= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Mois));
p.date.annee= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Annee));
p.poids= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Poids));
p.taille= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Taille));



if(((choix[0]==1) && (choix[1]==1)) || ((choix[0]==0) && (choix[1]==0)) || (strcmp(p.identifiant,"")==0))
{
windowErreur = create_windowChampsmer();
gtk_widget_show(windowErreur);
}
else
{
modifier_animal(p,tmps); 
windowSuccees = create_dialog2mer();
gtk_widget_show(windowSuccees);
windowM = lookup_widget(button, "Windowmodifier");
gtk_widget_destroy(windowM);
}
}





void
on_checkbutton1male_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choix[0] = 1;
else
choix[0] = 0;
}


void
on_checkbutton2femelle_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choix[1] = 1;
else
choix[1] = 0;
}







void
on_recherchem_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *treeview2;
GtkWidget *liste1;
GtkWidget *input;
GtkWidget *buttonEnable;
GtkWidget *window;
int ok; 
ANIMAL a;
char identifiant[20];
input = lookup_widget(button, "entryidentifiantt");
buttonEnable = lookup_widget(button, "Modifierm"); 
strcpy(identifiant,gtk_entry_get_text(GTK_ENTRY(input)));

window = lookup_widget(button, "windowModification");
treeview2 = lookup_widget(window, "treeview2Mer");
rechercher_animal(a, identifiant, &ok);
if (ok)
gtk_widget_set_sensitive(buttonEnable, TRUE); 
else
gtk_widget_set_sensitive(buttonEnable, FALSE); 
afficher_troupeauModif(treeview2);
}

char tmps[30];
void
on_Modifierm_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
char poids[20];
char taille[20];


ANIMAL a;
GtkWidget *input1;

GtkWidget *windowModifier;
FILE *fp;
fp = fopen("tmp1.bin", "rb");
input1 = lookup_widget(button, "entryidentifiantt");
strcpy(tmps,gtk_entry_get_text(GTK_ENTRY(input1)));
windowModifier = create_Windowmodifier();

gtk_widget_show(windowModifier);

GtkWidget *output1, *output2, *output3, *output4, *output5, *output6, *output7 , *output8 , *output9 ;
if(fp!=NULL)
{
while (fread(&a, sizeof(a), 1, fp))
{
	
	output1 = lookup_widget(windowModifier, "entryidentifiant2");
	
	gtk_entry_set_text(GTK_ENTRY(output1),a.identifiant);


	output2 = lookup_widget(windowModifier, "comboboxentrytype2");
	if (strcmp(a.type,"Brebi")==0)
	gtk_combo_box_set_active(output2,0);
	else if (strcmp(a.type,"Veau")==0)
	gtk_combo_box_set_active(output2,1);
	
	
	output9 = lookup_widget(windowModifier, "checkbutton1male");
	output8 = lookup_widget(windowModifier, "checkbutton2femelle");
	if (strstr(a.sexe,"Femelle"))
	{
	gtk_toggle_button_set_active (output8,TRUE);
	}
	else if (strstr(a.sexe,"Male"))
	{
	gtk_toggle_button_set_active (output9,TRUE);
	}
	
	
	sprintf(poids, "%d", a.poids);
	output3 = lookup_widget(windowModifier, "spinbutton5Poids");
	gtk_entry_set_text(GTK_ENTRY(output3), poids);

	sprintf(taille, "%d", a.taille);
	output4 = lookup_widget(windowModifier, "spinbutton6Taille");
	gtk_entry_set_text(GTK_ENTRY(output4), taille);

	output5 = lookup_widget(windowModifier, "spinbuttonJour1");
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(output5), a.date.jour);


	output6 = lookup_widget(windowModifier, "spinbutton3Mois");
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(output6), a.date.mois);


	output7 = lookup_widget(windowModifier, "spinbutton4Annee");
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(output7), a.date.annee);

}
}

fclose(fp);
}


void
on_button1mar_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
window = lookup_widget(button, "dialog1mer");
gtk_widget_destroy(window);
}


void
on_button2mar_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
window = lookup_widget(button, "dialog2mer");
gtk_widget_destroy(window);
}


void
on_button2RrefreshStat_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *labelVeau;
GtkWidget *labelBrebi;

labelVeau=lookup_widget(button,"labelVeau");
labelBrebi=lookup_widget(button,"labelBrebi");
int veau,brebi;
char veauCh[30], brebiCh[30];
brebi = nombre_brebi();
veau = nombre_veau();
sprintf(veauCh, "%d", veau);
sprintf(brebiCh, "%d", brebi);
gtk_label_set_text(GTK_LABEL(labelVeau), veauCh);
gtk_label_set_text(GTK_LABEL(labelBrebi), brebiCh);

}





void
on_button3_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
Production p;
GtkWidget *identifiant;
GtkWidget *age;
GtkWidget *nombre;
GtkWidget *spinn1, *spinn2;
GtkWidget *dialog;
GtkWidget *windowSuccm;


identifiant = lookup_widget(button, "combobox3");
age = lookup_widget(button, "combobox5");
nombre = lookup_widget(button, "combobox6");
spinn1 = lookup_widget(button,"spinbutton1");
spinn2 = lookup_widget(button,"spinbutton2");

dialog = create_windowChampsmer();

p.lait = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinn1));
p.laine= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinn2));


if((gtk_combo_box_get_active_text(GTK_COMBO_BOX(identifiant))==NULL)) 
{
	gtk_widget_show(dialog);

}



else 
{
strcpy(p.animal.identifiant, gtk_combo_box_get_active_text(GTK_COMBO_BOX(identifiant)));
strcpy(p.age, gtk_combo_box_get_active_text(GTK_COMBO_BOX(age)));
strcpy(p.nombre, gtk_combo_box_get_active_text(GTK_COMBO_BOX(nombre)));
production(p);
windowSuccm = create_dialog6mer();
gtk_widget_show(windowSuccm);
}

}





void
on_button_rech_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *treeview1;
GtkWidget *Combobox;
GtkWidget *dialog;
char identif[30];
Combobox=lookup_widget(button,"combobox4");

dialog = create_dialog5mer();
if(gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combobox))==NULL)
{
	gtk_widget_show(dialog);
}
else
{
strcpy(identif, gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combobox)));
treeview1= lookup_widget(button, "treeview3Mer");
afficher_production(treeview1,identif);
}
}


void
on_button3mar_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
window = lookup_widget(button, "dialog3mer");
gtk_widget_destroy(window);
}


void
on_button4mar_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
window = lookup_widget(button, "dialog4mer");
gtk_widget_destroy(window);
}


void
on_button5mar_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
window = lookup_widget(button, "dialog5mer");
gtk_widget_destroy(window);
}


void
on_button6mar_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
window = lookup_widget(button, "dialog6mer");
gtk_widget_destroy(window);
}





void
on_buttonCreationCompt_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *combo1, *combo2, *username, *password, *window, *treeview;
combo1 = lookup_widget(button, "comboboxComptID");
combo2 = lookup_widget(button, "comboboxComptype");
username = lookup_widget(button, "entryComptUser");
password = lookup_widget(button, "entryComptPass");
compt c;
compt c2;
FILE *fp;
fp = fopen("accounts.bin", "rb");
int id;
int fail = 0;
treeview = lookup_widget(button, "treeview10");

strcpy(c.username,gtk_entry_get_text(GTK_ENTRY(username)));
strcpy(c.password,gtk_entry_get_text(GTK_ENTRY(password)));
if((gtk_combo_box_get_active_text(GTK_COMBO_BOX(combo1))==NULL) || (gtk_combo_box_get_active_text(GTK_COMBO_BOX(combo2))==NULL))
{
window = create_windowChampsseif();
gtk_widget_show(window);
fail=1;
return;
}

if ((strcmp(c.username, "")==0) || (strcmp(c.password, "")==0))
{
window = create_windowChampsseif();
gtk_widget_show(window);
fail=1;
}


id = atoi(gtk_combo_box_get_active_text(GTK_COMBO_BOX(combo1)));
if(fp==NULL)
{
return;
}
else
{
	while (fread(&c2, sizeof(c2), 1, fp))
	{
		if(c2.id==id)
		{
			fail=1;
			return;
		}
	}
}


if(fail==1)
{
	return;
}
else
{
c.id = atoi(gtk_combo_box_get_active_text(GTK_COMBO_BOX(combo1)));
strcpy(c.type, gtk_combo_box_get_active_text(GTK_COMBO_BOX(combo2)));
creer_compt(c);
afficher_comptes(treeview);
}

}

char type[30];
void
on_buttonLogin_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *username, *pass;
GtkWidget *window, *buttonEnable;
GtkWidget *windowFail;
GtkWidget *windowLogin;
GtkWidget *windowChamps;
char user[30], pwd[30];
int fail = 1;
username = lookup_widget(button, "entryLoginUsername");
pass = lookup_widget(button, "entryLoginPassword");
strcpy(user,gtk_entry_get_text(GTK_ENTRY(username)));
strcpy(pwd,gtk_entry_get_text(GTK_ENTRY(pass)));
if((verif_login(user,pwd, &type)==1) && (strcmp(type, "Modérateur")!=0))
{
window = create_windowHome();
gtk_widget_show(window);
windowLogin = lookup_widget(button, "windowLogin");
gtk_widget_destroy(windowLogin);
fail = 0;

}
else if((verif_login(user,pwd, &type)==1) && (strcmp(type, "Modérateur")==0))
{
window = create_windowHome();
gtk_widget_show(window);
buttonEnable = lookup_widget(window, "eventbox3");
gtk_widget_show(buttonEnable);
windowLogin = lookup_widget(button, "windowLogin");
gtk_widget_destroy(windowLogin);
fail = 0;
}
else if ((strcmp(user, "")==0) || (strcmp(pwd, "")==0))
{
windowChamps = create_windowChampsseif();
gtk_widget_show(windowChamps);
return;
}
if (fail==1)
{
windowFail = create_dialogErreur();
gtk_widget_show(windowFail);


}
}
///////////////////////////////Boutton Acceuil SEIF ///////////////////////////
void
on_buttonAcceuil_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowSupprimer;
GtkWidget *windowMenu;
GtkWidget *windowGestionEmp;
GtkWidget *windowAjoutEmploye;
GtkWidget *windowModifier;
GtkWidget *windowListeEmployes;
GtkWidget *windowpointage;
GtkWidget *buttonEnable;
windowSupprimer = lookup_widget(button, "windowSupprimerEmploye");
gtk_widget_destroy(windowSupprimer);

windowGestionEmp = lookup_widget(button, "windowGestionEmployes");
gtk_widget_destroy(windowGestionEmp);

windowModifier = lookup_widget(button, "windowModifierEmploye");
gtk_widget_destroy(windowModifier);

windowAjoutEmploye = lookup_widget(button, "windowAjoutEmploye");
gtk_widget_destroy(windowAjoutEmploye);


windowListeEmployes = lookup_widget(button, "windowListeEmployes");
gtk_widget_destroy(windowListeEmployes);
windowpointage = lookup_widget(button, "windowPointage");
gtk_widget_destroy(windowpointage);



if(strcmp(type, "Modérateur")==0)
{
windowMenu = create_windowHome();
gtk_widget_show(windowMenu);
buttonEnable = lookup_widget(windowMenu, "eventbox3");
gtk_widget_show(buttonEnable);
}
else
{
windowMenu = create_windowHome();
gtk_widget_show(windowMenu);
}
}
/////////////////////////////////////////////////////////////////////////////////////

gboolean
on_eventbox3_button_press_event        (GtkWidget       *widget,
                                        GdkEventButton  *event,
                                        gpointer         user_data)
{
GtkWidget *windowCompt;
GtkWidget *window;
GtkWidget *combobox1;
GtkWidget *combobox2;
GtkWidget *combobox3;
GtkWidget *treeview;
char id[30];
Employe e;
FILE *fp;
fp = fopen("utilisateurs.bin", "rb");
windowCompt = create_windowGestionComptes();
gtk_widget_show(windowCompt);
treeview = lookup_widget(windowCompt, "treeview10");
afficher_comptes(treeview);
window = lookup_widget(widget, "windowHome");
gtk_widget_destroy(window);
combobox1 = lookup_widget(windowCompt, "comboboxComptID");
combobox2 = lookup_widget(windowCompt, "comboboxAdminID");
combobox3 = lookup_widget(windowCompt, "comboboxAdminSupp");
if(fp!=NULL)
{
while (fread(&e,sizeof(e),1,fp))
{
sprintf(id,"%d",e.id); //convert employe id from int to char 
gtk_combo_box_append_text(GTK_COMBO_BOX(combobox1), id);
gtk_combo_box_append_text(GTK_COMBO_BOX(combobox2), id); //append id's in combobox from user file(window de Pointage)
gtk_combo_box_append_text(GTK_COMBO_BOX(combobox3), id);

}
fclose(fp);
}

  return FALSE;
}


gboolean
on_eventbox4_button_press_event        (GtkWidget       *widget,
                                        GdkEventButton  *event,
                                        gpointer         user_data)
{
GtkWidget *windowMeriam;
GtkWidget *window;
windowMeriam = create_WindowMenu();
gtk_widget_show(windowMeriam);
window = lookup_widget(widget, "windowHome");
gtk_widget_destroy(window);

  return FALSE;
}



void
on_DeconnectionMer_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowsupprimer;
GtkWidget *windowLogin;
GtkWidget *windowajouter;
GtkWidget *windowmodification;
GtkWidget *windowliste;
GtkWidget *windowp;
GtkWidget *windowMenu;

windowsupprimer = lookup_widget(button, "Windowsupprimer");
gtk_widget_destroy(windowsupprimer);

windowmodification = lookup_widget(button, "windowModification");
gtk_widget_destroy(windowmodification);

windowajouter = lookup_widget(button, "Windowajouter");
gtk_widget_destroy(windowajouter);


windowliste = lookup_widget(button, "Windowliste");
gtk_widget_destroy(windowliste);

windowp = lookup_widget(button, "windowproduction");
gtk_widget_destroy(windowp);


windowMenu = lookup_widget(button, "WindowMenu");
gtk_widget_destroy(windowMenu);



windowLogin = create_windowLogin();
gtk_widget_show(windowLogin);
}


void
on_buttonAdminModifier_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *combobox, *window, *treeview;
compt c;
compt c2;
int id;
FILE *fp;
fp = fopen("comptrecherche.bin", "rb");
if (fp==NULL)
{
return;
}
else
{
combobox = lookup_widget(button, "comboboxAdminType");
treeview = lookup_widget(button, "treeview10");
while (fread(&c, sizeof(c), 1, fp))
{
	c2.id = c.id;
	id = c.id;
	strcpy(c2.username, c.username);	
	strcpy(c2.password, c.password);
}
fclose(fp);
if(gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox))==NULL)
{
window = create_windowChampsseif();
gtk_widget_show(window);
return;
}
strcpy(c2.type, gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)));
modifier_compt(c2, id);
afficher_comptes(treeview);

}

}


void
on_buttonAdminRechercher_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *treeview8;
GtkWidget *input;
GtkWidget *buttonEnable;
GtkWidget *window;
int ok, id;
compt c;

input = lookup_widget(button, "comboboxAdminID");
buttonEnable = lookup_widget(button, "buttonAdminModifier"); //Pointeur sur bouton Modifier
if(gtk_combo_box_get_active_text(GTK_COMBO_BOX(input))==NULL)
{
window = create_windowChampsseif();
gtk_widget_show(window);
return;
}
id = atoi(gtk_combo_box_get_active_text(GTK_COMBO_BOX(input)));

treeview8 = lookup_widget(button, "treeview8");
chercher_compt(c, id, &ok);
if (ok)
gtk_widget_set_sensitive(buttonEnable, TRUE); //Set Sensitivity to TRUE
else
gtk_widget_set_sensitive(buttonEnable, FALSE); //Set Sensitivity to FALSE

afficher_comptModif(treeview8);


}


void
on_buttonAdminChercherSupp_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *treeview9;
GtkWidget *input;
GtkWidget *buttonEnable;
GtkWidget *window;
int ok, id;
compt c;
FILE *fp;
input = lookup_widget(button, "comboboxAdminSupp");
buttonEnable = lookup_widget(button, "buttonAdminSupp"); //Pointeur sur bouton Modifier
if(gtk_combo_box_get_active_text(GTK_COMBO_BOX(input))==NULL)
{
window = create_windowChampsseif();
gtk_widget_show(window);
return;
}
id = atoi(gtk_combo_box_get_active_text(GTK_COMBO_BOX(input)));

treeview9 = lookup_widget(button, "treeview9");
chercher_compt(c, id, &ok);
if (ok)
gtk_widget_set_sensitive(buttonEnable, TRUE); //Set Sensitivity to TRUE
else
gtk_widget_set_sensitive(buttonEnable, FALSE); //Set Sensitivity to FALSE

afficher_comptModif(treeview9);

}


void
on_buttonAdminSupp_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
int id;
GtkWidget *windowSuccees, *treeview;
compt c;
GtkWidget *input;
input = lookup_widget(button, "comboboxAdminSupp");
treeview = lookup_widget(button, "treeview10");
id = atoi(gtk_combo_box_get_active_text(GTK_COMBO_BOX(input)));
supprimer_compt(c, id);
afficher_comptes(treeview);
windowSuccees = create_dialog3seif();
gtk_widget_show(windowSuccees);

}


void
on_okbutton7_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
window = lookup_widget(button, "dialogErreur");
gtk_widget_destroy(window);

}


/*void
on_buttonsupprimerg_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{

}*/

///////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

//interface "gestion"
void
on_buttonlistclient_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{ 	GtkWidget *treeview1;
	GtkWidget * windowlistclient;
	GtkWidget * windowgestion;

	windowlistclient = create_windowlistclient ();
  	gtk_widget_show (windowlistclient);	

	treeview1=lookup_widget(windowlistclient,"treeview1");
	afficher_client(treeview1);

	 windowgestion = lookup_widget(button ,"windowgestion");
         gtk_widget_destroy(windowgestion);
		
}

//interface "gestion"
void
on_buttonservices_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget * windowservices;
 GtkWidget * windowgestion; 

 windowservices = create_windowservices ();
 gtk_widget_show (windowservices);

 windowgestion = lookup_widget(button ,"windowgestion");
 gtk_widget_destroy(windowgestion);
}

//interface "supprimer" 
void
on_buttonsupprimer_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{

char cin[10];
client c;
GtkWidget *input;
// GtkWidget *treeview4;
GtkWidget * dialogsupprimer;
GtkWidget *windowsupprimer;
GtkWidget *treeview;

input = lookup_widget(button,"entryidentifiant");
strcpy(cin,gtk_entry_get_text(GTK_ENTRY(input)));
supprimer_client( c,cin);

  dialogsupprimer = create_dialogsupprimer ();
  gtk_widget_show (dialogsupprimer);

 windowsupprimer = lookup_widget(button ,"windowsupprimer");
 gtk_widget_destroy(windowsupprimer);

 windowsupprimer = create_windowsupprimer ();
 gtk_widget_show (windowsupprimer);	

 treeview = lookup_widget(windowsupprimer ,"treeview_sup");
 afficher_client(treeview);

}



//interface "gestion"
void
on_buttonmodifier_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{ GtkWidget * windowmodifier  ;
  GtkWidget * windowgestion;
  GtkWidget * treeview;
	 
 windowmodifier = create_windowmodifier ();
  gtk_widget_show (windowmodifier); 


 windowgestion = lookup_widget(button ,"windowgestion");
 gtk_widget_destroy(windowgestion);

  treeview = lookup_widget(windowmodifier ,"treeview_client");
  afficher_client(treeview);	
}

//interface "gestion"
void
on_buttonajouter_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{ GtkWidget * windowajouter ;
  GtkWidget * windowgestion;

 windowajouter = create_windowajouter ();
 gtk_widget_show (windowajouter);

 windowgestion = lookup_widget(button ,"windowgestion");
 gtk_widget_destroy(windowgestion);
}

//tt les interfaces sauf ajouter
void
on_buttonacceuil_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{  GtkWidget * windowgestion;
  
   GtkWidget *windowmodifier;
   GtkWidget *windowsupprimer;
   GtkWidget *windowservices;
   GtkWidget *windowlistclient;
   GtkWidget * windowachats;

  windowgestion = create_windowgestion ();
  gtk_widget_show (windowgestion);
  

windowmodifier = lookup_widget(button ,"windowmodifier");
 gtk_widget_destroy(windowmodifier);


windowsupprimer = lookup_widget(button ,"windowsupprimer");
 gtk_widget_destroy(windowsupprimer);


windowlistclient = lookup_widget(button ,"windowlistclient");
 gtk_widget_destroy(windowlistclient);


windowservices = lookup_widget(button ,"windowservices");
 gtk_widget_destroy(windowservices);


windowachats = lookup_widget(button ,"windowachats");
 gtk_widget_destroy(windowachats);
}


void
on_buttonretour_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
  
}


void
on_buttondeconnection_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{

}


//interface "services"
void
on_buttonAchats_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget * windowachats;
  GtkWidget *windowservices;

 windowachats = create_windowachats ();
 gtk_widget_show (windowachats);

windowservices = lookup_widget(button ,"windowservices");
 gtk_widget_destroy(windowservices);
}
/*
//interface "liste des clients"
void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                     GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
	gchar nom;
	gchar prenom;
	gchar adresse;
	gchar gouvernement;
	gchar sexe;
	gchar gsm;
	gchar cin;
	gchar mail;
	gchar date;
	client c;
 
 	GtkTreeModel *model = gtk_tree_view_get_model(treeview);
	
	if(gtk_tree_model_get_iter(model, &iter , path))
 	{//obts des val de ligne selectionnee
	gtk_tree_model_get (GTK_LIST_STORE(model), &iter, 0, &nom, 1, &prenom,2,&cin,3,&sexe,4,&date,5,&gsm,6,&gouvernement,7,&adresse,8,&mail, -1);
	//copie des val ds la va p de type p pour passer a la fct de supp
	
	strcpy(c.nom,nom);
	strcpy(c.prenom,prenom);
	strcpy(c.cin,cin);
	strcpy(c.cin,cin);
	strcpy(c.gsm,gsm);
	strcpy(c.gouvernement,gouvernement);
	strcpy(c.adresse,adresse);
	strcpy(c.mail,mail);
	//mise de la fct sup
	 //supprimer_client(client c)
	//mise a jour de l'aff de tree
	 afficher_client(treeview);
	}
}*/
int choixc[]={0,0};

void
on_checkbuttonhomme_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{choixc[0]=1;}
}


void
on_checkbuttonfemme_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{choixc[1]=1;}
}

//interface "ajouter"
void
on_button_ajouter_clicked              (GtkButton        *button,
                                        gpointer         user_data)
{
client c;
char texte[100]="";
GtkWidget *nom , *prenom, *cin , *gsm, *gouvernement ,*adresse ,*mail ,*jour, *mois,*annee;
GtkWidget *windowajouter;
GtkWidget *dialog2client;
GtkWidget *dialog1client;

nom = lookup_widget(button, "entrynom");
prenom = lookup_widget(button, "entryprenom");
cin = lookup_widget(button, "entrycin");
gsm = lookup_widget(button, "entrygsm");
gouvernement = lookup_widget(button, "entrygouvernement");
adresse = lookup_widget(button, "entryadresse");
mail = lookup_widget(button, "entrymail");



strcpy(c.nom, gtk_entry_get_text(GTK_ENTRY(nom))); 
strcpy(c.prenom, gtk_entry_get_text(GTK_ENTRY(prenom)));  
strcpy(c.cin, gtk_entry_get_text(GTK_ENTRY(cin)));
strcpy(c.gsm, gtk_entry_get_text(GTK_ENTRY(gsm)));
strcpy(c.gouvernement, gtk_entry_get_text(GTK_ENTRY(gouvernement))); 
strcpy(c.adresse, gtk_entry_get_text(GTK_ENTRY(adresse))); 
strcpy(c.mail, gtk_entry_get_text(GTK_ENTRY(mail)));

jour = lookup_widget(button, "spinbuttonjourc");
mois = lookup_widget(button, "spinbuttonmoisc");
annee = lookup_widget(button, "spinbuttonanneec");
 
	if(choixc[0]==1)
	strcpy(c.sexe," Homme");
	if(choixc[1]==1)
	strcpy(c.sexe," Femme");
	
c.date_de_naissance.jour= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
c.date_de_naissance.mois= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
c.date_de_naissance.annee= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));

if((strcmp(c.nom,"")==0) || (strcmp(c.prenom,"")==0) || (strcmp(c.cin,"")==0) || ((choixc[0]==1) && (choixc[1]==1)) || ((choixc[0]==0) && (choixc[1]==0)) || (strcmp(c.gsm,"")==0) || (strcmp(c.gouvernement,"")==0) || (strcmp(c.adresse,"")==0) || (strcmp(c.mail,"")==0))
{
 dialog2client = create_dialog2client ();
  gtk_widget_show (dialog2client);
}
else 
 { 
 ajouter_client(c);
  dialog1client = create_dialog1client ();
  gtk_widget_show (dialog1client);
 }
}

//interface "modifier"
void
on_button_rechercher_clicked           (GtkButton      *button,
                                        gpointer         user_data)
{GtkWidget *treeview;

GtkWidget *liste;
GtkWidget *input;
GtkWidget *window;
GtkWidget *buttonEnable;
GtkWidget * windowlistclient;
client c;
char cin[10];
int verif;
input = lookup_widget(button, "entryidentifiant");
strcpy(cin,gtk_entry_get_text(GTK_ENTRY(input)));

buttonEnable = lookup_widget(button,"button_modifierc");

window = lookup_widget(button, "windowmodifier");
treeview = lookup_widget(window, "treeview");
rechercher_client(c, cin,&verif);

if(verif)
gtk_widget_set_sensitive(buttonEnable,TRUE);
else
gtk_widget_set_sensitive(buttonEnable,FALSE);


afficher_client_modifier(treeview);

}


//interface "ajouter"
void
on_button_afficher_clicked             (GtkButton      *button,
                                        gpointer         user_data)
{

	GtkWidget *windowajouter;
	GtkWidget * windowlistclient;
	GtkWidget *treeview1;
	

	windowajouter=lookup_widget(button,"windowajouter");
	gtk_widget_destroy(windowajouter);

	windowlistclient =lookup_widget(button,"windowlistclient");

	windowlistclient = create_windowlistclient ();
  	gtk_widget_show (windowlistclient);

	treeview1=lookup_widget(windowlistclient,"treeview1");
	afficher_client(treeview1);
	
}






//interface"gestion"
void
on_buttonsupprimerg_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
GtkWidget *windowgestion;
GtkWidget *treeview;

windowgestion = lookup_widget(button ,"windowgestion");
gtk_widget_destroy(windowgestion);

window=create_windowsupprimer();
gtk_widget_show(window);

 treeview = lookup_widget(window ,"treeview_sup");
 afficher_client(treeview);

}

//interface modifier -->modifier client


char tmps[30];// stocker dans la variable tmps le cin du client a modifier pour l'utiliser dans l'affichage

int i; //variable pour savoir le numero d'identifiant 

int choix1c[] = {0,0};

void
on_button_modifier_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
client c;
FILE *fp1;
fp1 = fopen("client.bin", "rb");
if (fp1==NULL)
    {
	i = 0;
    }
    
 
    else
    {
	while (fread(&c,sizeof(c),1,fp1))
	{
		if (strcmp(c.cin,tmps)==0){
		i = c.cin; // i prends la valeur du client qui a la cin à rechercher
		break;}
	}
    }

GtkWidget *windowerreur;
GtkWidget *dialog1client;
GtkWidget *dialog2client;
GtkWidget *nom1;
GtkWidget *prenom1;
GtkWidget *cin1;
GtkWidget *gsm1;
GtkWidget *gouvernement1;
GtkWidget *adresse1;
GtkWidget *mail1;
GtkWidget *jour;
GtkWidget *mois;
GtkWidget *annee;

nom1 = lookup_widget(button, "entrynommodif");
prenom1 = lookup_widget(button, "entryprenommodif");
cin1 = lookup_widget(button, "entrycinmodif");
gsm1 = lookup_widget(button, "entrygsmmodif");
gouvernement1 = lookup_widget(button, "entrygouvernementmodif");
adresse1 = lookup_widget(button, "entryadressemodif");
mail1 = lookup_widget(button, "entrymailmodif");

jour = lookup_widget(button, "spinbuttonjourmodif");
mois = lookup_widget(button, "spinbuttonmoismodif");
annee = lookup_widget(button, "spinbuttonanneemodif");

strcpy(c.nom,gtk_entry_get_text(GTK_ENTRY(nom1)));
strcpy(c.prenom,gtk_entry_get_text(GTK_ENTRY(prenom1)));
strcpy(c.cin,gtk_entry_get_text(GTK_ENTRY(cin1)));
strcpy(c.gsm,gtk_entry_get_text(GTK_ENTRY(gsm1)));
strcpy(c.gouvernement,gtk_entry_get_text(GTK_ENTRY(gouvernement1)));
strcpy(c.adresse,gtk_entry_get_text(GTK_ENTRY(adresse1)));
strcpy(c.mail,gtk_entry_get_text(GTK_ENTRY(mail1)));

if (choix1c[0]==1)
strcpy(c.sexe,"Homme");
else if (choix1c[1]==1)
strcpy(c.sexe,"Femme");

c.date_de_naissance.jour= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
c.date_de_naissance.mois= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
c.date_de_naissance.annee= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
c.cin == i;

if((strcmp(c.nom,"")==0) || (strcmp(c.prenom,"")==0) || (strcmp(c.cin,"")==0) || ((choix1c[0]==1) && (choix1c[1]==1)) || ((choix1c[0]==0) && (choix1c[1]==0)) || (strcmp(c.gsm,"")==0) || (strcmp(c.gouvernement,"")==0) || (strcmp(c.adresse,"")==0) || (strcmp(c.mail,"")==0))


{
  dialog2client = create_dialog2client ();
  gtk_widget_show (dialog2client);
}
else
{
modifier_client(c, tmps); 
 
 dialog1client = create_dialog1client ();
 gtk_widget_show (dialog1client);
 
dialog1client = lookup_widget(button ,"dialog1");
gtk_widget_destroy(dialog1client);
}

}

// interface "modifier client"
void
on_button_modifierc_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{ 
GtkWidget *windowmodifierc;
client c;
GtkWidget *input1;
GtkWidget *windowmodifier;

FILE *f;
f = fopen("tmpr.bin", "rb");
input1 = lookup_widget(button, "entryidentifiant");

strcpy(tmps,gtk_entry_get_text(GTK_ENTRY(input1)));

windowmodifierc = create_windowmodifierc ();
gtk_widget_show (windowmodifierc);


windowmodifier = lookup_widget(button ,"windowmodifier");
 gtk_widget_destroy(windowmodifier);

// 
GtkWidget *nom1, *prenom1, *cin1, *gsm1, *gouvernement1, *adresse1, *mail1, *jour, *annee, *mois;
if(f!=NULL)
  {
while (fread(&c, sizeof(c), 1, f))
	{
	nom1 = lookup_widget(windowmodifierc, "entrynommodif");
	gtk_entry_set_text(GTK_ENTRY(nom1), c.nom);

	prenom1 = lookup_widget(windowmodifierc, "entryprenommodif");
	gtk_entry_set_text(GTK_ENTRY(prenom1), c.prenom);

	cin1 = lookup_widget(windowmodifierc, "entrycinmodif");
	gtk_entry_set_text(GTK_ENTRY(cin1), c.cin);

	gsm1 = lookup_widget(windowmodifierc, "entrygsmmodif");
	gtk_entry_set_text(GTK_ENTRY(gsm1), c.gsm);

	gouvernement1 = lookup_widget(windowmodifierc, "entrygouvernementmodif");
	gtk_entry_set_text(GTK_ENTRY(gouvernement1), c.gouvernement);

	adresse1 = lookup_widget(windowmodifierc, "entryadressemodif");
	gtk_entry_set_text(GTK_ENTRY(adresse1), c.adresse);

	mail1 = lookup_widget(windowmodifierc, "entrymailmodif");
	gtk_entry_set_text(GTK_ENTRY(mail1), c.mail);

	jour = lookup_widget(windowmodifierc, "spinbuttonjourmodif");
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(jour), c.date_de_naissance.jour);


	mois = lookup_widget(windowmodifierc, "spinbuttonmoismodif");
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(mois), c.date_de_naissance.mois);


	annee = lookup_widget(windowmodifierc, "spinbuttonanneemodif");
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(annee), c.date_de_naissance.annee);
	}
  }

//
fclose(f);
}

void
on_button_actualiser_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{

	GtkWidget *windowajouter;
	GtkWidget * windowlistclient;
	GtkWidget *treeview1;
	

	windowajouter=lookup_widget(button,"windowajouter");
	gtk_widget_destroy(windowajouter);

	windowlistclient =lookup_widget(button,"windowlistclient");


	treeview1=lookup_widget(windowlistclient,"treeview1");
	afficher_client(treeview1);
	
}


void
on_checkbutton_femmemodif_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{choix1c[1]=1;}
}


void
on_checkbutton_hommemodif_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{choix1c[0]=1;}
}


void
on_buttonacceuilaj_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget * windowgestion;
GtkWidget *windowajouter;


  windowgestion = create_windowgestion ();
  gtk_widget_show (windowgestion);
  
 windowajouter = lookup_widget(button ,"windowajouter");
 gtk_widget_destroy(windowajouter);

}

// ajouter averc succee
/*void
on_button1_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{ GtkWidget *dialog1client;
 
dialog1client = lookup_widget(button ,"dialog1");
gtk_widget_destroy(dialog1client);

}*/

//alert champ pas remplie
void
on_button_ok_att_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *dialog2client;

 dialog2client = lookup_widget(button , "dialog2client");
gtk_widget_destroy(dialog2client);
}

//commande

int x;

void
on_radiobutton_ouic_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{x=0;}
}


void
on_radiobutton_nonc_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{x=2;}
}

int veau;
int brebi;
int yaourt;
int rigouta;

void
on_button_ajouter_achat_clicked        (GtkButton         *button,
                                        gpointer         user_data)
{
achat a;
//char texte1[100]="";

char quantite_brebis[30],quantite_veaux[30],quantite_yaourt[30],quantite_rigouta[30];

float som=0;
float s1=0;
float s2=0;
float s3=0;
float s4=0;
char s[100];

GtkWidget *nom , *prenom, *cin,*mail ,*jour, *mois,*annee, *quantiteveaux, *quantitebrebis, *quantiteyaourt, *quantiterigouta;

GtkWidget *windowajouter;
GtkWidget *dialog2client;
GtkWidget *dialog1client;
GtkWidget *output;

int verif;

nom = lookup_widget(button, "entrynom");
prenom = lookup_widget(button, "entryprenom");
cin = lookup_widget(button, "entrycin");
mail = lookup_widget(button, "entrymail");

quantitebrebis = lookup_widget(button, "entryquantitebrebi");
quantiteveaux = lookup_widget(button, "entryquantiteveau");
quantiteyaourt = lookup_widget(button, "entryquantiteyaourt");
quantiterigouta = lookup_widget(button, "entryquantiterigouta");

strcpy(a.c.nom, gtk_entry_get_text(GTK_ENTRY(nom))); 
strcpy(a.c.prenom, gtk_entry_get_text(GTK_ENTRY(prenom)));  
strcpy(a.c.cin, gtk_entry_get_text(GTK_ENTRY(cin)));
strcpy(a.c.mail, gtk_entry_get_text(GTK_ENTRY(mail)));
 
strcpy(quantite_brebis, gtk_entry_get_text(GTK_ENTRY(quantitebrebis)));
strcpy(quantite_veaux, gtk_entry_get_text(GTK_ENTRY(quantiteveaux)));
strcpy(quantite_yaourt, gtk_entry_get_text(GTK_ENTRY(quantiteyaourt)));
strcpy(quantite_rigouta, gtk_entry_get_text(GTK_ENTRY(quantiterigouta)));

a.quantite_brebis= atoi(quantite_brebis);
a.quantite_veaux= atoi(quantite_veaux);
a.quantite_yaourt= atoi(quantite_yaourt);
a.quantite_rigouta= atoi(quantite_rigouta);

jour = lookup_widget(button, "spinbuttonjourachat");
mois = lookup_widget(button, "spinbuttonmoisachat");
annee = lookup_widget(button, "spinbuttonanneeachat");



	 
	if(x==0)
	strcpy(a.livraison," Oui");
	if(x==2)
	strcpy(a.livraison," Non");

	if(veau==1)
        strcpy(a.veau,"OUI");
	if(veau==0)
	strcpy(a.veau,"NON");

	if(brebi==1)
        strcpy(a.brebi,"OUI");
	if(brebi==0)
	strcpy(a.brebi,"NON");

	if(yaourt==1)
        strcpy(a.yaourt,"OUI");
	if(yaourt==0)
	strcpy(a.yaourt,"NON");

	if(rigouta==1)
        strcpy(a.rigouta,"OUI");
	if(rigouta==0)
	strcpy(a.rigouta,"NON");
	
		
a.date_de_paiement.jour= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
a.date_de_paiement.mois= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
a.date_de_paiement.annee= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));


 	if(brebi==1)
	 { s1=((a.quantite_brebis)*170);}
	 else
	{ s1=0;} 

	if(veau==1)
	 { s2=((a.quantite_veaux)*300);}
	 else
	{ s2=0;} 
         
	if(yaourt==1)
	 { s3=((a.quantite_yaourt)*1.2);}
	 else
	{ s3=0;}
	
 	if(rigouta==1)
	 { s4=((a.quantite_rigouta)*6);}
	 else
	{ s4=0;}

	som=s1+s2+s3+s4;

sprintf(s, "votre somme est: %f ",som);
output = lookup_widget(button, "labelsomme");
gtk_label_set_text(GTK_LABEL(output), s);


if((strcmp(a.c.nom,"")==0) || (strcmp(a.c.prenom,"")==0) || (strcmp(a.c.cin,"")==0)|| (strcmp(a.c.mail,"")==0) || ((brebi==1) && (brebi==0)) || ((veau==1) && (veau==0)) || ((yaourt==1) && (yaourt==0)) || ((rigouta==1) && (rigouta==0)))
 
{  dialog2client = create_dialog2client ();
  gtk_widget_show (dialog2client);
}
else 
 { 
 ajouter_achat(a);
  dialog1client = create_dialog1client ();
  gtk_widget_show (dialog1client);
 }
}


void
on_button_affichier_achat_clicked      (GtkButton        *button,
                                        gpointer         user_data)
{
    GtkWidget * window_liste_achat;
	
	GtkWidget *treeview2;
	



	window_liste_achat =lookup_widget(button," window_liste_achat");

	

	window_liste_achat = create_window_liste_achat ();
         gtk_widget_show (window_liste_achat);

	treeview2=lookup_widget(window_liste_achat,"treeview2");

	afficher_achat(treeview2);
}


void
on_checkbutton_oui_brebi_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{ 

GtkWidget *buttonEnable;

GtkWidget *window;

window = create_windowachats ();

buttonEnable = lookup_widget(window,"entryquantitebrebi");


if (gtk_toggle_button_get_active(togglebutton))
{brebi=1;

gtk_widget_set_sensitive(buttonEnable , TRUE);


}


}

void
on_checkbutton_non_brebi_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{


GtkWidget *buttonEnable;

GtkWidget *window;

window = create_windowachats ();

buttonEnable = lookup_widget(window,"entryquantitebrebi");

if (gtk_toggle_button_get_active(togglebutton))
{
brebi =0;

gtk_widget_set_sensitive(buttonEnable , FALSE);
}

}


void
on_checkbutton_oui_veau_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{veau=1;}
}


void
on_checkbutton_non_veau_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{veau=0;}
}


void
on_checkbutton_oui_yaourt_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{yaourt=1;}
}


void
on_checkbutton_non_yaourt_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{yaourt=0;}
}


void
on_checkbutton_oui_rigouta_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{rigouta=1;}
}


void
on_checkbutton_non_rigouta_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{rigouta=0;}
}
// interface "reservationn"

void
on_button_ajouter_reservation_clicked  (GtkButton       *button,
                                        gpointer         user_data)
{
{
reservation r;
//char texte1[100]="";
char num[30];
GtkWidget *nom , *prenom, *num1 ,*mail ,*jour, *mois,*annee, *combobox1;
GtkWidget *windowajouter;
GtkWidget *windowerreur;
GtkWidget *dialog1client;

nom = lookup_widget(button, "entrynom");
prenom = lookup_widget(button, "entryprenon");
num1 = lookup_widget(button, "entrynumpersonne");
mail = lookup_widget(button, "entrymail");
combobox1 =  lookup_widget(button, "combobox1");


strcpy(r.c.nom, gtk_entry_get_text(GTK_ENTRY(nom))); 
strcpy(r.c.prenom, gtk_entry_get_text(GTK_ENTRY(prenom)));  
strcpy(num, gtk_entry_get_text(GTK_ENTRY(num1)));
strcpy(r.c.mail, gtk_entry_get_text(GTK_ENTRY(mail)));
strcpy(r.type_reservation, gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)));

r.num= atoi(num);

jour = lookup_widget(button, "spinbuttonjourres");
mois = lookup_widget(button, "spinbuttonmoisres");
annee = lookup_widget(button, "spinbuttonanneeres");
 
	
	
r.date_de_reservation.jour= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
r.date_de_reservation.mois= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
r.date_de_reservation.annee= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));

if((strcmp(r.c.nom,"")==0) || (strcmp(r.c.prenom,"")==0) || (strcmp(r.c.mail,"")==0)) 
{ windowerreur = create_windowerreur ();
  gtk_widget_show (windowerreur);
}
else 
 { 
 ajouter_reservation(r);
  dialog1client = create_dialog1client ();
  gtk_widget_show (dialog1client);
 }
}
}

//interface "reservation"
void
on_button_affichier_reservation_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget * windowliste_reservation;
	
		GtkWidget *treeview3;
		
		GtkWidget * window_reservation;

	window_reservation = lookup_widget(button, "window_reservation");
	gtk_widget_destroy(window_reservation);

        windowliste_reservation =lookup_widget(button,"windowliste_reservation");

	windowliste_reservation = create_windowliste_reservation ();
  	gtk_widget_show (windowliste_reservation);

	treeview3=lookup_widget(windowliste_reservation,"treeview3");
	afficher_reservation(treeview3);
}

//interface "service"
void
on_button_reservation_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget * window_reservation;
	GtkWidget *windowservices;

	windowservices = lookup_widget(button, "windowservices");
	gtk_widget_destroy(windowservices);

	window_reservation = create_window_reservation ();
	gtk_widget_show (window_reservation);

}



//interface "service"
void
on_buttonlist_achatse_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{

   


        GtkWidget * window_liste_achat;
	GtkWidget *treeview2;
	GtkWidget *windowservices;

	windowservices = lookup_widget(button, "windowservices");
	gtk_widget_destroy(windowservices);

	window_liste_achat =lookup_widget(button," window_liste_achat");

	window_liste_achat = create_window_liste_achat ();
         gtk_widget_show (window_liste_achat);

	treeview2=lookup_widget(window_liste_achat,"treeview2");
	afficher_achat(treeview2);

}

//interface service
void
on_button_liste_res_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
 	GtkWidget * windowliste_reservation;
	GtkWidget *treeview3;
	GtkWidget *windowservices;

	windowservices = lookup_widget(button, "windowservices");
	gtk_widget_destroy(windowservices);

	windowliste_reservation =lookup_widget(button,"windowliste_reservation");

	windowliste_reservation = create_windowliste_reservation ();
        gtk_widget_show (windowliste_reservation);

	treeview3=lookup_widget(windowliste_reservation,"treeview3");
	afficher_reservation(treeview3);
}

//interface modif client
void
on_button_retour_modif_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget * windowmodifierc;
 	GtkWidget * windowmodifier; 
	GtkWidget * treeview;

 windowmodifier = create_windowmodifier ();
 gtk_widget_show (windowmodifier);
 
 windowmodifierc = lookup_widget(button ,"windowmodifierc");
 gtk_widget_destroy(windowmodifierc);

 treeview = lookup_widget(windowmodifier , "treeview_client");
 afficher_client(treeview);

}

//interface liste achat
void
on_button_retour_lista_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *windowservices;
	GtkWidget * window_liste_achat;

 windowservices = create_windowservices ();
 gtk_widget_show (windowservices);

  window_liste_achat = lookup_widget(button ,"window_liste_achat");
 gtk_widget_destroy(window_liste_achat);

}

//interface res
void
on_button_retour_res_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
      GtkWidget *windowservices;
      GtkWidget * window_liste_achat;
       GtkWidget * window_reservation;

 windowservices = create_windowservices ();
 gtk_widget_show (windowservices);

  window_reservation = lookup_widget(button ,"window_reservation");
 gtk_widget_destroy(window_reservation);
}

//interface liste res
void
on_buttonretour_listres_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *windowservices;
	GtkWidget * windowliste_reservation;

 windowservices = create_windowservices ();
 gtk_widget_show (windowservices);

  windowliste_reservation = lookup_widget(button ,"windowliste_reservation");
 gtk_widget_destroy(windowliste_reservation);
}

//interfacesup
void
on_button_rechercher_sup_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *treeview;
GtkWidget *liste;
GtkWidget *input;
GtkWidget *window;
GtkWidget *buttonEnable;
GtkWidget * windowlistclient;
client c;
char cin[10];
int verif;

input = lookup_widget(button, "entryidentifiant");
strcpy(cin,gtk_entry_get_text(GTK_ENTRY(input)));

buttonEnable = lookup_widget(button,"buttonsupprimer");

window = lookup_widget(button, "windowsupprimer");
treeview = lookup_widget(window, "treeview_rechsup");
rechercher_client(c, cin,&verif);

if(verif)
gtk_widget_set_sensitive(buttonEnable,TRUE);
else
gtk_widget_set_sensitive(buttonEnable,FALSE);

 afficher_client_supprimer(treeview);
}


gboolean
on_treeview_rechsup_start_interactive_search
                                        (GtkTreeView     *treeview,
                                        gpointer         user_data)
{

  return FALSE;
}

//interface "achat"
void
on_buttonretour_achat_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
 GtkWidget *windowservices;
 GtkWidget *windowachats;

 windowachats = lookup_widget(button ,"windowachats");
 gtk_widget_destroy(windowachats);

 windowservices = create_windowservices ();
 gtk_widget_show (windowservices);


}


void
on_button_retour_meilleur_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
	 GtkWidget *windowservices;
	 GtkWidget *windowmeilleur_client;

 windowmeilleur_client = lookup_widget(button ,"windowmeilleur_client");
 gtk_widget_destroy(windowmeilleur_client);

 windowservices = create_windowservices ();
 gtk_widget_show (windowservices);
}


void
on_button_meilleurclient_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
	 GtkWidget *windowmeilleur_client;
	GtkWidget *windowservices;
 windowmeilleur_client = create_windowmeilleur_client ();
 gtk_widget_show (windowmeilleur_client);

windowservices = lookup_widget(button ,"windowservices");
 gtk_widget_destroy(windowservices);
}


void
on_button_acceuilgestion_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{

}



gboolean
on_eventbox5_button_press_event        (GtkWidget       *widget,
                                        GdkEventButton  *event,
                                        gpointer         user_data)
{

GtkWidget *windowNouchene;
GtkWidget *window;
windowNouchene = create_windowgestion();
gtk_widget_show(windowNouchene);
window = lookup_widget(widget, "windowHome");
gtk_widget_destroy(window);
  return FALSE;
}


gboolean
on_eventbox6_button_press_event        (GtkWidget       *widget,
                                        GdkEventButton  *event,
                                        gpointer         user_data)
{

  return FALSE;
}

///////////////////////////////////////////////////////////////////////
/*Gestion Des Capteurs */

void
on_Liste_des_Capteur_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *treeview;
GtkWidget *listecap;
GtkWidget *window;
listecap = create_windowListeCapteurs();
gtk_widget_show(listecap);
treeview = lookup_widget(listecap, "treeview17");
afficher_capteur(treeview);
window = lookup_widget(button,"windowGestionCapteurs");
gtk_widget_destroy(window);
}

void
on_buttonAjouterCapteur_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowAjout;
GtkWidget *windowMenu;
windowMenu = lookup_widget(button,"windowGestionCapteurs");
gtk_widget_destroy(windowMenu);

windowAjout = lookup_widget(button,"windowAjoutCapteur");
windowAjout = create_windowAjoutCapteur();
gtk_widget_show(windowAjout);
}


void
on_buttonModifCapteur_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowModifier;
GtkWidget *windowMenu;
GtkWidget *treeview;
windowMenu = lookup_widget(button, "windowGestionCapteurs");
gtk_widget_destroy(windowMenu);
windowModifier = create_windowModifierCapteur();
gtk_widget_show(windowModifier);
treeview = lookup_widget (windowModifier, "treeview12");
afficher_capteur(treeview);
}


void
on_buttonSupprimerCapteur_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowSupprimer;
GtkWidget *windowMenu;
GtkWidget *treeview;
windowMenu = lookup_widget(button, "windowGestionCapteurs");
gtk_widget_destroy(windowMenu);
windowSupprimer = create_windowSupprimeCapteur();
gtk_widget_show(windowSupprimer);
treeview = lookup_widget (windowSupprimer, "treeview14");
afficher_capteur(treeview);
}


void
on_buttonConsulterCapteurs_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowalarmant;
GtkWidget *windowMenu1;
windowMenu1 = lookup_widget(button,"windowGestionCapteurs");
gtk_widget_destroy(windowMenu1);

windowalarmant = lookup_widget(button,"windowAlarmants");
windowalarmant = create_windowAlarmants();
gtk_widget_show(windowalarmant);
}


void
on_buttonAcceuilCa_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowSupprimer;
GtkWidget *windowMenu1;
GtkWidget *windowAjoutCapteur;
GtkWidget *windowModifier;
GtkWidget *windowListeCapteurs;
GtkWidget *windowCapteurAlarmants;
windowSupprimer = lookup_widget(button, "windowSupprimeCapteur");
gtk_widget_destroy(windowSupprimer);

windowModifier = lookup_widget(button, "windowModifierCapteur");
gtk_widget_destroy(windowModifier);

windowAjoutCapteur = lookup_widget(button, "windowAjoutCapteur");
gtk_widget_destroy(windowAjoutCapteur);


windowListeCapteurs = lookup_widget(button, "windowListeCapteurs");
gtk_widget_destroy(windowListeCapteurs);

windowCapteurAlarmants = lookup_widget(button,"windowAlarmants");
gtk_widget_destroy(windowCapteurAlarmants);

windowMenu1 = create_windowGestionCapteurs();
gtk_widget_show(windowMenu1);

}


void
on_buttonDeconnexionAmine_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowSupprimer;
GtkWidget *windowLogin;
GtkWidget *windowGestionCapteurs;
GtkWidget *windowAjoutCapteur;
GtkWidget *windowModifier;
GtkWidget *windowListeCapteurs;
GtkWidget *windowAlarmants;
windowSupprimer = lookup_widget(button, "windowSupprimeCapture");
gtk_widget_destroy(windowSupprimer);

windowGestionCapteurs = lookup_widget(button, "windowGestionCapteurs");
gtk_widget_destroy(windowGestionCapteurs);

windowModifier = lookup_widget(button, "windowModifierCapteur");
gtk_widget_destroy(windowModifier);

windowAjoutCapteur = lookup_widget(button, "windowAjoutCapteur");
gtk_widget_destroy(windowAjoutCapteur);


windowListeCapteurs = lookup_widget(button, "windowListeCapteurs");
gtk_widget_destroy(windowListeCapteurs);

windowAlarmants = lookup_widget(button, "windowAlarmants");
gtk_widget_destroy(windowAlarmants);


windowLogin = create_windowLogin();
gtk_widget_show(windowLogin);
}
//////////////////////////////////////////////
int choixCa[] = {0,0};
int choixCa1[] = {0,0};
void
on_buttonAjouterCa_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
Capteur c;
Capteur r;
FILE *fp1;

fp1 = fopen("capteurs.bin", "rb");

GtkWidget *input1;
GtkWidget *input2;
GtkWidget *input3;
GtkWidget *Jour;
GtkWidget *Mois;
GtkWidget *Annee;
GtkWidget *windowRemplir;
GtkWidget *windowConfirmation;


input1 = lookup_widget(button, "entry1");
input2 = lookup_widget(button, "entry2");
input3 = lookup_widget(button, "entry3");
Jour = lookup_widget(button, "spinbuttonJours");
Mois = lookup_widget(button, "spinbuttonMois");
Annee = lookup_widget(button, "spinbuttonAnnees");
strcpy(c.id,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(c.valeur,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(c.marque,gtk_entry_get_text(GTK_ENTRY(input3)));

if (choixCa[0]==1)
strcpy(c.type,"Temperature");
else if (choixCa[1]==1)
strcpy(c.type,"Humidite");


c.date_creation.jour= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Jour));
c.date_creation.mois= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Mois));
c.date_creation.annee= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Annee));


ajouter_capteur(c);
windowConfirmation = create_validajout();
gtk_widget_show(windowConfirmation);
}

//////////////////////////////////////////////
void
on_buttonRechercherCa_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *treeview11;
GtkWidget *liste1;
GtkWidget *input;
GtkWidget *input1;
GtkWidget *buttonEnable;
GtkWidget *window;
int ok;
char type[20]; 
Capteur r;
char id[20];
input = lookup_widget(button, "entry4");
input1 = lookup_widget(button, "comboboxentry3");
buttonEnable = lookup_widget(button, "buttonModif"); 
strcpy(id,gtk_entry_get_text(GTK_ENTRY(input)));
strcpy(type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input1)));
window = lookup_widget(button, "windowModifierCapteur");
treeview11 = lookup_widget(window, "treeview11");
chercher_capteur_supp(r,id,type, &ok);
if (ok)
gtk_widget_set_sensitive(buttonEnable, TRUE); 
else
gtk_widget_set_sensitive(buttonEnable, FALSE); 


afficher_capteurModif(treeview11);

}
char cap[50];
//////////////////////////////////////////////
void
on_buttonModifCa_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
Capteur c;
GtkWidget *input1;
GtkWidget *windowModification;
FILE *fp;
fp = fopen("temp1.bin", "rb");
input1 = lookup_widget(button, "entry4");
strcpy(cap,gtk_entry_get_text(GTK_ENTRY(input1)));
windowModification = create_ModifierCapteur();
gtk_widget_show(windowModification);

GtkWidget *output1, *output2, *output3, *output4, *output5, *output6;
if(fp!=NULL)
{
while (fread(&c, sizeof(c), 1, fp))
{
	output1 = lookup_widget(windowModification, "entry6");
	gtk_entry_set_text(GTK_ENTRY(output1), c.id);

	output2 = lookup_widget(windowModification, "entry7");
	gtk_entry_set_text(GTK_ENTRY(output2), c.valeur);

	output3 = lookup_widget(windowModification, "entry8");
	gtk_entry_set_text(GTK_ENTRY(output3), c.marque);

	output4 = lookup_widget(windowModification, "spinbutton6");
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(output4), c.date_creation.jour);


	output5 = lookup_widget(windowModification, "spinbutton7");
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(output5), c.date_creation.mois);


	output6 = lookup_widget(windowModification, "spinbutton8");
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(output6), c.date_creation.annee);

}
}

fclose(fp);
}

//////////////////////////////////////////////
void
on_buttonSupprimerCa_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowConfirmation;
char id[30];
char type[30];
Capteur c;
GtkWidget *input1;
GtkWidget *input2;
input1= lookup_widget(button, "entry5");
input2= lookup_widget(button, "comboboxentry4");
strcpy(id, gtk_entry_get_text(GTK_ENTRY(input1)));
supprimer_capteur(c,id,type);
windowConfirmation = create_validsupp();
gtk_widget_show(windowConfirmation);
}
//////////////////////////////////////////////

void
on_RechSuppCa_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *treeview3;
GtkWidget *liste1;
GtkWidget *input;
GtkWidget *input2;
GtkWidget *buttonEnable;
GtkWidget *window;
Capteur r;
int ok; 
char id[30];
char type[30];
input2 = lookup_widget(button, "entry5");
input= lookup_widget(button, "comboboxentry4");
buttonEnable = lookup_widget(button, "buttonSupprimer");

strcpy(id,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input)));

window = lookup_widget(button, "windowSupprimeCapteur");
treeview3 = lookup_widget(window, "treeview13");
chercher_capteur_supp(r, id,type, &ok);
if (ok)
gtk_widget_set_sensitive(buttonEnable, TRUE); 
else
gtk_widget_set_sensitive(buttonEnable, FALSE); 


afficher_capteurModif(treeview3);
}

//////////////////////////////////////////////
void
on_actualiserCa_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *treeview;
GtkWidget *listecap;
listecap = create_windowListeCapteurs();
treeview = lookup_widget(listecap, "treeview17");
afficher_capteur(treeview);
}

//////////////////////////////////////////////
void
on_okbuttonajout_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
window = lookup_widget(button, "validajout");
gtk_widget_destroy(window);
}
//////////////////////////////////////////////

void
on_buttonConfirmerModifCa_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
Capteur c;
int i;
FILE *fp1;
fp1 = fopen("capteurs.bin", "rb");
if (fp1==NULL)
    {
	i = 0;
    }
    
 
    else
    {
	while (fread(&c,sizeof(c),1,fp1))
	{
		if (strcmp(c.id,cap)==0){
		i = c.id; 
		break;}
	}
    }

GtkWidget *input1;
GtkWidget *input2;
GtkWidget *input3;
GtkWidget *Jour;
GtkWidget *Mois;
GtkWidget *Annee;
GtkWidget *windowErreur;
GtkWidget *windowSuccees;
GtkWidget *ModifierCapteur;


input1 = lookup_widget(button, "entry6");
input2 = lookup_widget(button, "entry7");
input3 = lookup_widget(button, "entry8");
Jour = lookup_widget(button, "spinbutton6");
Mois = lookup_widget(button, "spinbutton7");
Annee = lookup_widget(button, "spinbutton8");


strcpy(c.id,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(c.valeur,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(c.marque,gtk_entry_get_text(GTK_ENTRY(input3)));

if (choixCa1[0]==1)
strcpy(c.type,"Temperature");
else if (choixCa1[1]==1)
strcpy(c.type,"Humidite");


c.date_creation.jour= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Jour));
c.date_creation.mois= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Mois));
c.date_creation.annee= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Annee));

if(((choixCa1[0]==1) && (choixCa1[1]==1)) && ((choixCa1[0]==0) && (choixCa1[1]==0)) && (strcmp(c.id,"")==0) && (strcmp(c.valeur,"")==0) && (strcmp(c.marque,"")==0))
{
windowErreur = create_windowRemplir();
gtk_widget_show(windowErreur);
}
else
{
modifier_capteur(c,cap);
windowSuccees = create_validmodif();
gtk_widget_show(windowSuccees);
ModifierCapteur = lookup_widget(button, "ModifierCapteur");
gtk_widget_destroy(ModifierCapteur);
}
}

//////////////////////////////////////////////
void
on_okbuttonmodif_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
window = lookup_widget(button, "validmodif");
gtk_widget_destroy(window);
}

//////////////////////////////////////////////
void
on_okbuttonsupp_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
window = lookup_widget(button, "validsupp");
gtk_widget_destroy(window);

}

//////////////////////////////////////////////
void
on_okbuttonremplir_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
window = lookup_widget(button, "windowRemplir");
gtk_widget_destroy(window);
}

//////////////////////////////////////////////
void
on_consulterCa_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *liste;
GtkWidget *window1;
Capteur c;
window1=lookup_widget(button,"windowAlarmants");
liste = lookup_widget(window1, "treeview18");
 afficher_capteur_alarmant (liste);
}

//////////////////////////////////////////////
void
on_buttonAcceuilCa__clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowSupprimer;
GtkWidget *windowMenu1;
GtkWidget *windowAjoutCapteur;
GtkWidget *windowModifier;
GtkWidget *windowListeCapteurs;
GtkWidget *windowCapteurAlarmants;
windowSupprimer = lookup_widget(button, "windowSupprimeCapteur");
gtk_widget_destroy(windowSupprimer);

windowModifier = lookup_widget(button, "windowModifierCapteur");
gtk_widget_destroy(windowModifier);

windowAjoutCapteur = lookup_widget(button, "windowAjoutCapteur");
gtk_widget_destroy(windowAjoutCapteur);


windowListeCapteurs = lookup_widget(button, "windowListeCapteurs");
gtk_widget_destroy(windowListeCapteurs);

windowCapteurAlarmants = lookup_widget(button,"windowAlarmants");
gtk_widget_destroy(windowCapteurAlarmants);

windowMenu1 = create_windowGestionCapteurs();
gtk_widget_show(windowMenu1);

}

//////////////////////////////////////////////
void
on_buttonMarque__clicked               (GtkButton       *button,
                                        gpointer         user_data)
{

}


//////////////////////////////////////////////
void
on_buttonDeconnexinAmine__clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowSupprimer;
GtkWidget *windowLogin;
GtkWidget *windowGestionCapteurs;
GtkWidget *windowAjoutCapteur;
GtkWidget *windowModifier;
GtkWidget *windowListeCapteurs;
GtkWidget *windowAlarmants;
windowSupprimer = lookup_widget(button, "windowSupprimeCapture");
gtk_widget_destroy(windowSupprimer);

windowGestionCapteurs = lookup_widget(button, "windowGestionCapteurs");
gtk_widget_destroy(windowGestionCapteurs);

windowModifier = lookup_widget(button, "windowModifierCapteur");
gtk_widget_destroy(windowModifier);

windowAjoutCapteur = lookup_widget(button, "windowAjoutCapteur");
gtk_widget_destroy(windowAjoutCapteur);


windowListeCapteurs = lookup_widget(button, "windowListeCapteurs");
gtk_widget_destroy(windowListeCapteurs);

windowAlarmants = lookup_widget(button, "windowAlarmants");
gtk_widget_destroy(windowAlarmants);


windowLogin = create_windowLogin();
gtk_widget_show(windowLogin);
}

//////////////////////////////////////////////
void
on_buttonRetourCa_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_checkbuttonTemperature_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choixCa[0] = 1;
else
choixCa[0] = 0;
}


void
on_checkbuttonHumudite_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choixCa[1] = 1;
else
choixCa[1] = 0;
}

