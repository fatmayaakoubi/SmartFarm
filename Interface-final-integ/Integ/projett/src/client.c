# ifdef HAVE_CONFIG_H
# include <config.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "client.h"
#include<gtk/gtk.h>

enum
{
	ECIN,
	ENOM,
	EPRENOM,
	EADRESSE,
	EGSM,
	EGOUVERNEMENT,
	ESEXE,
	EMAIL,
        EDATE_DE_NAISSANCE,
	COLUMNS,
};

enum
 { 
	ENOM1,
	EPRENOM1,
	ECIN1,
	EMAIL1,
	ELIVRAISON1,	
 	EDATE_DE_PAIEMENT1,
	EBREBI1,
	EQUANTITE_BREBIS1,
	EVEAU1,
	EQUANTITE_VEAUX1,
	EYAOURT1,
	EQUANTITE_YAOURT1,
	ERIGOUTA1,
	EQUANTITE_RIGOUTA1,
	ESOMME1,
	COLUMNS1,
  };

enum
 { 
	ENOM2,
	EPRENOM2,
	EDATE_DE_RESERVATION2,
	ENUM2,
	ETYPE_RESERVATION2,
	EMAIL2,
	
 	
	COLUMNS2,
  };
//////////////////////////////////////// ajouter_client ///////////////////////////////////////////////////////////////////////////

void ajouter_client(client c)
{
    FILE *f;
    f = fopen("client.bin", "ab+");
    if (f!=NULL)
    {
        

        fwrite(&c, sizeof(c), 1, f);
        
    }
    else
    {
        printf("\nEchec lors de l'ouverture du fichier 'client.bin'");
    }
fclose(f);
}

///////////////////////////////////////// afficher_client ///////////////////////////////////////////////////////////////////////////

void afficher_client(GtkWidget *liste)
{
        client c;
	char DATE[40];
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	store = NULL;

	FILE *f;


	store = gtk_tree_view_get_model(liste);
if (store == NULL)
{
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Nom",renderer,"text",ENOM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Prenom",renderer,"text",EPRENOM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Sexe",renderer,"text",ESEXE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Date de Naissance",renderer,"text",EDATE_DE_NAISSANCE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


	renderer = gtk_cell_renderer_text_new(); 
	column = gtk_tree_view_column_new_with_attributes(" CIN",renderer,"text",ECIN,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" GSM",renderer,"text",EGSM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Gouvernement",renderer,"text",EGOUVERNEMENT,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Adresse",renderer,"text",EADRESSE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Mail",renderer,"text",EMAIL,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
}
	store = gtk_list_store_new(COLUMNS, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
	f = fopen("client.bin", "rb");

	if(f==NULL)
	{
	return;
	}

	else
	{
		f = fopen("client.bin", "ab+");	
		while(fread(&c, sizeof(c), 1, f))
		{
		   sprintf(DATE, "%d / %d / %d", c.date_de_naissance.jour,c.date_de_naissance.mois,c.date_de_naissance.annee); 

		gtk_list_store_append(store, &iter);
		gtk_list_store_set(store, &iter, ENOM, c.nom, EPRENOM, c.prenom, ESEXE, c.sexe,EDATE_DE_NAISSANCE, DATE, ECIN, c.cin, EGSM, c.gsm, EGOUVERNEMENT,c.gouvernement, EADRESSE, c.adresse, EMAIL, c.mail,-1);
		}
		fclose(f);
		gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref(store);
	}

}
///////////////////////////////////////// rechercher_client //////////////////////////////////////////////////////////////////////////

void rechercher_client(client c, char cin[],int *verif)
{

 
FILE *f ,*g;
*verif=0;
 f =fopen("client.bin","rb");
 g = fopen("tmpr.bin","wb");
 
	if(f==NULL)
	{
	 return;
 	  }
	else
	{ 
	  while(fread(&c, sizeof(c), 1, f))
	    {
	       if (strcmp(cin,c.cin)==0)
	          {
	            fwrite(&c ,sizeof(c), 1 ,g);
			*verif=1;//si le client exit d'ou il prend la val 1 si nn prend val 0;
	          }
	    }
	}
		
	
	
	fclose(f);
	fclose(g);

}

//////////////////////////////////////// supprimer_client ////////////////////////////////////////////////////////////////////////////
void supprimer_client(client c, char cin[])
{

FILE *f, *g;
    f = fopen("client.bin", "rb");
    g = fopen("temp.bin", "ab+");
    if (f==NULL)
    {
        printf("\nEchec lors de l'ouverture du fichier 'client.bin'");
    }
    else
    {
        while (fread(&c, sizeof(c), 1, f))
        {
            if (strcmp(cin, c.cin)!=0)
                fwrite(&c, sizeof(c), 1, g);
        }
    }
    fclose(f);
    fclose(g);
    remove("client.bin");
    rename("temp.bin", "client.bin");
}
//////////////////////////////////////// affichier supp  client ////////////////////////////////////////////////////////////////////////
void afficher_client_supprimer(GtkWidget *liste)

{
  client c;
char DATE[40];
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	store = NULL;

	FILE *f;


	store = gtk_tree_view_get_model(liste);
if (store == NULL)
{
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Nom",renderer,"text",ENOM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Prenom",renderer,"text",EPRENOM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Sexe",renderer,"text",ESEXE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Date de Naissance",renderer,"text",EDATE_DE_NAISSANCE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new(); 
	column = gtk_tree_view_column_new_with_attributes(" CIN",renderer,"text",ECIN,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" GSM",renderer,"text",EGSM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Gouvernement",renderer,"text",EGOUVERNEMENT,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Adresse",renderer,"text",EADRESSE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Mail",renderer,"text",EMAIL,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
}
	store = gtk_list_store_new(COLUMNS, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
	f = fopen("tmpr.bin", "rb");
	if (f==NULL)
	 { 
	   return;
	  }
	   else
	    {
		f = fopen("tmpr.bin", "ab+");	
		while(fread(&c, sizeof(c), 1, f))
	       { 
			sprintf(DATE, "%d / %d / %d", c.date_de_naissance.jour,c.date_de_naissance.mois,c.date_de_naissance.annee);
		
		gtk_list_store_append(store, &iter);
		gtk_list_store_set(store, &iter, ENOM, c.nom, EPRENOM, c.prenom, ESEXE, c.sexe,EDATE_DE_NAISSANCE, DATE, ECIN, c.cin, EGSM, c.gsm, EGOUVERNEMENT,c.gouvernement, EADRESSE, c.adresse, EMAIL, c.mail,-1);
	       }
		fclose(f);
		gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref(store);
	     }
}
/////////////////////////////////////// modifier_client    //////////////////////////////////////////////////////////////////////

void modifier_client(client m, char cin[])
{
FILE *f, *g;
client c;

f = fopen("client.bin", "rb");
g = fopen("tmpm.bin","ab+");
if (f==NULL)
{
	return ;
}
else
{
	while (fread(&c,sizeof(c),1,f))
	{
		if (strcmp(c.cin,cin)!=0)
			fwrite(&c,sizeof(c),1,g);
		else
		{
			fwrite(&m,sizeof(m),1,g);			
		}
	}
}
fclose(f);
fclose(g);
remove("client.bin");
rename("tmpm.bin", "client.bin");

}

////////////////////////////////////////////// afficher_client_modifier////////////////////////////////////////////////////////////////

void afficher_client_modifier(GtkWidget *liste)

{
  client c;
char DATE[40];
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	store = NULL;

	FILE *f;


	store = gtk_tree_view_get_model(liste);
if (store == NULL)
{
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Nom",renderer,"text",ENOM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Prenom",renderer,"text",EPRENOM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Sexe",renderer,"text",ESEXE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Date de Naissance",renderer,"text",EDATE_DE_NAISSANCE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new(); 
	column = gtk_tree_view_column_new_with_attributes(" CIN",renderer,"text",ECIN,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" GSM",renderer,"text",EGSM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Gouvernement",renderer,"text",EGOUVERNEMENT,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Adresse",renderer,"text",EADRESSE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Mail",renderer,"text",EMAIL,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
}
	store = gtk_list_store_new(COLUMNS, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
	f = fopen("tmpr.bin", "rb");
	if (f==NULL)
	 { 
	   return;
	  }
	   else
	    {
		f = fopen("tmpr.bin", "ab+");	
		while(fread(&c, sizeof(c), 1, f))
	       { 
			sprintf(DATE, "%d / %d / %d", c.date_de_naissance.jour,c.date_de_naissance.mois,c.date_de_naissance.annee);
		
		gtk_list_store_append(store, &iter);
		gtk_list_store_set(store, &iter, ENOM, c.nom, EPRENOM, c.prenom, ESEXE, c.sexe,EDATE_DE_NAISSANCE, DATE, ECIN, c.cin, EGSM, c.gsm, EGOUVERNEMENT,c.gouvernement, EADRESSE, c.adresse, EMAIL, c.mail,-1);
	       }
		fclose(f);
		gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref(store);
	     }
}

////////////////////////////////////////////////////////// ajouter_achat /////////////////////////////////////////////////////////////////////////////

void ajouter_achat(achat a)
{
    FILE *f;
    f = fopen("achat.bin", "ab+");
    if (f!=NULL)
    {
        

        fwrite(&a, sizeof(a), 1, f);
        
    }
    else
    {
        return;
    }
fclose(f);
}
//////////////////////////////////////////////////////// afficher_achat /////////////////////////////////////////////////////////////////////////////

void afficher_achat(GtkWidget *liste)
{
        achat a;
	char DATE[40];
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	store = NULL;

	FILE *f;


	store = gtk_tree_view_get_model(liste);
if (store == NULL)
{
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Nom",renderer,"text",ENOM1,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Prenom",renderer,"text",EPRENOM1,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);



	renderer = gtk_cell_renderer_text_new(); 
	column = gtk_tree_view_column_new_with_attributes(" CIN",renderer,"text",ECIN1,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Mail",renderer,"text",EMAIL1,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" livraison",renderer,"text",ELIVRAISON1,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Date de paiement",renderer,"text",EDATE_DE_PAIEMENT1,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" brebi",renderer,"text",EBREBI1,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" quantite des brebis",renderer,"text",EQUANTITE_BREBIS1,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" veau",renderer,"text",EVEAU1,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" quantite des veaux",renderer,"text",EQUANTITE_VEAUX1,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" yaourt",renderer,"text",EYAOURT1,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" quantite du yaourt",renderer,"text",EQUANTITE_YAOURT1,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	 
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" rigouta",renderer,"text",ERIGOUTA1,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" quantite du rigouta",renderer,"text",EQUANTITE_RIGOUTA1,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" SOMME NET ",renderer,"text",ESOMME1,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
}
	store = gtk_list_store_new(COLUMNS1, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_STRING,G_TYPE_INT,G_TYPE_STRING,G_TYPE_INT,G_TYPE_STRING,G_TYPE_INT,G_TYPE_FLOAT);
	f = fopen("achat.bin", "rb");

	if(f==NULL)
	{
	return;
	}

	else
	{
		f = fopen("achat.bin", "ab+");	
		while(fread(&a, sizeof(a), 1, f))
		{
		   sprintf(DATE, "%d / %d / %d", a.date_de_paiement.jour,a.date_de_paiement.mois,a.date_de_paiement.annee); 

		gtk_list_store_append(store, &iter);
		gtk_list_store_set(store, &iter, ENOM1, a.c.nom, EPRENOM1, a.c.prenom, ECIN1, a.c.cin, EMAIL1, a.c.mail, ELIVRAISON1, a.livraison ,EDATE_DE_PAIEMENT1, DATE, EBREBI1, a.brebi, EQUANTITE_BREBIS1, a.quantite_brebis, EVEAU1, a.veau ,EQUANTITE_VEAUX1, a.quantite_veaux, EYAOURT1, a.yaourt, EQUANTITE_YAOURT1, a.quantite_yaourt, ERIGOUTA1, a.rigouta, EQUANTITE_RIGOUTA1, a.quantite_rigouta,ESOMME1, a.somme,-1);
		}
		fclose(f);
		gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref(store);
	}

}
////////////////////////////////////////////////////////////////////////////
void ajouter_reservation(reservation r)
{
    FILE *f;
    f = fopen("reservation.bin", "ab+");
    if (f!=NULL)
    {
        

        fwrite(&r, sizeof(r), 1, f);
        
    }
    else
    {
        return;
    }
fclose(f);
}
//////////////////////////////////////////////////////// afficher_achat /////////////////////////////////////////////////////////////////////////////

void afficher_reservation(GtkWidget *liste)
{
     reservation r;
	char DATE[40];
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	store = NULL;

	FILE *f;


	store = gtk_tree_view_get_model(liste);
if (store == NULL)
{
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Nom",renderer,"text",ENOM2,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Prenom",renderer,"text",EPRENOM2,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Date de reservation",renderer,"text",EDATE_DE_RESERVATION2,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" numbre pers",renderer,"text",ENUM2,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

       renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" type de reservation",renderer,"text",ETYPE_RESERVATION2,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);		

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Mail",renderer,"text",EMAIL2,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


}
	store = gtk_list_store_new(COLUMNS2, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING);
	f = fopen("reservation.bin", "rb");

	if(f==NULL)
	{
	return;
	}

	else
	{
		f = fopen("reservation.bin", "ab+");	
		while(fread(&r, sizeof(r), 1, f))
		{
		  sprintf(DATE, "%d / %d / %d", r.date_de_reservation.jour, r.date_de_reservation.mois,  r.date_de_reservation.annee);  

		gtk_list_store_append(store, &iter);
		gtk_list_store_set(store, &iter, ENOM2, r.c.nom, EPRENOM2, r.c.prenom, EDATE_DE_RESERVATION2, DATE,ENUM2, r.num ,ETYPE_RESERVATION2, r.type_reservation ,EMAIL2, r.c.mail,-1);
		}
		fclose(f);
		gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref(store);
	}

} 
	
