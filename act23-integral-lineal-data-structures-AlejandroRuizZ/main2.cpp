#include<iostream>
#include<cstdlib>

using namespace std;
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

int main()
{


    char str[100]={"This is a pattern matching"};
    char substr[20]={"Alex"};
    int result;
    result=FindSbstr(str,substr);
    cout<< result <<endl;




    return 0;
}
