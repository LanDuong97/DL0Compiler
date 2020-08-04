#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_IDENT_LEN 10
#define MAX_LINE_LEN 128

void List_token(char *str)
{
    if (strcmp(str, "Begin") == 0)
    {
        printf("BEGIN");
    }
    else if (strcmp(str, "Call") == 0)
    {
        printf("CALL");
    }
    else if (strcmp(str, "Const") == 0)
    {
        printf("CONST");
    }
    else if (strcmp(str, "Do") == 0)
    {
        printf("DO");
    }
    else if (strcmp(str, "End") == 0)
    {
        printf("END");
    }
    else if (strcmp(str, "Else") == 0)
    {
        printf("ELSE");
    }
    else if (strcmp(str, "For") == 0)
    {
        printf("FOR");
    }
    else if (strcmp(str, "If") == 0)
    {
        printf("IF");
    }
    else if (strcmp(str, "Odd") == 0)
    {
        printf("ODD");
    }
    else if (strcmp(str, "Procedure") == 0)
    {
        printf("PROCEDURE");
    }
    else if (strcmp(str, "Program") == 0)
    {
        printf("PROGRAM");
    }
    else if (strcmp(str, "Then") == 0)
    {
        printf("THEN");
    }
    else if (strcmp(str, "To") == 0)
    {
        printf("TO");
    }
    else if (strcmp(str, "Var") == 0)
    {
        printf("VAR");
    }
    else if (strcmp(str, "While") == 0)
    {
        printf("WHILE");
    }
    else if (strcmp(str, "Read") == 0)
    {
        printf("READ");
    }
    else if (strcmp(str, "Readln") == 0)
    {
        printf("READLN");
    }
    else if (strcmp(str, "Write") == 0)
    {
        printf("WRITE");
    }
    else if (strcmp(str, "Writeln") == 0)
    {
        printf("WRITELN");
    }
    else if (strcmp(str, "+") == 0)
    {
        printf("PLUS");
    }
    else if (strcmp(str, "-") == 0)
    {
        printf("MINUS");
    }
    else if (strcmp(str, "*") == 0)
    {
        printf("MULTIPLY");
    }
    else if (strcmp(str, "/") == 0)
    {
        printf("DIVISION");
    }
    else if (strcmp(str, "%") == 0)
    {
        printf("PERCENT");
    }
    else if (strcmp(str, "(") == 0)
    {
        printf("LPARENT");
    }
    else if (strcmp(str, ")") == 0)
    {
        printf("RPARENT");
    }
    else if (strcmp(str, "[") == 0)
    {
        printf("LBRACK");
    }
    else if (strcmp(str, "]") == 0)
    {
        printf("RBRACK");
    }
    else if (strcmp(str, ">") == 0)
    {
        printf("GRT");
    }
    else if (strcmp(str, "<") == 0)
    {
        printf("LSS");
    }
    else if (strcmp(str, "=") == 0)
    {
        printf("EQU");
    }
    else if (strcmp(str, ",") == 0)
    {
        printf("COMMA");
    }
    else if (strcmp(str, ";") == 0)
    {
        printf("SEMICOLON");
    }
    else if (strcmp(str, ":=") == 0)
    {
        printf("GRT");
    }
    else if (strcmp(str, ">=") == 0)
    {
        printf("GEQ");
    }
    else if (strcmp(str, "<=") == 0)
    {
        printf("LEQ");
    }
    else if (strcmp(str, ".") == 0)
    {
        printf("DOTS");
    }
    else if (strcmp(str, "<>") == 0)
    {
        printf("NEQ");
    }
    else if (strcmp (str, "") != 0)
    {
        printf("INDENT(%s)", str);
    }
    if (strcmp (str, "") != 0){
        printf("\n");
    }
}
int check(char *str)
{
    if (strlen(str) > MAX_IDENT_LEN)
    {
        printf("error: Too many symbol\n");
        return 0;
    }
    else if (strlen(str) == 0)
    {
        return 1;
    }
    else
    {
        size_t i = 0;
        for (i = 0; i < strlen(str); i++)
        {
            if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] == '+') || (str[i] == '-') || (str[i] == '*') || (str[i] == '/') || (str[i] == '%') || (str[i] == '(') || (str[i] == ')') || (str[i] == '[') || (str[i] == ']') || (str[i] == ',') || (str[i] == ';') || (str[i] == '.') || (str[i] >= '0' && str[i] <= '9') || (str[i] == 32) || (str[i] == '\n') || (str[i] == '<') || (str[i] == '>') || (str[i] == ':') || (str[i] == '='))
            {
                return 1;
            }else{
                printf("error: Invalid symbol\n");
                return 0;
            }
        }
        printf("error: Invalid symbol\n");
        return 0;
    }
}

int main()
{
    char line[MAX_LINE_LEN];
    char str[MAX_LINE_LEN];
    char str_temp[MAX_LINE_LEN];
    FILE *fptr = fopen("test.txt", "r");
    int line_no = 0;
    while (fgets(line, 1024, fptr) != NULL)
    {
        strncpy(str, line, strlen(line));
        line_no++;
        size_t i;
        int k = 0;
        int comment = 0;
        for (i = 0; i < strlen(str); i++)
        {
            /* If the character is a alphabetical or a number*/
            if (('/' == str[i]) && ('*' == str[i+1]))
            {
                comment = 1;
            }
            else if (('*' == str[i-1]) && ('/' == str[i]))
            {
                comment = 0;
                continue;
            }

            if (comment == 1) 
            {
                continue;
            }

            if ((('a' <= str[i]) && ('z' >= str[i])) || (('A' <= str[i]) && ('Z' >= str[i])) || (('0' <= str[i]) && ('9' >= str[i])))
            {
                
            }
            else
            {
                if (((str[i] == '=') && ((':' == str[i - 1]) || ('<' == str[i - 1]) || ('>' == str[i - 1]))) || ((str[i] == '>') && (str[i - 1] == '<')))
                {
                }
                else
                {
                    str_temp[k] = '\0';
                    if (check(str_temp) == 0)
                    {
                        printf("%s", line);
                        int index = i - k;
                        while (index--)
                        {
                            printf(" ");
                        }
                        printf("^\n");
                        printf("Line: %d - Column: %ld\n", line_no, i + 1 - k);
                        return 0;
                    }
                    List_token(str_temp);
                    memset(str_temp, 0, MAX_LINE_LEN);
                    k = 0;
                }
            }
            if (str[i] != 32 && str[i] != '\n')
            {
                str_temp[k] = str[i];
                k++;
            }
            if ('(' == str[i] || ',' == str[i] || '>' == str[i])
            {
                str_temp[k] = '\0';
                if (check(str_temp) == 0)
                {
                    printf("%s", line);
                    int index = i - k;
                    while (index--)
                    {
                        printf(" ");
                    }
                    printf("^\n");
                    printf("Line: %d - Column: %ld\n", line_no, i + 1 - k);
                    return 0;
                }
                List_token(str_temp);
                memset(str_temp, 0, MAX_LINE_LEN);
                k = 0;
            }
        }
        str_temp[k] = '\0';
        if (check(str_temp) == 0)
        {
            printf("%s", line);
            int index = i - k;
            while (index--)
            {
                printf(" ");
            }
            printf("^\n");
            printf("Line: %d - Column: %ld\n", line_no, i + 1 - k);
            return 0;
        }
        List_token(str_temp);
        memset(str_temp, 0, MAX_LINE_LEN);
        k = 0;
        memset(line, 0, MAX_LINE_LEN);
        memset(str, 0, MAX_LINE_LEN);
    }
    fclose(fptr);
    return 0;
}