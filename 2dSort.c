#include<stdio.h>
int main(){
    int a[4][4];
    int b[16];
    int m=0;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            scanf("%d",&a[i][j]);
            b[m]=a[i][j];
            m++;
        }
    }
    int temp=0;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            for(int k=0;k<4;k++){
                for(int l=0;l<4;l++){
                    if(a[i][j]<a[k][l]){
                        temp=a[i][j];
                        a[i][j]=a[k][l];
                        a[k][l]=temp;
                    }
                }
            }
        }
    }
    for(int i=0;i<16;i++){
        for(int j=0;j<16;j++){
            if(b[i]<b[j]){
                temp=b[i];
                b[i]=b[j];
                b[j]=temp;
            }
        }
    }

    for(int i=0;i<16;i++){
            printf("%d ",b[i]);
             if(i%4==0)
              printf("\n");
    }
    return 0;
}
