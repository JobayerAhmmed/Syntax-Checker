/*
* This program check else statement
* Input: line number, line
* Output: report error
* Line: 25
*/

void check_else(int line, string s)
{
    string str;

    /* take portion after else */
    str = s.substr(4);
    str = erase_first_last_space(str);

    /* if { found then store it in the stack */
    if(str == "{")
        mystack.push('{');

    /* if unexpected character then report */
    else if(str != "")
        cout << "Line " << line << " :\tunexpected character after \'else\'\n" << endl;
}
