/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esotska <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 12:34:58 by esotska           #+#    #+#             */
/*   Updated: 2023/05/17 14:25:50 by esotska          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/wait.h>

int	main(int argc, char *argv[], char *env[])
{
	int	fd[2];
	
	if (argc < 3)
	{
		printf("To few arguments");
	}
	char	*file;
	char	*command;
	
	file = argv[1];
	command = argv[2];
	int pid = fork();
    //error if couldn't fork
    if (pid == -1)
    {
        return 1;
    }
    if (pid == 0)
    {
        //int testfile = open(file, O_RDONLY, 0777);
        char *args[] = {"/bin/ls","-l", NULL};
        int result = execve("/bin/ls", args, env);
        if (result == -1) {
            printf("Failed to execute the command.\n");
            return 1;
         }
        //close(testfile);
    }
    if (pid != 0)
    {
        wait(NULL);
    }
    return (0);
}