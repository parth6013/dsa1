// topological sort using dfs toh jo dependent h woh add hote rhenge jo independent h woh front m last m add hoga 
#include<iostream>
#include<map>
#include<list>
#include<string>
using namespace std;


class Graph{

    map<string,list<string>> l;

    public:

        void addEdges(string x, string y){
            l[x].push_back(y);
        }


        void helper(string src,map<string,bool> &visited,list<string> &order){

            
            visited[src]=true;
            for(auto nbr: l[src]){

                if(!visited[nbr]){
                    helper(nbr,visited,order);
                }


            }
            // we want to push last item to front first;
            order.push_front(src);

        }

        void helper2(string src,map<string,bool> &visited,list<string> &order){
            
            visited[src]=true;

            for(auto x:l[src]){
                if(visited[x]!=true){
                    helper2(x,visited,order);
                }
            }

            order.push_front(src);

        }


        void dfs_topSort(){

            map<string,bool> visited;

            for(auto node_pair:l){
                string node = node_pair.first;
                visited[node]=false;

            }

            list<string> order;

            for(auto node_pair2:visited){
                string node2=node_pair2.first;
                if(!visited[node2]){
                    helper(node2,visited,order);
                }
            }

            for(auto node3:order){
                cout<<node3<<endl;
            }


        }

        void dfs_topsort2(){

            map<string,bool> visited;
            list<string> order;

            for(auto x : l){
                string node = x.first;
                visited[node]=false;
            }

            for(auto x2 : l){
                string node2 =x2.first;
                if(visited[node2]!=true){
                    helper(node2,visited,order);
                }

            }

            for(auto x:order){
                cout<<x<<" ";
            }

        }

};



int main(){

Graph g;

g.addEdges("python","data processing");
g.addEdges("python","pytorch");
g.addEdges("python","ml basics");
g.addEdges("data processing","ml basics");
g.addEdges("pytorch","dl");
g.addEdges("ml basics","dl");
g.addEdges("dl","fai");
g.addEdges("data set","fai");

g.dfs_topsort2();


}