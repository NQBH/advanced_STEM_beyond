#include <bits/stdc++.h>
#include "fraction.h"
using namespace std;

#define int long long

/* ================================================================================== */
/* Save the result of (f(bx))^a (b := beta, a:= alpha) into std::stringstream */
/* ================================================================================== */

void output_sin(std::stringstream& buffer, std::stringstream& maple_buffer, vector<Fraction> cluster_result, int alpha, int beta) {
    int n = cluster_result.size() - 2;

    for(int j = n; j >= 0; --j) {
        if(cluster_result[j] > Fraction(0, 1)) {
            buffer << "+" << cluster_result[j] << "*(sin(" << beta << "*x))^" << j << "*cos(" << beta << "*x) ";
            maple_buffer << "+" << cluster_result[j] << "*(sin(" << beta << "*x))^" << j << "*cos(" << beta << "*x) ";
        } 
        else if(cluster_result[j] < Fraction(0, 1)) {
            buffer << cluster_result[j] << "*(sin(" << beta << "*x))^" << j << "*cos(" << beta <<"*x) ";
            maple_buffer << cluster_result[j] << "*(sin(" << beta << "*x))^" << j << "*cos(" << beta <<"*x) ";
        }
        else continue;
    }

    if(cluster_result[n+1] > Fraction(0, 1)) {
        buffer << "+" << cluster_result[n+1] << "*x ";
        maple_buffer << "+" << cluster_result[n+1] << "*x ";
    }
    else if(cluster_result[n+1] < Fraction(0, 1)) {
        buffer << cluster_result[n+1] << "*x ";
        maple_buffer << cluster_result[n+1] << "*x ";
    }
}

void output_cos(std::stringstream& buffer, std::stringstream& maple_buffer, vector<Fraction> cluster_result, int alpha, int beta) {
    int n = cluster_result.size() - 2;

    for(int j = n; j >= 0; --j) {
        if(cluster_result[j] > Fraction(0, 1)) {
            buffer << "+" << cluster_result[j] << "*(cos(" << beta << "*x))^" << j << "*sin(" << beta << "*x) ";
            maple_buffer << "+" << cluster_result[j] << "*(cos(" << beta << "*x))^" << j << "*sin(" << beta << "*x) ";
        } 
        else if(cluster_result[j] < Fraction(0, 1)) {
            buffer << cluster_result[j] << "*(cos(" << beta << "*x))^" << j << "*sin(" << beta <<"*x) ";
            maple_buffer << cluster_result[j] << "*(cos(" << beta << "*x))^" << j << "*sin(" << beta <<"*x) ";
        }
        else continue;
    }

    if(cluster_result[n+1] > Fraction(0, 1)) {
        buffer << "+" << cluster_result[n+1] << "*x ";
        maple_buffer << "+" << cluster_result[n+1] << "*x ";
    }
    else if(cluster_result[n+1] < Fraction(0, 1)) {
        buffer << cluster_result[n+1] << "*x ";
        maple_buffer << cluster_result[n+1] << "*x ";
    }
}

void output_tan(std::stringstream& buffer, std::stringstream& maple_buffer, vector<Fraction> cluster_result, int alpha, int beta) {
    int n = cluster_result.size() - 2;

    for(int j = n; j >= 1; --j) {
        if(cluster_result[j] > Fraction(0, 1)) {
            buffer << "+" << cluster_result[j] << "*(tan(" << beta << "*x))^" << j << " ";
            maple_buffer << "+" << cluster_result[j] << "*(tan(" << beta << "*x))^" << j << " ";
        } 
        else if(cluster_result[j] < Fraction(0, 1)) {
            buffer << cluster_result[j] << "*(tan(" << beta << "*x))^" << j << " ";
            maple_buffer << cluster_result[j] << "*(tan(" << beta << "*x))^" << j << " ";
        }
        else continue;
    }

    if(cluster_result[0] > Fraction(0, 1)) {
        buffer << "+" << cluster_result[0] << "*ln(abs(cos(" << beta << "*x))) ";
        maple_buffer << "+" << cluster_result[0] << "*ln(abs(cos(" << beta << "*x))) ";
    }
    else if(cluster_result[0] < Fraction(0, 1)) {
        buffer << cluster_result[0] << "*ln(abs(cos(" << beta << "*x))) ";
        maple_buffer << cluster_result[0] << "*ln(abs(cos(" << beta << "*x))) ";
    }

    if(cluster_result[n+1] > Fraction(0, 1)) {
        buffer << "+" << cluster_result[n+1] << "*x ";
        maple_buffer << "+" << cluster_result[n+1] << "*x ";
    }
    else if(cluster_result[n+1] < Fraction(0, 1)) {
        buffer << cluster_result[n+1] << "*x ";
        maple_buffer << cluster_result[n+1] << "*x ";
    }
}

void output_cot(std::stringstream& buffer, std::stringstream& maple_buffer, vector<Fraction> cluster_result, int alpha, int beta) {
    int n = cluster_result.size() - 2;

    for(int j = n; j >= 1; --j) {
        if(cluster_result[j] > Fraction(0, 1)) {
            buffer << "+" << cluster_result[j] << "*(cot(" << beta << "x))^" << j << " ";
            maple_buffer << "+" << cluster_result[j] << "*(cot(" << beta << "x))^" << j << " ";
        } 
        else if(cluster_result[j] < Fraction(0, 1)) {
            buffer << cluster_result[j] << "*(cot(" << beta << "x))^" << j << " ";
            maple_buffer << cluster_result[j] << "*(cot(" << beta << "x))^" << j << " ";
        }
        else continue;
    }

    if(cluster_result[0] > Fraction(0, 1)) {
        buffer << "+" << cluster_result[0] << "*ln(abs(sin(" << beta << "x))) ";
        maple_buffer << "+" << cluster_result[0] << "*ln(abs(sin(" << beta << "x))) ";
    }
    else if(cluster_result[0] < Fraction(0, 1)) {
        buffer << cluster_result[0] << "*ln(abs(sin(" << beta << "x))) ";
        maple_buffer << cluster_result[0] << "*ln(abs(sin(" << beta << "x))) ";
    }

    if(cluster_result[n+1] > Fraction(0, 1)) {
        buffer << "+" << cluster_result[n+1] << "*x ";
        maple_buffer << "+" << cluster_result[n+1] << "*x ";
    }
    else if(cluster_result[n+1] < Fraction(0, 1)) {
        buffer << cluster_result[n+1] << "*x ";
        maple_buffer << cluster_result[n+1] << "*x ";
    }
}

void output_sec(std::stringstream& buffer, std::stringstream& maple_buffer, vector<Fraction> cluster_result, int alpha, int beta) {
    int n = cluster_result.size() - 2;

    for(int j = n; j >= 1; --j) {
        if(cluster_result[j] > Fraction(0, 1)) {
            buffer << "+" << cluster_result[j] << "*(sec(" << beta << "x))^" << j << "*sin(" << beta << "x) ";
            maple_buffer << "+" << cluster_result[j] << "*(sec(" << beta << "x))^" << j << "*sin(" << beta << "x) ";
        } 
        else if(cluster_result[j] < Fraction(0, 1)) {
            buffer << cluster_result[j] << "*(sec(" << beta << "x))^" << j << "*sin(" << beta <<"x) ";
            maple_buffer << cluster_result[j] << "*(sec(" << beta << "x))^" << j << "*sin(" << beta <<"x) ";
        }
        else continue;
    }

    if(cluster_result[0] > Fraction(0, 1)) {
        buffer << "+" << cluster_result[0] << "*ln(abs((1+sin(" << beta << "x))/(1-sin(" << beta << "x)))) ";
        maple_buffer << "+" << cluster_result[0] << "*ln(abs((1+sin(" << beta << "x))/(1-sin(" << beta << "x)))) ";
    }
    else if(cluster_result[0] < Fraction(0, 1)) {
        buffer << cluster_result[0] << "*ln(abs((1+sin(" << beta << "x))/(1-sin(" << beta << "x)))) ";
        maple_buffer << cluster_result[0] << "*ln(abs((1+sin(" << beta << "x))/(1-sin(" << beta << "x)))) ";
    }

    if(cluster_result[n+1] > Fraction(0, 1)) {
        buffer << "+" << cluster_result[n+1] << "*x ";
        maple_buffer << "+" << cluster_result[n+1] << "*x ";
    }
    else if(cluster_result[n+1] < Fraction(0, 1)) {
        buffer << cluster_result[n+1] << "*x ";
        maple_buffer << cluster_result[n+1] << "*x ";
    }
}

void output_csc(std::stringstream& buffer, std::stringstream& maple_buffer, vector<Fraction> cluster_result, int alpha, int beta) {
    int n = cluster_result.size() - 2;

    for(int j = n; j >= 1; --j) {
        if(cluster_result[j] > Fraction(0, 1)) {
            buffer << "+" << cluster_result[j] << "*(csc(" << beta << "x))^" << j << "*cos(" << beta << "x) ";
            maple_buffer << "+" << cluster_result[j] << "*(csc(" << beta << "x))^" << j << "*cos(" << beta << "x) ";
        } 
        else if(cluster_result[j] < Fraction(0, 1)) {
            buffer << cluster_result[j] << "*(csc(" << beta << "x))^" << j << "*cos(" << beta <<"x) ";
            maple_buffer << cluster_result[j] << "*(csc(" << beta << "x))^" << j << "*cos(" << beta <<"x) ";
        }
        else continue;
    }

    if(cluster_result[0] > Fraction(0, 1)) {
        buffer << "+" << cluster_result[0] << "*ln(abs((1-cos(" << beta << "x))/(1+cos(" << beta << "x)))) ";
        maple_buffer << "+" << cluster_result[0] << "*ln(abs((1-cos(" << beta << "x))/(1+cos(" << beta << "x)))) ";
    }
    else if(cluster_result[0] < Fraction(0, 1)) {
        buffer << cluster_result[0] << "*ln(abs((1-cos(" << beta << "x))/(1+cos(" << beta << "x)))) ";
        maple_buffer << cluster_result[0] << "*ln(abs((1-cos(" << beta << "x))/(1+cos(" << beta << "x)))) ";
    }

    if(cluster_result[n+1] > Fraction(0, 1)) {
        buffer << "+" << cluster_result[n+1] << "*x ";
        maple_buffer << "+" << cluster_result[n+1] << "*x ";
    }
    else if(cluster_result[n+1] < Fraction(0, 1)) {
        buffer << cluster_result[n+1] << "*x ";
        maple_buffer << cluster_result[n+1] << "*x ";
    }  
}

void output_arcsin(std::stringstream& buffer, std::stringstream& maple_buffer, vector<Fraction> cluster_result, int alpha, int beta) {
    int n = cluster_result.size() - 2;

    for(int j = n; j >= 0; --j) {
        if((alpha - j) % 2 == 0) {
            if(cluster_result[j] > Fraction(0, 1)) {
                buffer << "+" << cluster_result[j] << "*x*(arcsin(" << beta << "x))^" << j << " ";
                maple_buffer << "+" << cluster_result[j] << "*x*(arcsin(" << beta << "x))^" << j << " ";
            } 
            else if(cluster_result[j] < Fraction(0, 1)) {
                buffer << cluster_result[j] << "*x*(arcsin(" << beta << "x))^" << j << " ";
                maple_buffer << cluster_result[j] << "*x*(arcsin(" << beta << "x))^" << j << " ";
            }
            else continue;
        }
        else {
            if(cluster_result[j] > Fraction(0, 1)) {
                buffer << "+" << cluster_result[j] << "*sqrt(1-(" << beta << ")^2*x^2)*(arcsin(" << beta << "x))^" << j << " ";
                maple_buffer << "+" << cluster_result[j] << "*sqrt(1-(" << beta << ")^2*x^2)*(arcsin(" << beta << "x))^" << j << " ";
            } 
            else if(cluster_result[j] < Fraction(0, 1)) {
                buffer << cluster_result[j] << "*sqrt(1-(" << beta << ")^2*x^2)*(arcsin(" << beta << "x))^" << j << " ";
                maple_buffer << cluster_result[j] << "*sqrt(1-(" << beta << ")^2*x^2)*(arcsin(" << beta << "x))^" << j << " ";
            } 
            else continue;
        }
    }
}

void output_arccos(std::stringstream& buffer, std::stringstream& maple_buffer, vector<Fraction> cluster_result, int alpha, int beta) {
    int n = cluster_result.size() - 2;

    for(int j = n; j >= 0; --j) {
        if((alpha - j) % 2 == 0) {
            if(cluster_result[j] > Fraction(0, 1)) {
                buffer << "+" << cluster_result[j] << "*x*(arccos(" << beta << "x))^" << j << " ";
                maple_buffer << "+" << cluster_result[j] << "*x*(arccos(" << beta << "x))^" << j << " ";
            } 
            else if(cluster_result[j] < Fraction(0, 1)) {
                buffer << cluster_result[j] << "*x*(arccos(" << beta << "x))^" << j << " ";
                maple_buffer << cluster_result[j] << "*x*(arccos(" << beta << "x))^" << j << " ";
            }
            else continue;
        }
        else {
            if(cluster_result[j] > Fraction(0, 1)) {
                buffer << "+" << cluster_result[j] << "*sqrt(1-(" << beta << ")^2*x^2)*(arccos(" << beta << "x))^" << j << " ";
                maple_buffer << "+" << cluster_result[j] << "*sqrt(1-(" << beta << ")^2*x^2)*(arccos(" << beta << "x))^" << j << " ";
            } 
            else if(cluster_result[j] < Fraction(0, 1)) {
                buffer << cluster_result[j] << "*sqrt(1-(" << beta << ")^2*x^2)*(arccos(" << beta << "x))^" << j << " ";
                maple_buffer << cluster_result[j] << "*sqrt(1-(" << beta << ")^2*x^2)*(arccos(" << beta << "x))^" << j << " ";
            } 
            else continue;
        }
    }
}

void output_arctan(std::stringstream& buffer, std::stringstream& maple_buffer, vector<Fraction> cluster_result, int alpha, int beta) {
    if(cluster_result[0] > Fraction(0, 1)) {
        buffer << "+" << cluster_result[0] << "*x*arctan(" << beta << "*x)^" << alpha << " ";
        maple_buffer << "+diff(+" << cluster_result[0] << "*x*arctan(" << beta << "*x)^" << alpha << ",x) ";
    }
    else if(cluster_result[0] < Fraction(0, 1)) {
        buffer << cluster_result[0] << "*x*arctan(" << beta << "*x)^" << alpha << " ";
        maple_buffer << "+diff(" << cluster_result[0] << "*x*arctan(" << beta << "*x)^" << alpha << ",x) ";
    }

    if(alpha != 0) {
        buffer << "-((" << cluster_result[1] << ")*";
        maple_buffer << "-((" << cluster_result[1] << ")*";
        if(alpha == 1) {
            buffer << "(ln(1+(" << beta << ")^2*x^2))) ";
            maple_buffer << "diff((ln(1+(" << beta << ")^2*x^2)),x)) ";
        }
        else if(alpha >= 2) {
            buffer << "(int((arctan(" << beta << "*x)^" << alpha-1 << ")*(d/dx(ln(1+(" << beta << ")^2*x^2)))dx))) ";
            maple_buffer << "((arctan(" << beta << "*x)^" << alpha-1 << ")*(diff(ln(1+(" << beta << ")^2*x^2),x)))) ";
        }
    }
}

void output_arccot(std::stringstream& buffer, std::stringstream& maple_buffer, vector<Fraction> cluster_result, int alpha, int beta) {
    if(cluster_result[0] > Fraction(0, 1)) {
        buffer << "+" << cluster_result[0] << "*x*arccot(" << beta << "*x)^" << alpha << " ";
        maple_buffer << "+diff(+" << cluster_result[0] << "*x*arccot(" << beta << "*x)^" << alpha << ",x) ";
    }
    else if(cluster_result[0] < Fraction(0, 1)) {
        buffer << cluster_result[0] << "*x*arccot(" << beta << "*x)^" << alpha << " ";
        maple_buffer << "+diff(" << cluster_result[0] << "*x*arccot(" << beta << "*x)^" << alpha << ",x) ";
    }

    if(alpha != 0) {
        buffer << "+((" << cluster_result[1] << ")*";
        maple_buffer << "+((" << cluster_result[1] << ")*";
        if(alpha == 1) {
            buffer << "(ln(1+(" << beta << ")^2*x^2))) ";
            maple_buffer << "diff((ln(1+(" << beta << ")^2*x^2)),x)) ";
        }
        else if(alpha >= 2) {
            buffer << "(int((arccot(" << beta << "*x)^" << alpha-1 << ")*(d/dx(ln(1+(" << beta << ")^2*x^2)))dx))) ";
            maple_buffer << "((arccot(" << beta << "*x)^" << alpha-1 << ")*(diff(ln(1+(" << beta << ")^2*x^2),x)))) ";
        }
    }
}

void output_arcsec(std::stringstream& buffer, std::stringstream& maple_buffer, vector<Fraction> cluster_result, int alpha, int beta) {
    if(cluster_result[0] > Fraction(0, 1)) {
        buffer << "+" << cluster_result[0] << "*x*arcsec(" << beta << "*x)^" << alpha << " ";
        maple_buffer << "+diff(+" << cluster_result[0] << "*x*arcsec(" << beta << "*x)^" << alpha << ",x) ";
    }
    else if(cluster_result[0] < Fraction(0, 1)) {
        buffer << cluster_result[0] << "*x*arcsec(" << beta << "*x)^" << alpha << " ";
        maple_buffer << "+diff(" << cluster_result[0] << "*x*arcsec(" << beta << "*x)^" << alpha << ",x) ";
    }

    if(alpha != 0) {
        buffer << "-(" << cluster_result[1] << "*";
        maple_buffer << "-(" << cluster_result[1] << "*";
        if(alpha == 1) {
            buffer << "(ln(abs(" << beta << "x)+sqrt((" << beta << ")^2*x^2-1))) ";
            maple_buffer << "diff((ln(abs(" << beta << "x)+sqrt((" << beta << ")^2*x^2-1))),x)) ";
        }
        else if(alpha >= 2) {
            buffer << "(int((arcsec(" << beta << "*x)^" << alpha-1 << ")/(sqrt((" << beta << ")^2*x^2-1))*(d/dx(abs(" << beta << "*x)))dx))) ";
            maple_buffer << "((arcsec(" << beta << "*x)^" << alpha-1 << ")/(sqrt((" << beta << ")^2*x^2-1))*(diff(abs(" << beta << "*x),x)))) ";
        }
    }
}

void output_arccsc(std::stringstream& buffer, std::stringstream& maple_buffer, vector<Fraction> cluster_result, int alpha, int beta) {
    if(cluster_result[0] > Fraction(0, 1)) {
        buffer << "+" << cluster_result[0] << "*x*arccsc(" << beta << "*x)^" << alpha << " ";
        maple_buffer << "+diff(+" << cluster_result[0] << "*x*arccsc(" << beta << "*x)^" << alpha << ",x) ";
    }
    else if(cluster_result[0] < Fraction(0, 1)) {
        buffer << cluster_result[0] << "*x*arccsc(" << beta << "*x)^" << alpha << " ";
        maple_buffer << "+diff(" << cluster_result[0] << "*x*arccsc(" << beta << "*x)^" << alpha << ",x) ";
    }

    if(alpha != 0) {
        buffer << "+(" << cluster_result[1] << "*";
        maple_buffer << "+(" << cluster_result[1] << "*";
        if(alpha == 1) {
            buffer << "(ln(abs(" << beta << "x)+sqrt((" << beta << ")^2*x^2-1))) ";
            maple_buffer << "diff((ln(abs(" << beta << "x)+sqrt((" << beta << ")^2*x^2-1))),x)) ";
        }
        else if(alpha >= 2) {
            buffer << "(int((arccsc(" << beta << "*x)^" << alpha-1 << ")/(sqrt((" << beta << ")^2*x^2-1))*(d/dx(abs(" << beta << "*x)))dx))) ";
            maple_buffer << "((arccsc(" << beta << "*x)^" << alpha-1 << ")/(sqrt((" << beta << ")^2*x^2-1))*(diff(abs(" << beta << "*x),x)))) ";
        }
    }
}



/* ================================================================================== */
/* Calculate (f(bx))^n (b := beta) */
/* ================================================================================== */

vector<vector<Fraction>> solve_sin(int n, int beta = 1) {
    vector<vector<Fraction>> coeff(n+1, vector<Fraction>(n+2));
    
    // primitive at power i
    // coeff[i][j] := coeff(sin^jcos)
    // coeff[i][n+1] := coeff(x)
    coeff[0][n+1] = Fraction(1, 1);
    coeff[1][0] = Fraction(-1, beta);
    for(int i = 2; i <= n; ++i) {
        coeff[i][i-1] = Fraction(-1, beta * i);
        // temp_coeff := coeff(\int at power i-2)
        Fraction temp_coeff = Fraction(i - 1, i);
        coeff[i][n+1] = temp_coeff * coeff[i-2][n+1];
        for(int j = i-2; j >= 0; --j) {
            if (coeff[i-2][j].numerator != 0 && temp_coeff.numerator != 0) {
                coeff[i][j] = temp_coeff * coeff[i-2][j];
            }
        }
    }

    std::stringstream buffer, maple_buffer;
    for(int i = 0; i <= n; ++i) {
        output_sin(buffer, maple_buffer, coeff[i], i, beta);
        buffer << '\n';
    }

    return coeff;
}

vector<vector<Fraction>> solve_cos(int n, int beta = 1) {
    vector<vector<Fraction>> coeff(n+1, vector<Fraction>(n+2));
    
    // primitive at power i
    // coeff[i][j] := coeff(cos^jsin)
    // coeff[i][n+1] := coeff(x)
    coeff[0][n+1] = Fraction(1, 1);
    coeff[1][0] = Fraction(1, beta);
    for(int i = 2; i <= n; ++i) {
        coeff[i][i-1] = Fraction(1, beta * i);
        // temp_coeff := coeff(\int at power i-2)
        Fraction temp_coeff = Fraction(i - 1, i);
        coeff[i][n+1] = temp_coeff * coeff[i-2][n+1];
        for(int j = i-2; j >= 0; --j) {
            if (coeff[i-2][j].numerator != 0 && temp_coeff.numerator != 0) {
                coeff[i][j] = temp_coeff * coeff[i-2][j];
            }
        }
    }

    std::stringstream buffer, maple_buffer;
    for(int i = 0; i <= n; ++i) {
        output_cos(buffer, maple_buffer, coeff[i], i, beta);
        buffer << '\n';
    }
    
    return coeff;
}

vector<vector<Fraction>> solve_tan(int n, int beta = 1) {
    vector<vector<Fraction>> coeff(n+1, vector<Fraction>(n+2));
    
    // primitive at power i
    // coeff[i][0] := coeff(ln|cos|)
    // coeff[i][j] := coeff(tan^j) 
    // coeff[i][n+1] := coeff(x)
    coeff[0][n+1] = Fraction(1, 1);
    coeff[1][0] = Fraction(-1, beta);
    for(int i = 2; i <= n; ++i) {
        coeff[i][i-1] = Fraction(1, beta * (i-1));
        // temp_coeff := coeff(\int at power i-2)
        Fraction temp_coeff = Fraction(-1, 1);
        coeff[i][n+1] = temp_coeff * coeff[i-2][n+1];
        for(int j = i-2; j >= 0; --j) {
            if (coeff[i-2][j].numerator != 0 && temp_coeff.numerator != 0) {
                coeff[i][j] = temp_coeff * coeff[i-2][j];
            }
        }
    }
    
    std::stringstream buffer, maple_buffer;
    for(int i = 0; i <= n; ++i) {
        output_tan(buffer, maple_buffer, coeff[i], i, beta);
        buffer << '\n';
    }

    return coeff;
}

vector<vector<Fraction>> solve_cot(int n, int beta = 1) {
    vector<vector<Fraction>> coeff(n+1, vector<Fraction>(n+2));
    
    // primitive at power i
    // coeff[i][0] := coeff(ln|sin|)
    // coeff[i][j] := coeff(cot^j)
    // coeff[i][n+1] := coeff(x)
    coeff[0][n+1] = Fraction(1, 1);
    coeff[1][0] = Fraction(1, beta);
    for(int i = 2; i <= n; ++i) {
        coeff[i][i-1] = Fraction(-1, beta * (i-1));
        // temp_coeff := coeff(\int at power i-2)
        Fraction temp_coeff = Fraction(-1, 1);
        coeff[i][n+1] = temp_coeff * coeff[i-2][n+1];
        for(int j = i-2; j >= 0; --j) {
            if (coeff[i-2][j].numerator != 0 && temp_coeff.numerator != 0) {
                coeff[i][j] = temp_coeff * coeff[i-2][j];
            }
        }
    }

    std::stringstream buffer, maple_buffer;
    for(int i = 0; i <= n; ++i) {
        output_cot(buffer, maple_buffer, coeff[i], i, beta);
        buffer << '\n';
    }

    return coeff;
}

vector<vector<Fraction>> solve_sec(int n, int beta = 1) {
    vector<vector<Fraction>> coeff(n+1, vector<Fraction>(n+2));
    
    // primitive at power i
    // coeff[i][0] := coeff(ln|(1+sin)/(1-sin)|)
    // coeff[i][j] := coeff(sec^jsin)
    // coeff[i][n+1] := coeff(x)
    coeff[0][n+1] = Fraction(1, 1);
    coeff[1][0] = Fraction(1, 2 * beta);
    for(int i = 2; i <= n; ++i) {
        coeff[i][i-1] = Fraction(1, beta * (i-1));
        // temp_coeff := coeff(\int at power i-2)
        Fraction temp_coeff = Fraction(i - 2, i - 1);
        coeff[i][n+1] = temp_coeff * coeff[i-2][n+1];
        for(int j = i-2; j >= 0; --j) {
            if (coeff[i-2][j].numerator != 0 && temp_coeff.numerator != 0) {
                coeff[i][j] = temp_coeff * coeff[i-2][j];
            }
        }
    }

    std::stringstream buffer, maple_buffer;
    for(int i = 0; i <= n; ++i) {
        output_sec(buffer, maple_buffer, coeff[i], i, beta);
        buffer << '\n';
    }

    return coeff;
}

vector<vector<Fraction>> solve_csc(int n, int beta = 1) {
    vector<vector<Fraction>> coeff(n+1, vector<Fraction>(n+2));
    
    // primitive at power i
    // coeff[i][0] := coeff(ln|(1-cos)/(1+cos)|)
    // coeff[i][j] := coeff(csc^jcos)
    // coeff[i][n+1] := coeff(x)
    coeff[0][n+1] = Fraction(1, 1);
    coeff[1][0] = Fraction(1, 2 * beta);
    for(int i = 2; i <= n; ++i) {
        coeff[i][i-1] = Fraction(-1, beta * (i-1));
        // temp_coeff := coeff(\int at power i-2)
        Fraction temp_coeff = Fraction(i - 2, i - 1);
        coeff[i][n+1] = temp_coeff * coeff[i-2][n+1];
        for(int j = i-2; j >= 0; --j) {
            if (coeff[i-2][j].numerator != 0 && temp_coeff.numerator != 0) {
                coeff[i][j] = temp_coeff * coeff[i-2][j];
            }
        }
    }

    std::stringstream buffer, maple_buffer;
    for(int i = 0; i <= n; ++i) {
        output_csc(buffer, maple_buffer, coeff[i], i, beta);
        buffer << '\n';
    }

    return coeff;
}

vector<vector<Fraction>> solve_arcsin(int n, int beta = 1) {
    vector<vector<Fraction>> coeff(n+1, vector<Fraction>(n+2));
    
    // primitive at power i
    // coeff[i][j] := coeff(arcsin^i)
    coeff[0][0] = Fraction(1, 1);
    coeff[1][1] = Fraction(1, 1);
    coeff[1][0] = Fraction(1, beta);
    for(int i = 2; i <= n; ++i) {
        coeff[i][i] = Fraction(1, 1);
        coeff[i][i-1] = Fraction(i, beta);
        // temp_coeff := coeff(\int at power i-2)
        Fraction temp_coeff = Fraction(-i * (i-1), 1);
        for(int j = i-2; j >= 0; --j) {
            if (coeff[i-2][j].numerator != 0 && temp_coeff.numerator != 0) {
                coeff[i][j] = temp_coeff * coeff[i-2][j];
            }
        }
    }

    std::stringstream buffer, maple_buffer;
    for(int i = 0; i <= n; ++i) {
        output_arcsin(buffer, maple_buffer, coeff[i], i, beta);
        buffer << '\n';
    }

    return coeff;
}

vector<vector<Fraction>> solve_arccos(int n, int beta = 1) {
    vector<vector<Fraction>> coeff(n+1, vector<Fraction>(n+2));
    
    // primitive at power i
    // coeff[i][j] := coeff(arccos^i)
    coeff[0][0] = Fraction(1, 1);
    coeff[1][1] = Fraction(1, 1);
    coeff[1][0] = Fraction(-1, beta);
    for(int i = 2; i <= n; ++i) {
        coeff[i][i] = Fraction(1, 1);
        coeff[i][i-1] = Fraction(-i, beta);
        // temp_coeff := coeff(\int at power i-2)
        Fraction temp_coeff = Fraction(-i * (i-1), 1);
        for(int j = i-2; j >= 0; --j) {
            if (coeff[i-2][j].numerator != 0 && temp_coeff.numerator != 0) {
                coeff[i][j] = temp_coeff * coeff[i-2][j];
            }
        }
    }

    std::stringstream buffer, maple_buffer;
    for(int i = 0; i <= n; ++i) {
        output_arccos(buffer, maple_buffer, coeff[i], i, beta);
        buffer << '\n';
    }

    return coeff;
}

vector<vector<Fraction>> solve_arctan(int n, int beta = 1) {
    vector<vector<Fraction>> coeff(1, vector<Fraction>(2));
    coeff[0][0] = Fraction(1, 1);
    coeff[0][1] = Fraction(n, 2*beta);

    std::stringstream buffer, maple_buffer;
    output_arctan(buffer, maple_buffer, coeff[0], n, beta);
    
    return coeff;
}

vector<vector<Fraction>> solve_arccot(int n, int beta = 1) {
    vector<vector<Fraction>> coeff(1, vector<Fraction>(2));
    coeff[0][0] = Fraction(1, 1);
    coeff[0][1] = Fraction(n, 2*beta);

    std::stringstream buffer, maple_buffer;
    output_arccot(buffer, maple_buffer, coeff[0], n, beta);
    
    return coeff;
}

vector<vector<Fraction>> solve_arcsec(int n, int beta = 1) {
    vector<vector<Fraction>> coeff(1, vector<Fraction>(2));
    coeff[0][0] = Fraction(1, 1);
    coeff[0][1] = Fraction(n, beta);

    std::stringstream buffer, maple_buffer;
    output_arcsec(buffer, maple_buffer, coeff[0], n, beta);
    
    return coeff;
}

vector<vector<Fraction>> solve_arccsc(int n, int beta = 1) {
    vector<vector<Fraction>> coeff(1, vector<Fraction>(2));
    coeff[0][0] = Fraction(1, 1);
    coeff[0][1] = Fraction(n, beta);

    std::stringstream buffer, maple_buffer;
    output_arccsc(buffer, maple_buffer, coeff[0], n, beta);
    
    return coeff;
}



/* ================================================================================== */
/* Solve */
/* ================================================================================== */

// Classify and group check function
vector<string> group_1 = {"sin", "cos", "tan", "cot", "sec", "csc"};
vector<string> group_2 = {"arcsin", "arccos"};
vector<string> group_3 = {"arctan", "arccot", "arcsec", "arccsc"};
bool is_in(string target_func, vector<string> func_list) {
    for(auto func: func_list) {
        if(target_func == func) return true;
    }
    return false;
}

// Map above functions with the corresponding trigonometric function
typedef vector<vector<Fraction>> (*solve_ptr)(int, int);
typedef void (*output_ptr)(std::stringstream&, std::stringstream&, vector<Fraction>, int, int);

// Individual solving for each type of trigonometric function
pair<string, string> solve_func(int n, string func, vector<tuple<int, int, int>> terms) {
    // get<0>(terms[i]) := alpha[i], get<1>(terms[i]) := beta[i], get<2>(terms[i]) := gamma[i]
    auto cmp = [](tuple<int, int, int> t1, tuple<int, int, int> t2) {
        // Sort by beta
        return get<1>(t1) < get<1>(t2);
    };
    sort(terms.begin(), terms.end(), cmp);

    vector<vector<tuple<int, int, int>>> clusters(2*n);
    int cluster_index;
    if(is_in(func, group_1)) {
        cluster_index = 0;
        clusters[cluster_index].push_back(terms[0]);
        for(int i = 1; i < n; ++i) {
            if(get<1>(terms[i]) != get<1>(terms[i-1])) ++cluster_index;
            clusters[cluster_index].push_back(terms[i]);
        }
    }
    else if(is_in(func, group_2)) {
        cluster_index = 1;
        if(get<0>(terms[0]) % 2 == 0) clusters[cluster_index-1].push_back(terms[0]);
        else clusters[cluster_index].push_back(terms[0]);
        for(int i = 1; i < n; ++i) {
            if(get<1>(terms[i]) != get<1>(terms[i-1])) {
                cluster_index += 2;
                if(get<0>(terms[i]) % 2 == 0) clusters[cluster_index-1].push_back(terms[i]);
                else clusters[cluster_index].push_back(terms[i]);
            }
            else {
                if(get<0>(terms[i]) % 2 == 0) clusters[cluster_index-1].push_back(terms[i]);
                else clusters[cluster_index].push_back(terms[i]);
            }
        } 
    }
    else if(is_in(func, group_3)) {
        cluster_index = 0;
        clusters[cluster_index].push_back(terms[0]);
        for(int i = 1; i < n; ++i) {
            if((get<0>(terms[i]) != get<0>(terms[i-1])) || (get<1>(terms[i]) != get<1>(terms[i-1]))) ++cluster_index;
            clusters[cluster_index].push_back(terms[i]);
        } 
    }

    for(int i = 0; i <= cluster_index; ++i) {
        sort(clusters[i].begin(), clusters[i].end());
        reverse(clusters[i].begin(), clusters[i].end());
    }

    map<string, solve_ptr> solve_map;
    solve_map["sin"] = solve_sin;
    solve_map["cos"] = solve_cos;
    solve_map["tan"] = solve_tan;
    solve_map["cot"] = solve_cot;
    solve_map["sec"] = solve_sec;
    solve_map["csc"] = solve_csc;
    solve_map["arcsin"] = solve_arcsin;
    solve_map["arccos"] = solve_arccos;
    solve_map["arctan"] = solve_arctan;
    solve_map["arccot"] = solve_arccot;
    solve_map["arcsec"] = solve_arcsec;
    solve_map["arccsc"] = solve_arccsc;

    map<string, output_ptr> output_map;
    output_map["sin"] = output_sin;
    output_map["cos"] = output_cos;
    output_map["tan"] = output_tan;
    output_map["cot"] = output_cot;
    output_map["sec"] = output_sec;
    output_map["csc"] = output_csc;
    output_map["arcsin"] = output_arcsin;
    output_map["arccos"] = output_arccos;
    output_map["arctan"] = output_arctan;
    output_map["arccot"] = output_arccot;
    output_map["arcsec"] = output_arcsec;
    output_map["arccsc"] = output_arccsc;

    string total_result = "", total_maple_result = "";
    std::stringstream buffer, maple_buffer;
    for(int i = 0; i <= cluster_index; ++i) {
        if(clusters[i].size() > 0) {
            vector<vector<Fraction>> coeff_matrix = solve_map[func](get<0>(clusters[i][0]), get<1>(clusters[i][0]));
            vector<Fraction> cluster_result(coeff_matrix[0].size());

            if(is_in(func, group_1) || is_in(func, group_2)) {
                for(int j = 0; j < clusters[i].size(); ++j) {
                    for(int k = 0; k < cluster_result.size(); ++k) {
                        cluster_result[k] += Fraction(get<2>(clusters[i][j]), 1) * coeff_matrix[get<0>(clusters[i][j])][k];
                    }
                }
            }
            else if(is_in(func, group_3)) {
                for(int j = 0; j < clusters[i].size(); ++j) {
                    for(int k = 0; k < cluster_result.size(); ++k) {
                        cluster_result[k] += Fraction(get<2>(clusters[i][j]), 1) * coeff_matrix[0][k];
                    }
                }
            }
            output_map[func](buffer, maple_buffer, cluster_result, get<0>(clusters[i][0]), get<1>(clusters[i][0]));
        }
    }

    total_result = buffer.str();
    total_maple_result = maple_buffer.str();
    pair<string, string> return_string = make_pair(total_result, total_maple_result);

    return return_string;
}

// Main solving
void solve() {
    int n; cin >> n;
    vector<tuple<int, int, int, string>> terms(n);

    // get<0>(terms[i]) := alpha[i], terms[i].second := beta[i]
    for(int i = 0; i < n; ++i) cin >> get<0>(terms[i]);
    for(int i = 0; i < n; ++i) cin >> get<1>(terms[i]);
    for(int i = 0; i < n; ++i) cin >> get<2>(terms[i]);
    for(int i = 0; i < n; ++i) cin >> get<3>(terms[i]);

    auto cmp = [](tuple<int, int, int, string> t1, tuple<int, int, int, string> t2) {
        return get<3>(t1) < get<3>(t2);
    };
    sort(terms.begin(), terms.end(), cmp);

    vector<vector<tuple<int, int, int, string>>> clusters(12);
    int cluster_index = 0;
    clusters[cluster_index].push_back(terms[0]);
    for(int i = 1; i < n; ++i) {
        if(get<3>(terms[i]) != get<3>(terms[i-1])) ++cluster_index;
        clusters[cluster_index].push_back(terms[i]);
    }

    string total_result = "", maple_check = "";
    for(int i = 0; i <= cluster_index; ++i) {
        int cluster_size = clusters[i].size();
        string cluster_func = get<3>(clusters[i][0]);
        vector<tuple<int, int, int>> cluster_terms(cluster_size);
        for(int j = 0; j < cluster_size; ++j) {
            get<0>(cluster_terms[j]) = get<0>(clusters[i][j]);
            get<1>(cluster_terms[j]) = get<1>(clusters[i][j]);
            get<2>(cluster_terms[j]) = get<2>(clusters[i][j]);
        }
        pair<string, string> cluster_result = solve_func(cluster_size, cluster_func, cluster_terms);
        total_result += cluster_result.first;
        if(cluster_func == "sin" || cluster_func == "cos" || cluster_func == "arcsin" || cluster_func == "arccos") {
            maple_check += "+diff(" + cluster_result.first + ",x) ";
        }
        else if(cluster_func == "tan" || cluster_func == "cot" || cluster_func == "sec" || cluster_func == "csc") {
            maple_check += "+evalc(diff(" + cluster_result.first + ",x)) ";
        }
        else if(cluster_func == "arctan" || cluster_func == "arccot") {
            maple_check += cluster_result.second;
        }
        else if(cluster_func == "arcsec" || cluster_func == "arccsc") {
            string convert_query = "+convert(" + cluster_result.second + ", 'piecewise', x) ";
            maple_check += convert_query;
        }
    }
    std::stringstream fx_buffer;
    cout << "Input = ";
    for(int i = 0; i < n; ++i) {
        if(get<2>(terms[i]) > 0) fx_buffer << "+";
        fx_buffer << get<2>(terms[i]) << "*" << get<3>(terms[i]) << "(" << get<1>(terms[i]) << "*x)^" << get<0>(terms[i]) << " ";
    }
    cout << fx_buffer.str();
    cout << "\n\nOutput: " << total_result;
    cout << "\n\nMaple query: " << "simplify(" << maple_check << "-" << "(" << fx_buffer.str() << ")" ")" << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("./input.txt", "r", stdin);

    solve();

    return 0;
}