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
void Network_Save_Config(char* Conf_File)
{
	WritePrivateProfileString("Network", "Network mode", Network_Mode, Conf_File);
	WritePrivateProfileString("Network", "Network address", Network_Address, Conf_File);
	sprintf(Str_Tmp, "%d", Network_Port);
	WritePrivateProfileString("Network", "Network port", Str_Tmp, Conf_File);
}
void Network_Load_Config(char* Conf_File)
{
	GetPrivateProfileString ("Network", "Network mode", "", &Network_Mode[0], 1024, Conf_File);
	GetPrivateProfileString ("Network", "Network address", "localhost", &Network_Address[0], 1024, Conf_File);
	Network_Port = GetPrivateProfileInt ("Network", "Network port", 9999, Conf_File);
}
char* Network_Integer_To_Array(int Integer)
{
	int Integer_New = 0;
	int Len = 1;
	char* Value = NULL;
	Integer_New = Integer / 10;
	while(Integer_New != 0)
	{
		Len++;
		Integer_New = Integer_New / 10;
	}
	Value = malloc(sizeof(char) * Len + 1);
	sprintf(Value, "%d", Integer);
	return Value;
}
void Network_Set_Value(GtkWidget* Menu_Item, gpointer User_Data)
{
	if(strcmp(gtk_widget_get_name(Menu_Item), "Network_Item_Network_Mode_Server") == 0)
	{
		strcpy(Network_Mode, "server\0");
	}
	if(strcmp(gtk_widget_get_name(Menu_Item), "Network_Item_Network_Mode_Client") == 0)
	{
		strcpy(Network_Mode, "client\0");
	}
	if(strcmp(gtk_widget_get_name(Menu_Item), "Network_Item_Network_Mode_Disabled") == 0)
	{
		strcpy(Network_Mode, "disabled\0");
	}
	if(strcmp(gtk_widget_get_name(Menu_Item), "Network_Item_Network_Mode_Disabled") == 0)
	{
		strcpy(Network_Mode, "disabled\0");
	}
	if(strcmp(gtk_widget_get_name(Menu_Item), "Network_Button_Network_Address_Ok") == 0)
	{
		if(strlen(User_Data) == 0)
			strcpy(Network_Address, "localhost");
		else
			strcpy(Network_Address, User_Data);
	}
	if(strcmp(gtk_widget_get_name(Menu_Item), "Network_Button_Network_Port_Ok") == 0)
	{
		if(strlen(User_Data) == 0)
			Network_Port = 5394;
		else
			Network_Port = atoi(User_Data);
	}
}
void Network_Create_Window_Network_Address(void)
{
	gint Spacing = 5;
	/* window network address */
	GtkWidget* Network_Window_Network_Address;
	Network_Window_Network_Address = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_widget_set_name(Network_Window_Network_Address, "Network_Window_Network_Address");
	gtk_container_set_border_width(GTK_CONTAINER(Network_Window_Network_Address), Spacing);
	gtk_window_set_title(GTK_WINDOW(Network_Window_Network_Address), "Network address");
	gtk_window_set_modal(GTK_WINDOW(Network_Window_Network_Address), TRUE);
	gtk_window_set_resizable(GTK_WINDOW(Network_Window_Network_Address), FALSE);
	/* vbox network address */
	GtkWidget* Network_VBox_Network_Address;
	Network_VBox_Network_Address = gtk_vbox_new(FALSE, Spacing);
	gtk_widget_set_name(Network_VBox_Network_Address, "Network_VBox_Network_Address");
	gtk_widget_show(Network_VBox_Network_Address);
	gtk_container_add(GTK_CONTAINER(Network_Window_Network_Address), Network_VBox_Network_Address);
	/* entry network address */
	GtkWidget* Network_Entry_Network_Address;
	Network_Entry_Network_Address = gtk_entry_new();
	gtk_widget_set_name(Network_Entry_Network_Address, "Network_Entry_Network_Address");
	gtk_widget_show(Network_Entry_Network_Address);
	gtk_box_pack_start(GTK_BOX(Network_VBox_Network_Address), Network_Entry_Network_Address, TRUE, TRUE, 0);
	gtk_entry_set_text(Network_Entry_Network_Address, Network_Address);
	/* hbox network address */
	GtkWidget* Network_HBox_Network_Address;
	Network_HBox_Network_Address = gtk_hbox_new(TRUE, Spacing);
	gtk_widget_set_name(Network_HBox_Network_Address, "Network_HBox_Network_Address");
	gtk_widget_show(Network_HBox_Network_Address);
	gtk_box_pack_start(GTK_BOX(Network_VBox_Network_Address), Network_HBox_Network_Address, TRUE, TRUE, 0);
	/* button network address cancel */
	GtkWidget* Network_Button_Network_Address_Cancel;
	Network_Button_Network_Address_Cancel = gtk_button_new_from_stock("gtk-cancel");
	gtk_widget_set_name(Network_Button_Network_Address_Cancel, "Network_Button_Network_Address_Cancel");
	gtk_widget_show(Network_Button_Network_Address_Cancel);
	gtk_box_pack_start(GTK_BOX(Network_HBox_Network_Address), Network_Button_Network_Address_Cancel, FALSE, FALSE, 0);
	gtk_button_set_relief(GTK_BUTTON(Network_Button_Network_Address_Cancel), GTK_RELIEF_NONE);
	/* button network address ok */
	GtkWidget* Network_Button_Network_Address_Ok;
	Network_Button_Network_Address_Ok = gtk_button_new_from_stock("gtk-ok");
	gtk_widget_set_name(Network_Button_Network_Address_Ok, "Network_Button_Network_Address_Ok");
	gtk_widget_show(Network_Button_Network_Address_Ok);
	gtk_box_pack_start(GTK_BOX(Network_HBox_Network_Address), Network_Button_Network_Address_Ok, FALSE, FALSE, 0);
	gtk_button_set_relief(GTK_BUTTON(Network_Button_Network_Address_Ok), GTK_RELIEF_NONE);
	/* connect to the callback function */
	g_signal_connect((gpointer) Network_Button_Network_Address_Cancel, "clicked", G_CALLBACK(gtk_widget_destroy), NULL);
	g_signal_connect((gpointer) Network_Button_Network_Address_Ok, "clicked", G_CALLBACK(Network_Set_Value), gtk_entry_get_text(Network_Entry_Network_Address));
	/* show */
	gtk_widget_show(Network_Window_Network_Address);
}
void Network_Create_Window_Network_Port(void)
{
	gint Spacing = 5;
	/* window network port */
	GtkWidget* Network_Window_Network_Port;
	Network_Window_Network_Port = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_widget_set_name(Network_Window_Network_Port, "Network_Window_Network_Port");
	gtk_container_set_border_width(GTK_CONTAINER(Network_Window_Network_Port), Spacing);
	gtk_window_set_title(GTK_WINDOW(Network_Window_Network_Port), "Network port");
	gtk_window_set_modal(GTK_WINDOW(Network_Window_Network_Port), TRUE);
	gtk_window_set_resizable(GTK_WINDOW(Network_Window_Network_Port), FALSE);
	/* vbox network port */
	GtkWidget* Network_VBox_Network_Port;
	Network_VBox_Network_Port = gtk_vbox_new(FALSE, Spacing);
	gtk_widget_set_name(Network_VBox_Network_Port, "Network_VBox_Network_Port");
	gtk_widget_show(Network_VBox_Network_Port);
	gtk_container_add(GTK_CONTAINER(Network_Window_Network_Port), Network_VBox_Network_Port);
	/* entry network port */
	char* value = Network_Integer_To_Array(Network_Port);
	GtkWidget* Network_Entry_Network_Port;
	Network_Entry_Network_Port = gtk_entry_new();
	gtk_widget_set_name(Network_Entry_Network_Port, "Network_Entry_Network_Port");
	gtk_widget_show(Network_Entry_Network_Port);
	gtk_box_pack_start(GTK_BOX(Network_VBox_Network_Port), Network_Entry_Network_Port, TRUE, TRUE, 0);
	gtk_entry_set_text(Network_Entry_Network_Port, value);
	/* hbox network port */
	GtkWidget* Network_HBox_Network_Port;
	Network_HBox_Network_Port = gtk_hbox_new(TRUE, Spacing);
	gtk_widget_set_name(Network_HBox_Network_Port, "Network_HBox_Network_Port");
	gtk_widget_show(Network_HBox_Network_Port);
	gtk_box_pack_start(GTK_BOX(Network_VBox_Network_Port), Network_HBox_Network_Port, TRUE, TRUE, 0);
	/* button network port cancel */
	GtkWidget* Network_Button_Network_Port_Cancel;
	Network_Button_Network_Port_Cancel = gtk_button_new_from_stock("gtk-cancel");
	gtk_widget_set_name(Network_Button_Network_Port_Cancel, "Network_Button_Network_Port_Cancel");
	gtk_widget_show(Network_Button_Network_Port_Cancel);
	gtk_box_pack_start(GTK_BOX(Network_HBox_Network_Port), Network_Button_Network_Port_Cancel, FALSE, FALSE, 0);
	gtk_button_set_relief(GTK_BUTTON(Network_Button_Network_Port_Cancel), GTK_RELIEF_NONE);
	/* button network port ok */
	GtkWidget* Network_Button_Network_Port_Ok;
	Network_Button_Network_Port_Ok = gtk_button_new_from_stock("gtk-ok");
	gtk_widget_set_name(Network_Button_Network_Port_Ok, "Network_Button_Network_Port_Ok");
	gtk_widget_show(Network_Button_Network_Port_Ok);
	gtk_box_pack_start(GTK_BOX(Network_HBox_Network_Port), Network_Button_Network_Port_Ok, FALSE, FALSE, 0);
	gtk_button_set_relief(GTK_BUTTON(Network_Button_Network_Port_Ok), GTK_RELIEF_NONE);
	/* connect to the callback function */
	g_signal_connect((gpointer) Network_Button_Network_Port_Cancel, "clicked", G_CALLBACK(gtk_widget_destroy), NULL);
	g_signal_connect((gpointer) Network_Button_Network_Port_Ok, "clicked", G_CALLBACK(Network_Set_Value), gtk_entry_get_text(Network_Entry_Network_Port));
	/* show */
	gtk_widget_show(Network_Window_Network_Port);
}
void Network_Create_Window(GtkWidget* Network_Window)
{
	/* vbox */
	GtkWidget* Network_VBox;
	Network_VBox = gtk_bin_get_child(Network_Window);
	/* handlebox */
	GtkWidget* Network_Handle_Box;
	GList* Network_G_List = gtk_container_get_children(Network_VBox);
	Network_Handle_Box = Network_G_List->data;
	/* menubar */
	GtkWidget* Network_Menu_Bar;
	Network_G_List = gtk_container_get_children(Network_Handle_Box);
	Network_Menu_Bar = Network_G_List->data;
	/* item network */
	GtkWidget* Network_Item_Network;
	Network_Item_Network = gtk_image_menu_item_new_with_mnemonic("_Network");
	gtk_widget_set_name(Network_Item_Network, "Network_Item_Network");
	gtk_widget_show(Network_Item_Network);
	gtk_container_add(GTK_CONTAINER(Network_Menu_Bar), Network_Item_Network);
	/* menu network */
	GtkWidget* Netwok_Menu_Network;
	Netwok_Menu_Network = gtk_menu_new();
	gtk_widget_set_name(Netwok_Menu_Network, "Netwok_Menu_Network");
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(Network_Item_Network), Netwok_Menu_Network);
	/* item network mode */
	GtkWidget* Network_Item_Network_Mode;
	Network_Item_Network_Mode = gtk_image_menu_item_new_with_mnemonic("Mode");
	gtk_widget_set_name(Network_Item_Network_Mode, "Network_Item_Network_Mode");
	gtk_widget_show(Network_Item_Network_Mode);
	gtk_container_add(GTK_CONTAINER(Netwok_Menu_Network), Network_Item_Network_Mode);
	/* item network address */
	GtkWidget* Network_Item_Network_Address;
	Network_Item_Network_Address = gtk_image_menu_item_new_with_mnemonic("Address...");
	gtk_widget_set_name(Network_Item_Network_Address, "Network_Item_Network_Address");
	gtk_widget_show(Network_Item_Network_Address);
	gtk_container_add(GTK_CONTAINER(Netwok_Menu_Network), Network_Item_Network_Address);
	/* item network port */
	GtkWidget* Network_Item_Network_Port;
	Network_Item_Network_Port = gtk_image_menu_item_new_with_mnemonic("Port...");
	gtk_widget_set_name(Network_Item_Network_Port, "Network_Item_Network_Port");
	gtk_widget_show(Network_Item_Network_Port);
	gtk_container_add(GTK_CONTAINER(Netwok_Menu_Network), Network_Item_Network_Port);
	/* menu network mode */
	GtkWidget* Network_Menu_Network_Mode;
	Network_Menu_Network_Mode = gtk_menu_new();
	gtk_widget_set_name(Network_Menu_Network_Mode, "Network_Menu_Network_Mode");
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(Network_Item_Network_Mode), Network_Menu_Network_Mode);
	/* item network mode server */
	GSList* Network_Group_Network_Mode = NULL;
	GtkWidget* Network_Item_Network_Mode_Server;
	Network_Item_Network_Mode_Server = gtk_radio_menu_item_new_with_mnemonic(Network_Group_Network_Mode, "Server");
	Network_Group_Network_Mode = gtk_radio_menu_item_get_group(GTK_RADIO_MENU_ITEM(Network_Item_Network_Mode_Server));
	gtk_widget_set_name(Network_Item_Network_Mode_Server, "Network_Item_Network_Mode_Server");
	gtk_widget_show(Network_Item_Network_Mode_Server);
	gtk_container_add(GTK_CONTAINER(Network_Menu_Network_Mode), Network_Item_Network_Mode_Server);
	if(strcmp(Network_Mode, "server") == 0)
		gtk_check_menu_item_set_active(GTK_CHECK_MENU_ITEM(Network_Item_Network_Mode_Server), TRUE);
	/* item network mode client */
	GtkWidget* Network_Item_Network_Mode_Client;
	Network_Item_Network_Mode_Client = gtk_radio_menu_item_new_with_mnemonic(Network_Group_Network_Mode, "Client");
	Network_Group_Network_Mode = gtk_radio_menu_item_get_group(GTK_RADIO_MENU_ITEM(Network_Item_Network_Mode_Client));
	gtk_widget_set_name(Network_Item_Network_Mode_Client, "Network_Item_Network_Mode_Client");
	gtk_widget_show(Network_Item_Network_Mode_Client);
	gtk_container_add(GTK_CONTAINER(Network_Menu_Network_Mode), Network_Item_Network_Mode_Client);
	if(strcmp(Network_Mode, "client") == 0)
		gtk_check_menu_item_set_active(GTK_CHECK_MENU_ITEM(Network_Item_Network_Mode_Client), TRUE);
	/* item network mode disabled */
	GtkWidget* Network_Item_Network_Mode_Disabled;
	Network_Item_Network_Mode_Disabled = gtk_radio_menu_item_new_with_mnemonic(Network_Group_Network_Mode, "Disabled");
	Network_Group_Network_Mode = gtk_radio_menu_item_get_group(GTK_RADIO_MENU_ITEM(Network_Item_Network_Mode_Disabled));
	gtk_widget_set_name(Network_Item_Network_Mode_Disabled, "Network_Item_Network_Mode_Disabled");
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
int Network_Do_Genesis_Frame(void)
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
	Do_Genesis_Frame();
	return 0;
}
void Network_Do(void)
{
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
			Update_Frame = Network_Do_Genesis_Frame;
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
			Update_Frame = Network_Do_Genesis_Frame;
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
