#include <iostream>
#include <random>
#include <algorithm>
#include <vector>
 
using namespace std;
 
int main(){
  /*乱数の発生に用いる変数*/
  random_device rnd;  
  int a;
  /*山札の枚数の指定*/
  int n;
  /*山札のvector*/
  vector<int> dick;
  /*4人分のvector*/
  vector<int> vec[4];
  /*カウンタ変数*/
  int i = 0;
  
  /*山札の枚数の入力を受け付ける*/
  cin >> n;

  /*nの数だけ乱数を発生させ山札aに格納*/
  for(int i=0;i<n;i++){
   a = rnd()%13+1;
   //ここで、aをvectorコンテナへ
   dick.push_back(a);
  }

  /*山札のvectorは<int>なのでvector<int>に対するイテレータを宣言*/
  vector<int>::iterator it;
  
  /*4人に余らせることなく配布*/
  for(it = dick.begin(), i = 0; it != dick.end(); it++, i++){
    /*4人のvectorの配列に順番にアクセスしplayer0から山札の数字を格納していく*/
    vec[i%4].push_back(*it);
  }

  /*各プレイヤーの手札をソートする*/
  for(int i = 0; i < 4; i++) sort(vec[i].begin(), vec[i].end());

  /*各プレイヤーの手札を出力する*/
  for(int i = 0; i < 4; i++){
    /*[playerX]部分の出力*/
    cout << "[player" << i+1 << "]";
    /*forループでイテレータを用いて4人のvectorにアクセスし手札を全て出力する*/
    for(it = vec[i].begin(); it != vec[i].end(); it++)
      cout << " " << *it;
    cout << endl;
  }
 
  return 0;
}
/* 念のため以下に動作結果をコメントしておきます。
 * std6dc39{s1240234}78: g++ ex02-2.cc
 * std6dc39{s1240234}79: ./a.out
 * 52
 * [player1] 2 2 2 7 7 8 9 10 10 10 10 12 13
 * [player2] 1 1 1 1 2 3 5 6 7 9 11 12 13
 * [player3] 1 3 4 4 5 5 5 5 6 7 11 13 13
 * [player4] 3 4 5 5 6 7 7 8 9 9 9 10 10
 * std6dc39{s1240234}80: ./a.out
 * 22
 * [player1] 1 1 1 3 11 12
 * [player2] 1 1 3 8 11 13
 * [player3] 1 5 9 11 12
 * [player4] 2 3 4 10 11
 */
