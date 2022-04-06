#include <iostream>
#include <list>
#include <array>
#include <vector>
#include "Matrix.h"
#include "IntContainer.h"
#include "IntRange.h"

using namespace std;

void makeListMean(list<double>& ld)
{
    double sum = 0;
    for (auto n : ld)
    {
        sum += n;
    }
    ld.push_back(sum / ld.size());
}

void task_1()
{
    list<double> l{ 1.1, 2.2, 3.3 };
    makeListMean(l);
    for (auto n : l)
    {
        cout << n << " ";
    }
    cout << endl;
    list<double>::iterator it = l.end();
    it--;
    cout << *it << endl;
}

void task_2()
{
    cout << "=====================================================" << endl;
    cout << "                   Task 2" << endl;

    vector<vector<int>> vec{ {{1, 0, 5}, { 3, 2, 0 }, { 4, 0, 6 }} };
    vector<vector<int>> vec4{ {
                                { 1, 1, 5, 7 }, 
                                { 0 , 2, 6, 3 }, 
                                { 0, 1, 0, 3 }, 
                                { 5, 4, 8, 1 }
                                } };
    vector<vector<int>> vec5{ {
                                { 1, 1, 5, 7, 1 },
                                { 0, 2, 6, 3, 2 },
                                { 0, 1, 0, 3, 3 },
                                { 5, 4, 8, 1, 4 },
                                { 2, 4, 7, 9, 1 }
                                } };

    cout << "Matrix:" << endl;
    Matrix m5(5, 5, vec5);
    cout << m5(1, 1) << endl;
    cout << m5 << endl;
    cout << "Det = " << m5.Determinant() << endl;



}

void task_3()
{
    IntContainer tempInt(3);
    tempInt[0] = 1;
    tempInt[1] = 3;
    tempInt[2] = 5;
    cout << tempInt << endl;

    for (auto c : tempInt)
    {
        cout << c << " ";
    }
    cout << endl;

    cout << "Range" << endl;
    IntRange ir(1, 10);
    for (auto i : ir)
    {
        cout << i << " ";
    }
    cout << endl;
}


int main()
{
    //task_1();
    //task_2();
    task_3();
}
