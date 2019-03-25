#include <iostream>
#include <memory> //メモリ管理に関するheader
 
using namespace std;
 
int main(){
 
  int *data;              //データを格納する動的配列の先頭アドレス
  int *lim;             //動的配列の末端（厳密には、最終要素の１つ後ろ）のアドレス
  allocator<int> alloc;   //メモリの動的確保・解放に関するクラスのオブジェクトallocを生成
  int size;               //確保するデータサイズ
 
 
  //確保するメモリサイズを入力
  cout << "Input how much memory you will allocate." << endl;
  cin >> size;
 
 
 
  /* メモリ領域の動的確保 */
 
  data = alloc.allocate(size);         //sizeで指示された要素数分のメモリを確保し、最初の要素へのポインタをdataに格納する(ただし要素の初期化は行われない)
  lim = data + size;                 //最初の要素のポインタに確保した要素数分を足すことにより最後の要素のひとつ後へのポインタをlimに格納
  uninitialized_fill(data,lim,0);    //初期化されていない,ポインタdata, limで示される範囲を値0のコピーで満たす
 
  /* 確保ここまで */
 
 
 
 
  //確保した領域に値を代入、出力するテスト
  for(int i=0; i<size;i++) data[i]=i;
  for(int i=0; i<size;i++) cout << data[i]*2 <<endl;
  
 
 
 
  /* 動的に確保したメモリ領域の解放 */
 
  if(data){                              //alloc.deallocate関数は必ず0でないポインタに適用しなくてはならないため条件分岐を用いてdataが0でない場合に処理を限定する.dataが0の場合はなにもしない.
    int *itr = lim;                    //ポインタitrに最後の要素のひとつ後へのポインタを格納
    while(itr != data){                  //whileループ中でデータ要素を(生成された逆順で)破棄していく
      alloc.destroy(--itr);        
    }
    alloc.deallocate(data, lim-data); //確保されていたメモリを解放する
  }
 
  /* 解放ここまで */
 
 
  return 0;
}
