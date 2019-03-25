#include <iostream>
#include <string>
 
using namespace std;
 
 
int main(){
  string str1 = "apple";   
  string str2("pen");      //<1>
  string str3(10, '*');    //<2>
  string str4;
 
  string out1 = str1+str2; //<3>
  string out2 = str2;
  int out3 = out1.size();  //<4>
  string out4;
   
  out1.insert(out1.begin()+5, '-');  //<5>
  out2 += '!';  //<6>
  out4 = out1;
  out4.erase(out4.begin() + 1, out4.begin() + 8); //<7>
 
   
  cout << str3 << endl;
  cout << out1 << endl;  
  cout << out2 << endl;  
  cout << out3 << endl;
  cout << str4.empty() << endl; //<8>
  cout << out4 << endl;  
  cout << str3 << endl;
   
  return 0;
}
