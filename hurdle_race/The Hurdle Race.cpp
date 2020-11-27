#include <iostream>
using namespace std;


int main() {
    int n, k;
    int max = 0;

    cin >> n >> k;

    for(int i = 0; i < n; i++)
    {
        int a = 0;
        cin >> a;

        if(max < a)
        {
            max = a;
        }
    }

    if(max > k)
    {
        cout << max - k << endl;
    }
    else
    {
        cout << "0" << endl;
    }

    return 0;
}
