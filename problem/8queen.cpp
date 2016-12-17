
struct node{
	int score;
	node* parent;
	int map[8];
};
class problem{
public:
	node set_initialstate();
	int eval(node);
	node neighbour(node, int);
	bool is_neighbour(int);
	void print_sol();
};
