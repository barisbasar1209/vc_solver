#include<list>
#include<vector>
#include<string>
#include<iostream>
#include<algorithm>
#include<cmath>

# define DYNAMIC true 

class Vertex{
	public:
		// attributes
		int name=-1; 
		int degree=-1; 
		bool is_dynamic=false; 
		std::list<Vertex*> neighbors; 
		// constructors
		Vertex(int v_name) : name(v_name){degree=0;}
		Vertex(int v_name, bool v_is_dynamic) : name(v_name), is_dynamic(v_is_dynamic){degree=0;}   		
		Vertex(int v_name, const std::list<Vertex*>& v_neighbors) : name(v_name), neighbors(v_neighbors){degree = neighbors.size();}
		// methods 
		void print_vertex(void){
			std::cout<<"name: "<<name<<'\n'<<"degree: "<<degree<<'\n'; 
			if (!neighbors.empty()){
				for (Vertex *v : neighbors){
					std::cout<<v->name<<", "; 
				}	
				std::cout<<'\n'; 
			}
		}
}; 

class Edge{
	public: 
		// attributes 
		Vertex *first; 
		Vertex *second; 
		// constructors	
		Edge(Vertex *v1, Vertex *v2) : first(v1), second(v2){}
		Edge(const Edge& e) : first(e.first), second(e.second){}

		bool operator==(const Edge& e) const{
			return (first==e.first && second==e.second) || (first==e.second && second==e.first); 	
		}
		void print_edge(void){
			std::cout<<"Edge: {"<<first->name<<","<<second->name<<"}"; 
			std::cout<<'\n'; 
		}
		bool is_incident(Vertex *v){
			return first == v || second == v; 	
		}
}; 

class Graph{
	public: 
		// attributes
		int n = -1; 
		int m = -1; 
		std::list<Vertex*> V; 
		std::list<Edge> E; 

		// constructors
		Graph(std::list<Vertex*>& V_G, std::list<Edge>& E_G) : V(V_G) {
			n = V_G.size(); 
			add_edge_set(E_G);
		}
		Graph(std::vector<int>& adj_matrix){
			m = 0; 
			n = adj_matrix.size(); 
			// init V
			for (int i=0; i<n; i++){
				Vertex *v = new Vertex(i, DYNAMIC); // dynamic allocation with i as the name
				V.push_back(v); 
			}
			// init E
			for (int adj_list_idx=n; adj_list_idx>0; adj_list_idx--){
				int adj_list = adj_matrix[n-adj_list_idx]; 
				for (int bit_idx=n-1; bit_idx>=0; bit_idx--){
					if(adj_list & (1<<bit_idx)){
						auto iter1 = V.begin(); 
						std::advance(iter1, n-adj_list_idx);
						auto iter2 = V.begin(); 
						std::advance(iter2, n-bit_idx-1); 
						Vertex *v1 = *iter1; 
						Vertex *v2 = *iter2; 
						Edge *e = new Edge(v1,v2); 
						add_edge(*e); 
					}
				}
			}
		}
		// destructor 
		~Graph(){
			for (Vertex *v : V){
				if (v->is_dynamic){
					delete v; 
					v=0x0; 
				}	
			}	
		}	
		// methods 
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
			V.remove(v); 
			for (auto iter = E.begin(); iter != E.end(); ){
				Edge& e = *iter; 
				if (e.is_incident(v)){
					Vertex *v1(e.first); 
					Vertex *v2(e.second); 
					v1->degree--; 
					v2->degree--; 
					v1->neighbors.remove(v2); 
					v2->neighbors.remove(v1); 
					iter = E.erase(iter); 
				}	
				else ++iter; 
			}

			for (Vertex *u : v->neighbors){
				u->neighbors.remove(v); 
				u->degree--; 	
			}
		
			if (v->is_dynamic) delete v; 
		}
		void add_edge_set(std::list<Edge>& E_G){
			for (Edge& e : E_G) add_edge(e); 	
		}

		void print_graph(void){
			std::cout<<"n = "<<n<<'\n'<<"m = "<<m<<'\n'; 
			if (!V.empty()){
				for (Vertex *v : V) std::cout<<v->name<<" "; 
			}
			std::cout<<'\n'; 
			if (!E.empty()){
				for (Edge& e : E) std::cout<<"{"<<e.first->name<<" "<<e.second->name<<"} "; 
			}
			std::cout<<'\n'; 
		}
}; 

void copy_list(std::list<Vertex*>& new_list, std::list<Vertex*>& old_list){
	for(Vertex *v : old_list){
		new_list.push_back(v); 	
	}
}
