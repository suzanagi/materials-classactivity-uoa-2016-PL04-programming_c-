#include <iostream>
 
using namespace std;
 
class Test{
//フレンド関数
//外部の通常の関数「setval()」からは、あたかもsetval()がクラスのメンバー関数であるかのように
//private宣言されたこのクラスのメンバーにアクセスができる
//この１行をコメントアウトすれば、「valはprivateだからsetval()からはアクセスできない」とコンパイルエラーが出る
friend int setval(Test*,int); // int setval(Test*,int); をこのクラスの友達として登録する
 
private:
  int val;
  void checkfunc(void){//この関数もprivateなので、単純に外からは見えない
    cout << "We are friends!!! YEAR!!!!!!!" << endl;
  }
public:
  Test() : val(1){//1でvalが初期化されている
    cout << "Test class object" << endl;
  }
  int getval(void){//ゲッターはpublicで宣言されているので、どこからもアクセス可能
    return val;
  }
};
 
 
//setval()はTestクラスとは無関係のただの関数
int setval(Test*,int); //通常の関数なので、（Testクラス内のfriend宣言とは別に）プロトタイプ宣言は必要
 
 
int main(){
  Test a;
 
  setval(&a,3);   
 
  //a.val = 3;    //これはもちろんダメ(valはprivate)
  //a.checkfunc();    //これもダメ(checkfunc()はprivate)
 
  cout << a.getval() << endl; // getval()はpublic
 
  return 0;
}
 
 
//アドレスが指すクラスオブジェクトのvalにsetの値を代入する
//普通はこんなことはできないが、setval()がTestクラスにお友達認定されていれば
//クラスのメンバー関数であるかのように扱える
int setval(Test* a,int set){
  a->val = set;
  a->checkfunc();
  return 1;
}
