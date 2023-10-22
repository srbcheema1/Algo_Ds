//C program for Bankers Algorithm

#include<stdio.h>
#include<stdlib.h>
void main(){
    int n,m,i,j,k;
    printf("Process\n");
    scanf("%d",&n);
    printf("Resource\n");
    scanf("%d",&m);
    int alloc[n][m],max[n][m], avail[m];
    printf("Allo\n");
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            scanf("%d",&alloc[i][j]);
    printf("Max\n");
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            scanf("%d",&max[i][j]);
    printf("Allo\n");
    for(i=0;i<m;i++)
        scanf("%d",&avail[i]);
    int f[n],ans[n],index=0;
    for(k=0;k<n;k++)
        f[k]=0;
    int need[n][m];
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            need[i][j]=abs(max[i][j]-alloc[i][j]);
    printf("Need\n");
    for(i=0;i<n;i++) {
        for(j=0;j<m;j++)
            printf("%d ",need[i][j]);
        printf("\n");
    }

    int y=0;
    for(k=0;k<5;k++) {
        for(i=0;i<n;i++) {
            if(f[i]==0){
                int flag=0;
                for(j=0;j<m;j++){
                    if(need[i][j]>avail[j]){
                        flag=1;
                        break;
                    }
                }
                if(flag==0){
                    ans[index++]=i;
                    for(y=0;y<m;y++)
                        avail[y]+=alloc[i][y];
                    f[i]=1;
                }
            }
        }
    }
    int flag=1;
    for(int i=0;i<n;i++)
        if(f[i]==0){
            flag=0;
            printf("not safe\n");
            break;
        }
    if(flag==1){
        printf("safe\n");
        for(i=0;i<n-1;i++)
            printf("P%d->",ans[i]);
        printf("P%d\n",ans[n-1]);
    }
}
