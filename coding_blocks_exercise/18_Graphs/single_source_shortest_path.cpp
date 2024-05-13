// bfs only give single source shortest path as we move in the neighhbour node which is discovered first will come early only

#include<iostream>
#include<map>
#include<list>
#include<queue>
using namespace std;

template<typename T>
class Graph{

    map<T,list<T>>l;

    public:
        void addEdge(int x,int y){
            l[y].push_back(x);
            l[x].push_back(y);

        

        }

        void bfs(T src){
            map<T,int> dist;
            queue<T> q;

           


            for(auto node_pair:l){
                T node =node_pair.first;
                dist[node]=INT_MAX;
            }

            q.push(src);
            dist[src]=0;    

            while(!q.empty()){

                T node= q.front();
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
                T node = node_pair.first;
                int d=dist[node];
                cout<<"Node"<<node<<"Dist from src "<<d<<endl;
            }


        }

};

int main(){

    Graph<int> g;
    g.addEdge(0,1);
    g.addEdge(0,3);
    g.addEdge(1,2);
    g.addEdge(3,2);
    g.addEdge(2,4);

    g.bfs(0);

}

