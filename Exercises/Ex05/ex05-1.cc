#include <iostream>
using namespace std;
 
class Test{
public:
  int x1, x2;
  double center(){
    return (x1 + x2) * 0.5;
  }
};
 
int main(){
 
  Test a, b;

  cin >> a.x1;
  cin >> a.x2;

  cout << "a: " << a.center() << endl;
  cout << "b: " << b.center() << endl;
 
  return 0;
}

/*実行結果
bash-4.4$ g++ ex05-1.cc
bash-4.4$ ./a.out
4 8
a: 6
b: 1.35163e+08
bash-4.4$ ./a.out
0 3
a: 1.5
b: 1.35163e+08
bash-4.4$ ./a.out
3 6
a: 4.5
b: 1.35163e+08
*/
