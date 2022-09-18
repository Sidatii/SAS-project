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
printf("Veuillez saisir le nombre des produits à ajouter: ");
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
    printf("Veuillez inserer la quantite initiale:");
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

    printf("\n1. Afficher la liste des produits\n2. Retour au menu principale");
    scanf("%d",&choix);
    system("cls");


    }




void list_produits(){
    int afficher;
    /*printf("Veuillez saisir le nombre des lignes a afficher: ");
    scanf("%d", &afficher);*/
    for (j=0; j<nb_produit;j++)
    printf("\n%d \t %s \t %d \t %f \n",s[j].codee,s[j].inf.nom,s[j].inf.qty,s[j].inf.price,s[j].inf.price_TTC);
}


///
int main () {

    start1:
    system("cls");
    printf("*******************************************************************************************************************\n");
    printf("                                   The NOUHI Pharmacy management system\n");
    printf("                               Your application to better manage your pharmacy \n");
    printf("*******************************************************************************************************************\n\n");
    printf("Bienvenue!! Que est ce que vous voulez faire?\n\n");
    start:
    printf("________________________________\n");
    printf("1 : Ajouter un ou plusieurs produits \n");
    printf("2 : Supprimer un ou plusieurs produits\n");
    printf("3 : Gestion de stock \n");
    printf("4 : Etats de synthese \n");
    printf("5 : Etat d inventaire \n");
    printf("6 : Quitter le program\n");
    printf("________________________________\n");
    printf("Veuillez saisir votre choix: ");
    scanf("%d",&choix);

    while ((choix < 1 || choix >= 6) ||  (sscanf(check, "%d", &choix)==1)){
        fgets(check, 100, stdin);
        system("cls");
        printf("Saisie invalid !!! \nVeuillez saisir un choix valid.\n ");
        goto start;
        }


    switch(choix){
        case 1:
            ajoute();
            switch (choix){
                case 1:
                    list_produits();
                    break;
                case 2:
                    goto start1;
                    break;
        //case 2:
}
///Ajouter un ou plusieurs produits:

///Supprimer un ou plusieurs produits:

///Gestion de stock:

///Etats de synthese:

///Etat d'inventaire




return 0;

}
}
