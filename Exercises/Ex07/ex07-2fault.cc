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
  }
  //温度を設定する関数
  int setTemperature(int temp){
    temperature = temp;
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
  //産地
  string area;
  
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
  //産地を登録する関数
  void setProductionArea(string area){
    char C;
    //入力が現在の産地と異なる場合は問いかけ
    if(this->area != area){
      cout << "産地を偽装しますか?(Y/N)" << endl;
      cin >> C;
      if(C == 'Y') this->area = area;
    }
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

class CurryRice{
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
  CurryRice(int spice, int curryAmo, int riceAmo, int curryTemp, int riceTemp, int riceTough, string riceArea){
    increaseSpice(spice);
    CurryRoux::changeAmount(curryAmo - 200);
    Rice::changeAmount(riceAmo - 200);
    CurryRoux::changeTemperature(curryTemp);
    Rice::changeTemperature(riceTemp);
    setToughness(riceTough);
    setProductionArea(riceArea);
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
    CurryRoux::changeTemperature(Roux::temperature + temp);
    Rice::changeTemperature(Rice::temperature + temp);
    //温めた温度だけ米も柔らかくなる
    changeToughness(temp);
  }
  //お代わり
  void rouxOkawari(){
    CurryRoux::changeAmount(200);
  }
  void riceOkawari(){
    Rice::changeAmount(200);
  }
  //カレーの情報を表示する関数
  void showInfo(){
    cout << "----------------" << endl;
    cout << "品名:カレーライス" << endl;
    cout << "辛さ: " << spicy << endl;
    if(!area.isempty()){
      cout << "内容量: " << "ルゥ" << CurryRoux::amount << "g 米(" << area << "産)"
	   << Rice::amount << "g" <<endl;
    }
    else{
      cout << "内容量: " << "ルゥ" << CurryRoux::amount << "g 米"
	   << Rice::amount << "g" << endl;
    }
    cout << "硬さ:" << tough << endl;
    cout << "温度: " << "ルゥ" << CurryRoux::temperature << "度 " << " 米"
	 << Rice::temperature << " 度" << endl;
  }
};
int main(){

  CurryRice curry = new CurryRice(50, 170, 20, 40, 10, 200, "中国");
  curry.showInfo();
  curry.microWave(20);
  curry.eat();
  curry.riceOkawari();
  curry.eat();
  curry.eat();
  curry.ChangeProductionArea("新潟県");
  curry.eat();
  curry.showInfo();
  

  
  return 0;

}
