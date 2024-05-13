#include<iostream>
#include<map>
#include<list>
#include<queue>
#include<climits>
using namespace std;


class Graph{

map<int,list<int>> l;

public:

    void addEdges(int x,int y){
        l[x].push_back(y);

    }

    void bfs(int src, int dest){

        map<int,int> dist;

        queue<int> q; 


        for(auto node_pair:l){
            int node = node_pair.first;
            dist[node]=INT_MAX;
        }

        q.push(src);
        dist[src]=0; 

                 while(!q.empty()){

                int node= q.front();
                q.pop();
                // cout<<node<<" ";
                for(int nbr: l[node]){
                    if(dist[nbr]==INT_MAX){
                        q.push(nbr);

                        dist[nbr]=dist[node]+1;
                    }
                }


            }

                for(auto node_pair:l){
                int node = node_pair.first;
                int d=dist[node];
                cout<<"Node"<<node<<"Dist from src "<<d<<endl;
            }

    }



};


int main(){


    int board[50]={0};

    // Snakes  Ladders

    board[2]=13;
    board[5]=2;
    board[9]=18;
    board[18]=11;
    board[17]=-13;
    board[20]=-14;
    board[24]=-8;
    board[25]=10;
    board[32]=-2;
    board[34]=-22;

    Graph g;

    for(int i=0;i<=36;i++){
        for(int j=1;j<=6;j++){
            int edge_temp = j+i;
            // question is such to add otherwise you have to replace
            edge_temp=edge_temp+board[j];

            if(edge_temp<=36){
                g.addEdges(i,edge_temp);
            }

        }
    }

    g.addEdges(36,36);

    g.bfs(0,36);





}