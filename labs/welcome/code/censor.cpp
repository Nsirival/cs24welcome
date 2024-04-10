#include <iostream>
#include <string>
#include <vector>
using namespace std;


int main(int argc, char** argv){
    
    
    string initial;
    getline(cin, initial); 
    string word;
    string fin;
    vector <string> vect;

    if (argc != 2) {
        cout << "USAGE: censor [length]" << endl;
        return 1;
    }

    for(int i = 0; i < (int)initial.length(); i++){
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
    
    for(int i = 0; i < (int)vect.size(); i++){
        if((int)vect.at(i).length() != (int)atoi(argv[1]) && (int)vect.at(i).length() != 0){
            fin = fin + vect.at(i) + " ";
        }
    }
    if((int)fin.length() > 0){
        fin.pop_back();
    }
<<<<<<< HEAD
    cout << fin;
=======
    cout << fin << endl;
>>>>>>> 8c258e6b5d1c17901687db2dcec14f87a1229c2c

    return 0;
}
