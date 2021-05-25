/**
 * 问题：排列小球。
 * 
 * 来源：LeetCode 滴滴历届编程题真题。
 * https://leetcode-cn.com/leetbook/read/didiglobal2/e7hh2i/
 * 
 * 给定三种类型的小球 P、Q、R，每种小球的数量分别为 np、nq、nr 个。现在
 * 想将这些小球排成一条直线，但是不允许相同类型的小球相邻，问有多少种排列
 * 方法。如果无法组合出合适的结果，则输出 0。
 * 
 * 格式：
 *     输入：一行以空格相隔的三个数，分别表示为 np，nq，nr。
 *     输出：排列方法的数量。
 * 
 * 示例：
 *     输入：2 1 1
 *     输出：6
 *     解释：如若 np=2，nq=1，nr=1 则共有 6 种排列方式：PQRP，QPRP，PRQP，RPQP，PRPQ 以及 PQPR。
 */
#pragma once

#include <iostream>

#define T01Main_MAX 100

namespace T01Main
{
    // 结果记录，减少不必要的重复计算，否则会超时。
    long Result[T01Main_MAX][T01Main_MAX][T01Main_MAX];

    // 获取第一个小球类型已知的排列方式种类。
    long GetCountByNum(long nFirst, long nOther1, long nOther2)
    {
        // 保证大小顺序减少计算。
        if (nOther2 > nOther1)
            std::swap(nOther2, nOther1);

        // 没有记录则进行计算。
        if (Result[nFirst][nOther1][nOther2] < 0)
        {
            // 如果第一个小球数量为 0，则无法排列到第一位，排列结果为 0
            if (nFirst <= 0)
                return 0;

            // 如果第一个小球数量为 1，且其他小球都已经用完，则排列结果为 1
            if (nFirst == 1 && nOther1 == 0 && nOther2 == 0)
                return 1;

            // 其他情况下， 则第一个小球数量减一，其他两种选一个作为新的第一个继续计算。
            Result[nFirst][nOther1][nOther2] = GetCountByNum(nOther1, nFirst - 1, nOther2) + GetCountByNum(nOther2, nFirst - 1, nOther1);
        }

        return Result[nFirst][nOther1][nOther2];
    }

    void Test(long nP, long nQ, long nR)
    {
        memset(Result, -1, sizeof(Result));

        long nRetP = GetCountByNum(nP, nQ, nR);
        long nRetQ = GetCountByNum(nQ, nP, nR);
        long nRetR = GetCountByNum(nR, nP, nQ);

        std::cout << nRetP + nRetQ + nRetR << std::endl;
    }
};