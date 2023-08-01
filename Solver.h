#include<list>
#include<iostream>
#include<string>
#include<vector>
#include"Graph.h"

// TODO: Test
// checks whether or not S is a valid vertex cover
bool check_vc(Graph& G, std::list<Vertex*>& S) {
	// check for all edges if there is at least one vertex in the vertex cover S that covers it
	// if one vertex covers the edge proceed with the next edge, otherwise if no vertex covers it S is not a vertex cover
	bool covered = false; 
	// check for all edges
	for (Edge& e : G.E){
		covered = false; 
		// if there exists one vertex in the VC S that covers it
		for (Vertex *v : S){
			if (e.isEndpoint(v)){
				// if that vertex is found mark the edge as covered and move to next edge
				covered = true; 	
				break; 
			}
		}
		// if there was no vertex covering that edge then return false
		if (!covered) return false;
	}
	return true; 
}

bool exp_solve(Graph G, int k){
	if (k<=0) return false; 
	std::vector<bool> bitmask(G.n,false); 
	std::fill(bitmask.begin(), bitmask.begin()+k, true); 

	do{
		std::list<Vertex*> S; 
		for (int i=0; i<G.n; ++i){
			if(bitmask[i]){
				S.push_back(*(std::next(G.V.begin(), k))); 	
			}	
		}	
		if (check_vc(G,S)) {
			std::cout<<"The vertex cover S of size "<<k<<" consists of: "; 
			for (Vertex *v : S){
				std::cout<<v->name<<" "; 	
			}
			return true; 	
			std::cout<<'\n'; 
		}
		else {
			std::cout<<"Not valid VC S of size "<<k<<" consists of: "; 	
			for (Vertex *v : S){
				std::cout<<v->name<<" "; 	
			}
			std::cout<<'\n'; 
		}

		int t = G.n-1; 
		while(t >= 0 && bitmask[t]) --t; 
		if(t>=0){
			bitmask[t] = true; 	
			for(int i=t+1; i<G.n; ++i) bitmask[i] = false; 
		}
	} while (std::count(bitmask.begin(), bitmask.end(), true) == k); 
	return false; 
}

// TODO: Test
// solves the vertex cover problem for a Graph G with parameter k, the maximal size of a vertex cover S in exponential time, most naive approach
bool exp_solve_trash(Graph G, int k){
		// trivial cases
		if (k<=0) return false; 
		//if (k>=(G.n/2)) return true; 
	
		// for all subsets with k elements
		int bitmask = (1 << k) - 1; 
		while(bitmask < (1 << G.n)){
			std::list<Vertex*> S; 
			int count = 0; 
			auto it = (G.V).begin(); 
			while(it != (G.V).end()){
				if((bitmask >> count) & 1){
					S.push_back(*it);	
				}	
				count++; 
				++it; 
			}
			// checking whether or not S is a valid VC in G 
			// if (check_vc(G, S)) return true; 
			if (check_vc(G, S)) {
					std::cout<<"Vertex cover of size "<<k<<" is S : "; 
					for (Vertex *v : S){
						std::cout<<v->name<<","; 	
					}
					std::cout<<'\n'; 
					return true; 
			}
	
			// increment the bitmask to the next subset
			int smallest = bitmask & -bitmask; 
			int ripple = bitmask + smallest; 
			int ones = bitmask ^ ripple; 
			ones = (ones >> 2) / smallest; 
			bitmask = ripple | ones; 
		}
		return false; 
}
