// =================================================================
//
// File: main.cpp
// Author:
// Date:
//
// =================================================================
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "exception.h"
#include "header.h"
#include "list.h"
#include "boat.hpp"


using namespace std;
string* removeDupWord2(string str, char c){
	string word = "";
	int pointer = 0;
	int i = 0;
	string* dateArray = new string[3];
	for(auto x : str){
		if(x == c){
			dateArray[pointer] = word;
			pointer++;
			word = "";
		}else{
			word= word + x;
		}
		i++;
	}
	dateArray[pointer] = word;
	return dateArray;
}

string *removeDupWord(string str,char c){
	string word = "";
	string boatArray[4];
	string *dateArray;
	string *myArray = new string[6];
	int pointer = 0;
	//char c = '-';
	for(auto x : str){
		if(x == c){
			boatArray[pointer] = word;
			pointer++;
			word = "";
		}else{
			word= word + x;
		}
	}
	boatArray[pointer] = word;
	dateArray = removeDupWord2(boatArray[0], '-');
	myArray[0]=dateArray[0];
	myArray[1]=dateArray[1];
	myArray[2]=dateArray[2];
	myArray[3]=boatArray[1];
	myArray[4]=boatArray[2];
	myArray[5]=boatArray[3];
	return myArray;
	/*for(int j=0; j < 3; j++){
		cout<<dateArray[j]<<endl;
	}*/
}

string* removeDupWord3(string str, char c){
	string word = "";
	int pointer = 0;
	int i = 0;
	string* npArray = new string[2];
	for(auto x : str){
		if(x == c){
			npArray[pointer] = word;
			pointer++;
			word = "";
		}else{
			word= word + x;
		}
		i++;
	}
	npArray[pointer] = word;
	return npArray;
}
//array[pointer] = word;

int FindSbstr(string str, string substr){
  int i,j,temp;
  for(i=0;str[i]!='\0';i++){
      j=0;
      if(str[i]==substr[j]){
          temp=i+1;
          while(str[i]==substr[j]){
              i++;
              j++;
          }
          if(substr[j]=='\0')
              return 1;
          else{
              i=temp;
              temp=0;
          }
      }
  }
  if(temp==0){
    return 0;
  }
  return 0;
}


int main(int argc, char* argv[]) {
	std::ifstream f("input1.txt");
  std::string line;
	char c=' ';
	string *data = new string[6];
	string *np = new string[2];
	std::getline(f, line);
	np = removeDupWord3(line, c);
	int day;
	int month;
	int year;
	DoubleLinkedList<Boat> *ListaDeBarcosM = new DoubleLinkedList <Boat>();
	DoubleLinkedList<Boat> *ListaDeBarcosR = new DoubleLinkedList <Boat>();
  while(std::getline(f, line)){
    data = removeDupWord(line,c);
    // instancia objeto clase Boat
		// asignar valores de @data@ a los campos del objeto
		day=stoi(data[0]);
		month=stoi(data[1]);
		year=stoi(data[2]);
		string s1(data[3]);
		string s2(data[4]);
		string s3(data[5]);
		string s4 = "";
		for(char ch : np[1]){
				s4 += ch;
		}
		char myString[3];
		myString[0] = s4[0];
		myString[1] = s4[1];
		myString[2] = s4[2];
		int found = FindSbstr(s3,myString);
		Boat Barco = Boat(day,month,year,s1,s2,s3);
		if(found){
			if(Barco.getPort() == "M"){
				ListaDeBarcosM -> push_back(Barco);

			}
			else{
				ListaDeBarcosR -> push_back(Barco);
			}
		}
  }
	if(!(ListaDeBarcosM -> empty())){
		ListaDeBarcosM -> getFinalResult("M");
	}
	if(!(ListaDeBarcosR -> empty())){
		ListaDeBarcosR -> getFinalResult("R");
	}
	// quiza tengas listas R y M
	// ordenas listas por mes
	return 0;
}
