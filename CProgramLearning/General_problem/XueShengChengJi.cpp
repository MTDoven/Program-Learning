#include<iostream>
#include<algorithm>
using namespace std;

typedef struct student_temp{
    int number;
    char name[10];
    float grade1;
    float grade2;
    float grade3;
    float mean;
} student;
student students[100]={0};

bool compare(student x, student y){
    if(x.mean>y.mean) return true;
    else return false;
}

int main(){
    int N=0;
    cin>>N;
    for(int i=0; i<N; i++)
        scanf("%d %s %f %f %f",&students[i].number, students[i].name,
            &students[i].grade1, &students[i].grade2, &students[i].grade3);
    for(int i=0; i<N; i++)
        students[i].mean = (students[i].grade1 + students[i].grade2 + students[i].grade3)/3;
    sort(students, students+N, compare);
    for(int i=0; i<N; i++)
        printf("%d %s %.1f\n",students[i].number, students[i].name, students[i].mean);
    return 0;
}
