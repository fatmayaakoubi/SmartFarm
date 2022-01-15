#include "equipement.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
enum
{
TYPE,
DESIGNATION,
REF,
MARQUE,
PRIXACHAT,
STOCK,
//ETAT,
//SITUATION,
COLUMNS
};
enum
{
TYPE1,
DESIGNATION1,
REF1,
MARQUE1,
PRIXACHAT1,
STOCK1,
ETAT1,
SITUATION1,
COLUMNS1
};
void ajouterequipement(equipement P)
{

FILE *f;

f=fopen("equipement.bin","a+b");


if(f!=NULL)
{
fwrite(&P,sizeof(P),1,f);
}
fclose(f);


}
void liste(GtkWidget *lista)
{

equipement P;
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

store=NULL;
FILE *f;
store=gtk_tree_view_get_model(lista);
if(store==NULL)
{
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Type",renderer,"text",TYPE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (lista),column);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Designation",renderer,"text",DESIGNATION,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (lista),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Reference",renderer,"text",REF,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (lista),column);

 	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Marque",renderer,"text",MARQUE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (lista),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Prix achat",renderer,"text",PRIXACHAT,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (lista),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Stock",renderer,"text",STOCK,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (lista),column);
	
}
store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f=fopen("equipement.bin","rb");
if(f==NULL)
{
return;
}
else
{

while(fread(&P,sizeof(P),1,f))
{
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,TYPE,P.type,DESIGNATION,P.designation,REF,P.ref,MARQUE,P.marque,PRIXACHAT,P.prixachat,STOCK,P.stock,-1);
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW (lista),GTK_TREE_MODEL (store));
g_object_unref (store);

}
}

void supprimer(char ref[20])
{
equipement P;
FILE *f;
FILE *g;
//*supver=0;
f=fopen("equipement.bin","rb");
g=fopen("dumb.bin","ab+");
if((f==NULL)||(g==NULL))
{
return;
}
else
{
while(fread(&P,sizeof(P),1,f))
{ if(strcmp(ref,P.ref)!=0)
	
	fwrite(&P,sizeof(equipement),1,g);
     
	
}
}
fclose(f);
fclose(g);
remove("equipement.bin");
rename("dumb.bin","equipement.bin");
}
/*************************************/
void supprimert2(char ref1[20])
{
equipement P;
FILE *f;
FILE *g;
//*supver=0;
f=fopen("eq.bin","rb");
g=fopen("dumbt2.bin","ab+");
if((f==NULL)||(g==NULL))
{
return;
}
else
{
while(fread(&P,sizeof(P),1,f))
{ if(strcmp(ref1,P.ref)!=0)
	
	fwrite(&P,sizeof(equipement),1,g);
     
	
}
}
fclose(f);
fclose(g);
remove("eq.bin");
rename("dumbt2.bin","eq.bin");
}
/************************************/

void cherchereq(equipement P,char ref1[20], int *verif)
{

FILE *f;
FILE *f1;
f=fopen("equipement.bin","rb");
f1=fopen("modtemp.bin","wb");
*verif=0;
if((f==NULL)||(f1==NULL))
{
return ;
}
else
{

while(fread(&P,sizeof(P),1,f))
{
	if(strcmp(ref1,P.ref)==0)
{
	fwrite(&P,sizeof(P),1,f1);
	*verif=1;
	
	
}

}
}
fclose(f);
fclose(f1);
}
/****************************************************/
void listeModif(GtkWidget *lista)
{
equipement P;
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
store=NULL;
FILE *f;
store=gtk_tree_view_get_model(lista);
if(store==NULL)
{
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Type",renderer,"text",TYPE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (lista),column);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Designation",renderer,"text",DESIGNATION,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (lista),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Reference",renderer,"text",REF,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (lista),column);

 	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Marque",renderer,"text",MARQUE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (lista),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Prix achat",renderer,"text",PRIXACHAT,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (lista),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Stock",renderer,"text",STOCK,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (lista),column);
	
}
store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f=fopen("modtemp.bin","rb");
if(f==NULL)
{
return;
}
else
{
f=fopen("modtemp.bin","ab+");
while(fread(&P,sizeof(P),1,f))
{
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,TYPE,P.type,DESIGNATION,P.designation,REF,P.ref,MARQUE,P.marque,PRIXACHAT,P.prixachat,STOCK,P.stock,-1);
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW (lista),GTK_TREE_MODEL (store));
g_object_unref (store);

}

}
/*************************************************************************/
/*************************************************************************/
void modif_eq(equipement e,char ref[])
{
FILE *f;
FILE *f1;
equipement d;
f=fopen("equipement.bin","rb");
f1=fopen("modtemp.bin","wb");
if((f==NULL)||(f1==NULL))
{
return;
}
else
{
	while(fread(&d,sizeof(d),1,f))
	    {
	if(strcmp(d.ref,ref)!=0)
		fwrite(&d,sizeof(d),1,f1);
		else
		 {
		 fwrite(&e,sizeof(e),1,f1);
		 }
	    }
}

fclose(f);
fclose(f1);
remove("equipement.bin");
rename("modtemp.bin","equipement.bin");
}
/************/
void modif_eq2(equipement P,char ref[])
{
FILE *f;
FILE *f1;
equipement d;

f=fopen("eq.bin","rb");
f1=fopen("modtemp1.bin","wb");
if((f==NULL)||(f1==NULL))
{
return;
}
else
{
	while(fread(&d,sizeof(d),1,f))
	    {
	if(strcmp(d.ref,ref)!=0)
		fwrite(&d,sizeof(d),1,f1);
		else
		 {
		 fwrite(&P,sizeof(P),1,f1);
		 }
	    }
}

fclose(f);
fclose(f1);
remove("eq.bin");
rename("modtemp1.bin","eq.bin");
}
/********************************************************************************/
/********************************************************************************/
void listeficher(GtkWidget *fiche)
{

equipement P;
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

store=NULL;
FILE *f;
store=gtk_tree_view_get_model(fiche);
if(store==NULL)
{
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Type",renderer,"text",TYPE1,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (fiche),column);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Designation",renderer,"text",DESIGNATION1,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (fiche),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Reference",renderer,"text",REF1,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (fiche),column);

 	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Marque",renderer,"text",MARQUE1,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (fiche),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Prix achat",renderer,"text",PRIXACHAT1,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (fiche),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Stock",renderer,"text",STOCK1,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (fiche),column);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Situation",renderer,"text",SITUATION1,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (fiche),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Etat",renderer,"text",ETAT1,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (fiche),column);
	
	
	
}
store=gtk_list_store_new(COLUMNS1,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f=fopen("eq.bin","rb");
if(f==NULL)
{
return;
}
else
{

while(fread(&P,sizeof(P),1,f))
{
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,TYPE1,P.type,DESIGNATION1,P.designation,REF1,P.ref,MARQUE1,P.marque,PRIXACHAT1,P.prixachat,STOCK1,P.stock,SITUATION1,P.situation,ETAT1,P.etat,-1);
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW (fiche),GTK_TREE_MODEL (store));
g_object_unref (store);

}
}
/********************************La fonction plus defaillent ****************************************************************************/
int calcul_defaillement()
{
FILE *f,*f1,*f2;
equipement P;
equipement h;

int max=0;
int def=0;
f=fopen("equipement.bin","rb");
f1=fopen("eq.bin","rb");
f2=fopen("plusdef.bin","ab");
//f2=fopen("plusdef.bin","ab");
if((f==NULL)||(f1==NULL)||(f2==NULL))
{
return;
}
else
{
	
 	while(fread(&P,sizeof(P),1,f))
	{ rewind(f1);
	  def=0;
		
		while(fread(&h,sizeof(h),1,f1))
		  { 
			
				
			  	if(strcmp(P.ref,h.ref)==0)
					{
				 		 if(strcmp(h.etat,"defaillant")==0)
				   		  {
				     			  def+=1;
				       
					
				    		 } 
					
					}
				if(max<def)
				{ max=def;
			          remove(f2);
				  f2=fopen("plusdef.bin","ab");
				 fwrite(&P,sizeof(P),1,f2);
				}
			 
		  }
		

			
	}
 

}
fclose(f);
fclose(f1);
fclose(f2);

//sprintf(defaillant,"%d",&def);
return max;
}


/********************************************************************************************************************************/

void listedefaillant(GtkWidget *fiche)
{

equipement P;
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

store=NULL;
FILE *f2;
store=gtk_tree_view_get_model(fiche);
if(store==NULL)
{
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Type",renderer,"text",TYPE1,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (fiche),column);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Designation",renderer,"text",DESIGNATION1,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (fiche),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Reference",renderer,"text",REF1,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (fiche),column);

 	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Marque",renderer,"text",MARQUE1,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (fiche),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Prix achat",renderer,"text",PRIXACHAT1,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (fiche),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Stock",renderer,"text",STOCK1,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (fiche),column);
	
	/*renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Situation",renderer,"text",SITUATION1,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (fiche),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Etat",renderer,"text",ETAT1,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (fiche),column);*/
	
	
	
}
store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f2=fopen("plusdef.bin","rb");
if(f2==NULL)
{
return;
}
else
{

while(fread(&P,sizeof(P),1,f2))
{
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,TYPE,P.type,DESIGNATION,P.designation,REF,P.ref,MARQUE,P.marque,PRIXACHAT,P.prixachat,STOCK,P.stock,-1);
}
fclose(f2);
gtk_tree_view_set_model(GTK_TREE_VIEW (fiche),GTK_TREE_MODEL (store));
g_object_unref (store);

}
remove("plusdef.bin");
}

/**************************************************************************************************************/
int calcul_utilisation()
{
FILE *f,*f1,*f4;
equipement t;
equipement g;

int max1=0;
int ut=0;
f=fopen("equipement.bin","rb");
f1=fopen("eq.bin","rb");
f4=fopen("plusut.bin","wb");
if((f==NULL)||(f1==NULL))
{
return;
}
else
{
	
 	while(fread(&t,sizeof(t),1,f))
	{ rewind(f1);
	  ut=0;
		
		while(fread(&g,sizeof(g),1,f1))
		  { 
			
				
			  	if(strcmp(t.ref,g.ref)==0)
					{
				 		 if(strcmp(g.situation,"libre")!=0)
				   		  {
				     			  ut+=1;
				       
					
				    		 } 
					
					}
				if(max1<ut)
				{
				 max1=ut;
				remove(f4);
				f4=fopen("plusut.bin","ab");
				fwrite(&g,sizeof(g),1,f4);
				}
			 
		  }
		

			
	}
 //fwrite(&t,sizeof(t),1,f4);

}
fclose(f);
fclose(f1);
fclose(f4);
return max1;
}

/**********************************************************************************/
void listeut(GtkWidget *uti)
{

equipement g;
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

store=NULL;
FILE *f4;
store=gtk_tree_view_get_model(uti);
if(store==NULL)
{
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Type",renderer,"text",TYPE1,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (uti),column);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Designation",renderer,"text",DESIGNATION1,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (uti),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Reference",renderer,"text",REF1,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (uti),column);

 	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Marque",renderer,"text",MARQUE1,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (uti),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Prix achat",renderer,"text",PRIXACHAT1,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (uti),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Stock",renderer,"text",STOCK1,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (uti),column);
	
	/*renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Situation",renderer,"text",SITUATION1,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (uti),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Etat",renderer,"text",ETAT1,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (uti),column);*/
	
	
	
}
store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f4=fopen("plusut.bin","rb");
if(f4==NULL)
{
return;
}
else
{ 
while(fread(&g,sizeof(g),1,f4))
{
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,TYPE,g.type,DESIGNATION,g.designation,REF,g.ref,MARQUE,g.marque,PRIXACHAT,g.prixachat,STOCK,g.stock,-1);
}
fclose(f4);
gtk_tree_view_set_model(GTK_TREE_VIEW (uti),GTK_TREE_MODEL (store));
g_object_unref (store);

}
remove("plusut.bin");
}














