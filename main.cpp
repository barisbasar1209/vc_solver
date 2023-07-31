#include<list>
#include<string>
#include<iostream> 
#include"Graph.h"

int main(){
	Vertex v1("v1"); 
	std::list<Vertex> lst; 
	lst.push_back(v1); 
	Vertex v2("v2", lst); 
	v1.neighbors.push_back(v2); 
	v1.degree++;  
	lst.push_back(v2); 
	Vertex v3("v3", lst); 
	v1.neighbors.push_back(v3); 
	v2.neighbors.push_back(v3); 
	v1.degree++; 
	v2.degree++; 
	v1.print_vertex(); 
	v2.print_vertex(); 
	v3.print_vertex(); 

	Edge e1(v1,v2); 
	Edge e2(v2,v3); 
	Edge e3(v1,v3); 
	e1.print_edge(); 
	e2.print_edge();
	e3.print_edge(); 
	return 0; 
}
