#include <iostream>
#include <vector> //vector利用時には、ヘッダーが必要
 
 
using namespace std;
 
int main(){
  vector<int> weight; //int型のvectorコンテナ（≒int型の伸縮自在な配列）
  int w;
  double sum=0.0;
  double avg, median;
 
  cout << "Input values" << endl;
   
 // cin は 入力失敗（入力終了時）に 0 を返すので、
 // 任意の入力個数に対する入力は、このようにwhile文で書ける
  while(cin >> w){
    weight.push_back(w);  // vectorに入力値 w を末尾に挿入
  }
 
  cout << "[Data]" << endl;
  for(int i=0;i<weight.size();i++){ // vectorの入力された個数分ループする
    cout << weight[i] << " ";
    sum += weight[i]; //合計値計算（vectorの各要素へは配列と同じようにしてランダムアクセスが行える）
  }
  cout << endl;
 
  //平均値計算
  avg= sum / weight.size(); 
   
  //中央値計算
  sort(weight.begin(),weight.end());
  if(weight.size()%2==1){//奇数個の時は真ん中の値
    median = weight[weight.size()/2];
  }
  else{//偶数個のときは、真ん中に近い2つの平均値
    median = (weight[weight.size()/2-1]+weight[weight.size()/2])/2.0;
  }
 
  cout << "Number of Data: " << weight.size() << endl
       << "total: " << sum << " average: " << avg
       << " median: " << median << endl;
  
  return 0;
}
