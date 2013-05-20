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
#include <gtk/gtk.h> /* for GtkWidget */
typedef struct
{
	const gchar *text;
	GtkWidget *widget;
} audio_user_data_t;
extern int Audio_Volume;
/**
 * Saves the configuration to the given file.
 * It is called by the Save_Config function.
 * @param conf_file the configuration file
 */
void Audio_Save_Config(char *conf_file);
/**
 * Load the configuration from the given file.
 * It is called by the Load_Config function.
 * @param conf_file the configuration file
 */
void Audio_Load_Config(char *conf_file);
/**
 * Converts an integer to a string.
 * It is called by the Audio_Create_Window_Audio_Volume function.
 * @param integer the integer
 * @return the string
 */
char *Audio_Integer_To_String(int integer);
/**
 * Appends the source string to the destination string.
 * It is called by the Audio_Create_Window_Audio function.
 * @param dest the destination string
 * @param src the source string
 * @return the new string containing the source and the destination
 */
char *Audio_Concatenate_Strings(const char *dest, const char *src);
/**
 * The callback function.
 * It is called by the Audio_Create_Window_Audio function.
 * @param widget the widget
 * @param user_data the user data
 */
void Audio_Set_Value(GtkWidget *widget, gpointer user_data);
/**
 * Creates a window containing an entry and two buttons.
 * It is called by the Audio_Create_Window_Audio_Volume functions.
 * @param name the name of the window
 * @param entry_text the text of the entry
 */
void Audio_Create_Window_Audio(const char *name, const char *entry_text);
/**
 * Creates a window containing an entry and two buttons for the audio volume.
 * It calls the Audio_Create_Window_Audio function.
 */
void Audio_Create_Window_Audio_Volume(void);
void Audio_Create_Window(GtkWidget *Audio_Window);
