#include <iostream>
#include <vector>
#include <utility>
#include <climits>
#include <queue> // Added for priority_queue

using namespace std;

// The Router struct remains the same
struct Router {
    int srno;
    int n; // number of Routers in the Network
    vector<pair<int, int>> neighbours;
    vector<vector<pair<int, int>>> lsdb;
    vector<int> shortestPath;

    Router(int r, int i) {
        srno = i;
        n = r;
        lsdb.resize(n);
        shortestPath.assign(n, INT_MAX);
        int size;
        cout << "Enter the Number of vertices connected to the Router " << i << ": ";
        cin >> size;
        cout << "Enter the Connectivity Information for the Router " << i << ":\n";
        for (int j = 0; j < size; j++) {
            int v, w;
            cout << "Enter the Router to which it is Connected: ";
            cin >> v;
            cout << "Enter the Weight of the Edge: ";
            cin >> w;
            neighbours.push_back({v, w});
        }
    }
};

// setupLSDB function remains the same
void setupLSDB(vector<Router*>& allRouter, int n) {
    for (int i = 0; i < allRouter.size(); i++) {
        allRouter[n]->lsdb[i] = allRouter[i]->neighbours;
    }
}


void dijkstra(struct Router* router) {
    int v = router->n;
    int root = router->srno;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    router->shortestPath[root] = 0;
    pq.push({0, root}); // {distance, vertex_number}

    while (!pq.empty()) {
        // Get the vertex with the smallest distance from the priority queue.
        int current_dist = pq.top().first;
        int u = pq.top().second;
        pq.pop();
       
        if(current_dist > router->shortestPath[u]){
            continue;
        }

        for (auto& edge : router->lsdb[u]) {
            int targetVertex = edge.first;
            int weight = edge.second;

            if (router->shortestPath[u] + weight < router->shortestPath[targetVertex]) {
                router->shortestPath[targetVertex] = router->shortestPath[u] + weight;
                pq.push({router->shortestPath[targetVertex], targetVertex});
            }
        }
    }
}

// The main function remains the same
int main() {
    int r;
    cout << "Enter the Number of Routers in the Network: ";
    cin >> r;
    vector<Router*> allRouter(r, NULL);
    cout << "--- Setup the Routers State ---\n";
    for (int i = 0; i < r; i++) {
        cout << "\nSetup Router " << i << " :\n";
        struct Router* router = new Router(r, i);
        allRouter[i] = router;
    }

    cout << "\nStates of the Routers have been Initialised Successfully !!" << endl;
    cout << "Waiting Till all the routers Setup their LSDB...." << endl;

    for (int i = 0; i < r; i++) {
        setupLSDB(allRouter, i);
    }

    cout << "LSDB for all the routers setup Successfully !!" << endl;
    cout << "Finding the shortest Path for Each Router to all the Routers...\n";

    for (int i = 0; i < r; i++) {
        dijkstra(allRouter[i]);
    }

    cout << "\n--- Shortest Path Tables ---\n";
    for (int i = 0; i < r; i++) {
        cout << "Router " << i << " shortest paths:\n";
        for (int j = 0; j < r; j++) {
            if (allRouter[i]->shortestPath[j] == INT_MAX) {
                cout << "To Router " << j << " : No Path\n";
            } else {
                cout << "To Router " << j << " : " << allRouter[i]->shortestPath[j] << "\n";
            }
        }
        cout << endl;
    }

    // Clean up dynamically allocated memory
    for(int i = 0; i < r; i++){
        delete allRouter[i];
    }

    return 0;
}