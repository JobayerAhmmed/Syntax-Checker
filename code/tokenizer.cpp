/*
** This program tokenize a string by a delimiter and store tokens in the given array
** Input: string, delimiter, array of tokens
** Output: store the tokens in the array
** Line: 50
*/

void tokenize(string s, char delimiter, string *tokens)
{
    int current_index;  // current token index
    int previous_index; // previous token index

    current_index = s.find(delimiter);
    previous_index = 0;

    /* tokenize the string as long as the delimiter found */
    int i = 0;
    while(current_index != -1) {

        tokens[i] = s.substr(previous_index, current_index - previous_index);

        previous_index = current_index + 1;

        // find next delimiter
        current_index = s.find(delimiter, previous_index);

        i++;
    }
    //last token
    tokens[i] = s.substr(previous_index);
}

/*
** This program count the number of tokens
** Input: string, delimiter
** Output: return number of tokens
*/
int token_number(string s, char delimiter)
{
    int n = 1;  // number of token
    int i = 0;

    /* search for tokens */
    while(s[i]) {
        if(s[i] == delimiter)
            n++;
        i++;
    }

    return n;
}

