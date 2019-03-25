#include <iostream>
using namespace std;
 
class Test{
private:
  int p, q;
public:
  void x1_set(int x){
    p = x;
  }
  void x2_set(int x){
    q = x;
  }
  int x1_get(){
    return p;
  }
  int x2_get(){
    return q;
  }
  double center(){
    return (p + q) * 0.5;
  }
};
 
int main(){
 
  Test a, b;
  int input;

  cin >> input;
  a.x1_set(input);
  cin >> input;
  a.x2_set(input);

  cout << "x1 = " << a.x1_get() << ", x2 = " << a.x2_get() << endl;
  
  cout << "a: " << a.center() << endl;
  cout << "b: " << b.center() << endl;
 
  return 0;
}

/* 構造体で実装された場合との違い
 * 構造体で実装した場合、main関数からTestの変数xに対し直接アクセスするため、
 * 変数名を変更する場合に変数名の出現する全てのコードを書き直す必要があるが、
 * クラスで関数を用いてアクセスする場合、コードを書き直す範囲はクラスの中だけで済む。
 */

/*実行結果
bash-4.4$ g++ ex05-2.cc
bash-4.4$ ./a.out
4 8
x1 = 4, x2 = 8
a: 6
b: 1.35163e+08
bash-4.4$ ./a.out
0 3
x1 = 0, x2 = 3
a: 1.5
b: 1.35163e+08
bash-4.4$ ./a.out
5 10
x1 = 5, x2 = 10
a: 7.5
b: 1.35163e+08
*/
