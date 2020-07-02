#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <sys/unistd.h>
#include <netinet/in.h>
#include <sys/time.h>
#include <iostream>
#include <string.h>
//#include "tracer.h"

using namespace std;


int main(void)
{


    printf("AF_INET\n");
    //create unix socket
    socklen_t connect_fd;
    connect_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(connect_fd < 0) {
        perror("cannot create communication socket");
        return 1;
    }

    struct sockaddr_in srv_addr;
    srv_addr.sin_family = AF_INET;
    srv_addr.sin_port = htons(8050);
    srv_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    //connect server
    socklen_t ret;
    ret = connect(connect_fd, (struct sockaddr*)&srv_addr, sizeof(srv_addr));
    if(ret == -1) {
        perror("cannot connect to the server");
        close(connect_fd);
        return 1;
    }


    while(true){
        char buf[100];
        cin >> buf;
        int rt = write(connect_fd,buf,strlen(buf));
        cout << "rt:" << rt << endl;

    }

}

