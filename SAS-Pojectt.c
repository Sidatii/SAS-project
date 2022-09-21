#include <stdio.h>
#include <time.h>
#include <string.h>

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

int ajoute(){
int n;
start:
printf("************************Ajoutez vos produits************************\n\n ");
printf("Veuillez saisir le nombre des produits a ajouter: ");
scanf("%d", &n);
int temp = nb_produit;
//La choix d abondonner les modifications--------------------------------------------
    int x;
        printf("Voulez-vous continuer cette operation?\n1. No  || 2. YES\n\n-------> ");
        scanf("%d", &x);
            if(x==1) return 0;

//------------------------------------------------------------------------------------
printf("Veuillez saisir les infos de votre produit: ");

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

int supprimer(){
int del_num,del_code;
int index = -1;
int n;
start:
system("cls");
printf("************************Supprimez un ou plusieurs produits************************\n\n ");
printf("Veuillez saisir le nombre des produits a supprimer: ");
scanf("%d", &n);
//La choix d abondonner les modifications--------------------------------------------
    int x;
        printf("Voulez-vous continuer cette operation?\n1. No  || 2. YES\n\n---------> ");
        scanf("%d", &x);
            if(x==1) return 0;
//------------------------------------------------------------------------------------
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
printf("Votre nouvelle liste: \n");
for (j=0; j<nb_produit;j++)
    printf("\n%d \t %s \t %d \t %f \t %f\n",s[j].codee,s[j].inf.nom,s[j].inf.qty,s[j].inf.price,s[j].inf.price_TTC);
}

void Approvisionnement(){

    printf("\33[0;36m");
    printf("Code\tNom\tQte\tPrix HT\t        Prix TTC\n");
    printf("\033[0m");
    for (j=0; j<nb_produit;j++){
            if(s[j].inf.qty<3)
            printf("\n%d \t %s \t %d \t %f \t %f\n",s[j].codee,s[j].inf.nom,s[j].inf.qty,s[j].inf.price,s[j].inf.price_TTC);
    }

}

int Enregistrement_ventes(){

int code_code,qte_vendue,index;
int n;
printf("************************Enregister une ou plusieurs operation vente************************\n\n ");
printf("Veuillez saisir le nombre des produits vendus: ");
scanf("%d", &n);
//----------------------------------------------------------------------------------------------
if(nb_produit==0){ //La verification si la table est vide.
          printf("\n\a\033[0;41mVous avez pas encore ajoute des produits!!!\033[0m\n\nVeuillez ajouter des produit auparavant\\n\n");
          }

//----------------------------------------------------------------------------------------------



for(i=0; i<n; i++){
        begin:
    printf("Veuillez saisir le code du produit vendu n %d: ",i+1);
    scanf("%d",&code_code);fflush(stdin);

    //Recherche si le code saisi est existant.
    for(int l=0;l<nb_produit;l++){
        if(s[l].codee==code_code)
            break;
        if(l>nb_produit){
        printf("\n\n\a\033[0;31mDesole!!! Le code saisi n existe pas dans la list des produits\033[0m\n\n");
        goto begin;}}
        //----------------------------------------------------------------------------------------------


    printf("Veuillez saisir la quantite vendue: ");
    scanf("%d",&qte_vendue);fflush(stdin);
        for(int m=0; m<nb_produit;m++)
            if(s[m].codee==code_code){
                index=m;
                if(qte_vendue>s[m].inf.qty){
                    system("cls");
                    printf("L etat de stock du produit ne peut pas satisfaire la quantitee saisie!!\n\n");
                    goto begin;
                }
            }
            int x;
        printf("Voulez-vous vraiment effectuer cette operation?\n1. No  || 2. YES\n\n");
        scanf("%d", &x);
            if(x==1){ system("cls"); return 0;}

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

int Enregistrement_achats(){

int qte_code2,qte_achetee,index;
int n;
printf("************************Alimenter le stock d un ou plusieurs produits************************\n\n ");
printf("Veuillez saisir le nombre des produits a alimenter: ");
scanf("%d", &n);
//--------------------------------------------------------------------------------------------
if(nb_produit==0){ //La verification si la table est vide.
          printf("\n\a\033[0;41mVous avez pas encore ajoute des produits!!!\033[0m\n\nVeuillez ajouter des produit auparavant\n\n");
          return 0;
          }

//--------------------------------------------------------------------------------------------
for(i=0; i<n; i++){
    printf("Veuillez saisir le code du produit a alimenter n %d: ",i+1);
    scanf("%d",&qte_code2);fflush(stdin);
    printf("Veuillez saisir la quantite a ajouter: ");
    scanf("%d",&qte_achetee);fflush(stdin);
    for(int m=0; m<nb_produit;m++)
        if(s[m].codee==qte_code2){
                index=m;
            }
            int x;
        printf("Voulez-vous vraiment effectuer cette operation?\n1. No  || 2. YES\n\n");
        scanf("%d", &x);
            if(x==1){system("cls"); return 0;}

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

    printf("..................L'operation est enregistree.................\n\n");

    printf("..................journal des achats..................\n\n");
    printf("Code\tNom\tQte\tPrix HT\t        Prix TTC\t        Date operation\n");
    for (int k=0; k<compteur1;k++)
    printf("\n%d\t%s\t%d\t%f\t%f\t%d/%d/%d\n",a[k].codee,a[k].info.nom,a[k].info.qty,a[k].info.prix_TTC,a[k].info.Total,a[k].info.dt.jour,a[k].info.dt.mois,a[k].info.dt.annee);
}

void Ascendant_par_nom(){

for(int i=0;i<nb_produit-1;i++){
    for(int j=i+1;j<nb_produit;j++){
        if(strcmp(s[i].inf.nom,s[j].inf.nom)==1){
            products temp;
            temp = s[i];
            s[i] = s[j];
            s[j] = temp;
        }
    }
}

printf("...........................[List des produit triee ascendante par nom]...........................\n\n");
printf("\33[0;36m");
printf("Code\tNom\tQte\tPrix HT\t     Prix TTC");
printf("\033[0m");
for (int k=0; k<nb_produit;k++)
    printf("\n%d \t %s \t %d \t %f \t %f\n",s[k].codee,s[k].inf.nom,s[k].inf.qty,s[k].inf.price,s[k].inf.price_TTC);

}

void Descendant_par_prix(){

for(int i=0;i<nb_produit-1;i++){
        for(int j=i+1;j<nb_produit;j++){
            if(s[i].inf.price<s[j].inf.price){
                products temp1;
                temp1 = s[i];
                s[i] = s[j];
                s[j] = temp1;
            }
        }
}
printf("...........................[List des produit triee descendante par prix]...........................\n\n");
printf("\33[0;36m");
printf("Code\tNom\tQte\tPrix HT\t     Prix TTC");
printf("\033[0m");
for (int k=0; k<nb_produit;k++)
    printf("\n%d \t %s \t %d \t %f \t %f\n",s[k].codee,s[k].inf.nom,s[k].inf.qty,s[k].inf.price,s[k].inf.price_TTC);

}

void Journal_ventes(){
    printf("...........................[Journal des ventes]...........................\n\n");
    printf("\33[0;36m");
    printf("\nCode\tNom\tQte\tPrix\t      Total TTC\t    Date operation\n");
    printf("\033[0m");
    for (j=0; j<compteur;j++){
    printf("\n%d\t%s\t%d\t%f\t%f\t%d/%d/%d\n",t[j].codee,t[j].inf.nom,t[j].inf.qty,t[j].inf.prix,t[j].inf.Total_TTC,t[j].inf.d.jour,t[j].inf.d.mois,t[j].inf.d.annee);
    }

}

void Journal_achats(){
    printf("...........................[Journal des achats]...........................\n\n");
    printf("\33[0;36m");
    printf("\nCode\tNom\tQte\tPrix TTC\t      Total\t     Date operation\n");
    printf("\033[0m");
    for (i=0; i<compteur1;i++){
    printf("\n%d\t%s\t%d\t%f\t%f\t%d/%d/%d\n",a[i].codee,a[i].info.nom,a[i].info.qty,a[i].info.prix_TTC,a[i].info.Total,a[i].info.dt.jour,a[i].info.dt.mois,a[i].info.dt.annee);
    }

}

void recherche(){

printf("..............................Rechercher un produit.............................."
       ".................................................................................\n");
        int choix;
        printf("\n1. Recherche par Code produit\n2. Recherche par Quantite produit\n\nVeuillez saisir votre choix: ");
        scanf("%d", &choix);
        int recherche;
        switch(choix){
            case 1:
                int index01 = -1;
                printf("Veuillez saisir le code du produit a rechercher: ");
                scanf("%d",&recherche);fflush(stdin);
                int m, index;
                for(m=0;m<nb_produit;m++){
                    if(s[m].codee==recherche)
                        index01= m;
                        break;
                }
                if(index01 == -1)
                printf("\n\n\a\033[0;31mDesole!!! Le code recherche n existe pas dans la list des produits\033[0m\n\n");
                else
                printf("\n\n%d\t%s\t%d\t%f\n\n",s[m].codee,s[m].inf.nom,s[m].inf.qty,s[m].inf.price);
                break;
            case 2:
                int index02 = -1;
                printf("Veuillez saisir la quantite du produit a rechercher: ");
                scanf("%d",&recherche);fflush(stdin);
                for(m=0;m<nb_produit;m++){
                    if(s[m].inf.qty==recherche)
                        index02= m;
                        break;
                }
                if(index01 == -1)
                printf("\n\n\a\033[0;31mDesole!!! La quantite recherchee n existe pas dans la list des produits\033[0m\n\n");
                else
                printf("\n\n%d\t%s\t%d\t%f\n\n",s[m].codee,s[m].inf.nom,s[m].inf.qty,s[m].inf.price);
                break;
        }
}

void stats_ventes(){
    float chiffre_affaire_vte = 0;
    time_t h2 = time(NULL);
    struct tm tm = *localtime(&h2);
    //La somme des ventes journaliers
    for(i=0; i<compteur; i++){
        if(t[i].inf.d.jour==tm.tm_mday && (t[i].inf.d.mois==tm.tm_mon + 1) && (t[i].inf.d.annee==tm.tm_year + 1900))
        chiffre_affaire_vte += t[i].inf.Total_TTC;
    }
    //La moyenne des ventes
    float moyenne_vte;
    moyenne_vte = chiffre_affaire_vte/compteur;

    float max_vte;
    max_vte=t[0].inf.Total_TTC;
    int index;
    for (int i=1 ; i<compteur ; i++){
        if(t[i].inf.d.jour==tm.tm_mday && t[i].inf.d.mois==tm.tm_mon + 1 && t[i].inf.d.annee==tm.tm_year + 1900){
            if(t[i].inf.Total_TTC>max_vte){
                max_vte=t[i].inf.Total_TTC;
                index = i;
            }
        }

    }
    float min_vte;
    min_vte=t[0].inf.Total_TTC;
    int index1;
    for (int i=1 ; i<compteur ; i++){
        if(t[i].inf.d.jour==tm.tm_mday && t[i].inf.d.mois==tm.tm_mon + 1 && t[i].inf.d.annee==tm.tm_year + 1900){
            if(t[i].inf.Total_TTC<min_vte){
                min_vte=t[i].inf.Total_TTC;
                index1 = i;
            }
        }

    }

    printf("Chiffre d affaire journalier: %f Dh\n\nMoyenne vente journaliere: %f Dh\n\n", chiffre_affaire_vte,moyenne_vte);
    printf("Le produit avec le chiffre d affaire le plus grand:\n");
    printf("\n%d\t%s\t%f Dh\t%d/%d/%d\n\n",t[index].codee,t[index].inf.nom,t[index].inf.Total_TTC,t[index].inf.d.jour,t[index].inf.d.mois,t[index].inf.d.annee);
    printf("Le produit avec le chiffre d affaire le plus bas:\n");
    printf("\n%d\t%s\t%f Dh\t%d/%d/%d\n\n",t[index1].codee,t[index1].inf.nom,t[index1].inf.Total_TTC,t[index1].inf.d.jour,t[index1].inf.d.mois,t[index1].inf.d.annee);
}


void stats_achats(){

    float chiffre_affaire_ach = 0;
    time_t h2 = time(NULL);
    struct tm tm = *localtime(&h2);
    //La somme des ventes journaliers
    for(i=0; i<compteur1; i++){
        if(a[i].info.dt.jour==tm.tm_mday && a[i].info.dt.mois==tm.tm_mon + 1 && (a[i].info.dt.annee==tm.tm_year + 1900)){
            chiffre_affaire_ach += a[i].info.Total;}
    }
    //La moyenne des ventes
    float moyenne_ach;
    moyenne_ach = chiffre_affaire_ach/compteur1;

    float max_ach;
    int index;
    max_ach= a[0].info.Total;
    for (int i=1 ; i<compteur1 ; i++){
        if(a[i].info.dt.jour==tm.tm_mday && a[i].info.dt.mois==tm.tm_mon + 1 && a[i].info.dt.annee==tm.tm_year + 1900){
            if(a[i].info.Total>max_ach){
                max_ach=a[i].info.Total;
                index = i;
            }
        }

    }
    float min_ach;
    int index1;
    min_ach=a[0].info.Total;

    for (int i=1 ; i<compteur1 ; i++){
        if(a[i].info.dt.jour==tm.tm_mday && a[i].info.dt.mois==tm.tm_mon + 1 && a[i].info.dt.annee==tm.tm_year + 1900){
            if(a[i].info.Total<min_ach){
                min_ach=a[i].info.Total;
                index1 = i;
            }
        }

    }

    printf("Chiffre d affaire journalier: %f Dh\n\nMoyenne vente journaliere: %f Dh\n\n", chiffre_affaire_ach,moyenne_ach);
    printf("Le produit avec le chiffre d affaire le plus grand:\n");
    printf("\n%d\t%s\t%f Dh\t%d/%d/%d\n\n",a[index].codee,a[index].info.nom,a[index].info.Total,a[index].info.dt.jour,a[index].info.dt.mois,a[index].info.dt.annee);
    printf("Le produit avec le chiffre d affaire le plus bas:\n");
    printf("\n%d\t%s\t%f Dh\t%d/%d/%d\n\n",a[index1].codee,a[index1].info.nom,a[index1].info.Total,a[index1].info.dt.jour,a[index1].info.dt.mois,a[index1].info.dt.annee);
}
void red_bg (){
  printf("\033[1;41m");
}

void yellow_bg(){
  printf("\033[1;33m\n");
}

void cyan_bg(){
  printf("\33[0;36m\n");
}

void reset() {
  printf("\033[0m");
}

///>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
int main () {

    start1:
    cyan_bg();
    printf("|<---------------------------------------------------------------------------------------------------------->|\n"
           "||                          ||       The NOUHI Pharmacy management system        ||                         ||\n"
           "||                          ||  Your application to better manage your pharmacy  ||                         ||\n"
           "|<---------------------------------------------------------------------------------------------------------->|\n\n");
    reset();
    printf("                                 \033[0;36mBienvenue!! Que est ce que vous voulez faire?\033[0m\n\n");
    invalid:
    yellow_bg();
    printf("|<---------------------------------------------------->||<--------------------------------------------------->|\n"
           "|| [1] Ajouter un ou plusieurs produits                || [2] Supprimer un ou plusieurs produits             ||\n"
           "|<---------------------------------------------------->||<--------------------------------------------------->|\n"
           "|| [3] Etat de stock                                   || [4] Gestion des Vente                              ||\n"
           "|<---------------------------------------------------->||<--------------------------------------------------->|\n"
           "|| [5] Gestion des Achat                               || [6] Statistique Ventes/Achats                      ||\n"
           "|<---------------------------------------------------->||<--------------------------------------------------->|\n"
           "||                                            [7] Quitter le program                                         ||\n"
           "|<----------------------------------------------------------------------------------------------------------->|\n");
    reset();
    printf("\n                                         Veuillez saisir votre choix: ");
    scanf("%d",&choix);

    while ((choix < 1 || choix > 7) ||  (sscanf(check, "%d", &choix)==1)){
        fgets(check, 100, stdin);
        system("cls");
        printf("\a\033[0;41mSaisie invalid!!!\033[0m \nVeuillez saisir un choix valid.\n");
        goto invalid;
        }

///#########################################################################################################################################################################
    switch(choix){
///Ajouter un ou plusieurs produits*****************************************************************************************************************************************
        case 1:
            aj:
            system("cls");
            ajoute();
            printf("\n1. Afficher l etat du stock\n2. Retour au menu principale\n"
                   "-------> ");
            scanf("%d",&choix);
            system("cls");
            switch (choix){
                case 1:
                    goto list_des_produit;
                case 2:
                    goto start1;
                    }
///Supprimer un ou plusieurs produits***************************************************************************************************************************************
        case 2:
            supp:
            supprimer();
            printf("\n1. Ajouter un ou plusieurs produits\n2. Supprimer un ou plusieurs produits\n3. Retour au menu principale\n"
                   "-------> ");
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
///Etat du stock************************************************************************************************************************************************************
        case 3: //Ici on donne le choix a l'utilisateur pour choisir sa direction.
            list_des_produit:
            system("cls");
            printf("\n1. Rechercher un produit\n2. Approvisionnement du stock\n3. Afficher la list triee ascendante par nom\n4. Afficher la list triee descendante par prix\n5. Retour au menu principale\n");
            printf("-------> ");
            scanf("%d",&choix);
            system("cls");
            switch (choix){
                //----------------------------------------------------------------------------------------------------------------------------------------------------------
                case 1: //La recherche d'un produit par code ----------------------------------------------------------------------------------------------------------------
                    rech:
                    system("cls");
                    recherche();
                    printf("\n1. Rechercher un autre produit?\n2. Retour au menu principale\n");
                    printf("-------> ");
                    scanf("%d",&choix);
                    system("cls");
                        switch (choix){
                            case 1:
                                goto rech;
                            default:
                                system("cls");
                                goto start1;
                            }
                //---------------------------------------------------------------------------------------------------------------------------------------------------------
                case 2: // l'approvisionnement des produits ---------------------------------------------------------------------------------------------------------------
                    list:
                    system("cls");
                    Approvisionnement();
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
                //---------------------------------------------------------------------------------------------------------------------------------------------------------
                case 3: //L'affichage ascendant des produit par nom -------------------------------------------------------------------------------------------------------
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
                //---------------------------------------------------------------------------------------------------------------------------------------------------------
                case 4: // L'affichage descendant des produit par prix ----------------------------------------------------------------------------------------------------
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
                //---------------------------------------------------------------------------------------------------------------------------------------------------------
                default://Main menu----------------------------------------------------------------------------------------------------------------------------------------
                    goto start1;
                    system("cls");
            }
///Gestion vente*************************************************************************************************************************************************************************
        case 4:
            system("cls");
            printf("\n1. Enregistrer une ou plusieurs operations vente\n2. Afficher le journal des ventes\n3. Retour au menu principale\n");
            printf("-------> ");
            scanf("%d",&choix);
            system("cls");
            switch(choix){
                //----------------------------------------------------------------------------------------------------------------------------------------------------------
                case 1://Enregistrement des ventes--------------------------------------------------------------------------------------------------------------------------
                    ventes:
                    system("cls");
                    Enregistrement_ventes();
                    printf("\n1. Enregistrer une ou plusieurs operations vente\n2. Afficher le journal des ventes\n3. Retour au menu principale\n");
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
                //----------------------------------------------------------------------------------------------------------------------------------------------------------
                case 2://Journal des ventes
                    journal_vte:
                    system("cls");
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
                //----------------------------------------------------------------------------------------------------------------------------------------------------------
                default://Menu principale
                    system("cls");
                    goto start1;
            }
///Gestion achats*************************************************************************************************************************************************************************
        case 5:
            system("cls");
            printf("\n1. Alimenter le stock d un ou plusieurs produit\n2. Afficher le journal des achats\n3. Retour au menu principale\n");
            printf("-------> ");
            scanf("%d",&choix);
            system("cls");
            switch(choix){
                //----------------------------------------------------------------------------------------------------------------------------------------------------------
                case 1://Enregistrement des achats
                    achats:
                    system("cls");
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
                //----------------------------------------------------------------------------------------------------------------------------------------------------------
                case 2://Journal des achats
                    journal_ach:
                    system("cls");
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
                //----------------------------------------------------------------------------------------------------------------------------------------------------------
                default://Menu principale
                    goto start1;
                    system("cls");
            }
///Statistiques des ventes*************************************************************************************************************************************************************************
        case 6:
            system("cls");
            printf("\n1. Statistiques des ventes\n2. Statistiques des achats\n3. Retour au menu principale\n");
            printf("-------> ");
            scanf("%d",&choix);
            system("cls");
            switch(choix){
                case 1:
                    stats_ventes();
                    printf("\n1. Retour au menu principale\n");
                    printf("-------> ");
                    scanf("%d",&choix);
                    system("cls");
                        switch(choix){
                            default:
                                goto start1;
                        }
                case 2:
                    stats_achats();
                    printf("\n1. Retour au menu principale\n");
                    printf("-------> ");
                    scanf("%d",&choix);
                    system("cls");
                        switch(choix){
                            default:
                                goto start1;
                        }

                default:
                    goto start1;

            }
///Quit program*************************************************************************************************************************************************************************
        case 7:
            printf(".....................................................................................\n"
                   "                                  ||  Au revoir  ||                                  \n"
                   ".....................................................................................\n");
            system("exit");
///*************************************************************************************************************************************************************************

///#########################################################################################################################################################################

}
return 0;
}
///>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
