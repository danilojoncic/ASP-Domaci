#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

// vraca 1 ako je prvi broj veci, -1 ako je drugi
// vraca 0 ako su jednaki
int compare_array_num(string a, string b) {
    if (a.size() > b.size()) return 1;
    else if (b.size() > a.size()) return -1;

    int len = a.size();
    for (int i = 0; i < len; i++) {
        if (a[i] > b[i]) return 1;
        else if (a[i] < b[i]) return -1;
    }

    return 0;
}

void copy_array(string a, string b) {
    a = b;
}

string double_array(string a) {
    string result;

    int carry = 0;

    for (int i = a.size() - 1; i >= 0; i--) {
        int digit = a[i] - '0';
        result.insert(result.begin(), ((digit * 2 + carry) % 10) + '0');
        if (digit * 2 + carry > 9) carry = 1;
        else carry = 0;
    }

    if (carry == 1) result.insert(result.begin(), '1');

    return result;
}

string sum_two_arrays(string a, string b) {
    string result;

    int len = (a.size() > b.size()) ? b.size() : a.size();
    int carry = 0;

    for (int i = len - 1; i >= 0; i--) {
        int digit_a = a[i] - '0';
        int digit_b = b[i] - '0';
        result.insert(result.begin(), (digit_a + digit_b + carry) % 10 + '0');
        if (digit_a + digit_b + carry > 9) carry = 1;
        else carry = 0;
    }

    if (a.size() > len) {
        for (int i = a.size() - len - 1; i >= 0; i--) {
            result.insert(result.begin(), a[i]);
        }
    }

    if (b.size() > len) {
        for (int i = b.size() - len - 1; i >= 0; i--) {
            result.insert(result.begin(), b[i]);
        }
    }

    return result;
}

string divide_by_two_array(string number)
{
    string ans;
    int divisor = 2;

    int idx = 0;
    int temp = number[idx] - '0';
    while (temp < divisor)
        temp = temp * 10 + (number[++idx] - '0');

    while (number.size() > idx) {
        ans.push_back(temp / divisor + '0');

        temp = (temp % divisor) * 10 + (number[++idx] - '0');
    }
    if (ans.size() == 0)
        return "0";
    return ans;
}
string decrement(string a) {
    int last = a[a.size() - 1] - '0';

    // 140
    // 139
    // 099
    // 1
    int i = a.size() - 1;
    while(a[i] == '0') {
        a[i] = '9';
        i--;
    }
    a[i] -= 1;
    i = 0;
    while (a[i] == '0') {
        a.erase(a.begin());
    }
    return a;
}

string increment(string a) {
    // 99
    // 100
    // 909
    // 910
    int i = a.size() - 1;
    while(a[i] == '9') {
        a[i] = '0';
        i--;
    }
    a[i] += 1;
    return a;
}

int main() {
    string a = "999";
    string b = "1";

    cout << compare_array_num(a, b) << endl;
    cout << double_array(a) << endl;
    cout << sum_two_arrays(a, b) << endl;
    cout << divide_by_two_array(a) << endl;
    cout << decrement(a) << endl;
    cout << increment(a) << endl;

    return 0;
}