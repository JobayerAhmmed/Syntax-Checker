/*
** This program check the validity of variable names
** Output: report errors if variable name
**         does not fulfill the convention
**          and return -1
** Line: 85
*/

/* check the variable name */
int check_name(int line, string name)
{
    /* reserved 32 standard keywords of C */
    string standard_keyword[] = {"auto", "double", "int", "struct", "break", "else", "long", "switch",
                                "case", "enum", "register", "typedef ", "char", "extern", "return",
                                "union", "const", "float", "short", "unsigned", "continue", "for",
                                "signed", "void", "default", "goto", "sizeof", "volatile", "do",
                                "if", "static", "while"};

    /* valid letters in naming */
    string valid_letter = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_$";

    /* if variable name found in standard keyword
       then report error */
    for(int i = 0; i < 32; i++) {

        if(name == standard_keyword[i]) {
            cout << "Line " << line << " :\t" << "keyword \'" << name <<
                "\' can not be a variable or function name\n" << endl;
            return -1;
        }
    }

    /* if variable name started with a letter out of a-z, A-Z, _, $
       then report error */
    if(name[0] > 64 && name[0] < 91 ||
       name[0] > 96 && name[0] < 123 || name[0] == 95 || name[0] == 36) {
        ;
    }
    else {
        cout << "Line " << line << " :\t\'" << name <<
            "\' started with unqualified character\n" << endl;
        return -1;
    }

    /* if variable name contains a letter out of a-z, A-Z, 0-9, _, $
       then report error */
    int i = 1;
    while(name[i]) {

        /* check each character of name for validity
           if not match then report error */
        if(check_character(name[i], valid_letter) == -1) {
            cout << "Line " << line << " :\t\'" << name << "\' contains unqualified character\n" << endl;
            return -1;
        }
        i++;
    }

    return 0;
}

/*
* This program check the validity of a name
* Input: string
* Output: 0 or -1
*/

int verify_name(string name)
{
    /* valid letters in naming */
    string valid_letter = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_$";

    /* if variable name contains a letter out of a-z, A-Z, 0-9, _, $
       then return -1 */
    int i = 0;
    while(name[i]) {

        /* check each character of name for validity */
        return check_character(name[i], valid_letter);

        i++;
    }
}
