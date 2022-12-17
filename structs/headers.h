#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include <string.h>
//adherant
adherent* create_adh(char* id);
adh_node* create_adh_node(char* id);
int push_adh(adh_list* head, char* id); //takes a list and an element
void afficher_adh(adh_list* head);
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

//add it if it's needed
/*void delete(int data, List * list){
  Node * current = list->head;            
  Node * previous = current;           
  while(current != NULL){           
    if(current->data == data){      
      previous->next = current->next;
      if(current == list->head)
        list->head = current->next;
      free(current);
      return;
    }                               
    previous = current;             
    current = current->next;        
  }                                 
}*/
