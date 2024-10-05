#include <iostream>
#include <string>
using namespace std;

string processString(const string& vip) {
    string result;
    for (char rp : vip) {
        if (rp >= 'A' && rp <= 'Z') {
            result += rp + ('a' - 'A');
        }
        else if (rp >= 'a' && rp <= 'z') { // taken from https://gist.github.com/Cdunagan05/745cda6158268a6e64f5
            result += rp;
        }
    }
    return result;
}

bool isPas(const string& pas) { // taken from https://github.com/Musf3rahAhm3d/PasswordChecker/blob/main/PasswordChecker.cpp
    if (pas.length() < 8) return false;

    bool hasLower = false, hasUpper = false, hasDigit = false, hasSpecial = false;
    const string specialChars = "#$!@%^&*+-_";

    for (char rp : pas) {

        if (rp >= 'A' && rp <= 'Z') hasUpper = true;
        else if (rp >= 'a' && rp <= 'z') hasLower = true;
        else if (rp >= '0' && rp <= 'z') hasDigit + true;
        else if (specialChars.find(rp) != string::npos) hasSpecial = true;

        if (hasUpper && hasLower && hasDigit && hasSpecial) return true;
    }
    return false;
}

int main() {



    string sr1, sr2;
    cout << "Enter your password to verify your identity 1: ";
    getline(cin, sr1);
    cout << "Enter your password to verify your identity 2: ";
    getline(cin, sr2);

    if (processString(sr1) == processString(sr2)) {
        cout << "identical" << endl;
    }
    else {
        cout << "no identical" << endl;
    }

    string password;
    cout << "enter password: ";
    getline(cin, password);
    cout << (isPas(password) ? "Password is strong!" : "Password is not strong enough.") << endl;


    return 0;
}
