
#include "headers.h"

//lezem nlawjou bel user bel user les prets

int id_emp=1;
emprunte* create_emp(char* code, char* id_adh,char* id){
	
	emprunte* emp = (emprunte*)malloc(sizeof(emprunte));

	printf("l'ajout d'un emprunte");	
	strcpy(emp->doc, code);
	strcpy(emp->id_adh, id_adh);
	emp->returned = 0;
	emp->depasse = 0;
	//add id
	sprintf(emp->id ,"%d", id_emp);
	id_emp++;
	return emp;
}

emp_node* create_emp_node(emprunte* emp){
	emp_node* node = (emp_node*)malloc(sizeof(emp_node));
	if(!node){
		return NULL;
	}
	node->emp = emp;
	node->suivant= NULL;
}

int create_emp_list(){
	emp_l = (emp_list*)malloc(sizeof(emp_list));
	if(!emp_l){
		return -1;
	}
	emp_l->debut = NULL;
	return 1;
}
int peut_emp(adherent* adh){
	if(adh->retard!=0){
		printf("cet adherant est retardere est il ne peut pas avoir une emprunte avant de régulariser sa situation");
		return -1;
	}
	if(strcmp(adh->type ,"visiteur") && adh->nbr_encours>=1){
		printf("\nun visiteur ne peut pas exceder 1 seule emprunte en cours, et ce visiteur a %d empruntes en cours\n",adh->nbr_encours);
		return -1;
	}
	if(strcmp(adh->type ,"enseignant") && adh->nbr_encours>=4){
		printf("\nun enseignant ne peut pas exceder 4 empruntes en cours, et cet enseignant a %d empruntes en cours\n",adh->nbr_encours);
		return -1;
	}
	if(strcmp(adh->type ,"etudiant") && adh->nbr_encours>=1){
		printf("\nun etudiant ne peut pas exceder 1 seule emprunte en cours, et cet etudiant a %d empruntes en cours\n",adh->nbr_encours);
		return -1;
	}
	return 1;
}
int push_emp(char* id){
	int* p;
	int choix;
	char id_adh[10];
	char code[10];
	date* current = (date*)malloc(sizeof(date));
	date* delai = (date*)malloc(sizeof(date));
	
	printf("\ndonnez l'dentifiant de l'adherent");
	scanf("%s", id_adh);
	adherent* adh = recherche_adh(id_adh);
	if(adh==NULL){
		printf("\nadherent introuvable , veuillez le creer (tapez 1) our annuler l'operation (tapez n'importe quel chiffre)\n");
		if(!scanf("%d", &choix)){
			return -1;
		}
		if(choix!=1){
			return -1;
		}else{
			push_adh(id_adh);
				
			adh = recherche_adh(id_adh);
				
		}
	}
	if(peut_emp(adh)==-1){

		return -1;
	}
	adh->nbr_encours = adh->nbr_encours+1;
	//check after this
	printf("\ndonnez le code du document");
	scanf(" %s", code);
	if(verif_doc(code)==-1){
		do{
			printf("document introuvable, essayez de nouveau ou entrez -1 pour annuler");
			scanf(" %s", code);
		}while(verif_doc(code)==-1 && code!="-1");
		if(code=="-1"){
			return -1;
		}
	}
	emprunte* emp = create_emp(code,id_adh,id);
	
	get_current_date(current);
	emp->dateDebut = current;
	if(adh->type=="visiteur"){
		ajouter_jours(current,7,delai);
	}else if(adh->type=="enseignant"){
		ajouter_jours(current,21,delai);
	}else{
		ajouter_jours(current,14,delai);
	}
	emp->delaiLimite = delai;
	emp_node* node = create_emp_node(emp);
	
//	adh->nbr_encours = adh->nbr_encours+1;
	emp->returned = 0;
	if(emp_l->debut == NULL){
		emp_l->debut = node;

		return 1;
	}
	emp_node* temp = emp_l->debut;
	while(temp->suivant!=NULL){
		temp=temp->suivant;
	}
	temp->suivant = node; 
	return 1;
}

void affiche_emp(){
	emp_node* temp= emp_l->debut;
	if(temp==NULL){
		printf("\nliste vide");
		return;
	}
	while(temp!=NULL){
		printf("\n\t\t\t******************************************************************************");
		printf("\n\t\t\tId de l'emprunte     = %s\n", temp->emp->id);
        printf("\n\t\t\tCode de document     = %s\n",temp->emp->doc);
        printf("\n\t\t\tId de l'adherent     = %s\n",temp->emp->id_adh);
		printf("\n\t\t\tDate de debut        = (%d/%d/%d)\n",temp->emp->dateDebut->dd , temp->emp->dateDebut->mm, temp->emp->dateDebut->yy);
        printf("\n\t\t\tDate de delai limite = (%d/%d/%d)\n",temp->emp->delaiLimite->dd, temp->emp->delaiLimite->mm, temp->emp->delaiLimite->yy);
        printf("\n\t\t\tdepassé ?(1/0)       = %d\n",temp->emp->depasse);
        printf("\n\t\t\tretourne ?(1/0)      = %d\n",temp->emp->returned);
        printf("\n\t\t\t******************************************************************************");
        
		temp = temp->suivant;
	}
}
/* TODO (#1#): finish this */
int verif_doc(char* code){
	int choix;
	do{
		printf("\ndonnez le type de document a emprunter:\n1 pour article\n2pour magazine\n3pour livre");
		while(!scanf("%d",&choix)){
			printf("\nentree invalide essayez de nouveau svp");
			fflush(stdin);
		}
	}while(choix!=1 && choix!=2 && choix!=3);
	switch(choix){
		case 1:{
			article* art=recherche_article(code);
			if(art!=NULL){
				if(art->doc->nbr_exemplaires<1){
					printf("\nil n y a plus d'exemplaires a preter");
					return -2;
				}
				art->doc->nbr_exemplaires = art->doc->nbr_exemplaires-1;
				return 1;
			}
			break;
		}
		case 2:{
			magazine* mag=recherche_magazine(code);
			if(mag!=NULL){
				if(mag->doc->nbr_exemplaires<1){
					printf("\nil n y a plus d'exemplaires a preter");
					return -2;
				}
				mag->doc->nbr_exemplaires = mag->doc->nbr_exemplaires-1;
				return 1;
			}
			break;
		}
		case 3:{
			livre* liv=recherche_livre(code);
			if(liv!=NULL){
				if(liv->doc->nbr_exemplaires<1){
					printf("\nil n y a plus d'exemplaires a preter");
					return -2;
				}
				liv->doc->nbr_exemplaires = liv->doc->nbr_exemplaires -1;
				return 1;
			}
			break;
		}
		default:
			printf("erreur de verification de doc");
	}
	return -1;
}

int retourner(char* adh_id,char* code,int type){
	emp_node* temp = emp_l->debut;
	while(temp!=NULL){
		if(temp->emp->returned==0&&strcmp(adh_id,temp->emp->id_adh)==0&&strcmp(code,temp->emp->doc)==0){
			temp->emp->returned=1;
			switch(type){
				case 1:{
					article* art = recherche_article(code);
					art->doc->nbr_exemplaires= art->doc->nbr_exemplaires+1;
					adherent* adh=recherche_adh(adh_id);
					adh->nbr_encours = adh->nbr_encours -1;
					break;
				}
				case 2:{
					livre* liv = recherche_livre(code);
					liv->doc->nbr_exemplaires= liv->doc->nbr_exemplaires+1;
					adherent* adh=recherche_adh(adh_id);
					adh->nbr_encours = adh->nbr_encours -1;
					break;
				}
				case 3:{
					magazine* mag = recherche_magazine(code);
					mag->doc->nbr_exemplaires= mag->doc->nbr_exemplaires+1;
					adherent* adh=recherche_adh(adh_id);
					adh->nbr_encours = adh->nbr_encours -1;
					break;
				}
			}
			printf("document retourné");
			return 1;
		}
		temp=temp->suivant;
	}
	printf("\nverifier l'id de l'adherent et le code\n");
}

int nbr_emps_par_adh_ec();//nbr emps en cours
int nbr_emps_par_adh_tt();//nbr emps total
int nbr_emps_par_adh_ec();//nbr emps dépassées

emprunte* emp_construct(char* single){
	emprunte* emp = (emprunte*)malloc(sizeof(emprunte));
	date* dateDebut = (date*)malloc(sizeof(date));
	date* delaiLimite = (date*)malloc(sizeof(date));
	emp->dateDebut = dateDebut;
	emp->delaiLimite = delaiLimite;
	if(emp==NULL){
		printf("adh_construct a echouee");
		return NULL;
	}
	char delim[] = ":";
	char *ptr = strtok(single,delim);
	strcpy (emp->id, ptr);
	ptr = strtok (NULL, delim);
	strcpy (emp->id_adh, ptr);
	ptr = strtok (NULL, delim);
	strcpy(emp->doc, ptr);
	emp->dateDebut->dd = atoi(strtok(NULL, delim));
	emp->dateDebut->mm = atoi(strtok (NULL, delim));
	emp->dateDebut->yy = atoi(strtok (NULL, delim));
	emp->delaiLimite->dd=atoi(strtok(NULL,delim));
	
	emp->delaiLimite->mm= atoi(strtok(NULL, delim)); 
	emp->delaiLimite->yy= atoi(strtok (NULL, delim)) ;
	emp->returned = atoi(strtok (NULL, delim));
	emp->depasse = atoi(strtok (NULL, delim));

	return emp;
}


int push_emp_inload(emprunte* emp){
	if(!emp){
		return -1;
	}	
	emp_node *p = (emp_node*)malloc(sizeof(emp_node));
	if(!p){
		return -1;
	}
	p->emp= emp;
	p->suivant = NULL;
	
	emp_node* temp = emp_l->debut;
	if(!p){
		return -1;
	}
	if(emp_l->debut == NULL){
		emp_l->debut = p;
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



int saver_emps(){
	FILE *f;
	char buffer[100];
	emp_node* temp = emp_l->debut;
	int len;
   	f = fopen("emps.dat", "w+");
   	if(f == NULL) {
		perror("erreur dans l'ouverture de fichier");
		return(-1);
   }
	if(temp == NULL){
		printf("\npas d'empruntes a sauvegarder");
		return 1;
	}
	while(temp!=NULL){
		sprintf(buffer,"%s:%s:%s:%d:%d:%d:%d:%d:%d:%d:%d\n", temp->emp->id, temp->emp->id_adh, temp->emp->doc, temp->emp->dateDebut->dd,temp->emp->dateDebut->mm,temp->emp->dateDebut->yy,temp->emp->delaiLimite->dd,temp->emp->delaiLimite->mm,temp->emp->delaiLimite->yy,temp->emp->returned,temp->emp->depasse);
		fputs(buffer, f);
		fseek(f, 0, SEEK_END);
		temp = temp->suivant;
	}
   len = ftell(f);
   
   fclose(f);
   
   printf("\n%d octets ecrits dans emps.dat", len);
   return 1;
}

int loader_emp(){
	date* current = (date*)malloc(sizeof(date));
	FILE *f;
	char buffer[100];
	int len,i=0;
   	f = fopen("emps.DAT", "r");
   	if(f == NULL) {
		perror("erreur dans l'ouverture de fichier");
		return(-1);
}
	get_current_date(current);
   	if(buffer==NULL){
   		printf("erreur de memoire dans loader_emp");
	   }
	   
	   while (fgets(buffer, sizeof(buffer),f)) {
           emprunte* emp = emp_construct(buffer);
           //printf("\n\n%d/%d/%d\n\n",emp->delaiLimite->dd,emp->delaiLimite->mm,emp->delaiLimite->yy);
           if(emp->returned==0){
		   if(emp->delaiLimite->yy<current->yy){
           	emp->depasse = 1;
           	adherent* adh = recherche_adh(emp->id_adh);
           	if(adh!=NULL){
           		adh->retard = 1;
			   }
           	
		   }else if(emp->delaiLimite->mm<current->mm&&emp->delaiLimite->yy==current->yy){
		   	emp->depasse = 1;
           	adherent* adh = recherche_adh(emp->id_adh);
           	if(adh!=NULL){
           		adh->retard = 1;
			   }
		   }else if(emp->dateDebut->dd<current->dd&&emp->delaiLimite->mm==current->mm&&emp->delaiLimite->yy==current->yy){
		   	
		   	emp->depasse = 1;
           	adherent* adh = recherche_adh(emp->id_adh);
           	if(adh!=NULL){
           		adh->retard = 1;
			   }
		   }}
           push_emp_inload(emp);
        //	printf("%s", buffer); 
        	i = atoi(emp->id)+1;
    	}
   fclose(f);
   
   id_emp = i+1;
   return 1;
}

