/*
* This program check for a given token and return its index
* Input: token
* Output: index
* Line: 20
*/

int check_token(string token)
{
    string reserved_token[] = {"void", "char", "int", "float", "double", "printf",
                                "scanf", "if", "else", "for", "while", "do", "break", "return"};
    int i;

    for( i = 0; i < 14; i++)
        if(token == reserved_token[i])
            return i;

    return -1;
}
