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

bool startTest(string email){
    bool test = true;


    bool findAtSign = false;
    int lengthFirstPart = 0, lengthSecondPart = 0;
    int countAtSign = 0;
    bool checkForSymbol = false;
    bool checkForSpecSymbol = false;

    checkForSymbol = check_for_symbols(email[0]);
    checkForSpecSymbol = (checkForSymbol) ? true : check_for_spec_symbols(email[0]);

    if (email[0] == '@' || email[0] == '.' || email[email.length() - 1] == '.' || ((!checkForSymbol) && (!checkForSpecSymbol))) test = false;
    else{
        for(int i = 1; i < email.length() - 1; i++){
            checkForSymbol = check_for_symbols(email[i]);
            checkForSpecSymbol = (checkForSymbol) ? true : check_for_spec_symbols(email[i]);

            if(email[i] == '@') {
                countAtSign++;
                findAtSign = true;
                if(countAtSign > 1) {
                    test = false;
                    break;
                }
                lengthFirstPart = i;
                lengthSecondPart = email.length() - lengthFirstPart - 1;
            }

            if(!findAtSign){
                if(!checkForSymbol && !checkForSpecSymbol){
                    test = false;
                    break;
                }
            }else{
                if(!checkForSymbol && checkForSpecSymbol){
                    test = false;
                    break;
                }
            }
            if(email[i] == '.' && email[i-1] == '.') {
                test = false;
                break;
            }
        }
    }
    return test;
}

int main(){
    string email;
    cout << "Enter email address: " << endl;
    cin >> email;

    (startTest(email)) ? cout << "Yes\n" : cout << "No\n";

    return 0;

}



