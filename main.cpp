#include <iostream>

using namespace std;

bool check_for_spec_symbols(char sym){
    bool temp = false;
    string origin = "!#$%&'*+-/=?^_`{|}~";
    for(int j = 0; j < origin.length(); j++){
        if(sym == origin[j]) temp = true;
        break;
    }
    return temp;
}

bool check_for_symbols(char sym){
    bool temp = true;
    if((sym >= 'A' && sym <= 'Z') || (sym >= 'a' && sym <= 'z') || (sym >= '0' && sym <= '9') || sym == '-' || sym == '.') temp = true;
    else temp = false;
    return temp;
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
    bool mainFlag = true;
    cout << "Enter email address: " << endl;
    cin >> email;

    posAtSign = positionAtSign(email);
    leftLength = posAtSign;
    rightLength = email.length() - posAtSign;

    if (email[0] == '.' || email[email.length() - 1] == '.' || leftLength > 64 || rightLength > 63) mainFlag = false;
    else{
        if(posAtSign == 0) mainFlag = false;
        else{
            for(int i = 0; i < posAtSign; i++){
                mainFlag = check_for_symbols(email[i]) || check_for_spec_symbols(email[i]);
                if(!mainFlag) break;
                if(email[i] == '.' && email[i+1] == '.'){
                    mainFlag = false;
                    break;
                }
            }
            for(int i = posAtSign + 1; i < email.length(); i++){
                mainFlag = check_for_symbols(email[i]);
                if(!mainFlag) break;
                if(email[i] == '.' && email[i-1] == '.'){
                    mainFlag = false;
                    break;
                }
            }
        }
    }

    (mainFlag) ? cout << "Yes\n" : cout << "No\n";

    return 0;

}



