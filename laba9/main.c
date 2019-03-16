#define _CRT_SECURE_NO_WARNINGS
#include "usefulFunc_9.h"
int main()
{
	puts("---------------------DATABASE---------------------\n");
	printf("What do you want to do?\n\n"
		"1. Create a new database.\n"
		"2. Add a new note to the database.\n"
		"3. Delete the note from the database.\n"
		"4. Find the note in the database.\n"
		"5. Edit the note in the database.\n"
		"6. Sort the notes in the database.\n"
		"7. Output data in the terminal from the database.\n\nYour choice: "
	
	);
	int choice; if (!(scanf("%d", &choice))) raise_val_error("You had to input number. Termination of the programm."); clear();

	char name[12];
	printf("\nInput the name of database file: ");
	getClearly(name, 12);

	name[strlen(name) - 1] = 0;
	validate_fname(name);

	switch (choice)
	{
	case 1:
	{
		int n;
		printf("Input how much goods you want to input to the database: ");
		if (!(scanf("%d", &n))) raise_val_error("You had to input number. Termination of the programm."); clear();
		createFile(name, n);  //the name can be the same and we should create new file. createFile should consist of fillFile
							  //chech the scope of these to chanks
		break;
	}
	case 2:
	{
		int *n = malloc(sizeof(int));
		printf("Input how much goods you want to add to the database: ");
		if (!(scanf("%d", n))) raise_val_error("You had to input number");
		//fillFile(&f, name, n); //PRICE CANT BE NEGATIVE
		break;
	}
	case 3:
	{
		deleteTheNote(name);
		//the idea of finding only the first matching product. and use this function in another 3-4 funcs
		break;
	}
	case 4:
	{
		product *p;
		printProduct(findTheNote(name, &p));
		break;
	}
	case 5:
	{
		//editTheNote(&f, name);
	}
	case 6:
	{
		//sortTheNotes(&f, name);
		break;
	}
	case 7:
	{
		outputTheNotes(name);
		break;
	}
	default:
		raise_val_error("You`ve inputed unvalid data. Terminating the programm");
		break;
	}

}