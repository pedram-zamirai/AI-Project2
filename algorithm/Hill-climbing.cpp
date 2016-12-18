#include <iostream>
#include "../problem/8queen.cpp"

using namespace std;

class algorithm{
public:
	problem p;
	node current, next, neighbour;
	void run();
};

void algorithm::run(){
	current = p.set_initialstate();
	int curr_score;
	while(1){
		curr_score = current.score;
		for(int i=0; p.is_neighbour(i); i++){
			neighbour = p.neighbour(current, i);
			if(curr_score < neighbour.score){
					next = neighbour;
					curr_score = neighbour.score;

			}
		}
		if(current.score == curr_score)
			break;
		current = next;
	}
	p.print_sol();
	
}

int main(){
	algorithm hill;
	hill.run();
	return 0;
}
