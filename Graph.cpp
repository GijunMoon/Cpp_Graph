#include <bits/stdc++.h>
using namespace std;

const int MAX_V = 1010;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef tuple<int, int, int> iii;

int AM[MAX_V][MAX_V];

int main() {

  int V; 
  scanf("%d", &V);                        
  for (int u = 0; u < V; ++u)                    
    for (int v = 0; v < V; ++v)                  
      scanf("%d", &AM[u][v]);

  printf("Neighbors of vertex 0:\n");
  for (int v = 0; v < V; ++v)                 
    if (AM[0][v])
      printf("Edge 0-%d (weight = %d)\n", v, AM[0][v]);

  scanf("%d", &V);
  vector<vii> AL(V, vii());                     
  for (int u = 0; u < V; ++u) {
    int total_neighbors; scanf("%d", &total_neighbors);
    while (total_neighbors--) {
      int v, w; scanf("%d %d", &v, &w); --v;     
      AL[u].emplace_back(v, w);
    }
  }

  printf("Neighbors of vertex 0:\n");            
  for (auto &[v, w] : AL[0])                     
    printf("Edge 0-%d (weight = %d)\n", v, w);

  int E; scanf("%d", &E);
  vector<iii> EL(E);                              
  for (int i = 0; i < E; ++i) {
    int u, v, w; scanf("%d %d %d", &u, &v, &w);
    EL[i] = tie(w, u, v);
  }
 
  sort(EL.begin(), EL.end());
  for (auto &[w, u, v] : EL)                     
    printf("weight: %d (%d-%d)\n", w, u, v);

  return 0;
}