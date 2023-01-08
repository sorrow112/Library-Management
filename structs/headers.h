#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include <string.h>

emp_list* emp_l;
art_list* art_l;
liv_list* liv_l;
mag_list* mag_l;
adh_list* adh_l;

int test_date(date* date);
void get_current_date(date* current);
void ajouter_jours(date* debut,int days, date* delai);
//adherant
int create_adh_list();
adherent* create_adh();
adh_node* create_adh_node();
int push_adh();
void afficher_adh();
adherent* recherche_adh(char* id);
void afficher_un_adh(adherent* adh);
int supprimer_adh(char* id);

int saver_adhs();
int loader_adh();
int recherche_adh_nom(char* nom);
int recherche_adh_prenom(char* prenom);
int resolver(adherent* adh);

//emprunte
emprunte* create_emp(char* code, char* id_adh,char* id);
emp_node* create_emp_node(emprunte* emp);
int create_emp_list();
int push_emp(char* id);
int peut_emp(adherent* adh);
void affiche_emp();
emp_node* recherche_emp(); //TODO:make this
emprunte* emp_construct(char* single);
int push_emp_inload(emprunte* emp);
int retourner(char* adh_id,char* code,int type);
int saver_emps();
int loader_emp();

//docs
doc* create_doc();
doc* recherche_doc(char* code);
void affiche_doc();

//livres
livre* create_livre();
liv_node* create_liv_node(livre* liv);
int create_liv_list();
int push_liv();
void affiche_liv();
livre* recherche_livre(char* code); //par id doc
int push_liv_inload(livre* liv);
livre* liv_construct(char* single);
void afficher_un_liv(livre* liv);
int supprimer_liv(char* code);
int loader_liv();
int saver_livs();
int recherche_livre_titre(char* titre);
int recherche_livre_auteur(char* auteur);
int recherche_livre_editeur(char* editeur);



//articles
article* create_article();
art_node* create_art_node(article* art);
int create_art_list();
int push_art();
void affiche_art();
article* recherche_article(char* code); //par id doc
article* art_construct(char* single);
int push_art_inload(article* art);
void afficher_un_article(article* art);
int supprimer_art(char* code);
int saver_arts();
int loader_art();
int recherche_article_titre(char* titre);
int recherche_article_auteur(char* auteur);

//magazines
magazine* create_magazine();
mag_node* create_mag_node(magazine* mag);
int create_mag_list();
magazine* recherche_magazine(char* code); //par id doc
int push_mag();
void affiche_mag();
magazine* mag_construct(char* single);
int push_mag_inload(magazine* mag);
void afficher_un_mag(magazine* mag);
int supprimer_mag(char* code);
int saver_mags();
int loader_mag();
int recherche_magazine_titre(char* titre);




