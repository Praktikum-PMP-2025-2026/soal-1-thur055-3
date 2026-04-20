#include <stdio.h>
#include <stdlib.h>

#define MAX_DATA 512
int search_len(int *arrin, int N){
    int arrout[N];
    int j = 0;
    for (int i = 0; i<N; i++){
        if(arrin[i]==-1){
            arrout[j] = i;
            j++;
        }
    }
    return j;
}

int main(){
    int N;
    int j = 0;
    scanf("%d ",&N);
    int arr[N];
    int arrout[N]; 
    for(int i = 0; i< N-1; i++){
        scanf("%d ", &arr[i]);
    }
    scanf("%d", &arr[N-1]);
    for(int i = 0; i< N; i++){
        arrout[i] = arr[i];
    }
    j = search_len(arr, N);
    int arridx[j];
    int k = 0;
    for(int i = 0; i<N-1;i++){
        if (arr[i]==-1){
            arridx[k] = i;
            k++;
        }
    
    }
    /*for(int i = 0; i<j; i++){
        printf("%d ", arridx[i]);
    }
        */
    for (int i = 0; i<j;i++){
        if (arridx[0] == 0){
            if(arr[1]== -1){
                arrout[0] = 0;
            }
            else{
                arrout[0] = arrout[1];
            }
        }
        else{
            if(arr[arridx[i]+1]==-1 && arr[arridx[i]-1]==-1){
                arrout[arridx[i]] = 0;
                k++;
            }
            else if (arr[arridx[i]+1]==-1 && !(arr[arridx[i]-1]==-1))
            {
                arrout[arridx[i]] = arr[arridx[i]-1];
                k++;
            }
            else if (!(arr[arridx[i]+1]==-1) && arr[arridx[i]-1]==-1)
            {
                arrout[arridx[i]] = arr[arridx[i]+1];
                k++;
            }
            else if (!(arr[arridx[i]+1]==-1) && !(arr[arridx[i]-1]==-1))
            {
                arrout[arridx[i]] = (arr[arridx[i]-1]+arr[arridx[i]+1])/2;
                k++;
            }
        }
    }
    printf("RECOVERED ");
    int sum = 0;
    for(int i = 0; i < N;i++){
        printf("%d ", arrout[i]);
        sum = sum + arrout[i];
    }
    printf("\n");
    printf("MAX_SUM %d", sum);

}

