#include <iostream>
#include <map>
#include <vector>
#define NUM 100
 
using namespace std;
 
int main(){
  int n, mod;
  map<int, vector<int> > integers; //キーを int, 値を int型のvectorコンテナとするmap "integers"を宣言
 
  cout << "Input modulus ->";
  cin >> n;
  
  for(int i=0;i<NUM;i++){
    integers[i % n].push_back(i);      //値 i を、 n で割った余りごとに map "integers"に振り分ける
  }
   
  cout << "Input display class ->";
  cin >> mod; //ｍの値を入力する
 
  cout << "Members in <" << mod << ">" << endl; //余りがｍになる整数たちを列挙する
  vector<int>::iterator itr;   //そのために、値を順に出力するためのイテレータを宣言
  for(itr = integers[mod].begin(); itr != integers[mod].end(); itr++){ //イテレータが、データの先頭から末尾に向かう間ループする
    cout << *itr << endl; // itr が指す値（整数）を出力
  }
 
  return 0;
}

/*実行結果
bash-4.4$ g++ ex04-3.cc
bash-4.4$ ./a.out
Input modulus ->11
Input display class ->9
Members in <9>
9
20
31
42
53
64
75
86
97
bash-4.4$ ./a.out
Input modulus ->12
Input display class ->5
Members in <5>
5
17
29
41
53
65
77
89
 */
