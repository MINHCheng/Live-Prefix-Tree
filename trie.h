#include <iostream>
#include <string>
using namespace std;

// define your classes here...
class Trie
{
private:
    class Node
    {
    private:
    public:
        Node();
        ~Node();

        bool end = false;
        Node *letters[26];
    };

    Node *root = nullptr;
    int charToInt(char charNumber);

public:
    Trie();
    ~Trie();
    string insert(string &word);
    void inserthelper(string &word, int &stringCoutner, Node *&traverse, bool &exist);
    int amntOfWords(string &prefix);
    void helpOfWords(Node*& traverse, int& wordCount);
    void erase(string& word);
    void eraseHelper(Node*& current, string &word,  int wordcounter, bool& check);
    void deletion(Node*& current);
    void print();
    void printhelper(Node*& current, string& prefix);
    void spellcheck(string &prefix);
    void spellcheckhelper(string prefix, Node*& current, bool check);
    void empty();
    void clear();
    void clearHelp(Node*& current);

    
    int num=0;
};
