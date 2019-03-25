#include <iostream>
#include <map>
#include <string>
using namespace std;
 
int main(){
  string name;
  map<string, int> candidate;
   
  while(cin >> name){ //投票（入力）された候補者の名前をキーにして、対応するmap"candidate"の要素をカウントアップ
    candidate[name]++;
  }
 
  cout << "[Voting Result]" << endl;
  map<string, int>::iterator itr; //mapを巡回するためのイテレータを宣言
  for(itr = candidate.begin(); itr != candidate.end();itr++){
       cout << "Name:" <<  itr->first         // itr を利用して、mapのキーを出力
     << "            Number of votes obtained:" << itr->second        // itr を利用して、mapの値を出力
     << endl; 
  }
  return 0;
}

/*実行結果
bash-4.4$ g++ ex04-2.cc
bash-4.4$ ./a.out < voting.txt
[Voting Result]
Name:arai            Number of votes obtained:22
Name:hirasawa            Number of votes obtained:31
Name:kazawa            Number of votes obtained:24
Name:makiguchi            Number of votes obtained:26
Name:takahashi            Number of votes obtained:29
Name:yabe            Number of votes obtained:31
Name:yoshida            Number of votes obtained:37
 */
