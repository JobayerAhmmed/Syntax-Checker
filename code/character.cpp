/*
** This program search for a character
** Input: char c, string s
** Output: return the index of the character
** Line: 20
*/

int check_character(char c, string s)
{
    int i = 0;

    /* search the character in the string */
    while(s[i]) {
        if(s[i] == c)
            return i;   // if found then return its index
        i++;
    }

    /* if not found then return -1 */
    return -1;
}
