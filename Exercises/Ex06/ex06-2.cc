#include <iostream>
using namespace std;
  
class Wolf{//オオカミクラス
private:
 string name;  //名前
 int hungry;   //満腹度
 int h_speed;  //腹減りの速さ
public:
  Wolf(int, int, string); //コンストラクタ
  ~Wolf();                //デストラクタ
  string ShowName();      //名前を取得（ゲッター）
  int FindState();        //満腹度を調べる（ゲッター）
  int Feed(int);          //エサを与える
  int Timestep();         //時間を1刻み分進める（満腹度が下がる）
};  
 
 
int main(){
  Wolf *x,*y,*z;
  int *feeds = new int[3]; //エサ箱に相当するint型配列を確保
  feeds[0]=5;//それぞれのオオカミに与えるエサの量を決める
  feeds[1]=10;
  feeds[2]=20;
  x = new Wolf(100,20,"X");  //満腹度100,腹減りの速さ20、名前"X"
  y = new Wolf(65,30,"Y");   //満腹度65,腹減りの速さ30、名前"Y"
  z = new Wolf(150,50,"Z");  //満腹度30,腹減りの速さ50、名前"Z"
 
  cout << "[[Wolves Breeding Simulation]]" << endl;
 
  /****************************** !!ここから下にバグあり!! ******************************/
  for(int day=1; x!=NULL || y!=NULL || z!=NULL ; day++){ //全部が同時に死んでいない限り飼育を続ける
 
    cout << "<Day " << day << ">" << endl;
    
    //餌を与える(もし、死んでいるものがいれば、新しいものを連れて来る)
    /* if(x!=NULL) x.Feed(feeds[0]);  <- ポインタ型を参照するにはアロー演算子などが必要 */
    if(x!=NULL) x->Feed(feeds[0]); // <- 訂正したもの
    /* else x = new Wolf;             <- 引数なしのコンストラクタが存在しないので変数を追加する */
    else x = new Wolf(100, 20,"X");// <- 訂正したもの
    /* if(y!=NULL) y.Feed(feeds[1]);  <- ポインタ型を参照するにはアロー演算子などが必要 */
    if(y!=NULL) y->Feed(feeds[1]); // <- 訂正したもの
    else y = new Wolf(65,30,"Y");
    /* if(z!=NULL) z.Feed(feeds[2]);  <- ポインタ型を参照するにはアロー演算子などが必要 */
    if(z!=NULL) z->Feed(feeds[2]); // <- 訂正したもの
    else z = new Wolf(150,50,"Z");
 
    //時間を経過させる(それぞれ、一定の割合で空腹になる)
    if(x!=NULL) x->Timestep();
    if(y!=NULL) y->Timestep();
    if(z!=NULL) z->Timestep();
 
 
    //健康管理(もし空腹で死んでいたら、その時点でそのオブジェクトは破棄する)
    if(x!=NULL){
      /* cout << "Wolf \""<< x.name <<"\": " << (*x).FindState() << " " << endl; <- nameはアロー演算子などを用いて関数を呼びアクセスしなくてはならない */
      cout << "Wolf \""<< x->ShowName()  <<"\": " << (*x).FindState() << " " << endl;
      if( x->FindState() <= 0 ){ 
          delete x; //餓死したら破棄
      x = NULL; //deleteしただけだと、メモリに値が残っている可能性がある or 多重解放のリスクがあるので明示的にNULL(=0)でリセット＆死んでいる判定にも使える
      }
    }
 
    if(y!=NULL){
      /* cout << "Wolf \""<< y.name <<"\": " << (*y).FindState() << " " << endl; <- nameはアロー演算子などを用いて関数を呼びアクセスしなくてはならない */
      cout << "Wolf \""<< y->ShowName() <<"\": " << (*y).FindState() << " " << endl; 
      if( y->FindState() <= 0 ){
          delete y;
      y = NULL;
      }
    }
 
    if(z!=NULL){
      /* cout << "Wolf \""<< z.name  <<"\": " << (*z).FindState() << " " << endl; <- nameはアロー演算子などを用いて関数を呼びアクセスしなくてはならない */
      cout << "Wolf \""<< z->ShowName()  <<"\": " << (*z).FindState() << " " << endl;
      if( z->FindState() <= 0 ){
          delete z;
      z = NULL;
      }
    }
 
  }
  /* delete feeds; //飼育員引退（最後にエサ箱を破棄する）<- 配列をdeleteするときには[]が必要 */
  delete []feeds; //飼育員引退（最後にエサ箱を破棄する） <- 訂正したもの
  
  /****************************** !!バグありここまで!! ******************************/
 
  cout << "Sorry, all wolves were dead." << endl;
 
return 0;
}
 
 
//オオカミクラスのメンバー関数定義
Wolf::Wolf(int val1,int val2, string val3){//コンストラクタ(引数1:満腹度, 引数2:腹減り速さ, 引数3:名前)
  if(val1>=1)  hungry = val1; // 引数の値が0以下の場合いきなり死んでしまうので、それを回避する
  else hungry = 10;
  h_speed = val2;
  name = val3;
  cout << "[" << name << "] " << "WOOOOOOON!! hungry:" << hungry << endl;
}
 
string Wolf::ShowName(){//名前を返す
  return name;
}
 
int Wolf::FindState(){//満腹度を返す
  return hungry;
}
 
int Wolf::Feed(int quantity){//引数で与えられた量のエサを与える（満腹度が回復する)
  int old = hungry;
  hungry+=quantity;
  cout << "You gave a feed to wolf " << name << ". (" << old << " => " << hungry << ")" <<  endl;
  return hungry;
}
 
int Wolf::Timestep(){//各々のスピードで満腹度が下がる
  hungry -= h_speed;
  return hungry;
}
 
Wolf::~Wolf(){//デストラクタ(餓死したときにオブジェクトを破棄する)
  cout << "This wolf named " <<"\""<< name << "\" " <<  "was dead." << endl;
}

/*実行結果
...
<Day 70>
You gave a feed to wolf X. (5 => 10)
You gave a feed to wolf Y. (15 => 25)
You gave a feed to wolf Z. (10 => 30)
Wolf "X": -10 
This wolf named "X" was dead.
Wolf "Y": -5 
This wolf named "Y" was dead.
Wolf "Z": -20 
This wolf named "Z" was dead.
Sorry, all wolves were dead.
*/
