#include<stdio.h> 

char items[30]={0};
char N=0;
short methods=0;
//这定义了全局变量，所有的函数都能拿过来用
void get_breakk(char remain, char nb_now, char position);


int main(){
	scanf("%d", &N);
	get_breakk(N, 1, 0);
    printf("There are %d ways to break %d.",methods,N);
	//不知道为啥我电脑中文会乱码，所以写英文了
	return 0;
}

void get_breakk(char remain, char nb_now, char position){
	/*param1：剩下的数第一次为7
	  param2：现在准备分解出来的数字，第一次为1（7-1）
	  param3：现在分解到第几个数字，对应到数组中的位置*/
	if(remain!=0){   //继续分解
		for(nb_now; nb_now<=remain; nb_now++) {
			items[position] = nb_now;
			//把当前正在处理的这个数字按位置添加到数组
			get_breakk(remain-nb_now, nb_now, position+1);
			//这行……发生了些有趣的事情，你尝试理解一下……
		}
	}
    else{  //分解完成
        if(items[0]==N)
            return 0;	//处理最后出现7=7的情况
		printf("%d=%d",N,items[0]);	//打印7=*这个特殊的结构
		for(char i=1; i<position; i++)
			printf("+%d",items[i]); 	//打印后面的数字
        printf(";\n");	//换行
        methods++;	//记数一种分解方式
	}
    return 0;
}
