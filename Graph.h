#include<list>
#include<string>
#include<iostream>

// TODO: Test
class Vertex{
	public:
		std::string name=""; 
		int degree=-1; 
		std::list<Vertex> neighbors; 
		Vertex(std::string v_name) : name(v_name){degree=0;}   		
		Vertex(std::string v_name, const std::list<Vertex>& v_neighbors) : name(v_name), neighbors(v_neighbors){degree = neighbors.size();}
		//Vertex(const Vertex& v) name(v.name), degree(v.degree), neighbors(v.neighbors){}
	void print_vertex(){
		std::cout<<"name: "<<name<<'\n'<<"degree: "<<degree<<'\n'; 
		if (!neighbors.empty()){
			for (const Vertex& v : neighbors){
				std::cout<<v.name<<", "; 
			}	
			std::cout<<'\n'; 
		}
	}
}; 

// TODO: Test
class Edge{
	public: 
		// attributes
		Vertex first; 
		Vertex second; 
		
		// constructors
		Edge(const Vertex& v1, const Vertex& v2) : first(v1), second(v2){}
		Edge(const Edge& e): first(e.first), second(e.second){}
	void print_edge(){
		std::cout<<"Edge: {"<<first.name<<","<<second.name<<"}"<<'\n'; 	
	}
}; 

class Graph{
	public: 
		// attributes
		int n; // number of vertices
		int m; // number of edges
		std::list<Vertex> V; 
		std::list<Edge> E; 

		// constructors

		// assuming that V is nonempty
		Graph(std::list<Vertex>& V_G, std::list<Edge>& E_G) : V(V_G), E(E_G){
			n = V_G.size(); 
			m = E_G.size(); 	
		}

}; 

void copy_list(std::list<Vertex>& new_list, std::list<Vertex>& old_list){
	for(Vertex& v : old_list){
		new_list.push_back(v); 	
	}
}
