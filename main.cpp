#include<list>
#include<string>
#include<iostream> 
#include<vector>
#include"Solver.h"

int main(){
/*
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
	Edge e1(v1,v2); 
	Edge e2(v2,v3); 
	Edge e3(v1,v3); 
	Edge e4(v4,v3); 
	Edge e5(v4,v1); 
	Edge e6(v4,v5); 
	Edge e7(v5,v1); 
	std::list<Edge> E; 	
	E.push_back(e1); 
	E.push_back(e2); 
	E.push_back(e3); 
	E.push_back(e4); 
	E.push_back(e5); 
	E.push_back(e6); 
	E.push_back(e7); 
	
	Graph G(V,E); // small graph from uni
	
	for(int i=0;i<G.n;i++){
		if (exp_solve(G,i)){
			std::cout<<"found vc of size "<<i<<'\n'; 
			break; 	
		}	
	}	
*/	
	Vertex u1("u1"); 	
	Vertex u2("u2"); 	
	Vertex u3("u3"); 	
	Vertex u4("u4"); 	
	Vertex u5("u5"); 	
	Vertex u6("u6"); 	
	Vertex u7("u7"); 	
	Vertex u8("u8"); 	
	Vertex u9("u9"); 	
	Vertex u10("u10"); 	
	Vertex u11("u11"); 	
	Vertex u12("u12"); 	
	// Graph H with 12 vertices, selfconstructed random graph
	std::vector<Vertex*> u = {&u1,&u2,&u3,&u4,&u5,&u6,&u7,&u8,&u9,&u10,&u11,&u12}; 
	
	Edge f1(&u1,&u2); Edge f2(&u2,&u3); Edge f3(&u2,&u12); Edge f4(&u2,&u11); Edge f5(&u2,&u8); Edge f6(&u2,&u7); Edge f7(&u2,&u6); Edge f8(&u2,&u4); Edge f9(&u3,&u4); 
	Edge f10(&u4,&u11); Edge f11(&u4,&u7); Edge f12(&u4,&u5); Edge f13(&u4,&u6); Edge f14(&u6,&u7); Edge f15(&u6,&u8); Edge f16(&u7,&u8); Edge f17(&u7,&u11); Edge f18(&u8,&u11);
	Edge f19(&u11,&u10); Edge f20(&u11,&u12); Edge f21(&u12,&u9);

	std::vector<Edge> f = {f1,f2,f3,f4,f5,f6,f7,f8,f9,f10,f11,f12,f13,f14,f15,f16,f17,f18,f19,f20,f21}; 

	std::list<Vertex*> U(u.begin(), u.end()); std::list<Edge> F(f.begin(), f.end()); 
	Graph H(U,F);
	
	for(int i=0;i<H.n;i++){
		if (exp_solve(H,i)){
			std::cout<<"found vc of size "<<i<<'\n'; 
			break; 	
		}	
	}	
	return 0; 
}

// should myself a function that converts an adjacency matrix into a graph
