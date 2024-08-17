/*
 Name: Johnny Castillo
 NetID: johnnysc
 Course: CompSci 242P
*/

#include <iostream>

using namespace std;

int i = 0;
void next(string& s);
void Computation(string& s);
int Expression(string& s);
int Term(string& s);
int Factor(string& s);

void next(string& s){ // consume whitespaces if any
    while(s[i] == ' ') i++;
}
void Computation(string& s){
    int value = 0, n = s.length();
    next(s);
    while(i < n){
        value = Expression(s);
        if(s[i] == '.'){
            cout << value << endl;
            i++;
            next(s);
        }
    }
}
int Expression(string& s){
    next(s);
    int value = 0;
    value = Term(s);
    next(s);

    while(s[i] == '+' || s[i] == '-'){
        if(s[i] == '+'){
            i++;
            value += Term(s);
        }
        else{
            i++;
            value -= Term(s);
        }
        next(s);
    }
    return value;
}
int Term(string& s){
    next(s);
    int value = 0;
    value = Factor(s);
    next(s);

    while(s[i] == '*' || s[i] == '/'){
        if(s[i] == '*'){
            i++;
            value *= Factor(s);
        }
        else{
            i++;
            value /= Factor(s);
        }
        next(s);
    }
    return value;
}
int Factor(string& s){
    next(s);
    int value = 0;
    if(s[i] == '('){
        i++; // consume ( paren
        next(s);
        value = Expression(s);
        i++; // consume ) paren
        next(s);
    }
    else if(isdigit(s[i])){
        value = s[i] - '0';
        i++;
        next(s);
        while(isdigit(s[i])){
            value = value * 10 + (s[i] - '0');
            i++;
            next(s);
        }
    }
    next(s);
    return value;
}
int main(){
    string s = "1   +2    *(3+4) . 7 * 6 . ((3*4)+(5-2))/2-6*((9*9)/10+4).   1 + 1. 2-1 + 2 .(1+(4+5+2)-3)+(6+8).";
    Computation(s);
    return 0;
}