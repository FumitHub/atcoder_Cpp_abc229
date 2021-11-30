#include<iostream>
using namespace std;

int main() {
    string s1;
    string s2;
    cin >> s1;
    cin >> s2;
    if ( ( ( s1[0] == '.') && ( s2[1] == '.' ) ) || ( ( s1[1] == '.') && ( s2[0] == '.' ) ) ) cout << "No" << endl;
    else cout << "Yes" << endl;
}