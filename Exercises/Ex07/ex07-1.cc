/*Q2 set_name(), set_age()の部分を削除した場合の実行時の出力と挙動について
  まず、実行結果は以下のようになる。
  bash-4.4$ g++ ex07-1.cc
  bash-4.4$ ./a.out
  Name: Ken  Age: 5  Hungry: 10
  [EAT] Ken got a feed. (10 -> 20)
  
  Name: Ken  Age: 5  Hungry: 10
  Ken barks.  Bow!! BoW!!
  [EAT] Ken got a feed. (10 -> 15)
  
  Name: Ken  Age: 5  Hungry: 10
  [Frisbee] You threw a frisbee.
  Ken failed to catch the frisbee! (Fail)
  Ken barks.  Bow!! BoW!!
  [Guard] A strange man is appeared in your house!
  The strange man was dismissed byKen! (Success)
  Ken got 1000 yen. (Total prize: 1000 yen)
  [EAT] Ken got a feed. (10 -> 25)
  
  Name: Ken  Age: 5  Hungry: 10
  Ken cries.   Nyaan! Nyaaaan!
  Ken get rounded in kotatsu.
  [Nekojarashi] Ken jumped to the nekojarashi.
  [EAT] Ken got a feed. (10 -> 30)
  
  Name: Ken  Age: 5  Hungry: 10
  [EAT] Ken got a feed. (10 -> 40)
  Ken cries.   Nyaan! Nyaaaan!
  Ken get rounded in kotatsu.
  [Nekojarashi] Ken jumped to the nekojarashi.
  Target set (Ken): Elephant
  Ken hunted Elephant.

  それぞれのsetメソッドを削除すると、作成した全種類について名前は"Ken", 年齢は'5'になった。
  これはAnimalクラスのコンストラクタで指定される値であり、Animalを継承したすべてのクラスのインスタンス化
  の際にAnimalクラスのコンストラクタが実行されているためである。継承されたサブクラスのコンストラクタは自身
  が実行される前に継承元のコンストラクタを実行し、また今回はサブクラスのコンストラクタでそれぞれに初期化を
  行うことがないため、全て継承元のコンストラクタで指定された名前、年齢が設定されたままになってしまった。
*/

#include <iostream>
#include <string>
#include <cstdlib>      //乱数用 （犬系のチャレンジ判定用）
 
using namespace std;
 
class Animal{//Animalクラス
protected:
  string name;              //動物の名前
  int age;                  //年齢
  int hungry;               //満腹度
public:
  Animal();                 //デフォルトコンストラクタ
  void eat(int);            //引数に与えられた量のエサを食べる
  void show_status(void);   //動物の調子を見る（出力するだけ）≠ゲッター（アクセス関数）
  void set_name(string);    //動物の名前をセットする（セッター）
  void set_age(int);        //動物の年齢をセットする（セッター）
};
 
  class Dog : public Animal  //Dogクラス（Animalから継承）
  {
  protected:
    int ability;        //芸を行うための能力値
  public:
    Dog();
    int frisbee(void);  //フリスビーを投げて、この動物に取らせる
    void bark(void);    //この動物を吠えさせる
  };
 
    class BullDog : public Dog  //BullDogクラス（Dogから継承）
    {
    private:
      int reward;       //番犬の役目を果せたらもらえる報酬
    public:
      BullDog();
      int guard(void);  //番犬として働く
    };
 
  class Cat : public Animal  //Catクラス（Animalから継承）
  {
  protected:
    int nikukyu;           //肉球の柔らかさ
  public:
    Cat();
    void nekojarashi();    //ねこじゃらしで遊ぶ
    void kotatsu();        //コタツで丸くなる
    void cry();            //鳴かせる
  };
 
     class Lion : public Cat  //Lionクラス（Catから継承）
     {
     private:
       int fang_strength;       //牙の強さ
       string target;           //狙う獲物
     public:
       Lion();
       void set_target(string); //獲物を見定める
       void hunt();             //獲物を狩る
     };

/*Q3 新しく作成したクラス*/
  class Elephant : public Animal //Elephantクラス（Animalから継承）
  {
  protected:
    int hana;          //鼻の長さ(cm)
  public:
    Elephant();
    void drink();     //水を飲む
    void reverse();     //水を吹き出す
    void paooon();     //パオーン
  };
 
int main(){
//各オブジェクトを1個ずつ生成
  Animal ani_A;
  Dog ani_B;
  BullDog ani_C;
  Cat ani_D;
  Lion ani_E;
  //Q3 新しく作成したElephantクラス
  Elephant ani_F;
 
  srand( time(NULL) );
 
 
/* インターフェース呼び出し */
  ani_A.show_status();
  ani_A.eat(10);
  //ani_A.frisbee(); ani_AはAnimalクラス(frisbee()をもつDogの継承元)のオブジェクトであり、Animalクラスにfrisbeeメソッドは存在しないためコンパイルエラーとなる。
  //ani_A.cry(); ani_AはAnimalクラス(cry()をもつCatの継承元)のオブジェクトであり、Animalクラスにcryメソッドは存在しないためコンパイルエラーとなる。
  //ani_A.hunt(); ani_AはAnimalクラス(hunt()をもつLionの継承元の継承元)のオブジェクトであり、Animalクラスにhuntメソッドは存在しないためコンパイルエラーとなる。
  cout << endl;
  
  //ani_B.set_name("Mike");
  //ani_B.set_age(11);
  ani_B.show_status();
  ani_B.bark();
  //ani_B.guard(); ani_BはDogクラス(guard()をもつBullDogの継承元)のオブジェクトであり、Dogクラスにguardメソッドは存在しないためコンパイルエラーとなる。
  //ani_B.nekojarashi(); ani_BはDogクラス(nekojarashi()をもつCatの継承元)のオブジェクトであり、Dogクラスにnekojarashiメソッドは存在しないためコンパイルエラーとなる。
  ani_B.eat(5);
  cout << endl;
  
  //ani_C.set_name("Ben");
  //ani_C.set_age(10);
  ani_C.show_status();
  ani_C.frisbee();
  ani_C.bark();
  ani_C.guard();
  //ani_C.kotatsu(); ani_CはBullDogクラス(Dogを継承したが、CatクラスとはAnimal以外の繋がりがない)のオブジェクトであり、Catクラスのkotatsuメソッドにはアクセスできない。BullDogクラスにkotatsuメソッドが存在しないため、コンパイルエラーとなる。
  ani_C.eat(15);
  cout << endl;
  
  //ani_D.set_name("Yoko");
  //ani_D.set_age(3);
  ani_D.show_status();
  ani_D.cry();
  ani_D.kotatsu();
  ani_D.nekojarashi();
  //ani_D.hunt(); ani_DはCatクラス(hunt()をもつLionの継承元)のオブジェクトであり、Lionクラスのhuntメソッドにはアクセスできない。Catクラスにhuntメソッドは存在しないため、コンパイルエラーとなる。
  ani_D.eat(20);
  cout << endl;
  
  //ani_E.set_name("Jun");
  //ani_E.set_age(7);
  ani_E.show_status();
  ani_E.eat(30);
  ani_E.cry();
  ani_E.kotatsu();
  ani_E.nekojarashi();
  ani_E.set_target("Elephant");
  ani_E.hunt();
  //ani_E.frisbee(); ani_EはLionクラス(Catを継承したが、DogクラスとはAnimal以上の関係がない)のオブジェクトであり、Dogクラスのfrisbeeメソッドにはアクセスできない。Lionクラスにfrisbeeメソッドは存在しないため、コンパイルエラーとなる。
  cout << endl;

  /*Q3で定義したクラスの動作確認*/
  ani_F.set_name("Michael");
  ani_F.set_age(180);
  ani_F.show_status();
  ani_F.eat(530000);
  ani_F.paooon();
  ani_F.reverse();
  ani_F.drink();
  
  
  return 0;
}
 
 
 
 
Animal::Animal(){
  name = "Ken";
  age = 5;
  hungry = 10;
}
void Animal::eat(int val){
  cout << "[EAT] " << name << " got a feed. (" << hungry << " -> ";
  hungry += val;
  cout << hungry << ")" << endl;
}
void Animal::show_status(void){
  //
  cout << "Name: " << name << "  Age: " << age << "  Hungry: " << hungry <<endl;
}
void Animal::set_name(string val){
  name = val;
}
void Animal::set_age(int val){
  age = val;
}
 
 
 
Dog::Dog(){
  ability = 50;
}
int Dog::frisbee(void){
  //この犬の能力値を元に、確率的にフリスビーを取れるか取れないか判断する
  cout << "[Frisbee] You threw a frisbee." << endl;
  if(rand()%100 <= ability){
    cout << name << " caught the frisbee! (Success)" << endl;
    return 1;
  }
  else{
    cout << name << " failed to catch the frisbee! (Fail)" << endl;
    return 0;    
  }
}
void Dog::bark(void){
  cout << name << " barks.  Bow!! BoW!!" <<endl;
}
 
 
 
BullDog::BullDog(){
  reward = 0;
}
int BullDog::guard(void){
  //この犬の能力値を元に、確率的に番犬が成功するか失敗するか判断する
  cout << "[Guard] A strange man is appeared in your house!" << endl;
  if(rand()%100 <= ability){
    cout << "The strange man was dismissed by" << name <<"! (Success)" << endl;
    reward += 1000;
    cout << name << " got 1000 yen. (Total prize: " << reward << " yen)" << endl;
    return 1;
  }
  else{
    cout << "The strange man could enter into the house. (Fail)" << endl;
    return 0;    
  }
}
 
 
Cat::Cat(){
  nikukyu = 30;
}
void Cat::nekojarashi(void){
  cout << "[Nekojarashi] " << name << " jumped to the nekojarashi." << endl; 
}
void Cat::kotatsu(void){
  cout << name << " get rounded in kotatsu." << endl;
}
void Cat::cry(void){
  cout << name << " cries.   Nyaan! Nyaaaan!" << endl;
}
 
 
Lion::Lion(){
  fang_strength = 100;
  target = -1;
}
void Lion::set_target(string val){
  target = val;
  cout << "Target set (" << name << "): " << target << endl;
}
void Lion::hunt(void){
  cout << name <<" hunted " << target << "." << endl;
}


Elephant::Elephant(){
  hana = 300;
}
void Elephant::drink(){
  cout << "ジュボボボボボボボボ" << endl;
  cout << "drunk too much water" << endl;
}
void Elephant::reverse(){
  cout << "reversed too much water" << endl;
}
void Elephant::paooon(){
  cout << "パオーン" << endl;
}
