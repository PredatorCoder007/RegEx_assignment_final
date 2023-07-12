//representing a*b*c* using trie data structure
#include<iostream>>
#include<cctype>
#include<string>
#include<vector>
#include<algorithm>
#include<random>// std::default_random_engine
#include<chrono>// std::chrono::system_clock

const int ALPHABET_SIZE = 26;

class Node
{
    Node *children[ALPHABET_SIZE];
    bool end;

    static int getIndex(char c)
    {
        return tolower(c) - 'a';
    }

public:
    Node()
    {
        end = false;

        for(int i=0; i<ALPHABET_SIZE; i++)
            children[i] = nullptr;

    };

    void insert(std::string key)
    {
        Node *temp = this;

        for(int i=0; i<key.length(); ++i)
        {
            int index = Node::getIndex(key[i]);
            if(temp->children[index] == nullptr)
               temp->children[index] == new Node();

            temp = temp->children[index];
        }

        temp->end = true;
    }

    bool search(std::string key)
    {
        Node *temp = this;

        for(int i=0; i<key.length(); i++)
        {
            int index = Node::getIndex(key[i]);
            if(temp->children[index] == nullptr)
                return false;

            temp = temp->children[index];
        }

        return temp->end;
    }

    bool matchPattern(std::string key)
    {
        Node *temp = this;

        for(int i=0; i<key.length(); i++)
        {
            int index = Node::getIndex(key[i]);

            //check if the current character matches 'a' or 'b'
            if(index != 0 && index != 1)
                return false;

            if(temp->children[index] == nullptr)
                return false;

            temp = temp->children[index];
        }

       return true;
    }
};

int main()
{
    std::vector<std::string> allWords = {"a", "aa", "aaa", "b", "bb", "bbb", "c", "cc", "ccc"};

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(allWords.begin(), allWords.end(), std::default_random_engine(seed));

    Node *root = new Node;

    for (const std::string& word : allWords)
        root->insert(word);

    std::cout << "Matching words for pattern 'a*b*c*':" << std::endl;
    for (const std::string& word : allWords)
    {
        if (root->matchPattern(word))
            std::cout << word << std::endl;
    }

    return 0;
}
