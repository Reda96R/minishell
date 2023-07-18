# ::: Minishell_42 :::
`This project is about creating a simple shell. Yes, your own little bash. You will learn a lot about processes and file descriptors.`

## Project overview:
In this project we'll need to implement our own mini-shell that will consist of some basic features from bash which are:
- Display a prompt while waiting for a new command.
- Have a working history.
- Find and launch executables (using the `PATH` variable or an absolute path).
- Handle `'` (single) and `"` (double) **quotes** like in bash.
- Implement **redirections** such as:
    - `<` redirect input.
    - `>` redirect output.
    - `<<` heredoc (doesn't affect history).
    - `>>` redirect output in append mode.
- Implement `|` (**pipes**).
- Handle **environment variables**.
- Handle `$?`.
- `ctrl-C`, `ctrl-D`, and `ctrl-\` should behave like in bash.
- Recreate the following **builtins**:
    - `echo` with option `-n`.
    - `cd` with only a relative or absolute path.
    - `pwd` (no flags).
    - `export` (no flags).
    - `unset` (no flags).
    - `env` (no flags or arguments).
    - `exit` (no flags).
you can check the [subject](https://github.com/Reda96R/minishell/blob/main/minishell.sub.pdf) for more information.

## Background theory:
The first thing we need to know in order to tackle this project, is the functioning of Bash.

### What is bash?
bash or *Bourne Again Shell* is a  free and enhanced version of the [Bourne shell](https://searchdatacenter.techtarget.com/definition/Bourne-shell) which is a type of computer program called a command-line interpreter that lets Linux and Unix users control their operating systems with command-line interfaces. Shells allow users to communicate efficiently and directly with their operating systems

### How does it work?
At its core, Bash acts as a translator, transforming human-readable commands into actions understood by the operating system, it first starts with the **lexer**, it scans the input and breaks it into tokens, while the **parser** analyzes the tokens' syntax and builds an abstract syntax tree (AST). The **expander** resolves variables, expands expressions, and substitutes commands within the AST. Finally, the **executor** traverses the modified AST, executing the commands, performing variable substitutions, handling I/O redirection, and managing control flow. Together, these stages ensure that Bash can process commands and scripts by tokenizing, parsing, expanding, and executing them in a systematic manner.
here's a little demonstration of what we said,

```bash
Input:
---------------
$ echo "Hello, World!"

Lexer:
---------------
Tokens: [ "$", "echo", "Hello,", "World!", "!" ]

Parser:
---------------
      Command
       /    \
    echo  "Hello, World!"
     
Expander:
---------------
         Command
            |
         "Hello, World!"

Executor:
---------------
Output: Hello, World!
```
if you want to deep dive in how the bash works you can check [this](https://www.cs.purdue.edu/homes/grr/SystemsProgrammingBook/Book/Chapter5-WritingYourOwnShell.pdf).

## Making the code:
We will start by parsing the environment variables, but first let's take a look at our structs, mainly we'll have four structs, but let's focus on what we'll use now,
```c
/* this is the main struct that will contain all the data that we'll need */
typedef struct s_data
{
	char    **vars; //will contain our env vars
	char    **paths; //will contain the paths fetched from env vars
	char    *pwd; //current working dir
	char    *old_pwd; // old working dir
	char    *input; // user's input
	int     color; // an int value to determine the prompt color R or G
	int     pipes; // a count for all the existing pipes
	t_mylxr *mylexer; // a pointer to the lexer struct
	t_cmds  *cmds; // a pointer to the commands struct
} t_data;
/*---------------------------------------------------------------------*/

/* this struct reprersents the nodes of a linked list containing the input where each node contains a word/cmd/token */
typedef struct s_mylxr
{
	char    *str; // a word/cmd or a token
	int     node_id // the id of the node in the linked list 
	int     token_id; // token id if it is non null then it is a tkoen
	struct s_mylxr *next; // pointer to the next node
	struct s_mylxr *prerv; // pointer to the prervious node
} t_mylxr;
/*---------------------------------------------------------------------*/

/* this struct is for the commands, it contains infos about each cmd in the linked list */
typedef struct s_cmds
{
	char    **str; // the command and its args
	char    *herdoc; // the herdoc if it exists
	t_mylxr *redirections; // a pointer to the lxr struct for the redirections
	int     redirections_count; // a count for all existing redirections
	struct s_cmds *next; // pointer to the next node
	struct s_cmds *next; // pointer to the previous node
}
/*---------------------------------------------------------------------*/
```

> **token_id** is a simple int that is 0 if the node containing a cmd/word or a non null value if it is a token, each token has its own id and they're specified in [macros.h](https://github.com/Reda96R/minishell/blob/main/src/includes/parsing/macros.h).

### Environment variables:
now let's parse our env vars, this step is somewhere close to what we did before in [pipex](https://github.com/Reda96R/pipex), so it might be useful to check it out.
`ft_env_setter()` is our starting point here, in which we start by allocating enough memory to store all env vars in `data->vars`, then we search in the stored vars for `PWD` and `OLDPWD` variables, they contain respectively the current and the old working directory, and it's now turn for the paths, which we'll get using `ft_paths_parser()` that gets the `PATH` var using [`ft_path_finder()`](https://en.wikipedia.org/wiki/Nissan_Pathfinder), it then splits the paths by `:` and stores the final result in `data->paths` and by this the part of environment variables is done, **or is it?**

![nick-lang-tcb](https://github.com/Reda96R/minishell/assets/59890802/a2060ef4-0142-4560-8c69-a8b48c8e7af9)

### Starting the shell:
before diving into the code of how the core shell works, I would like to explain how the program looks from a bird's eye view,




