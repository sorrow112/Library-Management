
//adherants
typedef struct{
	char id[10];
	char nom[20];
	char prenom[20];
	char adresse[20];
	char type[11];
	int retard;
	//emp_node* l_emps; na7ineha car bech tkoun kima DB , kol 7aja fi fichier mte3ha , bech ki na3mel save leldata menal9ach mochkol
}adherent;

typedef struct adh_node{
	adherent* adh;
	struct adh_node* suivant;
}adh_node;


//docs
typedef struct document{
	char code[10];
	char titre[20];
	char type[20];
	int nbr_exemplaires;
	int location;
	int nbr_emps;
	//char categorie[20];
}doc;

typedef struct article{
	char code_doc[10];
	char auteur[20];
	char date_pub[11];
}article;
typedef struct livre{
	char code_doc[10];
	char auteur[20];
	char editeur[20];
	char date_edition[11];
}livre;
typedef struct magazine{
	char code_doc[10];
	int frequence; //par semaine
}magazine;

typedef struct doc_node{
	doc* doc;
	struct doc_node* suivant;
}doc_node;

//empruntes
typedef struct{
	char id[10];
	char id_adh[10];
	char doc[20];
	char dateDebut[11];
	char delaiLimite[11];
	int returned;
}emprunt;

typedef struct emp_node{
	emprunt* emp;
	struct emp_node* suivant;
}emp_node;

typedef struct date{
	int dd;
	int mm;
	int yy;
}date;
