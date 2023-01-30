#include<stdio.h>
#include<stdlib.h>
int flag1=0,flag2=0;
void print(int a[3][3]){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(j==0 || j==1){
                if(a[i][j]==0){
                    printf(" ");
                }
                printf(" %c  |",a[i][j]);
            }
            if(j==2){
                printf(" %c ",a[i][j]);
            }
        }
        if(i==0 || i==1){
            printf("\n____|____|____\n");
        }
        if(i==2){
            printf("\n    |    |\n");
        }
    }
    printf("\n");  
}
void win(int a[3][3]){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            int s1=0,s2=0,s3=0,s4=0,s5=0,s6,s7,s8=0,s9=0;
            if((i==0 && j==0) ||(i==0 && j==2) || (i==2 && j==0) || (i==2 && j==2)){
                for(int k=0;k<3;k++){
                    s1+=a[i][k];
                    s2+=a[k][j];
                }
                if((i==0 && j==0) || (i==2 && j==2)){
                    s3=a[0][0]+a[2][2]+a[1][1];
                }
                if((i==0 && j==2) || (i==2 && j==0)){
                    s3=a[0][2]+a[2][0]+a[1][1];
                }
            }
            else if(i==1 && j==1){
                for(int k=0;k<3;k++){
                    s4+=a[i][k];
                    s5+=a[k][j];
                }
                s6=a[0][0]+a[2][2]+a[1][1];
                s7=a[0][2]+a[2][0]+a[1][1];
            }
            else{
                for(int k=0;k<3;k++){
                    s8+=a[i][k];
                    s9+=a[k][j];
                }
            }
            if(s1==144||s2==144||s3==144 ||s4==144||s5==144||s6==144||s7==144||s8==144||s9==144){
                flag1=1;
            }
            if(s1==264||s2==264||s3==264 ||s4==264||s5==264||s6==264||s7==264||s8==264||s9==264){
                flag2=1;
            }
        }
    }
}
void update(int a[3][3],int p,int k){
    int n ,m;
    switch (k)
    {
    case 1:
        n=0;
        m=0;
        break;
    case 2:
        n=0;
        m=1;
        break;
    case 3:
        n=0;
        m=2;
        break;
    case 4:
        n=1;
        m=0;
        break;
    case 5:
        n=1;
        m=1;
        break;
    case 6:
        n=1;
        m=2;
        break;
    case 7:
        n=2;
        m=0;
        break;
    case 8:
        n=2;
        m=1;
        break;
    case 9:
        n=2;
        m=2;
        break; 
    }                                   
    if(p==1){
        a[n][m]=48;
    }
    else{
        a[n][m]=88;
    }
}
int main(){
    int a[3][3]={0,0,0,0,0,0,0,0,0};
    int arr[9]={0,0,0,0,0,0,0,0,0};
    for(int i=2;i<11;i++){
        int n,m;
        if(i%2==0){
            scnf:
                printf("Enter position  player 1: ");
                scanf("%d",&n);    
            if(n>0 && n<10){
                if(arr[n]==0){
                    arr[n]=1;
                }
                else{
                    printf("Position is reserved Please enter again : \n");
                    goto scnf;
                }
                update(a,1,n);
            }
            else{
                printf("Enter valid position\n");
                goto scnf;
            }
            system("cls");
            print(a);
            win(a);
            if(flag1==1){
                printf("First Player wins  !!!!!! >>>.");
                break;
            }
        }
        else{
            scan:
                printf("Enter position player 2: ");
                scanf("%d",&n);
            if(n>0 && n<10){
                if(arr[n]==0){
                    arr[n]=1;
                }
                else{
                    printf("Position is reserved Please enter again : \n");
                    goto scan;
                }
                update(a,2,n);
            }
            else{
                printf("Enter valid position\n");
                goto scan;
            }
            system("cls");
            print(a);
            win(a);
            if(flag2==1){
                printf(" Second Player wins  !!!! >>>.");
                break;
            }
        }   
    }
    if(flag1==0 && flag2==0){
        printf("Match is draw>>>>>\n");
    }
    return 0;
}