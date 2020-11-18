/*
* This program check return statement
* Input: line number, return statement
* Output: report error
* Line: 40
*/

void check_return(int line, string s)
{
    int index;
    string str;

    /*
    * check spelling mistake of return
    */
    if(s[6] == ' ' || s[6] == ';');
    else
        cout << "Line " << line << " :\tspelling mistake\n" << endl;

    /* search for semicolon */
    index = s.find_first_of(';');

    if(index == -1)
        cout << "Line " << line << " :\tinsert a semicolon\n" << endl;

    /*
    * if semicolon found then check whether
    * there is extra character after semicolon
    */
    else {

        /* take extra character after semicolon if found */
        str = s.substr(index + 1);
        str = erase_first_last_space(str);

        /* if extra character found then report error */
        if(str != "")
            cout << "Line " << line << " :\tunexpected character after semicolon\n" << endl;
    }
}
