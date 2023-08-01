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
	// TODO: optional newline
	void print_vertex(void){
		std::cout<<"name: "<<name<<'\n'<<"degree: "<<degree<<'\n'; 
		if (!neighbors.empty()){
			for (const Vertex& v : neighbors){
				std::cout<<v.name<<", "; 
			}	
			std::cout<<'\n'; 
		}
	}
	// compare Vertex objects by their name, assuming that vertices are named uniquely
	bool operator==(const Vertex& v) const{
		return name == v.name; 	
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
	// edges are identical iff both endpoint are identical
	bool operator==(const Edge& e) const{
		return first == e.first && second == e.second; 	
	}
	// TODO: optional newline 
	void print_edge(void){
		std::cout<<"Edge: {"<<first.name<<","<<second.name<<"}"; 
		std::cout<<'\n'; 
	}
	bool isEndpoint(Vertex& v){
		return first == v || second == v; 	
	}
	
}; 

// TODO: Test
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
	void delete_edge(Edge& e){
		Vertex v1(e.first); 
		Vertex v2(e.second); 

		v1.degree--; 
		v2.degree--; 
		v1.neighbors.remove(v2); 
		v2.neighbors.remove(v1); 
		E.remove(e); 	
	}

	void delete_vertex(Vertex& v){
		// delete vertex itsself
		V.remove(v); 
		// delete all incident edges
		for (Edge& e : E){
			if (e.isEndpoint(v)){
				delete_edge(e); 	
			}	
		}
		// adjust neighborhoods and degrees for adjacent vertices
		for (Vertex& u : v.neighbors){
			u.neighbors.remove(v); 
			u.degree--; 	
		}
	}
	void print_graph(void){
		std::cout<<"n = "<<n<<'\n'<<"m = "<<m<<'\n'; 
		for (Vertex& v : V) std::cout<<v.name<<", "; 
		std::cout<<'\n'; 
		for (Edge& e : E) std::cout<<"{"<<e.first.name<<","<<e.second.name<<"}, "; 
		std::cout<<'\n'; 
	}
}; 

void copy_list(std::list<Vertex>& new_list, std::list<Vertex>& old_list){
	for(Vertex& v : old_list){
		new_list.push_back(v); 	
	}
}
