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

    bool cycle_helper(int node,bool *visited,bool *stack){

        // visit a node
        visited[node]=true;
        stack[node]=true;

        for(int nbr : l[node]){

            if(stack[nbr]==true){
                return true;
            }

            else if(visited[nbr]==false){

                bool cycle_mila=cycle_helper(nbr,visited,stack);

                if(cycle_mila==true){
                    
                    return cycle_mila;
                }

            }

        }

        // return frrom a node
        stack[node]=false;
        return false;


    }

    bool contains_cycle(){

        bool *visited= new bool[V];
        bool *stack=new bool[V];

        for(int i=0;i<V;i++){
         
         visited[i]=false;
         stack[i]=false;

        }

        cycle_helper(0,visited,stack);

    }


};