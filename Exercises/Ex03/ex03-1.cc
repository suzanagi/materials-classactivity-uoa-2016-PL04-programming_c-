#include <iostream>
#include <list>

using namespace std;

/*構造体宣言*/
typedef struct{
  string word;
  int wordCount;
}wordLibrary;

/*listの内容を全て表示する*/
void Listprint(list<wordLibrary>);
/*listに指定の１つの値が存在するか調べる*/
list<wordLibrary>::iterator Finditem(string, list<wordLibrary> &);
/*ソートルールの指示*/
bool sort_word(const wordLibrary&, const wordLibrary&);

int main(){

  //入力を保持する変数
  string input;
  //listに挿入するためのwordLibrary型の変数
  wordLibrary wl;
  //Library型の要素をもつlist
  list<wordLibrary> ls;
  //listを参照するためのイテレータ
  list<wordLibrary>::iterator itr;

  
  //変数wlの初期化
  wl.wordCount = 1;

  
  while(cin >> input){
    itr = Finditem(input, ls);
    
    if(itr == ls.end()){//初めて出現する単語の場合
      //単語を入れたwordLibrary変数を作成
      wl.word = input;
      //lsの末尾に挿入
      ls.push_back(wl);
    }
    else{//既にlist内に同じ要素があった場合
      (*itr).wordCount++;
    }
  }

  //単語のアルファベット順にソートする
  ls.sort(sort_word);
  
  //結果を出力
  Listprint(ls);
  
  return 0;
}

/*listから単語とカウントを出力する*/
void Listprint(list<wordLibrary> listdata){

  //listにアクセスするためのイテレータ
  list<wordLibrary>::iterator itr;

  //単語とカウントを出力する
  for(itr = listdata.begin(); itr != listdata.end(); itr++){
    cout << (*itr).word << " " << (*itr).wordCount << endl;
  }
}

/*listから、指定の１つの値を存在するか調べる*/
list<wordLibrary>::iterator Finditem(string key, list<wordLibrary> &listdata){

  //listにアクセスするためのイテレータ
  list<wordLibrary>::iterator itr;
  
  //keyの中身をlistdataから探索する
  for(itr = listdata.begin(); itr != listdata.end(); itr++){
    if((*itr).word == key) break;
  }
  
  //見つけた場所を返す
  return itr;
}

/*ソートルール指示*/
bool sort_word(const wordLibrary& x, const wordLibrary& y){
  return x.word < y.word;
}

/* 実行結果(Solaris環境)
 * bash-4.4$ ./a.out < testWord.txt
 * appl 1
 * apple 4
 * banana 3
 * cherry 1
 * kiwi 1
 * lemon 1
 * melon 2
 * orange 1
 */
