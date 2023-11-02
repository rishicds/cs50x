#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int countletters(string text);
int countwords(string text);
int countsentences(string text);
int finalscore(float l, float s);

int main(void)
{
    string sentence = get_string("Text : "); // input
    // to store number of letters,words and sentences
    int letters = countletters(sentence);
    int words = countwords(sentence);
    int sentences = countsentences(sentence);
    // L is the average number of letters per 100 words in the text.
    // S is the average number of sentences per 100 words in the text.
    float L = ((float) letters / (float) words) * 100.00;   // letter avg.
    float S = ((float) sentences / (float) words) * 100.00; // sentence avg.

    int score = (int) (round((finalscore(L, S))));

    if (score > 16)
    {
        printf("Grade 16+\n");
    }
    else if (score < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %d\n", score);
    }
}
int countletters(string text)
{
    int n = 0;
    int length = strlen(text);
    for (int i = 0; i < length; i++)
    {
        // only increase count if character is a letter or number
        if ((isalpha(text[i])) || (isalnum(text[i])))
        {
            n++;
        }
    }
    return n;
}

int countwords(string text)
{
    int n = 0;
    int length = strlen(text);
    for (int i = 0; i < length; i++)
    {
        if (text[i] == ' ')
        {
            n++;
        }
    }
    return n + 1; // compensation purpose
}

int countsentences(string text)
{
    int n = 0;
    int length = strlen(text);
    for (int i = 0; i < length; i++)
    {
        if ((text[i] == '.') || (text[i] == '!') || (text[i] == '?'))
        {
            n++;
            if ((text[i + 1] == '.') || (text[i + 1] == '!') || (text[i + 1] == '?'))
            {
                n--;
            }
        }
    }
    return n;
}

int finalscore(float l, float s)
// Koilaman formula:index = 0.0588 * L - 0.296 * S - 15.8
{
    float index = 0;
    index = ((0.0588 * l) - (0.296 * s)) - 15.8;
    return (int) (round(index));
}
