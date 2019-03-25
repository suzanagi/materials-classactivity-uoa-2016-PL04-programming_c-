#include <stdio.h>
#include <stdlib.h>

#define MaxNodeNum 100
#define WHITE 0
#define GRAY  1
#define BLACK 2

/*
 * リストのノードを表すデータ構造
 */
struct node {
  int vertex;
  struct node *next;
};
typedef struct node * NodePointer;

/*
 * リストを表すデータ構造
 */
struct list {
  NodePointer head;
  NodePointer tail;
};

void listinitialize(struct list *lp);
NodePointer insert(struct list *lp, int v);
void dfs(int n);
void dfsvisit(int u);
void visitprint(int n);
void graphprint(int n);

struct list adj[MaxNodeNum];	/* 隣接リストのデータ構造 */

/* DFS のためのデータ */
int color[MaxNodeNum];
int d[MaxNodeNum], f[MaxNodeNum];
int timer;

main(){
  int n, e, v, i, j;

  /* グラフのノード数の入力 */
  scanf("%d", &n);
  /* 各ノードの隣接リストの初期化（初期化したいリストのアドレスを渡す） */
  for (i=0; i<n; i++)
    listinitialize(&adj[i]);

  /* 隣接リスト法で表現されたグラフのノードと連結の情報の入力 */
  for (i=0; i<n; i++)  {

    scanf("%d", &e);
    
    for(j = 0; j < e; j++){
      scanf("%d", &v);
      if(insert(&adj[i], v - 1) == NULL){//vの数字はひとつずれる
	printf("list insert failed\n");
	break;
      }
    }

  }
  /* 以下の行のコメントを外すと、グラフの確認ができる */
  /* graphprint(n); */

  dfs(n);
  visitprint(n);
}

/* 深さ優先探索 */
void dfs(int n){

  int u;
  
  for(u = 0; u < n; u++)
    color[u] = WHITE;

  timer = 0;

  for(u = 0; u < n; u++)
    if(color[u] == WHITE) dfsvisit(u);
}

void dfsvisit(int u){

  int i;
  NodePointer np;
  
  color[u] = GRAY; //just been discovered
  timer = timer + 1;
  d[u] = timer; //discovered time

  np = adj[u].head;

  while(1){ //explore edge
    /*リストの最後についたらループ終了*/
    np = np->next;
    if(np == adj[u].tail) break;

    if(color[(*np).vertex] == WHITE) dfsvisit((*np).vertex);
  }

  color[u] = BLACK; //finished

  f[u] = ++timer; //finished time

}

/* 各ノードの発見時刻と終了時刻の出力 */
void visitprint(int n){

  int i, j;
  
  printf("timestamps\n");
  
  for(i = 0; i < n; i++){
    printf("%d: ", i+1);

    printf("%d %d\n", d[i], f[i]);
  }
}

/* リストの初期化（初期化するリストへのポインタも引数で与えられる） */
void listinitialize(struct list *lp){
  lp->head = (NodePointer)malloc(sizeof(struct node));
  lp->tail = (NodePointer)malloc(sizeof(struct node));

  lp->head->next = lp->tail;
  lp->tail->next = lp->tail;
}

/* リストへの要素の挿入（挿入先のリストへのポインタも引数で与えられる） */
NodePointer insert(struct list *lp, int v){
  NodePointer x;

  x = (NodePointer)malloc(sizeof(struct node));
  x->vertex = v;
  x->next = lp->head->next;
  lp->head->next = x;
  return x;
}

/* グラフの隣接リスト法によるデータ構造から、隣接リスト法による表現を出力する */
void graphprint(int n)
{
  int i;
  NodePointer np;

  printf("adjacency list\n");
  for (i=0; i<n; i++)  {
    printf("%d: ",i+1);
    for (np=adj[i].head->next; np != adj[i].tail; np = np->next)
      printf("%d ",np->vertex+1);
    putchar('\n');
  }
}
