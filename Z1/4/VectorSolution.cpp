#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

// vraca 1 ako je prvi broj veci, -1 ako je drugi
// vraca 0 ako su jednaki
int compare_array_num(vector<int> a, vector<int> b) {
    if (a.size() > b.size()) return 1;
    else if (b.size() > a.size()) return -1;

    int len = a.size();
    for (int i = 0; i < len; i++) {
        if (a[i] > b[i]) return 1;
        else if (a[i] < b[i]) return -1;
    }

    return 0;
}

void copy_array(vector<int> a, vector<int> b) {
    while(!a.empty()) {
        a.pop_back();
    }

    for (int i = 0; i < b.size(); i++) {
        a.push_back(b[i]);
    }
}

vector<int> double_array(vector<int> a) {
    vector<int> result;

    int carry = 0;

    for (int i = a.size() - 1; i >= 0; i--) {
        result.insert(result.begin(), (a[i] * 2 + carry) % 10);
        if (a[i] * 2 + carry > 9) carry = 1;
        else carry = 0;
    }

    if (carry == 1) result.insert(result.begin(), 1);

    return result;
}

vector<int> sum_two_arrays(vector<int> a, vector<int> b) {
    vector<int> result;

    int len = (a.size() > b.size()) ? b.size() : a.size();
    int carry = 0;

    for (int i = len - 1; i >= 0; i--) {
        result.insert(result.begin(), (a[i] + b[i] + carry) % 10);
        if (a[i] + b[i] + carry > 9) carry = 1;
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

vector<int> divide_by_two_array(vector<int> number)
{
    vector<int> ans;
    int divisor = 2;

    int idx = 0;
    int temp = number[idx];
    while (temp < divisor)
        temp = temp * 10 + (number[++idx]);

    while (number.size() > idx) {
        ans.push_back(temp / divisor);

        temp = (temp % divisor) * 10 + number[++idx];
    }
    if (ans.size() == 0)
        return {0};
    return ans;
}

vector<int> decrement(vector<int> a) {
    int last = a[a.size() - 1];

    // 140
    // 139
    // 099
    // 1
    int i = a.size() - 1;
    while(a[i] == 0) {
        a[i] = 9;
        i--;
    }
    a[i] -= 1;
    i = 0;
    while (a[i] == 0) {
        a.erase(a.begin());
    }
    return a;
}

vector<int> increment(vector<int> a) {
    // 99
    // 100
    // 909
    // 910
    int i = a.size() - 1;
    while(a[i] == 9) {
        a[i] = 0;
        i--;
    }

    if (i == -1) {
        a.insert(a.begin(), 1);
    }
    else {
        a[i] += 1;
    }

    return a;

}

vector<int> binarna(vector<int> x, vector<int> y)
{
    vector<int> mid;
    int res;
    while (compare_array_num(x, y) != 1)
    {
        mid = divide_by_two_array(sum_two_arrays(x, y));


        cout << "? ";
        for (int i = 0; i < mid.size(); i++) {
            cout<<mid[i];
        }
        cout<<endl;

        cin>>res;

        if (res == 1) {
            y = decrement(mid);
        }
        else {
            x = increment(mid);
        }

    }

    return mid;
}

void ask(vector<int> a) {
    cout<<"? ";
    for (int i = 0; i < a.size()-1; i++) {
        cout<<a[i];
    }
    cout<<endl;
}

int main()
{
    vector<int> x, prev, final_result;
    x.push_back(1);
    prev.push_back(1);
    int res = 0;

    while (1)
    {
        ask(x);
        cin >> res;
        if (res == 1)
        {
            final_result = binarna(prev, x);
            break;
        } else {
            copy_array(prev, x);
            x = double_array(x);
        }
    }
    cout << "! ";
    for (int i = 0; i < final_result.size(); i++) {
        cout<<final_result[i];
    }
    cout<<endl;
    return 0;
}
