# include <stdio.h>

int main(){
    int n,m;
    scanf("%d %d", &n, &m);

    for(int first=n; first<=m; first++){
        for(int secend=n; secend<=m; secend++){
            for(int third=n; third<=m; third++){
                if(n>=first) continue;
                if(first>=secend) continue;
                if(secend>=third) continue;
                if(third>=m) continue;
                if(3>=m-n) continue;
                if(m-n>=7) continue;
                printf("<%d,%d,%d>\n",first,secend,third); 
            }
        }
    }

    return 0;
}