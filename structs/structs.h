typedef struct date{
	int dd;
	int mm;
	int yy;
}date;
//adherants
typedef struct{
	char id[10];
	char nom[20];
	char prenom[20];
	char adresse[20];
	char type[11];
	int retard;
	int nbr_encours;
	//emp_node* l_emps; na7ineha car bech tkoun kima DB , kol 7aja fi fichier mte3ha , bech ki na3mel save leldata menal9ach mochkol
}adherent;

typedef struct adh_node{
	adherent* adh;
	struct adh_node* suivant;
}adh_node;

typedef struct adh_list{
	adh_node* debut;
}adh_list;

//docs
typedef struct document{
	char code[10];
	char titre[20];
	char type[20];
	int nbr_exemplaires;
	int location;

}doc;

typedef struct article{
	doc* doc;
	char auteur[20];
	date* date_pub;
}article;
typedef struct livre{
	doc* doc;
	char auteur[20];
	char editeur[20];
	date* date_edit;
}livre;
typedef struct magazine{
	doc* doc;
	int frequence; //par semaine
}magazine;

typedef struct article_node{
	article* doc;
	struct article_node* suivant;
}art_node;
typedef struct livre_node{
	livre* doc;
	struct livre_node* suivant;
}liv_node;
typedef struct magazine_node{
	magazine* doc;
	struct magazine_node* suivant;
}mag_node;

typedef struct article_list{
	art_node* debut;
}art_list;
typedef struct livre_list{
	liv_node* debut;
}liv_list;
typedef struct magazine_list{
	mag_node* debut;
}mag_list;


typedef struct doc_node{
	doc* doc;
	struct doc_node* suivant;
}doc_node;

typedef struct doc_list{
	doc_node* debut;
}doc_list;

//empruntes
typedef struct{
	char id[10];
	char id_adh[10];
	char doc[20];
	date* dateDebut;
	date* delaiLimite;
	int returned;
	int depasse;
}emprunte;

typedef struct emp_node{
	emprunte* emp;
	struct emp_node* suivant;
}emp_node;
typedef struct emp_list{
	emp_node* debut;
}emp_list;

