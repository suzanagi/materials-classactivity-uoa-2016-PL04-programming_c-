#include <iostream>

using namespace std;

class Color{
private:
  /*RGBそれぞれの色の値*/
  int red, green, blue;
public:
  /*3種類のコンストラクタ*/
  Color();
  Color(int);
  Color(int, int, int);
  /*デストラクタ*/
  ~Color();
  /*コンストラクタで初期化された各オブジェクトの色の値を取得するゲッター*/
  int get(int);
};

int main(){
  Color a; //引数無しコンストラクタ
  Color b(100); //引数1個版コンストラクタ
  Color c(10, 20, 30); //引数3個版コンストラクタ
   
cout << "Color A:" << endl;
cout << a.get(0) << ", " << a.get(1) << ", " << a.get(2) << endl;// オブジェクト a が持つ R,G,B値 
cout << "Color B:" << endl;
cout << b.get(0) << ", " << b.get(1) << ", " << b.get(2) << endl;// オブジェクト b が持つ R,G,B値 
cout << "Color C:" << endl;
cout << c.get(0) << ", " << c.get(1) << ", " << c.get(2) << endl;// オブジェクト c が持つ R,G,B値 
 
return 0; //ここでデストラクタが呼ばれる
}


/*3種類のコンストラクタ*/
//引数が無いとき
Color::Color(){
  red = 255;
  green = 255;
  blue = 255;
};
//引数が1個のとき
Color::Color(int c){
  red = c;
  green = c;
  blue = c;
};
//引数が3個のとき
Color::Color(int r, int g, int b){
  red = r;
  green = g;
  blue = b;
};

/*デストラクタ*/
Color::~Color(){
  //オブジェクトが破棄される時に、それを伝える旨のメッセージを出力する
  cout << "This object was destructed." << endl;
};

/*コンストラクタで初期化された各オブジェクトの色の値を取得するゲッター*/
int Color::get(int c){
  switch(c){
  case 0:
    return red;
  case 1:
    return green;
  case 2:
    return blue;
  }
};

/*実行結果
bash-4.4$ g++ ex06-1.cc
bash-4.4$ ./a.out
Color A:
255, 255, 255
Color B:
100, 100, 100
Color C:
10, 20, 30
This object was destructed.
This object was destructed.
This object was destructed.
*/
