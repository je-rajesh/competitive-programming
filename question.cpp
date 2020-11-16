#include<bits/stdc++.h>
using namespace std;


void splitString(vector<string>&array, string str, char delimiter){
    stringstream stream(str); // for making it a stream. 
    
    string temp;
    
    // Tokenizing w.r.t. space ' ' 
    while(getline(stream, temp, delimiter)) 
    { 
        array.push_back(temp); 
    } 
}

int main()
{
    int n;
    string temp ;
    // cin >> n;

    vector<string>mail;

    vector<string>array;
    std::map<string, vector<string>> M;

    vector<string>hello = {"hi@hotmail.com", "def@yahoo.com", "ghi@gmail.com", "abc@channelier.com", "abc@hotmail.com", "def@hotmail.com", "abc@gmail.com", "abc@yahoo.com", "def@channelier.com","jkl@hotmail.com", "ghi@yahoo.com", "def@gmail.com"};

    for(int i = 0; i< hello.size(); i++) {
        // cin >> temp;
        temp = hello[i];
        splitString(array, temp, '@');

        // pushing the emails into their mapped domain name array. 
        M[array[1]].push_back(temp);
        array.clear();
    }

    for(auto i = M.begin(); i != M.end(); i++) { // gives iterator
        sort(i->second.begin(), i->second.end());

        mail.push_back(i->second[0]);
    }

    for(auto i = mail.begin(); i != mail.end(); i++){
        cout << *i << endl;
    }
}
