#include <iostream>
using namespace std;

bool check_for_spec_symbols(char sym){
    string origin = "!#$%&'*+-/=?^_`{|}~";
    for(int j = 0; j < origin.length(); j++){
        if(sym == origin[j]) return true;
    }
    return false;
}

bool check_for_symbols(char sym){
    if((sym >= 'A' && sym <= 'Z') || (sym >= 'a' && sym <= 'z') ||
       (sym >= '0' && sym <= '9') || sym == '-' || sym == '.') return true;
    else return false;
}

int positionAtSign(string addr){
    int pos;
    int countAtSign = 0;
    for(int i = 0; i < addr.length(); i++){
        if(addr[i] == '@'){
            pos = i;
            countAtSign++;
        }
    }
    if(countAtSign > 1) pos = 0;
    return pos;
}

int main(){
    string email;
    int posAtSign = 0;
    int leftLength, rightLength;
    bool leftSideFlag = true;
    bool rightSideFlag = true;
    cout << "Enter email address: " << endl;
    cin >> email;

    posAtSign = positionAtSign(email);
    leftLength = posAtSign;
    rightLength = email.length() - posAtSign;

    if (email[0] == '.' || email[email.length() - 1] == '.' || leftLength > 64 || rightLength > 63) leftSideFlag = false;
    else{
        if(posAtSign == 0) leftSideFlag = false;
        else{
            for(int i = 0; i < posAtSign; i++){
                leftSideFlag = check_for_symbols(email[i]) || check_for_spec_symbols(email[i]);
                if(!leftSideFlag) break;
                if(email[i] == '.' && email[i+1] == '.'){
                    leftSideFlag = false;
                    break;
                }
            }
            for(int i = posAtSign + 1; i < email.length(); i++){
                rightSideFlag = check_for_symbols(email[i]);
                if(rightSideFlag) break;
                if(email[i] == '.' && email[i-1] == '.'){
                    rightSideFlag = false;
                    break;
                }
            }
        }
    }

    (leftSideFlag && rightSideFlag) ? cout << "Yes\n" : cout << "No\n";

    return 0;
}



