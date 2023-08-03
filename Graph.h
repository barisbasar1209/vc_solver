#include<list>
#include<vector>
#include<string>
#include<iostream>
#include<algorithm>
#include<cmath>

// TODO: Test
class Vertex{
	public:
		std::string name=""; 
		int degree=-1; 
		std::list<Vertex*> neighbors; 
		Vertex(std::string v_name) : name(v_name){degree=0;}   		
		Vertex(std::string v_name, const std::list<Vertex*>& v_neighbors) : name(v_name), neighbors(v_neighbors){degree = neighbors.size();}
		//Vertex(const Vertex& v) name(v.name), degree(v.degree), neighbors(v.neighbors){}
	void print_vertex(void){
		std::cout<<"name: "<<name<<'\n'<<"degree: "<<degree<<'\n'; 
		if (!neighbors.empty()){
			for (Vertex *v : neighbors){
				std::cout<<v->name<<", "; 
			}	
			std::cout<<'\n'; 
		}
	}
	// compare Vertex objects by their name, assuming that vertices are named uniquely
	// pracitcally useless since vertices are compared by adress 
	bool operator==(const Vertex& v) const{
		return name == v.name; 	
	}
}; 

// TODO: Test
class Edge{
	public: 
		// attributes
		Vertex *first; 
		Vertex *second; 
		
		// constructors
		Edge(Vertex *v1, Vertex *v2) : first(v1), second(v2){}
		Edge(const Edge& e) : first(e.first), second(e.second){}
	// edges are identical iff both endpoint are identical
	bool operator==(const Edge& e) const{
		return first == e.first && second == e.second; 	
	}
	void print_edge(void){
		std::cout<<"Edge: {"<<first->name<<","<<second->name<<"}"; 
		std::cout<<'\n'; 
	}
	bool isEndpoint(Vertex *v){
		return first == v || second == v; 	
	}
	
}; 

// TODO: Test
// TODO: write constructor that constructs Graph from adjacencymatrix
// TODO: considering a change from Edge set to Edge* set
class Graph{
	public: 
		// attributes
		int n = -1; // number of vertices uninitialized
		int m = -1; // number of edges unintialized 
		std::list<Vertex*> V; 
		std::list<Edge> E; 

		// constructors

		// assuming that V is nonempty
		Graph(std::list<Vertex*>& V_G, std::list<Edge>& E_G) : V(V_G) {
			n = V_G.size(); 
			// m = E_G.size(); 	
			for (Edge& e : E_G){
				add_edge(e); 	
			}	
		}

		// adjacencymatrix constructor taking binarynumber array converting it to graph object
		// usage of bitset because graph could have way more than 16 or 32 vertices
		Graph(std::vector<int> matrix){
			n = matrix.size(); // length of matrix implies number of vertices	
			int bitmask = std::pow(2,n)-1; // all ones bitmask of length n

			// initialize V
			// TODO: I have to dynamically allocate the objects with new keyword on the heap because otherwise the compiler only allocates the address on the stack
			// and with each new loop the adress can and most likely will be reused, causing a segfault. Now by using the heap memory and dynamically allocating
			// the object I must delete/deconstruct the object when I dont need it anymore, otherwise I am leaking memory 
			for (int i=0; i<n; i++){
				// dynamically allocated, must be deconstructed later on !
				Vertex *v = new Vertex("v" + std::to_string(i));
				V.push_back(v); 
			}
			for (int i=0; i<n; i++){
					
			}
		}
		// TODO: Graph constructor that works with string and number of vertices
	// assuming vertices are already inside of V
	void add_edge(Edge& e){
		auto iter = std::find(E.begin(), E.end(), e); 
		if (iter == E.end()){
			E.push_back(e); 
			e.first->degree++; 
			e.second->degree++; 
			e.first->neighbors.push_back(e.second);
			e.second->neighbors.push_back(e.first);
			m++; 
		}	
	}
	void delete_edge(Edge& e){
		Vertex *v1(e.first); 
		Vertex *v2(e.second); 

		v1->degree--; 
		v2->degree--; 
		v1->neighbors.remove(v2); 
		v2->neighbors.remove(v1); 
		E.remove(e); 	
	}

	void delete_vertex(Vertex *v){
		// delete vertex itsself
		V.remove(v); 
		// delete all incident edges
		for (Edge& e : E){
			if (e.isEndpoint(v)){
				delete_edge(e); 	
			}	
		}
		// adjust neighborhoods and degrees for adjacent vertices
		for (Vertex *u : v->neighbors){
			u->neighbors.remove(v); 
			u->degree--; 	
		}
	}
	void print_graph(void){
		std::cout<<"n = "<<n<<'\n'<<"m = "<<m<<'\n'; 
		if (!V.empty()){
			for (Vertex *v : V) std::cout<<v->name<<" "; 
		}
		std::cout<<'\n'; 
		if (!E.empty()){
			for (Edge& e : E) std::cout<<"{"<<e.first->name<<","<<e.second->name<<"}, "; 
		}
		std::cout<<'\n'; 
	}
}; 

void copy_list(std::list<Vertex*>& new_list, std::list<Vertex*>& old_list){
	for(Vertex *v : old_list){
		new_list.push_back(v); 	
	}
}
