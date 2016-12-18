#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "../problem/8queen.cpp"

using namespace std;

class algorithm{
public:
	problem p;
	node current, neighbour;
	vector<node> next;
	void run();
};

void algorithm::run(){
	srand(time(NULL));
	current = p.set_initialstate();
	int curr_score;
	while(true){
		curr_score = current.score;
		next.resize(0);
		for(int i=1; p.is_neighbour(i); i++){
			neighbour = p.neighbour(current, i);
			if(curr_score < neighbour.score){
				next.clear();
				next.push_back(neighbour);
				curr_score = neighbour.score;

			}
			else if(curr_score == neighbour.score)
				next.push_back(neighbour);
		}
		if(current.score == curr_score){
			if(curr_score == 0)
				break;
			else{
				current = p.nodes[rand() % p.nodes.size()];
				p.nodes.clear();
				current.tag=0;
				current.parent=NULL;
				p.nodes.push_back(current);
				continue;
			}
				
		}
		current = next[rand() % next.size()];
	}
	p.print_sol(current);
}

int main(){
	algorithm hill;
	hill.run();
	return 0;
}
