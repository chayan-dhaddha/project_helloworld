// C++ program for Kruskal's algorithm to find Minimum Spanning Tree 
// of a given connected, undirected and weighted graph 
#include <bits/stdc++.h> 
using namespace std; 



int V; // Number of vertices in graph 
int E; // Number of edges in graph 

// a structure to represent a weighted edge in graph 
struct Edge 
{ 
	int src;
	int dest;
	int weight; 
}; 


// Creates a graph with V vertices and E edges 
struct Edge* createEdge(int u, int v, int w) 
{ 
    struct Edge* edge = (struct Edge*)malloc(sizeof(struct Edge));
	edge->src = u; 
	edge->dest = v; 
	edge->weight = w; 
	return edge; 
} 
// Structure to represent a min heap node 
struct MinHeapNode { 
	int v; 
	int key; 
}; 

// Structure to represent a min heap 
struct MinHeap { 
	int size; // Number of heap nodes present currently 
	int capacity; // Capacity of min heap 
	struct Edge** array; 
}; 

void minHeapify(struct MinHeap* minHeap, int idx);

// A utility function to create a new Min Heap Node 
// struct Edge* newMinHeapNode(int v, int key) 
// { 
// 	struct Edge* minHeapNode = (struct Edge*)malloc(sizeof(struct Edge)); 
// 	minHeapNode->v = v; 
// 	minHeapNode->key = key; 
// 	return minHeapNode; 
// } 

void buildHeap(MinHeap* minHeap){
    int mid = minHeap->size / 2;
    for (int i = mid; i >= 0; i--) {
        minHeapify(minHeap, i);
    }
}

// A utilit function to create a Min Heap 
struct MinHeap* createMinHeap(int capacity,struct Edge** edges) 
{ 
	struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap)); 
	minHeap->size = capacity; 
	minHeap->capacity = capacity;
	minHeap->array = edges;
	buildHeap(minHeap);
	return minHeap; 
} 

// A utility function to swap two nodes of min heap. Needed for min heapify 
void swapMinHeapNode(struct Edge** a, struct Edge** b) 
{ 
	struct Edge* t = *a; 
	*a = *b; 
	*b = t; 
} 

// A standard function to heapify at given idx 
// This function also updates position of nodes when they are swapped. 
// Position is needed for decreaseKey() 
void minHeapify(struct MinHeap* minHeap, int idx) 
{ 
	int smallest, left, right; 
	smallest = idx; 
	left = 2 * idx + 1; 
	right = 2 * idx + 2; 

	if (left < minHeap->size && minHeap->array[left]->weight < minHeap->array[smallest]->weight) 
		smallest = left; 

	if (right < minHeap->size && minHeap->array[right]->weight < minHeap->array[smallest]->weight) 
		smallest = right; 

	if (smallest != idx) { 
		// The nodes to be swapped in min heap 
		Edge* smallestNode = minHeap->array[smallest]; 
		Edge* idxNode = minHeap->array[idx]; 

		// Swap positions 

		// Swap nodes 
		swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]); 

		minHeapify(minHeap, smallest); 
	} 
} 

// A utility function to check if the given minHeap is ampty or not 
int isEmpty(struct MinHeap* minHeap) 
{ 
	return minHeap->size == 0; 
} 

// Standard function to extract minimum node from heap 
struct Edge* extractMin(struct MinHeap* minHeap) 
{ 
	if (isEmpty(minHeap)) 
		return NULL; 

	// Store the root node 
	struct Edge* root = minHeap->array[0]; 

	// Replace root node with last node 
	struct Edge* lastNode = minHeap->array[minHeap->size - 1]; 
	minHeap->array[0] = lastNode; 

	// Update position of last node 

	// Reduce heap size and heapify root 
	--minHeap->size; 
	minHeapify(minHeap, 0); 

	return root; 
} 





// A structure to represent a subset for union-find 
struct subset 
{ 
	int parent; 
	int rank; 
}; 

// A utility function to find set of an element i 
// (uses path compression technique) 
int find(struct subset subsets[], int i) 
{ 
	// find root and make root as parent of i 
	// (path compression) 
	if (subsets[i].parent != i) 
		subsets[i].parent = find(subsets, subsets[i].parent); 

	return subsets[i].parent; 
} 

// A function that does union of two sets of x and y 
// (uses union by rank) 
void Union(struct subset subsets[], int x, int y) 
{ 
	int xroot = find(subsets, x); 
	int yroot = find(subsets, y); 

	// Attach smaller rank tree under root of high 
	// rank tree (Union by Rank) 
	if (subsets[xroot].rank < subsets[yroot].rank) 
		subsets[xroot].parent = yroot; 
	else if (subsets[xroot].rank > subsets[yroot].rank) 
		subsets[yroot].parent = xroot; 

	// If ranks are same, then make one as root and 
	// increment its rank by one 
	else
	{ 
		subsets[yroot].parent = xroot; 
		subsets[xroot].rank++; 
	} 
} 


// The main function to construct MST using Kruskal's algorithm 
void KruskalMST(struct Edge** edges) 
{ 
	struct Edge* result[V]; // Tnis will store the resultant MST 
	int e = 0; // An index variable, used for result[] 
	int i = 0; // An index variable, used for sorted edges 

	// Step 1: Sort all the edges in non-decreasing 
	// order of their weight. If we are not allowed to 
	// change the given graph, we can create a copy of 
	// array of edges 

        struct MinHeap* minHeap = createMinHeap(E, edges);


	// Allocate memory for creating V ssubsets 
	struct subset* subsets = (struct subset*) malloc(sizeof(struct subset) * V); 

	// Create V subsets with single elements 
	for (int v = 0; v < V; ++v) 
	{ 
		subsets[v].parent = v; 
		subsets[v].rank = 0; 
	} 
	// Number of edges to be taken is equal to V-1 
	while (e < V - 1 && i < E) 
	{ 
		// Step 2: Pick the smallest edge. And increment 
		// the index for next iteration 
		Edge* next_edge = extractMin(minHeap); 

		int x = find(subsets, next_edge->src); 
		int y = find(subsets, next_edge->dest); 

		// If including this edge does't cause cycle, 
		// include it in result and increment the index 
		// of result for next edge 
		if (x != y) 
		{ 
			result[e++] = next_edge; 
			Union(subsets, x, y); 
		} 
		// Else discard the next_edge 
	} 

	// print the contents of result[] to display the 
	// built MST 
	// cout<<"Following are the edges in the constructed MST\n"; 
	int mstweight=0;
	for (i = 0; i < e; ++i) 
		mstweight += result[i]->weight;
	cout<<mstweight;
		// cout<<result[i]->src<<" -- "<<result[i]->dest<<" == "<<result[i]->weight<<endl; 
	return; 
} 

 
// Driver code 
int main() 
{ 
	cin >> V >> E;
   	// struct Edge* edges[] = new Edge*[E];
	    struct Edge** edges = (struct Edge**)malloc(sizeof(struct Edge*) * E);
	    int u, v, w;
    // struct HeapNode** heap = (struct HeapNode**)malloc(sizeof(HeapNode*) * E);
    for (int i = 0; i < E; i++) {
        cin >> u >> v >> w;
        
        edges[i] = createEdge(u, v, w);
    }

    
    KruskalMST(edges); 
    
	return 0; 
} 


