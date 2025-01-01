#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    cout << "520 " << n << " Times!";
    return 0;
}
#include <iostream>
using namespace std;
int main()
{
    int L,num1,num2;
    cin >> L >> num1 >> num2;
    if (num1 - L >= 0 && num2 - L >= 0)
    {
        cout << "*^_^*";
    }
    else if (num1 >= L && num2 < L)
    {
        cout << "T_T";
    }
    else if (num1 < L && num2 >= L)
    {
        cout << "-_-#";
    }
    else if (num1 < L && num2 < L)
    {
        cout << "-_-";
    }
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int num;
    cin >> num;
    vector<int> love(num);
    for (int i = 0; i < num - 1; i++)
    {
        cin >> love[i];
        if (love[i] % 2)
        {
            cout << "Love!" << endl;
        }
        else
        {
            cout << "!Love" << endl;
        }
    }
    cin >> love[num - 1];
    if (love[num - 1] % 2)
    {
        cout << "Love!";
    }
    else
    {
        cout << "!Love";
    }
    return 0;
}
#include <iostream>
using namespace std;
int main()
{
    int zodvalid[12][10], zodvalidn[12], zodinvalid[12][10], zodinvalidn[12];
    int zodn;
    for (int i = 0; i < 12; i++) // initialize
    {
        cin >> zodn;
        cin >> zodvalidn[zodn];
        for (int j = 0; j < zodvalidn[zodn]; j++)
        {
            cin >> zodvalid[zodn][j];
        }
        cin >> zodinvalidn[zodn];
        for (int j = 0; j < zodinvalidn[zodn]; j++)
        {
            cin >> zodinvalid[zodn][j];
        }
    }
    int n, zod1, zod2, flagCP, flagNCP, flagNA;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        flagCP = flagNCP = flagNA = 0;
        cin >> zod1 >> zod2;
        for (int j = 0; j < zodvalidn[zod1]; j++)
        {
            if (zodvalid[zod1][j] == zod2)
            {
                flagCP = 1;
                break;
            }
        }
        if (flagCP)
        {
            cout << "Yes" << endl;
            continue;
        }
        else
        {
            for (int j = 0; j < zodinvalidn[zod1]; j++)
            {
                if (zodinvalid[zod1][j] == zod2)
                {
                    flagNCP = 1;
                    break;
                }
            }
            if (flagNCP)
            {
                cout << "No" << endl;
                continue;
            }
            else
            {
                for (int j = 0; j < zodvalidn[zod2]; j++)
                {
                    if (zodvalid[zod2][j] == zod1)
                    {
                        flagCP = 1;
                        break;
                    }
                }
                if (flagCP)
                {
                    cout << "Yes" << endl;
                    continue;
                }
                else
                {
                    for (int j = 0; j < zodinvalidn[zod2]; j++)
                    {
                        if (zodinvalid[zod2][j] == zod1)
                        {
                            flagNCP = 1;
                            break;
                        }
                    }
                    if (flagNCP)
                    {
                        cout << "No" << endl;
                        continue;
                    }
                }
            }
        }
        cout << "NA" << endl;
    }
    return 0;
}
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int main()
{
    char reva[10] = {'0', '1', '\0', '\0', '\0', '\0', '9', '\0', '8', '6'};
    int n;
    string reastr;
    char rea[20], tprea[20];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> reastr;
        strcpy(rea, reastr.c_str());
        // for (int j = 0; j < strlen(rea) / 2; j++)
        // {
        //     rea[strlen(rea) - 1 - j] = rea[j];
        // }
        // strcpy(rea, strrev(rea));
        int j;
        for (j = 0; j < strlen(rea); j++)
        {
            if (reva[rea[j] - '0'])
                rea[j] = reva[rea[j] - '0'];
            else
            {
                cout << "bu ke neng" << endl;
                break;
            }
        }
        if (j == strlen(rea))
        {
            if (strcmp(rea, reastr.c_str()))
            {
                printf("%s\n", rea);
            }
            else
            {
                cout << "bu ke neng" << endl;
            }
        }
    }
    return 0;
}
#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
int main()
{
    int c, count = 0;
    string num, tpnum;
    char cnum[10], anum[10], bnum[10];
    cin >> c;
    for (int i = 0, na = 0, nb = 0; i < c; i++)
    {
        cin >> num;
        tpnum = num;
        if (num[0] != '-')
        {
            if (num.size() % 2 == 0)
            {
                int halflen = strlen(cnum);
                strcpy(cnum, num.c_str());
                strcpy(bnum, cnum + halflen / 2);
                cnum[halflen / 2] = '\0';
                strcpy(anum, cnum + halflen / 2);
                for (int j = 0; j < halflen - 1; j++)
                {
                    if (!(anum[j] >= anum[j + 1]))
                    {
                        na = 1;
                        break;
                    }
                }
                for (int j = 0; j < halflen - 1; j++)
                {
                    if (!(bnum[j] <= bnum[j + 1]))
                    {
                        nb = 1;
                        break;
                    }
                }
                if (!na && !nb)
                {
                    count++;
                    if (tpnum > num)
                    {
                        tpnum = num;
                    }
                    tpnum = num;
                }
                        }
        }
    }
    cout << count << endl;
    cout << tpnum;
    return 0;
}