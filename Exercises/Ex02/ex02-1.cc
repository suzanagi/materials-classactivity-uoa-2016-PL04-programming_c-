#include <iostream>
#include <vector>

using namespace std;

int main(){
  /*ベクトルをvectorを使用して宣言*/
  vector<double> u;
  vector<double> v;
  /*入力を受け付ける変数*/
  double input;
  /*カウンタ変数*/
  int i;
  /*内積を格納する変数*/
  double result = 0;

  /*ベクトルuの入力*/
  cout << "Input u" << endl;
  
  while(cin >> input){
    u.push_back(input);
  }

  
  /*cinをclear*/
  cin.clear();

  
  /*ベクトルvの入力*/
  cout << "Input v" << endl;

  while(cin >> input){
    v.push_back(input);
  }

  
  /*内積を求める*/
  for(i = 0; i < u.size(); i++){
    result += u[i] * v[i];
  }
  
   
  /*結果の出力*/
  cout << "Result: u*v = " << result << endl;
  
  return 0;

}

/* 計算機環境について
 * コンパイルに問題はありませんがMac環境で実行したところ、2回目のCtrl-Dが反応せず Segmentation fault となり
 * 正常に動作しなかったため、念のためSolaris環境で実行した場合の実行結果をコメントします。
 * Solaris環境では問題なく実行できます。
 * bash-4.4$ g++ ex02-1.cc
 * bash-4.4$ ./a.out
 * Input u
 * 1.0
 * 2.0
 * 3.0
 * 4.0
 * Input v
 * 1.5
 * 0.0
 * 1.0
 * 2.0
 * Result: u*v = 12.5
 * bash-4.4$ ./a.out
 * Input u
 * 2.5
 * 3.3
 * 1.8
 * 1.4
 * 1.2
 * 1.1
 * -0.5
 * 2.5
 * 1.9
 * 4.0
 * Input v
 * 1.2
 * 1.6
 * -1.2
 * 13.0
 * 4.5
 * -2.9
 * 3.1
 * 1.8
 * 0.45
 * -2.25
 * Result: u*v = 21.335
 */
