//Joseph Starr, CS202, Program#3

#include "sports.h"


//The next handful of functions are the constructors, destructors, and copy constructors for the hierarchy.
athlete_node :: athlete_node() : next(NULL)
{
}

athlete_node :: athlete_node(const athlete_node & a)
{
	person = a.person;
}


athlete_node :: ~athlete_node()
{
	next = NULL;
}


sport :: sport() : head(NULL), name(NULL), details(NULL), schedule(NULL), network(NULL), rtti(0)
{
}


sport :: sport(int type) : head(NULL), name(NULL), details(NULL), schedule(NULL), network(NULL), rtti(type)
{
}


sport :: ~sport()
{
	if(name)
		delete [] name;
	if(details)
		delete [] details;	
	if(schedule)
		delete [] schedule;	
	if(network)
		delete [] network;
	if(head)
		delete_nodes(head);
	
}


sport :: sport(const sport & s)
{
	if(s.name)
	{
		name = new char[strlen(s.name) + 1];
		strcpy(name, s.name);
	}
	if(s.details)
	{
		details = new char[strlen(s.details) + 1];
		strcpy(details, s.details);
	}
	if(s.schedule)
	{
		schedule = new char[strlen(s.schedule) + 1];
		strcpy(schedule, s.schedule);
	}
	if(s.network)
	{
		network = new char[strlen(s.network) + 1];
		strcpy(network, s.network);
	}
	rtti = s.rtti;	
	if(!s.head)
		head = NULL;
	else
		copy_list(s.head, head);
}


single :: single() : players(0)
{
}

single :: single(const single & source) : sport(source)
{
	players = source.players;
}

single :: single(int i) : sport(1)
{
	players = i;
}

single :: ~single()
{
}


team :: team() : teams(0)
{
}

team :: team(const team & source) : sport(source)
{
	teams = source.teams;
}

team :: team(int i) : sport(2)
{
	teams = i;
}

team :: ~team()
{
}


//This next two functions are used to copy or delete the list for the sport class and are
//used in the copy constructors and destructors
void sport :: copy_list(athlete_node * source, athlete_node *& head)
{
	if(!source)
		return;
	head = new athlete_node(*source);
	copy_list(source -> go_athlete_next(), head -> go_athlete_next());
}



void sport :: delete_nodes(athlete_node *& head)
{
	if(!head)
		return;
	delete_nodes(head -> go_athlete_next());
	delete head;
	head = NULL;
}


athlete_node *& athlete_node :: go_athlete_next()
{
	return next;
}


//This is used to connect the athlete_node's next pointer
void athlete_node :: connect_athlete_next(athlete_node * to_connect)
{
	next = to_connect;
}


//The next two functions used the overloaded << operator to display
void athlete_node :: display(ostream & o) const
{
	o << person;
	return;
}


void sport :: display(ostream & o) const
{
	o <<"Sport Name: " <<name <<"\n";
	o <<"Sport Details: " <<details <<"\n";
	o <<"Sport Schedule: " <<schedule <<"\n";
	o <<"Network to Air Sport: " <<network <<"\n";
	if(!head)
	{
		o <<"No current athletes or teams participating in this sport. \n\n";
		return;
	}
	else
	{
		display_rec(head, o);
		return;
	}
}


//This functino retuyrns the sports name to the tree so it can be sued to compare
char * sport :: give_name()
{
	return name;
}


//This function recieves the data for the sport class from the user
void sport :: recieve_data()
{
	char temp_name[100];
	char temp_details[1000];
	char temp_schedule[100];
	char temp_network[100];
	if(name)
		delete [] name;
	if(details)
		delete [] details;
	if(schedule)
		delete [] schedule;
	if(network)
		delete [] network;
	cout <<"Enter the sport's name. \n";
	cin >>temp_name;
	name = new char[strlen(temp_name) + 1];
	strcpy(name, temp_name);
	cout <<"Enter the sport description. \n";
	cin  >>temp_details;
	details = new char[strlen(temp_details) + 1];
	strcpy(details, temp_details);
	cout <<"Enter in the sport's schedule. \n";
	cin >>temp_schedule;
	schedule = new char[strlen(temp_schedule) + 1];
	strcpy(schedule, temp_schedule);
	cout <<"Enter in the network this sport will be broadcasted on. \n";
	cin >>temp_network;
	network = new char[strlen(temp_network) + 1];
	strcpy(network, temp_network);
	add_athlete_wrap();
	return;
}


//This function is the recursive funtion for the sport classes diusplay function.
//it uses the overloaded << operator
void sport :: display_rec(athlete_node * head, ostream & o) const
{
	if(!head)
		return;
	o << *head;
	display_rec(head -> go_athlete_next(), o);	
}


//This function is the wrapper function to add an athelte to the LLL of athletes 
//in the sport class
void sport :: add_athlete_wrap()
{
	if(!head)
	{
		head = new athlete_node;
		cin >>*head;
		head -> connect_athlete_next(NULL);
		if(continue_input())
		{
			do
			{
				add_athlete(head);
			}while(continue_input());
		}
		return;
	}
	else
	{
		do
		{
			add_athlete(head);
		}while(continue_input());
		return;
	}

}


//This is the recusrive funciton for the function that adds an athlete to the sport class
//it uses the overloaded >> operator
void sport :: add_athlete(athlete_node *& head)
{
	if(!head -> go_athlete_next())
	{
		athlete_node * temp = head;
		head = new athlete_node;
		cin >> *head;
		head -> connect_athlete_next(temp);
		return;
	}
	add_athlete(head -> go_athlete_next());	
}


//This function is to check if the user wants to continue adding athletes to the sport class
bool sport :: continue_input()
{
	char answer = ' ';
	cout <<"Continue Adding Athletes? Y/N\n\n";
	cin >>answer;
	cin.ignore(2, '\n');
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


/*************************************************************
			The next section of code 
			is for the derived classes
**************************************************************/



//The next two functions are the display functions 
//for the derived classes using the overloaded << operator
void single :: display(ostream & o) const
{
	this -> sport::display(o);
	o <<"Number of participants: " <<players <<"\n\n";
	return;
	
}


void team :: display(ostream & o) const
{
	this -> sport::display(o);
	o <<"Number of teams participating: " <<teams <<"\n\n";
	return;
}








