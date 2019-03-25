#include <iostream>
#include <vector>
#include <cmath>
#include <exception>
#include <stdexcept> //invalid_argumentの呼出し時に"not declared"とエラーが出るため追加しました
 
using namespace std;
 
class V{
 private:
  int size;//このベクトルの次数（実質vectorの.size()と同じもの）
  vector<int> vect;//【これがベクトルの要素を持つコンテナ】
  vector<int> ansvec;//ベクトル和の結果を格納するコンテナ
  vector<int> outprod;//外積の結果を格納するコンテナ
  int ans_scalar; //内積の結果を格納するスカラー変数
   
 public:
  void insert(int val){ //間接的にvector（ベクトル）に値を挿入するインターフェース
    vect.push_back(val);//vectorへ入力
    size = vect.size();
  }
   
 
/* Define each operations for vectors*/
  //ベクトル和
  vector<int> operator+(V v){
    if(this->size >= v.size){
      ansvec = this->vect;
      for(int i = 0; i < v.size; i++) ansvec[i] += v.vect[i];
    }
    else{
      ansvec = v.vect;
      for(int i = 0; i < this->size; i++) ansvec[i] += this->vect[i];
    }
    return ansvec;
  }
 
  //ベクトルの内積
  int operator*(V v){
    //明示的に初期化
    this->ans_scalar = 0;
    
    if(this->size >= v.size){
      for(int i = 0; i < v.size; i++) this->ans_scalar += (this->vect[i] * v.vect[i]);
    }
    else{
      for(int i = 0; i < this->size; i++) this->ans_scalar += this->vect[i] * v.vect[i];
    }
    return this->ans_scalar;
  }

  //ベクトルのノルム
  double operator*() const{
    double p = 2.0;
    int psum = 0;
    for(int i = 0; i < size; i++) psum += pow(abs(vect[i]), p);
    return pow(psum, 1/p);
  }

  //もし保持するベクトルが３次元ベクトルならば、ベクトルの外積を求める
  vector<int> operator%(V v){
    if(this->size != 3 || v.size != 3) throw invalid_argument("Outer product is defined for 3-D vectors.");
    else{
      //x成分
      outprod.push_back(this->vect[1] * v.vect[2] - this->vect[2] * v.vect[1]);
      //y成分
      outprod.push_back(this->vect[2] * v.vect[0] - this->vect[0] * v.vect[2]);
      //z成分
      outprod.push_back(this->vect[0] * v.vect[1] - this->vect[1] * v.vect[0]);
    }
    return outprod;
  }
};
 
 
 
/* !!ここから先を変更する必要は無い!! */
int main(){
  V v1,v2;
  vector<int> v3,v4;
  int val ,res;
  double norm;
 
  cout << "Input vector1" << endl;//ベクトル１入力
  while(cin >> val){
    v1.insert(val);
  }
  cin.clear();
  cout << "Input vector2" << endl;//ベクトル２入力
  while(cin >> val){
    v2.insert(val);
  }
  //入力はここまで
 
 
 
  //ここから演算子の処理
  cout << "[Result: Vector Add]" << endl;//ベクトル和
  v3 = v1 + v2;
  for(int i=0; i < v3.size(); i++){
      cout << v3[i] << endl;
  }
  
  cout << "[Result: Inner product]" << endl;//ベクトルの内積
  res = v1 * v2;
  cout << res  << endl;
 
  cout << "[Result: L2 Norm of v1]" << endl;//ベクトルのノルム（大きさ）
  norm = *v1;
  cout << norm << endl;
  
  cout << "[Result: Outer product]" << endl;//ベクトルの外積（ただし、3次元ベクトルに限る）
  try{
   v4 = v1 % v2;
   for(int i=0; i < v3.size(); i++){
   cout << v4[i] << endl;
  }
  }
  catch (const exception &e){
    cerr << e.what() << endl; //標準例外メソッドが投げたメッセージを受け取る
  } 
  
  return 0;
}

/*実行結果
bash-4.4$ g++ ex13-2.cc
bash-4.4$ ./a.out
Input vector1
1
2
0
Input vector2
0
1
-1
[Result: Vector Add]
1
3
-1
[Result: Inner product]
2
[Result: L2 Norm of v1]
2.23607
[Result: Outer product]
-2
1
1
bash-4.4$ ./a.out
Input vector1
1
11
7
19
6
Input vector2
2
-4
8
10
15
[Result: Vector Add]
3
7
15
29
21
[Result: Inner product]
294
[Result: L2 Norm of v1]
23.8328
[Result: Outer product]
Outer product is defined for 3-D vectors.
bash-4.4$ ./a.out
Input vector1
3
9
2
3
9
Input vector2
1
9
8
1
0
[Result: Vector Add]
4
18
10
4
9
[Result: Inner product]
103
[Result: L2 Norm of v1]
13.5647
[Result: Outer product]
Outer product is defined for 3-D vectors.
*/
