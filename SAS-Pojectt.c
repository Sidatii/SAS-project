#include <stdio.h>
int nb_produit = 0;

typedef struct{

char nom[14];
int qty;
float price;
float price_TTC;

}infos;

typedef struct{

int codee;
infos inf;

}products;

products s[100];
int j, n,choix;
char check[100];

int i,j;
void ajoute(){

start:
int n;
printf("************************Ajoutez vos produits************************\n\n ");
printf("Veuillez saisir le nombre des produits a ajouter: ");
scanf("%d", &n);
printf("Veuillez saisir les infos de votre produit: ");
int temp = nb_produit;
 for (j=temp; j<temp+n;j++){
    printf("\nProduit n %d: \n", j+1);
    printf("Veuillez inserer le code de votre produit: ");
    scanf("%d",&s[j].codee);
    fflush(stdin);
    printf("Veuillez inserer le nom du produit: ");
    scanf("%s",&s[j].inf.nom);
    printf("Veuillez inserer la quantite initiale: ");
    scanf("%d",&s[j].inf.qty);
    fflush(stdin);
    printf("Veuillez inserer le prix unitaire: ");
    scanf("%f",&s[j].inf.price);
    fflush(stdin);
    s[j].inf.price_TTC=s[j].inf.price*1.15;
    nb_produit++;
    system("cls");
    printf("..................Votre produit est bien enregistre..................");
    }
}

void supprimer(){
int del_num,del_code,index;
start:
int n;
printf("************************Supprimez un ou plusieurs produits************************\n\n ");
printf("Veuillez saisir le nombre des produits a supprimer: ");
scanf("%d", &n);

for(i=0; i<n; i++){
printf("Veuillez inserer le code du produit a supprimer n %d: ",i+1);
    scanf("%d",&del_code);fflush(stdin);
 for (j=0; j<nb_produit;j++){

    if(s[j].codee==del_code){
            index=j;
    }
    if(index != -1){
    for(j=index; j<nb_produit;j++)
        s[j]= s[j+1];
        nb_produit--;
    }

    printf("..................Votre produit est supprime..................\n\n");
    }
}
printf("Votre nouvelle liste s'affiche comme suit: \n");
for (j=0; j<nb_produit;j++)
    printf("\n%d \t %s \t %d \t %f \t %f\n",s[j].codee,s[j].inf.nom,s[j].inf.qty,s[j].inf.price,s[j].inf.price_TTC);


}

void list_produits(){

    for (j=0; j<nb_produit;j++){
    printf("\n%d \t %s \t %d \t %f \t %f\n",s[j].codee,s[j].inf.nom,s[j].inf.qty,s[j].inf.price,s[j].inf.price_TTC);
    }

}

int main () {

    start1:
    system("cls");
    printf("*******************************************************************************************************************\n");
    printf("                           ||      The NOUHI Pharmacy management system         ||\n");
    printf("                           ||  Your application to better manage your pharmacy  ||\n");
    printf("*******************************************************************************************************************\n\n");
    printf("Bienvenue!! Que est ce que vous voulez faire?\n\n");
    start:
    printf("________________________________\n");
    printf("1 : Ajouter un ou plusieurs produits \n");
    printf("2 : Supprimer un ou plusieurs produits\n");
    printf("3 : Liste des produits \n");
    printf("4 : Gestion vente/achat \n");
    printf("5 : Etat d'inventaire \n");
    printf("6 : Quitter le program\n");
    printf("________________________________\n");
    printf("Veuillez saisir votre choix: ");
    scanf("%d",&choix);

    while ((choix < 1 || choix > 6) ||  (sscanf(check, "%d", &choix)==1)){
        fgets(check, 100, stdin);
        system("cls");
        printf("Saisie invalid!!! \nVeuillez saisir un choix valid.\n ");
        goto start;
        }


    switch(choix){
///Ajouter un ou plusieurs produits
        case 1:
            aj:
            system("cls");
            ajoute();
            printf("\n1. Afficher la liste des produits\n2. Retour au menu principale\n");
            printf("-------> ");
            scanf("%d",&choix);
            system("cls");
            switch (choix){
                case 1:
                    list_produits();
                    printf("\n1. Ajouter un ou plusieurs produits\n2. Supprimer un ou plusieurs produits\n3. Retour au menu principale\n");
                    printf("-------> ");
                    scanf("%d",&choix);
                    system("cls");
                        switch(choix){
                            case 1: goto aj;
                            case 2: goto supp;
                            case 3: goto start1;
                            }

                case 2:
                    goto start1;
                    break;
                    }
///Supprimer un ou plusieurs produits:
        case 2:
            supp:
            supprimer();
            printf("\n1. Ajouter un ou plusieurs produits\n2. Supprimer un ou plusieurs produits\n3. Retour au menu principale\n");
            printf("-------> ");
            scanf("%d",&choix);
            system("cls");
                    switch(choix){
                        case 1:
                            goto aj;
                        case 2:
                            goto supp;
                        case 3:
                            goto start1;
                    }
///Liste des produits
        case 3: list:
            system("cls");
            list_produits();
            printf("\n1. Ajouter un ou plusieurs produits\n2. Retour au menu principale\n");
            printf("-------> ");
            scanf("%d",&choix);
            system("cls");
                switch (choix){
                    case 1:
                        goto aj;
                    case 2:
                        goto start1;

                }
///Gestion vente\achat
        case 4:
///Etat d'inventaire
        case 5:
///Quit program
        case 6:
            system("exit");

    }











return 0;

}

