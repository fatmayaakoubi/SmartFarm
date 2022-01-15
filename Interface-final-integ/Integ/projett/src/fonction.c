#include "fonction.h"
#include "callbacks.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <gtk/gtk.h>

enum{
NOM,
PRENOM,
SEXE,
DATE_NAISSANCE,
CIN,
GSM,
ID,
COLUMNS
};

enum{
ID1,
DATE1,
ETAT1,
COLUMNS1
};

enum{
ID2,
TYPE2,
USERNAME2,
COLUMNS2
};


void ajouter_employe(Employe e)
{
    FILE *fp;
    fp = fopen("utilisateurs.bin", "ab+");
    if (fp!=NULL)
    {
        

        fwrite(&e, sizeof(e), 1, fp);
        
    }
    else
    {
        printf("\nEchec lors de l'ouverture du fichier 'utilisateurs.bin'");
    }
fclose(fp);
}

void afficher_employe(GtkWidget *liste)
{
Employe p;
char DATE[30];
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
store = NULL;

FILE *fp;


store = gtk_tree_view_get_model(liste);
if (store == NULL)
{
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Nom",renderer,"text",NOM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Prenom",renderer,"text",PRENOM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Sexe",renderer,"text",SEXE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Date de Naissance",renderer,"text",DATE_NAISSANCE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new(); 
	column = gtk_tree_view_column_new_with_attributes(" CIN",renderer,"text",CIN,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" GSM",renderer,"text",GSM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Identifiant",renderer,"text",ID,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
}
	store = gtk_list_store_new(COLUMNS, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT);
	fp = fopen("utilisateurs.bin", "rb");

	if(fp==NULL)
	{
	return;
	}

	else
	{
		fp = fopen("utilisateurs.bin", "ab+");	
		while(fread(&p, sizeof(p), 1, fp))
		{
		sprintf(DATE, "%d/%d/%d", p.date_naissance.jour,p.date_naissance.mois,p.date_naissance.annee);
		
		gtk_list_store_append(store, &iter);
		gtk_list_store_set(store, &iter, NOM, p.nom, PRENOM, p.prenom, SEXE, p.sexe, DATE_NAISSANCE, DATE, CIN, p.cin, GSM, p.gsm, ID, p.id,-1);
		}
		fclose(fp);
		gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref(store);
	}

}

void supprimer_employe(Employe e, char cin[])
{

FILE *fp1, *fp2;
    fp1 = fopen("utilisateurs.bin", "rb");
    fp2 = fopen("temp.bin", "ab+");
    
    if (fp1==NULL)
    {
        printf("\nEchec lors de l'ouverture du fichier 'utilisateurs.bin'");
    }
    else
    {
        while (fread(&e, sizeof(e), 1, fp1))
        {
            if (strcmp(cin, e.cin)!=0)
                fwrite(&e, sizeof(e), 1, fp2);
        }
    }
    fclose(fp1);
    fclose(fp2);
    remove("utilisateurs.bin");
    rename("temp.bin", "utilisateurs.bin");
}

int id_supprimer_employe(Employe e, char cin[])
{
int id;
FILE *fp1;
    fp1 = fopen("utilisateurs.bin", "rb");

    
    if (fp1==NULL)
    {
        printf("\nEchec lors de l'ouverture du fichier 'utilisateurs.bin'");
    }
    else
    {
        while (fread(&e, sizeof(e), 1, fp1))
        {
            if (strcmp(cin, e.cin)==0)
                id=e.id;	
        }
    }
    fclose(fp1);
    return id;
}

void supprimer_pointage(Pointage e, int id)
{

FILE *fp1, *fp2;
    fp1 = fopen("pointage.bin", "rb");
    fp2 = fopen("tempPointage.bin", "ab+");
    
    if (fp1==NULL)
    {
        printf("\nEchec lors de l'ouverture du fichier 'utilisateurs.bin'");
    }
    else
    {
        while (fread(&e, sizeof(e), 1, fp1))
        {
            if (id != e.employe.id)
                fwrite(&e, sizeof(e), 1, fp2);
        }
    }
    fclose(fp1);
    fclose(fp2);
    remove("pointage.bin");
    rename("tempPointage.bin", "pointage.bin");
}

void chercher_employe(Employe e, char cin[20], int *ok)
{
FILE *fp ,*fp1;
fp = fopen("utilisateurs.bin", "rb");
fp1 = fopen("temp1.bin", "wb");
*ok=0;

if(fp==NULL)
{
return;
}
else
{
while(fread(&e, sizeof(e), 1, fp))
{
	if (strcmp(cin, e.cin)==0)
	{
		fwrite(&e, sizeof(e), 1, fp1);
		*ok=1; // ok prends la valeur 1 si cin existe *********** sinon ok = 0
	}

}
}
fclose(fp);
fclose(fp1);
}

void afficher_employeModif(GtkWidget *liste)
{
Employe p;
char DATE[30];
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

store = NULL;

FILE *fp;



store = gtk_tree_view_get_model(liste);

if (store == NULL)
{
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Nom",renderer,"text",NOM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Prenom",renderer,"text",PRENOM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Sexe",renderer,"text",SEXE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Date de Naissance",renderer,"text",DATE_NAISSANCE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new(); 
	column = gtk_tree_view_column_new_with_attributes(" CIN",renderer,"text",CIN,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" GSM",renderer,"text",GSM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Identifiant",renderer,"text",ID,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
}
	store = gtk_list_store_new(COLUMNS, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT);
	fp = fopen("temp1.bin", "rb");

	if(fp==NULL)
	{
	return;
	}

	else
	{
		fp = fopen("temp1.bin", "ab+");	
		while(fread(&p, sizeof(p), 1, fp))
		{
		sprintf(DATE, "%d/%d/%d", p.date_naissance.jour,p.date_naissance.mois,p.date_naissance.annee);
		
		gtk_list_store_append(store, &iter);
		gtk_list_store_set(store, &iter, NOM, p.nom, PRENOM, p.prenom, SEXE, p.sexe, DATE_NAISSANCE, DATE, CIN, p.cin, GSM, p.gsm, ID, p.id,-1);
		}
		fclose(fp);
		gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref(store);
	}

}

void modifier_employe(Employe h, char cin[])
{
FILE *fp1, *fp2;
Employe e;
fp1 = fopen("utilisateurs.bin", "rb");
fp2 = fopen("tmpp.bin","ab+");
if (fp1==NULL)
{
	return ;
}
else
{
	while (fread(&e,sizeof(e),1,fp1))
	{
		if (strcmp(e.cin,cin)!=0)
			fwrite(&e,sizeof(e),1,fp2);
		else
		{
			fwrite(&h,sizeof(h),1,fp2);			
		}
	}
}
fclose(fp1);
fclose(fp2);
remove("utilisateurs.bin");
rename("tmpp.bin", "utilisateurs.bin");

}

void afficher_employeSupp(GtkWidget *liste)
{

Employe p;
char DATE[30];
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

store = NULL;

FILE *fp;



store = gtk_tree_view_get_model(liste);

if (store == NULL)
{
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Nom",renderer,"text",NOM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Prenom",renderer,"text",PRENOM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Sexe",renderer,"text",SEXE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Date de Naissance",renderer,"text",DATE_NAISSANCE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new(); 
	column = gtk_tree_view_column_new_with_attributes(" CIN",renderer,"text",CIN,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" GSM",renderer,"text",GSM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Identifiant",renderer,"text",ID,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
}
	store = gtk_list_store_new(COLUMNS, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT);
	fp = fopen("temp1.bin", "rb");

	if(fp==NULL)
	{
	return;
	}

	else
	{
		fp = fopen("temp1.bin", "ab+");	
		while(fread(&p, sizeof(p), 1, fp))
		{
		sprintf(DATE, "%d/%d/%d", p.date_naissance.jour,p.date_naissance.mois,p.date_naissance.annee);
		
		gtk_list_store_append(store, &iter);
		gtk_list_store_set(store, &iter, NOM, p.nom, PRENOM, p.prenom, SEXE, p.sexe, DATE_NAISSANCE, DATE, CIN, p.cin, GSM, p.gsm, ID, p.id,-1);
		}
		fclose(fp);
		gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref(store);
	}

}

void pointage(Pointage p)
{
FILE *fp;
fp = fopen("pointage.bin","ab+");
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



int tauxABS()
{

FILE *fp;
Pointage p;
int x1=0;
int x2=0;
int res=0;


fp = fopen("calc.bin", "rb");
if (fp==NULL)
{
return;
}
else
{
while (fread(&p, sizeof(p),1,fp))
{
	
	
	if(strcmp(p.etat ,"Absent")==0)
	{
		x1 += 1;
		
	}
	x2+= 1;


}
res = (x1*100)/(x2); 
}

fclose(fp);
return res;

}

void afficher_taux(GtkWidget *liste, char id[30])
{
Pointage p;
char DATE[30];
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
	column = gtk_tree_view_column_new_with_attributes(" Identifiant",renderer,"text",ID1,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Date de Pointage",renderer,"text",DATE1,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Etat",renderer,"text",ETAT1,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


	
}
	store = gtk_list_store_new(COLUMNS1, G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING);
	fp = fopen("pointage.bin", "rb");

	if(fp==NULL)
	{
	return;
	}

	else
	{
		fp = fopen("pointage.bin", "ab+");	
		while(fread(&p, sizeof(p), 1, fp))
		{
		sprintf(ident, "%d", p.employe.id);
		if(strcmp(id, ident)==0)
		{
		sprintf(DATE, "%d/%d/%d", p.date.jour,p.date.mois,p.date.annee);
		
		gtk_list_store_append(store, &iter);
		gtk_list_store_set(store, &iter, ID1, p.employe.id, DATE1, DATE, ETAT1, p.etat, -1);
		}
		}
		fclose(fp);
		gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref(store);
	}

}

void chercher_employe_taux(Employe e, char id[20], int *ok)
{
FILE *fp ,*fp1;
fp = fopen("utilisateurs.bin", "rb");
fp1 = fopen("tempTaux.bin", "wb");
*ok=0;
char ident[30];

if(fp==NULL)
{
return;
}
else
{
while(fread(&e, sizeof(e), 1, fp))
{
	sprintf(ident, "%d", e.id);
	if (strcmp(id, ident)==0)
	{
		fwrite(&e, sizeof(e), 1, fp1);
		*ok=1; // ok prends la valeur 1 si cin existe *********** sinon ok = 0
	}

}

}
fclose(fp);
fclose(fp1);
}

void check(Pointage p, char ident[], int *ok1)
{
FILE *fp;
*ok1 = 0;
char id[30];
fp = fopen("pointage.bin", "rb");
if (fp==NULL)
{
return;
}
else
{
while (fread(&p, sizeof(p),1,fp))
{
sprintf(id, "%d", p.employe.id);
if(strcmp(ident, id)==0)
{
*ok1=1;
}

}



}
fclose(fp);
}


int premier(int id)
{
FILE *fp;
int absence=0;
Pointage p;
fp = fopen("pointage.bin", "rb");
if (fp==NULL)
{
	return;
}
else
{
	while (fread(&p, sizeof(p), 1, fp))
	{
		if((p.employe.id==id) && (strcmp(p.etat, "Absent")==0))
		{
			absence ++;
		}
		
	}
}
fclose(fp);
return (absence);

}

void deuxieme(int id, int *total)
{
FILE *fp;
*total = 0;

Pointage p;
fp = fopen("pointage.bin", "rb");
if (fp==NULL)
{
	return;
}
else
{
	while (fread(&p, sizeof(p), 1, fp))
	{
		if(p.employe.id==id)
		{
			*total += 1;
		}
		
	}
}
fclose(fp);


}

void afficher_meilleur_employe(GtkWidget *liste, char ident[30])
{
Employe p;
char DATE[30];
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
store = NULL;

FILE *fp;


store = gtk_tree_view_get_model(liste);
if (store == NULL)
{
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Nom",renderer,"text",NOM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Prenom",renderer,"text",PRENOM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Sexe",renderer,"text",SEXE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Date de Naissance",renderer,"text",DATE_NAISSANCE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new(); 
	column = gtk_tree_view_column_new_with_attributes(" CIN",renderer,"text",CIN,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" GSM",renderer,"text",GSM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Identifiant",renderer,"text",ID,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
}
	store = gtk_list_store_new(COLUMNS, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT);
	fp = fopen("utilisateurs.bin", "rb");

	if(fp==NULL)
	{
	return;
	}

	else
	{
		fp = fopen("utilisateurs.bin", "ab+");	
		while(fread(&p, sizeof(p), 1, fp))
		{
		if(p.id==ident)
		{
		sprintf(DATE, "%d/%d/%d", p.date_naissance.jour,p.date_naissance.mois,p.date_naissance.annee);
		
		gtk_list_store_append(store, &iter);
		gtk_list_store_set(store, &iter, NOM, p.nom, PRENOM, p.prenom, SEXE, p.sexe, DATE_NAISSANCE, DATE, CIN, p.cin, GSM, p.gsm, ID, p.id,-1);
		}
		}
		fclose(fp);
		gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref(store);
	}

}

void creer_compt(compt c)
{
FILE *fp;
fp = fopen("accounts.bin", "ab+");
if(fp==NULL)
{
	return;
}
else
{
	fwrite(&c, sizeof(c), 1, fp);
}
fclose(fp);
}

int verif_login(char username[30], char pass[30], char *type)
{
FILE *fp1;
fp1 = fopen("accounts.bin", "rb");
compt c;
int test=0;
if(fp1==NULL)
{
	fp1 = fopen("accounts.bin", "ab+");
	strcpy(c.type, "Modérateur");
	strcpy(c.username, "admin");
	strcpy(c.password, "admin");
	c.id = 999999;
	fwrite(&c, sizeof(c), 1, fp1);
	fclose(fp1);
}
else
{
	while (fread(&c, sizeof(c), 1, fp1))
	{
		if((strcmp(c.username, username)==0) && (strcmp(c.password, pass)==0))
		{
			test=1;
			strcpy(type, c.type);
		}

	}
}
return test;

}

void chercher_compt(compt c, int id, int *ok)
{
FILE *fp ,*fp1;
fp = fopen("accounts.bin", "rb");
fp1 = fopen("comptrecherche.bin", "wb");
*ok=0;

if(fp==NULL)
{
return;
}
else
{
while(fread(&c, sizeof(c), 1, fp))
{
	if (c.id == id)
	{
		fwrite(&c, sizeof(c), 1, fp1);
		*ok=1; // ok prends la valeur 1 si cin existe *********** sinon ok = 0
	}

}
}
fclose(fp);
fclose(fp1);
}


void afficher_comptModif(GtkWidget *liste)
{
compt c;
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

store = NULL;

FILE *fp;



store = gtk_tree_view_get_model(liste);

if (store == NULL)
{
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Identifiant",renderer,"text",NOM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Type",renderer,"text",PRENOM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Username",renderer,"text",SEXE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


	
}
	store = gtk_list_store_new(COLUMNS2, G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING);
	fp = fopen("comptrecherche.bin", "rb");

	if(fp==NULL)
	{
	return;
	}

	else
	{
		fp = fopen("comptrecherche.bin", "ab+");	
		while(fread(&c, sizeof(c), 1, fp))
		{
		
		gtk_list_store_append(store, &iter);
		gtk_list_store_set(store, &iter, ID2, c.id, TYPE2, c.type, USERNAME2, c.username, -1);
		}
		fclose(fp);
		gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref(store);
	}

}


void modifier_compt(compt c1, int id)
{
FILE *fp1, *fp2;
compt c2;
fp1 = fopen("accounts.bin", "rb");
fp2 = fopen("tmpcompt.bin","ab+");
if (fp1==NULL)
{
	return ;
}
else
{
	while (fread(&c2,sizeof(c2),1,fp1))
	{
		if (c2.id!=id)
			fwrite(&c2,sizeof(c2),1,fp2);
		else
		{
			fwrite(&c1,sizeof(c1),1,fp2);			
		}
	}
}
fclose(fp1);
fclose(fp2);
remove("accounts.bin");
rename("tmpcompt.bin", "accounts.bin");

}

void supprimer_compt(compt c, int id)
{

FILE *fp1, *fp2;
    fp1 = fopen("accounts.bin", "rb");
    fp2 = fopen("comptTempo.bin", "ab+");
    
    if (fp1==NULL)
    {
        return;
    }
    else
    {
        while (fread(&c, sizeof(c), 1, fp1))
        {
            if (id!=c.id)
                fwrite(&c, sizeof(c), 1, fp2);
        }
    }
    fclose(fp1);
    fclose(fp2);
    remove("accounts.bin");
    rename("comptTempo.bin", "accounts.bin");
}
void afficher_comptes(GtkWidget *liste)
{
compt c;
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
store = NULL;

FILE *fp;


store = gtk_tree_view_get_model(liste);
if (store == NULL)
{
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Identifiant",renderer,"text",NOM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Type",renderer,"text",PRENOM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Utilisateur",renderer,"text",SEXE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

}
	store = gtk_list_store_new(COLUMNS2, G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING);
	fp = fopen("accounts.bin", "rb");

	if(fp==NULL)
	{
	return;
	}

	else
	{
		fp = fopen("accounts.bin", "ab+");	
		while(fread(&c, sizeof(c), 1, fp))
		{
		
		gtk_list_store_append(store, &iter);
		gtk_list_store_set(store, &iter, ID2, c.id, TYPE2, c.type, USERNAME2, c.username, -1);
		}
		fclose(fp);
		gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref(store);
	}

}

























