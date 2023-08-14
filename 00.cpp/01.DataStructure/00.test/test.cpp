#include <iostream>

using namespace std;

typedef struct {
    int num;
    int people;
} Customer;

int main()
{
    Customer a;
    a.num = 1;
    a.people = 2;
    cout <<sizeof(Customer) << endl;
    return 0;
}