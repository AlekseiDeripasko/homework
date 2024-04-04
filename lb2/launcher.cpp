#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <cstring>
#include <sys/wait.h>

void launch_sync(const char* executable) {
    pid_t pid = fork();
    if (pid < 0) {
        std::cerr << "Failed to fork!" << std::endl;
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        char cwd[1024];
        if (getcwd(cwd, sizeof(cwd)) == NULL) {
            std::cerr << "Failed to get current directory!" << std::endl;
            exit(EXIT_FAILURE);
        }
        setenv("PATH", cwd, 1);
        execlp(executable, executable, nullptr);
        std::cerr << "Failed to execute " << executable << std::endl;
        exit(EXIT_FAILURE);
    } else {
        int status;
        waitpid(pid, &status, 0);
        std::cout << executable << " finished with exit code: " << WEXITSTATUS(status) << std::endl;
    }
}

void launch_async(const char* executable) {
    pid_t pid = fork();
    if (pid < 0) {
        std::cerr << "Failed to fork!" << std::endl;
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        char cwd[1024];
        if (getcwd(cwd, sizeof(cwd)) == NULL) {
            std::cerr << "Failed to get current directory!" << std::endl;
            exit(EXIT_FAILURE);
        }
        setenv("PATH", cwd, 1);
        execlp(executable, executable, nullptr);
        std::cerr << "Failed to execute " << executable << std::endl;
        exit(EXIT_FAILURE);
    } else {
        std::cout << "Launched " << executable << " asynchronously." << std::endl;
    }
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " [-w/-f] executable_name" << std::endl;
        return EXIT_FAILURE;
    }
    
    const char* option = argv[1];
    const char* executable = argv[2];
    
    if (strcmp(option, "-w") == 0) {
        std::cout << "Launching " << executable << " synchronously..." << std::endl;
        launch_sync(executable);
    } else if (strcmp(option, "-f") == 0) {
        launch_async(executable);
    } else {
        std::cerr << "Invalid option. Use -w for synchronous launch or -f for asynchronous launch." << std::endl;
        return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;
}
