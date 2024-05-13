#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Graph{

    // Adjancey List
    vector<pair<int,int>> *l;
    int V;

    public:
        Graph(int n){
            V=n;
            l=new vector<pair<int,int>> [n];

        }

        void addEdge(int x,int y,int w){
            l[x].push_back({y,w});
            l[y].push_back({x,w});
        }


        int prim_mst(){

            // Init a Min Heap
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> Q;

            bool *visited =new bool[V]{0};
            int ans=0;

            // begin
// weight,node
            Q.push({0,0});

            while(!Q.empty()){
                // pick out the edge with min weight
                auto best =Q.top();
                Q.pop();

                int to=best.second;
                int weight =best.first;

                if(visited[to]){
                        continue;
                }

                // otherwise take the current  edge
                ans+=weight;
                visited[to]=1;

                // add the new edges in the queue
                for(auto x:l[to]){
                    if(visited[x.first]==0){
                        Q.push({x.second,x.first});
                    }
                }

            }

            return ans;
        }

};