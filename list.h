//Joseph Starr, CS 202, Program #3
//This file contains the main data structure class
//declaration and its cooresponding prototypes.


#include "sports.h"



class tree_node
{
	public:
		tree_node();
		~tree_node();
		tree_node(const tree_node&);
		tree_node *& go_right();
		tree_node *& go_left();
		tree_node *& go_middle();
		tree_node *& go_parent();
		void connect_right(tree_node * to_connect);	
		void connect_left(tree_node * to_connect);	
		void connect_middle(tree_node * to_connect);	
		void connect_parent(tree_node * to_connect);
		void create_left_sport(int i);
		void create_temp_sport(int i);
		void create_right_sport(int i);
		bool is_less_left(char * sport_name);
		bool is_greater_right(char * sport_name);
		sport *& get_left_sport();
		sport *& get_right_sport();
		sport *& get_temp_sport();
		void connect_left_sport(sport * to_connect);
		void connect_right_sport(sport * to_connect);
		void display() const;
		int what_type(const sport & source);
		void connect_temp_sport(sport * to_connect);
		void set_flag(int);
		int which_side();
		char * get_name_left();
		char * get_name_right();
		char * get_name_temp();
		int create_cast(const sport & source);
		void which_split(tree_node *& root, tree_node *& parent, char * sport_name, int menu_choice);
	private:
		int flag;
		tree_node * parent;
		tree_node * right;
		tree_node * middle;
		tree_node * left;
		sport * right_sport;
		sport * left_sport;
		sport * temp_sport;
};


class list
{
	public:
		list();
		~list();
		list(const list&);
		void add_sport(char *, int);
		void display() const;
	private:
		void delete_list(tree_node *& root);
		void display_list(tree_node * root) const;
		void add_new_sport(tree_node *& root, tree_node *& parent, char *, int);
		tree_node * root;
};


/******************************************************************************
				Below is the binary tree
*******************************************************************************/



/*class tree_node
{
	public:
		tree_node();
		tree_node(const tree_node&);
		~tree_node();	
		tree_node & operator=(const tree_node&);
		tree_node *& go_left();
		tree_node *& go_right();
		void connect_left(tree_node * to_connect);
		void connect_right(tree_node * to_connect);
		void display() const;
		void create_type(int i);
		bool is_less(char * sport_name);
	private:
		tree_node * right;
		tree_node * left;
		sport * type;
};


class list
{
	public:
		list();
		list(const list&);
		~list();
		list & operator=(const list&);
		void display() const;
		void add_sport(char *, int);
	private:
		void delete_list(tree_node *& root);
		void add_new_sport(tree_node *& root, int, char*);
		void display_list(tree_node * root) const;
		void copy(tree_node * source, tree_node *& root);
		tree_node * root;
};*/


void menu(char *& sport_name, int & menu_choice);
void type_menu(int & menu_choice);

