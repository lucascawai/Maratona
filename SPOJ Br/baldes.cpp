#include <stdio.h>
#include <string.h>

#define MAXN 100005

int sequencia[MAXN], sequencia_aux[MAXN];
int cont;

void mergeSort(int begin, int end)
{
    int left=0, right=0, middle=0;

    if(begin==end)
        return;

    middle=(begin+end)/2;

    mergeSort(begin, middle);
    mergeSort(middle+1, end);

    left=begin;
    right=middle+1;

    for(int i=begin; i<=end; i++)
    {
        if(right>end || (left<=middle && sequencia[left]<=sequencia[right]))
        {
            sequencia_aux[i]=sequencia[left];
            left++;
        }
        else
        {
            sequencia_aux[i]=sequencia[right];
            cont+=right-left+1;
            right++;
        }
    }
    for(int i=begin; i<=end; i++)
        sequencia[i]=sequencia_aux[i];
}

int main()
{
    int n;

    while(1)
    {
        memset(sequencia, 0, sizeof(sequencia));
        memset(sequencia_aux, 0, sizeof(sequencia_aux));
        cont=0;

        scanf("%d", &n);
        if(n==0)
            break;

        for(int i=1; i<=n; i++)
            scanf("%d", &sequencia[i]);

        mergeSort(1, n);

        if((cont%2)==1)
            printf("Marcelo\n");
        else
            printf("Carlos\n");

    }

    return 0;
}


