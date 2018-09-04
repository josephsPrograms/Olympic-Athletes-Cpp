//Joseph Starr, CS 202, Program #3
//This is the .h file for the class decs for the hierarchy.  This is in its own
//file to keep the program organized and reasy to read


#include "athletes.h"


//This is the node class for the athletes contained in the hierarchy.
class athlete_node
{
	public: 
		athlete_node();
		athlete_node(const athlete_node&);
		~athlete_node();
		friend ostream&operator<<(ostream & , const athlete_node&);
		friend istream&operator>>(istream&, athlete_node&);
		athlete_node&operator=(const athlete_node&);
		friend bool operator!=(const athlete_node&, const athlete_node&);
		friend bool operator!=(const athlete_node&, const athlete&);
		friend bool operator!=(const athlete&, const athlete_node&);
		friend bool operator==(const athlete_node&, const athlete_node&);
		friend bool operator==(const athlete_node&, const athlete&);
		friend bool operator==(const athlete&, const athlete_node&);
		friend bool operator<(const athlete_node&, const athlete_node&);
		friend bool operator<(const athlete&, const athlete_node&);
		friend bool operator<(const athlete_node&, const athlete&);
		friend bool operator>(const athlete_node&, const athlete_node&);
		friend bool operator>(const athlete&, const athlete_node&);
		friend bool operator>(const athlete_node&, const athlete&);
		friend bool operator<=(const athlete_node&, const athlete_node&);
		friend bool operator<=(const athlete&, const athlete_node&);
		friend bool operator<=(const athlete_node&, const athlete&);
		friend bool operator>=(const athlete_node&, const athlete_node&);
		friend bool operator>=(const athlete&, const athlete_node&);
		friend bool operator>=(const athlete_node&, const athlete&);
		athlete_node *& go_athlete_next();
		void connect_athlete_next(athlete_node * to_connect);
		void display(ostream & out) const;
	private:
		athlete_node * next;
		athlete person;
};


//This is the base class of the entire hierarchy.  It contains a LLL of athletes as well as the information foe eachsport 
class sport
{
	public: 
		sport();
		sport(const sport&);
		sport(int);
		virtual ~sport();
		virtual void display(ostream & out) const;
		sport&operator=(const sport&);
		friend ostream&operator<<(ostream & , const sport&);
		friend istream&operator>>(istream&, sport&);
		friend bool operator!=(const sport&, const sport&);
		friend bool operator!=(char*, const sport&);
		friend bool operator!=(const sport&, char*);
		friend bool operator==(const sport&, const sport&);
		friend bool operator==(char*, const sport&);
		friend bool operator==(const sport&, char*);
		friend bool operator<(const sport&, const sport&);
		friend bool operator<(char*, const sport&);
		friend bool operator<(const sport&, char*);
		friend bool operator>(const sport&, const sport&);
		friend bool operator>(char*, const sport&);
		friend bool operator>(const sport&, char*);
		friend bool operator<=(const sport&, const sport&);
		friend bool operator<=(char*, const sport&);
		friend bool operator<=(const sport&, char*);
		friend bool operator>=(const sport&, const sport&);
		friend bool operator>=(char*, const sport&);
		friend bool operator>=(const sport&, char*);
		char * give_name();
		void add_athlete_wrap();
		void recieve_data();
		bool continue_input();

	protected:
		athlete_node * head;
	private:
		void add_athlete(athlete_node *& head);
		void display_rec(athlete_node * head, ostream &) const;
		void copy_list(athlete_node * source, athlete_node *& head);
		void delete_nodes(athlete_node *& head);
		char * name;
		char * details;
		char * schedule;
		char * network;
		int rtti;
};


//This is the class for a sport that is for single people instead of teams.  Inheriting from the above sport class
class single : public sport
{
	public:
		single();
		single(const single&);
		single(int);
		~single();
		single&operator=(const single&);
		friend ostream&operator<<(ostream & , const single&);
		friend istream&operator>>(istream&, single&);
		single & operator+=(const single&);
		friend single operator+(const single&, const single&);
		friend single operator+(const single&, int);
		friend single operator+(int, const single&);
		friend bool operator!=(const single&, const single&);
		friend bool operator!=(int, const single&);
		friend bool operator!=(const single&, int);
		friend bool operator==(const single&, const single&);
		friend bool operator==(int, const single&);
		friend bool operator==(const single&, int);
		friend bool operator<(const single&, const single&);
		friend bool operator<(int, const single&);
		friend bool operator<(const single&, int);
		friend bool operator>(const single&, const single&);
		friend bool operator>(int, const single&);
		friend bool operator>(const single&, int);
		friend bool operator<=(const single&, const single&);
		friend bool operator<=(int, const single&);
		friend bool operator<=(const single&, int);
		friend bool operator>=(const single&, const single&);
		friend bool operator>=(int, const single&);
		friend bool operator>=(const single&, int);
		void display(ostream & out) const;
	private:
		int players;
};


//This is the team class for sports that are made of teams.  It inherits from the sport class
class team : public sport
{
	public:
		team();
		team(const team&);
		team(int);
		~team();
		team&operator=(const team&);
		friend ostream&operator<<(ostream & , const team&);
		friend istream&operator>>(istream&, team&);
		team & operator+=(const team&);
		friend team operator+(const team&, const team&);
		friend team operator+(const team&, int);
		friend team operator+(int, const team&);
		friend bool operator!=(const team&, const team&);
		friend bool operator!=(int, const team&);
		friend bool operator!=(const team&, int);
		friend bool operator==(const team&, const team&);
		friend bool operator==(int, const team&);
		friend bool operator==(const team&, int);
		friend bool operator<(const team&, const team&);
		friend bool operator<(int, const team&);
		friend bool operator<(const team&, int);
		friend bool operator>(const team&, const team&);
		friend bool operator>(int, const team&);
		friend bool operator>(const team&, int);
		friend bool operator<=(const team&, const team&);
		friend bool operator<=(int, const team&);
		friend bool operator<=(const team&, int);
		friend bool operator>=(const team&, const team&);
		friend bool operator>=(int, const team&);
		friend bool operator>=(const team&, int);
		void display(ostream & out) const;
	private:
		int teams;
};



