/*
 Implementation example of Trie data structure

 Only three oparations where implemented:
 1 - Add word to the dictionary
 2 - Find amount of exact match of given word
 3 - Find amount of words with given prefix
*/

#include <iostream>

using namespace std;


class trie {
  int prefixes;
  int ending_words;
  trie* nodes[27];

  public: 
    trie(){
      for(int i = 0; i < 27; i++) {
        prefixes = 0;
        ending_words = 0;
        nodes[i] = NULL;
      }
    }

    void add_word(string word) {
      trie* current = this;
      for(int i = 0; i < word.size(); i++) {
        int pos = word[i]-'a';
        if(current->nodes[pos] == NULL) {
          current->nodes[pos] = new trie();
        }
        current->prefixes++;
        current = current->nodes[pos];
      }
      current->ending_words++;
    }

    int search_word(string word) {
        trie* current = this;
        for(int i = 0; i < word.size(); i++) {
            int pos = word[i]-'a';
            if(current->nodes[pos] == NULL){
                return 0;
            }
            current = current->nodes[pos];
        }
        return current->ending_words;
    }

    int search_possible_words(string word)
    {
        trie* current = this;
        for(int i = 0; i < word.size(); i++) {
            int pos = word[i]-'a';
            if(current->nodes[pos] == NULL) {
              return 0;
            }  
            current = current->nodes[pos];
        }
        return current->prefixes;
    }
};

int main() {
  int queries, option;
  string word, prefix;
  trie T = trie();
  
  cout << "Enter the amount of queries to perform: ";
  cin >> queries;
  while(queries--) {
    cout << "Please enter a valid option: " << endl;
    cout << "1: To add a word to the dictionary" << endl;
    cout << "2: To find amount of exact match of given word" << endl;
    cout << "3: To find amount of words with given prefix" << endl;
    cin >> option;
    switch(option) {
      case 1:
        cin >> word;
        T.add_word(word); 
      break;
      case 2: 
        cin >> word;
        cout << "Amount of exact words: " << T.search_word(word) << endl;
      break;
      case 3:
        cin >> prefix;
        cout << "Amount of words with this prefix : " << 
          T.search_possible_words(prefix) << endl;
      break;
      default:
      break;
    }
  }
}