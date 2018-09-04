//Joseph Starr, CS202, Program 3
//This program organizes and stores data about any oylmpic sports/events and  athelete read in or entered by the user.
//Includes indepth information about the events and the  atheletes that participate in said events.


//#include "athletes.h"


#include "list.h"


int main()
{
	list obj;
	int menu_choice = 0;
	char * sport_name = NULL;
	menu(sport_name, menu_choice);
	while(menu_choice != 3)//This is the main loop for the prpogram.  It terminates the program when the user enters a 3
	{
		if(menu_choice == 1)
		{
			type_menu(menu_choice);
			obj.add_sport(sport_name, menu_choice);
			menu(sport_name, menu_choice);	
		}
		else if(menu_choice == 2)
		{
			obj.display();
			menu(sport_name, menu_choice);
		}
	}
	obj.display();
	if(sport_name)
		delete [] sport_name;

	/***********************************************************
				below is the binary
	***********************************************************/

	/*list obj;
	int menu_choice = 0;
	char * sport_name = NULL;
	menu(sport_name, menu_choice);
	while(menu_choice != 3)
	{
		if(menu_choice == 1)
		{
			type_menu(menu_choice);
			obj.add_sport(sport_name, menu_choice);
			menu(sport_name, menu_choice);	
		}
		else if(menu_choice == 2)
		{
			obj.display();
			menu(sport_name, menu_choice);
		}
	}
	obj.display();
	if(sport_name)
		delete [] sport_name;*/
	return 0;
} 


