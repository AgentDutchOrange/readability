#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

float averages(int x, int y);

int main(void)
{
    string paragraph = get_string("Text: ");
    
    int words = 0;
    int sentences = 0;
    int letters = 0;
    int n = strlen(paragraph);
    
    //count the number of words and sentences
    for (int i = 0; i <= n; i++)
    {
        //word increment per space (extra check for null at end of paragraph)
        if (paragraph[i] == '\0' || paragraph[i] == ' ')
        {
            ++words;
        }
        //sentence increment per punctuation mark
        if (paragraph[i] == '.' || paragraph[i] == '!' || paragraph[i] == '?')
        {
            ++sentences;
        }
        //# of letters
        if (isalpha(paragraph[i]))
        {
            ++letters;
        }
    }
    
    float l = averages(letters, words);
    
    float s = averages(sentences, words);
   
    
    int index = round(0.0588 * l - 0.296 * s - 15.8);
    
    if (index < 16 && index >= 1)
    {
        printf("Grade %i\n", index);
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Before Grade 1\n");
    }
}

float averages(int x, int y)
{
    //get averages
    float a = ((float) x / (float) y * 100);
    return a;
}
