#include "minishell.h"

t_ast_node  *expand_node(t_ast_node *node)
{
    if (node->type == AST_CMD)
        expand_command(node);//expand the command node
    else if (node->type == AST_REDIRECT)
        expand_redirect(node);//expand the redirect node
    return (node);
}
//expand the command node
void    expand_command(t_ast_node *node)
{
    char **args;
    t_list *expanded_args;//rename to args_ll

    expanded_args = NULL;
    args = node->u_data.cmd.args;
    while (*args)
    {
        //expand one argument
        //add the expanded argument to the linked list
    }
    //convert the linked list to an array
    //free the linked list
}

//expand the redirect node except heredoc
void    expand_redirect(t_ast_node *node)
{
    char *file;
    t_list *expanded_args;//rename to files_ll

    if (node->u_data.redirect.type == TOKEN_HEREDOC)
        return;
    expanded_args = NULL;
    file = node->u_data.redirect.file;
    //expand one argument --> should give exactly one non empty word
    //add the expanded argument to the linked list
    // if linked list anything other than one word || it is ""
    //  return error
    //else
    node->u_data.redirect.file = expanded_args->content;
    //free the linked list
}



