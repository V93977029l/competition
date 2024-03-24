#include <iostream>
#include <string>
using namespace std;

string cString;

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    cin >> cString;

    for (int i = 0; i < 7; i++)
    {
        if (cString[i] >= 'A' && cString[i] <= 'Z')
        {
            cString[i] += 32;
        }
    }
    
    if (cString == "lanqiao")
    {
        cout << "yes";
    }
    else
    {
        cout << "no";
    }
    
    return 0;
}