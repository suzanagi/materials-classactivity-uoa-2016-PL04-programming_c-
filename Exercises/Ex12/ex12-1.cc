#include <iostream>

std::istream& operator>>(std::istream& is, Str& s){
  //現在のデータを破棄
  s.data.clear();
  //空白を読んで破棄
  char c;
  while(is.get(c) && isspace(c))
    ; //条件のテスト以外何もしない
  //読み込むべきものがあれば次の空白まで読み込む
  if(is){
    do s.data.push_back(c); //コンパイルエラー！
      while(is.get(c) && !isspace(c));
      //空白を読み込んだならストリームに戻しておく
      if(is)
	is.unget();
  }
  return is;
};
std::ostream& operator<<(std::ostream& os, const Str& s){
  for(Str::size_type i = 0; i != s.size(); ++i)
    os << s[i];
  return os;
};

Str operator+(const Str& s, const Str& t){
  Str r = s;
  r += t;
  return r;
};

class Str{
  friend std::istream& operator>>(std::istream&, Str&);
public:
  Str& operator+=(const Str& s){
    std::copy(s.data.begin(), s.data.end(), std::back_inserter(data));
    return *this;
  }
  
  typedef Vec<char>::size_type size_type;
  //空のStrオブジェクトを生成するデフォルトコンストラクタ
  Str(){}
  //n個のcのコピーを含むオブジェクトを生成する
  Str(size_type n, char c): data(n, c){}
  //ヌル文字で終わる文字の配列からオブジェクトを生成する
  Str(const char* cp){
    std::copy(cp, cp + std::strlen(cp), std::back_inserter(data));
  }
  //反復子bとeで囲まれた範囲をコピーしてオブジェクトを生成する
  template<class In> Str(In b, In e){
    std::copy(b, e, std::back_inserter(data));
  }
  char& operator[](size_type i){ return data[i]; }
  const char& operator[](size+type i) const { return data[i]; }
  size_type size() const { return data.size(); }
  //std::back_inserter();のせい？
  typedef const T& const_reference;
  
private:
  Vec<char> data;
};
