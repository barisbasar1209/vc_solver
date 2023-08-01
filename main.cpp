#include<list>
#include<string>
#include<iostream> 
//#include"Graph.h"
#include"Solver.h"

int main(){

	std::list<Vertex> V; 
	Vertex v1("v1"); 
	V.push_back(v1); 
	Vertex v2("v2", V); 
	v1.neighbors.push_back(v2); 
	v1.degree++;  
	V.push_back(v2); 
	Vertex v3("v3", V); 
	V.push_back(v3); 
	v1.neighbors.push_back(v3); 
	v2.neighbors.push_back(v3); 
	v1.degree++; 
	v2.degree++; 
	Vertex v4("v4"); 
	v4.neighbors.push_back(v3); 
	v4.degree++; 
	v3.degree++; 
	v3.neighbors.push_back(v4); 
	v4.neighbors.push_back(v1); 
	v4.degree++; 
	v1.neighbors.push_back(v4); 
	v1.degree++; 
	Vertex v5("v5"); 
	v5.neighbors.push_back(v1); 
	v5.degree++; 
	v1.neighbors.push_back(v5); 
	v1.degree++; 
	v5.neighbors.push_back(v4); 
	v5.degree++; 
	v4.neighbors.push_back(v5); 
	v4.degree++; 
	V.push_back(v4); 
	V.push_back(v5); 
	/*
	v1.print_vertex(); 
	std::cout<<'\n'; 
	v2.print_vertex(); 
	std::cout<<'\n'; 
	v3.print_vertex(); 
	std::cout<<'\n'; 
	*/	

	Edge e1(v1,v2); 
	Edge e2(v2,v3); 
	Edge e3(v1,v3); 
	Edge e4(v4,v3); 
	Edge e5(v4,v1); 
	Edge e6(v4,v5); 
	Edge e7(v5,v1); 
	/*e1.print_edge(); 
	std::cout<<'\n'; 
	e2.print_edge();
	std::cout<<'\n'; 
	e3.print_edge(); 
	std::cout<<'\n'; */
	
	std::list<Edge> E; 	
	E.push_back(e1); 
	E.push_back(e2); 
	E.push_back(e3); 
	E.push_back(e4); 
	E.push_back(e5); 
	E.push_back(e6); 
	E.push_back(e7); 
	
	Graph G(V,E); 
	//G.print_graph(); 
	
	std::cout<<"k=1: "<<exp_solve(G, 1)<<'\n'; 
	std::cout<<"k=2: "<<exp_solve(G, 2)<<'\n'; 
	std::cout<<"k=3: "<<exp_solve(G, 3)<<'\n'; 
	std::cout<<"k=4: "<<exp_solve(G, 4)<<'\n'; 
	return 0; 
}
