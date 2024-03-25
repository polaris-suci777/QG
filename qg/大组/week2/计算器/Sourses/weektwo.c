#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define n 50

//����ջ
typedef struct nodeFirst{
    double a[n];
    int size;// ��ʾջ�к��е�Ԫ������
} stackFirst;

//����ջ
typedef struct nodeSecond{
    char a[n];
    int size;
} stackSecond;

//����ջ��ջ
double pop(stackFirst *p) {
    if (p -> size == 0)
        //printf("��ջ");
        return 0;
    else {
        --(p -> size);
        return p -> a[p -> size];
    }
}

//����ջ��ջ
char popSecond(stackSecond *p) {
    if (p -> size == 0)
        return 0;
    else {
        --(p -> size);
        return p -> a[p -> size];
    }
}

//��������ջջ��Ԫ��
double top(stackFirst *p) {
    if (p -> size == 0)
        return 0;//���0��ʾ��
    else {
        return p -> a[p -> size - 1];
    }
}

//���ط���ջջ��Ԫ��
char topSecond(stackSecond *p) {
    if (p -> size == 0)
        return 0;//���0��ʾ��
    else {
        return p -> a[p -> size - 1];
    }
}

//������ջ�ÿ�
int empty(stackFirst *p) {
    return p -> size == 0;
}

//������ջ�ÿ�
int emptySecond(stackSecond *p) {
    return p -> size == 0;
}

//����ջ��ջ
void push(stackFirst *p, double b) {
    p -> a[p -> size] = b;
    ++p -> size;
}

//����ջ��ջ
void pushSecond(stackSecond *p, char b) {
    p -> a[p -> size] = b;
    ++p -> size;
}

//�ȽϷ������ȼ�
int compare(char str) {
    if (str == '+' || str == '-') {
        return 1;
    } else if (str == '*' || str == '/') {
        return 2;
    } else {
        return 0;
    }
}

//����
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
        //����ջ
        stackFirst *first;
        first = (stackFirst *) malloc(sizeof(stackFirst));
        first->size = 0;
        //����ջ
        stackSecond *second;
        second = (stackSecond *) malloc(sizeof(stackSecond));
        second->size = 0;
        char a[100];
        printf("��������Ҫ������������ʽ��\n");
        scanf("%s", a);
        int length = (int) strlen(a);
        //���û��������ʽ�Ӻ���ӡ�#����
        a[length] = '#';
        length = length + 1;
        int i = 0;
        double x = 0;
        //��ջ���ڼ���ķ���
        char strtest;
        //��ջ���ڼ��������
        double numFirst, numSecond;
        //���ڱ��浱�μ�����
        double res;
        while (a[i] != '#') {
            //��������ַ��ͱ���
            if (a[i] >= 'a' && a[i] <= 'z'||a[i] >= 'A' && a[i] <= 'Z'){
                printf("������ı��ʽ����!\n");
                key=1;
                break;
            }
            x = 0;
            //��������־�������ջ
            if (a[i] >= '0' && a[i] <= '9') {
                while (a[i] >= '0' && a[i] <= '9') {
                    x *= 10;
                    x += a[i++] - '0';
                }
                //������С�������
                if (a[i] == '.') {
                    double d = 0.1;
                    ++i;
                    while (a[i] >= '0' && a[i] <= '9') {
                        x += ((a[i] - '0') * d);
                        d *= 0.1;
                        ++i;
                    }
                }
                //���ֽ�ջ
                push(first, x);
                continue;
            }

            //����Ƿ��ţ��ҷ���ջΪ�գ�����ֱ�ӽ�����ջ
            if (second->size == 0 &&
                (a[i] == '+' || a[i] == '-' || a[i] == '*' || a[i] == '/' || a[i] == '(' || a[i] == ')')) {
                pushSecond(second, a[i]);
                ++i;
                continue;
            }

            //����������ţ�ֱ����ջ
            if (a[i] == '(') {
                pushSecond(second, a[i]);
                ++i;
                continue;
            }

            //����������ţ�ѭ��ȡ������ջ�еķ��ţ�������ջ���������ֲ��������������ջ��ֱ������������Ϊֹ
            if (a[i] == ')') {
                while (topSecond(second) != '(') {
                    strtest = popSecond(second);
                    numFirst = pop(first);
                    numSecond = pop(first);
                    res = counter(numSecond, numFirst, strtest);
                    //������������ջ
                    push(first, res);
                }
                //�����ų�ջ
                popSecond(second);
                ++i;
                continue;
            }

            //���һ�������Ҫ�����ջ
            while (compare(a[i]) <= compare(topSecond(second))) {
                strtest = popSecond(second);
                numFirst = pop(first);
                numSecond = pop(first);
                res = counter(numSecond, numFirst, strtest);
                //������������ջ
                push(first, res);
            }
            //�����ջ
            pushSecond(second, a[i]);
            ++i;
        }

        //�������ջ����Ϊ�յ����
        while (second->size > 0) {
            strtest = popSecond(second);
            numFirst = pop(first);
            numSecond = pop(first);
            res = counter(numSecond, numFirst, strtest);
            //������������ջ
            push(first, res);
        }
        //������ռ�����
        if(key!=1){
        printf("%lf\n", top(first));
        }
    }
}
