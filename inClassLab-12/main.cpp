#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector <int> dijkstra(int V, vector<vector<int>> adj[], int S);

int main()
{

    // because this is a zero based indexed graph we can use adjecency list for represent this graph

    vector<vector<int>> adj[6] = {{{1,10},{4,15},{5,5}},{{0,10},{2,10},{3,30}},{{1,10},{3,12}},{{2,12},{1,30},{5,20}},{{0,15},{2,5}},{{0,5},{3,20}}};
    vector<int> ans = dijkstra(6,adj,0);
    for (int i = 0 ; i < ans.size() ; i++){
        cout << "Minimum distance for vertex " << i << " is " << ans[i] << " from source: " << 0 << endl;;
    }
    return 0;

}
    //from the source vertex S.
vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // this line of code creates a priority_queue named pq that stores pairs of
        //integers in a min heap structure. The elements are stored in a vector, and the order is
        //determined by the comparison of the first elements of each pair using the greater functor.

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // we need to create an array to store the distances according to the indexes

    vector<int> distance(V);
        // mark every distances as infinite

    for (int i = 0 ; i < V ; i++){
        distance[i] = 1e9;
    }

        // source to cource distance is always zero so we can initialize it
    distance[S] = 0;
        // push the distance and node to the priority queue
    pq.push({0,S});

    while(!pq.empty()){
            // pop the min value from the min heap
            // its first value represents the distance and second value represents the node

        int dis = pq.top().first;
        int node = pq.top().second;
            // then remove the top value from the priority queue

        pq.pop();

            // iterate through the adjecency list
        for (auto it : adj[node]){

            int edgeWeight = it[1];
            int adjNode = it[0];

                // relaxation process
            if (dis + edgeWeight < distance[adjNode]){
                distance[adjNode] = dis + edgeWeight;

                    // push the new node and weight value the priority queue

                pq.push({distance[adjNode],adjNode});
            }
        }

    }
    return distance;
}
