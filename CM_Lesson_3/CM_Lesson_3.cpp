#include <iostream>
#include <list>
#include <array>
#include <vector>
#include "Matrix.h"

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
    array<array<int, 3>, 3> arr{ {{1, 2, 3}, { 4,5,6 }, { 7,8,9 }} };
    cout << arr[0][1] << endl;
    for (size_t m = 0; m < 3; m++)
    {
        for (size_t n = 0; n < 3; n++)
            cout << arr[m][n] << " ";
        cout << endl;
    }

    vector<vector<int>> vec{ {{1, 2, 3}, { 4,5,6 }, { 7,8,9 }} };
    cout << vec[0][1] << endl;
    for (size_t m = 0; m < 3; m++)
    {
        for (size_t n = 0; n < 3; n++)
            cout << vec[m][n] << " ";
        cout << endl;
    }

    cout << vec.size() << " " << vec[0].size() << endl;

    cout << "Matrix:" << endl;
    Matrix m(3, 3, vec);
    cout << m(1, 1);
    //cout << m << endl;
    //vector<vector<int>> vec2;
    //vec2[0][0] = 1;
    //vector<int> vv;
    //vv.resize(3);
    //vv.reserve(2);
    //vv[0] = 1;
}


int main()
{
    task_1();
    task_2();
}
