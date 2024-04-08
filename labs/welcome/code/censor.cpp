#include <iostream>
#include <string>
#include <vector>
using namespace std;


int main(int argc, char** argv){
    
    
    string initial;
    getline(cin, initial); 
    string word;
    
    vector <string> vect;

    if (argc != 2) {
        cout << "USAGE: censor [length]" << endl;
        return 1;
    }

    for(int i = 0; i < initial.length(); i++){
        if (!isspace(initial[i])) {
            word += initial[i];
        } else {
            if (!word.empty()) {
                vect.push_back(word);
                word.clear();
            }
        }
    }

    if (!word.empty()) {
        vect.push_back(word);
    }
    
    for(int i = 0; i < vect.size(); i++){
        if(vect.at(i).length() != atoi(argv[1]) && vect.at(i).length() != 0){
            cout << vect.at(i) << " ";
        }
    }

    return 0;
}
