#include <iostream>
#include <list>

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

int main()
{
    task_1();
}
