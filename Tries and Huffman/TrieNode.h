
class TrieNode{
    char data;
    TrieNode** children;
    bool isTerminal;

    //constructor
    TrieNode(char data)
    {
        this->data = data;
        children = new TrieNode*[26];
        for(int i=0; i<26; i++)
            children[i] = '\0';
        isTerminal = false;
    }

};