#include <iostream>
#include "../problem/8queen.cpp"

using namespace std;

class algorithm{
public:
	problem p;
	node current, next;
	void run();
};

void algorithm::run(){
	current = p.set_initialstate();
	int curr_score;
	while(1){
		curr_score = current.score;
		for(int i=0; p.is_neighbour(i); i++){
			if(curr_score < p.neighbour(current,i).score){
					next = p.neighbour(current, i);
					curr_score = p.neighbour(current,i).score;

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
