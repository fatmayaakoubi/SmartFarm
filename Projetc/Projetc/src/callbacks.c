#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fonction.h"


void
on_buttonAcceuil_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowSupprimer;
GtkWidget *windowMenu;
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

windowCapteurAlarmants = lookup_widget(button,"window1");
gtk_widget_destroy(windowCapteurAlarmants);

windowMenu = create_windowGestionCapteurs();
gtk_widget_show(windowMenu);

}


void
on_buttonDeconnexin_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_buttonAjoutCapteur_clicked          (GtkButton       *button,
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
on_buttonListeCapteurs_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *treeview;
GtkWidget *listecap;
GtkWidget *window;
listecap = create_windowListeCapteurs();
gtk_widget_show(listecap);
treeview = lookup_widget(listecap, "treeview");
afficher_capteur(treeview);
window = lookup_widget(button,"windowGestionCapteurs");
gtk_widget_destroy(window);
}


void
on_buttonSupprimeCapteur_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowSupprimer;
GtkWidget *windowMenu;
GtkWidget *treeview;
windowMenu = lookup_widget(button, "windowGestionCapteurs");
gtk_widget_destroy(windowMenu);
windowSupprimer = create_windowSupprimeCapteur();
gtk_widget_show(windowSupprimer);
treeview = lookup_widget (windowSupprimer, "treeview4");
afficher_capteur(treeview);
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
treeview = lookup_widget (windowModifier, "treeview2");
afficher_capteur(treeview);
}

int choix[] = {0,0}; 
int choix1[] = {0,0};



void
on_buttonAjouter_clicked               (GtkButton       *button,
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


input1 = lookup_widget(button, "entryId");
input2 = lookup_widget(button, "entry2");
input3 = lookup_widget(button, "entryMarque");
Jour = lookup_widget(button, "spinbuttonJours");
Mois = lookup_widget(button, "spinbuttonMois");
Annee = lookup_widget(button, "spinbuttonAnnees");
strcpy(c.id,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(c.valeur,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(c.marque,gtk_entry_get_text(GTK_ENTRY(input3)));

if (choix1[0]==1)
strcpy(c.type,"Temperature");
else if (choix1[1]==1)
strcpy(c.type,"Humidite");


c.date_naissance.jour= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Jour));
c.date_naissance.mois= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Mois));
c.date_naissance.annee= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Annee));


ajouter_capteur(c);
windowConfirmation = create_dialog1();
gtk_widget_show(windowConfirmation);



}


void
on_buttonDeconnexion_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_checkbuttonTemperature_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choix1[0] = 1;
else
choix1[0] = 0;

}


void
on_checkbuttonHumudite_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choix1[1] = 1;
else
choix1[1] = 0;

}





char tmps[30];
void
on_buttonModif_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
Capteur c;
GtkWidget *input1;
GtkWidget *windowModification;
FILE *fp;
fp = fopen("temp1.bin", "rb");
input1 = lookup_widget(button, "entryID");
strcpy(tmps,gtk_entry_get_text(GTK_ENTRY(input1)));
windowModification = create_ModifierCapteur();
gtk_widget_show(windowModification);

GtkWidget *output1, *output2, *output3, *output4, *output5, *output6;
if(fp!=NULL)
{
while (fread(&c, sizeof(c), 1, fp))
{
	output1 = lookup_widget(windowModification, "entryMOdifierId");
	gtk_entry_set_text(GTK_ENTRY(output1), c.id);

	output2 = lookup_widget(windowModification, "entryModifierValeur");
	gtk_entry_set_text(GTK_ENTRY(output2), c.valeur);

	output3 = lookup_widget(windowModification, "entryModifierMarque");
	gtk_entry_set_text(GTK_ENTRY(output3), c.marque);

	output4 = lookup_widget(windowModification, "spinbuttonJour");
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(output4), c.date_naissance.jour);


	output5 = lookup_widget(windowModification, "spinbuttonMois");
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(output5), c.date_naissance.mois);


	output6 = lookup_widget(windowModification, "spinbuttonMAnnee");
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(output6), c.date_naissance.annee);

}
}
////////////////////////////////////////////////////////
fclose(fp);
}





void
on_buttonConfirmerModif_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
Capteur c;
FILE *fp1;
fp1 = fopen("capteurs.bin", "rb");


GtkWidget *input1;
GtkWidget *input2;
GtkWidget *input3;
GtkWidget *Jour;
GtkWidget *Mois;
GtkWidget *Annee;
GtkWidget *windowErreur;
GtkWidget *windowSuccees;
GtkWidget *ModifierCapteur;


input1 = lookup_widget(button, "entryMOdifierId");
input2 = lookup_widget(button, "entryModifierValeur");
input3 = lookup_widget(button, "entryModifierMarque");
Jour = lookup_widget(button, "spinbuttonJour");
Mois = lookup_widget(button, "spinbuttonMois");
Annee = lookup_widget(button, "spinbuttonAnnee");


strcpy(c.id,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(c.valeur,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(c.marque,gtk_entry_get_text(GTK_ENTRY(input3)));

if (choix1[0]==1)
strcpy(c.type,"Temperature");
else if (choix1[1]==1)
strcpy(c.type,"Humidite");


c.date_naissance.jour= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Jour));
c.date_naissance.mois= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Mois));
c.date_naissance.annee= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Annee));

if(((choix1[0]==1) && (choix1[1]==1)) && ((choix1[0]==0) && (choix1[1]==0)) && (strcmp(c.id,"")==0) && (strcmp(c.valeur,"")==0) && (strcmp(c.marque,"")==0))
{
windowErreur = create_windowRemplir();
gtk_widget_show(windowErreur);
}
else
{
modifier_capteur(c,tmps);
windowSuccees = create_dialog2();
gtk_widget_show(windowSuccees);
ModifierCapteur = lookup_widget(button, "ModifierCapteur");
gtk_widget_destroy(ModifierCapteur);
}
}



void
on_buttonSupprimer_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowConfirmation;
char id[30];
char type[30];
Capteur c;
GtkWidget *input1;
GtkWidget *input2;
input1= lookup_widget(button, "entryID");
input2= lookup_widget(button, "comboboxentry1");
strcpy(id, gtk_entry_get_text(GTK_ENTRY(input1)));
supprimer_capteur(c,id,type);
windowConfirmation = create_dialog3();
gtk_widget_show(windowConfirmation);
}




void
on_actualiser_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *treeview;
GtkWidget *listecap;
listecap = create_windowListeCapteurs();
treeview = lookup_widget(listecap, "treeview");
afficher_capteur(treeview);
}


void
on_okbutton1_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
window = lookup_widget(button, "dialog1");
gtk_widget_destroy(window);
}


void
on_okbutton2_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
window = lookup_widget(button, "dialog2");
gtk_widget_destroy(window);

}


void
on_okbutton3_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
window = lookup_widget(button, "dialog3");
gtk_widget_destroy(window);

}


void
on_okbutton4_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
window = lookup_widget(button, "windowRemplir");
gtk_widget_destroy(window);

}








void
on_actualiser1_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *treeview;
GtkWidget *listecap;
listecap = create_windowSupprimeCapteur();
treeview = lookup_widget(listecap, "treeview");
afficher_capteur(treeview);
}

void
on_buttonRechercher_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *treeview1;
GtkWidget *liste1;
GtkWidget *input;
GtkWidget *input1;
GtkWidget *buttonEnable;
GtkWidget *window;
int ok;
char type[20]; //variable de la fonction chercher_employe (1 si existe 0 si existe pas)
Capteur r;
char id[20];
input = lookup_widget(button, "entryID");
input1 = lookup_widget(button, "comboboxentry2");
buttonEnable = lookup_widget(button, "buttonModif"); //Pointeur sur bouton Modifier
strcpy(id,gtk_entry_get_text(GTK_ENTRY(input)));
strcpy(type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input1)));
window = lookup_widget(button, "windowModifierCapteur");
treeview1 = lookup_widget(window, "treeview1");
chercher_capteur_supp(r,id,type, &ok);
if (ok)
gtk_widget_set_sensitive(buttonEnable, TRUE); //Set Sensitivity to TRUE
else
gtk_widget_set_sensitive(buttonEnable, FALSE); //Set Sensitivity to FALSE


afficher_capteurModif(treeview1);

}
void
on_RechSupp_clicked                    (GtkButton       *button,
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
input2 = lookup_widget(button, "entryID");
input= lookup_widget(button, "comboboxentry1");
buttonEnable = lookup_widget(button, "buttonSupprimer");

strcpy(id,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input)));

window = lookup_widget(button, "windowSupprimeCapteur");
treeview3 = lookup_widget(window, "treeview3");
chercher_capteur_supp(r, id,type, &ok);
if (ok)
gtk_widget_set_sensitive(buttonEnable, TRUE); 
else
gtk_widget_set_sensitive(buttonEnable, FALSE); 


afficher_capteurModif(treeview3);

}


void
on_consulter1_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *liste;
GtkWidget *window1;
Capteur c;
window1=lookup_widget(button,"window1");
liste = lookup_widget(window1, "treeview5");
 afficher_capteur_alarmant (liste);
}





void
on_button22_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowalarmant;
GtkWidget *windowMenu;
windowMenu = lookup_widget(button,"windowGestionCapteurs");
gtk_widget_destroy(windowMenu);

windowalarmant = lookup_widget(button,"window1");
windowalarmant = create_window1();
gtk_widget_show(windowalarmant);
}


gboolean
on_treeview_start_interactive_search   (GtkTreeView     *treeview,
                                        gpointer         user_data)
{

  return FALSE;
}


void
on_buttonMarque_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{

}

