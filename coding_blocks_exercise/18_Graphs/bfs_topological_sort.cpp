// topological sort by using bfs ,indegree method
#include<iostream>
#include<list>
#include<queue>
using namespace std;

// class Graph{

//     int v;
//     list<int> *l;
//     public:

//     Graph (int v){
//         this->v=v;
//          l= new list<int>[v];

//     }

//     void addEdge(int x,int y){

//         l[x].push_back(y);
//     }


//     void tsort(){

//         int*indegree = new int[v];

//         for(int i=0;i<v;i++){
//             indegree[i]=0;
//         }

//         // setting up indegree
//         for(int i=0;i<v;i++){
//             for(auto x:l[i]){
//                 indegree[x]++;
//             }
//         }

//         queue<int>q;

//         for(int i=0;i<v;i++){
//             if(indegree[i]==0){
//                 q.push(i);
//             }
//         }

//         while(!q.empty()){

//             int node =q.front();
//             cout<<node<<" ";
//             q.pop();


//             for(auto nbr:l[node]){
//                 indegree[nbr]--;
//                 if(indegree[nbr]==0){
//                     q.push(nbr);
//                 }
//             }

//         }


//     }
    
   


// };



// int main(){






// }



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
    }

    void topological_sort(){

        int *indegree = new int[V];

        // intializing 0 indegree for all 
        for(int i=0;i<V;i++){
            indegree[i]=0;
        }


        // updating indegree
        for(int i=0;i<V;i++){
            for(auto x:l[i]){
                indegree[x]++;
            }
        }

        // bfs
        queue<int> q;

        // Finding nodes with with 0 indegree

        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node =q.front();

            cout<<node<<" ";
            q.pop();

            for(auto x:l[node]){
                indegree[x]--;
                if(indegree[x]==0){
                    q.push(x);
                }
            }

        }


    }

};