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
#include "network.h" /* for Network_* */
#include "io.h" /* for Controller_* */
#include "g_main.h" /* for MESSAGE_L */
#include "g_sdldraw.h" /* for Update_Frame */
#include "gens.h" /* for Do_VDP_Only */
#include <SDL/SDL_net.h> /* for TCPsocket and SDLNet_TCP_Accept */
#define GLADE_HOOKUP_OBJECT(component,widget,name) \
  g_object_set_data_full (G_OBJECT (component), name, \
    gtk_widget_ref (widget), (GDestroyNotify) gtk_widget_unref)
char Network_Mode[1024] = "disabled\0";
char Network_Address[1024] = "localhost\0";
int Network_Port = 5394;
TCPsocket Network_Server_Tcpsocket = NULL;
TCPsocket Network_Tcpsocket = NULL;
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
unsigned int Controller_2_Type;
unsigned int Controller_2_State;
unsigned int Controller_2_COM;
unsigned int Controller_2_Counter;
unsigned int Controller_2_Delay;
unsigned int Controller_2_Up;
unsigned int Controller_2_Down;
unsigned int Controller_2_Left;
unsigned int Controller_2_Right;
unsigned int Controller_2_Start;
unsigned int Controller_2_Mode;
unsigned int Controller_2_A;
unsigned int Controller_2_B;
unsigned int Controller_2_C;
unsigned int Controller_2_X;
unsigned int Controller_2_Y;
unsigned int Controller_2_Z;
void Network_Save_Config(char *conf_file)
{
	WritePrivateProfileString("Network", "Network mode", Network_Mode, conf_file);
	WritePrivateProfileString("Network", "Network address", Network_Address, conf_file);
	sprintf(Str_Tmp, "%d", Network_Port);
	WritePrivateProfileString("Network", "Network port", Str_Tmp, conf_file);
}
void Network_Load_Config(char *conf_file)
{
	GetPrivateProfileString("Network", "Network mode", "", &Network_Mode[0], 1024, conf_file);
	GetPrivateProfileString("Network", "Network address", "localhost", &Network_Address[0], 1024, conf_file);
	Network_Port = GetPrivateProfileInt("Network", "Network port", 9999, conf_file);
}
char *Network_Integer_To_String(int integer)
{
	int integer_new = 0;
	int len = 1;
	char *value = NULL;
	integer_new = integer / 10;
	while(integer_new != 0)
	{
		len++;
		integer_new = integer_new / 10;
	}
	value = malloc(sizeof(char) * len + 1);
	sprintf(value, "%d", integer);
	return value;
}
char *Network_Concatenate_Strings(const char *dest, const char *src)
{
	if(dest == NULL || src == NULL)
	{
		fprintf(stderr, "%s:%d: %s (The parameters are null)\n", __FILE__, __LINE__, __PRETTY_FUNCTION__);
		exit(EXIT_FAILURE);
	}
	int size = (strlen(dest)*sizeof(char)) + (strlen(src)*sizeof(char)) + 1;
	char *newdest = NULL;
	newdest = malloc(size);
	if(newdest == NULL)
	{
		fprintf(stderr, "%s:%d: %s (Unable to allocate dynamic memory)\n", __FILE__, __LINE__, __PRETTY_FUNCTION__);
		exit(EXIT_FAILURE);
	}
	sprintf(newdest, "%s%s\0", dest, src);
	return newdest;
}
void Network_Set_Value(GtkWidget *widget, gpointer user_data)
{
	if(strcmp(gtk_widget_get_name(widget), "Network item network mode server") == 0)
	{
		strcpy(Network_Mode, "server\0");
	}
	if(strcmp(gtk_widget_get_name(widget), "Network item network mode client") == 0)
	{
		strcpy(Network_Mode, "client\0");
	}
	if(strcmp(gtk_widget_get_name(widget), "Network item network mode disabled") == 0)
	{
		strcpy(Network_Mode, "disabled\0");
	}
	if(strcmp(gtk_widget_get_name(widget), "Network item network mode disabled") == 0)
	{
		strcpy(Network_Mode, "disabled\0");
	}
	if(strcmp(gtk_widget_get_name(widget), "Network button ok network address") == 0)
	{
		if(strlen(user_data) == 0)
			strcpy(Network_Address, "localhost");
		else
			strcpy(Network_Address, user_data);
	}
	if(strcmp(gtk_widget_get_name(widget), "Network button ok network port") == 0)
	{
		if(strlen(user_data) == 0)
			Network_Port = 5394;
		else
			Network_Port = atoi(user_data);
	}
}
void Network_Create_Window_Network(const char *name, const char *entry_text)
{
	gint Spacing = 5;
	char *widget_name = NULL;
	/* window network */
	widget_name = Network_Concatenate_Strings("Network window ", name);
	GtkWidget *Network_Window;
	Network_Window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_widget_set_name(Network_Window, widget_name);
	gtk_container_set_border_width(GTK_CONTAINER(Network_Window), Spacing);
	gtk_window_set_title(GTK_WINDOW(Network_Window), name);
	gtk_window_set_modal(GTK_WINDOW(Network_Window), TRUE);
	gtk_window_set_resizable(GTK_WINDOW(Network_Window), FALSE);
	free(widget_name);
	/* vbox network */
	widget_name = Network_Concatenate_Strings("Network vbox ", name);
	GtkWidget *Network_VBox;
	Network_VBox = gtk_vbox_new(FALSE, Spacing);
	gtk_widget_set_name(Network_VBox, widget_name);
	gtk_widget_show(Network_VBox);
	gtk_container_add(GTK_CONTAINER(Network_Window), Network_VBox);
	free(widget_name);
	/* entry network */
	widget_name = Network_Concatenate_Strings("Network entry ", name);
	GtkWidget *Network_Entry;
	Network_Entry = gtk_entry_new();
	gtk_widget_set_name(Network_Entry, widget_name);
	gtk_widget_show(Network_Entry);
	gtk_box_pack_start(GTK_BOX(Network_VBox), Network_Entry, TRUE, TRUE, 0);
	gtk_entry_set_text(GTK_ENTRY(Network_Entry), entry_text);
	free(widget_name);
	/* hbox network */
	widget_name = Network_Concatenate_Strings("Network hbox ", name);
	GtkWidget *Network_HBox;
	Network_HBox = gtk_hbox_new(TRUE, Spacing);
	gtk_widget_set_name(Network_HBox, widget_name);
	gtk_widget_show(Network_HBox);
	gtk_box_pack_start(GTK_BOX(Network_VBox), Network_HBox, TRUE, TRUE, 0);
	free(widget_name);
	/* button network cancel */
	widget_name = Network_Concatenate_Strings("Network button cancel ", name);
	GtkWidget *Network_Button_Cancel;
	Network_Button_Cancel = gtk_button_new_from_stock("gtk-cancel");
	gtk_widget_set_name(Network_Button_Cancel, widget_name);
	gtk_widget_show(Network_Button_Cancel);
	gtk_box_pack_start(GTK_BOX(Network_HBox), Network_Button_Cancel, FALSE, FALSE, 0);
	gtk_button_set_relief(GTK_BUTTON(Network_Button_Cancel), GTK_RELIEF_NONE);
	free(widget_name);
	/* button network ok */
	widget_name = Network_Concatenate_Strings("Network button ok ", name);
	GtkWidget *Network_Button_Ok;
	Network_Button_Ok = gtk_button_new_from_stock("gtk-ok");
	gtk_widget_set_name(Network_Button_Ok, widget_name);
	gtk_widget_show(Network_Button_Ok);
	gtk_box_pack_start(GTK_BOX(Network_HBox), Network_Button_Ok, FALSE, FALSE, 0);
	gtk_button_set_relief(GTK_BUTTON(Network_Button_Ok), GTK_RELIEF_NONE);
	free(widget_name);
	/* connect to the callback function */
	g_signal_connect((gpointer) Network_Button_Cancel, "clicked", G_CALLBACK(gtk_widget_destroy), NULL);
	g_signal_connect((gpointer) Network_Button_Ok, "clicked", G_CALLBACK(Network_Set_Value), (gpointer) gtk_entry_get_text(GTK_ENTRY(Network_Entry)));
	/* show */
	gtk_widget_show(Network_Window);
}
void Network_Create_Window_Network_Address(void)
{
	Network_Create_Window_Network("network address", Network_Address);
}
void Network_Create_Window_Network_Port(void)
{
	char *value = Network_Integer_To_String(Network_Port);
	Network_Create_Window_Network("network port", value);
	free(value);
}
void Network_Create_Window(GtkWidget *Network_Window)
{
	/* vbox */
	GtkWidget *Network_VBox;
	Network_VBox = gtk_bin_get_child(GTK_BIN(Network_Window));
	/* handlebox */
	GtkWidget *Network_Handle_Box;
	GList *Network_G_List = gtk_container_get_children(GTK_CONTAINER(Network_VBox));
	Network_Handle_Box = Network_G_List->data;
	/* menubar */
	GtkWidget *Network_Menu_Bar;
	Network_G_List = gtk_container_get_children(GTK_CONTAINER(Network_Handle_Box));
	Network_Menu_Bar = Network_G_List->data;
	/* item network */
	GtkWidget *Network_Item_Network;
	Network_Item_Network = gtk_image_menu_item_new_with_mnemonic("_Network");
	gtk_widget_set_name(Network_Item_Network, "Network item network");
	gtk_widget_show(Network_Item_Network);
	gtk_container_add(GTK_CONTAINER(Network_Menu_Bar), Network_Item_Network);
	/* menu network */
	GtkWidget *Netwok_Menu_Network;
	Netwok_Menu_Network = gtk_menu_new();
	gtk_widget_set_name(Netwok_Menu_Network, "Netwok menu network");
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(Network_Item_Network), Netwok_Menu_Network);
	/* item network mode */
	GtkWidget *Network_Item_Network_Mode;
	Network_Item_Network_Mode = gtk_image_menu_item_new_with_mnemonic("Mode");
	gtk_widget_set_name(Network_Item_Network_Mode, "Network item network mode");
	gtk_widget_show(Network_Item_Network_Mode);
	gtk_container_add(GTK_CONTAINER(Netwok_Menu_Network), Network_Item_Network_Mode);
	/* item network address */
	GtkWidget *Network_Item_Network_Address;
	Network_Item_Network_Address = gtk_image_menu_item_new_with_mnemonic("Address...");
	gtk_widget_set_name(Network_Item_Network_Address, "Network item network address");
	gtk_widget_show(Network_Item_Network_Address);
	gtk_container_add(GTK_CONTAINER(Netwok_Menu_Network), Network_Item_Network_Address);
	/* item network port */
	GtkWidget *Network_Item_Network_Port;
	Network_Item_Network_Port = gtk_image_menu_item_new_with_mnemonic("Port...");
	gtk_widget_set_name(Network_Item_Network_Port, "Network item network port");
	gtk_widget_show(Network_Item_Network_Port);
	gtk_container_add(GTK_CONTAINER(Netwok_Menu_Network), Network_Item_Network_Port);
	/* menu network mode */
	GtkWidget *Network_Menu_Network_Mode;
	Network_Menu_Network_Mode = gtk_menu_new();
	gtk_widget_set_name(Network_Menu_Network_Mode, "Network menu network mode");
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(Network_Item_Network_Mode), Network_Menu_Network_Mode);
	/* item network mode server */
	GSList *Network_Group_Network_Mode = NULL;
	GtkWidget *Network_Item_Network_Mode_Server;
	Network_Item_Network_Mode_Server = gtk_radio_menu_item_new_with_mnemonic(Network_Group_Network_Mode, "Server");
	Network_Group_Network_Mode = gtk_radio_menu_item_get_group(GTK_RADIO_MENU_ITEM(Network_Item_Network_Mode_Server));
	gtk_widget_set_name(Network_Item_Network_Mode_Server, "Network item network mode server");
	gtk_widget_show(Network_Item_Network_Mode_Server);
	gtk_container_add(GTK_CONTAINER(Network_Menu_Network_Mode), Network_Item_Network_Mode_Server);
	if(strcmp(Network_Mode, "server") == 0)
		gtk_check_menu_item_set_active(GTK_CHECK_MENU_ITEM(Network_Item_Network_Mode_Server), TRUE);
	/* item network mode client */
	GtkWidget *Network_Item_Network_Mode_Client;
	Network_Item_Network_Mode_Client = gtk_radio_menu_item_new_with_mnemonic(Network_Group_Network_Mode, "Client");
	Network_Group_Network_Mode = gtk_radio_menu_item_get_group(GTK_RADIO_MENU_ITEM(Network_Item_Network_Mode_Client));
	gtk_widget_set_name(Network_Item_Network_Mode_Client, "Network item network mode client");
	gtk_widget_show(Network_Item_Network_Mode_Client);
	gtk_container_add(GTK_CONTAINER(Network_Menu_Network_Mode), Network_Item_Network_Mode_Client);
	if(strcmp(Network_Mode, "client") == 0)
		gtk_check_menu_item_set_active(GTK_CHECK_MENU_ITEM(Network_Item_Network_Mode_Client), TRUE);
	/* item network mode disabled */
	GtkWidget *Network_Item_Network_Mode_Disabled;
	Network_Item_Network_Mode_Disabled = gtk_radio_menu_item_new_with_mnemonic(Network_Group_Network_Mode, "Disabled");
	Network_Group_Network_Mode = gtk_radio_menu_item_get_group(GTK_RADIO_MENU_ITEM(Network_Item_Network_Mode_Disabled));
	gtk_widget_set_name(Network_Item_Network_Mode_Disabled, "Network item network mode disabled");
	gtk_widget_show(Network_Item_Network_Mode_Disabled);
	gtk_container_add(GTK_CONTAINER(Network_Menu_Network_Mode), Network_Item_Network_Mode_Disabled);
	if(strcmp(Network_Mode, "disabled") == 0)
		gtk_check_menu_item_set_active(GTK_CHECK_MENU_ITEM(Network_Item_Network_Mode_Disabled), TRUE);
	/* connect to the callback function */
	g_signal_connect((gpointer) Network_Item_Network_Mode_Server, "activate", G_CALLBACK(Network_Set_Value), NULL);
	g_signal_connect((gpointer) Network_Item_Network_Mode_Client, "activate", G_CALLBACK(Network_Set_Value), NULL);
	g_signal_connect((gpointer) Network_Item_Network_Mode_Disabled, "activate", G_CALLBACK(Network_Set_Value), NULL);
	g_signal_connect((gpointer) Network_Item_Network_Address, "activate", G_CALLBACK(Network_Create_Window_Network_Address), NULL);
	g_signal_connect((gpointer) Network_Item_Network_Port, "activate", G_CALLBACK(Network_Create_Window_Network_Port), NULL);
}
int Network_Do_Frame(void)
{
	if(strcmp(Network_Mode, "server") == 0)
	{
		int Len;
		int Result;
		Network_Data_T Network_Data;
		Network_Data = Network_GetData1();
		Len = sizeof(Network_Data);
		Result = SDLNet_TCP_Send(Network_Tcpsocket, &Network_Data, Len);
		if(Result < Len)
			fprintf(stderr, "%s:%d: %s (The server has a problem while sending data over the socket)\n", __FILE__, __LINE__, __PRETTY_FUNCTION__);
		if(SDLNet_TCP_Recv(Network_Tcpsocket, &Network_Data, sizeof(Network_Data)) <= 0)
			fprintf(stderr, "%s:%d: %s (The server has a problem while receiving data from the socket)\n", __FILE__, __LINE__, __PRETTY_FUNCTION__);
		Network_SetData2(Network_Data);
	}
	if(strcmp(Network_Mode, "client") == 0)
	{
		int Len;
		int Result;
		Network_Data_T Network_Data;
		if(SDLNet_TCP_Recv(Network_Tcpsocket, &Network_Data, sizeof(Network_Data)) <= 0)
			fprintf(stderr, "%s:%d: %s (The client has a problem while receiving data from the socket)\n", __FILE__, __LINE__, __PRETTY_FUNCTION__);
		Network_SetData1(Network_Data);
		Network_Data = Network_GetData2();
		Len = sizeof(Network_Data);
		Result = SDLNet_TCP_Send(Network_Tcpsocket, &Network_Data, Len);
		if(Result < Len)
			fprintf(stderr, "%s:%d: %s (The client has a problem while sending data over the socket)\n", __FILE__, __LINE__, __PRETTY_FUNCTION__);
	}
	Network_Update_Frame();
	return 0;
}
void Network_Update_Emulation(void)
{
	if(Update_Frame != Do_VDP_Only && Update_Frame != Network_Do_Frame)
		Network_Update_Frame = Update_Frame;
	if(strcmp(Network_Mode, "server") == 0)
	{
		if(Network_Server_Tcpsocket == NULL)
		{
			IPaddress ip;
			if(SDLNet_ResolveHost(&ip, NULL, Network_Port) == -1) 
				fprintf(stderr, "%s:%d: %s (The server is unable to resolve the host)\n", __FILE__, __LINE__, __PRETTY_FUNCTION__);
			Network_Server_Tcpsocket = SDLNet_TCP_Open(&ip);
			if(Network_Server_Tcpsocket == NULL)
				fprintf(stderr, "%s:%d: %s (The server is unable to connect to the host)\n", __FILE__, __LINE__, __PRETTY_FUNCTION__);
			Update_Frame = Do_VDP_Only;
		}
		else if(Network_Tcpsocket == NULL)
		{
			MESSAGE_L("Waiting for the client...", "Waiting for the client...", 1500);
			Network_Tcpsocket = SDLNet_TCP_Accept(Network_Server_Tcpsocket);
			Update_Frame = Do_VDP_Only;
		}
		else
		{
			Frame_Skip = 0;
			Update_Frame = Network_Do_Frame;
		}
	}
	else if(strcmp(Network_Mode, "client") == 0)
	{
		if(Network_Tcpsocket == NULL)
		{
			IPaddress ip;
			if(SDLNet_ResolveHost(&ip, Network_Address, Network_Port) == -1)
				fprintf(stderr, "%s:%d: %s (The client is unable to resolve the host)\n", __FILE__, __LINE__, __PRETTY_FUNCTION__);
			Network_Tcpsocket = SDLNet_TCP_Open(&ip);
			if(Network_Tcpsocket == NULL)
				fprintf(stderr, "%s:%d: %s (The client is unable to connect to the host)\n", __FILE__, __LINE__, __PRETTY_FUNCTION__);
			Update_Frame = Do_VDP_Only;
		}
		else
		{
			Frame_Skip = 0;
			Update_Frame = Network_Do_Frame;
		}
	}
}
Network_Data_T Network_GetData1(void)
{
	Network_Data_T Network_Data;
	Network_Data.Controller_1_Type = Controller_1_Type;
	Network_Data.Controller_1_State = Controller_1_State;
	Network_Data.Controller_1_COM = Controller_1_COM;
	Network_Data.Controller_1_Counter = Controller_1_Counter;
	Network_Data.Controller_1_Delay = Controller_1_Delay;
	Network_Data.Controller_1_Up = Controller_1_Up;
	Network_Data.Controller_1_Down = Controller_1_Down;
	Network_Data.Controller_1_Left = Controller_1_Left;
	Network_Data.Controller_1_Right = Controller_1_Right;
	Network_Data.Controller_1_Start = Controller_1_Start;
	Network_Data.Controller_1_Mode = Controller_1_Mode;
	Network_Data.Controller_1_A = Controller_1_A;
	Network_Data.Controller_1_B = Controller_1_B;
	Network_Data.Controller_1_C = Controller_1_C;
	Network_Data.Controller_1_X = Controller_1_X;
	Network_Data.Controller_1_Y = Controller_1_Y;
	Network_Data.Controller_1_Z = Controller_1_Z;
	return Network_Data;
}
Network_Data_T Network_GetData2(void)
{
	Network_Data_T Network_Data;
	Network_Data.Controller_1_Type = Controller_2_Type;
	Network_Data.Controller_1_State = Controller_2_State;
	Network_Data.Controller_1_COM = Controller_2_COM;
	Network_Data.Controller_1_Counter = Controller_2_Counter;
	Network_Data.Controller_1_Delay = Controller_2_Delay;
	Network_Data.Controller_1_Up = Controller_2_Up;
	Network_Data.Controller_1_Down = Controller_2_Down;
	Network_Data.Controller_1_Left = Controller_2_Left;
	Network_Data.Controller_1_Right = Controller_2_Right;
	Network_Data.Controller_1_Start = Controller_2_Start;
	Network_Data.Controller_1_Mode = Controller_2_Mode;
	Network_Data.Controller_1_A = Controller_2_A;
	Network_Data.Controller_1_B = Controller_2_B;
	Network_Data.Controller_1_C = Controller_2_C;
	Network_Data.Controller_1_X = Controller_2_X;
	Network_Data.Controller_1_Y = Controller_2_Y;
	Network_Data.Controller_1_Z = Controller_2_Z;
	return Network_Data;
}
void Network_SetData1(Network_Data_T Network_Data)
{
	Controller_1_Type = Network_Data.Controller_1_Type;
	Controller_1_State = Network_Data.Controller_1_State;
	Controller_1_COM = Network_Data.Controller_1_COM;
	Controller_1_Counter = Network_Data.Controller_1_Counter;
	Controller_1_Delay = Network_Data.Controller_1_Delay;
	Controller_1_Up = Network_Data.Controller_1_Up;
	Controller_1_Down = Network_Data.Controller_1_Down;
	Controller_1_Left = Network_Data.Controller_1_Left;
	Controller_1_Right = Network_Data.Controller_1_Right;
	Controller_1_Start = Network_Data.Controller_1_Start;
	Controller_1_Mode = Network_Data.Controller_1_Mode;
	Controller_1_A = Network_Data.Controller_1_A;
	Controller_1_B = Network_Data.Controller_1_B;
	Controller_1_C = Network_Data.Controller_1_C;
	Controller_1_X = Network_Data.Controller_1_X;
	Controller_1_Y = Network_Data.Controller_1_Y;
	Controller_1_Z = Network_Data.Controller_1_Z;
}
void Network_SetData2(Network_Data_T Network_Data)
{
	Controller_2_Type = Network_Data.Controller_1_Type;
	Controller_2_State = Network_Data.Controller_1_State;
	Controller_2_COM = Network_Data.Controller_1_COM;
	Controller_2_Counter = Network_Data.Controller_1_Counter;
	Controller_2_Delay = Network_Data.Controller_1_Delay;
	Controller_2_Up = Network_Data.Controller_1_Up;
	Controller_2_Down = Network_Data.Controller_1_Down;
	Controller_2_Left = Network_Data.Controller_1_Left;
	Controller_2_Right = Network_Data.Controller_1_Right;
	Controller_2_Start = Network_Data.Controller_1_Start;
	Controller_2_Mode = Network_Data.Controller_1_Mode;
	Controller_2_A = Network_Data.Controller_1_A;
	Controller_2_B = Network_Data.Controller_1_B;
	Controller_2_C = Network_Data.Controller_1_C;
	Controller_2_X = Network_Data.Controller_1_X;
	Controller_2_Y = Network_Data.Controller_1_Y;
	Controller_2_Z = Network_Data.Controller_1_Z;
}
