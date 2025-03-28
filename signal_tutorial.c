/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_tutorial.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 22:09:05 by nando             #+#    #+#             */
/*   Updated: 2025/03/27 17:53:05 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _POSIX_C_SOURCE 200809L
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

//void timer_handler(int sig) 
//{
//    (void)sig;
//    write(1, "Timer expired!\n", 15);
//	exit(0);
//}

//int main(void) 
//{
//    struct sigaction timer_sa;
//    timer_sa.sa_handler = timer_handler;
//    timer_sa.sa_flags = 0;
//    sigemptyset(&timer_sa.sa_mask);

//    // SIGALRM に対してハンドラを設定
//    if (sigaction(SIGALRM, &timer_sa, NULL) == -1)
//    {
//        perror("sigaction");
//        exit(EXIT_FAILURE);
//    }
//    // 5秒後に SIGALRM が送られるように設定
//    alarm(5);
//    printf("Alarm set for 5 seconds. PID: %d\n", getpid());
//    // シグナル待機ループ
//    while (1)
//        pause();
//    return 0;
//}


// SA_SIGINFO を使ったシグナルハンドラ
void siginfo_handler(int sig, siginfo_t *info, void *ucontext) {
    (void)ucontext;
    printf("Received signal %d from process %d\n", sig, info->si_pid);
}

int main(void) {
    struct sigaction siginfo_sa;
    // 拡張ハンドラを使うため、sa_sigaction に関数ポインタを設定
    siginfo_sa.sa_sigaction = siginfo_handler;
    
    // SA_SIGINFO を指定することで、3引数版のハンドラが呼ばれる
    siginfo_sa.sa_flags = SA_SIGINFO;
    sigemptyset(&siginfo_sa.sa_mask);
    
    // SIGUSR1 に対して設定を適用
    if (sigaction(SIGUSR1, &siginfo_sa, NULL) == -1) 
    {
         perror("sigaction");
         exit(EXIT_FAILURE);
    }
    printf("Process PID: %d\n", getpid());
    printf("Waiting for SIGUSR1...\n");
    
    kill(getpid(), SIGUSR1);
    
    while (1) 
        pause();
    return 0;
}

