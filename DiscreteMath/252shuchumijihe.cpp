# include <iostream>
# include <string>
# include <string.h>
# include <vector>
# include <math.h>
# include <algorithm>

using namespace std;

int length = -1;
char array[1001] = {0};
void next(){
    for(int i=0; i<length; i++){
        if (array[i]==0){
            array[i]++;
            break;
        } else array[i]=0;
    }
}
bool cmp(string str1, string str2){
    if (str1.size() < str2.size()) return true;
    else if (str1.size() > str2.size()) return false;
    else {
        if (strcmp(str1.c_str(), str2.c_str())<0) return true;
        else return false;
    }
}


int main(){
    int ignore = 0;

    char temp = 0;
    char rubbish = 0;
    scanf("%c",&rubbish);
    vector<string> listt;
    string tempstr = "";
    while (scanf("%c",&temp)!=EOF){
        if (temp=='{') ignore++;
        if (temp=='}') ignore--;
        if ((temp==',' && ignore==0) || ignore==-1){
            listt.push_back(tempstr);
            tempstr = "";
            if (ignore==-1) break;
            continue;
        } tempstr+=temp;
    } // input
    length = listt.size();

    vector<string> result;
    int items = (int)(pow(2,length)+0.5);
    for(int i=0; i<items; i++){
        tempstr = "{";
        for(int j=0; j<length; j++){
            if (array[j]==0) continue;
            tempstr = tempstr + listt[j] + ',';
        } // construct string
        tempstr = tempstr.substr(0, tempstr.size()-1)+"}";
        result.push_back(tempstr);
        next();
    } // get output
    
    sort(result.begin(), result.end(), cmp);
    // sort

    cout << "{";
    for (string t:result){
        if(t!="{}")
            cout<<t<<endl;
    } // output

    return 0;
}




/*
{a,b,c}
{}
{a}
{a,b,c,d}
{a,b}
{{},{a},{b},{a,b}}


*/