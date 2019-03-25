#include <algorithm>
#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;

/* プロトタイプ宣言 */
template <typename InItr, typename OutItr> OutItr my_copy(InItr, InItr, OutItr);

/* 動作確認のmain関数 */
int main(){

  //要素 {1, 2, 3}の int型vector を用意
  vector<int> intOrigin;
  intOrigin.push_back(1);
  intOrigin.push_back(2);
  intOrigin.push_back(3);

  //要素{1.0, 2.0, 3.0}の double型listを用意
  list<double> doubleOrigin;
  doubleOrigin.push_back(1.0);
  doubleOrigin.push_back(2.0);
  doubleOrigin.push_back(3.0);


  //それぞれの中身を表示
  cout << "[Original]" << endl;
  
  //intのvectorの中身を表示
  cout << "int型vector: {";
  for(vector<int>::iterator i = intOrigin.begin(); i != intOrigin.end(); i++) cout << *i << ", ";
  cout << "}" << endl;

  //doubleのlistの中身を表示
  cout << "double型list: {";
  for(list<double>::iterator d = doubleOrigin.begin(); d != doubleOrigin.end(); d++) cout << *d << ", ";
  cout << "}" << endl;

  
  //コピー先の int型vector を用意
  vector<int> intCopied(intOrigin.size());

  //コピー先の double型listを用意
  list<double> doubleCopied(doubleOrigin.size());


  //コピー
  my_copy(intOrigin.begin(), intOrigin.end(), intCopied.begin());
  my_copy(doubleOrigin.begin(), doubleOrigin.end(), doubleCopied.begin());


  //コピーした後の値の表示
  cout << "[Copied]" << endl;
  
  //コピーしたintのvectorの中身を表示
  cout << "int型vector: {";
  for(vector<int>::iterator i = intCopied.begin(); i != intCopied.end(); i++) cout << *i << ", ";
  cout << "}" << endl;

  //コピーしたdoubleのlistの中身を表示
  cout << "double型list: {";
  for(list<double>::iterator d = doubleCopied.begin(); d != doubleCopied.end(); d++) cout << *d << ", ";
  cout << "}" << endl;

  
  return 0;
}

/* ジェネリック関数 my_copy(b, e, dest) */
template <typename InItr, typename OutItr> OutItr my_copy(InItr b, InItr e, OutItr dest){
  
  while(b != e){
    *dest++ = *b++;
  }
  
  return dest;
}

/*実行結果
bash-4.4$ g++ ex08-2.cc
bash-4.4$ ./a.out
[Original]
int型vector: {1, 2, 3, }
double型list: {1, 2, 3, }
[Copied]
int型vector: {1, 2, 3, }
double型list: {1, 2, 3, }

*/
