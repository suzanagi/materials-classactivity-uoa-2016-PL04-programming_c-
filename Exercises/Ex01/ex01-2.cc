#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(){
  /*ファイルから読み込んだ名前と学籍番号を格納する文字列型変数*/
  string snum;
  string name;
  /*カウンタ変数*/
  int i;
  /*ファイル名を格納する文字列型変数*/
  string fname;
  
  for(i = 1; i <= 12; i++){
    //人数とHello, を出力
    cout << i << ") " << "Hello, ";

    //ex01-inputから入力されたデータを読み取る
    cin >> snum;
    cin >> name;
    
    cout << name << " (" << snum << ")!" << endl;
    
    //5つ出力するごとに線を引いて区切る
    if((i % 5) == 0) cout << "------------------------------------" << endl;
  }
}
