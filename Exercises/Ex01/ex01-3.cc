#include <iostream>

using namespace std;

int main(){
  //配列A
  int A[15] = {2,4,-1,3,0,6,-1,8,9,-5,1,-4,2,6,-8};
  //総和を格納する変数
  int sum = 0;

  //ranged-forで総和を求める
  for(int i: A){
    //sumに加算する
    sum += i;
  }

  //総和を出力
  cout << sum <<endl;
  
  return 0;
}
