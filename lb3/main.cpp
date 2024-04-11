#include <iostream>
#include <signal.h>
#include <syslog.h>
#include <unistd.h>

using namespace std;

void daemonize() {
    pid_t pid = fork();

    if (pid < 0) {
        cerr << "Failed to fork" << endl;
        exit(1);
    }

    if (pid > 0) {
        exit(0); // Parent process exits
    }

    // Unlink from the controlling terminal
    setsid();

    // Change the working directory
    chdir("/");

    // Close standard output and error descriptors
    fclose(stdout);
    fclose(stderr);

    // Open new standard output and error descriptors to /dev/null
    stdout = fopen("/dev/null", "w");
    stderr = fopen("/dev/null", "w");

    // Initialize syslog
    openlog("mydaemon", LOG_PID, LOG_LOCAL0);
}

void signalHandlerUSR1(int signal) {
    syslog(LOG_INFO, "Received SIGUSR1 signal");
}

void signalHandlerINT(int signal) {
    syslog(LOG_INFO, "Received SIGINT signal, terminating");
    closelog();
    exit(0);
}

int main() {
    daemonize();

    signal(SIGUSR1, signalHandlerUSR1);
    signal(SIGINT, signalHandlerINT);

    syslog(LOG_INFO, "Daemon started");

    while (true) {
        sleep(1); // Do some work here
    }

    return 0;
}
