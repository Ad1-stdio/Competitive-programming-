#include <iostream>
#include <string>
using namespace std;


void TooLong(string word)
{
    char MyString[] = word;
    char *ptr = MyChar; 
    int num = 0;
    int length = word.length();
    if (length > 10)
    {
        for(int i = word[0] ; i < word[length-1] ; i++)
        {
            num += i;
        }
        cout<<num<<endl;
    }
}

int main()
{
    string word = "internationalisation";
    TooLong(word);

    return 0;
}
