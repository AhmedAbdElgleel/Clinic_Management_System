/*
 =============================================================================================================================
 Author       : Ahmed Abd Elgleel
 Date         : 15 August 2023
 File Type    : Function definition file
 =============================================================================================================================
 */
#include "protypes.h"

/*----------------------------------------------- Global variables -------------------------------------------------------*/

PatientNode *patientList = NULL;                					/*Global variables for patient linked list*/

ReservationNode *reservationList = NULL;							/*Global variables for reservation linked list*/

/*---------------------------Function Admin mode which contain the options for admin --------------------------- */
void adminMode() {
	int password_retries = 3;											/* the available password tries for admin mode */
	int password;													/* the constant password for admin mode */
	const int adminPassword = 1234;
	while (password_retries > 0) {
		printf("Enter password (Remaining tries--> %d): ", password_retries);
		scanf("%d", &password);

		if (password == adminPassword) {							/* compare between the const pass of admin and the pass input */
			unsigned char adminChoice;
			while (1) {
				/* the menu for admin options */
				printf("\n---------< Admin Mode >---------\n");
				printf("A. Add new patient record\n");
				printf("B. Edit patient record\n");
				printf("C. Reserve a slot with the doctor\n");
				printf("D. Cancel reservation\n");
				printf("E. Exit From admin mode\n\n");
				printf("Enter your choice: ");
				scanf(" %c", &adminChoice);
				switch (adminChoice) {
				case 'A':
				case 'a':
					addPatient();									/* lets add patient information admin */
					break;
				case 'B':
				case 'b':
					editPatient();									/*lets edit patient data */
					break;
				case 'C':
				case 'c':
					reserveSlot();									/* Lets reserve slot for patient */
					break;
				case 'D':
				case 'd':
					cancelReservation();							/* Cancel reservation for patient */
					break;
				case 'E':
				case 'e':
					return;											/* the admin choose to exit admin mode */
				default:

					printf("Invalid choice.\n");					/* default statement to input validation from admin */
				}
			}
		} else {
			password_retries--;										/* if the entered is incorrect, then tries will decrement */
			if (password_retries > 0) {								/* Continue as their is more available tires */
				printf("Incorrect password\n");
			} else {
				printf("Incorrect password. Exiting...\n");		    /* if there is not available tries for password, then admin mode will automatically closed */
				return;
			}
		}
	}
}

/*----------------------------------------- Function which contain the options for user mode -----------------------------------*/
void userMode() {
	unsigned char userChoice;
	while (1) {
		/*---------------------------------User Feature menu-----------------------------------*/
		printf("\n---------< User Mode >---------\n");
		printf("A. View patient record\n");
		printf("B. View today's reservations\n");
		printf("C. Exit user mode\n\n");
		printf("Enter your choice: ");
		fflush(stdin);
		scanf(" %c", &userChoice);
		switch (userChoice) {
		case 'A':
		case 'a':
			printf("Enter patient ID: "); 					/* the user choose to view patient record and will enter the id */
			int patientId;
			scanf("%d", &patientId);
			viewPatientRecord(patientId);
			break;
		case 'B':
		case 'b':
			viewReservations();								/* the user choose to view reservations */
			break;
		case 'C':
		case 'c':
			return;											/* the user choose to exit user mode */
		default:
															/* default statement to input validation from user */
			printf("Invalid choice.\n");
		}
	}
}

/*-------------------- function to add new patient to the patient linked-list and check if the id exists or not ----------------*/
void addPatient() {
	PatientNode *new_Patient = (PatientNode*) malloc(sizeof(PatientNode));    /*create a new node*/
	assert(new_Patient!=NULL);       						/*if their is no space in program stop the program now*/
	printf("Enter patient ID: ");
	scanf("%d", &new_Patient->id);
	PatientNode *current = patientList;						/* check if the ID already used or exist in the list */
	while (current != NULL) {
		if (current->id == new_Patient->id) {				/* the Id is found and so we  can't add new patient using this id */
			printf("Patient with ID %d already exists.\n", new_Patient->id);

			free(new_Patient);								/* free allocated memory since we're not adding a new patient */
			new_Patient=NULL;                                /* to avoid dangling pointers*/
			return;
		}
		current = current->next;
	}
	/*-----in case program reach to this scope this mean that there is available place for new patient ----*/
	printf("Enter patient name: ");
	scanf("%s", new_Patient->name);
	printf("Enter patient age: ");
	scanf("%d", &new_Patient->age);
	printf("Enter patient gender (M/F): ");
	scanf(" %c", &new_Patient->gender);
	new_Patient->next = patientList;							/*Just keep tracking head*/
	patientList = new_Patient;								/* make the new record of patient is the head of linked list */
	printf("Patient record added successfully.\n");
}

/*-----------------------function to edit a data of patient and check if the id exists --------------------------------------*/
void editPatient() {
	int Id_patient;
	printf("Enter patient ID to edit: ");
	scanf("%d", &Id_patient);
	PatientNode *current_Patient = patientList;
	while (current_Patient != NULL) {						/* search for the entered id if exists or not */
		if (current_Patient->id == Id_patient) {
			printf("Enter new patient name: ");				/* the entered id is exists and ready to edit data */
			scanf("%s", current_Patient->name);
			printf("Enter new patient age: ");
			scanf("%d", &current_Patient->age);
			printf("Enter new patient gender (M/F): ");
			scanf(" %c", &current_Patient->gender);
			printf("Patient data updated successfully.\n");
			return;
		}
		current_Patient = current_Patient->next;
	}
	printf("Patient with ID %d not found.\n", Id_patient);	/* the id you entered is not exist */
}

/*-------------------------function enable the patient to reserve a slot if it is available---------------------*/
void reserveSlot() {
	bool found = FALSE;
	bool slot_1, slot_2, slot_3, slot_4, slot_5;
	int Id_Patient;
	int slotChoice;
	printf("\n---------< Available slots >---------\n");
	ReservationNode *check_Slot = reservationList;			/* check each slot if it is available or not */
	slot_1 = slot_2 = slot_3 = slot_4 = slot_5 = TRUE;		/* suppose at that by default all slots are available */
	while (check_Slot != NULL) {

		if (check_Slot->slot != 1 && slot_1) {				/* check if the first slot  is not reserved */

			slot_1 = TRUE;									/* the first slot is not reserved keep its value true */
		} else {
			slot_1 = TRUE;									/* the first slot is not available so we will make its disappear from menu */
		}
		if (check_Slot->slot != 2 && slot_2) {				/* check if second slot 2 is not reserved */
			slot_2 = TRUE;									/* the second slot is not reserved so keep its value true */
		} else {
			slot_2 = FALSE;									/* the second slot is not available so we will make its disappear from menu  */
		}
		if (check_Slot->slot != 3 && slot_3) {				/* check if the third slot is not reserved */
			slot_3 = TRUE;									/* the third slot is not reserved so remain true */
		} else {
			slot_3 = FALSE;									/* the third slot is not available so we will make its disappear from menu */
		}
		if (check_Slot->slot != 4 && slot_4) {				/* check if the fourth slot is not reserved */
			slot_4 = TRUE;									/* the fourth slot is not reserved so remain true */
		} else {
			slot_4 = FALSE;									/* the slot fourth is not available so we will make its disappear from menu  */
		}
		if (check_Slot->slot != 5 && slot_5) {				/* check if the fifth slot is not reserved */
			slot_5 = TRUE;									/* the fifth slot is not reserved so remain true */
		} else {
			slot_5 = FALSE;									/* the fifth slot is not available so we will make its disappear from menu  */
		}
		check_Slot = check_Slot->next;
	}
			/*-------------------- Displaying the all Available Slots ------------*/
	if (slot_1) {
		printf("1. 2:00pm : 2:30pm\n");
	}
	if (slot_2) {
		printf("2. 2:30pm : 3:00pm\n");
	}
	if (slot_3) {
		printf("3. 3:00pm : 3:30pm\n");
	}
	if (slot_4) {
		printf("4. 4:00pm : 4:30pm\n");
	}
	if (slot_5) {
		printf("5. 4:30pm : 5:00pm\n");
	}

	printf("Enter patient ID: ");
	scanf("%d", &Id_Patient);

	PatientNode *current = patientList;
	while (current != NULL) {
		if (current->id == Id_Patient) {
			found = TRUE;
			break;
		}
		current = current->next;
	}
	if (!found) {						   			/* check if the id is founded or not*/
		printf("Patient with ID %d not found.\n", Id_Patient);
		return;
	}
	printf("Enter the number of slot: ");
	fflush(stdin);
	scanf("%d", &slotChoice);						/* if incorrect slot choice is entered */
	if (slotChoice < 1 || slotChoice > 5) {
		printf("Invalid slot choice.\n");
		return;
	}
													/* Check if the slot is already reserved */
	ReservationNode *currentReservation = reservationList;
	while (currentReservation != NULL) {
		if (currentReservation->slot == slotChoice) {
													/* when u reach to this point this mean the chosen slot is reserved */
			printf("Slot is already reserved.\n");
			return;
		}
		currentReservation = currentReservation->next;
	}
	ReservationNode *new_Reservation = (ReservationNode*) malloc(sizeof(ReservationNode));
	assert(new_Reservation!=NULL);       			/*if their is no space in program stop the program now*/
	new_Reservation->slot = slotChoice;				/* at this point the chosen slot is not reserved and start to reserve it */
	new_Reservation->patientId = Id_Patient;
	new_Reservation->next = reservationList;
	reservationList = new_Reservation;
	printf("Slot reserved successfully.\n");
}

/* -------------function enable the patient to cancel a reservation if it exits with his id*------------------*/
void cancelReservation() {
	int Id_patient;
	printf("Enter patient ID to cancel reservation: ");
	scanf("%d", &Id_patient);
	ReservationNode *current_Reservation = reservationList;
	ReservationNode *prev_Reservation = NULL;
	while (current_Reservation != NULL) {							 /* search in  reservation slots in the clinic */
		if (current_Reservation->patientId == Id_patient) {			 /* if the entered id has been found in the reservations */
			if (prev_Reservation == NULL) {							 /* The reservation to cancel is the first node */
				reservationList = current_Reservation->next;
			} else {
				prev_Reservation->next = current_Reservation->next;	 /* connect between previous node and the next of current node */
			}
			free(current_Reservation);								 /* free the allocation of the cancelled reservation */
			current_Reservation=NULL;
			printf("Reservation cancelled.\n");
			return;
		}
		prev_Reservation = current_Reservation;						/* continue the search operation of the patient id */

		current_Reservation = current_Reservation->next;
	}
	printf("No reservation found for the given patient ID.\n");   /* if reach here, that is mean the patient id is not found in the linked-list */
}

/*------------------------- function to show data of patient in the linked-list by searching with his id ---------------------*/
void viewPatientRecord(int id) {
	PatientNode *current_Patient = patientList;
	while (current_Patient != NULL) {
		if (current_Patient->id == id) {
			/* the given id is found and print its data */
			printf("Patient Name: %s\n", current_Patient->name);
			printf("Age: %d\n", current_Patient->age);
			printf("Gender: %c\n", current_Patient->gender);
			printf("ID: %d\n", current_Patient->id);
			return;
		}
		current_Patient = current_Patient->next;
	}
	printf("Patient not found.\n");
}

/*------------------------------- function to show data of reservation for today ----------------------------------*/
void viewReservations() {

	if (reservationList == NULL) {
		printf("No reservations for today.\n");						/* there is no reservations and no patient take a slot */
		return;
	}
	printf("\n----------<Today's reservations >----------\n"); 		/* there is a reservations lets print it */
	ReservationNode *currentReservation = reservationList;
	while (currentReservation != NULL) {
		printf("Slot %d: Patient ID %d\n", currentReservation->slot,
				currentReservation->patientId);
		currentReservation = currentReservation->next;
	}
}
