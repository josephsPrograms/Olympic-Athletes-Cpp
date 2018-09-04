//Joseph Starr, CS202, PRogram #3


#include "list.h"


//The follwing functions are the constructors, destructors, and copy constructors for the main data strucutre.
tree_node :: tree_node() : flag(0), parent(NULL), right(NULL), middle(NULL), left(NULL), right_sport(NULL), left_sport(NULL), temp_sport(NULL) {}


tree_node :: ~tree_node()
{
	flag = 0;
	parent = NULL;
	right = NULL;
	middle = NULL;
	left = NULL;
	if(left_sport)
	{
		delete left_sport;
		left_sport = NULL;
	}
	if(right_sport)
	{
		delete right_sport;
		right_sport = NULL;
	}
	if(temp_sport)
	{
		delete temp_sport;
		temp_sport = NULL;
	}
}

//Copy constructor with the use of dynamic casting
tree_node :: tree_node(const tree_node & source)
{
	flag = source.flag;	
	if(source.temp_sport)
	{
		const single * single_event = dynamic_cast<const single*>(source.temp_sport);
		const team * team_event = dynamic_cast<const team*>(source.temp_sport);
		if(single_event)
			temp_sport = new single(*single_event);
		else if(team_event)
			temp_sport = new team(*team_event);
	}
	if(source.right_sport)
	{
		const single * single_event = dynamic_cast<const single*>(source.right_sport);
		const team * team_event = dynamic_cast<const team*>(source.right_sport);
		if(single_event)
			right_sport = new single(*single_event);
		else if(team_event)
			right_sport = new team(*team_event);	
	}
	if(source.left_sport)
	{
		const single * single_event = dynamic_cast<const single*>(source.left_sport);
		const team * team_event = dynamic_cast<const team*>(source.left_sport);
		if(single_event)
			left_sport = new single(*single_event);
		else if(team_event)
			left_sport = new team(*team_event);	
	}
}


list :: list() : root(NULL) {}


list :: ~list()
{
	if(!root)
		root = NULL;
	else
		delete_list(root);
}


void list :: delete_list(tree_node *& root)
{
	if(!root)
		return;
	delete_list(root -> go_left());
	delete_list(root -> go_middle());
	delete_list(root -> go_right());
	if(root)
	{
		delete root;
		root = NULL;
	}
}


//The following functions are purely to give the list class access to its node's
//private data memeber for traversal and connection of nodes
tree_node *& tree_node :: go_right()
{
	return right;
}


tree_node *& tree_node :: go_left()
{
	return left;
}


tree_node *& tree_node :: go_middle()
{
	return middle;
}


tree_node*& tree_node :: go_parent()
{
	return parent;
}


void tree_node :: connect_right(tree_node * to_connect)
{
	right = to_connect;
}


void tree_node :: connect_left(tree_node * to_connect)
{
	left = to_connect;
}


void tree_node :: connect_middle(tree_node * to_connect)
{
	middle = to_connect;
}


//The next two functions are used to compare data in the tree
//to the correct direction of traversal is performed
bool tree_node :: is_less_left(char * sport_name)
{
	if(sport_name < *left_sport)
		return 1;
	else
		return 0;
}


bool tree_node :: is_greater_right(char * sport_name)
{
	if(sport_name > *right_sport)
		return 1;
	else
		return 0;
}

//The next three functions create the proper port tyep within the node class
void tree_node :: create_temp_sport(int i)
{
	if(i == 1)
	{
		single * single_event = new single;
		temp_sport = single_event;
		//single * single_event = dynamic_cast<single*>(temp_sport);
		cin >>*single_event;
		//cin >> *temp_sport;
		return;
	}
	else
	{
		team * team_event = new team;
		temp_sport = team_event;
		//team * team_event = dynamic_cast<team*>(left_sport);
		cin >>*team_event;
		//cin >>*temp_sport;
		return;
	}	
}


void tree_node :: create_left_sport(int i)
{
	if(i == 1)
	{
		single * single_event = new single;
		left_sport = single_event;
		//single * single_event = dynamic_cast<single*>(temp_sport);
		cin >>*single_event;
		//cin >> *temp_sport;
		return;
	}
	else
	{
		team * team_event = new team;
		left_sport = team_event;
		//team * team_event = dynamic_cast<team*>(left_sport);
		cin >>*team_event;
		//cin >>*temp_sport;
		return;
	}	
}


void tree_node :: create_right_sport(int i)
{
	if(i == 1)
	{
		single * single_event = new single;
		right_sport = single_event;
		//single * single_event = dynamic_cast<single*>(temp_sport);
		cin >>*single_event;
		//cin >> *temp_sport;
		return;
	}
	else
	{
		team * team_event = new team;
		right_sport = team_event;
		//team * team_event = dynamic_cast<team*>(left_sport);
		cin >>*team_event;
		//cin >>*temp_sport;
		return;
	}	
}


/*int tree_node :: create_cast(const sport & source)
{
	const single * single_event = dynamic_cast<const single*>(&source);
	const team * team_event = dynamic_cast<const team*>(&source);
	if(single_event)
		return 1;
	else if(team_event)
		return 2;	
	else
		return 0;
		
}*/


//This function sets the node classes flag use when nodes are split
void tree_node :: set_flag(int i)
{
	flag = i;	
}


//The following functions are used to access or connect the proper data in the 
//node's private section when the list class needs it done.  the data is the 
//sport hierarchy
sport *& tree_node :: get_left_sport()
{
	return left_sport;
}


sport *& tree_node :: get_right_sport()
{
	return right_sport;
}


sport *& tree_node :: get_temp_sport()
{
	return temp_sport;
}


void tree_node :: connect_left_sport(sport * to_connect)
{
	left_sport = to_connect;
}


void tree_node :: connect_right_sport(sport * to_connect)
{
	right_sport = to_connect;
}

void tree_node :: connect_parent(tree_node * to_connect)
{
	parent = to_connect;
}


void tree_node :: connect_temp_sport(sport * to_connect)
{
	temp_sport = to_connect;
	to_connect = NULL;
}


//This function is used by the insertion function of the 2-3 tree
//to find the proper node to point to when split
int tree_node :: which_side()
{
	if(right && right -> middle -> flag == 1)
		return 1;
	else if(middle && middle -> middle -> flag == 1)
		return 2;
	else if(left && left -> middle -> flag == 1)
		return 3;
	else
		return 0;

}


//This is the wrapper insertion function for the 2-3 tree
void list :: add_sport(char * sport_name, int menu_choice)
{
	if(!root)
	{
		root = new tree_node;
		root -> create_left_sport(menu_choice);
		return;
	}
	else
		add_new_sport(root, root, sport_name, menu_choice);
}


//this is the insertion function for the 2-3 tree
void list :: add_new_sport(tree_node *& root, tree_node *& parent, char * sport_name, int menu_choice)
{
	if(!root)
	{
		root = new tree_node;
		root -> connect_parent(parent);
		root -> create_left_sport(menu_choice);	
		return;
	}
	if(!root -> go_left() && !root -> go_right() && !root -> go_middle())//Here insertion occurs when a leaf is accessed
	{
		if(!root -> get_right_sport())//INsertion in a leaf when there is room
		{
			if(!root -> is_less_left(sport_name)) 
			{
				root -> create_right_sport(menu_choice);	
				root -> connect_parent(parent);
				return;
			}
			else
			{
				root -> connect_right_sport(root -> get_left_sport());
				root -> create_left_sport(menu_choice);		
				return;
			}
		}
		else
		{//Insertino is a leaf when there is no room
			if(root -> is_less_left(sport_name))
			{
				parent -> connect_temp_sport(root -> get_left_sport());//PArent recieves the data being puched up
				root -> connect_left_sport(root -> get_right_sport());//The following is the splitting of root
				root -> connect_right_sport(NULL);
				tree_node * temp = new tree_node;
				temp -> create_left_sport(menu_choice);
				temp -> set_flag(1);//Temp is the flagged node that this roots parent will point to
				root -> connect_middle(temp);//The flagged node is connected to the leafs middle for easy acces by the parent
				return;	
			}	
			else if(root -> is_greater_right(sport_name))//The next two conditions are for when the data coming in is greater than the
			{//right data, and when it is the middle data
				parent -> connect_temp_sport(root -> get_right_sport());//Right data gets pushed up
				tree_node * temp = new tree_node;
				temp -> create_left_sport(menu_choice);
				temp -> set_flag(1);
				root -> connect_middle(temp);
				return;	
			}
			else
			{
				parent -> create_temp_sport(menu_choice);//data coming in is pushed up
				tree_node * temp = new tree_node;
				temp -> connect_left_sport(root -> get_left_sport());
				root -> connect_left_sport(root -> get_right_sport());
				root -> get_right_sport() = NULL;
				temp -> set_flag(1);
				root -> connect_middle(temp);
				return;	
			}
		}	
	}
	if(root -> is_less_left(sport_name))
		add_new_sport(root -> go_left(), parent, sport_name, menu_choice);
	else if(root -> is_greater_right(sport_name))
		add_new_sport(root -> go_right(), parent, sport_name, menu_choice);
	else
		add_new_sport(root -> go_middle(), parent, sport_name, menu_choice);
	int which = root -> which_side();//This function is called to fiund where the split node is
	if(which == 1)//The split node is the middle child of roots right child
	{
		if(root -> is_less_left(root -> get_name_temp()))//These if else send up the middle data to the parent
			root -> go_parent() -> connect_temp_sport(root -> get_left_sport());
		else if(root -> is_greater_right(root -> get_name_temp()))
			root -> go_parent() -> connect_temp_sport(root -> get_right_sport());
		else 
			root -> go_parent() -> connect_temp_sport(root -> get_temp_sport());	
		tree_node * temp = new tree_node;//The node is split and temp/root point to their new/moved childern
		temp -> connect_left(root -> go_left());
		temp -> connect_right(root -> go_middle());
		root -> connect_left(root -> go_right() -> go_middle());
		root -> connect_temp_sport(NULL);
	}
	else if(which == 2)//The split node is the middle child of roots middle child
	{
		if(root -> is_less_left(root -> get_name_temp()))
			root -> go_parent() -> connect_temp_sport(root -> get_left_sport());
		else if(root -> is_greater_right(root -> get_name_temp()))
			root -> go_parent() -> connect_temp_sport(root -> get_right_sport());
		else 
			root -> go_parent() -> connect_temp_sport(root -> get_temp_sport());	
		tree_node * temp = new tree_node;//The node is split and temp/root point to their new/moved childern
		temp -> connect_left(root -> go_left());
		temp -> connect_right(root -> go_middle() -> go_middle());
		root -> connect_left(root -> go_middle());
		root -> connect_middle(NULL);
		root -> connect_temp_sport(NULL);

	}
	else if(which == 3)//The split node is the middle child of root's left child
	{
		if(root -> is_less_left(root -> get_name_temp()))
			root -> go_parent() -> connect_temp_sport(root -> get_left_sport());
		else if(root -> is_greater_right(root -> get_name_temp()))
			root -> go_parent() -> connect_temp_sport(root -> get_right_sport());
		else 
			root -> go_parent() -> connect_temp_sport(root -> get_temp_sport());	
		tree_node * temp = new tree_node;//The node is split and temp/root point to their new/moved childern
		temp -> connect_left(root -> go_left() -> go_left());
		temp -> connect_right(root -> go_middle());
		root -> connect_left(root -> go_middle());
		root -> connect_middle(NULL);	
		root -> connect_temp_sport(NULL);
	}
}


//The next three functions recieve the name of the sport being compared, used in the list class
char * tree_node :: get_name_left()
{
	return left_sport -> give_name();
}


char * tree_node :: get_name_right()
{
	return right_sport -> give_name();
}


char * tree_node :: get_name_temp()
{
	return temp_sport -> give_name();
}


//The next three functions display the 2-3 tree
void list :: display() const
{
	if(!root)
	{
		cout <<"There is nothing to display. \n\n";
		return;
	}
	else
		display_list(root);
}


void list :: display_list(tree_node * root) const
{
	if(!root)
		return;
	root -> display();
	display_list(root -> go_left());
	display_list(root -> go_right());
	display_list(root -> go_middle());
}


void tree_node :: display() const
{
	if(left_sport)
		cout <<*left_sport <<"\n\n";
	if(right_sport)
		cout <<*right_sport <<"\n\n";
}

/****************************************************************************************************
				Below is the code for abinary tree
				it was implemented for the event that
				I could not get a working 2-3 tree done
*****************************************************************************************************/




/*tree_node :: tree_node() : right(NULL), left(NULL), type(NULL)
{
}

tree_node :: tree_node(const tree_node & t)
{
	if(!t.type)
		type = NULL;
}


tree_node :: ~tree_node()
{
	right = NULL;
	left = NULL;
	if(type)
		delete type;
}


list :: list() : root(NULL)
{
}


list :: list(const list & l)
{
	if(!root)
		root = NULL;
}


list :: ~list()
{
	if(!root)
		root = NULL;
	else
		delete_list(root);
}


void list :: delete_list(tree_node *& root)
{
	if(!root)
		return;
	delete_list(root -> go_left());
	delete_list(root -> go_right());
	if(root)
	{
		delete root;
		root = NULL;
	}
}


void list :: copy(tree_node * source, tree_node *& root)
{
	if(!source)
	{
		root = NULL;
		return;
	}
	root = new tree_node(*source);
	copy(source -> go_left(), root -> go_left());
	copy(source -> go_right(), root -> go_right());
}


tree_node *& tree_node :: go_left()
{
	return left;
}


tree_node *& tree_node :: go_right()
{
	return right;
}


void tree_node :: connect_left(tree_node * to_connect)
{
	left = to_connect;
}


void tree_node :: connect_right(tree_node * to_connect)
{
	right = to_connect;
}


void tree_node :: display() const
{
	cout <<*type;
}
	

bool tree_node :: is_less(char * sport_name)
{
	if(sport_name < *type)
		return 1;
	else
		return 2;
}


void list :: display() const
{
	if(!root)
	{
		cout <<"There is nothing to display. \n\n";
		return;
	}
	else
	{	
		display_list(root);
		return;
	}
}


void list :: display_list(tree_node * root) const
{
	if(!root)
		return;
	else
		root -> display();
	display_list(root -> go_right());
	display_list(root -> go_left());
}


void tree_node :: create_type(int i)
{
	if(i == 1)
	{
		type = new single;
		single * single_event = dynamic_cast<single*>(type);
		cin >>*single_event;
		return;
	}
	else
	{
		type = new team;
		team * team_event = dynamic_cast<team*>(type);
		cin >>*team_event;
		return;
	}	
}


void list :: add_sport(char * sport_name, int menu_choice)
{
	if(!root)
	{
		root = new tree_node;
		root -> create_type(menu_choice);
		return;
	}
	else
	{
		add_new_sport(root, menu_choice, sport_name);
	}	
}


void list :: add_new_sport(tree_node *& root, int menu_choice, char * sport_name)
{
	if(!root)
		return;
	if(root -> is_less(sport_name))
	{
		if(!root -> go_left())
		{
			tree_node * temp = new tree_node;
			temp -> create_type(menu_choice);
			temp -> connect_left(NULL);
			temp -> connect_right(NULL);
			root -> connect_left(temp);
			return;
		}
		else
			add_new_sport(root -> go_left(), menu_choice, sport_name);
	}
	else
	{
		if(!root -> go_right())
		{
			tree_node * temp = new tree_node;
			temp -> connect_right(NULL);
			temp -> connect_left(NULL);
			root -> connect_right(temp);
			return;
		}
		else
			add_new_sport(root -> go_right(), menu_choice, sport_name);
	}
}


list & list :: operator=(const list & l)
{
	if(this == &l)
		return *this;
	else
	{
		delete_list(root);
		this -> copy(l.root, root);
		return *this;
	}
	
}*/
	





