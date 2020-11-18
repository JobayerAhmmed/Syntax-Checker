/*
** This program check the given word
** whether it is a primitive type or not
** Input: input a type name
** Output: return the index of the type
** Line: 25
*/

int check_type(string type)
{
    string types[5] = {"char", "int", "float", "double", "void"}; // primitive types

    /*
    check for matching
    if match then return its index
    */
    int i = 0;
    while(i < 5) {
        if(types[i] == type)
            return i;
        i++;
    }

    /* if not found then return -1 */
    return -1;
}
