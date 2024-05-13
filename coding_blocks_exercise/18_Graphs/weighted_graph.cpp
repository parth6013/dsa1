// nodes to be alphabets rather than integer  and edges to be waited
// so in a map we store key as aplhabets and value as array(or list) of pairs where first denoting edge to another node 
// and second being its distance

#include<iostream>
#include<unordered_map>
#include<map>
#include<string>
#include<list>
using namespace std;

// class Graph{

// // adj list
// unordered_map<string,list<pair<string,int>>> l;

// public:
//     void addEdges(string x, string y, bool bidr,int dst){

//         l[x].push_back(make_pair(y,dst));
//         if(bidr){
//             l[y].push_back(make_pair(x,dst));
//         }

//     }

//     void printEdges(){
//         for(auto p:l){
//             string city =p.first;
//             list<pair<string,int>> nbrs =p.second;
//             cout<<city<<"->";
//             for(auto nbr:nbrs){
//                 string dest =nbr.first;
//                 int dist = nbr.second;
//                 cout<<dest<<" "<<dist<<",";
//             }
//             cout<<endl;
//         }
//     }

// };


// int main(){

//     Graph g;
//     g.addEdges("A","B",true,20);
//     g.addEdges("B","D",true,40);
//     g.printEdges();



// }

class Graph{

    map<string,list<pair<string,int>>> l;

    public:
    void add_edge(string x,string y,bool bidr,int dist){
        l[x].push_back(make_pair(y,dist));
        if(bidr){
            l[y].push_back(make_pair(x,dist));
        }
    }

    void print(){
        for(auto x : l){
            cout<<x.first<<" ->";
            for(auto y:x.second){
                cout<<y.first<<" "<<y.second<<" ,";
            }
            cout<<endl;
        }
    }


};

int main(){
    Graph g;
    g.add_edge("A","B",true,20);
    g.add_edge("B","D",true,40);
    g.print();
}