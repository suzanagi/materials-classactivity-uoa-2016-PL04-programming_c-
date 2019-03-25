#include <algorithm>
#include <iostream>
#include <vector>
#include <list>
 
using namespace std;
  
template <typename TextItr, typename SearchItr> 
TextItr my_search(TextItr, TextItr, SearchItr, SearchItr);
 
int main() {
 
  #ifndef STRING
  int val;
  vector<int> v;
  list<int> ls;
  
  cout << "Input  " << endl;
  while(cin >> val){
    v.push_back(val);
  }
  cin.clear();
 
  cout << "Input Search data" << endl;
  while(cin >> val){
    ls.push_back(val);
  }
  vector<int>::iterator it;
  vector<int>::iterator it2;  
  #else
  string v, ls;
  cout << "Input  " << endl;
  cin >> v;
  cout << "Input Search data" << endl;
  cin >> ls;
 
  string::iterator it;
  string::iterator it2;
  #endif
   /*
　　これより上で、変数の定義を行う。
　　コンパイル時に、引数に渡る変数型に応じてジェネリック関数の引数の型が自動で対応する。
　　*/
 
 
  it = search(v.begin(), v.end(), ls.begin(), ls.end());      //オリジナルのSTL関数
  it2 = my_search(v.begin(), v.end(), ls.begin(), ls.end());   //自作ジェネリック関数
 
   //STLの結果
  if (it == v.end())  cout << "[STL]not found" <<endl;
  else  cout << "[STL]found: index=" << distance(v.begin(), it) << endl;
 
   //自作関数の結果
  if (it2== v.end())  cout << "[MY TEMPLATE]not found" <<endl;
  else cout << "[MY TEMPLATE]found: index=" << distance(v.begin(), it2) << endl;
 
  return 0;
}
 
 
/*
自作ジェネリック関数 my_search
サーチ対象の値を持つ変数の先頭、末尾のイテレータと、
サーチする変数の値の入った先頭、末尾のイテレータを引数に渡す
 
Brute-Forceアルゴリズム（誰でも思いつく最も単純な全パターン体当たり検索方式）で
１つずつサーチ対象の値を探していって、見つけた場所の先頭のイテレータを返す。
*/
template <typename TextItr, typename SearchItr> 
TextItr my_search(TextItr b1, TextItr e1, SearchItr b2, SearchItr e2){
 
TextItr Titr = b1, Start_point = b1;
SearchItr Sitr = b2;
 
 while(Titr!=e1 && Sitr!=e2){//どちらの文字列も終端に達していなければ
   if(*Titr == *Sitr){//変数のある１要素同士を比較する
     Titr++;  //ある１要素が一致していれば（まだ完全一致の可能性があるなら）次の要素の比較へ進む
     Sitr++;
   }
   else{
     Start_point++;
     Titr = Start_point; //一致していないと分かれば、次のパターンへ（比較開始位置を１つずらしてやり直し）
     Sitr = b2;          //変数B側は先頭から比較をやり直し
   }
 }
 
 return Start_point; // 一致しているなら一致した先頭の場所、そうでなければ終端の場所
}
