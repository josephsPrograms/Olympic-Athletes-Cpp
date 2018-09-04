//Joseph Starr, CS 202, Program #3
//This file contains all the function implementation for the 
//athlete class and its corresponding node class.  This is to 
//keep the programm organized and easier to read.


#include "athletes.h"


//The next 8 functions arwe the constructors, destrcutors, and copy constructors fotr the athlete classs
//and its node class containing athletes history
node_history :: node_history() : medals(NULL), history(NULL), next(NULL)
{
}


node_history :: node_history(const node_history & source)
{
	medals = new char[strlen(source.medals) + 1];
	strcpy(medals, source.medals);
	history = new char[strlen(source.history) + 1];
	strcpy(history, source.history);
}


node_history :: ~node_history()
{
	delete [] medals;
	delete [] history;
	next = NULL;
}


athlete :: athlete() : name(NULL), events(NULL), head(NULL)
{
}


athlete :: athlete(const athlete & source)
{
	if(!source.head)
	{
		head = NULL;
		return;
	}
	copy_list(source.head, head);
}


athlete :: ~athlete()
{
	if(name)	
		delete [] name;
	if(events)
		delete [] events;
	if(head)
		delete_list(head);
}


void athlete :: copy_list(node_history * source_head, node_history *& head)
{
	if(!source_head)
		return;
	head = new node_history(*source_head);
	copy_list(source_head -> go_next(), head -> go_next());
}



node_history *& node_history :: go_next()
{
	return next;
}


void athlete :: delete_list(node_history *& head)
{
	if(!head)
		return;
	delete_list(head -> go_next());
	delete head;
	head = NULL;	
	return;
}


//The next three classes are used to display the node and athlete classes.
void node_history :: display() const
{
	cout <<" Medals: \n";
	cout <<"  " <<medals <<"\n";
	cout <<" History: \n";
	cout <<"  " <<history <<"\n\n";
	return;
}


void athlete :: display_wrap(ostream & out) const
{
	cout <<"Athlete name: " <<name <<"\n";
	cout <<"Athlete's events: \n";
	cout <<"  " <<events <<"\n";
	if(!head)
		return;
	else
	{
		display(head, out);
		return;
	}
}


//This function uses the overloaded << operator to display the nodes
void athlete :: display(node_history * head, ostream & out) const
{
	if(!head)
		return;	
	out << *head;
	display(head -> go_next(), out);	
}


node_history *& athlete :: return_head(node_history *& head)
{
	return head;
}


//this function is used to askt the user if they want to contine adding history to an athelte
bool athlete :: continue_add()
{
	char answer = ' ';
	cout <<"Would you like to add another history? Y/N";
	cin >> answer;
	cin.ignore(10, '\n');
	while(toupper(answer) != 'Y' && toupper(answer) != 'N')
	{
		cout <<"That was not a valid input. Pleas enter a Y/N. \n";
		cin >>answer;
		cin.ignore(10, '\n');
	}
	if(toupper(answer) == 'Y')
		return 1;
	else
		return 0;
}


//The remaining functions are used to add an athletes history ti the LLL
void athlete :: add_history_wrap()
{
	if(!head)
	{
		head = new node_history;
		cin >> *head;
		head -> go_next() = NULL;
		return;
	}
	else
		add_history(head);
}


void node_history :: connect_next(node_history * to_connect)
{
	next = to_connect;
}


void athlete :: add_history(node_history *& head)
{

	if(!head -> go_next())
	{
		node_history * temp = head;
		head = new node_history;
		cin >>*head;
		head -> connect_next(temp);
		return;
	}
	add_history(head -> go_next());
}




