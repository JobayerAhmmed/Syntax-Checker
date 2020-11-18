/*
    This program find the required shift to match a pattern.
    Useful for a pattern of fixed and small in size.
    kmp(): BigTheta(n);
    prefixFunction(): BigTheta(n);

    Output: return the index of the first
            character where the pattern matched
    Line: 60
*/

/*find the match within itself*/
void prefixFunction(string P, int *F)
{
    int q;
    int m = P.length();

    F[0] = 0;
    q = 0;

    for(int i = 1; i < m; i++) {

        while(q > 0 && P[q] != P[i])
            q = F[q];

        if(P[q] == P[i])
            q++;

        F[i] = q;
    }
}

/* search for the pattern */
int kmp(string P, string T){

    int m = P.length(); // length of the pattern
    int n = T.length(); // length of text
    int F[m];   // values of failure function
    int q;      // counter of matching characters

    prefixFunction(P, F);

    q = 0;  // number of characters matched

    /* scan the text from left to right */
    for(int i = 0; i < n; i++) {

        while(q > 0 && P[q] != T[i])
            q = F[q];   // next character does not match

        if(P[q] == T[i])
            q++;    // next character matches

        if(q == m) {    // all of P[] match
            return (i+1)-m; // if found then return its index
            //q = F[q-1];
        }
    }

    /* if not found then return -1 */
    return -1;
}

