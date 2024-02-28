/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:58:17 by blarger           #+#    #+#             */
/*   Updated: 2024/02/24 10:52:28 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

//Error message
# define MALLOC_FAIL	"Malloc allocation failed.\n"
# define ARG			"The input must have four parameters.\n"
# define OPEN_PIPE		"Error opening pipe."
# define FORK			"Fork failed to be created.\n"	
# define DUP2			"dup2 failed to create the duplication.\n"
# define EXEC_FAIL		"sh: command not found: "
# define ENV			"Can't find the environment"
# define COM			"zsh: command not found: "
# define FILE			"zsh: no such file or directory: "
# define PIPE			"Pipe creation failed."
# define WAIT			"waitpid function failed to resume parent process.\n"
# define CHILD			"Child process terminated abnormally\n"
# define PERM			"zsh: permission denied: "

#endif