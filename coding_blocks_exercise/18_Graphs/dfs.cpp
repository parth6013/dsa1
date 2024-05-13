//  Depth first search ,in this it goes to immediate neighbour if its not visited and then go back , its a recursive fn

#include<iostream>
#include<map>
#include<list>
using namespace std;



class Graph{

    map<int,list<int>> l;

    public:

    void addEdges(int x,int y){

        l[x].push_back(y);
        l[y].push_back(x);

    }


    void helper(int src,map<int,bool> &visited){

        cout<<src<<" ,";
        visited[src]=true;

        for(auto nbr : l[src]){
            if(!visited[nbr]){
                helper(nbr,visited);
            }
        }

        return;

    }

    void dfs(int src){

        // to see if we have visited or not
        map<int,bool> visited;

        // intialising false for all the nodes as we have not visited them
        for(auto node_pair:l){
            int node=node_pair.first;
            visited[node]=false;
        }

        helper(src,visited);



    }








};








int main(){

    Graph g;
    g.addEdges(3,0);
    g.addEdges(0,1);
    g.addEdges(1,2);
    g.addEdges(2,3);
    g.addEdges(3,4);
    g.addEdges(4,5);
    


    g.dfs(0);

    return 0;
}