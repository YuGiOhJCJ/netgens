/*
   Copyright 2013 YuGiOhJCJ

   This file is part of Netgens.

   Netgens is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   Netgens is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with Netgens.  If not, see <http://www.gnu.org/licenses/>.
*/
#include<SDL/SDL_net.h> /* for TCPsocket */
#include <gtk/gtk.h> /* for GtkWidget */
typedef struct
{
	unsigned int Controller_1_Type;
	unsigned int Controller_1_State;
	unsigned int Controller_1_COM;
	unsigned int Controller_1_Counter;
	unsigned int Controller_1_Delay;
	unsigned int Controller_1_Up;
	unsigned int Controller_1_Down;
	unsigned int Controller_1_Left;
	unsigned int Controller_1_Right;
	unsigned int Controller_1_Start;
	unsigned int Controller_1_Mode;
	unsigned int Controller_1_A;
	unsigned int Controller_1_B;
	unsigned int Controller_1_C;
	unsigned int Controller_1_X;
	unsigned int Controller_1_Y;
	unsigned int Controller_1_Z;
} Network_Data_T;
extern char Network_Mode[1024];
extern char Network_Address[1024];
extern int Network_Port;
extern TCPsocket Network_Server_Tcpsocket;
extern TCPsocket Network_Tcpsocket;
void Network_Save_Config(char* Conf_File);
void Network_Load_Config(char* Conf_File);
char* Network_Integer_To_Array(int Integer);
void Network_Set_Value(GtkWidget* Menu_Item, gpointer User_Data);
void Network_Create_Window_Network_Address(void);
void Network_Create_Window_Network_Port(void);
void Network_Create_Window(GtkWidget* Network_Window);
int Network_Do_Genesis_Frame(void);
void Network_Do(void);
Network_Data_T Network_GetData1(void);
Network_Data_T Network_GetData2(void);
void Network_SetData1(Network_Data_T);
void Network_SetData2(Network_Data_T);
