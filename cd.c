
char *remove_quotes()

int path(char *cd, char *command)
{
    char *temp;

    temp = remove_quotes(command);
    if (temp == "--")
    {
        chdir(env($OLDPWD));
        return 0;
    }
    chdir(temp);
    if (!chdir(temp))
        printf("No such file or directory!"); //falta imprimir por error
    else
    {
        free(temp);
        //cambiar oldpwd a pwd actual
    }
}

int main(int argc, char **argv)
{
    if (argc == 2) //solo ponen cd
        chdir(env($HOME));
    else if (argc == 3) //ponen cd y algo
        path(argv[1], argv[2]);

}