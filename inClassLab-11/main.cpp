#include <iostream>
#include <climits>

#define V 6 // Number of vertices in the graph

int findMinKey(int key[], bool mstSet[])
{
    int minKey = INT_MAX, minIndex;
    for (int v = 0; v < V; v++)
    {
        if (!mstSet[v] && key[v] < minKey)
        {
            minKey = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void primMST(int graph[V][V])
{
    int parent[V]; // Array to store constructed MST
    int key[V];    // Key values used to pick minimum weight edge in cut
    bool mstSet[V]; // To represent set of vertices included in MST

    // Initialize all keys as INFINITE
    for (int i = 0; i < V; i++)
    {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[0] = 0;       // Make the key 0 so that this vertex is picked as first vertex
    parent[0] = -1;   // First node is always the root of MST

    // The MST will have V vertices
    for (int count = 0; count < V - 1; count++)
    {
        int u = findMinKey(key, mstSet); // Pick the minimum key vertex from the set of vertices not yet included in MST

        mstSet[u] = true; // Add the picked vertex to the MST set

        // Update key values and parent index of the adjacent vertices of the picked vertex.
        // Consider only those vertices which are not yet included in MST
        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the constructed MST
    std::cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++)
    {
        std::cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << "\n";
    }
}

int main()
{
    int graph[V][V] = {{0, 3, 0, 0, 0, 1},
                      {3, 0, 2, 1, 10, 0},
                      {0, 2, 0, 3, 0, 5 },
                      {0, 1, 3, 0, 5, 0 },
                      {0, 10, 0, 5, 0, 4},
                      {1, 0, 0, 0, 4, 0}};

    primMST(graph);

    return 0;
}
