#include <stdio.h>
#define LENGTH 20
#define WIDTH 5

int position[LENGTH][WIDTH]={0};
int choose_position(int ticket_numbers);
int check_if_posible(int row_number, int people_number);

int main(){
    int order_numbers = -1;
    int ticket_numbers = -1;
    scanf("%d",&order_numbers);
    for(int i=0; i<order_numbers; i++){
        scanf("%d",&ticket_numbers);
        choose_position(ticket_numbers);}
    return 0;
}

int choose_position(int ticket_numbers){
    int start_pos = -1;
    for(int row=0; row<LENGTH; row++){
        start_pos = check_if_posible(row, ticket_numbers);
        //printf("start_pos:%d\n",start_pos);
        if(start_pos==-1) continue;
        for(int i=start_pos; i<ticket_numbers+start_pos; i++){
            position[row][i]=1;
            printf("%d ",5*row+(i+1)); }
        printf("\n");
        return 1;
    } // can find a constant position 
    int count=0;
    for(int i=0; i<LENGTH; i++)
        for(int j=0; j<WIDTH; j++)
            if(position[i][j]==0){
                position[i][j]==1; count++;
                printf("%d ",5*i+(j+1));
                if(count==ticket_numbers){
                    printf("\n");
                    return 2; }
            } // can find an inconstant position
    return -1; // cannot find any position
} // choose a position

int check_if_posible(int row_number, int people_number){
    int count = 0;
    for(int i=0; i<WIDTH; i++)
        if(position[row_number][i]==0) count++;
    if(count>=people_number) return 5-count;
    else return -1;
} // return the posible start position in the very row
// or return -1 for imposible

