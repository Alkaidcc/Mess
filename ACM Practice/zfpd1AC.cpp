#include<stdio.h>
#include<string.h>
int main(){
    char a[60][60];
    while(gets(a[0]) != NULL) {
        int n,cnt=1,cnt2=0,line=0,line3=0,row=0,row3=0,isfirstl=0,isfirstr=0;
        memset(a,0,sizeof(a));
       while(a[0][0]==0)                //判断是否结束
            if(gets(a[0])== NULL)
                return 0;
        while(*gets(a[cnt++])!=0);     
        cnt--;
        //横向遍历
        for(int i=0;i<cnt;i++){             //cnt 表示总行数
            int j=0,flag=1,y=strlen(a[i]);
            if(y>cnt2)                      //y代表每行的长度
                cnt2=y;
            while(a[i][j]!=0){
                int count=1;
                while(a[i][j]=='*'&&a[i][j+1]=='*')
                    count++,j++;            //count 表示连续*的个数
                if(count>=2){
                    if(flag)
                        line++,flag=0;
                    if(i==0||i==cnt-1)
                        isfirstl=1;         //第一行或者最后一行连续的情况
                    if(count>=3){
                        line3++;
                        break;     
                    }
                }
                j++;
            }
        }
        //纵向遍历
        int count2=0,first=0;
        for(int j=0;j<cnt2;j++){        //cnt2 表示总列数
            int flag=1;
            for(int i=0;i<cnt;i++){        
                int count=1;
                if(a[i][j]=='*')
                    count2++;
                while(a[i][j]=='*'&&a[i+1][j]=='*'&&i+1<cnt)
                    count++,i++;          //count 表示连续*的个数
                if(count>=2){
                    if(flag)
                        row++,flag=0;
                    if(j==first||j==cnt2-1)
                        isfirstr=1;     //第一列或者最后一列连续的情况
                    if(count>=3){
                        row3++;
                        break;     
                    }
                }
            }
            if(count2==0&&j==first)         //first 表示有内容的第一列
                first++;
        }
        if(line==3||row==3)         //有三行或者三列连续
            printf("B\n");
        else if(line3==1&&!isfirstl||row3==1&&!isfirstr)
            printf("A\n");
        else 
            printf("C\n");
    }
}
