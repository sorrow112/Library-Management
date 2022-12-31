#include "headers.h"

int mag_code=0;
magazine* create_magazine(){
	char temp[20];
	int choix;
	doc* doc =  create_doc();
	magazine *p = (magazine*)malloc(sizeof(magazine));
	if(!p||!doc){
		return NULL;
	}
	strcpy(doc->type, "magazine");
	sprintf(doc->code,"mag%d",mag_code);
	mag_code++;
	printf("\ndonnez la frequence de parution");
	while(!scanf("%d",&p->frequence)){
		printf("\ndonnez un entier svp\n");
		fflush(stdin);
	};
	printf("voulez vous sauvegarder la magazine ?(oui:1/non:-1)");
	if(scanf("%d", &choix)){
		if(choix == 1){	
		p->doc = doc;
		return p;
		}	
		else{
			free(p);
			free(doc);
			return NULL;
		}
	}
	else{
		free(p);
		free(doc);
		return NULL;
	}
	return p;
}

mag_node* create_mag_node(magazine* mag){
	mag_node* node = (mag_node*)malloc(sizeof(mag_node));
	if(!node){
		return NULL;
	}
	node->doc = mag;
	node->suivant = NULL;
	return node;
}

int create_mag_list(){
	mag_l = (mag_list*)malloc(sizeof(mag_list));
	if(!mag_l){
		return -1;
	}
	mag_l->debut = NULL;
	return 1;
}

int push_mag(){
	magazine* p = create_magazine();
	mag_node* node = create_mag_node(p);
	mag_node* temp = mag_l->debut;
	if(!p||!node){
		return -1;
	}
	if(mag_l->debut == NULL){
		mag_l->debut = node;	
		return 1;
	}
	if(!temp){
		return -1;
	}
	else{
		while(temp->suivant!=NULL){
			temp = temp->suivant;
		}
	temp->suivant = node;
	}
	return 1;
}
void affiche_mag(){
	mag_node* temp= mag_l->debut;
	if(temp==NULL){
		printf("\nliste vide");
		return;
	}
	while(temp!=NULL){
		printf("\n\t\t\t******************************************************************************");
		printf("\n\t\t\tCode unique           = %s\n",temp->doc->doc->code);
        printf("\n\t\t\tTitre                 = %s\n",temp->doc->doc->titre);
        printf("\n\t\t\tType                  = %s\n",temp->doc->doc->type);
        printf("\n\t\t\tLocalisation          = rayon :%d\n",temp->doc->doc->location);
        printf("\n\t\t\tFrequence de parution = %d\n",temp->doc->frequence);
        printf("\n\t\t\tNombre d'exemplaires  = %d\n",temp->doc->doc->nbr_exemplaires);
        printf("\n\t\t\t******************************************************************************");
		temp = temp->suivant;

	}
}

magazine* mag_construct(char* single){
	magazine* mag = (magazine*)malloc(sizeof(magazine));
	doc* ddoc = (doc*)malloc(sizeof(doc));
	mag->doc = ddoc;
	if(mag==NULL){
		printf("mag_construct echoué");
		return NULL;
	}
	char delim[] = ":";
	char *ptr = strtok(single,delim);
	strcpy (mag->doc->code, ptr);
	ptr = strtok (NULL, delim);
	strcpy (mag->doc->titre, ptr);
	ptr = strtok (NULL, delim);
	strcpy(mag->doc->type, ptr);
	mag->doc->location = atoi(strtok(NULL, delim));
mag->doc->nbr_exemplaires = atoi(strtok (NULL, delim));
	mag->frequence=atoi(strtok(NULL,delim));
		return mag;
}


int push_mag_inload(magazine* mag){
	if(mag==NULL){
		return -1;
	}	
	mag_node *p = (mag_node*)malloc(sizeof(mag_node));
	if(p==NULL){
		return -1;
	}
	
	p->doc= mag;
	p->suivant = NULL;
	
	mag_node* temp = mag_l->debut;
	if(mag_l->debut == NULL){
		mag_l->debut = p;
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



int saver_mags(){
	FILE *f;
	char buffer[100];
	mag_node* temp = mag_l->debut;
	int len;
   	f = fopen("mags.dat", "w+");
   	if(f == NULL) {
		perror("erreur dans l'ouverture de fichier");
		return(-1);
   }
	if(temp == NULL){
		printf("\npas de magazines a sauvegarder");
		return 1;
	}
	while(temp!=NULL){
		sprintf(buffer,"%s:%s:%s:%d:%d:%d\n", temp->doc->doc->code, temp->doc->doc->titre, temp->doc->doc->type, temp->doc->doc->location,temp->doc->doc->nbr_exemplaires,temp->doc->frequence);
		fputs(buffer, f);
		fseek(f, 0, SEEK_END);
		temp = temp->suivant;
	}
   len = ftell(f);
   
   fclose(f);
   
   printf("\n%d octets ecrits dans mags.dat", len);
   return 1;
}

int loader_mag(){
	FILE *f;
	char buffer[100];
	int len;
   	f = fopen("mags.dat", "r");
   	if(f == NULL) {
		perror("erreur dans l'ouverture de fichier");
		return(-1);
}
   	if(buffer==NULL){
   		printf("erreur de memoire dans loader_mag");
	   }
	   while (fgets(buffer, sizeof(buffer),f)) {
           magazine* mag = mag_construct(buffer);
           push_mag_inload(mag);
           mag_code++;
    	}
   fclose(f);
   
   return 1;
}

int supprimer_mag(char* code){
	mag_node* temp = mag_l->debut;
	if(strcmp(temp->doc->doc->code,code)==0){
		mag_l->debut = temp->suivant;
		free(temp);
		return 1;
	}
	if(temp->suivant==NULL){
		printf("magazine introuvable :(");
		return -1;
	}
	mag_node* pr = temp;
	temp = temp->suivant;

	while(temp->suivant!=NULL){
		if(strcmp(temp->doc->doc->code,code)==0){
			pr->suivant = temp->suivant;
			free(temp);
			return 1;
		}

		pr = temp;
		temp = temp->suivant;
	}
	printf("magazine introuvable :(");
	return -1;
}
void afficher_un_mag(magazine* mag){
		printf("\n\t\t\t******************************************************************************");
		printf("\n\t\t\tCode unique           = %s\n",mag->doc->code);
        printf("\n\t\t\tTitre                 = %s\n",mag->doc->titre);
        printf("\n\t\t\tType                  = %s\n",mag->doc->type);
        printf("\n\t\t\tLocalisation          = rayon :%d\n",mag->doc->location);
        printf("\n\t\t\tFrequence de parution = %d\n",mag->frequence);
        printf("\n\t\t\tNombre d'exemplaires  = %d\n",mag->doc->nbr_exemplaires);
        printf("\n\t\t\t******************************************************************************");
	}
