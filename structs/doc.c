
#include "headers.h"


int code_doc = 1;
doc* create_doc(){
	int choix;
	char temp[20];
	doc *p = (doc*)malloc(sizeof(doc));
	if(!p){
		return NULL;
	}
	printf("l'ajout d'un document");
	printf("\ndonnez le titre du document");
	while(!scanf(" %[a-zA-Z0-9 ]",temp)){
		printf("\nle nom ne doit pas contenir des caracteres speciaux\n");
		fflush(stdin);
	};
	strcpy(p->titre, temp);
	sprintf(p->code,"%d",code_doc);
	printf("\ndonnez la location de document (numero de rayon)");
	while(!scanf("%d",&p->location)){
		printf("\nentrez un numero de rayon valide\n");
		fflush(stdin);
	};
	printf("\ndonnez le nombre d'exemplaires qu'on possede");
	while(!scanf("%d",&p->nbr_exemplaires)){
		printf("\nentrez un entier svp\n");
		fflush(stdin);
	};
	return p;

};

doc* recherche_doc(char* code){
}
article* recherche_article(char* code){
	art_node* temp = art_l->debut;
	if(temp==NULL){
		return NULL;
	}
	while(temp!=NULL){
		if(strcmp(temp->doc->doc->code,code)==0){	
			return temp->doc;	
		}
		temp= temp->suivant;
	}
	return NULL;
} //par id doc
livre* recherche_livre(char* code){
	liv_node* temp = liv_l->debut;
	if(temp==NULL){
		return NULL;
	}
	while(temp!=NULL){
		if(strcmp(temp->doc->doc->code,code)==0){	
			return temp->doc;	
		}
		temp= temp->suivant;
	}
	return NULL;
} //par id doc
magazine* recherche_magazine(char* code){
	mag_node* temp = mag_l->debut;
	if(temp==NULL){
		return NULL;
	}
	while(temp!=NULL){
		if(strcmp(temp->doc->doc->code,code)==0){	
			return temp->doc;	
		}
		temp= temp->suivant;
	}
	return NULL;
} //par id doc


int recherche_magazine_titre(char* titre){
	mag_node* temp = mag_l->debut;
	if(temp==NULL){
		return 0;
	}
	while(temp!=NULL){
		if(strcmp(temp->doc->doc->titre,titre)==0){	
			afficher_un_mag(temp->doc);	
		}
		temp= temp->suivant;
	}
	return 1;
}

int recherche_livre_titre(char* titre){
	liv_node* temp = liv_l->debut;
	if(temp==NULL){
		return 0;
	}
	while(temp!=NULL){
		if(strcmp(temp->doc->doc->titre,titre)==0){	
			afficher_un_liv(temp->doc);	
		}
		temp= temp->suivant;
	}
	return 1;
} 

int recherche_article_titre(char* titre){
	art_node* temp = art_l->debut;
	if(temp==NULL){
		return 0;
	}
	while(temp!=NULL){
		if(strcmp(temp->doc->doc->titre,titre)==0){	
			afficher_un_article(temp->doc);	
		}
		temp= temp->suivant;
	}
	return 1;
}

int recherche_article_auteur(char* auteur){
	art_node* temp = art_l->debut;
	if(temp==NULL){
		return 0;
	}
	while(temp!=NULL){
		if(strcmp(temp->doc->auteur,auteur)==0){	
			afficher_un_article(temp->doc);	
		}
		temp= temp->suivant;
	}
	return 1;
}
int recherche_livre_auteur(char* auteur){
	liv_node* temp = liv_l->debut;
	if(temp==NULL){
		return 0;
	}
	while(temp!=NULL){
		if(strcmp(temp->doc->auteur,auteur)==0){	
			afficher_un_liv(temp->doc);	
		}
		temp= temp->suivant;
	}
	return 1;
} 
int recherche_livre_editeur(char* editeur){
	liv_node* temp = liv_l->debut;
	if(temp==NULL){
		return 0;
	}
	while(temp!=NULL){
		if(strcmp(temp->doc->editeur,editeur)==0){	
			afficher_un_liv(temp->doc);	
		}
		temp= temp->suivant;
	}
	return 1;
} 


