#include <vector>

using namespace std;

class node{
public:
	int score, tag;
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
	void print_sol(node);
	void print_state(node);
	int find_node(node);
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
	n.tag=0;
	nodes.push_back(n);
	return n;
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

node problem::neighbour(node n, int i){
	node neighbour;
	int state[8];
	for(int j=0;j<8;j++)
		state[j] = n.map[j];
	state[n.tag] = (n.map[n.tag] + i) % 8;
	neighbour.set_map(state);
	neighbour.score = eval(neighbour);
	neighbour.tag = n.tag + 1;
	nodes.push_back(neighbour);
	neighbour.parent = &nodes[find_node(n)];
	return neighbour;
}

bool problem::is_neighbour(int i){
	if(i>8)
		return false;
	return true;
}

void problem::print_sol(node end){
	int cnt=1;
	cout<<"Solution score:"<<end.score<<endl;
	while(end.tag!=1){
		cout<<end.tag<<":\n";
		print_state(end);
		cout<<endl;
		end = *(end.parent);
		cnt++;
	}
	cout<<end.tag<<":\n";
	print_state(end);
	cout<<endl<<"0:\n";
	print_state(nodes[0]);
	cout<<endl<<"Total created nodes:"<<nodes.size();
	cout<<endl<<"Total expanded nodes:"<<cnt<<endl;

}

void problem::print_state(node n){
	for(int i=7;i>=0;i--){
		for(int j=0;j<8;j++){
			if(n.map[j]==i)
				cout<<"* ";
			else
				cout<<"- ";
		}
		cout<<endl;
	}
}

int problem::find_node(node n){
	int count=0;
	for(int i=0;i<nodes.size();i++){
		for(int j=0;j<8;j++){
			if(n.map[j]==nodes[i].map[j])
				count++;
			else 
				break;
		}
		if(count == 8)
			return i;
		count = 0;
	}
}
