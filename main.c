#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structs/structs.h"


/* run this program using the console pauser or add your own getch, system("pause") or input loop */




int main(int argc, char *argv[]) {
	adh_list* l_adh = create_adh_list();
	push_adh(l_adh, "0");
	push_adh(l_adh, "0");
	push_adh(l_adh, "0");

	afficher_adh(l_adh);

	return 0;
}
