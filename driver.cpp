// include libraries here (STL not allowed)
#include <iostream>
#include <string>
#include "trie.h"
#include <fstream>
int main()
{

    Trie tree;

    while (true)
    {
        string command;
        cin >> command;

        if(command == "load"){
            ifstream fin("corpus.txt");
            string w;
            while(!fin.eof()){
                fin >> w;
                tree.insert(w);
            }
            cout << "success" << endl;
        }
        if (command == "i")
        {
            string word;
            cin >> word;
            cout << tree.insert(word) << endl;
        }
        if (command == "c")
        {
            string prefix;
            cin >> prefix;
            int num = tree.amntOfWords(prefix);
            if (num == 0)
                cout << "not found" << endl;
            else
                cout << "count is " << num << endl;;
        }
        if(command == "e"){
            string word;
            cin >> word;
            tree.erase(word);
        }
        if(command == "p"){
            tree.print();
        }
        if(command == "spellcheck"){
            string word;
            cin >> word;
            tree.spellcheck(word);
        }
        if(command == "empty"){
            tree.empty();
        }
        if(command == "clear"){
            tree.clear();
        }
        if(command == "size"){
            cout << "number of words is "<<tree.num << endl;
        }
        if(command == "exit"){
            return 1;
        }
    }
}