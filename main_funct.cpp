//JOseph Starr, CS 202, Program #3
//this file contains the functions implementation for the
//main client programms functions.  they are in their own file to keep
//the program organized and easy to read


#include "list.h"



//This is the menu function for the client program
void menu(char *& sport_name, int & menu_choice)
{	
	char temp_name[100] = {'\0'};
	cout <<"(1) Add a new sport and its cooresponding players. \n";
	cout <<"(2) See all sports and players. \n";
	cout <<"(3) See all sports and players and terminate the program. \n\n";
	do
	{
		cin >>menu_choice;
		cin.ignore(5, '\n');	
		if(menu_choice > 3 || menu_choice < 1)
			cout <<"You must enter a number between 1 and 3.  Please enter a number again. \n";

	}while(menu_choice < 1 || menu_choice > 3);
	if(menu_choice == 1)
	{
		cout <<"Enter the name of the sport you would like to add. \n";
		cin.get(temp_name, 1000, '\n');
		cin.ignore(1000, '\n');
	}
	if(sport_name)
	{
		delete [] sport_name;
		sport_name = new char[strlen(temp_name) + 1];
		strcpy(sport_name, temp_name);
	}
	else
	{
		sport_name = new char[strlen(temp_name) + 1];
		strcpy(sport_name, temp_name);
	}
	return;
}


//This is the menu to choose what type of sport the user wants to add
void type_menu(int & menu_choice)
{
	cout <<"What type of sport is it? \n";
	cout <<"  (1) Single Player Sport. \n";
	cout <<"  (2) Team Sport. \n";
	cin >>menu_choice;
	cin.ignore(5, '\n');
	return;
}
