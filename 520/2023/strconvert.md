# �ַ�����ָ�롢ָ�볣���α���
```c
/**
 * @file strConvert.c
 * @author Rabbit/003Assistant (xiali123.ch@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-05-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdio.h>
#include <string.h>

#define ELEM_CHAR

#ifdef ELEM_INT
typedef int elem;
#elif defined(ELEM_CHAR)
typedef char elem;
#endif

int main()
{
    // �����ֵ
    elem SingleAssign_0[10]; // ֻ���������ֵ
    printf("sizeof:%d,random strlen:%d\n", sizeof(SingleAssign_0), strlen(SingleAssign_0));
    elem SingleAssign_1[10] = {'s', '1', '2', '3', '4'}; // �Զ�Ϊ����ֵ��ֵ
    printf("%s\n", SingleAssign_1);
    printf("sizeof:%d,strlen:%d\n", sizeof(SingleAssign_1), strlen(SingleAssign_1));

    elem SingleAssign_2[] = {'s', '1', '2', '3', '4', '\0'}; // �����β
    printf("%s\n", SingleAssign_2);
    printf("sizeof:%d,strlen:%d\n", sizeof(SingleAssign_2), strlen(SingleAssign_2)); //'s1234'+'\0' �����ַ�

    // ���帳ֵ
    elem GroupAssign_1[10] = "s1234"; //'s1234'+'\0' �����ַ�
    printf("%s\n", GroupAssign_1);

    elem GroupAssign_2[] = "s1234"; // ���÷�β
    printf("%s\n", GroupAssign_2);
    // GroupAssign_2 = "1234"; // Illegal ���鲻�������޸�
    printf("%d,%d,%d,%d\n", strlen(SingleAssign_1), strlen(SingleAssign_2), strlen(GroupAssign_1), strlen(GroupAssign_2));

    // elem *PointerAssign_by_Single = {'p','1', '2', '3', '4'};
    // printf("%s\n", PointerAssign_by_Single);
    // PointerAssign_by_Single = SingleAssign_1;
    // printf("%s\n", PointerAssign_by_Single);

    elem *PointerAssign_by_Group = "p1234";  // Illegal ��Ҫ�ó���ָ��const char*��ָ��char *��ʼ��
    printf("%s\n", PointerAssign_by_Group);  // δ������Ϊin ISO C++
    PointerAssign_by_Group = SingleAssign_1; // legal
    printf("%s\n", PointerAssign_by_Group);

    printf("sizeof:%d,strlen:%d,", sizeof(PointerAssign_by_Group), strlen(PointerAssign_by_Group)); // 64λָ��8�ֽ�*8bit/�ֽ� =  64λ
    printf("sizeof:%d,strlen:%d\n", sizeof(GroupAssign_2), strlen(GroupAssign_2));

    // δ������Ϊin ISO C++
    PointerAssign_by_Group = "5678"; // Illeagal ����ָ�벻�������޸�
    printf("undefined behavior:%s\n", PointerAssign_by_Group);

    const elem PointerAssign_3[10] = "1234";
    // GroupAssign_3[0] = '0';//ILLEAGAL    �������鲻������޸�
    printf("%s\n", PointerAssign_3);

    const elem *GroupAssign_4 = "1234"; // ����ָ��
    printf("%s\n", GroupAssign_4);
    GroupAssign_4 = "5678"; // Legal   ����ָ����������޸�
    printf("%s\n", GroupAssign_4);

    return 0;
}

```
# ������
```shell
sizeof:10,random strlen:0
s1234
sizeof:10,strlen:5
s1234
sizeof:6,strlen:5
s1234
s1234
5,5,5,5
p1234
s1234
sizeof:8,strlen:5,sizeof:6,strlen:5
undefined behavior:5678
1234
1234
5678
```