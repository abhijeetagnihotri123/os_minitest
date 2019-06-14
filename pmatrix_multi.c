#include <stdio.h>
#include <pthread.h>
#define N 4
int a[N][N];
int b[N][N];
int c[N][N];
int count=0;
void *multi(void *args)
{
    int p=*(int*)(args);
    p--;
    for(int i=p;i<(p+1);i++)
    {
        for(int j=0;j<N;j++)
        {
            for(int k=0;k<N;k++)
            {
                c[i][j]+=a[i][k]*b[k][j];
            }
        }
    }
    pthread_exit(0);
}
int main()
{   
    printf("Enter elements in the first matrix\n");
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("Enter elements in the second matrix\n");
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            scanf("%d",&b[i][j]);
        }
    }
    pthread_t tid[N];
    for(int i=0;i<N;i++)
    {
        pthread_create(&tid[i],NULL,multi,&i);
    }
    for(int i=0;i<N;i++)
    {
        pthread_join(tid[i],NULL);
    }
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            printf("%d ",c[i][j]);
        }
        printf("\n");
    }
    return 0;
}