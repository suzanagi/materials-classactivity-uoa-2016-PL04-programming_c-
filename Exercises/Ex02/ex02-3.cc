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

  /*各プレイヤーの手札を出力する(確認用)
  for(int i = 0; i < 4; i++){
    // [playerX]部分の出力
    cout << "[player" << i+1 << "]";
    // forループでイテレータを用いて4人のvectorにアクセスし手札を全て出力する
    for(it = vec[i].begin(); it != vec[i].end(); it++)
      cout << " " << *it;
    cout << endl;
  }
  */
  
  /*重複したカードを捨てるのに用いるイテレータの宣言*/
  vector<int>::iterator check;
  
  /*各プレイヤーの手札にアクセスし重複したカードを捨てる*/
  for(int i = 0; i < 4; i++){
    /*ループ中で前の手札を記憶する変数*/
    int x = 0;
    for(it = vec[i].begin(); it != vec[i].end(); it++){
      /*前の手札と同じだった場合*/
      if(*it == x){
	/*末尾の手札かどうかの確認*/
	check = it;
	check++;
	/*末尾の手札だった場合処理の後にbreak*/
	if(check == vec[i].end()){
	  check--;
	  check--;
	  if(*it == *check){
	    vec[i].erase(it);
	    vec[i].erase(check);
	  }
	  break;
	}
	/*末尾でない手札の場合通常の削除処理*/  
	it--;
	it = vec[i].erase(it);
	it = vec[i].erase(it);
      }
      /*次のループで比較するため現在の手札を記憶*/
      x = *it;
    }
  }
  
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

/* 念のため実行結果をコメントします。
 * bash-4.4$ g++ -std=c++11 ex02-3.cc
 * bash-4.4$ ./a.out
 * 52
 * [player1] 1 2 3 5 6 7 9 10 13
 * [player2] 1 4 5 7 9 11 12
 * [player3] 1 2 3 4 5 6 7 8 13
 * [player4] 1 3 4 5 6
 * bash-4.4$ ./a.out
 * 22
 * [player1] 1 4 6 9 11 12
 * [player2] 1 3 9 10
 * [player3] 11 12 13
 * [player4] 3 8 13
 * bash-4.4$ g++ -std=c++11 ex02-3.cc
 * bash-4.4$ ./a.out
 * 52
 * [player1] 2 5 7 8 9 11 12
 * [player2] 1 2 5 6 7 12 13
 * [player3] 2 8 12
 * [player4] 1 2 4 5 7 8 9 12 13
 * bash-4.4$ ./a.out
 * 22
 * [player1] 1 4 7 9
 * [player2] 3 11
 * [player3] 2 3 5 8 9
 * [player4] 2 9 13
 */
