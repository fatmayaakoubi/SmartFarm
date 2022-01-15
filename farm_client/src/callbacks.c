#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "client.h"


//interface "gestion"
void
on_buttonlistclient_clicked            (GtkWidget       *object,
                                        gpointer         user_data)
{ 	GtkWidget *treeview1;
	GtkWidget * windowlistclient;
	GtkWidget * windowgestion;

	windowlistclient = create_windowlistclient ();
  	gtk_widget_show (windowlistclient);	

	treeview1=lookup_widget(windowlistclient,"treeview1");
	afficher_client(treeview1);

	 windowgestion = lookup_widget(object ,"windowgestion");
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
int choix[]={0,0};

void
on_checkbuttonhomme_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{choix[0]=1;}
}


void
on_checkbuttonfemme_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{choix[1]=1;}
}

//interface "ajouter"
void
on_button_ajouter_clicked              (GtkWidget        *object,
                                        gpointer         user_data)
{
client c;
char texte[100]="";
GtkWidget *nom , *prenom, *cin , *gsm, *gouvernement ,*adresse ,*mail ,*jour, *mois,*annee;
GtkWidget *windowajouter;
GtkWidget *dialog2client;
GtkWidget *dialog1client;

nom = lookup_widget(object, "entrynom");
prenom = lookup_widget(object, "entryprenom");
cin = lookup_widget(object, "entrycin");
gsm = lookup_widget(object, "entrygsm");
gouvernement = lookup_widget(object, "entrygouvernement");
adresse = lookup_widget(object, "entryadresse");
mail = lookup_widget(object, "entrymail");



strcpy(c.nom, gtk_entry_get_text(GTK_ENTRY(nom))); 
strcpy(c.prenom, gtk_entry_get_text(GTK_ENTRY(prenom)));  
strcpy(c.cin, gtk_entry_get_text(GTK_ENTRY(cin)));
strcpy(c.gsm, gtk_entry_get_text(GTK_ENTRY(gsm)));
strcpy(c.gouvernement, gtk_entry_get_text(GTK_ENTRY(gouvernement))); 
strcpy(c.adresse, gtk_entry_get_text(GTK_ENTRY(adresse))); 
strcpy(c.mail, gtk_entry_get_text(GTK_ENTRY(mail)));

jour = lookup_widget(object, "spinbuttonjourc");
mois = lookup_widget(object, "spinbuttonmoisc");
annee = lookup_widget(object, "spinbuttonanneec");
 
	if(choix[0]==1)
	strcpy(c.sexe," Homme");
	if(choix[1]==1)
	strcpy(c.sexe," Femme");
	
c.date_de_naissance.jour= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
c.date_de_naissance.mois= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
c.date_de_naissance.annee= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));

if((strcmp(c.nom,"")==0) || (strcmp(c.prenom,"")==0) || (strcmp(c.cin,"")==0) || ((choix[0]==1) && (choix[1]==1)) || ((choix[0]==0) && (choix[1]==0)) || (strcmp(c.gsm,"")==0) || (strcmp(c.gouvernement,"")==0) || (strcmp(c.adresse,"")==0) || (strcmp(c.mail,"")==0))
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
on_button_rechercher_clicked           (GtkWidget      *button,
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
on_button_afficher_clicked             (GtkWidget      *object,
                                        gpointer         user_data)
{

	GtkWidget *windowajouter;
	GtkWidget * windowlistclient;
	GtkWidget *treeview1;
	

	windowajouter=lookup_widget(object,"windowajouter");
	gtk_widget_destroy(windowajouter);

	windowlistclient =lookup_widget(object,"windowlistclient");

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

int choix1[] = {0,0};

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

if (choix1[0]==1)
strcpy(c.sexe,"Homme");
else if (choix1[1]==1)
strcpy(c.sexe,"Femme");

c.date_de_naissance.jour= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
c.date_de_naissance.mois= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
c.date_de_naissance.annee= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
c.cin == i;

if((strcmp(c.nom,"")==0) || (strcmp(c.prenom,"")==0) || (strcmp(c.cin,"")==0) || ((choix1[0]==1) && (choix1[1]==1)) || ((choix1[0]==0) && (choix1[1]==0)) || (strcmp(c.gsm,"")==0) || (strcmp(c.gouvernement,"")==0) || (strcmp(c.adresse,"")==0) || (strcmp(c.mail,"")==0))


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
on_button_actualiser_clicked           (GtkWidget       *object,
                                        gpointer         user_data)
{

	GtkWidget *windowajouter;
	GtkWidget * windowlistclient;
	GtkWidget *treeview1;
	

	windowajouter=lookup_widget(object,"windowajouter");
	gtk_widget_destroy(windowajouter);

	windowlistclient =lookup_widget(object,"windowlistclient");


	treeview1=lookup_widget(windowlistclient,"treeview1");
	afficher_client(treeview1);
	
}


void
on_checkbutton_femmemodif_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{choix1[1]=1;}
}


void
on_checkbutton_hommemodif_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{choix1[0]=1;}
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
void
on_button1_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{ GtkWidget *dialog1client;
 
dialog1client = lookup_widget(button ,"dialog1");
gtk_widget_destroy(dialog1client);

}

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
on_button_ajouter_achat_clicked        (GtkWidget         *object,
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

nom = lookup_widget(object, "entrynom");
prenom = lookup_widget(object, "entryprenom");
cin = lookup_widget(object, "entrycin");
mail = lookup_widget(object, "entrymail");

quantitebrebis = lookup_widget(object, "entryquantitebrebi");
quantiteveaux = lookup_widget(object, "entryquantiteveau");
quantiteyaourt = lookup_widget(object, "entryquantiteyaourt");
quantiterigouta = lookup_widget(object, "entryquantiterigouta");

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

jour = lookup_widget(object, "spinbuttonjourachat");
mois = lookup_widget(object, "spinbuttonmoisachat");
annee = lookup_widget(object, "spinbuttonanneeachat");



	 
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
output = lookup_widget(object, "labelsomme");
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
on_button_affichier_achat_clicked      (GtkWidget        *object,
                                        gpointer         user_data)
{
    GtkWidget * window_liste_achat;
	
	GtkWidget *treeview2;
	



	window_liste_achat =lookup_widget(object," window_liste_achat");

	

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
on_button_ajouter_reservation_clicked  (GtkWidget       *object,
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

nom = lookup_widget(object, "entrynom");
prenom = lookup_widget(object, "entryprenon");
num1 = lookup_widget(object, "entrynumpersonne");
mail = lookup_widget(object, "entrymail");
combobox1 =  lookup_widget(object, "combobox1");


strcpy(r.c.nom, gtk_entry_get_text(GTK_ENTRY(nom))); 
strcpy(r.c.prenom, gtk_entry_get_text(GTK_ENTRY(prenom)));  
strcpy(num, gtk_entry_get_text(GTK_ENTRY(num1)));
strcpy(r.c.mail, gtk_entry_get_text(GTK_ENTRY(mail)));
strcpy(r.type_reservation, gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)));

r.num= atoi(num);

jour = lookup_widget(object, "spinbuttonjourres");
mois = lookup_widget(object, "spinbuttonmoisres");
annee = lookup_widget(object, "spinbuttonanneeres");
 
	
	
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
                                        (GtkWidget       *object,
                                        gpointer         user_data)
{
GtkWidget * windowliste_reservation;
	
		GtkWidget *treeview3;
		
		GtkWidget * window_reservation;

	window_reservation = lookup_widget(object, "window_reservation");
	gtk_widget_destroy(window_reservation);

        windowliste_reservation =lookup_widget(object,"windowliste_reservation");

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
on_buttonlist_achatse_clicked          (GtkWidget       *object,
                                        gpointer         user_data)
{

   


        GtkWidget * window_liste_achat;
	GtkWidget *treeview2;
	GtkWidget *windowservices;

	windowservices = lookup_widget(object, "windowservices");
	gtk_widget_destroy(windowservices);

	window_liste_achat =lookup_widget(object," window_liste_achat");

	window_liste_achat = create_window_liste_achat ();
         gtk_widget_show (window_liste_achat);

	treeview2=lookup_widget(window_liste_achat,"treeview2");
	afficher_achat(treeview2);

}

//interface service
void
on_button_liste_res_clicked            (GtkWidget       *object,
                                        gpointer         user_data)
{
 	GtkWidget * windowliste_reservation;
	GtkWidget *treeview3;
	GtkWidget *windowservices;

	windowservices = lookup_widget(object, "windowservices");
	gtk_widget_destroy(windowservices);

	windowliste_reservation =lookup_widget(object,"windowliste_reservation");

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

