#include<stdio.h>
#include<string.h>
#include "animal.h"
#include <gtk/gtk.h>
enum
{
TYPE,
SEXE,
IDENTIFIANT,
POIDS,
TAILLE,
DATEA,
COLUMNS
};
enum{
IDENTIFIANT1,
AGE1,
NOMBRE1,
LAIT1,
LAINE1,

COLUMNS1
};
//ajouter un troupeau//
void ajouter_animal(ANIMAL a)
{
FILE *fp;
fp=fopen("animaux.bin","ab+");
if (fp!=NULL)
{

fwrite(&a, sizeof(a), 1, fp);}
else
{
printf("\nechec de l'ouverture du fichier 'animaux.bin'"); 
}
fclose(fp);
}


//liste//
void liste_animaux(GtkWidget *liste)
{
ANIMAL p;
GtkCellRenderer *renderer;
GtkTreeViewColumn *Column;
GtkTreeIter iter;


GtkListStore *store;
char type[20];
char sexe[20];
char identifiant[20];
int poids;
int taille;
char date1[30];
store=NULL;
FILE *fp;
store=gtk_tree_view_get_model(liste);
if (store==NULL);
{
renderer = gtk_cell_renderer_text_new ();
Column = gtk_tree_view_column_new_with_attributes(" Type de l'animal", renderer, "text",TYPE, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), Column);

renderer = gtk_cell_renderer_text_new ();
Column = gtk_tree_view_column_new_with_attributes(" Sexe", renderer, "text",SEXE, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), Column);

renderer = gtk_cell_renderer_text_new ();
Column = gtk_tree_view_column_new_with_attributes(" Identifiant", renderer, "text",IDENTIFIANT, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), Column);

renderer = gtk_cell_renderer_text_new ();
Column = gtk_tree_view_column_new_with_attributes(" Poids", renderer, "text",POIDS, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), Column);

renderer = gtk_cell_renderer_text_new ();
Column = gtk_tree_view_column_new_with_attributes("Taille", renderer, "text",TAILLE, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), Column);

renderer = gtk_cell_renderer_text_new ();
Column = gtk_tree_view_column_new_with_attributes(" Date de naissance", renderer, "text",DATEA, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), Column);
}
store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT, G_TYPE_INT, G_TYPE_STRING);
fp=fopen("animaux.bin","rb");
if (fp==NULL)
{
return;
}
else
if(fp==NULL)
	{

		return;
	}		
	else 

	{ fp = fopen("animaux.bin", "ab+");
while (fread(&p, sizeof(p) ,1, fp))
{
sprintf(date1,"%d/%d/%d", p.date.jour,p.date.mois,p.date.annee);


	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter, TYPE, p.type, SEXE,p.sexe, IDENTIFIANT, p.identifiant,POIDS,p.poids,TAILLE,p.taille,DATEA,date1, -1); 
		}
		fclose(fp);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste),  GTK_TREE_MODEL (store));
    g_object_unref (store);
	}
}
//supprimer//
void supprimer_animal(ANIMAL a,char identifiant[])
{

FILE *fp1, *fp2;
fp1 = fopen("animaux.bin", "rb");
    fp2 = fopen("tmp.bin", "ab+");
if (fp1==NULL)
    {
        printf("\nEchec lors de l'ouverture du fichier 'animaux.bin'");
    }
    else
    {
        while (fread(&a, sizeof(a), 1, fp1))
        {
            if (strcmp(identifiant, a.identifiant)!=0)
                fwrite(&a, sizeof(a), 1, fp2);
        }
    }
    fclose(fp1);
    fclose(fp2);
    remove("animaux.bin");
    rename("tmp.bin", "animaux.bin");
}
//rechercher//
void rechercher_animal(ANIMAL a,char identifiant[20],int *ok)
{
FILE *fp,*fp1;


fp=fopen("animaux.bin","rb");
fp1=fopen("tmp1.bin","wb");
if (fp==NULL)
{
return;
}

else 
{
while(fread(&a,sizeof(a),1,fp))
{
if(strcmp(identifiant,a.identifiant)==0)
{
fwrite(&a,sizeof(a),1,fp1);
break;
*ok=1; 
}
}
}
fclose(fp);
fclose(fp1);
}



void afficher_troupeauModif(GtkWidget *liste)
{
ANIMAL p;
GtkCellRenderer *renderer;
GtkTreeViewColumn *Column;
GtkTreeIter iter;
GtkListStore *store;

//char type[20];
//char sexe[20];
//char identifiant[20];
//int poids;
//int taille;
char date1[30];
store=NULL;
FILE *fp;
store=gtk_tree_view_get_model(liste);
if (store==NULL);
{
renderer = gtk_cell_renderer_text_new ();
Column = gtk_tree_view_column_new_with_attributes(" Type de l'animal", renderer, "text",TYPE, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), Column);

renderer = gtk_cell_renderer_text_new ();
Column = gtk_tree_view_column_new_with_attributes(" Sexe", renderer, "text",SEXE, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), Column);

renderer = gtk_cell_renderer_text_new ();
Column = gtk_tree_view_column_new_with_attributes(" Identifiant", renderer, "text",IDENTIFIANT, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), Column);

renderer = gtk_cell_renderer_text_new ();
Column = gtk_tree_view_column_new_with_attributes(" Poids", renderer, "text",POIDS, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), Column);

renderer = gtk_cell_renderer_text_new ();
Column = gtk_tree_view_column_new_with_attributes(" Taille", renderer, "text",TAILLE, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), Column);

renderer = gtk_cell_renderer_text_new ();
Column = gtk_tree_view_column_new_with_attributes(" Date de naissance", renderer, "text",DATEA, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), Column);
}
store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT, G_TYPE_INT, G_TYPE_STRING);
fp=fopen("tmp1.bin","rb");
if (fp==NULL)
{
return;
}
else
if(fp==NULL)
	{

		return;
	}		
	else 

	{ fp = fopen("tmp1.bin", "ab+");
while (fread(&p, sizeof(p) ,1, fp))
{
sprintf(date1,"%d/%d/%d", p.date.jour,p.date.mois,p.date.annee);


	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter, TYPE, p.type, SEXE,p.sexe, IDENTIFIANT, p.identifiant,POIDS,p.poids,TAILLE,p.taille,DATEA,date1, -1); 
break;
		}
		fclose(fp);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste),  GTK_TREE_MODEL (store));
    g_object_unref (store);
	}
}

//modifier//
void modifier_animal(ANIMAL t,char identifiant[])
{
ANIMAL a;
FILE *fp1,*fp2;
fp1=fopen("animaux.bin","rb");
fp2 = fopen("tmpp.bin","ab+");

if (fp1==NULL)
{
	return ;
}
else
{
	while (fread(&a,sizeof(a),1,fp1))
	{
		if (strcmp(identifiant,a.identifiant)!=0)
			fwrite(&a,sizeof(a),1,fp2);
		else
		{
			fwrite(&t,sizeof(t),1,fp2);			
		}
	}
}
fclose(fp1);
fclose(fp2);
remove("animaux.bin");
rename("tmpp.bin","animaux.bin");


}



int nombre_veau()
{
FILE *fp;
int veau=0;
ANIMAL a;
fp = fopen("animaux.bin", "rb");
if (fp==NULL)
{
	return;
}
else{
	while (fread(&a,sizeof(a),1,fp))
	{
		if (strcmp(a.type,"Veau")==0)
		{
			veau++;
		}
	}
}
fclose(fp);
return (veau);
}


int nombre_brebi()
{
FILE *fp;
int brebi=0;
ANIMAL a;
fp = fopen("animaux.bin", "rb");
if (fp==NULL)
{
	return;
}
else{
	while (fread(&a,sizeof(a),1,fp))
	{
		if (strcmp(a.type,"Brebi")==0)
		{
			brebi++;
		}
	}
}
fclose(fp);
return(brebi);
}

void production (Production p)
{
FILE *fp;
fp = fopen("production.bin","ab+");
if(fp==NULL)
{
return;
}
else
{
fwrite(&p, sizeof(p), 1,fp);
}
fclose(fp);
}

void afficher_production(GtkWidget *liste, char identif [30])
{
Production p;

char age[30];
char nombre[30];
int lait ;
int laine;

GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

store = NULL;

char ident[30];
FILE *fp;



store = gtk_tree_view_get_model(liste);

if (store == NULL)
{

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" identifiant",renderer,"text",IDENTIFIANT1,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" age de la mise en bas",renderer,"text",AGE1,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" nombre de naissance",renderer,"text",NOMBRE1,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Production de lait(par Litres)",renderer,"text",LAIT1,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Production de laine(en Kg)",renderer,"text",LAINE1,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
}
	store = gtk_list_store_new(COLUMNS1,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING, G_TYPE_INT, G_TYPE_INT);
	fp = fopen("production.bin", "rb");

	if(fp==NULL)
	{
	return;
	}

	else
	{
		fp = fopen("production.bin", "ab+");	
		while(fread(&p, sizeof(p), 1, fp))
		{
		if(strcmp(p.animal.identifiant,identif)==0)
		{
		
		
		gtk_list_store_append(store, &iter);
		
		gtk_list_store_set (store, &iter,IDENTIFIANT1,p.animal.identifiant,AGE1,p.age,NOMBRE1,p.nombre, LAIT1,p.lait,LAINE1,p.laine ,-1); 
		
		
		}
		}
		fclose(fp);
		gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref(store);
	}

}

















