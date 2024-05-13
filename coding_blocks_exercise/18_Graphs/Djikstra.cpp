#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// Cannot be used for negative weight

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Write your code here.
    int n=vertices;
    
    // use vertices instead of 5 
    vector<pair<int,int>> g[5];
    
    for(int i=0;i<edges;i++){
        int x= vec[i][0];
        int y=vec[i][1];
        int w=vec[i][2];
        g[x].push_back({y,w});
        g[y].push_back({x,w});
    }
//     min heap means minimum remains on top
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> dist(vertices,INT_MAX);
    
    pq.push({0,source});
        dist[source]=0;
        
    while(!pq.empty()){
        
        auto top= pq.top();
        
        int pre=top.second;
        int weight=top.first;
        pq.pop();
        
        for(auto x: g[pre]){
            if(dist[x.first]>weight+x.second){
                pq.push({x.second+weight,x.first});
                dist[x.first]=weight+x.second;
            }
        }
        
        
    }
    
    return dist;
    
    
}
