/*
** This program erase spaces from first and last of a string
** Input: string
** Output: string after erasing first and last spaces
** Line: 25
*/

string erase_first_last_space(string s)
{
    int first_character_index;  // first non-space character index
    int last_character_index;   // last non-space character index

    // find first character index
    first_character_index = s.find_first_not_of(' ');

    // erase spaces from the first
    s.erase(0, first_character_index);

    // find last character index
    last_character_index = s.find_last_not_of(' ');

    // erase spaces from the last
    s.erase(last_character_index + 1);

    return s;
}
