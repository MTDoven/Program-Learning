#include <stdio.h>
#include <stdlib.h>
float cal(float a, float b, int o)
{
    // char o[5] = {'w', '+', '-', '*', '/'};
    switch (o)
    {
    case 1:
        return a + b;
    case 2:
        return a - b;
    case 3:
        return a * b;
    case 4:
        return a / b;
    }
}
void getexm1(float a, float b, float c, float d, float *exm)
{
}
void tras(float *a, float *b)
{
    float temp;
    temp = *a;
    *a = *b;
    *b = temp;
    return;
}
void get24(float a, float b, float c, float d, int *sign)
{
    char z[5] = {'w', '+', '-', '*', '/'};
    int o1, o2, o3;
    for (o1 = 1; o1 <= 4; o1++)
    {
        for (o2 = 1; o2 <= 4; o2++)
        {
            for (o3 = 1; o3 <= 4; o3++)
            { //列举五种情况，if，else
                //（（AoB）oC）oD
                //需要一个标记，标记为零输出无法形成
                float A1 = cal(a, b, o1);
                float A2 = cal(A1, c, o2);
                float A3 = cal(A2, d, o3);
                if (A3 == 24)
                {
                    printf("\n((%.0f%c%.0f)%c%.0f)%c%.0f", a, z[o1], b, z[o2], c, z[o3], d);
                    *sign = 1;
                }
                //（Ao（BoC））oD
                A1 = 0;
                A2 = 0;
                A3 = 0;
                A1 = cal(b, c, o1);
                A2 = cal(a, A1, o2);
                A3 = cal(A2, d, o3);
                if (A3 == 24)
                {
                    printf("\n(%.0f%c(%.0f%c%.0f))%c%.0f", a, z[o2], b, z[o1], c, z[o3], d); //写出表达式
                    *sign = 1;
                }
                // Ao(Bo(CoD))
                A1 = 0;
                A2 = 0;
                A3 = 0;
                A1 = cal(c, d, o1);
                A2 = cal(b, A1, o2);
                A3 = cal(a, A2, o3);
                if (A3 == 24)
                {
                    printf("\n%.0f%c(%.0f%c(%.0f%c%.0f))", a, z[o3], b, z[o2], c, z[o1], d); //写出表达式
                    *sign = 1;
                }
                // Ao((BoC)oD)
                A1 = 0;
                A2 = 0;
                A3 = 0;
                A1 = cal(b, c, o1);
                A2 = cal(A1, d, o2);
                A3 = cal(a, A2, o3);
                if (A3 == 24)
                {
                    printf("\n%.0f%c((%.0f%c%.0f)%c%.0f)", a, z[o3], b, z[o1], c, z[o2], d); //写出表达式
                    *sign = 1;
                }
                //(AoB)o(CoD)
                A1 = 0;
                A2 = 0;
                A3 = 0;
                A1 = cal(a, b, o1);
                A2 = cal(c, d, o2);
                A3 = cal(A1, A2, o3);
                if (A3 == 24)
                {
                    printf("\n(%.0f%c%.0f)%c(%.0f%c%.0f)", a, z[o1], b, z[o3], c, z[o2], d); //写出表达式//写出表达式
                    *sign = 1;
                }
            }
        }
    }
    return;
}
int main()
{
    float num[4] = {0};
    for (int i = 0; i < 4; i++)
    {
        scanf("%f", &num[i]);
    }
    int sign = 0;
    int *sign2 = &sign;
    float exm[24][4] = {{num[0], num[1], num[2], num[3]},
                        {num[0], num[1], num[3], num[2]},
                        {num[0], num[2], num[1], num[3]},
                        {num[0], num[2], num[3], num[1]},
                        {num[0], num[3], num[1], num[2]},
                        {num[0], num[3], num[2], num[1]},
                        {num[1], num[0], num[2], num[3]},
                        {num[1], num[0], num[3], num[2]},
                        {num[1], num[2], num[0], num[3]},
                        {num[1], num[2], num[3], num[0]},
                        {num[1], num[3], num[2], num[0]},
                        {num[1], num[3], num[0], num[2]},
                        {num[2], num[0], num[1], num[3]},
                        {num[2], num[0], num[3], num[1]},
                        {num[2], num[1], num[3], num[0]},
                        {num[2], num[1], num[0], num[3]},
                        {num[2], num[3], num[0], num[1]},
                        {num[2], num[3], num[1], num[0]},
                        {num[3], num[0], num[1], num[2]},
                        {num[3], num[0], num[2], num[1]},
                        {num[3], num[1], num[0], num[2]},
                        {num[3], num[1], num[2], num[0]},
                        {num[3], num[2], num[1], num[0]},
                        {num[3], num[2], num[0], num[1]}};
    float exm1[12][4] = {{num[0], num[1], num[2], num[3]},
                         {num[0], num[1], num[3], num[2]},
                         {num[0], num[2], num[1], num[3]},
                         {num[0], num[3], num[1], num[2]},
                         {num[0], num[2], num[3], num[1]},
                         {num[0], num[3], num[2], num[1]},
                         {num[2], num[1], num[0], num[3]},
                         {num[3], num[1], num[0], num[2]},
                         {num[2], num[0], num[3], num[1]},
                         {num[3], num[0], num[2], num[1]},
                         {num[2], num[3], num[1], num[0]},
                         {num[3], num[2], num[1], num[0]}};
    float exm2[4][4] = {{num[0], num[1], num[2], num[3]},
                        {num[0], num[1], num[3], num[2]},
                        {num[0], num[3], num[1], num[2]},
                        {num[3], num[0], num[1], num[2]}};
    float exm3[6][4] = {{num[0], num[1], num[2], num[3]},
                        {num[0], num[2], num[1], num[3]},
                        {num[0], num[3], num[2], num[1]},
                        {num[2], num[3], num[0], num[1]},
                        {num[2], num[0], num[3], num[1]},
                        {num[2], num[1], num[0], num[3]}};
    float *a = &num[0];
    float *b = &num[1];
    float *c = &num[2];
    float *d = &num[3];
    if ((num[0] != num[1]) && (num[0] != num[2]) && (num[0] != num[3]) && (num[2] != num[1]) && (num[3] != num[1]) && (num[2] != num[3]))
    {
        for (int i = 0; i < 24; i++)
        {
            get24(exm[i][0], exm[i][1], exm[i][2], exm[i][3], sign2);
        }
    }
    // 12 34
    if ((num[0] == num[1]) && (num[2] == num[3]) && num[0] != num[2])
    {
        for (int i = 0; i < 6; i++)
        {
            get24(exm3[i][0], exm3[i][1], exm3[i][2], exm3[i][3], sign2);
        }
    }
    // 13 24
    if ((num[0] == num[2]) && (num[1] == num[3]) && num[0] != num[1])
    {
        tras(b, c);
        float exm3[6][4] = {{num[0], num[1], num[2], num[3]}, {num[0], num[2], num[1], num[3]}, {num[0], num[3], num[2], num[1]}, {num[2], num[3], num[0], num[1]}, {num[2], num[0], num[3], num[1]}, {num[2], num[1], num[0], num[3]}};
        for (int i = 0; i < 6; i++)
        {
            get24(exm3[i][0], exm3[i][1], exm3[i][2], exm3[i][3], sign2);
        }
        tras(b, c);
    }
    // 14 23
    if ((num[0] == num[3]) && (num[1] == num[2]) && num[0] != num[1])
    {
        tras(b, d);
        float exm3[6][4] = {{num[0], num[1], num[2], num[3]}, {num[0], num[2], num[1], num[3]}, {num[0], num[3], num[2], num[1]}, {num[2], num[3], num[0], num[1]}, {num[2], num[0], num[3], num[1]}, {num[2], num[1], num[0], num[3]}};
        for (int i = 0; i < 6; i++)
        {
            get24(exm3[i][0], exm3[i][1], exm3[i][2], exm3[i][3], sign2);
        }
        tras(b, d);
    }
    // 12
    if ((num[0] == num[1]) && (num[0] != num[2]) && (num[0] != num[3]) && (num[2] != num[3]))
    {
        for (int i = 0; i < 12; i++)
        {
            get24(exm1[i][0], exm1[i][1], exm1[i][2], exm1[i][3], sign2);
        }
    }
    // 13bug
    if ((num[0] == num[2]) && (num[0] != num[1]) && (num[0] != num[3]) && (num[1] != num[3]))
    {
        tras(b, c);
        float exm1[12][4] = {{num[0], num[1], num[2], num[3]}, {num[0], num[1], num[3], num[2]}, {num[0], num[2], num[1], num[3]}, {num[0], num[3], num[1], num[2]}, {num[0], num[2], num[3], num[1]}, {num[0], num[3], num[2], num[1]}, {num[2], num[1], num[0], num[3]}, {num[3], num[1], num[0], num[2]}, {num[2], num[0], num[3], num[1]}, {num[3], num[0], num[2], num[1]}, {num[2], num[3], num[1], num[0]}, {num[3], num[2], num[1], num[0]}};
        for (int i = 0; i < 12; i++)
        {
            get24(exm1[i][0], exm1[i][1], exm1[i][2], exm1[i][3], sign2);
        }
        tras(b, c);
    }
    // 14
    if ((num[0] == num[3]) && (num[0] != num[1]) && (num[0] != num[2]) && (num[1] != num[2]))
    {
        tras(b, d);
        float exm1[12][4] = {{num[0], num[1], num[2], num[3]}, {num[0], num[1], num[3], num[2]}, {num[0], num[2], num[1], num[3]}, {num[0], num[3], num[1], num[2]}, {num[0], num[2], num[3], num[1]}, {num[0], num[3], num[2], num[1]}, {num[2], num[1], num[0], num[3]}, {num[3], num[1], num[0], num[2]}, {num[2], num[0], num[3], num[1]}, {num[3], num[0], num[2], num[1]}, {num[2], num[3], num[1], num[0]}, {num[3], num[2], num[1], num[0]}};
        for (int i = 0; i < 12; i++)
        {
            get24(exm1[i][0], exm1[i][1], exm1[i][2], exm1[i][3], sign2);
        }
        tras(b, d);
    }
    // 23
    if ((num[1] == num[2]) && (num[1] != num[0]) && (num[1] != num[3]) && (num[0] != num[3]))
    {
        tras(a, c);
        float exm1[12][4] = {{num[0], num[1], num[2], num[3]}, {num[0], num[1], num[3], num[2]}, {num[0], num[2], num[1], num[3]}, {num[0], num[3], num[1], num[2]}, {num[0], num[2], num[3], num[1]}, {num[0], num[3], num[2], num[1]}, {num[2], num[1], num[0], num[3]}, {num[3], num[1], num[0], num[2]}, {num[2], num[0], num[3], num[1]}, {num[3], num[0], num[2], num[1]}, {num[2], num[3], num[1], num[0]}, {num[3], num[2], num[1], num[0]}};
        for (int i = 0; i < 12; i++)
        {
            get24(exm1[i][0], exm1[i][1], exm1[i][2], exm1[i][3], sign2);
        }
        tras(a, c);
    }
    // 24
    if ((num[1] == num[3]) && (num[1] != num[0]) && (num[1] != num[2]) && (num[0] != num[2]))
    {
        tras(a, d);
        float exm1[12][4] = {{num[0], num[1], num[2], num[3]}, {num[0], num[1], num[3], num[2]}, {num[0], num[2], num[1], num[3]}, {num[0], num[3], num[1], num[2]}, {num[0], num[2], num[3], num[1]}, {num[0], num[3], num[2], num[1]}, {num[2], num[1], num[0], num[3]}, {num[3], num[1], num[0], num[2]}, {num[2], num[0], num[3], num[1]}, {num[3], num[0], num[2], num[1]}, {num[2], num[3], num[1], num[0]}, {num[3], num[2], num[1], num[0]}};
        for (int i = 0; i < 12; i++)
        {
            get24(exm1[i][0], exm1[i][1], exm1[i][2], exm1[i][3], sign2);
        }
        tras(a, d);
    }
    // 34
    if ((num[2] == num[3]) && (num[2] != num[0]) && (num[2] != num[1]) && (num[0] != num[1]))
    {
        tras(a, c);
        tras(b, d);
        float exm1[12][4] = {{num[0], num[1], num[2], num[3]}, {num[0], num[1], num[3], num[2]}, {num[0], num[2], num[1], num[3]}, {num[0], num[3], num[1], num[2]}, {num[0], num[2], num[3], num[1]}, {num[0], num[3], num[2], num[1]}, {num[2], num[1], num[0], num[3]}, {num[3], num[1], num[0], num[2]}, {num[2], num[0], num[3], num[1]}, {num[3], num[0], num[2], num[1]}, {num[2], num[3], num[1], num[0]}, {num[3], num[2], num[1], num[0]}};
        for (int i = 0; i < 12; i++)
        {
            get24(exm1[i][0], exm1[i][1], exm1[i][2], exm1[i][3], sign2);
        }
        tras(b, d);
        tras(a, c);
    }
    // 123
    if ((num[0] == num[1]) && (num[0] == num[2]) && (num[0] != num[3]))
    {
        for (int i = 0; i < 4; i++)
        {
            get24(exm2[i][0], exm2[i][1], exm2[i][2], exm2[i][3], sign2);
        }
    }
    // 124 bug
    if ((num[0] == num[1]) && (num[0] == num[3]) && (num[0] != num[2]))
    {
        tras(c, d);
        float exm2[4][4] = {{num[0], num[1], num[2], num[3]}, {num[0], num[1], num[3], num[2]}, {num[0], num[3], num[1], num[2]}, {num[3], num[0], num[1], num[2]}};
        for (int i = 0; i < 4; i++)
        {
            get24(exm2[i][0], exm2[i][1], exm2[i][2], exm2[i][3], sign2);
        }
        tras(c, d);
    }
    // 134 bug
    if ((num[0] == num[2]) && (num[0] == num[3]) && (num[0] != num[1]))
    {
        tras(b, d);
        float exm2[4][4] = {{num[0], num[1], num[2], num[3]}, {num[0], num[1], num[3], num[2]}, {num[0], num[3], num[1], num[2]}, {num[3], num[0], num[1], num[2]}};
        for (int i = 0; i < 4; i++)
        {
            get24(exm2[i][0], exm2[i][1], exm2[i][2], exm2[i][3], sign2);
        }
        tras(b, d);
    }
    // 234
    if ((num[1] == num[2]) && (num[1] == num[3]) && (num[0] != num[1]))
    {
        tras(a, d);
        float exm2[4][4] = {{num[0], num[1], num[2], num[3]}, {num[0], num[1], num[3], num[2]}, {num[0], num[3], num[1], num[2]}, {num[3], num[0], num[1], num[2]}};
        for (int i = 0; i < 4; i++)
        {
            get24(exm2[i][0], exm2[i][1], exm2[i][2], exm2[i][3], sign2);
        }
        tras(a, d);
    }
    // 1234
    if ((num[0] == num[1]) && (num[0] == num[2]) && (num[0] == num[3]))
    {
        get24(num[0], num[1], num[2], num[3], sign2);
    }
    if (sign == 0)
    {
        printf("不可以");
    }
    system("pause");
    return 0;
}
