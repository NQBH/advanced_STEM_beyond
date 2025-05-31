//158
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <string>
using namespace std;

double evaluatePolynomial(const vector<double>& coeffs, double x) {
    double result = 0;
    for (int i = 0; i < coeffs.size(); i++) {
        result += coeffs[i] * pow(x, i);
    }
    return result;
}

vector<double> derivative(const vector<double>& coeffs) {
    vector<double> result;
    if (coeffs.size() <= 1) return result;
    
    for (int i = 1; i < coeffs.size(); i++) {
        result.push_back(coeffs[i] * i);
    }
    return result;
}

void removeLeadingZeros(vector<double>& coeffs) {
    while (!coeffs.empty() && fabs(coeffs.back()) < 1e-10) {
        coeffs.pop_back();
    }
}

double limitAtFinite(vector<double> P, vector<double> Q, double x0) {
    removeLeadingZeros(P);
    removeLeadingZeros(Q);
    
    if (P.empty()) return 0;
    if (Q.empty()) return INFINITY;
    
    double num = evaluatePolynomial(P, x0);
    double den = evaluatePolynomial(Q, x0);
    
    if (fabs(den) > 1e-10) {
        return num / den;
    }
    
    if (fabs(num) < 1e-10) {
        vector<double> numDer = derivative(P);
        vector<double> denDer = derivative(Q);
        
        if (numDer.empty() && denDer.empty()) {
            return 0;
        }
        
        return limitAtFinite(numDer, denDer, x0);
    }
    
    return (num > 0) ? INFINITY : -INFINITY;
}

double limitAtInfinity(vector<double> P, vector<double> Q, bool isPositiveInfinity) {
    removeLeadingZeros(P);
    removeLeadingZeros(Q);
    
    if (P.empty()) return 0;
    if (Q.empty()) return INFINITY;  
    
    int degP = P.size() - 1;
    int degQ = Q.size() - 1;
    
    if (degP < degQ) {
        return 0;
    }
    else if (degP > degQ) {
        double sign = P[degP] * Q[degQ];
        if (isPositiveInfinity) {
            return (sign > 0) ? INFINITY : -INFINITY;
        } else {
            return ((degP - degQ) % 2 == 1) ? ((sign > 0) ? -INFINITY : INFINITY) : ((sign > 0) ? INFINITY : -INFINITY);
        }
    }
    else {
        return P[degP] / Q[degQ];
    }
}

int main() {
    string x0_str;
    int m, n;
    
    cin >> x0_str >> m >> n;

    vector<double> P(m + 1), Q(n + 1);
    
    for (int i = 0; i <= m; i++) {
        cin >> P[i];
    }
    
    for (int i = 0; i <= n; i++) {
        cin >> Q[i];
    }
    
    double result;
    if (x0_str == "inf" || x0_str == "+inf" || x0_str == "Infinity") {
        result = limitAtInfinity(P, Q, true);
    }
    else if (x0_str == "-inf" || x0_str == "-Infinity") {
        result = limitAtInfinity(P, Q, false);
    }
    else {
        double x0 = stod(x0_str);
        result = limitAtFinite(P, Q, x0);
    }
    
    if (isinf(result)) {
        if (result > 0) {
            cout << "Infinity" << endl;
        } else {
            cout << "-Infinity" << endl;
        }
    } else {
        cout << fixed << setprecision(6) << result << endl;
    }
    
    return 0;
}