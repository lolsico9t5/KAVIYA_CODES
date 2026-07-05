//1.Write a program to read a line of text using a string object and perform the following operations: • Find empty spaces in the given text. • If only one space exists between words, add one extra space. • If more than two spaces exist, reduce them to two spaces. 
// Replace spaces
#include <iostream>
#include <string>
using namespace std;

class TextProcessor
{
private:
    string text;
    string result;
public:
    void readText()
    {
        cout << "Enter a line of text: ";
        getline (cin, text);
    }
    
    void processText()
    {
        int spaceCount = 0;
        int totalSpaces = 0;
        
        for(int i = 0; i < text.length(); i++)
        {
            if (text[i] == ' ')
            {
                spaceCount++;
                totalSpaces++;
            }
            else
            {
                if (spaceCount == 1)
                {
                    result += "  "; // one space make it two
                }
                else if (spaceCount >= 2)
                {
                    result += "  "; // more than two reduce to two
                }
                spaceCount = 0;
                result += text[i];
            }
        }
        
        // Handle trailing spaces
        if (spaceCount == 1)
            result += "  ";
        else if (spaceCount >= 2)
            result += "  ";
            
        cout << "\nTotal spaces found: " << totalSpaces << endl;
    }
    
    void display()
    {
        cout << "Modified text:\n" << result << endl;
    }
};

int main()
{
    TextProcessor obj;
    obj.readText();
    obj.processText();
    obj.display();
    return 0;
}