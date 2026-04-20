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
    int m = 0;
    int s = 0;
    for (int i = 0; i<N;i++){
        if (arrout[i] == -1){
            if(i == 0){
                while (arrout[i + m] == -1){
                    if (m > N-i){
                        arrout[i] = 0;
                        break;
                    }
                    else{
                        m++;
                    }
                }
                arrout[i] = arrout[i+m];
            }
            else if (i == N-1)
            {
                while (arrout[i - m] == -1){
                    if (m == N-1){
                        arrout[i] = 0;
                        break;
                    }
                    else{
                        m++;
                    }
                }
                
                arrout[i] = arrout[i-m];
            }
            else{
                while (1){
                    if (m > N-i && s == i+1){
                        arrout[i] = 0;
                        break;
                    }
                    else if (m > N-i && !(s == i+1))
                    {
                        arrout[i] = arrout[i-s];
                        break;
                    }
                    else if (!(m > N-i) && (s == i+1))
                    {
                        arrout[i] = arrout[i+m];
                        break;
                    }
                    
                    else{
                        if(arrout[i + m] != -1 && arrout[i-s] == -1){
                            s++;
                            
                        }
                        else if (arrout[i + m] == -1 && arrout[i-s] != -1)
                        {
                            m++;
                            
                        }
                        else if (arrout[i+m] == -1 && arrout[i-s] == -1){
                            s++;
                            m++;
                        }
                        else if (arrout[i + m] != -1 && arrout[i-s] != -1)
                        {
                            arrout[i] = (arrout[i + m] + arrout[i-s])/2;
                            break;
                        }
                    }
                    
                }
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

