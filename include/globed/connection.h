/*
This is for future Netcode for GDWii
Does not work right now but gameplay comes first
*/

#ifndef CONNECTION_H
#define CONNECTION_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <ogcsys.h>
#include <gccore.h>
#include <network.h>
#include <wiiuse/wpad.h>
#include <debug.h>

void *httpd(void* arg) {
    int sock, csock;
	int ret;
	u32	clientlen;
	struct sockaddr_in client;
	struct sockaddr_in server;
	char temp[1026];
	static int hits=0;

	clientlen = sizeof(client);

	sock = net_socket (AF_INET, SOCK_STREAM, IPPROTO_IP);

	if (sock == INVALID_SOCKET) {
      printf ("Cannot create a socket!\n");
    } else {

		memset (&server, 0, sizeof (server));
		memset (&client, 0, sizeof (client));

		server.sin_family = AF_INET;
		server.sin_port = htons (80);
		server.sin_addr.s_addr = INADDR_ANY;
		ret = net_bind (sock, (struct sockaddr *) &server, sizeof (server));

		if ( ret ) {

			printf("Error %d binding socket!\n", ret);

		} else {

			if ( (ret = net_listen( sock, 5)) ) {

				printf("Error %d listening!\n", ret);

			} else {

				while(1) {

					csock = net_accept (sock, (struct sockaddr *) &client, &clientlen);

					if ( csock < 0 ) {
						printf("Error connecting socket %d!\n", csock);
						while(1);
					}

					printf("Connecting port %d from %s\n", client.sin_port, inet_ntoa(client.sin_addr));
					memset (temp, 0, 1026);
					ret = net_recv (csock, temp, 1024, 0);
					printf("Received %d bytes\n", ret);

					net_close (csock);

				}
			}
		}
	}
	return NULL;
}

namespace GDWii {
    class Network {
    public:
        s32 interface;
        lwp_t httd_handle = (lwp_t)NULL;

        char localip[16] = {0};
        char gateway[16] = {0};
        char netmask[16] = {0};

        void req(void* arg) {
            httpd(arg);
        }

        void init() {
            interface = if_config(localip, netmask, gateway, true, 20);
            if (interface >= 0) {
                printf("network configured, IP: %s, gw: %s, mask: %s\n", localip, gateway, netmask);
                LWP_CreateThread(&httd_handle, httpd, localip, NULL, 64*1024, 50);
            } else {
                printf("network config failed\n");
            }
        }
    };
}

#endif