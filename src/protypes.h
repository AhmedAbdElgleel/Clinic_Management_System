/*
 ===========================================================================================================================================================
 Author       : Ahmed Abd Elgleel
Created On    : 13 August 2023
 File Type    : Function Prototype file
 ===========================================================================================================================================================
 */
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#ifndef __NODE_
#define __NODE_ 1
/*----------------------------limiting the patient name and slot numbers in clinic-------------------------- */

#define MAX_NAME_LENGTH 20
#define MAX_SLOTS 5
#define NULL (void*)0

/*------------------------------------------- define the boolean data type ----------------------------------*/

#define TRUE  1
#define FALSE 0
typedef unsigned char bool;

/*----------------------------------------structure for patient data-----------------------------------------*/

typedef struct PatientNode {
	char name[MAX_NAME_LENGTH];
	int age;
	char gender;
	int id;
	struct PatientNode *next;
} PatientNode;

/*--------------------------------------------structure for reservation slots-----------------------------------*/

typedef struct ReservationNode {
	int slot;
	int patientId;
	struct ReservationNode *next;
} ReservationNode;

#endif

/*---------------------------------------------- Function prototypes ------------------------------------------*/

void adminMode();                                /*Function used to enter into admin mode features*/

void addPatient();								/*Function used to add patient informations */

void editPatient();								/*Function used to Edit patient information after adding patient*/

void reserveSlot();								/*Function used to Reserve available Slot*/

void cancelReservation();						/*Function used to enter into admin mode features*/

void userMode();								/*Function used to enter into user mode features*/

void viewPatientRecord(int id);					/*Function used to view Patient Information via its ID */

void viewReservations();						/*Function used to View List Of Reservations*/
