//Joseph Starr, CS202, Program #3
//This file contains the class dec. for the athlete class.  THis is in its own
//file to keep the program organized and easy to read


#include <cctype>
#include <cstring>
#include <iostream>
#include <fstream>
using namespace std;


//This is the node class contianed in the athlete class.  it contains
//the medal hitory for each athlete
class node_history
{
	public:
		node_history();
		node_history(const node_history&);
		~node_history();	
		node_history *& go_next();
		node_history&operator=(const node_history&);
		friend ostream&operator<<(ostream & , const node_history&);
		friend istream&operator>>(istream&, node_history&);
		void display() const;
		void connect_next(node_history * to_connect);
	private:
		void copy_node(const node_history&);
		char * medals;
		char * history;
		node_history * next;
};


//This is the athlete class.  it contains the information for each athlete entered in
class athlete
{
	public:
		athlete();
		athlete(const athlete&);
		~athlete();
		athlete&operator=(const athlete&);
		friend ostream&operator<<(ostream & , const athlete&);
		friend istream&operator>>(istream&, athlete&);
		friend bool operator!=(const athlete&, const athlete&);
		friend bool operator!=(char*, const athlete&);
		friend bool operator!=(const athlete&, char*);
		friend bool operator==(const athlete&, const athlete&);
		friend bool operator==(char*, const athlete&);
		friend bool operator==(const athlete&, char*);
		friend bool operator<(const athlete&, const athlete&);
		friend bool operator<(char*, const athlete&);
		friend bool operator<(const athlete&, char*);
		friend bool operator>(const athlete&, const athlete&);
		friend bool operator>(char*, const athlete&);
		friend bool operator>(const athlete&, char*);
		friend bool operator<=(const athlete&, const athlete&);
		friend bool operator<=(char*, const athlete&);
		friend bool operator<=(const athlete&, char*);
		friend bool operator>=(const athlete&, const athlete&);
		friend bool operator>=(char*, const athlete&);
		friend bool operator>=(const athlete&, char*);
		void display_wrap(ostream & out) const;
		void add_history_wrap();
		bool continue_add();
	private:
		node_history *& return_head(node_history *& head);
		void add_history(node_history *& head);
		void display(node_history * head, ostream & out) const;
		void copy_this(const athlete&);
		void delete_list(node_history *&);
		void copy_list(node_history *, node_history *&);
		char * name;
		char * events;
		node_history * head;
		
};
