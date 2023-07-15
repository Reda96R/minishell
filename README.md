# ::: Minishell :::
`This project is about creating a simple shell. Yes, your own little bash. You will learn a lot about processes and file descriptors.`

## Project overview :
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
The first thing we needed to know in order to tackle the project, is the functioning of Bash.

### What is bash?
bash or *Bourne Again Shell* is a  free and enhanced version of the [Bourne shell](https://searchdatacenter.techtarget.com/definition/Bourne-shell) which is a type of computer program called a command-line interpreter that lets Linux and Unix users control their operating systems with command-line interfaces. Shells allow users to communicate efficiently and directly with their operating systems

### How it works?
At its core, Bash acts as a translator, transforming human-readable commands into actions understood by the operating system, it first starts with the **lexer**, it scans the input and breaks it into tokens, while the **parser** analyzes the tokens' syntax and builds an abstract syntax tree (AST). The **expander** resolves variables, expands expressions, and substitutes commands within the AST. Finally, the **executor** traverses the modified AST, executing the commands, performing variable substitutions, handling I/O redirection, and managing control flow. Together, these stages ensure that Bash can process commands and scripts by tokenizing, parsing, expanding, and executing them in a systematic manner.
here's a little demonstration of what we said,

```
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

