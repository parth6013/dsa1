// we have to find how many components are there in graph forest
#include<iostream>
#include<map>
#include<list>
using namespace std;



class Graph{

    map<int,list<int>> l;

    public:

    void addEdges(int x,int y){

        l[x].push_back(y);
        

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

    void dfs(){

        // to see if we have visited or not
        map<int,bool> visited;

        // intialising false for all the nodes as we have not visited them
        for(auto node_pair:l){
            int node=node_pair.first;
            visited[node]=false;
        }

        int cnt=0;
        for(auto node_pair2: visited){
            
            int node=node_pair2.first;
            if(!visited[node]){
                cout<<"component"<<cnt<<" ---->";
                helper(node,visited);
                cnt++;
                cout<<endl;
            }
        }

        cout<<cnt;



    }








};








int main(){

    Graph g;
    
    g.addEdges(0,1);
    g.addEdges(1,2);
    g.addEdges(2,3);
    g.addEdges(0,3);
    g.addEdges(0,4);


    g.addEdges(5,6);
    g.addEdges(6,7);

    g.addEdges(8,8);
    


    g.dfs();

    return 0;
}