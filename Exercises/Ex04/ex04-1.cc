#include <iostream>
#include <map>  // STLコンテナ「map」を使用する
#include <string>
using namespace std;
 
int main(){
  string mt_name;
  int mt_height;
  std::map<string, int> mountain;  //mapを定義
   
  //山の名前をキー、高さを値としてmapに随時登録する
  while(cin >> mt_name >> mt_height){
    mountain[mt_name] = mt_height;
    //    mountain.insert(make_pair(mt_name, mt_height));
  }
  cin.clear();
 
  cout << "Input the name of mountain. ->";
  cin >> mt_name; //山の名前（mapを探索するためのキー）を入力する
 
  //山の名前をキーにしてmapを探索し、それが登録されていればその山の高さを返す。
  if(mountain.find(mt_name) != mountain.end()){
   cout << mt_name << " is a mountain whose height is "
        << mountain.at(mt_name) << "m." << endl;
  }
  else{//登録されていなかった
    cout << "Sorry, " << mt_name << " is not registered here." << endl; 
  }
  return 0;
}

/*実行結果
bash-4.4$ g++ ex04-1.cc
bash-4.4$ ./a.out
Fuji 3776
Bandai 1816
Iimori 314
Everest 8848
K2 8611
Kangchenjunga 8586
Manaslu 8186
Eiger 3970
Aconcagua 6961
Kilimanjaro 5895
Matterhorn 4478
Input the name of mountain. ->Bandai
Bandai is a mountain whose height is 1816m.
bash-4.4$ ./a.out
Fuji 3776
Bandai 1816
Iimori 314
Everest 8848
K2 8611
Kangchenjunga 8586
Manaslu 8186
Eiger 3970
Aconcagua 6961
Kilimanjaro 5895
Matterhorn 4478
Input the name of mountain. ->K3
Sorry, K3 is not registered here.
bash-4.4$ ./a.out
Fuji 3776
Bandai 1816
Iimori 314
Everest 8848
K2 8611
Kangchenjunga 8586
Manaslu 8186
Eiger 3970
Aconcagua 6961
Kilimanjaro 5895
Matterhorn 4478
Input the name of mountain. ->Everest
Everest is a mountain whose height is 8848m.
 */
