
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

//char *remove_quotes()

int path(char *cd, char *command)
{
    char *temp;

    //temp = remove_quotes(command);
    if (!strncmp(temp, "-", 2))
    {
        chdir(getenv("OLDPWD"));
        return 0;
    }
    chdir(temp);
    if (!chdir(temp))
        printf("No such file or directory!"); //falta imprimir por error
    else
    {
        free(temp);
        //cambiar oldpwd a pwd actual
        return 0;
    }
    free(temp);
    return 1;
}

int main(int argc, char **argv)
{
    if (argc == 2) //solo ponen cd
    {
        chdir(getenv("HOME"));
    }
    else if (argc == 3) //ponen cd y algo
        path(argv[1], argv[2]);
    else if (argc >= 3)
        printf("error: too many arguments") //aqui debería hacer un printerror y así puedo cambiar la salida al numero de error

}