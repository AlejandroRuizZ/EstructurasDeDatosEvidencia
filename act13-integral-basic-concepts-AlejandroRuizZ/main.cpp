// =================================================================
//
// File: main.cpp
// Author:
// Date:
//
// =================================================================
#include <iostream>
#include <string>
#include <vector>
#include "header.h"
using namespace std;

class Boat {
public:
	string Date;
	string Hour;
	string Entry;
	string Ubi;


	Boat();
	Boat(string,string,string,string);
	string DetailBoat();


};

Boat::Boat(string date, string hour, string entry, string ubi){
	Date= date;
	Hour=hour;
	Entry=entry;
	Ubi=ubi;
}
string Boat::DetailBoat(){
	string info = "Date: " + Date + " Hour: " + Hour + " Entry: " + Entry + " Ubi: " + Ubi + "\n";
	return info;
}

void Filter(std::vector<Boat> &v,string prefix, string ubi, string date, string entry,string hour){
	int filter = ubi.find(prefix);
	if(filter != string::npos){
		v.push_back(Boat(date,hour,entry,ubi));
	}

}

template <class T>
void bubbleSort(std::vector<T> &v) {
	std::string y1,y2,m1,m2,d1,d2;
	for(int i = v.size() - 1; i > 0; i--){
		for(int j = 0; j < i; j++){
			y1=v[i].Date.substr(6,2);
			m1=v[i].Date.substr(3,2);
			d1=v[i].Date.substr(0,2);

			y2=v[i+1].Date.substr(6,2);
			m2=v[i+1].Date.substr(3,2);
			d2=v[i+1].Date.substr(0,2);

			if(y1==y2){
				if(m1==m2){
					if(d1<d2){
						swap(v, j, j + 1);
					}
				}
				else{
					if(m1<m2){
						swap(v, j, j + 1);
					}
				}
			}
			else{
				if(y1<y2){
				swap(v, j, j + 1);
				}

			}
		}
	}
}



int main(int argc, char* argv[]) {
	int n;
	string prefix, date, hour, entry,ubi;
	vector<Boat> Boats;
	vector<string> strings ={"lol1", "lol2","lol3"};

	cin >> n >> prefix;

	for (int i=0; i < n; i++){
		cin >> date;
		cin >> hour;
		cin >> entry;
		cin >> ubi;

		Filter(Boats,prefix,ubi,date,entry,hour);
	}

	bubbleSort(Boats);

	for(int i=0; i < Boats.size(); i++){
		cout << Boats[i].DetailBoat();
	}
	return 0;
}
