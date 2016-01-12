
#include <stdio.h>
#include <stdlib.h>

#include "mpc.h"

#ifdef _WIN32
#include <string.h>

static char* buffer[2048];

char* readline(char* prompt)
{
    fputs(prompt, stdout);
    fgets(buffer, 2048, stdin);
    char* cpy = malloc(strlen(buffer) + 1);
    strcpy(cpy, buffer);
    cpy[strlen(cpy) - 1] = '\0';
    return cpy;
}

void add_history(char* unused) {}

#else
#include <editline/readline.h>
#include <editline/history.h>
#endif

char* eval(mpc_ast_t* t)
{
    if (strstr(t->tag, "heading"))
    {
        // TODO(Lane): Count the amount of hashes preceding the heading. ERROR \
           if this number is greater than six.
    }
    if (strstr(t->tag, "blockquote"))
    {
        char* blk = malloc(strlen(t->contents) + 26); // 26 is the size of the blockquote tags + 1 for the escape character
        strcpy(blk, "<blockquote>");
        strcat(blk, t->contents);
        strcat(blk, "</blockquote>");
        blk[strlen(blk) - 1] = '\0';
        return blk;
    }

}

int main(int argc, char** argv)
{
    mpc_parser_t* Symbol = mpc_new("symbol");
    mpc_parser_t* Link = mpc_new("link");
    mpc_parser_t* Block = mpc_new("block"); // Formatted block
    mpc_parser_t* Inline = mpc_new("inline"); // Inline formatting
    mpc_parser_t* List = mpc_new("list");
    mpc_parser_t* Blockquote = mpc_new("blockquote");
    mpc_parser_t* Heading = mpc_new("heading");
    mpc_parser_t* Paragraph = mpc_new("paragraph");
    mpc_parser_t* Markdown = mpc_new("markdown");

    mpca_lang(MPCA_LANG_DEFAULT,
        "                                                        \
          symbol: /[A-Za-z1-9_+\\-\\/\\\\=><\\.,:;!{}\\s]+/ ;    \
          link: '[' <symbol> ']' '(' /[A-Za-z1-9:\\/\\.]+/ ')' ; \
          block: '`' '`' '`' <symbol> '`' '`' '`' ;              \
          inline: '`' <symbol> '`' ;                             \
          list: ('-' | '*' <paragraph>)+ ;                       \
          blockquote: '>' <symbol> ;                             \
          heading: /#+/ <symbol> ;                               \
          paragraph: (<symbol> | <inline> | <link> /\\n/)+ ;     \
          markdown: /^/ (<paragraph> | <heading> | <blockquote> | <list> | <block>)* /$/ ; \
        ",
        Symbol, Link, Block, Inline, List, Blockquote, Heading, Paragraph, Markdown);

    while (1)
    {
        char* input = readline("MarkMyHTML> ");
        add_history(input);

        mpc_result_t r;
        if (mpc_parse("<stdin>", input, Markdown, &r))
        {
            mpc_ast_print(r.output);
            mpc_ast_delete(r.output);
        }
        else
        {
            mpc_err_print(r.error);
            mpc_err_delete(r.error);
        }
    }
    mpc_cleanup(9, Symbol, Link, Block, Inline, List, Blockquote, Heading,
        Paragraph, Markdown);

    return EXIT_SUCCESS;
}