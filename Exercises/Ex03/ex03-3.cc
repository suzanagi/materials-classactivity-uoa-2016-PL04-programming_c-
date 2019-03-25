#include <iostream>
#include <list>

/*ノード(頂点)の数*/
#define NNUM 6
/*カラーコードを決める*/
#define WHITE 2
#define GRAY 1
#define BLACK 0

void dfs(int);
void dfsvisit(int);

using namespace std;

/*頂点の情報を保持する構造体を宣言*/
struct Node{
  int vertex;
  /*探索の状態で色を変える*/
  int color;
  //探索を開始した時間
  int discover;
  //探索を終了した時間
  int finish;
};

/*DFSに用いるtimerの宣言*/
int timer = 0;
/*リストの宣言*/
list<Node *> ls[NNUM];
/*各ノード(頂点)の情報を保持するNodeの宣言*/
Node node[NNUM];
/*全域木を出力するために用いるtFlag*/
bool tFlag = false;

int main(){

  /*頂点の情報の初期化*/
  for(int i = 0; i < NNUM; i++){
    node[i].vertex = i + 1;
    node[i].color = WHITE;
    node[i].discover = 0;
    node[i].finish = 0;
  }		      
  
  /*入力を保持する変数*/
  int input;

  /*隣接行列の入力*/
  cout << "Input the Adjacency matrix:" << endl;
  for(int i = 0; i < NNUM; i++){
    for(int j = 0; j < NNUM; j++){
      cin >> input;
      switch(input){
      case 1:
	ls[i].push_back(&node[j]);
	break;
      case 0:
	break;
      default:
	cout << "Please input '0' or '1' as this matrix." << endl;
	break;
      }
    }
  }
  
  /*改行*/
  cout << endl;

  /*リストにアクセスするイテレータの宣言*/
  list<Node *>::iterator itr;
  
  /*隣接リストの出力*/
  for(int i = 0; i < NNUM; i++){
    cout << "V" << i + 1 << "  is adjacent to ";
    for(itr = ls[i].begin(); itr != ls[i].end(); itr++){
      cout << (*itr)->vertex << " ";
    }
    cout << endl;
  }

  /*改行*/
  cout << endl;

  /*探索を開始する頂点を入力*/
  while(1){
    cout << "Input the initial node: ";
    cin >> input;
    if(input < 1 || 6 < input) cout << "Please input 1 to 6 as node" << endl;
    else break;
  }

  cout << "The edges in the DFS tree with root " << input << " are:" << endl;
  
  /*入力されたノードから深さ優先探索を行うとともに全域木を出力する*/
  dfs(input - 1);
  
  return 0;
}

/*深さ優先探索*/
void dfs(int n){

  /*listにアクセスするためのイテレータを宣言*/
  list<Node *>::iterator itr;
  
  /*入力されたノードと接続していなくても必ず探索するようにする*/
  for(int i = n; i < NNUM + n; i++){
    itr = ls[i].begin();
    if(node[n].color == WHITE){
      dfsvisit(i % NNUM);
    }
  }

  
  
}

void dfsvisit(int u){
  
  /*イテレータの宣言*/
  list<Node *>::iterator itr = ls[u].begin();

  /*探索を開始したことをカラーにマーク*/
  node[u].color = GRAY;

  /*全域木の表示を行う*/
  if(tFlag == true) cout << u + 1 << ")"<< endl;
  
  /*timerを更新*/
  timer++;
  /*探索開始の時間を記録*/
  node[u].discover = timer;
  
  /*探索を開始*/
  itr = ls[u].begin();
  while(1){
    if(itr == ls[u].end()) break;
    if((*itr)->color == WHITE){
      /*全域木の表示を行う*/
      cout << "( " << u + 1 << ", ";
      tFlag = true;
      /*再帰を用いて探索を行う*/
      dfsvisit(((*itr)->vertex) - 1);
    }
    itr++;
  }
  
  /*探索が完了したことをカラーにマーク*/
  node[u].color = BLACK;

  /*timerを更新*/
  timer++;
  /*探索終了の時間を記録*/
  node[u].finish = timer;
  
}

/*実行結果(Mac環境)
  bash-3.2$ ./a.out
  Input the Adjacency matrix:
  0 1 0 1 1 0
  0 0 0 1 0 1
  0 1 0 0 0 0
  1 0 0 0 0 0
  0 1 0 0 0 1
  1 0 1 0 1 0
  
  V1  is adjacent to 2 4 5 
  V2  is adjacent to 4 6 
  V3  is adjacent to 2 
  V4  is adjacent to 1 
  V5  is adjacent to 2 6 
  V6  is adjacent to 1 3 5 
  
  Input the initial node: 1
  The edges in the DFS tree with root 1 are:
  ( 1, 2)
  ( 2, 4)
  ( 2, 6)
  ( 6, 3)
  ( 6, 5) 
*/
