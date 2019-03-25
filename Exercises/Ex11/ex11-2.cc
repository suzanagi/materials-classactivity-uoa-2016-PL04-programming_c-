#include <iostream>
#include <string>
#include <algorithm>
 
using namespace std;
 
void vectest_int(void);
void vectest_str(void);
void vectest_double(void);
void vectest_struct(void);
 
typedef struct{
  int score;
  string name;
}Test;
 
 
template <class T> class Vec{
public:
  typedef T* iterator;
  typedef const T* const_iterator;
  typedef size_t size_type;
  typedef T value_type;
  Vec(){ create(); }
  explicit Vec(size_type n, const T& t = T()){ create(n, t); }
  Vec(const Vec& v){ create(v.begin(), v.end()); }
  Vec& operator=(const Vec&);
  ~Vec(){ uncreate(); }
  //T& operator[](size_type i) const { return data[i]; }
  const T& operator[](size_type i) const { return data[i]; }
  void push_back(const T& t){
    if(avail == limit)
      grow();
    unchecked_append(t);
  }
  size_type size() const { return avail - data; }
  iterator begin() { return data; }
  const_iterator begin() const { return data; }
  iterator end() { return avail; }
  const_iterator end() const { return avail; }
private:
  iterator data;
  iterator avail; //初期化されたの最後の要素の1つ後を指し,メモリの追加確保の判断などに用いられる
  iterator limit; //Vecの最後の要素の1つ後を指し,データの最後を管理するとともに次に使える場所を指示する
  //The system of memory allocation
  allocator<T> alloc; // the object to control the memory
  //Memory allocation and initialization of array inside
  void create();
  void create(size_type, const T&);
  void create(const_iterator, const_iterator);
  //Revocaion of the elements in the array and release of memory
  void uncreate();
  //function used in push_back
  void grow();
  void unchecked_append(const T&);
};
  
 
/*0～3の整数値入力で、対応する関数のVecテストを行う（エラー処理無しなので注意）*/
int main(){
  int op;
  void (*p[])()={vectest_int,vectest_str,vectest_double, vectest_struct};
 
  cout << "Input operation." << endl;
  cout << "0: int,  1: string,  2: double,  3: struct" << endl;
  cin >> op;
 
  (*p[op])();//関数ポインタで異なる型のテスト関数を呼ぶため、引数に応じて各検証ができる
 
  return 0;
}
 
 
/*int型Vecテスト： 0と1だけの周期７の乱数列を作り出す*/
void vectest_int(void){
  int val;
  Vec<int> dataint;
 
    dataint.push_back(1);
    dataint.push_back(1);
    dataint.push_back(0);
   
  for(int i=3;i<100;i++){    
    val = (dataint[i-3]+dataint[i-1])%2;
    dataint.push_back(val);
  }
  
  cout << "[output]" << endl;
  Vec<int>::iterator itr;
  for(itr=dataint.begin();itr!=dataint.end();itr++){
    cout << *itr << " ";
  }
  cout << endl;
}
 
 
/*string型Vecテスト：入力した文字列を、入力した時と逆順に出力させる*/
void vectest_str(void){
  string val;
  Vec<string> datastr;
 
  cout << "入力:" << endl;
  while(cin >> val){
    datastr.push_back(val);
  }
   
  cout << "出力:" << endl;
  Vec<string>::iterator itr;
  for(itr=datastr.end()-1;itr!=datastr.begin()-1;itr--){
    cout << *itr << endl;
  }
  cout << endl;
}
 
 
/*double型Vecテスト： 入力された値の平均値を算出する*/
void vectest_double(void){
  double val;
  Vec<double> datastr;
 
  cout << "入力:" << endl;
  while(cin >> val){
    datastr.push_back(val);
  }
   
  cout << "出力:" << endl;
  if(datastr.size()>0){
  Vec<double>::iterator itr;
  double sum = 0.0;
  for(itr=datastr.begin();itr!=datastr.end();itr++) sum += *itr;
   cout << "average: " << sum/datastr.size() << endl;
  }
  else cout << "error: no data input" << endl;
 
  cout << endl;
}
 
/*構造体Vecテスト：　コンテナ内のデータに対してリニアサーチを行う*/
void vectest_struct(void){
  Test data;
  Vec<Test> dataTest;
  int scores[12]={40,80,90,55,23,36,77,78,91,56,38,64};
  string names[12]={"tako","ebi","kani","ikura","sake","tara","masu","fugu","kujira","same","tai","saba"};
 
  for(int i=0;i<12;i++){
    data.score = scores[i];
    data.name = names[i];
    dataTest.push_back(data);
  }
   
  string searchname;
  cout << "Input searching name" << endl;
  cin >> searchname;
 
  cout << "[output]" << endl;
  Vec<Test>::iterator itr;
  for(itr=dataTest.begin();itr!=dataTest.end();itr++){
    if(itr->name == searchname) break;
  }
  if(itr!=dataTest.end())  cout << "[Find] name: " << itr->name << "  score: " << itr->score  << endl;
  else cout << "\"" << searchname << "\"" << " was not found."<<endl;
}


template <class T> void Vec<T>::create(){
  data = avail = limit = 0;
}

template <class T> void Vec<T>::create(size_type n, const T& val){
  data = alloc.allocate(n);
  limit = avail = data + n;
  uninitialized_fill(data, limit, val);
}

template <class T>
void Vec<T>::create(const_iterator i, const_iterator j){
  data = alloc.allocate(j - i);
  limit = avail = uninitialized_copy(i, j, data);
}

template <class T> void Vec<T>::uncreate(){
  if(data){
    //destroy the data element
    iterator it = avail;
    while(it != data)
      alloc.destroy(--it);

    //release the memory allocated
    alloc.deallocate(data, limit - data);
  }
  //reset the pointer and show that Vec is empty again
  data = limit = avail = 0;
}

template <class T> void Vec<T>::grow(){
  //allocate double size of memory when increase the momory range
  size_type new_size = max(2*(limit - data), ptrdiff_t(1));
  //allocate the memory and copy th element there
  iterator new_data = alloc.allocate(new_size);
  iterator new_avail = uninitialized_copy(data, avail, new_data);
  //release the memory used
  uncreate();
  //set the pointer to point new memory
  data = new_data;
  avail = new_avail;
  limit = data + new_size;
}

//avail is pointing uninitialized space in the allocated memory
template <class T> void Vec<T>::unchecked_append(const T& val){
  alloc.construct(avail++, val);
}


/*実行結果
bash-3.2$ g++ ex11-2.cc
bash-3.2$ ./a.out
Input operation.
0: int,  1: string,  2: double,  3: struct
0
[output]
1 1 0 1 0 0 1 1 1 0 1 0 0 1 1 1 0 1 0 0 1 1 1 0 1 0 0 1 1 1 0 1 0 0 1 1 1 0 1 0 0 1 1 1 0 1 0 0 1 1 1 0 1 0 0 1 1 1 0 1 0 0 1 1 1 0 1 0 0 1 1 1 0 1 0 0 1 1 1 0 1 0 0 1 1 1 0 1 0 0 1 1 1 0 1 0 0 1 1 1 
bash-3.2$ ./a.out
Input operation.
0: int,  1: string,  2: double,  3: struct
1
入力:
monday
tuestay
wednesday
thursday
friday
saturday
sunday
出力:
sunday
saturday
friday
thursday
wednesday
tuestay
monday

bash-3.2$ ./a.out
Input operation.
0: int,  1: string,  2: double,  3: struct
2
入力:
1.2
2.4
3.6
4.8
6.0
7.2
出力:
average: 4.2

bash-3.2$ ./a.out
Input operation.
0: int,  1: string,  2: double,  3: struct
3
Input searching name
tara
[output]
[Find] name: tara  score: 36
bash-3.2$ ./a.out
Input operation.
0: int,  1: string,  2: double,  3: struct
3
Input searching name
wakame
[output]
"wakame" was not found.
bash-3.2$ ./a.out
Input operation.
0: int,  1: string,  2: double,  3: struct
3
Input searching name
saba
[output]
[Find] name: saba  score: 64
*/
