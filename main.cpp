#include<list>
#include<string>
#include<iostream> 
#include<vector>
#include"Solver.h"

int main(){
		
	// stargraph with v3 as the center
	std::vector<int>matrix0 = {0b0001,0b0001,0b0001,0b1110}; 
	// expected : G = ({v0,v1,v2,v3},{{v0,v3},{v1,v3},{v2,v3}})
	Graph G(matrix0);
	std::cout<<"printing stargraph"<<std::endl; 
	G.print_graph(); 
	
	// K6
	std::vector<int>matrix1 = {0b011111,0b101111,0b110111,0b111011,0b111101,0b111110}; 
	Graph H(matrix1); 
	std::cout<<"printing K6"<<std::endl; 
	H.print_graph(); 
	std::cout<<"reducing K6 to K5"<<std::endl; 
	Vertex *v = H.V.front(); 
	H.delete_vertex(v); 
	std::cout<<"printing K5"<<std::endl; 
	H.print_graph(); 
	std::cout<<"RETURNING"<<std::endl; 
	return 0; 
}

// should myself a function that converts an adjacency matrix into a graph
