#include <iostream> // cin/cout用ヘッダー（C言語でいうstdio.h）
#include <string>   // 文字列型"string"型を使用する際のヘッダー
 
 
//stdという名前空間を使う
//⇒ これを最初に書いておくと、 std::cout や std::cin 等の記述を省略できる
using namespace std;
 
 
int main(){
  string name; //文字列型変数
   
  cout << "Input your name" << endl;  // coutが出力ストリーム
  cin >> name;  //cinが入力ストリーム、この場合は name へ入力
  cout << "Hello, " << name << "!" << endl;  // << で複数の出力項目を繋いでストリームに流せる。endlは改行(='\n')
 
  return 0;
}
