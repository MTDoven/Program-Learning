# include <stdio.h>

int main(){
    int n=1;
    int m=-1;
    scanf("%d", &m);

    for(int first=n; first<=m; first++){
        for(int secend=n; secend<=m; secend++){
            for(int third=n; third<=m; third++){
                for(int fourth=n; fourth<=m; fourth++){
                    if(first*secend*third*fourth!=m) continue;
                    printf("<%d,%d,%d,%d>\n",first,secend,third,fourth); 
                }
            }
        }
    }

    return 0;
}