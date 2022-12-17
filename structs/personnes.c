
#include "headers.h"

adherent* create_adh(char* id){
	int choix;
	char temp[20];
	adherent *p = (adherent*)malloc(sizeof(adherent));
	printf("l'ajout d'un edherant");
	printf("\ndonnez le nom de l'adherant");
	while(!scanf(" %[a-zA-Z]",temp)){
		printf("\nle nom ne doit pas contenir des chiffres ou caracteres speciaux\n");
		fflush(stdin);
	};
	strcpy(p->nom, temp);
	printf("\ndonnez le prenom de l'adherant");
	while(!scanf(" %[a-zA-Z]",temp)){
		printf("\nle prenom ne doit pas contenir des chiffres ou caracteres speciaux\n");
		fflush(stdin);
	};
	strcpy(p->prenom, temp);
	printf("\ndonnez l'adresse de l'adherant\n");
	scanf(" %s", temp);
	strcpy(p->adresse, temp);
	do{
		printf("\nchoisissez le type de l'adherant par saisir\n1 pour etudiant\n2 pour enseignant\n3 pour visiteur\n");
		scanf("%d",&choix);
		switch(choix){
			case 1:
				strcpy(p->type, "etudiant");
				break;
			case 2:
				strcpy(p->type, "enseignant");
				break;
			case 3:
				strcpy(p->type, "visiteur");
				break;
	}
	}while(choix!=1 && choix!=2 && choix!=3);
	printf("voulez vous sauvegarder l'adherant ?(oui:1/non:-1)");
	if(scanf("%d", &choix)){
		if(choix == 1){
		sprintf(p->id, "%d", id);
		return p;
		}	
		else{
			free(p);
			return NULL;
		}
	}
	else{
		free(p);
		return NULL;
	}
};

adh_node* create_adh_node(char* id){
	adherent *adh = create_adh(id);
	adh_node *node = (adh_node*)malloc(sizeof(adh_node));
	node->adh = adh;
	node->suivant = NULL;
	return node;
}



 //takes a list and an element
void push_into_adh_list(adh_node* head, adh_node* newNode){
	newNode->suivant = head;
	head->suivant = newNode;
}
//TODO: make this work properly
void afficher_adh(adh_node* head){
	adh_node* temp = head;
	printf("\n\n");
	
	if(temp == NULL){
		printf("\nliste vide");
		return;
	}
	
	while(temp!=NULL){
		printf("{");
		printf("%s", temp->adh->nom);
		printf("}");
		temp = temp->suivant;
	}
	
}
 //takes a list and an element
int nbr_emps_par_adh_ec();//nbr emps en cours
int nbr_emps_par_adh_tt();//nbr emps total
int nbr_emps_par_adh_ec();//nbr emps dépassées

