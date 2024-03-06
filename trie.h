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

        Node(/* args */);
        ~Node();

        bool end = false;
        Node* letters = new Node[26];
    };    


public:
    Node* root = new Node;

    Trie(/* args */);
    ~Trie();
    string insert(string word);
};
