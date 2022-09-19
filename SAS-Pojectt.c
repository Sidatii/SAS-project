#include <stdio.h>
int nb_produit = 0;
int compteur = 0;

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

typedef struct{


char nom[14];
int qty;
float prix;
float Total_TTC;

}info;

typedef struct{

int codee;
info inf;

}ventes;

products s[100];
ventes t[100];
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

    for (j=0; j<nb_produit;j++){
    printf("\n%d \t %s \t %d \t %f \t %f\n",s[j].codee,s[j].inf.nom,s[j].inf.qty,s[j].inf.price,s[j].inf.price_TTC);
    }

}

void reduire_qte(){

int reduire_num,reduire_code,redu_qte,index;
int n;
printf("************************Reduire la quantite d un ou plusieurs produits************************\n\n ");
printf("Veuillez saisir le nombre des produits a mettre a jour: ");
scanf("%d", &n);

for(i=0; i<n; i++){
    printf("Veuillez inserer le code du produit a mettre a jour n %d: ",i+1);
    scanf("%d",&reduire_code);fflush(stdin);
    printf("Veuillez inserer la quantite a deduire: ");
    scanf("%d",&redu_qte);fflush(stdin);

        for(int m=0; m<nb_produit;m++)
            if(s[m].codee==reduire_code){
                index=m;
            }
        s[index].inf.qty -= redu_qte;
        t[compteur].codee = s[index].codee;
        strcpy(t[compteur].inf.nom,s[index].inf.nom);
        t[compteur].inf.qty = redu_qte;
        t[compteur].inf.prix = s[index].inf.price;
        t[compteur].inf.Total_TTC = s[compteur].inf.price*s[compteur].inf.qty*1.15;
        compteur++;



    printf("..................La quantite produit est mis a jour..................\n\n");

}
printf("Votre nouvelle liste s'affiche comme suit: \n\n");
printf("Code\tNom\tQte\tPrix HT\t  Prix TTC");
for (int k=0; k<nb_produit;k++)
    printf("\n%d \t %s \t %d \t %f \t %f\n",s[k].codee,s[k].inf.nom,s[k].inf.qty,s[k].inf.price,s[k].inf.price_TTC);

}

void augmente_qte(){

int augmente_num,augmente_code,augm_qte,index;
int n;
printf("************************Alimenter la quantite d un ou plusieurs produits************************\n\n ");
printf("Veuillez saisir le nombre des produits a mettre a jour: ");
scanf("%d", &n);

for(i=0; i<n; i++){
    printf("Veuillez inserer le code du produit a mettre a jour n %d: ",i+1);
    scanf("%d",&augmente_code);fflush(stdin);
    printf("Veuillez inserer la quantite a deduire: ");
    scanf("%d",&augm_qte);fflush(stdin);
    for (j=0; j<nb_produit;j++){

        for(int m=0; m<nb_produit;m++){
            if(s[m].codee==augmente_code){
                index=m;
            }
                s[index].inf.qty += augm_qte;

        }
    }
    printf("..................Votre quantite produit est mis a jour..................\n\n");

}
printf("Votre nouvelle liste s'affiche comme suit: \n\n");
printf("Code\tNom\tQte\tPrix HT\t  Prix TTC");
for (int k=0; k<nb_produit;k++)
    printf("\n%d \t %s \t %d \t %f \t %f\n",s[k].codee,s[k].inf.nom,s[k].inf.qty,s[k].inf.price,s[k].inf.price_TTC);

}

void Ascendant_par_nom(){

for(i=0; i<nb_produit;i++){
    if(strcmp(s[i].inf.nom,s[i+1].inf.nom)==1){
        products temp = s[i];
        s[i] = s[i+1];
        s[i+1] = temp;
    }

}
printf("Votre nouvelle liste s'affiche comme suit: \n\n");
printf("Code\tNom\tQte\tPrix HT\t  Prix TTC");
for (int k=0; k<nb_produit;k++)
    printf("\n%d \t %s \t %d \t %f \t %f\n",s[k].codee,s[k].inf.nom,s[k].inf.qty,s[k].inf.price,s[k].inf.price_TTC);

}

void Descendant_par_nom(){

for(i=0; i<nb_produit;i++){
    if(s[i].inf.price < s[i+1].inf.price){
        products temp = s[i];
        s[i] = s[i+1];
        s[i+1] = temp;
    }

}
printf("Votre nouvelle liste s'affiche comme suit: \n\n");
printf("Code\tNom\tQte\tPrix HT\t  Prix TTC");
for (int k=0; k<nb_produit;k++)
    printf("\n%d \t %s \t %d \t %f \t %f\n",s[k].codee,s[k].inf.nom,s[k].inf.qty,s[k].inf.price,s[k].inf.price_TTC);

}

void Journal_ventes(){
    printf("\nCode\tNom\tQte\tPrix\tTotal TTC\n");
    for (j=0; j<compteur;j++){
    printf("\n%d \t %s \t %d \t %f \t %f\n",t[j].codee,t[j].inf.nom,t[j].inf.qty,t[j].inf.prix,t[j].inf.Total_TTC);
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
    invalid:
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
                    /*system("cls");
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
                            }*/
                default:
                    system("cls");
                    Ascendant_par_nom();



            }
///Gestion vente\achat
        case 4:
            printf("\n1. Reduire la quantite d un ou plusieurs produit\n2. Alimenter la quantite d un ou plusieurs produit\n3. Retour au menu principale\n");
            printf("-------> ");
            scanf("%d",&choix);
            system("cls");
            switch(choix){
                case 1:
                    reduire:
                    reduire_qte();
                    printf("\n1. Reduire la quantite d un ou plusieurs produit\n2. Augmenter la quantite d un ou plusieurs produit\n3. Retour au menu principale\n");
                    printf("-------> ");
                    scanf("%d",&choix);
                    system("cls");
                        switch (choix){
                            case 1:
                                goto reduire;
                            case 2:
                                goto augmente;
                            default:
                                goto start1;
                        }
                case 2:
                    augmente:
                    augmente_qte();
                    printf("\n1. Augmenter la quantite d un ou plusieurs produit\n2. Reduire la quantite d un ou plusieurs produit\n3. Afficher le journal des ventes\n4. Retour au menu principale\n");
                    printf("-------> ");
                    scanf("%d",&choix);
                    system("cls");
                        switch (choix){
                            case 1:
                                goto augmente;
                            case 2:
                                goto reduire;
                            default:
                                goto start1;


                        }
                case 3:
                    Journal_ventes();
                    printf("\n1. Augmenter la quantite d un ou plusieurs produit\n2. Reduire la quantite d un ou plusieurs produit\n3. Retour au menu principale\n");
                    printf("-------> ");
                    scanf("%d",&choix);
                    system("cls");
                        switch (choix){
                            case 1:
                                goto augmente;
                            case 2:
                                goto reduire;
                            default:
                                goto start1;
                        }
                default:
                    goto start1;
            }
///Etat d'inventaire
        case 5:
///Quit program
        case 6:
            system("exit");

    }











return 0;

}

