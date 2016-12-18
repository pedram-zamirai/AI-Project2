#include <vector>

using namespace std;

class node{
public:
	int score;
	node* parent;
	int map[8];
	void set_map(int[]);
};
class problem{
public:
	vector<node> nodes;
	node set_initialstate();
	int eval(node);
	node neighbour(node, int);
	bool is_neighbour(int);
	void print_sol();
};

void node::set_map(int state[]){
	for(int i=0;i<8;i++)
		map[i]=state[i];
}

node problem::set_initialstate(){
	node n;
	int state[8];
	state[0]=0;
	state[1]=0;
	state[2]=0;
	state[3]=0;
	state[4]=0;
	state[5]=0;
	state[6]=0;
	state[7]=0;
	n.set_map(state);
	n.parent = NULL;
	n.score = eval(n);
	nodes.push_back(n);
}

int problem::eval(node n){
	int score=0;
	for(int i=0;i<8;i++){
		for(int j=i+1;j<8;j++){
			if(n.map[i]==n.map[j])
				score--;
			else if(j-i == n.map[j] - n.map[i])
				score--;
			else if(j-i == n.map[i] - n.map[j])
				score--;
		}
	}
	return score;
}
