//Program 2: Write a C++ program for a chat application to analyze a message using string operations: a) Count total vowels, display individual vowel counts, and identify the vowel with the highest count. b) Count the number of words in the message. c) Check whether a given keyword is present and display its starting position.
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class ChatAnalyzer
{
    string message;
public:
    void readMessage()
    {
        cout << "Enter chat message: ";
        getline(cin, message);
    }
    
    // a) Vowel analysis
    void vowelAnalysis()
    {
        int a = 0, e = 0, i = 0, o = 0, u = 0;
        
        for(int j = 0; j < message.length(); j++)
        {
            char ch = tolower(message[j]);
            if (ch == 'a') a++;
            else if (ch == 'e') e++;
            else if (ch == 'i') i++;
            else if (ch == 'o') o++;
            else if (ch == 'u') u++;
        }
        
        int total = a + e + i + o + u;
        cout << "\nTotal vowels = " << total << endl;
        cout << "a=" << a << " e=" << e << " i=" << i << " o=" << o << " u=" << u << endl;
        
        int max = a;
        char v = 'a';
        if(e > max) { max = e; v = 'e'; }
        if(i > max) { max = i; v = 'i'; }
        if(o > max) { max = o; v = 'o'; }
        if(u > max) { max = u; v = 'u'; }
        
        if (max > 0)
            cout << "Highest vowel = " << v << " (" << max << " times) " << endl;
    }

    // b) Word count
    void wordCount()
    {
        int count = 0;
        for(int j = 0; j < message.length(); j++)
        {
            if( (j == 0 && message[j] != ' ') || 
                (message[j] != ' ' && message[j-1] == ' ') )
            {
                count++;
            }
        }
        cout << "\nNumber of words = " << count << endl;
    }

    // c) Keyword search
    void searchKeyword()
    {
        string key;
        cout << "\nEnter keyword: ";
        cin >> key;
        int pos = message.find(key);
        
        if(pos != string::npos)
            cout << "Keyword found at position " << pos << endl;
        else
            cout << "Keyword not found" << endl;
    }
};

int main()
{
    ChatAnalyzer obj;
    obj.readMessage();
    obj.vowelAnalysis();
    obj.wordCount();
    obj.searchKeyword();
    return 0;
}