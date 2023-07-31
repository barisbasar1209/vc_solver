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
		std::cout<<"name: "<<name<<std::endl<<"degree: "<<degree<<std::endl; 
		if (!neighbors.empty()){
			for (const Vertex& v : neighbors){
				std::cout<<v.name<<", "; 
			}	
			std::cout<<std::endl; 
		}
	}
}; 

void copy_list(std::list<Vertex>& new_list, std::list<Vertex>& old_list){
	for(Vertex& v : old_list){
		new_list.push_back(v); 	
	}
}

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
	return 0; 
}
