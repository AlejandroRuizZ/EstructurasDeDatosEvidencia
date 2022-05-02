#include <iostream>
#include <string>
#include <vector>
#include "header.h"
using namespace std;

 class Boat{
  private:
    int day;
    int month;
    int year;
    string time;
    string port;
    string ubi;
  public:
    Boat();
    Boat(int day_,int month_,int year_, string time_, string port_, string ubi_);
    int getMonth();
    string getData();
    string getPort();
    string getUbi();
};

Boat::Boat(int day_,int month_,int year_,string time_, string port_, string ubi_){
  day=day_;
  month=month_;
  year=year_;
  time=time_;
  port=port_;
  ubi=ubi_;
}

int Boat::getMonth(){
  return month;
}


string Boat::getData(){
  return  time + " " + port + " " + ubi;
}

string Boat::getPort(){
  return port;
}

string Boat::getUbi(){
  return ubi;
}
