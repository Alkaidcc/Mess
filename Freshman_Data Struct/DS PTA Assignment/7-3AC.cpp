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
    Tree Root =Null;   //��nΪ0������Null
    
    scanf("%d",&n);
    if( n ){
        for( i=0; i<n; i++)
            check[i] = 0;
            
        for( i=0; i<n; i++){
            scanf("\n%c %c %c",&T[i].Data,&cl,&cr);
            if( cl!='-' ){
                T[i].Left = cl-'0';   //�����벻Ϊ'-',���ַ���ȥ�ַ�0ת��Ϊ������ֵ
                check[T[i].Left] = 1; //���ھ�̬�����г��ֹ�����ֵ���Ϊ1
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
    if((R1==Null)&&(R2==Null))      //���Ϊ��������ͬ����
        return 1;
        
    if(((R1==Null)&&(R2!=Null))||((R1!=Null)&&(R2==Null)))//���һ��Ϊ��һ����Ϊ������ͬ����
        return 0;
        
    if((T1[R1].Data)!=(T2[R2].Data))//�������ͬ����ͬ����
        return 0;
        
    //�������Ӷ�Ϊ���ж��Ҷ����Ƿ�ͬ��
    if((T1[R1].Left==Null)&&(T2[R2].Left==Null))
        return Isomorphic(T1[R1].Right,T2[R2].Right);
        
    /* �������������Ӷ���Ϊ�ղ������ݻ���һ���ģ�������ӽ��еݹ�*/
    if ( ((T1[R1].Left!=Null)&&(T2[R2].Left!=Null))&&((T1[T1[R1].Left].Data)==(T2[T2[R2].Left].Data)) )
        return ( Isomorphic( T1[R1].Left, T2[R2].Left )&&Isomorphic( T1[R1].Right, T2[R2].Right ) );
        
    /* �������������ӣ�һ����һ�����ջ��߶����գ��������ݲ�һ����
    ��ô�жϵ�һ���������ң������Ƿ���ڶ��������ң��󣩶���ͬ�� */
    else
        return ( Isomorphic( T1[R1].Left, T2[R2].Right)&&Isomorphic( T1[R1].Right, T2[R2].Left ) );
}