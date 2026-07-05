bool isValid(char* s) {
    int n = strlen(s);

    // Odd length can never be valid
    if (n % 2 != 0)
        return false;

    char* stack = (char*)malloc(n * sizeof(char));
    int top = -1;

    for (int i = 0; i < n; i++) {

        char c = s[i];

        if (c == '(')
            stack[++top] = ')';
        else if (c == '[')
            stack[++top] = ']';
        else if (c == '{')
            stack[++top] = '}';
        else {

            if (top == -1 || stack[top] != c) {
                free(stack);
                return false;
            }

            top--;
        }
    }

    bool ans = (top == -1);

    free(stack);
    return ans;
}