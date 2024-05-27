#include<bits/stdc++.h>
using namespace std;
double p_cal(double p, int n) {
    double temp = 1;
    for (int i = 1; i <= n; ++i) {
        if (i % 2 == 1)
            temp *= (p - i / 2);
        else
            temp *= (p + i / 2);
    }
    return temp;
}
int fact(int n) {
    int f = 1;
    for (int i = 2; i <= n; ++i) {
        f *= i;
    }
    return f;
}
double gfi(double value, const vector<double>& x, const vector<double>& y) {
    int n = x.size();
    vector<vector<double>> diff_table(n, vector<double>(n, 0));
    for (int i = 0; i < n; ++i) {
        diff_table[i][0] = y[i];
    }

    for (int j = 1; j < n; ++j) {
        for (int i = 0; i < n - j; ++i) {
            diff_table[i][j] = diff_table[i + 1][j - 1] - diff_table[i][j - 1];
        }
    }
    cout << "Difference Table:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << x[i] << "\t";
        for (int j = 0; j < n - i; ++j) {
            cout << diff_table[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;

    double sum = diff_table[0][0];
    double h = x[1] - x[0];
    double p = (value - x[0]) / h;

    for (int i = 1; i < n; ++i) {
        double u = p_cal(p, i);
        double delta_y = 0;
        for (int j = 0; j < i; ++j) {
            delta_y += (u * diff_table[0][j]) / fact(j + 1);
            u /= (j + 1);
        }
        sum += delta_y;
    }

    return sum;
}

int main() {
    vector<double> x = {1, 1.05, 1.10, 1.15, 1.20, 1.25, 1.30};
    vector<double> y = {2.7183, 2.8577, 3.0042, 3.1582, 3.3201, 3.4903, 3.6693};

    double value = 1.17;
    double interpolated_value = gfi(value, x, y);

    cout << "Interpolated value at " << value << " is " << fixed << setprecision(4) << interpolated_value << endl;

    return 0;
}
