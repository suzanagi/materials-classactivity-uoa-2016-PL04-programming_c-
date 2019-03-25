#include <iostream>
#include <string>

using namespace std;

class Frac{
private:
  int numerator;
  int denominator;
public:
  /*コンストラクタ*/
  Frac();
  Frac(int, int);
  /*メンバ関数*/
  void set_frac(int, int);
  void show_frac(void);
  void multfrac(Frac);
};

int main(){
  /*f1のコンストラクタは省く
  Frac f1;      //引数なしコンストラクタ
  */
  
  //引数２つのコンストラクタ
  Frac f2(2,3); 
  //入力を受け取る変数
  int num, den;
  //引数なしコンストラクタ
  Frac f3;      

  //分母と分子を入力させるようにする
  cout << "Input denominator(y) and numerator(x) -> x/y" << endl;
  cin >> den;
  cin >> num;

  /*f1とf2の表示は省く
  f1.show_frac(); // 1/1が出る
  f2.show_frac(); // 2/3が出る
  */  

  // f3.set_frac(4,5);の引数は入力させたものに変更
  f3.set_frac(num,den);

  try{
    //分数f2と引数に渡された分数f3の積をf2に格納
    f2.multfrac(f3);
  }catch(const char *e){
    cout << e << endl;
  }
  
  //f2を出力
  f2.show_frac();

  /*f2の関係ない処理は省く
  f2.multfrac(f2); //自分の2乗
  f2.show_frac();// 64/225が出る
  */
  return 0;
}

/*引数なしコンストラクタ*/
Frac::Frac():numerator(1), denominator(1){}
/*引数2つコンストラクタ*/
Frac::Frac(int num, int den):numerator(num), denominator(den){}
/*分母、分子に対するセッター関数*/
void Frac::set_frac(int num, int den){
  numerator = num;
  denominator = den;
}
/*クラスの実体が持つ分母、分子を出力する関数*/
void Frac::show_frac(){
  cout << numerator << "/" << denominator << endl;
}
/*他のクラス変数の持つ分数を１つ引数にとって、自分のクラス変数の分数との積をとり、結果を自分のクラス変数の新しい値とする関数*/
void Frac::multfrac(Frac fraction){
  try{
    if(fraction.denominator == 0) throw "Error: Division by zero";
  }catch(const char *e){
    throw;
  }
  set_frac(this->numerator * fraction.numerator, this->denominator * fraction.denominator);
}

/*実行結果
bash-4.4$ g++ ex09-2.cc
bash-4.4$ ./a.out
Input denominator(y) and numerator(x) -> x/y
0 4
Error: Division by zero
2/3
 */
