#include "trie.h"

// implement classes' member functions here...
Trie::Trie()
{
    this->root = new Node;
}
Trie::~Trie()
{
    clear();
    delete root;
    root = nullptr;
}

int Trie::charToInt(char charnumber)
{
    return (charnumber - 'A');
}

///////////////////// i function O(n) /////////////////////////////////////////
string Trie::insert(string &word)
{
    int counter = 0;
    bool pastexist = true;
    inserthelper(word, counter, root, pastexist);
    if (pastexist)
        return "failure";
    else
        return "success";
}

void Trie::inserthelper(string &word, int &stringCoutner, Trie::Node *&traverse, bool &pastexist)
{
    if (traverse == nullptr)
    {
        return;
    }
    if (word.length() == stringCoutner)
    {
        if (!traverse->end)
        {
            traverse->end = true;
            this->num++;
            pastexist = false;
        }
        return;
    }
    else
    {
        int charIndex = charToInt(word[stringCoutner]);

        if (traverse->letters[charIndex] == nullptr)
        {
            traverse->letters[charIndex] = new Node;
        }

        inserthelper(word, ++stringCoutner, traverse->letters[charIndex], pastexist);
    }

    return;
}
///////////////////// i function O(n) /////////////////////////////////////////

///////////////////// c function O(N)  ///////////////////////////////////////////
int Trie::amntOfWords(string &prefix)
{
    int prefixCounter = 0;
    int wordCount = 0;
    Node *current = root;
    while (prefixCounter < prefix.length())
    {
        int charValue = charToInt(prefix[prefixCounter]);
        if (current->letters[charValue] == nullptr)
        {
            return wordCount;
        }
        else
        {
            current = current->letters[charValue];
            ++prefixCounter;
        }
    }
    helpOfWords(current, wordCount);
    return wordCount;
}

void Trie::helpOfWords(Node *&traverse, int &wordCount)
{
    if (traverse == nullptr)
    {
        return;
    }
    if (traverse->end)
    {
        wordCount++;
    }
    for (int i = 0; i < 26; i++)
    {
        if (traverse->letters[i] != nullptr)
        {
            helpOfWords(traverse->letters[i], wordCount);
        }
    }
}
///////////////////// c function O(N)  ///////////////////////////////////////////

/////////////////////e function O(26n)   ///////////////////////////////////////////)

void Trie::erase(string &word)
{
    bool check = true;
    int counter = 0;
    eraseHelper(root, word, counter, check);
    if (check)
    {
        cout << "success" << endl;
    }
    else
        cout << "failure" << endl;
    return;
}
void Trie::eraseHelper(Node *&current, string &word, int wordcounter, bool &check)
{
    if (current == nullptr)
    {
        return;
    }
    if (wordcounter == word.length())
    {
        if (current->end)
        {
            current->end = false;
            this->num--;
        } // check if it has reached the end and switch to not end
        else check = false;
    }
    else
    {
        int charValue = charToInt(word[wordcounter]);
        if (current->letters[charValue] == nullptr)
        { // check if word exist
            check = false;
            return;
        }
        eraseHelper(current->letters[charValue], word, ++wordcounter, check);
    }

    bool shouldErase = true;
    if (!current->end)
    {
        for (int i = 0; i < 26; i++)
        {
            if (current->letters[i] != nullptr)
            {
                shouldErase = false;
                break;
            }
        }
        if (shouldErase && &current != &root)
        {
            /// delete node here
            delete current;
            current = nullptr;
        }
    }
    return;
}

/////////////////////e function O(26n)   ///////////////////////////////////////////)
void Trie::print()
{
    string word;
    printhelper(root, word);
    cout << endl;
}
void Trie::printhelper(Node *&current, string &prefix)
{
    if (current == nullptr)
    {
        return;
    }
    if (current->end)
    {
        cout << prefix << " ";
    }

    for (int i = 0; i < 26; i++)
    {
        if (current->letters[i] != nullptr)
        {
            char letter = static_cast<char>('A' + i);
            prefix.push_back(letter);
            printhelper(current->letters[i], prefix);
            prefix.pop_back();
        }
    }
}
void Trie::spellcheck(string &word) ////O(N)
{
    int wordCounter = 0;
    Node *current = root;
    string partialString;
    while (wordCounter != word.length())
    {
        if (current == nullptr)
        {
            break;
        }
        else
        {
            int char2number = charToInt(word[wordCounter]);
            if (current->letters[char2number] == nullptr)
            {
                break;
            }
            else
            {
                partialString.push_back(word[wordCounter]);
                current = current->letters[char2number];
                wordCounter++;
            }
        }
    }
    if (wordCounter == 0)
    {
        return;
    }
    if (wordCounter == word.length() && current->end)
    {
        cout << "correct" << endl;
    }
    else
    {
        string prefix;
        printhelper(current, partialString);
        cout << endl;
    }
}
void Trie::empty()
{
    Node *current = root;
    for (int i = 0; i < 26; i++)
    {
        if (current->letters[i] != nullptr)
        {
            cout << "empty 0" << endl;
            return;
        }
    }
    cout << "empty 1" << endl;
    return;
}

void Trie::clear()
{
    clearHelp(root);
    return;
}
void Trie::clearHelp(Node *&current)
{
    for (int i = 0; i < 26; i++)
    {
        if (current->letters[i] != nullptr)
        {
            clearHelp(current->letters[i]);
        }
    }
    if (current != root)
    {
        delete current;
        current = nullptr;
    }
    return;
}
Trie::Node::Node()
{
    for (int i = 0; i < 26; i++)
    {
        this->letters[i] = nullptr;
    }
}
Trie::Node::~Node()
{
    for (int i = 0; i < 26; ++i)
    {
        if (this->letters[i] != nullptr)
        {
            delete this->letters[i];
            this->letters[i] = nullptr;
        }
    }
}
