simple shell project by OMAREID0 & ahmed2103

shell should work like this in interactive mode:

$ ./hsh
($) /bin/ls
hsh main.c shell.c
_______________

also in non-interactive mode:

$ echo "/bin/ls" | ./hsh
hsh main.c shell.c
$
________________

shell will be compiled this way:

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
________________

