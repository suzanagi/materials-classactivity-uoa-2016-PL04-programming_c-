#include <iostream>
 
using namespace std;
 
int main(){
  int a;//デフォルトコンストラクタ ⇒ どうなるかは環境依存
  int b(3);//引数１個のコンストラクタ
  int c = 5;//内部的に「オブジェクトへの代入＝オブジェクト内の相当する変数の値のセット」
  double d(3.14);//doubleも同じ
 
  cout << "a=" <<  a << endl;
  cout << "b=" <<  b << endl;
  cout << "c=" <<  c << endl;
  cout << "d=" <<  d << endl;
  
  return 0;
}
