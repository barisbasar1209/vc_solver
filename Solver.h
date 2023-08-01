#include<list>
#include<iostream>
#include<string>
#include"Graph.h"

// TODO: Test
// checks whether or not S is a valid vertex cover
bool check_vc(Graph& G, std::list<Vertex>& S) {
	// check for all edges if there is at least one vertex in the vertex cover S that covers it
	// if one vertex covers the edge proceed with the next edge, otherwise if no vertex covers it S is not a vertex cover
	for (Edge& e : G.E){
		for (Vertex& v : S){
			if (e.isEndpoint(v)) break; 
		}
		return false; 
	}
	return true; 
}

// TODO: Test
// solves the vertex cover problem for a Graph G with parameter k, the maximal size of a vertex cover S in exponential time, most naive approach
bool exp_solve(Graph G, int k){
		// trivial cases
		if (k<=0) return false; 
		if (k>(G.n/2)) return true; 
	
		// for all subsets with k elements
		int bitmask = (1 << k) - 1; 
		while(bitmask < (1 << G.n)){
			std::list<Vertex> S; 
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
			if (check_vc(G, S)) return true; 
	
			// increment the bitmask to the next subset
			int smallest = bitmask & -bitmask; 
			int ripple = bitmask + smallest; 
			int ones = bitmask ^ ripple; 
			ones = (ones >> 2) / smallest; 
			bitmask = ripple | ones; 
		}
		return false; 
}
