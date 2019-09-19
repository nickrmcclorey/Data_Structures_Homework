#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

int main(){
    ifstream readFile;
    string fName, fLine;
    
    cout << "Enter a file name to open: " << endl;
    cin >> fName;
    
    readFile.open(fName);
    if(readFile.fail()){
        cout << "The specified file has failed to open" << endl; //Nothing happens, file fails to open
    }
    else{
        int k = 0;
        while(getline(readFile, fLine) && k < 10){
            cout << fLine << endl;
            k++;
        }
    }
    return 0;
}