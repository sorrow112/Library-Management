
#include "headers.h"

int adh_id=1;
adherent* create_adh(){
	int choix;
	char temp[20];
	adherent *p = (adherent*)malloc(sizeof(adherent));
	if(!p){
		return NULL;
	}
	//strcpy(p->id,id);
	printf("l'ajout d'un edherant");
	printf("\ndonnez le nom de l'adherant");
	sprintf(p->id,"%d",adh_id);
	adh_id++;
	while(!scanf(" %[a-zA-Z ]",temp)){
		printf("\nle nom ne doit pas contenir des chiffres ou caracteres speciaux\n");
		fflush(stdin);
	};
	strcpy(p->nom, temp);
	printf("\ndonnez le prenom de l'adherant");
	while(!scanf(" %[a-zA-Z ]",temp)){
		printf("\nle prenom ne doit pas contenir des chiffres ou caracteres speciaux\n");
		fflush(stdin);
	};
	strcpy(p->prenom, temp);
	p->nbr_encours =0;
	p->retard = 0;
	printf("\ndonnez l'adresse de l'adherant\n");
	scanf(" %[A-Za-z0-9 ]", temp);
	strcpy(p->adresse, temp);
	/* TODO (#1#): infinite loop when you scan caracs fix it */
	do{
		printf("\nchoisissez le type de l'adherant par saisir\n1 pour etudiant\n2 pour enseignant\n3 pour visiteur\n");
		while(!scanf("%d",&choix)){
			fflush(stdin);
			printf("\nentré invalide , essayez de nouveau svp\n");
			printf("\nchoisissez le type de l'adherant par saisir\n1 pour etudiant\n2 pour enseignant\n3 pour visiteur\n");
		}
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
		return p;
		}	
		else{
			free(p);
			return NULL;
		}
	}
	else{
		fflush(stdin);
		free(p);
		return NULL;
	}
};

adh_node* create_adh_node(){
	adherent *adh = create_adh();
	if(!adh){
		return NULL;
	}	
	adh_node *node = (adh_node*)malloc(sizeof(adh_node));
	if(!node){
		return NULL;
	}
	node->adh = adh;
	node->suivant = NULL;
	return node;
}
int create_adh_list(){
	adh_l = malloc(sizeof(adh_list*));
	if (!adh_l) {
   		return -1;
  	}
  	adh_l->debut = NULL;
  	return 1;
}



 //takes a list and an element
int push_adh(){
	adh_node* p = create_adh_node();
	adh_node* temp = adh_l->debut;
	if(!p){
		return -1;
	}
	if(adh_l->debut == NULL){
		adh_l->debut = p;
		return 1;	
	}
	else{
		while(temp->suivant!=NULL){
			temp = temp->suivant;
		}
	temp->suivant = p;
	}
	return 1;
}

void afficher_adh(){
	adh_node* temp = adh_l->debut;
	printf("\n\n");
	
	if(temp == NULL){
		printf("\nliste vide");
		return;
	}
	
	while(temp!=NULL){

		printf("\n\t\t\t******************************************************************************");
		printf("\n\t\t\tId                     = %s\n", temp->adh->id);
        printf("\n\t\t\tNom                    = %s\n", temp->adh->nom);
        printf("\n\t\t\tPrenom                 = %s\n", temp->adh->prenom);
        printf("\n\t\t\tType                   = %s\n", temp->adh->type);
        printf("\n\t\t\tAdresse                = %s\n", temp->adh->adresse);
        printf("\n\t\t\tRetardaire?(1/0)       = %d\n",temp->adh->retard);
        printf("\n\t\t\tNombre d'emps en cours = %d\n",temp->adh->nbr_encours);
        printf("\n\t\t\t******************************************************************************");

		temp = temp->suivant;
	}
	
}


adherent* recherche_adh(char* id){
	adh_node* temp = adh_l->debut;
	if(temp==NULL){
		return NULL;
	}
	while(temp!=NULL){
		if(strcmp(temp->adh->id,id)==0){	
			return temp->adh;	
		}
		temp= temp->suivant;
	}
	return NULL;
}
int recherche_adh_nom(char* nom){
	adh_node* temp = adh_l->debut;
	if(temp==NULL){
		return 0;
	}
	while(temp!=NULL){
		if(strcmp(temp->adh->nom,nom)==0){	
			afficher_un_adh(temp->adh);	
		}
		temp= temp->suivant;
	}
	return 1;
}
int recherche_adh_prenom(char* prenom){
	adh_node* temp = adh_l->debut;
	if(temp==NULL){
		return 0;
	}
	while(temp!=NULL){
		if(strcmp(temp->adh->prenom,prenom)==0){	
			afficher_un_adh(temp->adh);	
		}
		temp= temp->suivant;
	}
	return 1;
}

	
adherent* adh_construct(char* single){
	adherent* adh = (adherent*)malloc(sizeof(adherent));
	if(adh==NULL){
		printf("adh_construct a echouee");
		return NULL;
	}
	char delim[] = ":";
	char *ptr = strtok(single,delim);
	strcpy(adh->id,ptr);
	ptr = strtok(NULL,delim);
	strcpy(adh->nom,ptr);
	ptr = strtok(NULL,delim);
	strcpy(adh->prenom, ptr);
	ptr = strtok(NULL,delim);
	strcpy(adh->adresse, ptr);
	ptr = strtok(NULL,delim);
	strcpy(adh->type, ptr);
	adh->retard = atoi(strtok(NULL,delim));
	adh->nbr_encours = atoi(strtok(NULL,delim));
	return adh;
}


int push_adh_inload(adherent* adh){
	if(!adh){
		return -1;
	}	
	adh_node *p = (adh_node*)malloc(sizeof(adh_node));
	if(!p){
		return -1;
	}
	p->adh = adh;
	p->suivant = NULL;
	
	adh_node* temp = adh_l->debut;
	if(!p){
		return -1;
	}
	if(adh_l->debut == NULL){
		adh_l->debut = p;
		return 1;	
	}
	else{
		while(temp->suivant!=NULL){
			temp = temp->suivant;
		}
	temp->suivant = p;
	}
	return 1;
}



int saver_adhs(){
	FILE *f;
	char buffer[100];
	adh_node* temp = adh_l->debut;
	int len;
   	f = fopen("adhs.dat", "w+");
   	if(f == NULL) {
		perror("erreur dans l'ouverture de fichier");
		return(-1);
   }
	if(temp == NULL){
		printf("\npas d'adherent a sauvegarder");
		return 1;
	}
	while(temp!=NULL){
		sprintf(buffer,"%s:%s:%s:%s:%s:%d:%d\n", temp->adh->id, temp->adh->nom, temp->adh->prenom, temp->adh->adresse,temp->adh->type,temp->adh->retard,temp->adh->nbr_encours);
		fputs(buffer, f);
		fseek(f, 0, SEEK_END);
		temp = temp->suivant;
	}
   len = ftell(f);
   
   fclose(f);
   
   printf("\n%d octets ecrit dans adh.dat", len);
   return 1;
}

int loader_adh(){
	FILE *f;
	char buffer[100];
	int len;
	int i=0;
   	f = fopen("adhs.DAT", "r");
   	if(f == NULL) {
		perror("erreur dans l'ouverture de fichier");
		return(-1);
	}
   	if(buffer==NULL){
   		printf("errer de memoire dans loader_adh");
	   }
	   while (fgets(buffer, sizeof(buffer),f)) {
           adherent* adh = adh_construct(buffer);
           push_adh_inload(adh);
        	adh_id++;
    	}
   fclose(f);
   
	
   return 1;
}

int supprimer_adh(char* id){
	adh_node* temp = adh_l->debut;
	if(strcmp(temp->adh->id,id)==0){
		adh_l->debut = temp->suivant;
		free(temp);
		return 1;
	}
	if(temp->suivant==NULL){
		printf("adh introuvable");
		return -1;
	}
	adh_node* pr = temp;
	temp = temp->suivant;
	while(temp!=NULL){
		if(strcmp(temp->adh->id,id)==0){
			
			pr->suivant = temp->suivant;
			free(temp);
		return 1;
		}
		pr = temp;
		temp = temp->suivant;
	}
	
	printf("adh introuvable :(");
	return -1;
}

void afficher_un_adh(adherent* adh){
	printf("\n\t\t\t******************************************************************************");
		printf("\n\t\t\tId                     = %s\n", adh->id);
        printf("\n\t\t\tNom                    = %s\n", adh->nom);
        printf("\n\t\t\tPrenom                 = %s\n", adh->prenom);
        printf("\n\t\t\tType                   = %s\n", adh->type);
        printf("\n\t\t\tAdresse                = %s\n",adh->adresse);
        printf("\n\t\t\tRetardaire?(1/0)       = %d\n",adh->retard);
        printf("\n\t\t\tNombre d'emps en cours = %d\n",adh->nbr_encours);
        printf("\n\t\t\t******************************************************************************");
}

int resolver(adherent* adh){
	adh->retard = 0;
}


