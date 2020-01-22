#include <stdio.h>
#include <stdlib.h>
#define MaxTree 10
#define ElementType char
#define Tree int
#define Null -1

struct TreeNode
{
    ElementType Data;
    Tree Left;
    Tree Right;
}T1[MaxTree],T2[MaxTree];

Tree BuildTree ( struct TreeNode T[]);
Tree Isomorphic(Tree R1,Tree R2);

int main()
{
    Tree R1,R2;

    R1 = BuildTree(T1);
    R2 = BuildTree(T2);
    if( Isomorphic(R1,R2))
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}

Tree BuildTree ( struct TreeNode T[])
{

    Tree i;
    Tree n;
    Tree check[MaxTree];
    char cl,cr;
    Tree Root =Null;   //若n为0，返回Null
    
    scanf("%d",&n);
    if( n ){
        for( i=0; i<n; i++)
            check[i] = 0;
            
        for( i=0; i<n; i++){
            scanf("\n%c %c %c",&T[i].Data,&cl,&cr);
            if( cl!='-' ){
                T[i].Left = cl-'0';   //若输入不为'-',那字符减去字符0转换为整型数值
                check[T[i].Left] = 1; //把在静态链表中出现过的数值标记为1
            }
            else if( cl=='-' ){
                T[i].Left = Null;
            }
            if( cr!='-' ){
                T[i].Right = cr-'0';
                check[T[i].Right] = 1;
            }
            else if( cr=='-' ){
                T[i].Right = Null;
            }
        }
        for( i=0; i<n; i++){
            if( !check[i]){
                Root=i;
                break;
            }
        }
    }
    return Root;
}

int Isomorphic(Tree R1,Tree R2){
    if((R1==Null)&&(R2==Null))      //如果为空树则是同构的
        return 1;
        
    if(((R1==Null)&&(R2!=Null))||((R1!=Null)&&(R2==Null)))//如果一个为空一个不为空则不是同构的
        return 0;
        
    if((T1[R1].Data)!=(T2[R2].Data))//如果根不同则不是同构的
        return 0;
        
    //如果左儿子都为空判断右儿子是否同构
    if((T1[R1].Left==Null)&&(T2[R2].Left==Null))
        return Isomorphic(T1[R1].Right,T2[R2].Right);
        
    /* 如果两棵树左儿子都不为空并且数据还是一样的，对左儿子进行递归*/
    if ( ((T1[R1].Left!=Null)&&(T2[R2].Left!=Null))&&((T1[T1[R1].Left].Data)==(T2[T2[R2].Left].Data)) )
        return ( Isomorphic( T1[R1].Left, T2[R2].Left )&&Isomorphic( T1[R1].Right, T2[R2].Right ) );
        
    /* 如果两棵树左儿子（一个空一个不空或者都不空）并且数据不一样，
    那么判断第一棵树的左（右）儿子是否跟第二棵树的右（左）儿子同构 */
    else
        return ( Isomorphic( T1[R1].Left, T2[R2].Right)&&Isomorphic( T1[R1].Right, T2[R2].Left ) );
}