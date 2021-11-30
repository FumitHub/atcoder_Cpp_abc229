#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<algorithm>

using namespace std;

int checkUp(string s1, string s2) {
    int l1, l2;
    l1 = s1.length();
    l2 = s2.length();
    int len = min(l1, l2);
    int n1, n2;
    char c1, c2;
    for ( int i = 1; i <= len; i++ ) {
        c1 = s1[l1 - i];
        c2 = s2[l2 - i];
        n1 = int(s1[l1 - i]-'0');
        n2 = int(s2[l2 - i]-'0');
        //cout << c1 << c2 << endl;
        if ( n1 + n2 > 9) return 1;
    }
    return 0;
}

int main() {
    long a, b;
    string str1, str2;
    cin >> a;
    cin >> b;
    str1 = to_string(a);
    str2 = to_string(b);
    if ( checkUp(str1, str2) ) cout << "Hard" << endl;
    else cout << "Easy" << endl;
    return 0;
}