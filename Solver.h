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
			if (e.isIncident(v)){
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

// TODO: Test
// solves the vertex cover problem for a Graph G with parameter k, the maximal size of a vertex cover S in exponential time, most naive approach
bool exp_solve(Graph G, int k){
		// trivial false case
		if (k<=0) return false; 
	
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
			// decision type //  if (check_vc(G, S)) return true; 
			if (check_vc(G, S)) {
					std::cout<<"Vertex cover of size "<<k<<" is S : "; 
					for (Vertex *v : S){
						std::cout<<v->name<<" "; 	
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
