// This application is under GNU GPLv3. Please read the COPYING.txt file for further terms and conditions of the license.
// Copyright © 2016 Matthew James 
// "Remote Terminal" is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// "Remote Terminal" is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
// You should have received a copy of the GNU General Public License along with "Remote Terminal". If not, see http://www.gnu.org/licenses/.

#include "server.h"

Server::Server(unsigned short int port, unsigned short int max_clients)
{
    this->num_clients = 0;

    SetMaxClients(max_clients);
    SetPort(port);
    SetLSocket();
    SetLProperties();
    LSocketBind();
    SocketsDisconnect();
}

Server::~Server() // Stop
{
    SocketsDisconnect();
    LSDisconnect();

    delete [] clients;
    clients = NULL;
}

unsigned short int Server::GetNumClients() const
{
    return num_clients;
}

unsigned short int Server::GetMaxClients() const
{
    return max_clients;
}

unsigned short int Server::GetCSocket() const
{
    return current_socket;
}

char* Server::GetCurrentIP() const
{
    return current_ip;
}

void Server::SetCSocket(unsigned short sock)
{
    current_socket = sock;
}

void Server::SetNumClients(const unsigned short &count)
{
    num_clients = count;
}

void Server::SetMaxClients(const unsigned short &count)
{
    max_clients = count;
    clients = new int[max_clients + 1];
}

void Server::SetCurrentIP(char *IP)
{
    current_ip = IP;
}

int Server::CheckConnection(const unsigned short int &index, fd_set rsd)
{
    return select(clients[index] + 1, &rsd, 0, 0, 0);
}

void Server::ResetSockets()
{
    for(unsigned short int i = 0; i <= max_clients; i++)
    {
        clients[i] = 0; // Null current socket by setting it to 0.
    }
}

unsigned int Server::GetMiliseconds()
{
    struct timeval tv; // Declare timeval
    /* structure definition of timeval is
     struct timeval {
          time_t      tv_sec;      seconds
          suseconds_t tv_usec;    microseconds
    };*/

    if (gettimeofday(&tv, NULL) != 0)
    {
        //gettimeofday() can get the time as well as a timezone
        return 0;
    }
    return (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
}

void Server::CloseSocket(unsigned short int index)
{
    if(clients[index] == -1)
    {
        clients[index] = 0; // Null global socket
    }
    else
    {
        close(clients[index]); // Close global socket
        clients[index] = 0; // Null global socket
    }
}

void Server::SocketsDisconnect()
{
    for(unsigned short int i = 0; i <= max_clients; i++)
    {
        if(clients[i] == -1)
        {
            clients[i] = 0; // Null global socket
        }
        else
        {
            close(clients[i]); // Close global socket
            clients[i] = 0; // Null global socket
        }
    }
}
