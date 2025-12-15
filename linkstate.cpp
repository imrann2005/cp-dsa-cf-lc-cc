#include<iostream>
#include<vector>
#include<utility>
#include <climits>

using namespace std;

struct Router{
    int srno;
    int n; // number of Routers in the Network
    vector<pair<int,int>> neighbours;
    vector<vector<pair<int,int>>> lsdb;
    vector<int> shortestPath;

    Router(int r,int i){
        srno = i;
        n = r;
        lsdb.resize(n);
        shortestPath.assign(n,INT_MAX); // use 999 instead of INT_MAX
        int size;
        cout<<"Enter the Number of vertices connected to the Router : ";
        cin>>size;
        cout<<"Enter the Connectivity Information for the Router :\n";
        for(int i=0 ; i<size ;i++){
            int v,w;
            cout<<"Enter the Router to which it is Connected : ";
            cin>>v;
            cout<<"Enter the Weight of the Edge : ";
            cin>>w;
            neighbours.push_back({v,w});
        }
    }
};


void setupLSDB(vector<Router*>& allRouter, int n){
    for(int i=0 ; i<allRouter.size() ; i++){
        // allRouter[n]->lsdb.push_back(allRouter[i]->neighbours); // option 1
        allRouter[n]->lsdb[i] = allRouter[i]->neighbours; // option 2
    }
}

int findClosestVertex(vector<int>& vis , struct Router* router){
    int min = INT_MAX;
    int index=-1;
    for(int i=0 ; i<router->shortestPath.size() ; i++){
        if(vis[i]==0 && router->shortestPath[i] < min){
            min = router->shortestPath[i];
            index = i;
        }
    }

    return index;
}


void dijkstra(struct Router* router){
    int v = router->n;
    vector<int> vis(v , 0);
    int root = router->srno;
    router->shortestPath[root] = 0;
    for(int i=0 ; i<v ;i++){
        int closestVertex = findClosestVertex(vis,router);
        vis[closestVertex] = 1;
        for(vector<pair<int,int>>::iterator it = router->lsdb[closestVertex].begin(); it!=router->lsdb[closestVertex].end(); it++){
            int targetvertex = it->first;
            int weight = it->second;
            if(vis[targetvertex]==0 && router->shortestPath[targetvertex] > router->shortestPath[closestVertex] + weight){
                router->shortestPath[targetvertex] = router->shortestPath[closestVertex] + weight;
            }
        }
    }
}


int main(){
    int r;
    cout<<"Enter the Number of Routers in the Network :";
    cin>>r;
    vector<Router*> allRouter(r,NULL);
    cout<<"Setup the Routers State:\n";
    for(int i=0 ; i<r; i++){
        cout<<"Setup Router "<<i<<" :\n"<<endl;
        struct Router* router = new Router(r,i);
        allRouter[i] = router;
    }

    cout<<"States of the Routers have been Initialised Successfully !!"<<endl;
    cout<<"Waiting Till all the routers Setup their LSBD...."<<endl;

    for(int i=0 ; i<r; i++){
        setupLSDB(allRouter , i);
    }

    cout<<"LSDB for all the router setup Successfully !!"<<endl;
    cout<<"Finding the shortest Path for Each Router to all the Routers : \n";

    for(int i=0 ; i<r ; i++){
        dijkstra(allRouter[i]);
    }

    cout << "\n--- Shortest Path Tables ---\n";
    for(int i = 0; i < r; i++){
        cout << "Router " << i << " shortest paths:\n";
        for(int j = 0; j < r; j++){
            cout << "To Router " << j << " : " << allRouter[i]->shortestPath[j] << endl;
        }
        cout << endl;
    }

}