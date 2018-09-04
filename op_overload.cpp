//Joseph Starr, CS 202, Program #3
//This file contains all the operator overloafing functions for the entire program.  This is 
//kept in its own file to keep things organized and easier to read.


#include "list.h"



//The next 4 functions are the overloaded = operator functinos 
//for the athelete class and its node class
athlete & athlete :: operator=(const athlete & a)
{
	if(this == &a)
		return *this;
	copy_this(a);
	return *this;	
}

void athlete :: copy_this(const athlete & a)
{
	if(name)
		delete [] name;
	if(events)
		delete [] events;
	if(head)
		delete head;
	name = new char[strlen(a.name) + 1];
	strcpy(name, a.name);
	events = new char[strlen(a.events) + 1];
	strcpy(events, a.events);
	copy_list(a.head, head);
	return;
}


node_history & node_history :: operator=(const node_history & n)
{
	if(this == &n)
		return *this;
	copy_node(n);
	return *this;
}


void node_history :: copy_node(const node_history & n)
{
	if(medals)
		delete[] medals;
	if(history)
		delete [] history;
	medals = new char[strlen(n.medals) + 1];
	strcpy(medals, n.medals);
	history = new char[strlen(n.history) + 1];
	strcpy(history, n.history);
	return;
}



//The next four functions are the overloaded ostream operators for the
//athlete and its node class
ostream & operator<<(ostream & o, const node_history & n)
{
	//o << n;
	o <<" Medals: \n";
	o <<"  " <<n.medals <<"\n";
	o <<" History: \n";
	o <<"  " <<n.history <<"\n\n";
	return o;
}


istream & operator>>(istream & i, node_history & n)
{
	char medal_type[10];
	char history_story[1000];
	if(n.medals)
		delete [] n.medals;
	if(n.history)
		delete [] n.history;
	cout <<"Enter in the medal type. (Gold, Silver, or Bronze) \n";
	i >>medal_type;
	i.ignore(10, '\n');
	cout <<"Enter in any historical information or sories. \n";
	i >>history_story;
	i.ignore(1000, '\n');
	n.medals = new char[strlen(medal_type) + 1];
	strcpy(n.medals, medal_type);
	n.history = new char[strlen(history_story) + 1];
	strcpy(n.history, history_story);
	return i;
}


ostream & operator<<(ostream & o, const athlete & a)
{
	a.display_wrap(o);
	return o;
}


istream & operator>>(istream & i, athlete & a)
{
	char temp_name[30];
	char temp_events[100];
	if(a.name)
		delete [] a.name;
	if(a.events)
		delete [] a.events;
	cout <<"Enter in the athlete's name. \n";
	i>>temp_name;
	cout <<"Enter in the athlete's events. \n";
	i>>temp_events;
	a.name = new char[strlen(temp_name) + 1];
	strcpy(a.name, temp_name);
	a.events = new char[strlen(temp_events) + 1];
	strcpy(a.events, temp_events);	
	do{
		a.add_history_wrap();
	}while(a.continue_add());
	return i;
}


//The next largwe amount of fcuntions are the relations operator overloading functions
//for the athlete class and its cooresponding node class
bool operator<(const athlete & a, const athlete & b)
{
	return (strcmp(a.name, b.name) < 0);
}



bool operator<(char * s, const athlete & a)
{
	return (strcmp(s, a.name) < 0);
}


bool operator<(const athlete & a, char * s)
{
	return (strcmp(a.name, s) <0);
}



bool operator!=(const athlete & a, const athlete & b)
{
	return !(a.name == b.name);
}


bool operator!=(char * s, const athlete & a)
{
	return !(s == a.name);
}


bool operator!=(const athlete & a, char * s)
{
	return !(a.name == s);
}


bool operator==(const athlete & a, const athlete & b)
{
	if(strcmp(a.name, b.name) == 0)
		return 1;
	else
		return 0;
}


bool operator==(char * s, const athlete & a)
{
	if(strcmp(s, a.name) == 0)
		return 1;
	else
		return 0;
}


bool operator==(const athlete & a, char * s)
{
	if(strcmp(a.name, s) == 0)
		return 1;
	else
		return 0;
}


bool operator>(const athlete & a, const athlete & b)
{
	return (strcmp(a.name, b.name) > 0);
}


bool operator>(const athlete & a, char * s)
{
	return (strcmp(a.name, s) > 0);
}


bool operator>(char * s, const athlete & a)
{
	return (strcmp(s, a.name) > 0);
}


bool operator<=(const athlete & a, const athlete & b)
{
	return (strcmp(a.name, b.name) <= 0);
}


bool operator<=(const athlete & a, char * s)
{
	return (strcmp(a.name, s) <= 0);	
}


bool operator<=(char * s, const athlete & a)
{
	return (strcmp(s, a.name) <= 0);
}


bool operator>=(const athlete & a, const athlete & b)
{
	return (strcmp(a.name, b.name) >= 0);
}


bool operator>=(const athlete & a, char * s)
{
	return (strcmp(a.name, s) >= 0);
}


bool operator>=(char * s, const athlete & a)
{
	return (strcmp(s, a.name) >= 0);
}


athlete_node& athlete_node :: operator=(const athlete_node & a)
{
	if(this == &a)
		return *this;
	person = a.person;
	return *this;
}


/********************************************
	The next large amoutn of 
	functions are the overloaded
	operator functions for the 
	athlete class	
********************************************/


sport& sport :: operator=(const sport & s)
{
	if(this == &s)
		return *this;
	copy_list(s.head, head);
	return *this;
}





ostream&operator<<(ostream & o, const athlete_node & a)
{
	o << a.person;
	return o;
}


istream & operator>>(istream & i, athlete_node & a)
{
	i >>a.person;
	return i;
}


bool operator!=(const athlete_node & a, const athlete_node & b)
{
	return !(b.person == a.person);	
}


bool operator!=(const athlete_node & an, const athlete & a)
{
	return !(an.person == a);
}


bool operator!=(const athlete & a, const athlete_node & an)
{
	return !(a == an.person);
}


bool operator==(const athlete_node & a, const athlete_node & b)
{
	if(b.person == a.person)
		return 1;
	else
		return 0;	
}


bool operator==(const athlete_node & an, const athlete & a)
{
	if(an.person == a)
		return 1;
	else
		return 0;
}


bool operator==(const athlete & a, const athlete_node & an)
{
	if(a == an.person)
		return 1;
	else
		return 0;
}


bool operator<(const athlete_node & a, const athlete_node & b)
{
	return(a.person < b.person);	
}


bool operator<(const athlete & a, const athlete_node & an)
{
	return(a < an.person);
}


bool operator<(const athlete_node & an, const athlete & a)
{
	return(an.person < a);
}


bool operator>(const athlete_node & a, const athlete_node & b)
{
	return(a.person > b.person);
}


bool operator>(const athlete & a, const athlete_node & an)
{
	return(a > an.person);
}


bool operator>(const athlete_node & an, const athlete & a)
{
	return(an.person > a);
}


bool operator<=(const athlete_node & a, const athlete_node & b)
{
	return(a.person <= b.person);
}


bool operator<=(const athlete & a, const athlete_node & an)
{
	return(a <= an.person);
}


bool operator<=(const athlete_node & an, const athlete & a)
{
	return(an.person >= a);
}


bool operator>=(const athlete_node & a, const athlete_node & b)
{
	return(a.person >= b.person);
}


bool operator>=(const athlete & a, const athlete_node & an)
{
	return(a >= an.person);
}


bool operator>=(const athlete_node & an, const athlete & a)
{
	return(an.person >= a);
}


/************************************************************
		The next large chunk of code is the
		overloaded operator functions for the
		sports. 
***********************************************************/


ostream & operator<<(ostream & o, const sport & s)
{
	s.display(o);
	return o;
}


istream & operator >> (istream & i, sport & s)
{
	/*char temp_name[100];
	char temp_details[1000];
	char temp_schedule[100];
	char temp_network[100];
	if(s.name)
		delete [] s.name;
	if(s.details)
		delete [] s.details;
	if(s.schedule)
		delete [] s.schedule;
	if(s.network)
		delete [] s.network;
	cout <<"Enter the sport's name. \n";
	i >>temp_name;
	s.name = new char[strlen(temp_name) + 1];
	strcpy(s.name, temp_name);
	cout <<"Enter the sport description. \n";
	i >>temp_details;
	s.details = new char[strlen(temp_details) + 1];
	strcpy(s.details, temp_details);
	cout <<"Enter in the sport's schedule. \n";
	i >>temp_schedule;
	s.schedule = new char[strlen(temp_schedule) + 1];
	strcpy(s.schedule, temp_schedule);
	cout <<"Enter in the network this sport will be broadcasted on. \n";
	i >>temp_network;
	s.network = new char[strlen(temp_network) + 1];
	strcpy(s.network, temp_network);
	s.add_athlete_wrap();*/
	s.recieve_data();
	return i;
}


bool operator!=(const sport & s, const sport & sn)
{
	return !(s.head == sn.head);
}


bool operator!=(char * w, const sport & s)
{
	return !(w == s);	
}


bool operator!=(const sport & s, char * w)
{
	return !(s == w);
}


bool operator==(const sport & s, const sport & s2)
{
	if(s.head == s2.head)
		return 1;
	else
		return 0;	
}


bool operator==(char * w, const sport & s)
{
	if(strcmp(w, s.name) == 0)
		return 1;
	else
		return 0;
}


bool operator==(const sport & s, char * w)
{
	if(strcmp(s.name, w) == 0)
		return 1;
	else
		return 0;
}


bool operator<(const sport & s, const sport & s2)
{
	return (strcmp(s.name, s2.name) < 0);
}


bool operator<(char * w, const sport & s)
{
	return (strcmp(w,s.name) < 0);
}


bool operator<(const sport & s, char * w)
{
	return (strcmp(s.name,w) < 0);
}


bool operator>(const sport & s, const sport & s2)
{
	return (strcmp(s.name, s2.name) > 0);
}


bool operator>(char * w, const sport & s)
{
	return (strcmp(w, s.name) > 0);
}


bool operator>(const sport & s, char * w)
{
	return (strcmp(s.name, w) > 0);
}


bool operator<=(const sport & s, const sport & s2)
{
	return (strcmp(s.name, s2.name) <= 0);
}


bool operator<=(char * w, const sport & s)
{	
	return (strcmp(w, s.name) <= 0);
}


bool operator<=(const sport & s, char * w)
{
	return (strcmp(s.name, w) <= 0);
}


bool operator>=(const sport & s, const sport & s2)
{
	return (strcmp(s.name, s2.name) >= 0);
}


bool operator>=(char * w, const sport & s)
{	
	return (strcmp(w, s.name) >= 0);
}


bool operator>=(const sport & s, char * w)
{	
	return (strcmp(s.name, w) >= 0);
}

/**********************************************************
		the next large chunk of
		code is for the single 
		derived class.  most of it is
		essentially copied from the base class
***********************************************************/


bool operator==(const single & s, const single & s2)
{
	if(s.players == s2.players) 
		return 1;	
	else
		return 0;
}


bool operator==(int i, const single & s)
{
	if(i == s)
		return 1;	
	else
		return 0;
}


bool operator==(const single & s, int i)
{
	if(s == i)
		return 1;
	else
		return 0;
}

single & single :: operator=(const single & s)
{
	if(this == &s)
		return *this;
	else
	{
		players = s.players;
		this -> sport::operator=(s);
		return *this;
	}
}


ostream & operator<<(ostream & o, const single & s)
{
	s.display(o);
	return o;
}


istream & operator>>(istream & i, single & s)
{
	cout <<"Enter in the number of participants. \n\n";
	i >>s.players;
	i.ignore(100, '\n');
	
	s.sport::recieve_data();
	return i;
}


single & single :: operator+=(const single & s)
{
	players = players + s.players;
	return *this;
}


single operator+(const single & s, const single & s2)
{
	int i = s.players + s2.players;
	return single(i);
}


single operator+(const single & s, int i)
{
	i += s.players;
	return single(i);	
}


single operator+(int i, const single & s)
{
	i += s.players;
	return single(i);	
}


bool operator<(const single & s, const single & s2)
{
	return (s.players < s2.players);
}


bool operator<(int i, const single & s)
{
	return (i < s.players);
}


bool operator<(const single & s, int i)
{
	return (s.players < i);
}


bool operator>(const single & s, const single & s2)
{
	return (s.players > s2.players);
}


bool operator>(int i, const single & s)
{
	return (i > s.players);
}


bool operator>(const single & s, int i)
{
	return (s.players > i);
}


bool operator<=(const single & s, const single & s2)
{
	return (s.players <= s2.players);
}


bool operator<=(int i, const single & s)
{	
	return (i <= s.players);
}


bool operator<=(const single & s, int i)
{
	return (s.players <= i);
}


bool operator>=(const single & s, const single & s2)
{
	return (s.players >= s2.players);
}


bool operator>=(int i, const single & s)
{	
	return (i >= s.players);
}


bool operator>=(const single & s, int i)
{	
	return (s.players >= i);
}


bool operator!=(const single & s, const single & sn)
{
	return !(s == sn);
}

bool operator!=(int i, const single & s)
{
	return !(i == s.players);	
}


bool operator!=(const single & s, int i)
{
	return !(s.players == i);
}


/*****************************************************************
		The next chunk of code is 
		the overloaded functions for the team
		derived class.  it is essentially copied
		from the single class
*****************************************************************/

bool operator==(const team & s, const team & s2)
{
	if(s.teams == s2.teams) 
		return 1;	
	else
		return 0;
}


bool operator==(int i, const team & s)
{
	if(i == s)
		return 1;	
	else
		return 0;
}


bool operator==(const team & s, int i)
{
	if(s == i)
		return 1;
	else
		return 0;
}

team & team :: operator=(const team & s)
{
	if(this == &s)
		return *this;
	else
	{
		teams = s.teams;
		this -> sport::operator=(s);
		return *this;
	}
}


ostream & operator<<(ostream & o, const team & s)
{
	s.display(o);
	return o;
}


istream & operator>>(istream & i, team & s)
{
	cout <<"Enter in the number of teams participating. \n\n";
	i >>s.teams;
	i.ignore(100, '\n');
	s.sport::recieve_data();
	return i;
}


team & team :: operator+=(const team & s)
{
	teams = teams + s.teams;
	return *this;
}


team operator+(const team & s, const team & s2)
{
	int i = s.teams + s2.teams;
	return team(i);
}


team operator+(const team & s, int i)
{
	i += s.teams;
	return team(i);	
}


team operator+(int i, const team & s)
{
	i += s.teams;
	return team(i);	
}


bool operator<(const team & s, const team & s2)
{
	return (s.teams < s2.teams);
}


bool operator<(int i, const team & s)
{
	return (i < s.teams);
}


bool operator<(const team & s, int i)
{
	return (s.teams < i);
}


bool operator>(const team & s, const team & s2)
{
	return (s.teams > s2.teams);
}


bool operator>(int i, const team & s)
{
	return (i > s.teams);
}


bool operator>(const team & s, int i)
{
	return (s.teams > i);
}


bool operator<=(const team & s, const team & s2)
{
	return (s.teams <= s2.teams);
}


bool operator<=(int i, const team & s)
{	
	return (i <= s.teams);
}


bool operator<=(const team & s, int i)
{
	return (s.teams <= i);
}


bool operator>=(const team & s, const team & s2)
{
	return (s.teams >= s2.teams);
}


bool operator>=(int i, const team & s)
{	
	return (i >= s.teams);
}


bool operator>=(const team & s, int i)
{	
	return (s.teams >= i);
}


bool operator!=(const team & s, const team & sn)
{
	return !(s == sn);
}

bool operator!=(int i, const team & s)
{
	return !(i == s.teams);	
}


bool operator!=(const team & s, int i)
{
	return !(s.teams == i);
}

