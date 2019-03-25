#include <string>
#include <iostream>
#include <vector>
 
using namespace std;
 
class ticket{
public:
 string ID;
 string seat;
 ticket(): ID("***"),seat("***"){
   cout << "ticket default constructor" << endl;
 }
 ticket(string i, string t): ID(i), seat(t){
   cout << "ticket parameter-constructor" << endl;
 }
  virtual void printInfo() = 0;
  /*
 void printInfo(){
  cout << "ID:" << ID << " Seat:" << seat << endl;
  }*/
};
  
class airplaneTicket: public ticket{
public:
 string flight;
 airplaneTicket():flight("***"){
   cout << "airplane default constructor" << endl;
 }
 airplaneTicket(string i, string t, string f): ticket(i,t), flight(f){
  cout << "airplane parameter-constructor" << endl; 
 }
 void printInfo(){
  cout << "ID:" << ID << " Seat:" << seat << " Flight No:" << flight << endl;
 }
};
 
class cinemaTicket: public ticket{
public:
 string movie;
 cinemaTicket():movie("***"){
  cout << "cinema default constructor" << endl;
 } 
 cinemaTicket(string i, string t, string m): ticket(i,t),movie(m){
  cout << "cinema parameter-constructor" << endl;
 }
 void printInfo(){
  cout << "ID:" << ID << " Seat:" << seat << " Movie Name:" << movie << endl;
 }
}; 
  
int main(){
 ticket *tList[100];
 tList[0] = new airplaneTicket();
 tList[1] = new cinemaTicket("123","45a","Flight to the Future");
 for(int i=0;i<2;i++) tList[i]->printInfo();
 return 0;
} 
