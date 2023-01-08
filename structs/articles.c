#include "headers.h"

int art_code = 0;
article* create_article(){
	char temp[20];
	int choix;
	doc* doc =  create_doc();
	date* d = (date*)malloc(sizeof(date));
	article *p = (article*)malloc(sizeof(article));
	sprintf(doc->code,"art%d",art_code);
	art_code++;
	if(!p||!d||!doc){
		return NULL;
	}
	strcpy(doc->type, "article");

	printf("\ndonnez le nom de l'auteur de l'article");
	while(!scanf(" %[a-zA-Z ]",temp)){
		printf("\nle nom ne doit pas contenir des chiffres ou des caracteres speciaux\n");
		fflush(stdin);
	};
	strcpy(p->auteur,temp);
	printf("\ndonnez la date de publication de l'article (jj/mm/yyyy)");
	while(!scanf("%d/%d/%d",&d->dd,&d->mm,&d->yy)||test_date(d)==-1){
		printf("\ndate invalide , essayez de nouveau\n");
		fflush(stdin);
	};
	p->date_pub = d;
	
	printf("voulez vous sauvegarder l'article ?(oui:1/non:-1)");
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

art_node* create_art_node(article* art){
	art_node* node = (art_node*)malloc(sizeof(art_node));
	if(!node){
		return NULL;
	}
	node->doc = art;
	node->suivant = NULL;
	return node;
}

int create_art_list(){
	art_l = (art_list*)malloc(sizeof(art_list));
	if(art_l==NULL){
		return -1;
	}
	art_l->debut = NULL;

	return 1;
}

int push_art(){
	article* p = create_article();
	art_node* node = create_art_node(p);
	art_node* temp = art_l->debut;

	if(art_l->debut == NULL){
		
		art_l->debut = node;	
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

void affiche_art(){
	art_node* temp= art_l->debut;
	if(art_l->debut==NULL){
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
        printf("\n\t\t\tDate de publication  = (%d/%d/%d)\n",temp->doc->date_pub->dd , temp->doc->date_pub->mm , temp->doc->date_pub->yy);
        printf("\n\t\t\tNombre d'exemplaires = %d\n",temp->doc->doc->nbr_exemplaires);
        printf("\n\t\t\t******************************************************************************");
        
		temp = temp->suivant;
	}
}

article* art_construct(char* single){
	article* art = (article*)malloc(sizeof(article));
	date* datePub= (date*)malloc(sizeof(date));
	doc* ddoc = (doc*)malloc(sizeof(doc));
	art->date_pub = datePub;
	art->doc = ddoc;
	if(art==NULL){
		printf("art_construct a echoué");
		return NULL;
	}
	char delim[] = ":";
	char *ptr = strtok(single,delim);
	strcpy(art->doc->code, ptr);
	ptr = strtok (NULL, delim);
	strcpy (art->doc->titre, ptr);
	ptr = strtok (NULL, delim);
	strcpy(art->doc->type, ptr);
	art->doc->location = atoi(strtok(NULL, delim));
	art->doc->nbr_exemplaires = atoi(strtok (NULL, delim));
	ptr = strtok (NULL, delim);
	strcpy(art->auteur, ptr);
	art->date_pub->dd=atoi(strtok(NULL,delim));
	art->date_pub->mm= atoi(strtok(NULL, delim)); 
	art->date_pub->yy= atoi(strtok (NULL, delim));

	return art;
}


int push_art_inload(article* art){
	if(art==NULL){
		return -1;
	}	
	art_node *p = (art_node*)malloc(sizeof(art_node));
	if(p==NULL){
		return -1;
	}
	
	p->doc= art;

	p->suivant = NULL;
	
	art_node* temp = art_l->debut;
	if(art_l->debut == NULL){
		art_l->debut = p;
		
		return 1;	
	}
		while(temp->suivant!=NULL){
			temp = temp->suivant;
		}
	temp->suivant = p;

	return 1;
}



int saver_arts(){
	FILE *f;
	char buffer[100];
	art_node* temp = art_l->debut;
	int len;
   	f = fopen("arts.dat", "w+");
   	if(f == NULL) {
		perror("erreur dans l'ouverture de fichier");
		return(-1);
   }
	if(temp == NULL){
		printf("\npas d'articles a sauvegarder");
		return 1;
	}
	while(temp!=NULL){
		sprintf(buffer,"%s:%s:%s:%d:%d:%s:%d:%d:%d\n", temp->doc->doc->code, temp->doc->doc->titre, temp->doc->doc->type, temp->doc->doc->location,temp->doc->doc->nbr_exemplaires, temp->doc->auteur,temp->doc->date_pub->dd,temp->doc->date_pub->mm,temp->doc->date_pub->yy);
		fputs(buffer, f);
		fseek(f, 0, SEEK_END);
		temp = temp->suivant;
	}
   len = ftell(f);
   
   fclose(f);
   
   printf("\n%d octets ecrits dans arts.dat", len);
   return 1;
}

int loader_art(){
	FILE *f;
	char buffer[100];
	int len;
   	f = fopen("arts.dat", "r");
   	if(f == NULL) {
		perror("erreur dans l'ouverture de fichier");
		return(-1);
}
   	if(buffer==NULL){
   		printf("erreur de memoire dans loader_art");
	   }
	   while (fgets(buffer, sizeof(buffer),f)) {
        	article* art = art_construct(buffer);
        	push_art_inload(art);
        	art_code++;
    	}
   fclose(f);
   
   return 1;
}
int supprimer_art(char* code){
	art_node* temp = art_l->debut;
	if(strcmp(temp->doc->doc->code,code)==0){
		art_l->debut = temp->suivant;
		free(temp);
		return 1;
	}
	if(temp->suivant==NULL){
		printf("article introuvable :(");
		return -1;
	}
	art_node* pr = temp;
	temp = temp->suivant;

	while(temp!=NULL){
		if(strcmp(temp->doc->doc->code,code)==0){
			pr->suivant = temp->suivant;
			free(temp);
			return 1;
		}

		pr = temp;
		temp = temp->suivant;
	}
	printf("article introuvable :(");
	return -1;
}
void afficher_un_article(article* art){
		printf("\n\t\t\t******************************************************************************");
		printf("\n\t\t\tCode unique          = %s\n",art->doc->code);
        printf("\n\t\t\tTitre                = %s\n",art->doc->titre);
        printf("\n\t\t\tType                 = %s\n",art->doc->type);
        printf("\n\t\t\tLocalisation         = rayon :%d\n",art->doc->location);
        printf("\n\t\t\tAuteur               = %s\n",art->auteur);
       printf("\n\t\t\tDate de publication  = (%d/%d/%d)\n",art->date_pub->dd , art->date_pub->mm , art->date_pub->yy);
        printf("\n\t\t\tNombre d'exemplaires = %d\n",art->doc->nbr_exemplaires);
        printf("\n\t\t\t******************************************************************************");
}

