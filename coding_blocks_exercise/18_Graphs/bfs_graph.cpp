// breadth first search is also known as level order search
// close neighbours are printed first

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
            map<T,bool> visited;
            queue<T> q;

            q.push(src);
            visited[src]=true;

            while(!q.empty()){

                T node= q.front();
                q.pop();
                cout<<node<<" ";
                for(int nbr: l[node]){
                    if(!visited[nbr]){
                        q.push(nbr);

                        visited[nbr]=true;
                    }
                }


            }
            


        }



        void bfs2(T src){
            map<T,int> visited;

            queue<T> q1;
            q1.push(src);
            visited[src]=2;
            while(!q1.empty()){
                T node=q1.front();
                cout<<node<<" ";
                q1.pop();
                for(auto x: l[node]){
                    if(visited[x]!=2){
                        q1.push(x);
                        visited[x]=2;
                    }
                }


            }

        }

};

int main(){

    Graph<int> g;
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);

    g.bfs2(0);

}

