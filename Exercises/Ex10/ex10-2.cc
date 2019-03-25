#include <iostream>
#include <fstream>
 
using namespace std;
 
bool mazesolve(int,int); //迷路解探索（この演習課題では無視して問題ない）
 
int **Maze;          //解くべき迷路のデータを格納する
int **Solution;      //迷路を解いた時の解を格納する（解答となる最短ルートが書き込まれる）
int nx,ny;           //迷路サイズ
int s_x,s_y;         //スタート地点の座標
int g_x,g_y;         //ゴール地点の座標
int searched_id=0;   //迷路の解として、何番目にその地点を通ったか？（探索アルゴリズム用なので、この演習課題では無視して問題ない）
 
 
int main( int argc, char *argv[] ){ //main関数の引数（ProgC のときと全く同じ）
 
  if(argc!=3){ //エラー（引数に入出力ファイル名が与えられていない）時、標準エラーストリームに出力
    cerr << "error: Give the argument of inputting file for this program." << endl;
    return -1;
  }

  
 
  //読み込みファイルオープン
  ifstream infile(argv[1]);
  
 
  if(!infile.is_open()){ //エラー（読み込みファイルオープン失敗）時、標準エラーストリームに出力
    cerr << "error: no such input file named '" << argv[1] << "'." << endl;
    return -2;
  }
 
  
  //開いた迷路ファイルからnx, ny（先頭の数字２つ）を読み取る
  infile >> nx;
  infile >> ny;
  
  
 
  //２次元配列の動的確保（まず、ny個分の１次元配列領域を確保、１次元目）
  Maze =  new int*[ny];
  Solution =  new int*[ny];
  for(int j=0;j<ny;j++){  //１次元配列のそれぞれに対してnx個分の領域を確保（２次元目）
    Maze[j] = new int[nx];
    Solution[j] = new int[nx];
    
    for(int i=0;i<nx;i++){//確保した領域へ、ファイルから読み込んだ値（迷路の情報）を Maze[][]に格納
      //１個ずつ読み込んで代入する操作が、for文でメモリ領域を確保した１行分繰り返される
      infile >> Maze[j][i];
    }
  }
 

  
  #ifdef DEBUG  //-DDEBUGをつけてコンパイルすれば、読み込み内容をプログラム内で確認できる
  cerr << "[Mazedata in readfile]" << endl; 
  for(int j=0;j<ny;j++){ //解のファイル出力時も、これと同じような２重ループになるので参考にするとよい
    for(int i=0;i<nx;i++){
      cerr << Maze[j][i];
      if(i!=nx-1) cerr << " ";
    }
     cerr << endl;
  }
  #endif
 
 
 
  //ファイルからs_x, s_y　迷路のスタート地点を読み取る
  infile >> s_x;
  infile >> s_y;
  //ファイルからg_x, g_y　迷路のゴール地点を読み取る
  infile >> g_x;
  infile >> g_y;
  //もう使わないので、読み込みファイルストリームはクローズする
  infile.close();
 
  int check = mazesolve(s_x,s_y); //スタート地点から迷路を探索させる

  //書き込みファイルオープン
  fstream outfile;
    
  if(check== false){//解無し
    cerr << "There is no way to solve this maze." << endl;
  }
  else{//解あり


    //(コンパイルが通らない場合は、ofstreamの変数宣言だけはif-elseの前に行い、
    //ここで、 メンバー関数open()を使って開くとよい。(演習スライドpage.9参照)
    outfile.open(argv[2]);

    if(!outfile.is_open()){ //エラー（書き込みファイルオープン失敗）時、標準エラーストリームに出力
    cerr << "error: no such output file named '" << argv[2] << "'." << endl;
    return -3;
      }
 
 
 
    //以下で、出力ファイルに Solution[][]の内容を全て書き出す
    for(int i = 0; i < ny; i++){
      for(int j = 0; j < nx; j++){
	outfile << Solution[i][j] << "\t";
      }
      outfile << endl;
    }
  
  }
 
  outfile.close();         //もう使わないので、書き込みファイルストリームはクローズする
   
  for(int j=0;j<ny;j++){
    //確保した Maze と Solutionの配列を２次元目を解放する
    delete []Maze[j];
    delete []Solution[j];
     
    Maze[j]=NULL;            //メモリ周りバグのリスク回避対策(ex06-2.cc参照)
    Solution[j]=NULL;
  }
 
  //確保した Maze と Solutionの配列を１次元目を解放する
  delete []Maze;
  delete []Solution;
 
  Maze=NULL;
  Solution=NULL;
 
  return 0;
}
 
 
 
 
/*
【迷路解探索ルーチン】
bool mazesolve(int, int);
アルゴリズム的な内容なので仕様以外は無視してよい。
 
引数：スタート位置ｘ座標、ｙ座標
戻り値：true(解あり)、false（解無し）
 
解が存在するならば、Solution[][]には
正解となるルート中の場所に、「スタートからゴールに向かうまでに通る順番（int型）」が書き込まれている。
０は通らない場所であることを示す。
 
※正解の最短ルートではなかったが、探索上調べた場所は-1が入るようになっている
*/
bool mazesolve(int search_x, int search_y){
  int i,res;
  int direction[4][2];
 
if(search_x == nx || search_x ==-1 || search_y == ny || search_y == -1) return false;
if( Maze[search_y][search_x]==0 || Solution[search_y][search_x]!=0 ){
 return false;
}
 
Solution[search_y][search_x]= ++searched_id;
if(search_x==g_x && search_y==g_y) return true;
 
 direction[0][0] = search_x+1;
 direction[0][1] = search_y;
 direction[1][0] = search_x-1;
 direction[1][1] = search_y;
 direction[2][0] = search_x;
 direction[2][1] = search_y+1;
 direction[3][0] = search_x;
 direction[3][1] = search_y-1;
 
 for(i=0;i<4;i++){
  res = mazesolve(direction[i][0],direction[i][1]);
  if(res==true) return true;
 }
 
 Solution[search_y][search_x]= -1;
 --searched_id;
 return false;
}
