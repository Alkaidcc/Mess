#include<stdio.h>
#include<iostream>
int main(){         //����jud�ļӼ����ж�"("��")"������ ��judΪ0��һ����
    int jud=0;
    char a;
    while(1){
        a=getchar();
        if(a=='(')
            jud++;
        if(a==')')
            jud--;
        if(jud<0){
            printf("NO");
            system("pause");
            return 0;
        }
        if(a=='@'){
            if(jud==0){
                printf("YES");
                system("pause");
                return 0;
            }
            else
            {
                printf("NO");
                system("pause");
                return 0;
            }
            
        }
    }
}