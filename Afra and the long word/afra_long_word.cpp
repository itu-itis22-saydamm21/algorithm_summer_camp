#include <iostream>
#include <string>

using namespace std;

void    printDivisions(string s, string out){
    if(s.length() == 0){
        cout << out << endl;
        return;
    }
    
    for (int i = 1; i <= s.length(); i++){
        string part = s.substr(0, i);
        string remaining = s.substr(i);
        
        if(!out.empty()){
            part = " " + part;
        }
        printDivisions(remaining, out + part);
    }
}

int main(){
    int n;
    string  s;
    cin >> n >> s;
    
    printDivisions(s, "");
    return 0;
}