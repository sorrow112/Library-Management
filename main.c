#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "structs/headers.h"

int leave = 0;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int preparation(){
	if(create_adh_list()==-1){
		printf("adh_list failed");
	}
	if(create_liv_list()==-1){
		printf("liv_list failed");
	}
	if(create_mag_list()==-1){
		printf("mag_list failed");
	}
	if(create_emp_list()==-1){
		printf("emp_list failed");
	}
	if(create_art_list()==-1){
		printf("art_list failed");
	}
}
void loader_all(){
	loader_adh();
	loader_emp();
	loader_liv();
	loader_mag();
	loader_art();
	printf("\nload complet\n\n");
}
void saver_all(){
	saver_adhs();
	
	saver_emps();
	saver_livs();
	saver_mags();
	saver_arts();
	printf("\nsave complet\n\n");
}
int menu_principale();
void menu_gerer_adh();
void menu_gerer_docs();
void menu_mod_document();
void menu_rech_document();
void menu_sup_document();
void menu_ajout_document();
void menu_aff_document();
void menu_gerer_emps();

int main(int argc, char *argv[]) {
	preparation();
	loader_all();
		printf("\n\t\t\t  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
    	printf("\n\t\t\t  +      ++++++++++++++++++++++++++++++++++++++++++++++++      +");
    	printf("\n\t\t\t  +      +                                              +      +");
    	printf("\n\t\t\t  +      +                                              +      +");
    	printf("\n\t\t\t  +      +          Bienvenue a votre logicel           +      +");
    	printf("\n\t\t\t  +      +         de gestion de bibliotheque           +      +");
    	printf("\n\t\t\t  +      +                                              +      +");
    	printf("\n\t\t\t  +      +                                              +      +");
    	printf("\n\t\t\t  +      ++++++++++++++++++++++++++++++++++++++++++++++++      +");
    	printf("\n\t\t\t  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    	printf("\n\t\t\t  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    	while(leave==0){
    		    	menu_principale();
		}

	saver_all();
	return 0;
}

void menu_gerer_adh(){
	int choice =0;
	char inp[10];
	printf("\n");
	do{
		fflush(stdin);
	printf("\n\t\t\t\t MENU\n\t\t\t\t ______________________________________________");
    printf("\n\t\t\t\t| [1] AJOUTER ADHERENT                                        |");
    printf("\n\t\t\t\t| ____________________________________________________________|");
    printf("\n\t\t\t\t| [2] SUPPRIMER ADHERENT                                      |");
    printf("\n\t\t\t\t| ____________________________________________________________|");
    printf("\n\t\t\t\t| [3] MODIFIER ADHERENT                                       |");
    printf("\n\t\t\t\t| ____________________________________________________________|");
    printf("\n\t\t\t\t| [4] AFFICHER ADHERENTS                                      |");
    printf("\n\t\t\t\t| ____________________________________________________________|");
    printf("\n\t\t\t\t| [5] RECHERCHER ADHERENT PAR ID                              |");
    printf("\n\t\t\t\t| ____________________________________________________________|");
    printf("\n\t\t\t\t| [6] RECHERCHER ADHERENT PAR NOM                             |");
    printf("\n\t\t\t\t| ____________________________________________________________|");
    printf("\n\t\t\t\t| [7] RECHERCHER ADHERENT PAR PRENOM                          |");
    printf("\n\t\t\t\t| ____________________________________________________________|");
    printf("\n\t\t\t\t| [8] RENDRE PAS RETARDAIRE                                   |");
    printf("\n\t\t\t\t| ____________________________________________________________|");
    printf("\n\t\t\t\t| [9] RETOURNER AU MENU PRINCIPAL                             |");
    printf("\n\t\t\t\t|_____________________________________________________________|\n");
	}while(!scanf("%d",&choice)||choice<1||choice>9);
    switch(choice){
    	case 1:{
    		push_adh();
			break;
		}
		case 2:{
			printf("\ndonnez l'identifiant de l'adherent a supprimer\n");
			scanf(" %s",inp);
			supprimer_adh(inp);
			break;
		}
		case 3:{
			printf("\nfonctionalité pas developé encore\n");
			//todo
			break;
		}
		case 4:{
			afficher_adh();
			break;
		}
		case 5:{
			printf("\ndonnez l'identifiant de l'adherent a rechercher\n");
			scanf(" %s",inp);
			adherent* adh = recherche_adh(inp);
			afficher_un_adh(adh);
			break;
		}
		case 6:{
			printf("\ndonnez le nom de l'adherent a rechercher\n");
			scanf(" %[^\n]",inp);
			recherche_adh_nom(inp);
			break;
		}
		case 7:{
			printf("\ndonnez le prenom de l'adherent a rechercher\n");
			scanf(" %[^\n]",inp);
			recherche_adh_prenom(inp);
			break;
		}
		case 8:{
			printf("\ndonnez l'identifiant de l'adherent rendre pas retardaire\n");
			scanf(" %s",inp);
			adherent* adh = recherche_adh(inp);
			resolver(adh);
			break;
		}
		case 9:{
			printf("\n\n\n");
			menu_principale();
			break;
		}
	}
	menu_principale();
}
void menu_gerer_docs(){
	int choice =0;
	printf("\n");
	do{
		fflush(stdin);
	printf("\n\t\t\t\t MENU\n\t\t\t\t ______________________________________________");
    printf("\n\t\t\t\t| [1] AJOUTER UND DOCUMENT                                    |");
    printf("\n\t\t\t\t| ____________________________________________________________|");
    printf("\n\t\t\t\t| [2] SUPPRIMER UN DOCUMENT                                   |");
    printf("\n\t\t\t\t| ____________________________________________________________|");
    printf("\n\t\t\t\t| [3] MODIFIER UN DOCUMENT                                    |");
    printf("\n\t\t\t\t| ____________________________________________________________|");
    printf("\n\t\t\t\t| [4] AFFICHER DES DOCUMENTS                                  |");
    printf("\n\t\t\t\t| ____________________________________________________________|");
    printf("\n\t\t\t\t| [5] RETCHERCHER UN DOCUMENT                                 |");
    printf("\n\t\t\t\t| ____________________________________________________________|");
    printf("\n\t\t\t\t| [6] RETOURNER AU MENU PRINCIPAL                             |");
    printf("\n\t\t\t\t|_____________________________________________________________|\n");
	}while(!scanf("%d",&choice)||choice<1||choice>6);
    switch(choice){
    	case 1:{
    		menu_ajout_document();
			break;
		}
		case 2:{
			menu_sup_document();
			break;
		}
		case 3:{
			printf("\nfonctionalité pas developé encore\n");
			//menu_mod_document();
			break;
		}
		case 4:{
			menu_aff_document();
			break;
		}
		case 5:{
			menu_rech_document();
			break;
		}
		case 6:{
			printf("\n\n\n");
			menu_principale();
		}
	}
	menu_principale();
}
void menu_aff_document(){
	int choice =0;
	printf("\n");
	do{
		fflush(stdin);
	printf("\n\t\t\t\t MENU\n\t\t\t\t ______________________________________________");
    printf("\n\t\t\t\t| [1] AFFICHER UN ARTICLE                                     |");
    printf("\n\t\t\t\t| ____________________________________________________________|");
    printf("\n\t\t\t\t| [2] AFFICHER UN LIVRE                                       |");
    printf("\n\t\t\t\t| ____________________________________________________________|");
    printf("\n\t\t\t\t| [3] AFFICHER UNE MAGAZINE                                   |");
    printf("\n\t\t\t\t| ____________________________________________________________|");
    printf("\n\t\t\t\t| [4] RETOURNER AU MENU PRINCIPAL                             |");
    printf("\n\t\t\t\t|_____________________________________________________________|\n");
	}while(!scanf("%d",&choice)||choice<1||choice>4);
    switch(choice){
    	case 1:{
    		affiche_art();
			break;
		}
		case 2:{
			affiche_liv();
			break;
		}
		case 3:{
			affiche_mag();
			break;
		}
		case 4:{
			printf("\n\n\n");
			menu_principale();
		}
	}
	menu_principale();
}
void menu_ajout_document(){
	int choice =0;
	printf("\n");
	do{
		fflush(stdin);
	printf("\n\t\t\t\t MENU\n\t\t\t\t ______________________________________________");
    printf("\n\t\t\t\t| [1] AJOUTER UN ARTICLE                                        |");
    printf("\n\t\t\t\t| ____________________________________________________________|");
    printf("\n\t\t\t\t| [2] AJOUTER UN LIVRE                                      |");
    printf("\n\t\t\t\t| ____________________________________________________________|");
    printf("\n\t\t\t\t| [3] AJOUTER UNE MAGAZINE                                       |");
    printf("\n\t\t\t\t| ____________________________________________________________|");
    printf("\n\t\t\t\t| [4] RETOURNER AU MENU PRINCIPAL                             |");
    printf("\n\t\t\t\t|_____________________________________________________________|\n");
	}while(!scanf("%d",&choice)||choice<1||choice>4);
    switch(choice){
    	case 1:{
    		push_art();
			break;
		}
		case 2:{
			push_liv();
			break;
		}
		case 3:{
			push_mag();
			break;
		}
		case 4:{
			printf("\n\n\n");
			menu_principale();
		}
	}
	menu_principale();
}
void menu_sup_document(){
	int choice =0;
	char inp[10];
	printf("\n");
	do{
		fflush(stdin);
	printf("\n\t\t\t\t MENU\n\t\t\t\t ______________________________________________");
    printf("\n\t\t\t\t| [1] SUPPRIMER UN ARTICLE                                    |");
    printf("\n\t\t\t\t| ____________________________________________________________|");
    printf("\n\t\t\t\t| [2] SUPPRIMER UN LIVRE                                      |");
    printf("\n\t\t\t\t| ____________________________________________________________|");
    printf("\n\t\t\t\t| [3] SUPPRIMER UNE MAGAZINE                                  |");
    printf("\n\t\t\t\t| ____________________________________________________________|");
    printf("\n\t\t\t\t| [4] RETOURNER AU MENU PRINCIPAL                             |");
    printf("\n\t\t\t\t|_____________________________________________________________|\n");
	}while(!scanf("%d",&choice)||choice<1||choice>4);
    switch(choice){
    	case 1:{
    	printf("\ndonnez le code d'article a supprimer\n");
			scanf(" %s",inp);
			supprimer_art(inp);
			break;
		}
		case 2:{
			printf("\ndonnez le code de livre a supprimer\n");
			scanf(" %s",inp);
			supprimer_liv(inp);
			break;
		}
		case 3:{
			printf("\ndonnez le code de magazine a supprimer\n");
			scanf(" %s",inp);
			supprimer_mag(inp);
			break;
		}
		case 4:{
			printf("\n\n\n");
			menu_principale();
			break;
		}
	}
	menu_principale();
}
void menu_mod_document(){
	int choice =0;
	printf("\n");
	do{
		fflush(stdin);
	printf("\n\t\t\t\t MENU\n\t\t\t\t ______________________________________________");
    printf("\n\t\t\t\t| [1] MODIFIER UN ARTICLE                                     |");
    printf("\n\t\t\t\t| ____________________________________________________________|");
    printf("\n\t\t\t\t| [2] MODIFIER UN LIVRE                                       |");
    printf("\n\t\t\t\t| ____________________________________________________________|");
    printf("\n\t\t\t\t| [3] MODIFIER UNE MAGAZINE                                   |");
    printf("\n\t\t\t\t| ____________________________________________________________|");
    printf("\n\t\t\t\t| [4] RETOURNER AU MENU PRINCIPAL                             |");
    printf("\n\t\t\t\t|_____________________________________________________________|\n");
	}while(!scanf("%d",&choice)||choice<1||choice>4);
    switch(choice){
    	case 1:{
    		//todo
			break;
		}
		case 2:{
			//todo
			break;
		}
		case 3:{
			//todo
			break;
		}
		case 4:{
			printf("\n\n\n");
			menu_principale();
			break;
		}
	}
	menu_principale();
}
void menu_rech_document(){
	int choice =0;
	char inp[10];
	printf("\n");
	do{
		fflush(stdin);
	printf("\n\t\t\t\t MENU\n\t\t\t\t ______________________________________________");
    printf("\n\t\t\t\t| [1] RECHERCHER UN ARTICLE PAR CODE                          |");
    printf("\n\t\t\t\t| ____________________________________________________________|");
    printf("\n\t\t\t\t| [2] RECHERCHER UN ARTICLE PAR AUTEUR                        |");
    printf("\n\t\t\t\t| ____________________________________________________________|");
    printf("\n\t\t\t\t| [3] RECHERCHER UN ARTICLE PAR TITRE                         |");
    printf("\n\t\t\t\t| ____________________________________________________________|");
    printf("\n\t\t\t\t| [4] RECHERCHER UN LIVRE PAR CODE                            |");
    printf("\n\t\t\t\t| ____________________________________________________________|");
    printf("\n\t\t\t\t| [5] RECHERCHER UN LIVRE PAR TITRE                           |");
    printf("\n\t\t\t\t| ____________________________________________________________|");
    printf("\n\t\t\t\t| [6] RECHERCHER UN LIVRE PAR AUTEUR                          |");
    printf("\n\t\t\t\t| ____________________________________________________________|");
    printf("\n\t\t\t\t| [7] RECHERCHER UN LIVRE PAR EDITEUR                         |");
    printf("\n\t\t\t\t| ____________________________________________________________|");
    printf("\n\t\t\t\t| [8] RECHERCHER UNE MAGAZINE PAR CODE                        |");
    printf("\n\t\t\t\t| ____________________________________________________________|");
    printf("\n\t\t\t\t| [9] RECHERCHER UNE MAGAZINE PAR TITRE                       |");
    printf("\n\t\t\t\t| ____________________________________________________________|");
    printf("\n\t\t\t\t| [10] RETOURNER AU MENU PRINCIPAL                             |");
    printf("\n\t\t\t\t|_____________________________________________________________|\n");
	}while(!scanf("%d",&choice)||choice<1||choice>10);
    switch(choice){
    	case 1:{
    		printf("\ndonnez le code de l'article que vous cherchez\n");
    		scanf(" %[^\n]",inp);
    		article* art = recherche_article(inp);
    		afficher_un_article(art);
			break;
		}
		case 2:{
    		printf("\ndonnez le nom d'auteur de l'article vous cherchez\n");
    		scanf(" %[^\n]",inp);
    		recherche_article_auteur(inp);
			break;
		}
			case 3:{
    		printf("\ndonnez le titre de l'article vous cherchez\n");
    		scanf(" %[^\n]",inp);
    		recherche_article_titre(inp);
			break;
		}
		case 4:{
			printf("\ndonnez le code du livre que vous cherchez\n");
    		scanf(" %[^\n]",inp);
			livre* liv = recherche_livre(inp);
			afficher_un_liv(liv);
			break;
		}
		case 5:{
			printf("\ndonnez le titre du livre que vous cherchez\n");
    		scanf(" %[^\n]",inp);
			recherche_livre_titre(inp);
			break;
		}
		case 6:{
			printf("\ndonnez le nom d'auteur du livre que vous cherchez\n");
    		scanf(" %[^\n]",inp);
			recherche_livre_auteur(inp);
			break;
		}
		case 7:{
			printf("\ndonnez le nom d'editeur du livre que vous cherchez\n");
    		scanf(" %[^\n]",inp);
			recherche_livre_editeur(inp);
			break;
		}
		case 8:{
			printf("\ndonnez le code du magazine que vous cherchez\n");
    		scanf(" %[^\n]",inp);
			magazine* mag=recherche_magazine(inp);
			afficher_un_mag(mag);
			break;
		}
		case 9:{
			printf("\ndonnez le titre du magazine que vous cherchez\n");
    		scanf(" %[^\n]",inp);
			recherche_magazine_titre(inp);
			break;
		}
		case 10:{
			printf("\n\n\n");
			menu_principale();
			break;
		}
	}
	menu_principale();
}

void menu_gerer_emps(){
	int choice =0;
	char inp[10];
	printf("\n");
	do{
		printf("\n\t\t\t\t MENU\n\t\t\t\t ______________________________________________");
    printf("\n\t\t\t\t| [1] AFFICHER LES EMPRUNTES                                 |");
    printf("\n\t\t\t\t| ___________________________________________________________|");
    printf("\n\t\t\t\t| [2] EMPRUNTER                                              |");
    printf("\n\t\t\t\t| ___________________________________________________________|");
    printf("\n\t\t\t\t| [3] RETOURNER UN EMPRUNTE                                  |");
    printf("\n\t\t\t\t| ___________________________________________________________|");
   	printf("\n\t\t\t\t| [4] RETOURNER AU MENU PRINCIPAL                            |");
    printf("\n\t\t\t\t|____________________________________________________________|\n");
    }while(!scanf("%d",&choice)||choice<1||choice>4);
    switch(choice){
    	case 1:{
			affiche_emp();
			break;
		}
		case 2:{
			push_emp("2");
			break;
		}
		case 3:{
			char code[10];
			int type=5;
			char id[10];
			printf("donnez le code de document a retourner");
			scanf(" %s", code);
			printf("c'est quoi le type de document?\n1 pour article\n2pour livre\n3pour magazine\n");
			while(!scanf("%d",&type)||type<1||type>3){
				printf("donnez un entré valide svp\n");
				fflush(stdin);
			}
			printf("donnez l'id de l'adherent\n");
			scanf(" %s", id);
			retourner(id,code,type);
			break;
		}
		case 4:{
			printf("\n\n\n");
			menu_principale();
			break;
		}
	}
	menu_principale();
}
int menu_principale(){
	int choice =0;
	printf("\n");
	do{
		fflush(stdin);
	printf("\n\t\t\t\t MENU\n\t\t\t\t ______________________________________________");
    printf("\n\t\t\t\t| [1] GERER MES ADHERENT                                     |");
    printf("\n\t\t\t\t| ___________________________________________________________|");
    printf("\n\t\t\t\t| [2] GERER LES DOCUMENT                                     |");
    printf("\n\t\t\t\t| ___________________________________________________________|");
    printf("\n\t\t\t\t| [3] GERER EMPRUNTES                                        |");
    printf("\n\t\t\t\t| ___________________________________________________________|");
    printf("\n\t\t\t\t| [4] QUITTER                                                |");
    printf("\n\t\t\t\t|____________________________________________________________|\n");
}while(!scanf("%d",&choice)||choice<1||choice>4);
switch(choice){
	case 1:{
		menu_gerer_adh();
		break;
	}
	case 2:{
		menu_gerer_docs();
		break;
	}
	case 3:{
		menu_gerer_emps();
		break;
	}
	case 4:{
		leave = 1;
		break;
	}
}
}

