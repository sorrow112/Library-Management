#include "headers.h"
//TODO: sauvegarder l'id doc somewhere and use it , all ids are 1 now
int liv_code = 0;
livre* create_livre(){
	char temp[20];
	int choix;
	doc* doc =  create_doc();
	date* d = (date*)malloc(sizeof(date));
	livre *p = (livre*)malloc(sizeof(livre));
	if(!p||!d||!doc){
		return NULL;
	}
	strcpy(doc->type, "livre");
	sprintf(doc->code,"liv%d",liv_code);
	liv_code++;
	printf("\ndonnez le nom de l'auteur du livre");
	while(!scanf(" %[a-zA-Z ]",temp)){
		printf("\nle nom ne doit pas contenir des chiffres ou des caracteres speciaux\n");
		fflush(stdin);
	};
	strcpy(p->auteur,temp);
	printf("\ndonnez le nom de l'editeur du livre");
	while(!scanf(" %[a-zA-Z ]",temp)){
		printf("\nle nom ne doit pas contenir des chiffres ou des caracteres speciaux\n");
		fflush(stdin);
	};
	strcpy(p->editeur,temp);
	printf("\ndonnez la date d'edition du livre (jj/mm/yyyy)");
	while(!scanf("%d/%d/%d",&d->dd,&d->mm,&d->yy)||test_date(d)==-1){
		printf("\ndate invalide , essayez de nouveau\n");
		fflush(stdin);
	};
	p->date_edit = d;
	
	printf("voulez vous sauvegarder le livre ?(oui:1/non:-1)");
	if(scanf("%d", &choix)){
		if(choix == 1){	
		p->doc = doc;
		//printf("%s,%s,%s,%s", p->doc->code,p->doc->titre,p->auteur,p->editeur);
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

liv_node* create_liv_node(livre* liv){
	liv_node* node = (liv_node*)malloc(sizeof(liv_node));
	if(!node){
		return NULL;
	}
	node->doc = liv;
	node->suivant = NULL;
	return node;
}

int create_liv_list(){
	liv_l = (liv_list*)malloc(sizeof(liv_list));
	if(!liv_l){
		return -1;
	}
	liv_l->debut = NULL;
	return 1;
}

int push_liv(){
	livre* p = create_livre();
	liv_node* node = create_liv_node(p);
	liv_node* temp = liv_l->debut;
	if(!p||!node){
		return -1;
	}
	if(liv_l->debut == NULL){
		liv_l->debut = node;	
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
void affiche_liv(){
	liv_node* temp= liv_l->debut;
	if(temp==NULL){
		printf("\nliste vide");
		return;
	}
	while(temp!=NULL){
		printf("\n\t\t\t******************************************************************************");
		printf("\n\t\t\tCode unique          = %s\n",temp->doc->doc->code);
        printf("\n\t\t\tTitre                = %s\n",temp->doc->doc->titre);
        printf("\n\t\t\tType                 = %s\n",temp->doc->doc->type);
        printf("\n\t\t\tLocalisation         = rayon :%d\n",temp->doc->doc->location);
        printf("\n\t\t\tAuteur               = %s\n",temp->doc->auteur);
        printf("\n\t\t\tEditeur              = %s\n",temp->doc->editeur);
        printf("\n\t\t\tDate d'edition       = (%d/%d/%d)\n",temp->doc->date_edit->dd,temp->doc->date_edit->mm,temp->doc->date_edit->yy);
        printf("\n\t\t\tNombre d'exemplaires = %d\n",temp->doc->doc->nbr_exemplaires);
        printf("\n\t\t\t******************************************************************************");
		temp = temp->suivant;
	}
}

livre* liv_construct(char* single){
	livre* liv = (livre*)malloc(sizeof(livre));
	date* dateEdit= (date*)malloc(sizeof(date));
doc* ddoc = (doc*)malloc(sizeof(doc));
liv->doc = ddoc;
	liv->date_edit = dateEdit;
	if(liv==NULL){
		printf("liv_construct failed");
		return NULL;
	}
	char delim[] = ":";
	char *ptr = strtok(single,delim);
	strcpy (liv->doc->code, ptr);
	ptr = strtok (NULL, delim);
	strcpy (liv->doc->titre, ptr);
	ptr = strtok (NULL, delim);
	strcpy(liv->doc->type, ptr);
	liv->doc->location = atoi(strtok(NULL, delim));
	liv->doc->nbr_exemplaires = atoi(strtok (NULL, delim));
	ptr = strtok (NULL, delim);
	strcpy(liv->auteur, ptr);
	ptr = strtok (NULL, delim);
	strcpy(liv->editeur, ptr);
	liv->date_edit->dd=atoi(strtok(NULL,delim));
	liv->date_edit->mm= atoi(strtok(NULL, delim)); 
	liv->date_edit->yy= atoi(strtok (NULL, delim));

	return liv;
}


int push_liv_inload(livre* liv){
	if(!liv){
		return -1;
	}	
	liv_node *p = (liv_node*)malloc(sizeof(liv_node));
	if(!p){
		return -1;
	}
	
	p->doc= liv;
	p->suivant = NULL;
	
	liv_node* temp = liv_l->debut;
	if(liv_l->debut == NULL){
		liv_l->debut = p;
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



int saver_livs(){
	FILE *f;
	char buffer[100];
	liv_node* temp = liv_l->debut;
	int len;
   	f = fopen("livs.dat", "w+");
   	if(f == NULL) {
		perror("erreur dans l'ouverture de fichier");
		return(-1);
   }
	if(temp == NULL){
		printf("\npas de livres a sauvegarder sauvegarder");
		return 1;
	}
	while(temp!=NULL){
		sprintf(buffer,"%s:%s:%s:%d:%d:%s:%s:%d:%d:%d\n", temp->doc->doc->code, temp->doc->doc->titre, temp->doc->doc->type, temp->doc->doc->location,temp->doc->doc->nbr_exemplaires, temp->doc->auteur,temp->doc->editeur,temp->doc->date_edit->dd,temp->doc->date_edit->mm,temp->doc->date_edit->yy);
		fputs(buffer, f);
		fseek(f, 0, SEEK_END);
		temp = temp->suivant;
	}
   len = ftell(f);
   
   fclose(f);
   
   printf("\n%d bytes written to livs.dat", len);
   return 1;
}

int loader_liv(){
	FILE *f;
	char buffer[100];
	int len;
   	f = fopen("livs.dat", "r");
   	if(f == NULL) {
		perror("erreur dans l'ouverture de fichier");
		return(-1);
}
   	if(buffer==NULL){
   		printf("no memory");
	   }
	   while (fgets(buffer, sizeof(buffer),f)) {
           livre* liv = liv_construct(buffer);
           push_liv_inload(liv);
           liv_code++;
    	}
   fclose(f);
   
   return 1;
}
int supprimer_liv(char* code){
	liv_node* temp = liv_l->debut;
	if(strcmp(temp->doc->doc->code,code)==0){
		liv_l->debut = temp->suivant;
		free(temp);
		return 1;
	}
	if(temp->suivant==NULL){
		printf("livre introuvable :(");
		return -1;
	}
	liv_node* pr = temp;
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
	printf("livre introuvable :(");
	return -1;
}
void afficher_un_liv(livre* liv){
		printf("\n\t\t\t******************************************************************************");
		printf("\n\t\t\tCode unique          = %s\n",liv->doc->code);
        printf("\n\t\t\tTitre                = %s\n",liv->doc->titre);
        printf("\n\t\t\tType                 = %s\n",liv->doc->type);
        printf("\n\t\t\tLocalisation         = rayon :%d\n",liv->doc->location);
        printf("\n\t\t\tAuteur               = %s\n",liv->auteur);
        printf("\n\t\t\tEditeur              = %s\n",liv->editeur);
        printf("\n\t\t\tDate d'edition       = (%d/%d/%d)\n",liv->date_edit->dd,liv->date_edit->mm,liv->date_edit->yy);
        printf("\n\t\t\tNombre d'exemplaires = %d\n",liv->doc->nbr_exemplaires);
        printf("\n\t\t\t******************************************************************************");
}

