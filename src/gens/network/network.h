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
int (*Network_Update_Frame)();
/**
 * Saves the configuration to the given file.
 * It is called by the Save_Config function.
 * @param conf_file the configuration file
 */
void Network_Save_Config(char *conf_file);
/**
 * Load the configuration from the given file.
 * It is called by the Load_Config function.
 * @param conf_file the configuration file
 */
void Network_Load_Config(char *conf_file);
/**
 * Converts an integer to a string.
 * It is called by the Network_Create_Window_Network_Port function.
 * @param integer the integer
 * @return the string
 */
char *Network_Integer_To_String(int integer);
/**
 * Appends the source string to the destination string.
 * It is called by the Network_Create_Window_Network function.
 * @param dest the destination string
 * @param src the source string
 * @return the new string containing the source and the destination
 */
char *Network_Concatenate_Strings(const char *dest, const char *src);
/**
 * The callback function.
 * It is called by the Network_Create_Window and Network_Create_Window_Network functions.
 * @param widget the widget
 * @param user_data the user data
 */
void Network_Set_Value(GtkWidget *widget, gpointer user_data);
/**
 * Creates a window containing an entry and two buttons.
 * It is called by the Network_Create_Window_Network_Address and Network_Create_Window_Network_Port functions.
 * @param name the name of the window
 * @param entry_text the text of the entry
 */
void Network_Create_Window_Network(const char *name, const char *entry_text);
/**
 * Creates a window containing an entry and two buttons for the network address.
 * It calls the Network_Create_Window_Network function.
 */
void Network_Create_Window_Network_Address(void);
/**
 * Creates a window containing an entry and two buttons for the network port.
 * It calls the Network_Integer_To_Array and Network_Create_Window_Network functions.
 */
void Network_Create_Window_Network_Port(void);
void Network_Create_Window(GtkWidget *Network_Window);
int Network_Do_Frame(void);
void Network_Update_Emulation(void);
Network_Data_T Network_GetData1(void);
Network_Data_T Network_GetData2(void);
void Network_SetData1(Network_Data_T);
void Network_SetData2(Network_Data_T);
