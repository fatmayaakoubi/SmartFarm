#ifdef HAVE_CONFIG_H
#  include <config.h>
# include <stdio.h>
#include <string.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fonction.h"


void
on_buttonAjouter_clicked               (GtkWidget        *button,
                                        gpointer         user_data)
{
FILE *fp;
fp = fopen("utilisateurs.txt", "a+");

GtkWidget *windowAuth, *username, *password, *nom, *prenom, *role;
char username1[20],password1[20], nom1[20], prenom1[20], role1[20];

nom = lookup_widget(button, "entryNom");
prenom = lookup_widget(button, "entryPrenom");
username = lookup_widget(button, "entryUsername");
password = lookup_widget(button, "entryPassword");
role = lookup_widget(button, "entryRole");

strcpy(nom1, gtk_entry_get_text(GTK_ENTRY(nom))); 
strcpy(prenom1, gtk_entry_get_text(GTK_ENTRY(prenom))); 
strcpy(username1, gtk_entry_get_text(GTK_ENTRY(username))); 
strcpy(password1, gtk_entry_get_text(GTK_ENTRY(password))); 
strcpy(role1, gtk_entry_get_text(GTK_ENTRY(role)));

if (fp!=NULL)
{
fprintf(fp, "%s %s %s %s %s\n", nom1, prenom1, username1, password1, role1);
fclose(fp);
}
else
{
printf("Echec de l'ouverture du fichier 'utilisateurs.txt'");
}

windowAuth = create_windowAuthentification();
gtk_widget_show(windowAuth);
}


void
on_buttonLogin_clicked                 (GtkWidget       *button,
                                        gpointer         user_data)
{
FILE *fp;
fp = fopen("utilisateurs.txt", "a+");
int test;

GtkWidget *windowAdmin, *username, *password;
char username1[20],password1[20];


username = lookup_widget(button, "entryUsername");
password = lookup_widget(button, "entryPassword");


strcpy(username1, gtk_entry_get_text(GTK_ENTRY(username))); 
strcpy(password1, gtk_entry_get_text(GTK_ENTRY(password))); 


test = verif(username1, password1);

if (test ==1 )
{
windowAdmin = create_windowAdmin();
gtk_widget_show(windowAdmin) ;
}
fclose(fp);


}

