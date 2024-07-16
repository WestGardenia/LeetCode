#define _CRT_SECURE_NO_WARNINGS

#include"Leetcode.h"

bool lemonadeChange(int* bills, int billsSize) {
    // 通过5元和10元对应的数量维护数组中的数据
    // 并以此进行判断
    int five = 0;
    int ten = 0;
    for (int i = 0; i < billsSize; i++)
    {
        if (bills[i] == 5)
        {
            five++;
        }
        else if (bills[i] == 10)
        {
            if (five > 0)
            {
                five--;
                ten++;
            }
            else
                return false;
        }
        else
        {
            if (five > 0 && ten > 0)
            {
                five--;
                ten--;
            }
            else if (five >= 3 && ten == 0)
            {
                five -= 3;
            }
            else
                return false;
        }
    }
    return true;
}