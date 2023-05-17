#include<stdio.h>

int main(){
    short n = -1;
    short rate[4] = {0};
    short r = -1;

    scanf("%hd", &n);
    for(int i=0; i<n; i++)
        scanf("%hd",&rate[i]);

    for(int i=0; i<n; i++){
        r = rate[i];
        if(r<1200) printf("Newbie\n");
        else if(r<1400) printf("Pupil\n");
        else if (r<1600) printf("Specialist\n");
        else if (r<1900) printf("Expert\n");
        else if (r<2100) printf("Candidate Master\n");
        else if (r<2300) printf("Master\n");
        else if (r<2400) printf("International Master\n");
        else if (r<2600) printf("Grandmaster\n");
        else if (r<3000) printf("International Grandmaster\n");
        else printf("Legendary Grandmaster\n"); 
    }
    
    return 0;
}



