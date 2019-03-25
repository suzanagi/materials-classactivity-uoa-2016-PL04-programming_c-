#include <iostream>
#include <string>

using namespace std;

class CurryRoux{
protected:
  //辛さ(数値が高いほど辛い)
  int spicy;
  //量(グラム表記)
  int amount;
  //ルーの温度
  int temperature;
  
public:
  //コンストラクタ
  CurryRoux(){
    spicy = 0;
    amount = 200;
    temperature = 30;
  }
  //デストラクタ
  ~CurryRoux(){
    cout << "ルゥが消滅しました。" << endl;
  }
  //辛さを増す関数(スパイスをかける)
  int increaseSpice(int spice){
    //一度辛くしたら戻せない
    if(spice < 0){
      cout << "スパイスは戻せません" << endl;
    }
    else this->spicy += spice;
    //辛さの値を戻す
    return spicy;
  }
  //量を増減する関数
  int changeAmount(int amo){
    amount += amo;
    if(amount < 0){
      cout << "ルゥのお代わりが必要です" << endl;
      amount = 0;
    }
    return amount;
  }
  //温度を設定する関数
  int setTemperature(int temp){
    temperature = temp;
    return temperature;
  }
  //温度を変える関数
  void changeTemperature(int temp){
    temperature += temp;
  }
};


class Rice{
protected:
  //米の硬さ加減(数字が大きいほど硬い)
  int tough;
  //量(グラム表記)
  int amount;
  //米の温度
  int temperature;
  
public:
  //コンストラクタ
  Rice(){
    tough = 100;
    amount = 200;
    temperature = 30;
  }
  //デストラクタ
  ~Rice(){
    cout << "米が消滅しました。" << endl;
  }
  //米の硬さを設定する関数
  int setToughness(int tough){
    this->tough = tough;
    return this->tough;
  }
  //米の硬さを変化させる関数
  void changeToughness(int tough){
    this->tough += tough;
  }
  //温度を設定する関数
  void setTemperature(int temp){
    this->temperature = temp;
  }
  //温度を変える関数
  void changeTemperature(int temp){
    this->temperature += temp;
  }

  //米の量を増減する関数
  void changeAmount(int amo){
    amount += amo;
    if(amount < 0){
      cout << "お米のお代わりが必要です" << endl;
      amount = 0;
    }
  }
};

class CurryRice: CurryRoux, Rice{
public:
  //コンストラクタ
  CurryRice(){}
  CurryRice(int spice){
    increaseSpice(spice);
  }
  CurryRice(int spice, int curryAmo, int riceAmo){
    increaseSpice(spice);
    CurryRoux::changeAmount(curryAmo - 200);
    Rice::changeAmount(riceAmo - 200);
  }
  CurryRice(int spice, int curryAmo, int riceAmo, int curryTemp, int riceTemp){
    increaseSpice(spice);
    CurryRoux::changeAmount(curryAmo - 200);
    Rice::changeAmount(riceAmo - 200);
    CurryRoux::setTemperature(curryTemp);
    Rice::setTemperature(riceTemp);
  }
  CurryRice(int spice, int curryAmo, int riceAmo, int curryTemp, int riceTemp, int riceTough){
    increaseSpice(spice);
    CurryRoux::changeAmount(curryAmo - 200);
    Rice::changeAmount(riceAmo - 200);
    CurryRoux::changeTemperature(curryTemp);
    Rice::changeTemperature(riceTemp);
    setToughness(riceTough);
  }
  //デストラクタ
  ~CurryRice(){
    cout << "カレーライスが消滅しました。" << endl;
  }

  //カレーを食べる時の関数(ルゥとライスの量を減らす)
  void eat(){
    CurryRoux::changeAmount(-30);
    Rice::changeAmount(-20);
  }
  //カレーを電子レンジで温める関数(引数は上昇した温度)
  void microWave(int temp){
    CurryRoux::changeTemperature(temp);
    Rice::changeTemperature(temp);
    //温めた温度だけ米も柔らかくなる
    changeToughness(-temp);
    cout << temp << "度加熱しました" << endl;
  }
  //お代わり
  void rouxOkawari(){
    cout << "カレーおかわり!" << endl;
    CurryRoux::changeAmount(200);
  }
  void riceOkawari(){
    cout << "ご飯おかわり!" << endl;
    Rice::changeAmount(200);
  }
  //カレーの情報を表示する関数
  void showInfo(){
    cout << "----------------" << endl;
    cout << "品名:カレーライス" << endl;
    cout << "辛さ: " << spicy << endl;
    cout << "内容量: " << "ルゥ" << CurryRoux::amount << "g 米"
	 << Rice::amount << "g" << endl;
    cout << "硬さ:" << tough << endl;
    cout << "温度: " << "ルゥ" << CurryRoux::temperature << "度 " << " 米"
	 << Rice::temperature << " 度" << endl;
    cout << "----------------" << endl;
  }
  void increaseSpice(int spicy){
    CurryRoux::increaseSpice(spicy);
  }
};

int main(){
  CurryRice curry(50, 170, 20, 40, 10, 200);
  curry.showInfo();
  curry.microWave(20);
  curry.eat();
  curry.increaseSpice(5000);
  curry.eat();
  curry.riceOkawari();
  curry.eat();
  curry.eat();
  curry.eat();
  curry.showInfo();
  
  return 0;

}
/*実行結果
bash-3.2$ g++ ex07-2.cc
bash-3.2$ ./a.out
----------------
品名:カレーライス
辛さ: 50
内容量: ルゥ170g 米20g
硬さ:200
温度: ルゥ70度  米40 度
----------------
20度加熱しました
お米のお代わりが必要です
ご飯おかわり!
----------------
品名:カレーライス
辛さ: 5050
内容量: ルゥ20g 米140g
硬さ:180
温度: ルゥ90度  米60 度
----------------
カレーライスが消滅しました。
米が消滅しました。
ルゥが消滅しました。
bash-3.2$ 
*/
