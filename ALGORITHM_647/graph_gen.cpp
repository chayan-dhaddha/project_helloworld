// A C++ Program to generate test cases for
// an weighted undirected graph
#include<bits/stdc++.h>
using namespace std;

// Define the maximum number of edges
//#define MAX_EDGES 499500
#define MAX_EDGES 10

// Define the maximum weight of edges
#define MAXWEIGHT 20

int main()
{
	set<pair<int, int>> container;
	set<pair<int, int>>::iterator it;

	// Uncomment the below line to store
	// the test data in a file
	 freopen("graph.txt",
			 "w", stdout);

	//For random values every time
	srand(time(NULL));

	int NUM=5; // Number of Vertices
	int NUMEDGE; // Number of Edges


		// Define the maximum number of edges of the graph
		// Since the most dense graph can have N*(N-1)/2 edges
		// where N = nnumber of vertices in the graph
		NUMEDGE = 1 + rand() % MAX_EDGES;
		/*while ((NUMEDGE<NUM-1) || (NUMEDGE > NUM*(NUM-1)/2))
			NUMEDGE = 1 + rand() % MAX_EDGES;*/

		// First print the number of vertices and edges
		printf("%d %d\n", NUM, NUMEDGE);
                pair<int,int> r;
                for(int startNode=1;startNode<=NUM-1;startNode++){
                 r=make_pair(startNode,startNode+1);
                 container.insert(r);
                 }
		// Then print the edges of the form (a b)
		// where 'a' is connected to 'b'
		for (int j=1; j<=NUMEDGE-NUM+1; j++)
		{
			int a = 1 + rand() % NUM;
			int b = 1 + rand() % NUM;
                          //a+=1;
                          //b+=1;
			pair<int, int> p = make_pair(a, b);
			pair<int, int> reverse_p = make_pair(b, a);

			// Search for a random "new" edge everytime
			// Note - In a tree the edge (a, b) is same
			// as the edge (b, a)
			while ((a==b) || container.find(p) != container.end() ||
					container.find(reverse_p) != container.end())
			{
				a =1 + rand() % NUM;
				b =1+ rand() % NUM;
				p = make_pair(a, b);
				reverse_p = make_pair(b, a);
			}
			container.insert(p);
		}
		for (it=container.begin(); it!=container.end(); ++it)
		{
			int wt = 1 + rand() % MAXWEIGHT;
			//printf("%d %d %d\n", it->first, it->second, wt);
                        cout<<it->first<<" "<<it->second<<" "<<wt;
                         cout<<endl; 
		}

		container.clear();
		//printf("\n");
                cout<<endl;

	// Uncomment the below line to store
	// the test data in a file
	 fclose(stdout);
	return(0);
}
