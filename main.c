#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structs/structs.h"


/* run this program using the console pauser or add your own getch, system("pause") or input loop */




int main(int argc, char *argv[]) {
	adh_node* *p1 = create_adh_node("0");
	adh_node* *p2 = create_adh_node("0");
	adh_node* *p3 = create_adh_node("0");
	push_into_adh_list(&p1,&p2);
	push_into_adh_list(&p2,&p3);
	//todo: make a list struct and make this test work

	afficher_adh(p1);

	return 0;
}
