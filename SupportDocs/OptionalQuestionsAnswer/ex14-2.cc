#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T> class vec{
private:
  T *p;
  int low, high;
public:
  vec(int l, int h){
    low = l;
    high = h;
    p = new T[high - low + 1];
  }

  T & operator[](int i){
    try{
      if(i > high || i < low) throw invalid_argument("添え字が限界を超えた");
    }catch(invalid_argument e){
      throw;
    }
    return p[i - low];
  }
};



int main(){
  vec<float> v(-10, 20);
  v[-10] = 10.0;
  v[20] = -10.0;
  try{
    cout << "v[" << -10 << "] = " << v[-10] << endl;
    cout << "v[" << 20 << "] = " << v[20] << endl;
    cout << "v[" << 30 << "] = " << v[30] << endl;
    cout << "v[" << 40 << "] = " << v[40] << endl;
  }catch(const exception &e){
    cout << e.what() << endl;
  }
  return 0;
}
	
/*実行結果
bash-4.4$ g++ ex14-2.cc
bash-4.4$ ./a.out
v[-10] = 10
v[20] = -10
添え字が限界を超えた
*/
