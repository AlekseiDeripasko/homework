#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>

int main(int argc, char* argv[]) {
    std::cout << "Command line arguments:";
    for (int i = 0; i < argc; ++i) {
        std::cout << " " << argv[i];
    }
    std::cout << std::endl;
    
    std::cout << "Process ID (pid): " << getpid() << std::endl;
    std::cout << "Session ID (sid): " << getsid(0) << std::endl;
    std::cout << "Process Group ID (pgid): " << getpgid(0) << std::endl;
    std::cout << "Parent Process ID (ppid): " << getppid() << std::endl;
    
    struct passwd *pw = getpwuid(getuid());
    std::cout << "Username: " << pw->pw_name << std::endl;
    
    struct group *gr = getgrgid(getgid());
    std::cout << "Group name: " << gr->gr_name << std::endl;
    
    return 0;
}

