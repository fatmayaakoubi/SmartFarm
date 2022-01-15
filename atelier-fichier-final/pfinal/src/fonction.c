#include <stdio.h>
#include <string.h>
#include "fonction.h"

int verif(char user[], char pw[])
{
int trouve = -1;
char nom[20], prenom[20], username[20], password[20], role[20];

FILE *fp=NULL;

fp = fopen("utilisateurs.txt", "r");

if (fp==NULL)
{
printf("Echec lors de l'ouverture du fichier 'utilisateurs.txt'");
}
else
{
while(fscanf(fp, "%s %s %s %s %s", nom, prenom, username, password, role)!=EOF)
{
if ((strcmp(user, username)==0) && (strcmp(pw, password)==0))
trouve = 1;
}
fclose(fp);
}

return (trouve);


}
