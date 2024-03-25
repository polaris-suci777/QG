#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define n 50

//数字栈
typedef struct nodeFirst{
    double a[n];
    int size;// 表示栈中含有的元素数量
} stackFirst;

//符号栈
typedef struct nodeSecond{
    char a[n];
    int size;
} stackSecond;

//数字栈出栈
double pop(stackFirst *p) {
    if (p -> size == 0)
        //printf("空栈");
        return 0;
    else {
        --(p -> size);
        return p -> a[p -> size];
    }
}

//符号栈出栈
char popSecond(stackSecond *p) {
    if (p -> size == 0)
        return 0;
    else {
        --(p -> size);
        return p -> a[p -> size];
    }
}

//返回数字栈栈顶元素
double top(stackFirst *p) {
    if (p -> size == 0)
        return 0;//输出0表示空
    else {
        return p -> a[p -> size - 1];
    }
}

//返回符号栈栈顶元素
char topSecond(stackSecond *p) {
    if (p -> size == 0)
        return 0;//输出0表示空
    else {
        return p -> a[p -> size - 1];
    }
}

//将数字栈置空
int empty(stackFirst *p) {
    return p -> size == 0;
}

//将符号栈置空
int emptySecond(stackSecond *p) {
    return p -> size == 0;
}

//数字栈入栈
void push(stackFirst *p, double b) {
    p -> a[p -> size] = b;
    ++p -> size;
}

//符号栈入栈
void pushSecond(stackSecond *p, char b) {
    p -> a[p -> size] = b;
    ++p -> size;
}

//比较符号优先级
int compare(char str) {
    if (str == '+' || str == '-') {
        return 1;
    } else if (str == '*' || str == '/') {
        return 2;
    } else {
        return 0;
    }
}

//计算
double counter(double x, double y, char str) {
    double ans = 0.0;
    if (str == '-') {
        ans = x - y;
    } else if (str == '+') {
        ans = x + y;
    } else if (str == '*') {
        ans = x * y;
    } else {
        ans = x / y;
    }
    return ans;
}

int main(void) {
    while(1) {
        int key=0;
        //数字栈
        stackFirst *first;
        first = (stackFirst *) malloc(sizeof(stackFirst));
        first->size = 0;
        //符号栈
        stackSecond *second;
        second = (stackSecond *) malloc(sizeof(stackSecond));
        second->size = 0;
        char a[100];
        printf("请输入需要计算的算术表达式：\n");
        scanf("%s", a);
        int length = (int) strlen(a);
        //在用户所输入的式子后面加‘#’号
        a[length] = '#';
        length = length + 1;
        int i = 0;
        double x = 0;
        //出栈用于计算的符号
        char strtest;
        //出栈用于计算的数字
        double numFirst, numSecond;
        //用于保存当次计算结果
        double res;
        while (a[i] != '#') {
            //如果出现字符就报错
            if (a[i] >= 'a' && a[i] <= 'z'||a[i] >= 'A' && a[i] <= 'Z'){
                printf("你输入的表达式有误!\n");
                key=1;
                break;
            }
            x = 0;
            //如果是数字就入数字栈
            if (a[i] >= '0' && a[i] <= '9') {
                while (a[i] >= '0' && a[i] <= '9') {
                    x *= 10;
                    x += a[i++] - '0';
                }
                //计算是小数的情况
                if (a[i] == '.') {
                    double d = 0.1;
                    ++i;
                    while (a[i] >= '0' && a[i] <= '9') {
                        x += ((a[i] - '0') * d);
                        d *= 0.1;
                        ++i;
                    }
                }
                //数字进栈
                push(first, x);
                continue;
            }

            //如果是符号，且符号栈为空，符号直接进符号栈
            if (second->size == 0 &&
                (a[i] == '+' || a[i] == '-' || a[i] == '*' || a[i] == '/' || a[i] == '(' || a[i] == ')')) {
                pushSecond(second, a[i]);
                ++i;
                continue;
            }

            //如果是左括号，直接入栈
            if (a[i] == '(') {
                pushSecond(second, a[i]);
                ++i;
                continue;
            }

            //如果是右括号，循环取出符号栈中的符号，跟数字栈中两个数字参与运算后入数字栈，直到碰到左括号为止
            if (a[i] == ')') {
                while (topSecond(second) != '(') {
                    strtest = popSecond(second);
                    numFirst = pop(first);
                    numSecond = pop(first);
                    res = counter(numSecond, numFirst, strtest);
                    //计算结果入数据栈
                    push(first, res);
                }
                //左括号出栈
                popSecond(second);
                ++i;
                continue;
            }

            //最后一种情况是要入符号栈
            while (compare(a[i]) <= compare(topSecond(second))) {
                strtest = popSecond(second);
                numFirst = pop(first);
                numSecond = pop(first);
                res = counter(numSecond, numFirst, strtest);
                //计算结果入数据栈
                push(first, res);
            }
            //入符号栈
            pushSecond(second, a[i]);
            ++i;
        }

        //如果符号栈还不为空的情况
        while (second->size > 0) {
            strtest = popSecond(second);
            numFirst = pop(first);
            numSecond = pop(first);
            res = counter(numSecond, numFirst, strtest);
            //计算结果入数据栈
            push(first, res);
        }
        //输出最终计算结果
        if(key!=1){
        printf("%lf\n", top(first));
        }
    }
}
