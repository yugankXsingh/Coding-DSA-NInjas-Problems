#include <bits/stdc++.h>
using namespace std;

int crossword[10][10];

bool isValidHorizontal(int row, int col, string word)
{ // check
    if (10 - col < word.length())
    {
        return false;
    }

    int count = 0;
    for (int j = col; count < word.length(); j++)
    {
        if (crossword[row][j] == '+')
        {
            return false;
        }

        if (crossword[row][j] != '+' && crossword[row][j] != '-')
        {
            if (crossword[row][j] != word[count])
            {
                return false;
            }
        }

        count++;
    }

    return true;
}

bool isValidVertical(int row, int col, string word)
{ // check
    if (10 - row < word.length())
    {
        return false;
    }

    int count = 0;
    for (int i = row; count < word.length(); i++, count++)
    {
        if (crossword[i][col] == '+')
        {
            return false;
        }

        if (crossword[i][col] != '+' && crossword[i][col] != '-')
        {
            if (crossword[i][col] != word[count])
            {
                return false;
            }
        }
    }

    return true;
}

void setHorizontal(int row, int col, string word, bool helper[])
{ // check
    int count = 0;
    for (int j = col; count < word.length(); j++, count++)
    {
        if (crossword[row][j] == word[count])
        {
            // right character is already present
            // at the correct place
            helper[count] = false;
        }
        else
        {
            // no character is present
            // insert the chaarcter
            crossword[row][j] = word[count];

            // update the helper array
            helper[count] = true;
        }
    }
}

void setVertical(int row, int col, string word, bool helper[])
{ // check
    int count = 0;
    for (int i = row; count < word.length(); count++, i++)
    {
        if (crossword[i][col] == word[count])
        {
            helper[count] = false;
        }
        else
        {
            crossword[i][col] = word[count];
            helper[count] = true;
        }
    }
}

void resetHorizontal(int row, int col, bool helper[], int length)
{ // check
    int count = 0;
    for (int j = col; count < length; count++, j++)
    {
        if (helper[count] == true)
        {
            crossword[row][j] = '-';
        }
    }
}

void resetVertical(int row, int col, bool helper[], int length)
{ // check
    int count = 0;
    for (int i = row; count < length; count++, i++)
    {
        if (helper[count] == true)
        {
            crossword[i][col] = '-';
        }
    }
}

void setHelperValue(bool helper[], int length)
{ // check
    for (int i = 0; i < length; i++)
    {
        helper[i] = false;
    }
    return;
}

bool crosswordHelper(string input[], int size, int index)
{

    // base case
    if (index == size)
    // check
    { // all words are inserted
        // print the grid
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                cout << crossword[i][j];
            }
            cout << endl;
        }
        return true;
    }

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (crossword[i][j] == '-' || crossword[i][j] == input[index][0])
            {
                // valid empty space
                int length = input[index].length(); //--> current word length
                bool helper[length];                // -->  to keep track of word which was filled
                setHelperValue(helper, length);

                if (isValidHorizontal(i, j, input[index]))
                {
                    setHorizontal(i, j, input[index], helper);

                    // call on the remaining grid
                    bool res = crosswordHelper(input, size, index + 1);
                    if (res == true)
                    {
                        // we have successfully filled the grid
                        return true;
                    }
                    else
                    {
                        // we have filled wrong word
                        // reset the grid
                        resetHorizontal(i, j, helper, length);
                    }
                }

                if (isValidVertical(i, j, input[index]))
                {
                    setVertical(i, j, input[index], helper);

                    // call on the remaining grid
                    bool res = crosswordHelper(input, size, index + 1);
                    if (res == true)
                    {
                        // we have successfully filled the grid
                        return true;
                    }
                    else
                    {
                        // we have filled wrong word
                        // reset the grid
                        resetVertical(i, j, helper, length);
                    }
                }
            }
        }
    }
    // return false;
}

void solveCrossword(string input[], int size)
{
    bool res = crosswordHelper(input, size, 0);
}

int main()
{
    // write your code here
    string s;

    // taking grid input
    for (int i = 0; i < 10; i++)
    {
        cin >> s;
        for (int j = 0; j < 10; j++)
        {
            crossword[i][j] = s[j];
        }
    }

    // taking word input
    string wordList;
    cin >> wordList;

    string word = "";
    string input[10];
    int a = 0;

    for (int i = 0; wordList[i] != '\0'; i++)
    {
        if (wordList[i] == ';')
        {
            // word ends here
            input[a++] = word;
            word = ""; // reset the word
        }
        else
        {
            word = word + wordList[i];
        }
    }

    // last word still not filled into the input array
    input[a++] = word;

    solveCrossword(input, a);

    return 0;
}
