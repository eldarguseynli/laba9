#define _CRT_SECURE_NO_WARNINGS
#include "usefulFunc_9.h"
int main(){

	puts("---------------------DATABASE---------------------\n");

	int choice = 1;
	while(choice){
	
		printf("\nWhat do you want to do?\n\n"
			"1. Create a new database.\n"
			"2. Add a new note to the database.\n"
			"3. Delete the note from the database.\n"
			"4. Find the note in the database.\n"
			"5. Edit the note in the database.\n"
			"6. Sort the notes in the database.\n"
			"7. Output data in the terminal from the database.\n"
			"8. Exit\n\nYour choice: "

		);
		readIntClearly(&choice);


		char name[12];
		printf("\nInput the name of database file: ");
		getClearly(name, 12);

		name[strlen(name) - 1] = 0;
		validate_fname(name);


		switch (choice)
		{
		case 8:
		{
			return 0; //if user choose 8 - terminate the programm
		}		      //else - ask him the name of database file 
		case 1:
		{
			createFile(name);
			break;
		}
		case 2:
		{
			addTheNote(name);
			break;
		}
		case 3:
		{
			deleteTheNote(name);
			break;
		}
		case 4:
		{
			findTheNote(name);
			break;
		}
		case 5:
		{
			editTheNote(name);
			break;
		}
		case 6:
		{
			sortTheNotes(name);
			break;
		}
		case 7:
		{
			outputTheNotes(name);
			break;
		}
		default:
			raise_val_error("You`ve inputed unvalid data. Choose number between 1 and 7. Terminating the programm");
			break;
		}
	}
}