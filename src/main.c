/*
 ===========================================================================================================
 project Name : Clinic Management System C prject
 Author       : Ahmed Abd Elgleel
 Created On   : 15 August 2023
 File Type    : Main File
 ============================================================================================================
 */

/* ---------------------------------------Function prototypes and Libraries-------------------------------- */
#include "protypes.h"

/*-----------------------------------------------Main Function ---------------------------------------------*/

int main() {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	unsigned char ChoiceOfMode;
			/*----------------------- first screen to choose mode ---------------------*/
	while (1) {
		printf("---------< Choose mode >---------\n");
		printf("A. Admin Mode\n");
		printf("B. User Mode\n");
		printf("C. Exit The system\n\n");
		printf("Choice char :");
		fflush(stdin);
		scanf(" %c", &ChoiceOfMode);

		  	  /*------ if the user choose A or a, the admin mode will activate -------*/

		if ( (ChoiceOfMode == 'A')||(ChoiceOfMode == 'a'))
		{
			adminMode();
		}
			/*------ if the user choose B or b, the user mode will activate ----------- */

		else if ( (ChoiceOfMode == 'B')||(ChoiceOfMode == 'b')) {
			userMode();
		}
			/*------- if user choose to exit system, the infinite loop will break --------*/

		else if ( (ChoiceOfMode == 'C')||(ChoiceOfMode == 'c')) {
			break;
		}
			/*---------- else statement to input validation from main screen------------ */
		else {
			printf("Invalid choice.\nwe will restart system for you\n");
		}
		printf("--------------------------------------------------");
	}
	/* The end of the system */
	printf("\nExit From System \n");
	return 0;
}

