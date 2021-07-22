#include <stdio.h>
#include <sys/socket.h>
#include <netdb.h>

int main (int argc, char *argv[]){
    if (argc<2)
    {
        printf("Mode Use: ./portscan 192.168.2.1\n");
    }
    
    else {
   
        int meusocket;
        int conecta;

        int porta;
        int inicio = 1;
        int final = 65535;
        char *destino;
        destino = argv[1];

        struct sockaddr_in alvo;

        for(porta=inicio;porta<final;porta++){

            meusocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
            alvo.sin_family = AF_INET;
            alvo.sin_port = htons (porta);
            alvo.sin_addr.s_addr = inet_addr(destino); 

            conecta = connect(meusocket, (struct sockaddr *)&alvo, sizeof alvo);

            if(conecta == 0){
                printf("Port %d - [OPEN]\n",porta);
                close(meusocket);
                close(conecta);
            }
            else{
                close(meusocket);
                close(conecta);
            }
        }
    }
}