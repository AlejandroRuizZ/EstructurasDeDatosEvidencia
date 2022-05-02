#ifndef ACTIVITY_H
#define ACTIVITY_H

// =========================================================
// File: actitivy.h
// Author:
// Date:
// =========================================================

#include "ugraph.h"

template <class Vertex>
int ports(const UnweightedGraph<Vertex>* graph, int city, int mnp) {
  typename std::set<Vertex>::iterator itr;
  std::vector<Vertex> temp;
  std::set<Vertex> sorted;
  typename std::vector<Vertex>::iterator it;

  temp = graph->getVertexes();
  for( it = temp.begin(); it != temp.end(); ++it){
    if(*it == city){
      sorted = dfs(*it,graph,mnp);
      break;
    }
  }
  return sorted.size();
}


template <class Vertex>
bool existeEnL(std::set<Vertex> &mySet, std::set<Vertex> &myIter){
    for(Vertex x : mySet){
       if(myIter.contains(x))
           continue;
       else
           return false;
    }
    return true;
}

template <class Vertex>
void dfs2(/*Vertex v,*/ const UnweightedGraph<Vertex>* graph,
    std::set<Vertex> &reached, std::stack<Vertex> &TS) {
  typename std::set<Vertex> itr;

  while(!existeEnL(reached, itr)){
      for(Vertex x : reached){
          if(itr.contains(x))
              continue;
          else
              visit(x, itr, TS, graph);
      }
  }
}

template <class Vertex>
void visit(Vertex v, std::set<Vertex> &itr, std::stack<Vertex> &TS,
           const UnweightedGraph<Vertex>* graph){
    std::set<Vertex> mySet;
    if(itr.contains(v)){
        return;
    }
    mySet = graph->getConnectionFrom(v);
    for(Vertex x : mySet){
        visit(x, itr, TS, graph);
    }
    TS.push(v);
    itr.insert(v);
}

template <class Vertex>
std::string topologicalSort(const UnweightedGraph<Vertex>* graph) {
  typename std::vector<Vertex>::iterator itr;
  std::stringstream aux;
 std::set<Vertex> reached;
  std::vector<Vertex>temp;
  std::stack<Vertex> TS;
  Vertex v;
  temp=graph->getVertexes();
  for(Vertex elem : temp){
    reached.insert(elem);
  }
  dfs2(/*v,*/graph, reached, TS);
aux << "[";
  while (!TS.empty()){
    aux << TS.top();
    TS.pop();
    if(!TS.empty()){
      aux << " ";
    }
  }
  aux << "]";
  return aux.str();
}
template <class Vertex>
bool isBipartite(const UnweightedGraph<Vertex>* graph) {
  //typename std::vector<Vertex>::iterator itr;
  //typename std::set<Vertex>::iterator j;
  std::queue<Vertex> Q;
  std::vector<Vertex> temp = graph -> getVertexes();
  int Color[temp.size()];
  bool Bipartite = true;
  for(int i=0; i < temp.size(); i++){
    Color[i] = -1;
  }
  Vertex v = temp.front();
  std::stringstream cadena;
  cadena  << v;
  std::stringstream cadena2;
  Color[std::stoi(cadena.str())-1] = 1;
  Q.push(v);
  Vertex u;
  std::set<Vertex> mySet;
  while(!Q.empty()){
    u = Q.front();
    Q.pop();
    mySet = graph->getConnectionFrom(u);
    //if(!mySet.empty()){
      for(Vertex x : mySet){
        cadena << x;
          //if(Color[graph->indexOf(x)] == -1){
          if(Color[std::stoi(cadena.str()) - 1] == -1){
            cadena2 << u;
            //Color[graph->indexOf(x)] = 1 - Color[graph->indexOf(u)];
            Color[std::stoi(cadena.str()) - 1] = 1 - Color[std::stoi(cadena2.str()) - 1];
            Q.push(x);
          }
          else{
            if(Color[std::stoi(cadena.str())- 1] == Color[std::stoi(cadena2.str()) - 1]){
              Bipartite = false;
            }
          }
      }
    //}
  }
  return false;
}

template <class Vertex>
bool isCyclic(Vertex v, const UnweightedGraph<Vertex>* graph,
  std::set<Vertex> &reached, Vertex parent) {
  typename std::set<Vertex>::iterator itr;

  return false;
}

template <class Vertex>
bool isTree(const UnweightedGraph<Vertex>* graph) {
  typename std::vector<Vertex>::iterator itr;

  return false;
}

#endif /* ACTIVITY_H */
