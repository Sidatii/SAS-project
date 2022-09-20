#include <stdio.h>
#include <time.h>
int nb_produit = 0;
int compteur = 0;
int compteur1 =0;

typedef struct{

char nom[14];
int qty;
float price;
float price_TTC;

}infos;

typedef struct{ ///Produits

int codee;
infos inf;

}products;

typedef struct{

int jour;
int mois;
int annee;

}date_operation1;

typedef struct{


char nom[14];
int qty;
float prix;
float Total_TTC;
date_operation1 d;

}informations1;

typedef struct{ ///Ventes

int codee;
informations1 inf;

}ventes;

typedef struct{

int jour;
int mois;
int annee;

}date_operation2;

typedef struct{


char nom[14];
int qty;
float prix_TTC;
float Total;
date_operation2 dt;

}informations2;

typedef struct{ ///Achats

int codee;
informations2 info;

}achats;

products s[100];
ventes t[100];
achats a[100];
int j, n,choix;
char check[100];
int i,j;

void ajoute(){
int n;
start:

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
int n;
start:

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

    printf("Code\tNom\tQte\tPrix HT\t        Prix TTC\n");
    for (j=0; j<nb_produit;j++){
    printf("\n%d \t %s \t %d \t %f \t %f\n",s[j].codee,s[j].inf.nom,s[j].inf.qty,s[j].inf.price,s[j].inf.price_TTC);
    }

}

void Enregistrement_ventes(){

int code_code,qte_vendue,index;
int n;
printf("************************Enregister une ou plusieurs operation vente************************\n\n ");
printf("Veuillez saisir le nombre des produits vendus: ");
scanf("%d", &n);

for(i=0; i<n; i++){
    printf("Veuillez saisir le code du produit vendu n %d: ",i+1);
    scanf("%d",&code_code);fflush(stdin);
    printf("Veuillez saisir la quantite vendue: ");
    scanf("%d",&qte_vendue);fflush(stdin);

        for(int m=0; m<nb_produit;m++)
            if(s[m].codee==code_code){
                index=m;
            }
        s[index].inf.qty -= qte_vendue;
        t[compteur].codee = s[index].codee;
        strcpy(t[compteur].inf.nom,s[index].inf.nom);
        t[compteur].inf.qty = qte_vendue;
        t[compteur].inf.prix = s[index].inf.price;
        t[compteur].inf.Total_TTC = s[index].inf.price*qte_vendue*1.15;
        time_t h = time(NULL);
        struct tm tm = *localtime(&h);
        t[compteur].inf.d.jour = tm.tm_mday;
        t[compteur].inf.d.mois = tm.tm_mon + 1;
        t[compteur].inf.d.annee = tm.tm_year + 1900;
        compteur++;



    printf("..................L'operation est enregistree..................\n\n");

}
printf("..................journal des ventes..................\n\n");
printf("Code\tNom\tQte\tPrix HT\t        Total TTC\t        Date operation");
for (int k=0; k<compteur;k++)
    printf("\n%d\t%s\t%d\t%f\t%f\t%d/%d/%d\n",t[k].codee,t[k].inf.nom,t[k].inf.qty,t[k].inf.prix,t[k].inf.Total_TTC,t[k].inf.d.jour,t[k].inf.d.mois,t[k].inf.d.annee);

}

void Enregistrement_achats(){

int qte_code2,qte_achetee,index;
int n;
printf("************************Alimenter le stock d un ou plusieurs produits************************\n\n ");
printf("Veuillez saisir le nombre des produits a alimenter: ");
scanf("%d", &n);

for(i=0; i<n; i++){
    printf("Veuillez saisir le code du produit a alimenter n %d: ",i+1);
    scanf("%d",&qte_code2);fflush(stdin);
    printf("Veuillez saisir la quantite a ajouter: ");
    scanf("%d",&qte_achetee);fflush(stdin);
    for (j=0; j<nb_produit;j++){

        for(int m=0; m<nb_produit;m++){
            if(s[m].codee==qte_code2){
                index=m;
            }
        s[index].inf.qty += qte_achetee;
        a[compteur1].codee = s[index].codee;
        strcpy(a[compteur1].info.nom,s[index].inf.nom);
        a[compteur1].info.qty = qte_achetee;
        a[compteur1].info.prix_TTC = s[index].inf.price*1.15;
        a[compteur1].info.Total = s[index].inf.price_TTC*qte_achetee;
        time_t h2 = time(NULL);
        struct tm tm = *localtime(&h2);
        a[compteur1].info.dt.jour=tm.tm_mday;
        a[compteur1].info.dt.mois=tm.tm_mon + 1;
        a[compteur1].info.dt.annee=tm.tm_year + 1900;
        compteur1++;
        }
    }
    printf("..................L'operation est enregistree.................\n\n");

}
printf("..................journal des achats..................\n\n");
printf("Code\tNom\tQte\tPrix HT\t        Prix TTC\t        Date operation\n");
for (int k=0; k<compteur1;k++)
    printf("\n%d\t%s\t%d\t%f\t%f\t%d/%d/%d\n",a[k].codee,a[k].info.nom,a[k].info.qty,a[k].info.prix_TTC,a[k].info.Total,a[k].info.dt.jour,a[k].info.dt.mois,a[k].info.dt.annee);

}

void Ascendant_par_nom(){

for(j=0; j<nb_produit-1;j++){
    for(i=1; i<nb_produit;i++){
        if(strcmp(s[j].inf.nom,s[i].inf.nom)==0){
            products temp = s[i];
            s[i] = s[j];
            s[j] = temp;
        }
    }
}
printf("Votre nouvelle liste s'affiche comme suit: \n\n");
printf("Code\tNom\tQte\tPrix HT\t  Prix TTC");
for (int k=0; k<nb_produit;k++)
    printf("\n%d \t %s \t %d \t %f \t %f\n",s[k].codee,s[k].inf.nom,s[k].inf.qty,s[k].inf.price,s[k].inf.price_TTC);

}

void Descendant_par_prix(){

for(j=0; j<nb_produit-1;j++){
    for(i=1; i<nb_produit;i++){
        if(s[j].inf.price < s[i].inf.price){
            products temp = s[i];
            s[i] = s[j];
            s[j] = temp;
    }
    }
}
printf("Votre nouvelle liste s'affiche comme suit: \n\n");
printf("Code\tNom\tQte\tPrix HT\t  Prix TTC");
for (int k=0; k<nb_produit;k++)
    printf("\n%d \t %s \t %d \t %f \t %f\n",s[k].codee,s[k].inf.nom,s[k].inf.qty,s[k].inf.price,s[k].inf.price_TTC);

}

void Journal_ventes(){
    printf("\nCode\tNom\tQte\tPrix\t   Total TTC\t   Date operation\n");
    for (j=0; j<compteur;j++){
    printf("\n%d\t%s\t%d\t%f\t%f\t%d/%d/%d\n",t[j].codee,t[j].inf.nom,t[j].inf.qty,t[j].inf.prix,t[j].inf.Total_TTC,t[j].inf.d.jour,t[j].inf.d.mois,t[j].inf.d.annee);
    }

}

void Journal_achats(){
    printf("\nCode\tNom\tQte\tPrix TTC\t     Total\t     Date operation\n");
    for (i=0; i<compteur1;i++){
    printf("\n%d\t%s\t%d\t%f\t%f\t%d/%d/%d\n",a[i].codee,a[i].info.nom,a[i].info.qty,a[i].info.prix_TTC,a[i].info.Total,a[i].info.dt.jour,a[i].info.dt.mois,a[i].info.dt.annee);
    }

}

int main () {

    start1:
    printf("*******************************************************************************************************************\n");
    printf("                           ||      The NOUHI Pharmacy management system         ||\n");
    printf("                           ||  Your application to better manage your pharmacy  ||\n");
    printf("*******************************************************************************************************************\n\n");
    printf("\033[0;36mBienvenue!! Que est ce que vous voulez faire?\033[0m\n\n");
    invalid:
    printf("|********************************************|\n");
    printf("|1 : Ajouter un ou plusieurs produits        |\n");
    printf("|--------------------------------------------|\n");
    printf("|2 : Supprimer un ou plusieurs produits      |\n");
    printf("|--------------------------------------------|\n");
    printf("|3 : Liste des produits                      |\n");
    printf("|--------------------------------------------|\n");
    printf("|4 : Gestion des Vente                       |\n");
    printf("|--------------------------------------------|\n");
    printf("|5 : Gestion des Achat                       |\n");
    printf("|--------------------------------------------|\n");
    printf("|6 : Etat d'inventaire                       |\n");
    printf("|--------------------------------------------|\n");
    printf("|7 : Quitter le program                      |\n");
    printf("|********************************************|\n");
    printf("Veuillez saisir votre choix: ");
    scanf("%d",&choix);

    while ((choix < 1 || choix > 7) ||  (sscanf(check, "%d", &choix)==1)){
        fgets(check, 100, stdin);
        system("cls");
        printf("\a\033[0;41mSaisie invalid!!!\033[0m \nVeuillez saisir un choix valid.\n");
        goto invalid;
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
                            default: goto start1;
                            }

                case 2:
                    goto start1;
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
                        default:
                            goto start1;
                    }
///Liste des produits
        case 3:
            printf("\n1. Afficher la list des produits\n2. Afficher la list triee ascendante par nom\n3. Afficher la list triee descendante par prix\n4. Retour au menu principale\n");
            printf("-------> ");
            scanf("%d",&choix);
            switch (choix){
                case 1:
                    list:
                    system("cls");
                    list_produits();
                    printf("\n1. Ajouter un ou plusieurs produits\n2. Supprimer un ou plusieurs produits\n3. Retour au menu principale\n");
                    printf("-------> ");
                    scanf("%d",&choix);
                    system("cls");
                        switch (choix){
                            case 1:
                                goto aj;
                            case 2:
                                goto supp;
                            default:
                                goto start1;
                            }

                case 2:
                    system("cls");
                    Ascendant_par_nom();
                    printf("\n1. Ajouter un ou plusieurs produits\n2. Supprimer un ou plusieurs produits\n3. Retour au menu principale\n");
                    printf("-------> ");
                    scanf("%d",&choix);
                    system("cls");
                        switch (choix){
                            case 1:
                                goto aj;
                            case 2:
                                goto supp;
                            default:
                                goto start1;
                            }
                case 3:
                    system("cls");
                    Descendant_par_prix();
                    printf("\n1. Ajouter un ou plusieurs produits\n2. Supprimer un ou plusieurs produits\n3. Retour au menu principale\n");
                    printf("-------> ");
                    scanf("%d",&choix);
                    system("cls");
                        switch (choix){
                            case 1:
                                goto aj;
                            case 2:
                                goto supp;
                            default:
                                goto start1;
                            }
                default:
                    system("cls");
                    Ascendant_par_nom();

            }
///Gestion vente
        case 4:
            printf("\n1. Enregistrer une ou plusieurs operations vente\n2. Afficher le journal des ventes\n3. Retour au menu principale\n");
            printf("-------> ");
            scanf("%d",&choix);
            system("cls");
            switch(choix){

                ///Enregistrement des ventes
                case 1:
                    ventes:
                    Enregistrement_ventes();
                    printf("\n1. Enregistrer une ou plusieurs operations vente\n2. Afficher le journal des ventes\n4. Retour au menu principale\n");
                    printf("-------> ");
                    scanf("%d",&choix);
                    system("cls");
                        switch (choix){
                            case 1:
                                goto ventes;
                            case 2:
                                goto journal_vte;
                            default:
                                goto start1;
                        }
                ///Journal des ventes
                case 2:
                    journal_vte:
                    Journal_ventes();
                    printf("\n1. Enregistrer une ou plusieurs operations vente\n2. Retour au menu principale\n");
                    printf("-------> ");
                    scanf("%d",&choix);
                    system("cls");
                        switch (choix){
                            case 1:
                                goto ventes;
                            default:
                                goto start1;
                        }
                ///Menu principale
                default:
                    goto start1;
            }
///Gestion achats
        case 5:
            printf("\n1. Alimenter le stock d un ou plusieurs produit\n2. Afficher le journal des achats\n3. Retour au menu principale\n");
            printf("-------> ");
            scanf("%d",&choix);
            system("cls");
            switch(choix){
                ///Enregistrement des achats
                case 1:
                    achats:
                    Enregistrement_achats();
                    printf("\n1. Alimenter le stock d un ou plusieurs produit\n2. Afficher le journal des achats\n3. Retour au menu principale\n");
                    printf("-------> ");
                    scanf("%d",&choix);
                    system("cls");
                        switch (choix){
                            case 1:
                                goto achats;
                            case 2:
                                goto journal_ach;
                            default:
                                goto start1;
                        }
                ///Journal des achats
                case 2:
                    journal_ach:
                    Journal_achats();
                    printf("\n1. Alimenter le stock d un ou plusieurs produit\n2. Retour au menu principale\n");
                    printf("-------> ");
                    scanf("%d",&choix);
                    system("cls");
                        switch (choix){
                            case 1:
                                goto achats;
                            default:
                                goto start1;
                        }
                ///Menu principale
                default:
                    goto start1;
            }
///Etat d'inventaire
        case 6:
///Quit program
        case 7:
            system("exit");

    }

return 0;

}

