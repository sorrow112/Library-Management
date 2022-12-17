#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include <string.h>
//adherant
adherent* create_adh(char* id);
adh_node* create_adh_node(char* id);
void push_into_adh_list(adh_node* head, adh_node* newNode); //takes a list and an element
void afficher_adh(adh_node* head);
int nbr_emps_par_adh_ec();//nbr emps en cours
int nbr_emps_par_adh_tt();//nbr emps total
int nbr_emps_par_adh_ec();//nbr emps dépassées

//emprunte
emprunt* create_emp();

emp_node* create_emp_node();

//docs
doc* create_doc();
doc_node* create_doc_node();
doc* recherche_doc();
article* recherche_article(); //par id doc
livre* recherche_livre(); //par id doc
magazine* recherche_magazine(); //par id doc
void affiche_doc();
