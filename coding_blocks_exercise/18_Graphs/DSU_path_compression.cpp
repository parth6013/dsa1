#include<iostream>
#include<list>
using namespace std;

// in directed graph

// making a class using edge pair format

class Graph{

    int V;
    list<pair<int,int>> l;

    public:
        Graph(int V){
            this->V=V;
        }

        int addEdge(int u,int v){
            l.push_back(make_pair(u,v));
        }

// Earlier it was O(n) in worst case now it's O(1) using something as memoisation

        // Finding leader
        int findSet(int i,int parent[]){
            if(parent[i]==-1){
                return i;
            }
            
            return parent[i]=findSet(parent[i],parent);
        }
        // Union

        void union_set(int x,int y,int parent[]){

            int s1=findSet(x,parent);
            int s2=findSet(y,parent);

            if(s1!=s2){
                parent[s1]=s2;
            }



        }

        



        bool contains_cycle(){

            int *parent =new int[V];

            for(int i=0;i<V;i++){
                parent[i]=-1;
            }

            for(auto x:l){
                int a=x.first;
                int b=x.second;

                int S1=findSet(a,parent);
                int S2=findSet(b,parent);

                if(S1!=S2){
                    union_set(S1,S2,parent);
                }else{
                    cout<<"Same Parents  "<<S1<<" "<<S2<<endl;
                    return true;
                }

            }

            return false;


        }



};

int main(){
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    // g.addEdge(3,0);

    cout<<g.contains_cycle();

}