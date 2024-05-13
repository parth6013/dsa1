// it works for directed graph for UG you have to convert it into directed graph

// it works for ive edges and detects if graph has negative cycle or not

// Time complexity is O(n-1)*O(edges)

// #include<bits/stdc++.h>
#include<vector>
using namespace std;

int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    // Write your code here.
   vector<int> d(n+1,1000000000);

// Distance of source to source is 0.

d[src] = 0;

 

// Apply bellmonford algorithm.

// n-1 times re

for (int i = 1; i < n; i++)

{

 for (int j = 0; j < m; j++)

 {

  int u = edges[j][0];

  int v =  edges[j][1];

  int w =  edges[j][2];

 

  if (d[u] != 1000000000 && d[v] > (d[u] + w)) {

   d[v] = d[u] + w;

  }

 }

}


// Return the distance of destination.

// if we run the loop one more time and if dist array changes means it have a negative cycle

return d[dest];

   }
    
    
