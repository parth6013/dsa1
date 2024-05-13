#include<iostream>
#include<list>
#include<queue>
using namespace std;

class Graph{

    list<int> *l;
    int V;

    public:

    Graph(int V){

        this->V=V;
        l= new list<int>[V];

    }

    void addEdge(int x,int y){
        l[x].push_back(y);
        l[y].push_back(x);

    }
    bool is_tree(){

        bool *visited = new bool[V];
        int *parent= new int[V];

        queue<int> q;

        for(int i=0;i<V;i++){
            visited[i]=false;
            parent[i]=i;
        }

        int src=0;
        q.push(src);
        visited[src]=true;

        // BFS
        while(!q.empty()){
             int node =q.front();
             q.pop();

             for(int nbr:l[node]){

                 if(visited[nbr]=true && parent[node]!=nbr){
                     return false;
                 }

                 else if (!visited[nbr]){
                     visited[nbr]=true;
                     parent[nbr]=node;
                     q.push(nbr);
                 }

             }

        }

        return true;

    }

};

int main(){

    Graph g(4);

    g.addEdge(0,1);
    g.addEdge(3,2);
    g.addEdge(1,2);
    g.addEdge(0,3);

    if(g.is_tree()){
        cout<<" yes";
    }else{
        cout<<"no";
    }


}

class Solution {
public:
    int minimumCost(vector<int>& cost) {
        
        if(cost.size()==1){
            return cost[0];
        }
        
        int i=0;
        int j=1;
        
        int total=0;
        
        reverse(cost.begin(),cost.end());
        
        while(true){
            
            total+=cost[i]+cost[j];
            
            if(i+3<cost.size()){
                i+=3;
            }else{
                break;
            }
               
            if(j+3<cost.size()){
                j+=3;
            }else{
                total+=cost[i];
                break;
            }
            

        }
               
               
        
        
    }
};