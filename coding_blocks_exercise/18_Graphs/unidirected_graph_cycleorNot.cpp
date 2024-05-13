#include<iostream>
#include<list>
#include<queue>
using namespace std;

class  Graph{

    list<int> *l;
    int V;

    public:
    Graph(int V){
        this->V= V;
        l = new list<int>[V];
    }


    void addEdge(int x,int y,bool directed){

        l[x].push_back(y);

        if(!directed){
            l[y].push_back(x);
        }

    }

    bool cycle_helper(int node,bool *visited,int parent){

        // visiting a node;
        visited[node]= true;

        for(auto nbr:l[node]){

            if(!visited[nbr]){

                bool cycle_mila = cycle_helper(nbr,visited,node);

                if(cycle_mila){
                    return true;
                }

            }

            else if(nbr !=parent){
                return true;
            }

        }
            return false;

    }

    bool contains_cycle(){

        bool *visited= new bool[V];
        int parent=-1;

        for(int i=0;i<V;i++){
         
         visited[i]=false;
         

        }

        cycle_helper(0,visited,parent);

    }


};