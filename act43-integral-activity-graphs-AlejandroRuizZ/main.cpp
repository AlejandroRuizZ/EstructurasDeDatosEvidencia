// =================================================================
//
// File: main.cpp
// Author:
// Date:
//
// =================================================================
#include <iostream>
#include "ugraph.h"
#include "activity.h"
#include <fstream>
#include <map>
using namespace std;

int main(int argc, char* argv[]) {
	int n, from, to, counter,id1,id2,result;
	UListGraph<int> *graph;
	ifstream input;
	string nose,city1,city2;
	set<string> cityset;
	set<string>::iterator itr;
	map<string,int> citymap;
	map<string,int>::iterator it, it2;

	input.open("input1.txt");
	input >> n;
	for(int i =0; i < n; i++){
		input >> city1 >> city2;
		cityset.insert(city1);
		cityset.insert(city2);
	}
	counter = 0;
	for (itr = cityset.begin(); itr != cityset.end(); itr++){
		citymap.insert(make_pair(*itr,counter));
		counter++;
	}
	input.close();
	graph = new UListGraph<int>(cityset.size());
	input.open("input1.txt");
	input >> n;
	while (n) {
		input >> city1 >> city2;
		it = citymap.find(city1);
		it2 =citymap.find(city2);
		id1 = it->second;
		id2 = it2->second;

		graph->addEdge(id1, id2);
		graph->addEdge(id2, id1);
		n--;
	}
	int queries,mnp;
	input >> queries;
	int cont = 1;
  while(queries){
		//ports(graph,city,mnp);
		input >> city1 >> mnp;
		it = citymap.find(city1);
		id1 = it->second;
			result = ports(graph,id1,mnp);
			//result = ports(graph,6,4);
			//cout << result <<endl;
			cout << "Case " << cont <<": " << cityset.size() - result << " ports not reachable from port " << it->first << " with MNP = " << id1 << "."<<endl;
			cont++;
			queries--;
  }
	//cout << sorted << endl;
	delete graph;
	return 0;
}
