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
#include "audio.h" /* for Audio_* */
#include "g_main.h" /* for Str_Tmp */
#include <gtk/gtk.h> /* for GtkWidget */
#include <stdlib.h> /* for malloc, free and exit */
#include <string.h> /* for strlen */
#include <SDL/SDL_audio.h> /* for SDL_MIX_MAXVOLUME */
int Audio_Volume = SDL_MIX_MAXVOLUME;
void Audio_Save_Config(char *conf_file)
{
	sprintf(Str_Tmp, "%d", Audio_Volume);
	WritePrivateProfileString("Audio", "Audio volume", Str_Tmp, conf_file);
}
void Audio_Load_Config(char *conf_file)
{
	Audio_Volume = GetPrivateProfileInt("Audio", "Audio volume", SDL_MIX_MAXVOLUME, conf_file);
}
char *Audio_Integer_To_String(int integer)
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
	if(value == NULL)
	{
		fprintf(stderr, "%s:%d: %s (Unable to allocate dynamic memory)\n", __FILE__, __LINE__, __PRETTY_FUNCTION__);
		exit(EXIT_FAILURE);
	}
	sprintf(value, "%d", integer);
	return value;
}
char *Audio_Concatenate_Strings(const char *dest, const char *src)
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
void Audio_Set_Value(GtkWidget *widget, gpointer user_data)
{
	if(strcmp(gtk_widget_get_name(widget), "Audio button cancel audio volume") == 0)
	{
		audio_user_data_t *callback_data = (audio_user_data_t*) user_data;
		gtk_object_destroy(GTK_OBJECT(callback_data->widget));
		free(callback_data);
	}
	if(strcmp(gtk_widget_get_name(widget), "Audio button ok audio volume") == 0)
	{
		audio_user_data_t *callback_data = (audio_user_data_t*) user_data;
		if(strlen(callback_data->text) == 0)
			Audio_Volume = SDL_MIX_MAXVOLUME;
		else
			Audio_Volume = atoi(callback_data->text);
		if(Audio_Volume < 0)
			Audio_Volume = 0;
		if(Audio_Volume > SDL_MIX_MAXVOLUME)
			Audio_Volume = SDL_MIX_MAXVOLUME;
		gtk_object_destroy(GTK_OBJECT(callback_data->widget));
		free(callback_data);
	}
}
void Audio_Create_Window_Audio(const char *name, const char *entry_text)
{
	gint Spacing = 5;
	char *widget_name = NULL;
	/* window audio */
	widget_name = Audio_Concatenate_Strings("Audio window ", name);
	GtkWidget *Audio_Window;
	Audio_Window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_widget_set_name(Audio_Window, widget_name);
	gtk_container_set_border_width(GTK_CONTAINER(Audio_Window), Spacing);
	gtk_window_set_title(GTK_WINDOW(Audio_Window), name);
	gtk_window_set_modal(GTK_WINDOW(Audio_Window), TRUE);
	gtk_window_set_resizable(GTK_WINDOW(Audio_Window), FALSE);
	free(widget_name);
	/* vbox audio */
	widget_name = Audio_Concatenate_Strings("Audio vbox ", name);
	GtkWidget *Audio_VBox;
	Audio_VBox = gtk_vbox_new(FALSE, Spacing);
	gtk_widget_set_name(Audio_VBox, widget_name);
	gtk_widget_show(Audio_VBox);
	gtk_container_add(GTK_CONTAINER(Audio_Window), Audio_VBox);
	free(widget_name);
	/* entry audio */
	widget_name = Audio_Concatenate_Strings("Audio entry ", name);
	GtkWidget *Audio_Entry;
	Audio_Entry = gtk_entry_new();
	gtk_widget_set_name(Audio_Entry, widget_name);
	gtk_widget_show(Audio_Entry);
	gtk_box_pack_start(GTK_BOX(Audio_VBox), Audio_Entry, TRUE, TRUE, 0);
	gtk_entry_set_text(GTK_ENTRY(Audio_Entry), entry_text);
	free(widget_name);
	/* hbox audio */
	widget_name = Audio_Concatenate_Strings("Audio hbox ", name);
	GtkWidget *Audio_HBox;
	Audio_HBox = gtk_hbox_new(TRUE, Spacing);
	gtk_widget_set_name(Audio_HBox, widget_name);
	gtk_widget_show(Audio_HBox);
	gtk_box_pack_start(GTK_BOX(Audio_VBox), Audio_HBox, TRUE, TRUE, 0);
	free(widget_name);
	/* button audio cancel */
	widget_name = Audio_Concatenate_Strings("Audio button cancel ", name);
	GtkWidget *Audio_Button_Cancel;
	Audio_Button_Cancel = gtk_button_new_from_stock("gtk-cancel");
	gtk_widget_set_name(Audio_Button_Cancel, widget_name);
	gtk_widget_show(Audio_Button_Cancel);
	gtk_box_pack_start(GTK_BOX(Audio_HBox), Audio_Button_Cancel, FALSE, FALSE, 0);
	gtk_button_set_relief(GTK_BUTTON(Audio_Button_Cancel), GTK_RELIEF_NONE);
	free(widget_name);
	/* button audio ok */
	widget_name = Audio_Concatenate_Strings("Audio button ok ", name);
	GtkWidget *Audio_Button_Ok;
	Audio_Button_Ok = gtk_button_new_from_stock("gtk-ok");
	gtk_widget_set_name(Audio_Button_Ok, widget_name);
	gtk_widget_show(Audio_Button_Ok);
	gtk_box_pack_start(GTK_BOX(Audio_HBox), Audio_Button_Ok, FALSE, FALSE, 0);
	gtk_button_set_relief(GTK_BUTTON(Audio_Button_Ok), GTK_RELIEF_NONE);
	free(widget_name);
	/* connect to the callback function */
	audio_user_data_t *callback_data = malloc(sizeof(audio_user_data_t));
	if(callback_data == NULL)
	{
		fprintf(stderr, "%s:%d: %s (Unable to allocate dynamic memory)\n", __FILE__, __LINE__, __PRETTY_FUNCTION__);
		exit(EXIT_FAILURE);
	}
	callback_data->text = gtk_entry_get_text(GTK_ENTRY(Audio_Entry));
	callback_data->widget = Audio_Window;
	g_signal_connect((gpointer) Audio_Button_Cancel, "clicked", G_CALLBACK(Audio_Set_Value), (gpointer) callback_data);
	g_signal_connect((gpointer) Audio_Button_Ok, "clicked", G_CALLBACK(Audio_Set_Value), (gpointer) callback_data);
	/* show */
	gtk_widget_show(Audio_Window);
}
void Audio_Create_Window_Audio_Volume(void)
{
	char *value = Audio_Integer_To_String(Audio_Volume);
	Audio_Create_Window_Audio("audio volume", value);
	free(value);
}
void Audio_Create_Window(GtkWidget *Audio_Window)
{
	/* vbox */
	GtkWidget *Audio_VBox;
	Audio_VBox = gtk_bin_get_child(GTK_BIN(Audio_Window));
	/* handlebox */
	GtkWidget *Audio_Handle_Box;
	GList *Audio_G_List = gtk_container_get_children(GTK_CONTAINER(Audio_VBox));
	Audio_Handle_Box = Audio_G_List->data;
	/* menubar */
	GtkWidget *Audio_Menu_Bar;
	Audio_G_List = gtk_container_get_children(GTK_CONTAINER(Audio_Handle_Box));
	Audio_Menu_Bar = Audio_G_List->data;
	/* item audio */
	GtkWidget *Audio_Item_Audio;
	Audio_G_List = gtk_container_get_children(GTK_CONTAINER(Audio_Menu_Bar));
	while(strcmp(gtk_widget_get_name(Audio_G_List->data), "item8") != 0)
		Audio_G_List = Audio_G_List->next;
	Audio_Item_Audio = Audio_G_List->data;
	/* menu audio */
	GtkWidget *Audio_Menu_Audio;
	Audio_Menu_Audio = gtk_menu_item_get_submenu(GTK_MENU_ITEM(Audio_Item_Audio));
	/* item audio volume */
	GtkWidget *Audio_Item_Audio_Volume;
	Audio_Item_Audio_Volume = gtk_image_menu_item_new_with_mnemonic("Volume...");
	gtk_widget_set_name(Audio_Item_Audio_Volume, "Audio item audio volume");
	gtk_widget_show(Audio_Item_Audio_Volume);
	gtk_container_add(GTK_CONTAINER(Audio_Menu_Audio), Audio_Item_Audio_Volume);
	/* connect to the callback function */
	g_signal_connect((gpointer) Audio_Item_Audio_Volume, "activate", G_CALLBACK(Audio_Create_Window_Audio_Volume), NULL);
}
