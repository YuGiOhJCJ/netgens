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
#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

#include <gdk/gdkkeysyms.h>
#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "network.h" /* for Network_Create_Window */

#define GLADE_HOOKUP_OBJECT(component,widget,name) \
  g_object_set_data_full (G_OBJECT (component), name, \
    gtk_widget_ref (widget), (GDestroyNotify) gtk_widget_unref)

#define GLADE_HOOKUP_OBJECT_NO_REF(component,widget,name) \
  g_object_set_data (G_OBJECT (component), name, widget)

GtkWidget*
create_gens_window (void)
{
  GtkWidget *gens_window;
  GdkPixbuf *gens_window_icon_pixbuf;
  GtkWidget *vbox1;
  GtkWidget *handlebox1;
  GtkWidget *menubar1;
  GtkWidget *item15;
  GtkWidget *image3295;
  GtkWidget *item15_menu;
  GtkWidget *open_rom;
  GtkWidget *image3296;
  GtkWidget *boot_cd;
  GtkWidget *image3297;
  GtkWidget *netplay;
  GtkWidget *image3298;
  GtkWidget *rom_history;
  GtkWidget *image3299;
  GtkWidget *close_rom;
  GtkWidget *image3300;
  GtkWidget *separatormenuitem1;
  GtkWidget *game_genie;
  GtkWidget *image3301;
  GtkWidget *separator2;
  GtkWidget *load_state;
  GtkWidget *image3302;
  GtkWidget *save_state_as;
  GtkWidget *image3303;
  GtkWidget *quick_load;
  GtkWidget *image3304;
  GtkWidget *quick_save;
  GtkWidget *image3305;
  GtkWidget *change_state1;
  GtkWidget *image3306;
  GtkWidget *change_state1_menu;
  GSList *change_state_slot0_group = NULL;
  GtkWidget *change_state_slot0;
  GtkWidget *change_state_slot1;
  GtkWidget *change_state_slot2;
  GtkWidget *change_state_slot3;
  GtkWidget *change_state_slot4;
  GtkWidget *change_state_slot5;
  GtkWidget *change_state_slot6;
  GtkWidget *change_state_slot7;
  GtkWidget *change_state_slot8;
  GtkWidget *change_state_slot9;
  GtkWidget *separator16;
  GtkWidget *quit;
  GtkWidget *image3307;
  GtkWidget *item3;
  GtkWidget *image3308;
  GtkWidget *item3_menu;
  GtkWidget *full_screen;
  GtkWidget *image3309;
  GtkWidget *vsync;
  GtkWidget *stretch;
  GtkWidget *separator17;
  GtkWidget *opengl;
  GtkWidget *opengl_resolution;
  GtkWidget *opengl_resolution_menu;
  GSList *_320x240_group = NULL;
  GtkWidget *_320x240;
  GtkWidget *_640x480;
  GtkWidget *_800x600;
  GtkWidget *_1024x768;
  GtkWidget *custom;
  GtkWidget *bits_per_pixel1;
  GtkWidget *bits_per_pixel1_menu;
  GSList *bpp16_group = NULL;
  GtkWidget *bpp16;
  GtkWidget *bpp24;
  GtkWidget *bpp32;
  GtkWidget *separator18;
  GtkWidget *color_adjust;
  GtkWidget *image3310;
  GtkWidget *item4;
  GtkWidget *image3311;
  GtkWidget *item4_menu;
  GSList *normal_group = NULL;
  GtkWidget *normal;
  GtkWidget *_double;
  GtkWidget *interpolated;
  GtkWidget *scanline;
  GtkWidget *_50_scanline;
  GtkWidget *_25_scanline;
  GtkWidget *interpolated_scanline;
  GtkWidget *interpolated_50_scanline;
  GtkWidget *interpolated_25_scanline;
  GtkWidget *_2xsai_kreed;
  GtkWidget *_scale2x;
  GtkWidget *hq2x;
  GtkWidget *separator4;
  GtkWidget *sprite_limit;
  GtkWidget *separator5;
  GtkWidget *item5;
  GtkWidget *image3312;
  GtkWidget *item5_menu;
  GSList *frame_auto_skip_group = NULL;
  GtkWidget *frame_auto_skip;
  GtkWidget *frame_0_skip;
  GtkWidget *frame_1_skip;
  GtkWidget *frame_2_skip;
  GtkWidget *frame_3_skip;
  GtkWidget *frame_4_skip;
  GtkWidget *frame_5_skip;
  GtkWidget *frame_6_skip;
  GtkWidget *frame_7_skip;
  GtkWidget *frame_8_skip;
  GtkWidget *separator15;
  GtkWidget *screen_shot;
  GtkWidget *image3313;
  GtkWidget *menuitem3;
  GtkWidget *image3314;
  GtkWidget *menuitem3_menu;
  GtkWidget *item6;
  GtkWidget *item6_menu;
  GtkWidget *genesis_68000;
  GtkWidget *genesis_z80;
  GtkWidget *genesis_vdp;
  GtkWidget *segacd_68000;
  GtkWidget *segacd_cdc;
  GtkWidget *segacd_gfx;
  GtkWidget *_32x_main_sh2;
  GtkWidget *_32x_sub_sh2;
  GtkWidget *_32x_vdp;
  GtkWidget *separator6;
  GtkWidget *country;
  GtkWidget *country_menu;
  GtkWidget *auto_detect;
  GtkWidget *japan_ntsc;
  GtkWidget *usa_ntsc;
  GtkWidget *europe_pal;
  GtkWidget *japan_pal;
  GtkWidget *separator9;
  GtkWidget *item7;
  GtkWidget *item7_menu;
  GtkWidget *detection_order_usa;
  GtkWidget *detection_order_japan;
  GtkWidget *detection_order_europe;
  GtkWidget *separator7;
  GtkWidget *hard_reset;
  GtkWidget *image3315;
  GtkWidget *reset_main_68000;
  GtkWidget *reset_sub_68000;
  GtkWidget *reset_68000;
  GtkWidget *reset_main_sh2;
  GtkWidget *reset_sub_sh2;
  GtkWidget *reset_z80;
  GtkWidget *separator8;
  GtkWidget *perfect_synchro;
  GtkWidget *item8;
  GtkWidget *image3316;
  GtkWidget *item8_menu;
  GtkWidget *enable_sound;
  GtkWidget *separator10;
  GtkWidget *rate;
  GtkWidget *rate_menu;
  GSList *rate_11025_group = NULL;
  GtkWidget *rate_11025;
  GtkWidget *rate_16000;
  GtkWidget *rate_22050;
  GtkWidget *rate_32000;
  GtkWidget *rate_44100;
  GtkWidget *rate_48000;
  GtkWidget *stereo;
  GtkWidget *separator11;
  GtkWidget *z80;
  GtkWidget *separator19;
  GtkWidget *ym2612;
  GtkWidget *ym2612_improved;
  GtkWidget *separator20;
  GtkWidget *dac;
  GtkWidget *dac_improved;
  GtkWidget *separator21;
  GtkWidget *psg;
  GtkWidget *psg_improved;
  GtkWidget *separator22;
  GtkWidget *pcm;
  GtkWidget *pwm;
  GtkWidget *separator23;
  GtkWidget *cdda;
  GtkWidget *separator12;
  GtkWidget *start_wav_dump;
  GtkWidget *start_gym_dump;
  GtkWidget *item1;
  GtkWidget *image3317;
  GtkWidget *item1_menu;
  GtkWidget *misc;
  GtkWidget *image3318;
  GtkWidget *joypads;
  GtkWidget *image3319;
  GtkWidget *directories;
  GtkWidget *image3320;
  GtkWidget *bios_misc_files;
  GtkWidget *image3321;
  GtkWidget *separator13;
  GtkWidget *menu_sdl_test;
  GtkWidget *image3322;
  GtkWidget *separator26;
  GtkWidget *item10;
  GtkWidget *image3323;
  GtkWidget *item9;
  GtkWidget *item9_menu;
  GSList *none_group = NULL;
  GtkWidget *none;
  GtkWidget *_8_kb;
  GtkWidget *_16_kb;
  GtkWidget *_32_kb;
  GtkWidget *_64_kb;
  GtkWidget *separator14;
  GtkWidget *load_config;
  GtkWidget *image3324;
  GtkWidget *save_config_as;
  GtkWidget *image3325;
  GtkWidget *menuitem6;
  GtkWidget *image3326;
  GtkWidget *menuitem6_menu;
  GtkWidget *about;
  GtkWidget *image3327;
  GtkAccelGroup *accel_group;
  GtkTooltips *tooltips;

  tooltips = gtk_tooltips_new ();

  accel_group = gtk_accel_group_new ();

  gens_window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_widget_set_name (gens_window, "gens_window");
  gtk_container_set_border_width (GTK_CONTAINER (gens_window), 5);
  gtk_window_set_title (GTK_WINDOW (gens_window), "gens");
  gtk_window_set_position (GTK_WINDOW (gens_window), GTK_WIN_POS_CENTER);
  gtk_window_set_default_size (GTK_WINDOW (gens_window), 400, 400);
  gens_window_icon_pixbuf = create_pixbuf ("Gens2.ico");
  if (gens_window_icon_pixbuf)
    {
      gtk_window_set_icon (GTK_WINDOW (gens_window), gens_window_icon_pixbuf);
      g_object_unref (gens_window_icon_pixbuf);
    }

  vbox1 = gtk_vbox_new (FALSE, 0);
  gtk_widget_set_name (vbox1, "vbox1");
  gtk_widget_show (vbox1);
  gtk_container_add (GTK_CONTAINER (gens_window), vbox1);

  handlebox1 = gtk_handle_box_new ();
  gtk_widget_set_name (handlebox1, "handlebox1");
  gtk_widget_show (handlebox1);
  gtk_box_pack_start (GTK_BOX (vbox1), handlebox1, FALSE, FALSE, 0);
  gtk_handle_box_set_shadow_type (GTK_HANDLE_BOX (handlebox1), GTK_SHADOW_NONE);
  gtk_handle_box_set_snap_edge (GTK_HANDLE_BOX (handlebox1), GTK_POS_LEFT);

  menubar1 = gtk_menu_bar_new ();
  gtk_widget_set_name (menubar1, "menubar1");
  gtk_widget_show (menubar1);
  gtk_container_add (GTK_CONTAINER (handlebox1), menubar1);

  item15 = gtk_image_menu_item_new_with_mnemonic ("_File");
  gtk_widget_set_name (item15, "item15");
  gtk_widget_show (item15);
  gtk_container_add (GTK_CONTAINER (menubar1), item15);

  image3295 = create_pixmap (gens_window, "resource.png");
  gtk_widget_set_name (image3295, "image3295");
  gtk_widget_show (image3295);
  gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (item15), image3295);

  item15_menu = gtk_menu_new ();
  gtk_widget_set_name (item15_menu, "item15_menu");
  gtk_menu_item_set_submenu (GTK_MENU_ITEM (item15), item15_menu);

  open_rom = gtk_image_menu_item_new_with_mnemonic ("_Open ROM");
  gtk_widget_set_name (open_rom, "open_rom");
  gtk_widget_show (open_rom);
  gtk_container_add (GTK_CONTAINER (item15_menu), open_rom);
  gtk_widget_add_accelerator (open_rom, "activate", accel_group,
                              GDK_O, (GdkModifierType) GDK_CONTROL_MASK,
                              GTK_ACCEL_VISIBLE);

  image3296 = create_pixmap (gens_window, "folder_slin_open.png");
  gtk_widget_set_name (image3296, "image3296");
  gtk_widget_show (image3296);
  gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (open_rom), image3296);

  boot_cd = gtk_image_menu_item_new_with_mnemonic ("Boot CD");
  gtk_widget_set_name (boot_cd, "boot_cd");
  gtk_widget_show (boot_cd);
  gtk_container_add (GTK_CONTAINER (item15_menu), boot_cd);
  //gtk_widget_set_sensitive (boot_cd, FALSE);
  gtk_widget_add_accelerator (boot_cd, "activate", accel_group,
                              GDK_B, (GdkModifierType) GDK_CONTROL_MASK,
                              GTK_ACCEL_VISIBLE);

  image3297 = create_pixmap (gens_window, "cdrom2_unmount.png");
  gtk_widget_set_name (image3297, "image3297");
  gtk_widget_show (image3297);
  gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (boot_cd), image3297);

  netplay = gtk_image_menu_item_new_with_mnemonic ("Netplay");
  gtk_widget_set_name (netplay, "netplay");
  gtk_widget_show (netplay);
  gtk_container_add (GTK_CONTAINER (item15_menu), netplay);
  gtk_widget_set_sensitive (netplay, FALSE);

  image3298 = create_pixmap (gens_window, "Modem.png");
  gtk_widget_set_name (image3298, "image3298");
  gtk_widget_show (image3298);
  gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (netplay), image3298);

  rom_history = gtk_image_menu_item_new_with_mnemonic ("Rom History");
  gtk_widget_set_name (rom_history, "rom_history");
  gtk_widget_show (rom_history);
  gtk_container_add (GTK_CONTAINER (item15_menu), rom_history);

  image3299 = create_pixmap (gens_window, "history.png");
  gtk_widget_set_name (image3299, "image3299");
  gtk_widget_show (image3299);
  gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (rom_history), image3299);

  close_rom = gtk_image_menu_item_new_with_mnemonic ("Close ROM");
  gtk_widget_set_name (close_rom, "close_rom");
  gtk_widget_show (close_rom);
  gtk_container_add (GTK_CONTAINER (item15_menu), close_rom);
  gtk_widget_add_accelerator (close_rom, "activate", accel_group,
                              GDK_C, (GdkModifierType) GDK_CONTROL_MASK,
                              GTK_ACCEL_VISIBLE);

  image3300 = create_pixmap (gens_window, "filleclose.png");
  gtk_widget_set_name (image3300, "image3300");
  gtk_widget_show (image3300);
  gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (close_rom), image3300);

  separatormenuitem1 = gtk_separator_menu_item_new ();
  gtk_widget_set_name (separatormenuitem1, "separatormenuitem1");
  gtk_widget_show (separatormenuitem1);
  gtk_container_add (GTK_CONTAINER (item15_menu), separatormenuitem1);
  gtk_widget_set_sensitive (separatormenuitem1, FALSE);

  game_genie = gtk_image_menu_item_new_with_mnemonic ("Game Genie");
  gtk_widget_set_name (game_genie, "game_genie");
  gtk_widget_show (game_genie);
  gtk_container_add (GTK_CONTAINER (item15_menu), game_genie);

  image3301 = create_pixmap (gens_window, "password.png");
  gtk_widget_set_name (image3301, "image3301");
  gtk_widget_show (image3301);
  gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (game_genie), image3301);

  separator2 = gtk_separator_menu_item_new ();
  gtk_widget_set_name (separator2, "separator2");
  gtk_widget_show (separator2);
  gtk_container_add (GTK_CONTAINER (item15_menu), separator2);
  gtk_widget_set_sensitive (separator2, FALSE);

  load_state = gtk_image_menu_item_new_with_mnemonic ("Load State...");
  gtk_widget_set_name (load_state, "load_state");
  gtk_widget_show (load_state);
  gtk_container_add (GTK_CONTAINER (item15_menu), load_state);
  gtk_widget_add_accelerator (load_state, "activate", accel_group,
                              GDK_F8, (GdkModifierType) GDK_SHIFT_MASK,
                              GTK_ACCEL_VISIBLE);

  image3302 = create_pixmap (gens_window, "folder_slin_open.png");
  gtk_widget_set_name (image3302, "image3302");
  gtk_widget_show (image3302);
  gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (load_state), image3302);

  save_state_as = gtk_image_menu_item_new_with_mnemonic ("Save State as...");
  gtk_widget_set_name (save_state_as, "save_state_as");
  gtk_widget_show (save_state_as);
  gtk_container_add (GTK_CONTAINER (item15_menu), save_state_as);
  gtk_widget_add_accelerator (save_state_as, "activate", accel_group,
                              GDK_F5, (GdkModifierType) GDK_SHIFT_MASK,
                              GTK_ACCEL_VISIBLE);

  image3303 = gtk_image_new_from_stock ("gtk-save-as", GTK_ICON_SIZE_MENU);
  gtk_widget_set_name (image3303, "image3303");
  gtk_widget_show (image3303);
  gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (save_state_as), image3303);

  quick_load = gtk_image_menu_item_new_with_mnemonic ("Quick Load");
  gtk_widget_set_name (quick_load, "quick_load");
  gtk_widget_show (quick_load);
  gtk_container_add (GTK_CONTAINER (item15_menu), quick_load);
  gtk_widget_add_accelerator (quick_load, "activate", accel_group,
                              GDK_F8, (GdkModifierType) 0,
                              GTK_ACCEL_VISIBLE);

  image3304 = create_pixmap (gens_window, "reload.png");
  gtk_widget_set_name (image3304, "image3304");
  gtk_widget_show (image3304);
  gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (quick_load), image3304);

  quick_save = gtk_image_menu_item_new_with_mnemonic ("Quick Save");
  gtk_widget_set_name (quick_save, "quick_save");
  gtk_widget_show (quick_save);
  gtk_container_add (GTK_CONTAINER (item15_menu), quick_save);
  gtk_widget_add_accelerator (quick_save, "activate", accel_group,
                              GDK_F5, (GdkModifierType) 0,
                              GTK_ACCEL_VISIBLE);

  image3305 = gtk_image_new_from_stock ("gtk-save", GTK_ICON_SIZE_MENU);
  gtk_widget_set_name (image3305, "image3305");
  gtk_widget_show (image3305);
  gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (quick_save), image3305);

  change_state1 = gtk_image_menu_item_new_with_mnemonic ("Change State");
  gtk_widget_set_name (change_state1, "change_state1");
  gtk_widget_show (change_state1);
  gtk_container_add (GTK_CONTAINER (item15_menu), change_state1);
  gtk_widget_add_accelerator (change_state1, "activate", accel_group,
                              GDK_F6, (GdkModifierType) 0,
                              GTK_ACCEL_VISIBLE);

  image3306 = gtk_image_new_from_stock ("gtk-revert-to-saved", GTK_ICON_SIZE_MENU);
  gtk_widget_set_name (image3306, "image3306");
  gtk_widget_show (image3306);
  gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (change_state1), image3306);

  change_state1_menu = gtk_menu_new ();
  gtk_widget_set_name (change_state1_menu, "change_state1_menu");
  gtk_menu_item_set_submenu (GTK_MENU_ITEM (change_state1), change_state1_menu);

  change_state_slot0 = gtk_radio_menu_item_new_with_mnemonic (change_state_slot0_group, "0");
  change_state_slot0_group = gtk_radio_menu_item_get_group (GTK_RADIO_MENU_ITEM (change_state_slot0));
  gtk_widget_set_name (change_state_slot0, "change_state_slot0");
  gtk_widget_show (change_state_slot0);
  gtk_container_add (GTK_CONTAINER (change_state1_menu), change_state_slot0);
  gtk_check_menu_item_set_active (GTK_CHECK_MENU_ITEM (change_state_slot0), TRUE);

  change_state_slot1 = gtk_radio_menu_item_new_with_mnemonic (change_state_slot0_group, "1");
  change_state_slot0_group = gtk_radio_menu_item_get_group (GTK_RADIO_MENU_ITEM (change_state_slot1));
  gtk_widget_set_name (change_state_slot1, "change_state_slot1");
  gtk_widget_show (change_state_slot1);
  gtk_container_add (GTK_CONTAINER (change_state1_menu), change_state_slot1);
  gtk_check_menu_item_set_active (GTK_CHECK_MENU_ITEM (change_state_slot1), TRUE);

  change_state_slot2 = gtk_radio_menu_item_new_with_mnemonic (change_state_slot0_group, "2");
  change_state_slot0_group = gtk_radio_menu_item_get_group (GTK_RADIO_MENU_ITEM (change_state_slot2));
  gtk_widget_set_name (change_state_slot2, "change_state_slot2");
  gtk_widget_show (change_state_slot2);
  gtk_container_add (GTK_CONTAINER (change_state1_menu), change_state_slot2);
  gtk_check_menu_item_set_active (GTK_CHECK_MENU_ITEM (change_state_slot2), TRUE);

  change_state_slot3 = gtk_radio_menu_item_new_with_mnemonic (change_state_slot0_group, "3");
  change_state_slot0_group = gtk_radio_menu_item_get_group (GTK_RADIO_MENU_ITEM (change_state_slot3));
  gtk_widget_set_name (change_state_slot3, "change_state_slot3");
  gtk_widget_show (change_state_slot3);
  gtk_container_add (GTK_CONTAINER (change_state1_menu), change_state_slot3);
  gtk_check_menu_item_set_active (GTK_CHECK_MENU_ITEM (change_state_slot3), TRUE);

  change_state_slot4 = gtk_radio_menu_item_new_with_mnemonic (change_state_slot0_group, "4");
  change_state_slot0_group = gtk_radio_menu_item_get_group (GTK_RADIO_MENU_ITEM (change_state_slot4));
  gtk_widget_set_name (change_state_slot4, "change_state_slot4");
  gtk_widget_show (change_state_slot4);
  gtk_container_add (GTK_CONTAINER (change_state1_menu), change_state_slot4);
  gtk_check_menu_item_set_active (GTK_CHECK_MENU_ITEM (change_state_slot4), TRUE);

  change_state_slot5 = gtk_radio_menu_item_new_with_mnemonic (change_state_slot0_group, "5");
  change_state_slot0_group = gtk_radio_menu_item_get_group (GTK_RADIO_MENU_ITEM (change_state_slot5));
  gtk_widget_set_name (change_state_slot5, "change_state_slot5");
  gtk_widget_show (change_state_slot5);
  gtk_container_add (GTK_CONTAINER (change_state1_menu), change_state_slot5);
  gtk_check_menu_item_set_active (GTK_CHECK_MENU_ITEM (change_state_slot5), TRUE);

  change_state_slot6 = gtk_radio_menu_item_new_with_mnemonic (change_state_slot0_group, "6");
  change_state_slot0_group = gtk_radio_menu_item_get_group (GTK_RADIO_MENU_ITEM (change_state_slot6));
  gtk_widget_set_name (change_state_slot6, "change_state_slot6");
  gtk_widget_show (change_state_slot6);
  gtk_container_add (GTK_CONTAINER (change_state1_menu), change_state_slot6);
  gtk_check_menu_item_set_active (GTK_CHECK_MENU_ITEM (change_state_slot6), TRUE);

  change_state_slot7 = gtk_radio_menu_item_new_with_mnemonic (change_state_slot0_group, "7");
  change_state_slot0_group = gtk_radio_menu_item_get_group (GTK_RADIO_MENU_ITEM (change_state_slot7));
  gtk_widget_set_name (change_state_slot7, "change_state_slot7");
  gtk_widget_show (change_state_slot7);
  gtk_container_add (GTK_CONTAINER (change_state1_menu), change_state_slot7);
  gtk_check_menu_item_set_active (GTK_CHECK_MENU_ITEM (change_state_slot7), TRUE);

  change_state_slot8 = gtk_radio_menu_item_new_with_mnemonic (change_state_slot0_group, "8");
  change_state_slot0_group = gtk_radio_menu_item_get_group (GTK_RADIO_MENU_ITEM (change_state_slot8));
  gtk_widget_set_name (change_state_slot8, "change_state_slot8");
  gtk_widget_show (change_state_slot8);
  gtk_container_add (GTK_CONTAINER (change_state1_menu), change_state_slot8);
  gtk_check_menu_item_set_active (GTK_CHECK_MENU_ITEM (change_state_slot8), TRUE);

  change_state_slot9 = gtk_radio_menu_item_new_with_mnemonic (change_state_slot0_group, "9");
  change_state_slot0_group = gtk_radio_menu_item_get_group (GTK_RADIO_MENU_ITEM (change_state_slot9));
  gtk_widget_set_name (change_state_slot9, "change_state_slot9");
  gtk_widget_show (change_state_slot9);
  gtk_container_add (GTK_CONTAINER (change_state1_menu), change_state_slot9);
  gtk_check_menu_item_set_active (GTK_CHECK_MENU_ITEM (change_state_slot9), TRUE);

  separator16 = gtk_separator_menu_item_new ();
  gtk_widget_set_name (separator16, "separator16");
  gtk_widget_show (separator16);
  gtk_container_add (GTK_CONTAINER (item15_menu), separator16);
  gtk_widget_set_sensitive (separator16, FALSE);

  quit = gtk_image_menu_item_new_with_mnemonic ("Quit");
  gtk_widget_set_name (quit, "quit");
  gtk_widget_show (quit);
  gtk_container_add (GTK_CONTAINER (item15_menu), quit);

  image3307 = gtk_image_new_from_stock ("gtk-quit", GTK_ICON_SIZE_MENU);
  gtk_widget_set_name (image3307, "image3307");
  gtk_widget_show (image3307);
  gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (quit), image3307);

  item3 = gtk_image_menu_item_new_with_mnemonic ("Graphic");
  gtk_widget_set_name (item3, "item3");
  gtk_widget_show (item3);
  gtk_container_add (GTK_CONTAINER (menubar1), item3);

  image3308 = create_pixmap (gens_window, "xpaint.png");
  gtk_widget_set_name (image3308, "image3308");
  gtk_widget_show (image3308);
  gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (item3), image3308);

  item3_menu = gtk_menu_new ();
  gtk_widget_set_name (item3_menu, "item3_menu");
  gtk_menu_item_set_submenu (GTK_MENU_ITEM (item3), item3_menu);

  full_screen = gtk_image_menu_item_new_with_mnemonic ("Full Screen");
  gtk_widget_set_name (full_screen, "full_screen");
  gtk_widget_show (full_screen);
  gtk_container_add (GTK_CONTAINER (item3_menu), full_screen);
  gtk_widget_add_accelerator (full_screen, "activate", accel_group,
                              GDK_Return, (GdkModifierType) GDK_MOD1_MASK,
                              GTK_ACCEL_VISIBLE);

  image3309 = create_pixmap (gens_window, "viewmag1.png");
  gtk_widget_set_name (image3309, "image3309");
  gtk_widget_show (image3309);
  gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (full_screen), image3309);

  vsync = gtk_check_menu_item_new_with_mnemonic ("VSync");
  gtk_widget_set_name (vsync, "vsync");
  gtk_widget_show (vsync);
  gtk_container_add (GTK_CONTAINER (item3_menu), vsync);
  gtk_widget_add_accelerator (vsync, "activate", accel_group,
                              GDK_F3, (GdkModifierType) GDK_SHIFT_MASK,
                              GTK_ACCEL_VISIBLE);

  stretch = gtk_check_menu_item_new_with_mnemonic ("Stretch");
  gtk_widget_set_name (stretch, "stretch");
  gtk_widget_show (stretch);
  gtk_container_add (GTK_CONTAINER (item3_menu), stretch);
  gtk_widget_add_accelerator (stretch, "activate", accel_group,
                              GDK_F2, (GdkModifierType) GDK_SHIFT_MASK,
                              GTK_ACCEL_VISIBLE);

  separator17 = gtk_separator_menu_item_new ();
  gtk_widget_set_name (separator17, "separator17");
  gtk_widget_show (separator17);
  gtk_container_add (GTK_CONTAINER (item3_menu), separator17);
  gtk_widget_set_sensitive (separator17, FALSE);

  opengl = gtk_check_menu_item_new_with_mnemonic ("OpenGL");
  gtk_widget_set_name (opengl, "opengl");
  gtk_widget_show (opengl);
  gtk_container_add (GTK_CONTAINER (item3_menu), opengl);
  gtk_widget_add_accelerator (opengl, "activate", accel_group,
                              GDK_r, (GdkModifierType) GDK_SHIFT_MASK,
                              GTK_ACCEL_VISIBLE);

  opengl_resolution = gtk_menu_item_new_with_mnemonic ("OpenGL Resolution");
  gtk_widget_set_name (opengl_resolution, "opengl_resolution");
  gtk_widget_show (opengl_resolution);
  gtk_container_add (GTK_CONTAINER (item3_menu), opengl_resolution);

  opengl_resolution_menu = gtk_menu_new ();
  gtk_widget_set_name (opengl_resolution_menu, "opengl_resolution_menu");
  gtk_menu_item_set_submenu (GTK_MENU_ITEM (opengl_resolution), opengl_resolution_menu);

  _320x240 = gtk_radio_menu_item_new_with_mnemonic (_320x240_group, "320x240");
  _320x240_group = gtk_radio_menu_item_get_group (GTK_RADIO_MENU_ITEM (_320x240));
  gtk_widget_set_name (_320x240, "_320x240");
  gtk_widget_show (_320x240);
  gtk_container_add (GTK_CONTAINER (opengl_resolution_menu), _320x240);
  gtk_check_menu_item_set_active (GTK_CHECK_MENU_ITEM (_320x240), TRUE);

  _640x480 = gtk_radio_menu_item_new_with_mnemonic (_320x240_group, "640x480");
  _320x240_group = gtk_radio_menu_item_get_group (GTK_RADIO_MENU_ITEM (_640x480));
  gtk_widget_set_name (_640x480, "_640x480");
  gtk_widget_show (_640x480);
  gtk_container_add (GTK_CONTAINER (opengl_resolution_menu), _640x480);
  gtk_check_menu_item_set_active (GTK_CHECK_MENU_ITEM (_640x480), TRUE);

  _800x600 = gtk_radio_menu_item_new_with_mnemonic (_320x240_group, "800x600");
  _320x240_group = gtk_radio_menu_item_get_group (GTK_RADIO_MENU_ITEM (_800x600));
  gtk_widget_set_name (_800x600, "_800x600");
  gtk_widget_show (_800x600);
  gtk_container_add (GTK_CONTAINER (opengl_resolution_menu), _800x600);
  gtk_check_menu_item_set_active (GTK_CHECK_MENU_ITEM (_800x600), TRUE);

  _1024x768 = gtk_radio_menu_item_new_with_mnemonic (_320x240_group, "1024x768");
  _320x240_group = gtk_radio_menu_item_get_group (GTK_RADIO_MENU_ITEM (_1024x768));
  gtk_widget_set_name (_1024x768, "_1024x768");
  gtk_widget_show (_1024x768);
  gtk_container_add (GTK_CONTAINER (opengl_resolution_menu), _1024x768);
  gtk_check_menu_item_set_active (GTK_CHECK_MENU_ITEM (_1024x768), TRUE);

  custom = gtk_radio_menu_item_new_with_mnemonic (_320x240_group, "Custom");
  _320x240_group = gtk_radio_menu_item_get_group (GTK_RADIO_MENU_ITEM (custom));
  gtk_widget_set_name (custom, "custom");
  gtk_widget_show (custom);
  gtk_container_add (GTK_CONTAINER (opengl_resolution_menu), custom);
  gtk_check_menu_item_set_active (GTK_CHECK_MENU_ITEM (custom), TRUE);

  bits_per_pixel1 = gtk_menu_item_new_with_mnemonic ("Bits per pixel");
  gtk_widget_set_name (bits_per_pixel1, "bits_per_pixel1");
  gtk_widget_show (bits_per_pixel1);
  gtk_container_add (GTK_CONTAINER (item3_menu), bits_per_pixel1);

  bits_per_pixel1_menu = gtk_menu_new ();
  gtk_widget_set_name (bits_per_pixel1_menu, "bits_per_pixel1_menu");
  gtk_menu_item_set_submenu (GTK_MENU_ITEM (bits_per_pixel1), bits_per_pixel1_menu);

  bpp16 = gtk_radio_menu_item_new_with_mnemonic (bpp16_group, "16");
  bpp16_group = gtk_radio_menu_item_get_group (GTK_RADIO_MENU_ITEM (bpp16));
  gtk_widget_set_name (bpp16, "bpp16");
  gtk_widget_show (bpp16);
  gtk_container_add (GTK_CONTAINER (bits_per_pixel1_menu), bpp16);
  gtk_check_menu_item_set_active (GTK_CHECK_MENU_ITEM (bpp16), TRUE);

  bpp24 = gtk_radio_menu_item_new_with_mnemonic (bpp16_group, "24");
  bpp16_group = gtk_radio_menu_item_get_group (GTK_RADIO_MENU_ITEM (bpp24));
  gtk_widget_set_name (bpp24, "bpp24");
  gtk_widget_show (bpp24);
  gtk_container_add (GTK_CONTAINER (bits_per_pixel1_menu), bpp24);
  gtk_check_menu_item_set_active (GTK_CHECK_MENU_ITEM (bpp24), TRUE);

  bpp32 = gtk_radio_menu_item_new_with_mnemonic (bpp16_group, "32");
  bpp16_group = gtk_radio_menu_item_get_group (GTK_RADIO_MENU_ITEM (bpp32));
  gtk_widget_set_name (bpp32, "bpp32");
  gtk_widget_show (bpp32);
  gtk_container_add (GTK_CONTAINER (bits_per_pixel1_menu), bpp32);
  gtk_check_menu_item_set_active (GTK_CHECK_MENU_ITEM (bpp32), TRUE);

  separator18 = gtk_separator_menu_item_new ();
  gtk_widget_set_name (separator18, "separator18");
  gtk_widget_show (separator18);
  gtk_container_add (GTK_CONTAINER (item3_menu), separator18);
  gtk_widget_set_sensitive (separator18, FALSE);

  color_adjust = gtk_image_menu_item_new_with_mnemonic ("Color Adjust...");
  gtk_widget_set_name (color_adjust, "color_adjust");
  gtk_widget_show (color_adjust);
  gtk_container_add (GTK_CONTAINER (item3_menu), color_adjust);

  image3310 = gtk_image_new_from_stock ("gtk-select-color", GTK_ICON_SIZE_MENU);
  gtk_widget_set_name (image3310, "image3310");
  gtk_widget_show (image3310);
  gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (color_adjust), image3310);

  item4 = gtk_image_menu_item_new_with_mnemonic ("Render");
  gtk_widget_set_name (item4, "item4");
  gtk_widget_show (item4);
  gtk_container_add (GTK_CONTAINER (item3_menu), item4);

  image3311 = create_pixmap (gens_window, "viewmag.png");
  gtk_widget_set_name (image3311, "image3311");
  gtk_widget_show (image3311);
  gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (item4), image3311);

  item4_menu = gtk_menu_new ();
  gtk_widget_set_name (item4_menu, "item4_menu");
  gtk_menu_item_set_submenu (GTK_MENU_ITEM (item4), item4_menu);

  normal = gtk_radio_menu_item_new_with_mnemonic (normal_group, "Normal");
  normal_group = gtk_radio_menu_item_get_group (GTK_RADIO_MENU_ITEM (normal));
  gtk_widget_set_name (normal, "normal");
  gtk_widget_show (normal);
  gtk_container_add (GTK_CONTAINER (item4_menu), normal);
  gtk_check_menu_item_set_active (GTK_CHECK_MENU_ITEM (normal), TRUE);

  _double = gtk_radio_menu_item_new_with_mnemonic (normal_group, "Double");
  normal_group = gtk_radio_menu_item_get_group (GTK_RADIO_MENU_ITEM (_double));
  gtk_widget_set_name (_double, "_double");
  gtk_widget_show (_double);
  gtk_container_add (GTK_CONTAINER (item4_menu), _double);
  gtk_check_menu_item_set_active (GTK_CHECK_MENU_ITEM (_double), TRUE);

  interpolated = gtk_radio_menu_item_new_with_mnemonic (normal_group, "Interpolated");
  normal_group = gtk_radio_menu_item_get_group (GTK_RADIO_MENU_ITEM (interpolated));
  gtk_widget_set_name (interpolated, "interpolated");
  gtk_widget_show (interpolated);
  gtk_container_add (GTK_CONTAINER (item4_menu), interpolated);
  gtk_check_menu_item_set_active (GTK_CHECK_MENU_ITEM (interpolated), TRUE);

  scanline = gtk_radio_menu_item_new_with_mnemonic (normal_group, "Scanline");
  normal_group = gtk_radio_menu_item_get_group (GTK_RADIO_MENU_ITEM (scanline));
  gtk_widget_set_name (scanline, "scanline");
  gtk_widget_show (scanline);
  gtk_container_add (GTK_CONTAINER (item4_menu), scanline);
  gtk_check_menu_item_set_active (GTK_CHECK_MENU_ITEM (scanline), TRUE);

  _50_scanline = gtk_radio_menu_item_new_with_mnemonic (normal_group, "50% Scanline");
  normal_group = gtk_radio_menu_item_get_group (GTK_RADIO_MENU_ITEM (_50_scanline));
  gtk_widget_set_name (_50_scanline, "_50_scanline");
  gtk_widget_show (_50_scanline);
  gtk_container_add (GTK_CONTAINER (item4_menu), _50_scanline);
  gtk_check_menu_item_set_active (GTK_CHECK_MENU_ITEM (_50_scanline), TRUE);

  _25_scanline = gtk_radio_menu_item_new_with_mnemonic (normal_group, "25% Scanline");
  normal_group = gtk_radio_menu_item_get_group (GTK_RADIO_MENU_ITEM (_25_scanline));
  gtk_widget_set_name (_25_scanline, "_25_scanline");
  gtk_widget_show (_25_scanline);
  gtk_container_add (GTK_CONTAINER (item4_menu), _25_scanline);
  gtk_check_menu_item_set_active (GTK_CHECK_MENU_ITEM (_25_scanline), TRUE);

  interpolated_scanline = gtk_radio_menu_item_new_with_mnemonic (normal_group, "Interpolated Scanline");
  normal_group = gtk_radio_menu_item_get_group (GTK_RADIO_MENU_ITEM (interpolated_scanline));
  gtk_widget_set_name (interpolated_scanline, "interpolated_scanline");
  gtk_widget_show (interpolated_scanline);
  gtk_container_add (GTK_CONTAINER (item4_menu), interpolated_scanline);
  gtk_check_menu_item_set_active (GTK_CHECK_MENU_ITEM (interpolated_scanline), TRUE);

  interpolated_50_scanline = gtk_radio_menu_item_new_with_mnemonic (normal_group, "Interpolated 50% Scanline");
  normal_group = gtk_radio_menu_item_get_group (GTK_RADIO_MENU_ITEM (interpolated_50_scanline));
  gtk_widget_set_name (interpolated_50_scanline, "interpolated_50_scanline");
  gtk_widget_show (interpolated_50_scanline);
  gtk_container_add (GTK_CONTAINER (item4_menu), interpolated_50_scanline);
  gtk_check_menu_item_set_active (GTK_CHECK_MENU_ITEM (interpolated_50_scanline), TRUE);

  interpolated_25_scanline = gtk_radio_menu_item_new_with_mnemonic (normal_group, "Interpolated 25% Scanline");
  normal_group = gtk_radio_menu_item_get_group (GTK_RADIO_MENU_ITEM (interpolated_25_scanline));
  gtk_widget_set_name (interpolated_25_scanline, "interpolated_25_scanline");
  gtk_widget_show (interpolated_25_scanline);
  gtk_container_add (GTK_CONTAINER (item4_menu), interpolated_25_scanline);
  gtk_check_menu_item_set_active (GTK_CHECK_MENU_ITEM (interpolated_25_scanline), TRUE);

  _2xsai_kreed = gtk_radio_menu_item_new_with_mnemonic (normal_group, "2xSAI (Kreed)");
  normal_group = gtk_radio_menu_item_get_group (GTK_RADIO_MENU_ITEM (_2xsai_kreed));
  gtk_widget_set_name (_2xsai_kreed, "_2xsai_kreed");
  gtk_widget_show (_2xsai_kreed);
  gtk_container_add (GTK_CONTAINER (item4_menu), _2xsai_kreed);
  gtk_check_menu_item_set_active (GTK_CHECK_MENU_ITEM (_2xsai_kreed), TRUE);

  _scale2x = gtk_radio_menu_item_new_with_mnemonic (normal_group, "Scale2x");
  normal_group = gtk_radio_menu_item_get_group (GTK_RADIO_MENU_ITEM (_scale2x));
  gtk_widget_set_name (_scale2x, "_scale2x");
  gtk_widget_show (_scale2x);
  gtk_container_add (GTK_CONTAINER (item4_menu), _scale2x);
  gtk_check_menu_item_set_active (GTK_CHECK_MENU_ITEM (_scale2x), TRUE);

  hq2x = gtk_radio_menu_item_new_with_mnemonic (normal_group, "Hq2x");
  normal_group = gtk_radio_menu_item_get_group (GTK_RADIO_MENU_ITEM (hq2x));
  gtk_widget_set_name (hq2x, "hq2x");
  gtk_widget_show (hq2x);
  gtk_container_add (GTK_CONTAINER (item4_menu), hq2x);
  gtk_check_menu_item_set_active (GTK_CHECK_MENU_ITEM (hq2x), TRUE);

  separator4 = gtk_separator_menu_item_new ();
  gtk_widget_set_name (separator4, "separator4");
  gtk_widget_show (separator4);
  gtk_container_add (GTK_CONTAINER (item3_menu), separator4);
  gtk_widget_set_sensitive (separator4, FALSE);

  sprite_limit = gtk_check_menu_item_new_with_mnemonic ("Sprite Limit");
  gtk_widget_set_name (sprite_limit, "sprite_limit");
  gtk_widget_show (sprite_limit);
  gtk_container_add (GTK_CONTAINER (item3_menu), sprite_limit);
  gtk_check_menu_item_set_active (GTK_CHECK_MENU_ITEM (sprite_limit), TRUE);

  separator5 = gtk_separator_menu_item_new ();
  gtk_widget_set_name (separator5, "separator5");
  gtk_widget_show (separator5);
  gtk_container_add (GTK_CONTAINER (item3_menu), separator5);
  gtk_widget_set_sensitive (separator5, FALSE);

  item5 = gtk_image_menu_item_new_with_mnemonic ("Frame Skip");
  gtk_widget_set_name (item5, "item5");
  gtk_widget_show (item5);
  gtk_container_add (GTK_CONTAINER (item3_menu), item5);

  image3312 = create_pixmap (gens_window, "2rightarrow.png");
  gtk_widget_set_name (image3312, "image3312");
  gtk_widget_show (image3312);
  gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (item5), image3312);

  item5_menu = gtk_menu_new ();
  gtk_widget_set_name (item5_menu, "item5_menu");
  gtk_menu_item_set_submenu (GTK_MENU_ITEM (item5), item5_menu);

  frame_auto_skip = gtk_radio_menu_item_new_with_mnemonic (frame_auto_skip_group, "Auto");
  frame_auto_skip_group = gtk_radio_menu_item_get_group (GTK_RADIO_MENU_ITEM (frame_auto_skip));
  gtk_widget_set_name (frame_auto_skip, "frame_auto_skip");
  gtk_widget_show (frame_auto_skip);
  gtk_container_add (GTK_CONTAINER (item5_menu), frame_auto_skip);
  gtk_check_menu_item_set_active (GTK_CHECK_MENU_ITEM (frame_auto_skip), TRUE);

  frame_0_skip = gtk_radio_menu_item_new_with_mnemonic (frame_auto_skip_group, "0");
  frame_auto_skip_group = gtk_radio_menu_item_get_group (GTK_RADIO_MENU_ITEM (frame_0_skip));
  gtk_widget_set_name (frame_0_skip, "frame_0_skip");
  gtk_widget_show (frame_0_skip);
  gtk_container_add (GTK_CONTAINER (item5_menu), frame_0_skip);
  gtk_check_menu_item_set_active (GTK_CHECK_MENU_ITEM (frame_0_skip), TRUE);

  frame_1_skip = gtk_radio_menu_item_new_with_mnemonic (frame_auto_skip_group, "1");
  frame_auto_skip_group = gtk_radio_menu_item_get_group (GTK_RADIO_MENU_ITEM (frame_1_skip));
  gtk_widget_set_name (frame_1_skip, "frame_1_skip");
  gtk_widget_show (frame_1_skip);
  gtk_container_add (GTK_CONTAINER (item5_menu), frame_1_skip);
  gtk_check_menu_item_set_active (GTK_CHECK_MENU_ITEM (frame_1_skip), TRUE);

  frame_2_skip = gtk_radio_menu_item_new_with_mnemonic (frame_auto_skip_group, "2");
  frame_auto_skip_group = gtk_radio_menu_item_get_group (GTK_RADIO_MENU_ITEM (frame_2_skip));
  gtk_widget_set_name (frame_2_skip, "frame_2_skip");
  gtk_widget_show (frame_2_skip);
  gtk_container_add (GTK_CONTAINER (item5_menu), frame_2_skip);
  gtk_check_menu_item_set_active (GTK_CHECK_MENU_ITEM (frame_2_skip), TRUE);

  frame_3_skip = gtk_radio_menu_item_new_with_mnemonic (frame_auto_skip_group, "3");
  frame_auto_skip_group = gtk_radio_menu_item_get_group (GTK_RADIO_MENU_ITEM (frame_3_skip));
  gtk_widget_set_name (frame_3_skip, "frame_3_skip");
  gtk_widget_show (frame_3_skip);
  gtk_container_add (GTK_CONTAINER (item5_menu), frame_3_skip);
  gtk_check_menu_item_set_active (GTK_CHECK_MENU_ITEM (frame_3_skip), TRUE);

  frame_4_skip = gtk_radio_menu_item_new_with_mnemonic (frame_auto_skip_group, "4");
  frame_auto_skip_group = gtk_radio_menu_item_get_group (GTK_RADIO_MENU_ITEM (frame_4_skip));
  gtk_widget_set_name (frame_4_skip, "frame_4_skip");
  gtk_widget_show (frame_4_skip);
  gtk_container_add (GTK_CONTAINER (item5_menu), frame_4_skip);
  gtk_check_menu_item_set_active (GTK_CHECK_MENU_ITEM (frame_4_skip), TRUE);

  frame_5_skip = gtk_radio_menu_item_new_with_mnemonic (frame_auto_skip_group, "5");
  frame_auto_skip_group = gtk_radio_menu_item_get_group (GTK_RADIO_MENU_ITEM (frame_5_skip));
  gtk_widget_set_name (frame_5_skip, "frame_5_skip");
  gtk_widget_show (frame_5_skip);
  gtk_container_add (GTK_CONTAINER (item5_menu), frame_5_skip);
  gtk_check_menu_item_set_active (GTK_CHECK_MENU_ITEM (frame_5_skip), TRUE);

  frame_6_skip = gtk_radio_menu_item_new_with_mnemonic (frame_auto_skip_group, "6");
  frame_auto_skip_group = gtk_radio_menu_item_get_group (GTK_RADIO_MENU_ITEM (frame_6_skip));
  gtk_widget_set_name (frame_6_skip, "frame_6_skip");
  gtk_widget_show (frame_6_skip);
  gtk_container_add (GTK_CONTAINER (item5_menu), frame_6_skip);
  gtk_check_menu_item_set_active (GTK_CHECK_MENU_ITEM (frame_6_skip), TRUE);

  frame_7_skip = gtk_radio_menu_item_new_with_mnemonic (frame_auto_skip_group, "7");
  frame_auto_skip_group = gtk_radio_menu_item_get_group (GTK_RADIO_MENU_ITEM (frame_7_skip));
  gtk_widget_set_name (frame_7_skip, "frame_7_skip");
  gtk_widget_show (frame_7_skip);
  gtk_container_add (GTK_CONTAINER (item5_menu), frame_7_skip);
  gtk_check_menu_item_set_active (GTK_CHECK_MENU_ITEM (frame_7_skip), TRUE);

  frame_8_skip = gtk_radio_menu_item_new_with_mnemonic (frame_auto_skip_group, "8");
  frame_auto_skip_group = gtk_radio_menu_item_get_group (GTK_RADIO_MENU_ITEM (frame_8_skip));
  gtk_widget_set_name (frame_8_skip, "frame_8_skip");
  gtk_widget_show (frame_8_skip);
  gtk_container_add (GTK_CONTAINER (item5_menu), frame_8_skip);
  gtk_check_menu_item_set_active (GTK_CHECK_MENU_ITEM (frame_8_skip), TRUE);

  separator15 = gtk_separator_menu_item_new ();
  gtk_widget_set_name (separator15, "separator15");
  gtk_widget_show (separator15);
  gtk_container_add (GTK_CONTAINER (item3_menu), separator15);
  gtk_widget_set_sensitive (separator15, FALSE);

  screen_shot = gtk_image_menu_item_new_with_mnemonic ("Screen Shot");
  gtk_widget_set_name (screen_shot, "screen_shot");
  gtk_widget_show (screen_shot);
  gtk_container_add (GTK_CONTAINER (item3_menu), screen_shot);
  gtk_widget_add_accelerator (screen_shot, "activate", accel_group,
                              GDK_BackSpace, (GdkModifierType) GDK_SHIFT_MASK,
                              GTK_ACCEL_VISIBLE);

  image3313 = create_pixmap (gens_window, "editcopy.png");
  gtk_widget_set_name (image3313, "image3313");
  gtk_widget_show (image3313);
  gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (screen_shot), image3313);

  menuitem3 = gtk_image_menu_item_new_with_mnemonic ("CPU");
  gtk_widget_set_name (menuitem3, "menuitem3");
  gtk_widget_show (menuitem3);
  gtk_container_add (GTK_CONTAINER (menubar1), menuitem3);

  image3314 = create_pixmap (gens_window, "memory.png");
  gtk_widget_set_name (image3314, "image3314");
  gtk_widget_show (image3314);
  gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (menuitem3), image3314);

  menuitem3_menu = gtk_menu_new ();
  gtk_widget_set_name (menuitem3_menu, "menuitem3_menu");
  gtk_menu_item_set_submenu (GTK_MENU_ITEM (menuitem3), menuitem3_menu);

  item6 = gtk_menu_item_new_with_mnemonic ("Debug");
  gtk_widget_set_name (item6, "item6");
  gtk_widget_show (item6);
  gtk_container_add (GTK_CONTAINER (menuitem3_menu), item6);

  item6_menu = gtk_menu_new ();
  gtk_widget_set_name (item6_menu, "item6_menu");
  gtk_menu_item_set_submenu (GTK_MENU_ITEM (item6), item6_menu);

  genesis_68000 = gtk_check_menu_item_new_with_mnemonic ("_Genesis - 68000");
  gtk_widget_set_name (genesis_68000, "genesis_68000");
  gtk_widget_show (genesis_68000);
  gtk_container_add (GTK_CONTAINER (item6_menu), genesis_68000);

  genesis_z80 = gtk_check_menu_item_new_with_mnemonic ("Genesis - _Z80");
  gtk_widget_set_name (genesis_z80, "genesis_z80");
  gtk_widget_show (genesis_z80);
  gtk_container_add (GTK_CONTAINER (item6_menu), genesis_z80);

  genesis_vdp = gtk_check_menu_item_new_with_mnemonic ("Genesis - _VDP");
  gtk_widget_set_name (genesis_vdp, "genesis_vdp");
  gtk_widget_show (genesis_vdp);
  gtk_container_add (GTK_CONTAINER (item6_menu), genesis_vdp);

  segacd_68000 = gtk_check_menu_item_new_with_mnemonic ("_SegaCD - 68000");
  gtk_widget_set_name (segacd_68000, "segacd_68000");
  gtk_widget_show (segacd_68000);
  gtk_container_add (GTK_CONTAINER (item6_menu), segacd_68000);

  segacd_cdc = gtk_check_menu_item_new_with_mnemonic ("SegaCD - _CDC");
  gtk_widget_set_name (segacd_cdc, "segacd_cdc");
  gtk_widget_show (segacd_cdc);
  gtk_container_add (GTK_CONTAINER (item6_menu), segacd_cdc);

  segacd_gfx = gtk_check_menu_item_new_with_mnemonic ("SegaCD - GF_X");
  gtk_widget_set_name (segacd_gfx, "segacd_gfx");
  gtk_widget_show (segacd_gfx);
  gtk_container_add (GTK_CONTAINER (item6_menu), segacd_gfx);

  _32x_main_sh2 = gtk_check_menu_item_new_with_mnemonic ("32X - main SH2");
  gtk_widget_set_name (_32x_main_sh2, "_32x_main_sh2");
  gtk_widget_show (_32x_main_sh2);
  gtk_container_add (GTK_CONTAINER (item6_menu), _32x_main_sh2);

  _32x_sub_sh2 = gtk_check_menu_item_new_with_mnemonic ("32X - sub SH2");
  gtk_widget_set_name (_32x_sub_sh2, "_32x_sub_sh2");
  gtk_widget_show (_32x_sub_sh2);
  gtk_container_add (GTK_CONTAINER (item6_menu), _32x_sub_sh2);

  _32x_vdp = gtk_check_menu_item_new_with_mnemonic ("32X - VDP");
  gtk_widget_set_name (_32x_vdp, "_32x_vdp");
  gtk_widget_show (_32x_vdp);
  gtk_container_add (GTK_CONTAINER (item6_menu), _32x_vdp);

  separator6 = gtk_separator_menu_item_new ();
  gtk_widget_set_name (separator6, "separator6");
  gtk_widget_show (separator6);
  gtk_container_add (GTK_CONTAINER (menuitem3_menu), separator6);
  gtk_widget_set_sensitive (separator6, FALSE);

  country = gtk_menu_item_new_with_mnemonic ("Country");
  gtk_widget_set_name (country, "country");
  gtk_widget_show (country);
  gtk_container_add (GTK_CONTAINER (menuitem3_menu), country);

  country_menu = gtk_menu_new ();
  gtk_widget_set_name (country_menu, "country_menu");
  gtk_menu_item_set_submenu (GTK_MENU_ITEM (country), country_menu);

  auto_detect = gtk_menu_item_new_with_mnemonic ("Auto Detect");
  gtk_widget_set_name (auto_detect, "auto_detect");
  gtk_widget_show (auto_detect);
  gtk_container_add (GTK_CONTAINER (country_menu), auto_detect);

  japan_ntsc = gtk_menu_item_new_with_mnemonic ("Japan (NTSC)");
  gtk_widget_set_name (japan_ntsc, "japan_ntsc");
  gtk_widget_show (japan_ntsc);
  gtk_container_add (GTK_CONTAINER (country_menu), japan_ntsc);

  usa_ntsc = gtk_menu_item_new_with_mnemonic ("USA (NTSC)");
  gtk_widget_set_name (usa_ntsc, "usa_ntsc");
  gtk_widget_show (usa_ntsc);
  gtk_container_add (GTK_CONTAINER (country_menu), usa_ntsc);

  europe_pal = gtk_menu_item_new_with_mnemonic ("Europe (PAL)");
  gtk_widget_set_name (europe_pal, "europe_pal");
  gtk_widget_show (europe_pal);
  gtk_container_add (GTK_CONTAINER (country_menu), europe_pal);

  japan_pal = gtk_menu_item_new_with_mnemonic ("Japan (PAL)");
  gtk_widget_set_name (japan_pal, "japan_pal");
  gtk_widget_show (japan_pal);
  gtk_container_add (GTK_CONTAINER (country_menu), japan_pal);

  separator9 = gtk_separator_menu_item_new ();
  gtk_widget_set_name (separator9, "separator9");
  gtk_widget_show (separator9);
  gtk_container_add (GTK_CONTAINER (country_menu), separator9);
  gtk_widget_set_sensitive (separator9, FALSE);

  item7 = gtk_menu_item_new_with_mnemonic ("Auto detection order");
  gtk_widget_set_name (item7, "item7");
  gtk_widget_show (item7);
  gtk_container_add (GTK_CONTAINER (country_menu), item7);

  item7_menu = gtk_menu_new ();
  gtk_widget_set_name (item7_menu, "item7_menu");
  gtk_menu_item_set_submenu (GTK_MENU_ITEM (item7), item7_menu);

  detection_order_usa = gtk_menu_item_new_with_mnemonic ("USA (NTSC)");
  gtk_widget_set_name (detection_order_usa, "detection_order_usa");
  gtk_widget_show (detection_order_usa);
  gtk_container_add (GTK_CONTAINER (item7_menu), detection_order_usa);

  detection_order_japan = gtk_menu_item_new_with_mnemonic ("Japan (NTSC)");
  gtk_widget_set_name (detection_order_japan, "detection_order_japan");
  gtk_widget_show (detection_order_japan);
  gtk_container_add (GTK_CONTAINER (item7_menu), detection_order_japan);

  detection_order_europe = gtk_menu_item_new_with_mnemonic ("Europe (PAL)");
  gtk_widget_set_name (detection_order_europe, "detection_order_europe");
  gtk_widget_show (detection_order_europe);
  gtk_container_add (GTK_CONTAINER (item7_menu), detection_order_europe);

  separator7 = gtk_separator_menu_item_new ();
  gtk_widget_set_name (separator7, "separator7");
  gtk_widget_show (separator7);
  gtk_container_add (GTK_CONTAINER (menuitem3_menu), separator7);
  gtk_widget_set_sensitive (separator7, FALSE);

  hard_reset = gtk_image_menu_item_new_with_mnemonic ("Hard Reset");
  gtk_widget_set_name (hard_reset, "hard_reset");
  gtk_widget_show (hard_reset);
  gtk_container_add (GTK_CONTAINER (menuitem3_menu), hard_reset);
  gtk_widget_add_accelerator (hard_reset, "activate", accel_group,
                              GDK_Tab, (GdkModifierType) 0,
                              GTK_ACCEL_VISIBLE);

  image3315 = create_pixmap (gens_window, "reload.png");
  gtk_widget_set_name (image3315, "image3315");
  gtk_widget_show (image3315);
  gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (hard_reset), image3315);

  reset_main_68000 = gtk_menu_item_new_with_mnemonic ("Reset Main 68000");
  gtk_widget_set_name (reset_main_68000, "reset_main_68000");
  gtk_widget_show (reset_main_68000);
  gtk_container_add (GTK_CONTAINER (menuitem3_menu), reset_main_68000);

  reset_sub_68000 = gtk_menu_item_new_with_mnemonic ("Reset Sub 68000");
  gtk_widget_set_name (reset_sub_68000, "reset_sub_68000");
  gtk_widget_show (reset_sub_68000);
  gtk_container_add (GTK_CONTAINER (menuitem3_menu), reset_sub_68000);

  reset_68000 = gtk_menu_item_new_with_mnemonic ("Reset 68000");
  gtk_widget_set_name (reset_68000, "reset_68000");
  gtk_widget_show (reset_68000);
  gtk_container_add (GTK_CONTAINER (menuitem3_menu), reset_68000);

  reset_main_sh2 = gtk_menu_item_new_with_mnemonic ("Reset main SH2");
  gtk_widget_set_name (reset_main_sh2, "reset_main_sh2");
  gtk_widget_show (reset_main_sh2);
  gtk_container_add (GTK_CONTAINER (menuitem3_menu), reset_main_sh2);

  reset_sub_sh2 = gtk_menu_item_new_with_mnemonic ("Reset sub SH2");
  gtk_widget_set_name (reset_sub_sh2, "reset_sub_sh2");
  gtk_widget_show (reset_sub_sh2);
  gtk_container_add (GTK_CONTAINER (menuitem3_menu), reset_sub_sh2);

  reset_z80 = gtk_menu_item_new_with_mnemonic ("Reset Z80");
  gtk_widget_set_name (reset_z80, "reset_z80");
  gtk_widget_show (reset_z80);
  gtk_container_add (GTK_CONTAINER (menuitem3_menu), reset_z80);

  separator8 = gtk_separator_menu_item_new ();
  gtk_widget_set_name (separator8, "separator8");
  gtk_widget_show (separator8);
  gtk_container_add (GTK_CONTAINER (menuitem3_menu), separator8);
  gtk_widget_set_sensitive (separator8, FALSE);

  perfect_synchro = gtk_check_menu_item_new_with_mnemonic ("Perfect Synchro (SLOW)");
  gtk_widget_set_name (perfect_synchro, "perfect_synchro");
  gtk_widget_show (perfect_synchro);
  gtk_container_add (GTK_CONTAINER (menuitem3_menu), perfect_synchro);

  item8 = gtk_image_menu_item_new_with_mnemonic ("Sound");
  gtk_widget_set_name (item8, "item8");
  gtk_widget_show (item8);
  gtk_container_add (GTK_CONTAINER (menubar1), item8);

  image3316 = create_pixmap (gens_window, "kmix.png");
  gtk_widget_set_name (image3316, "image3316");
  gtk_widget_show (image3316);
  gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (item8), image3316);

  item8_menu = gtk_menu_new ();
  gtk_widget_set_name (item8_menu, "item8_menu");
  gtk_menu_item_set_submenu (GTK_MENU_ITEM (item8), item8_menu);

  enable_sound = gtk_check_menu_item_new_with_mnemonic ("Enable");
  gtk_widget_set_name (enable_sound, "enable_sound");
  gtk_widget_show (enable_sound);
  gtk_container_add (GTK_CONTAINER (item8_menu), enable_sound);
  gtk_check_menu_item_set_active (GTK_CHECK_MENU_ITEM (enable_sound), TRUE);

  separator10 = gtk_separator_menu_item_new ();
  gtk_widget_set_name (separator10, "separator10");
  gtk_widget_show (separator10);
  gtk_container_add (GTK_CONTAINER (item8_menu), separator10);
  gtk_widget_set_sensitive (separator10, FALSE);

  rate = gtk_menu_item_new_with_mnemonic ("Rate");
  gtk_widget_set_name (rate, "rate");
  gtk_widget_show (rate);
  gtk_container_add (GTK_CONTAINER (item8_menu), rate);

  rate_menu = gtk_menu_new ();
  gtk_widget_set_name (rate_menu, "rate_menu");
  gtk_menu_item_set_submenu (GTK_MENU_ITEM (rate), rate_menu);

  rate_11025 = gtk_radio_menu_item_new_with_mnemonic (rate_11025_group, "11025");
  rate_11025_group = gtk_radio_menu_item_get_group (GTK_RADIO_MENU_ITEM (rate_11025));
  gtk_widget_set_name (rate_11025, "rate_11025");
  gtk_widget_show (rate_11025);
  gtk_container_add (GTK_CONTAINER (rate_menu), rate_11025);
  gtk_check_menu_item_set_active (GTK_CHECK_MENU_ITEM (rate_11025), TRUE);

  rate_16000 = gtk_radio_menu_item_new_with_mnemonic (rate_11025_group, "16000");
  rate_11025_group = gtk_radio_menu_item_get_group (GTK_RADIO_MENU_ITEM (rate_16000));
  gtk_widget_set_name (rate_16000, "rate_16000");
  gtk_widget_show (rate_16000);
  gtk_container_add (GTK_CONTAINER (rate_menu), rate_16000);
  gtk_check_menu_item_set_active (GTK_CHECK_MENU_ITEM (rate_16000), TRUE);

  rate_22050 = gtk_radio_menu_item_new_with_mnemonic (rate_11025_group, "22050");
  rate_11025_group = gtk_radio_menu_item_get_group (GTK_RADIO_MENU_ITEM (rate_22050));
  gtk_widget_set_name (rate_22050, "rate_22050");
  gtk_widget_show (rate_22050);
  gtk_container_add (GTK_CONTAINER (rate_menu), rate_22050);
  gtk_check_menu_item_set_active (GTK_CHECK_MENU_ITEM (rate_22050), TRUE);

  rate_32000 = gtk_radio_menu_item_new_with_mnemonic (rate_11025_group, "32000");
  rate_11025_group = gtk_radio_menu_item_get_group (GTK_RADIO_MENU_ITEM (rate_32000));
  gtk_widget_set_name (rate_32000, "rate_32000");
  gtk_widget_show (rate_32000);
  gtk_container_add (GTK_CONTAINER (rate_menu), rate_32000);
  gtk_check_menu_item_set_active (GTK_CHECK_MENU_ITEM (rate_32000), TRUE);

  rate_44100 = gtk_radio_menu_item_new_with_mnemonic (rate_11025_group, "44100");
  rate_11025_group = gtk_radio_menu_item_get_group (GTK_RADIO_MENU_ITEM (rate_44100));
  gtk_widget_set_name (rate_44100, "rate_44100");
  gtk_widget_show (rate_44100);
  gtk_container_add (GTK_CONTAINER (rate_menu), rate_44100);
  gtk_check_menu_item_set_active (GTK_CHECK_MENU_ITEM (rate_44100), TRUE);

  rate_48000 = gtk_radio_menu_item_new_with_mnemonic (rate_11025_group, "48000");
  rate_11025_group = gtk_radio_menu_item_get_group (GTK_RADIO_MENU_ITEM (rate_48000));
  gtk_widget_set_name (rate_48000, "rate_48000");
  gtk_widget_show (rate_48000);
  gtk_container_add (GTK_CONTAINER (rate_menu), rate_48000);
  gtk_check_menu_item_set_active (GTK_CHECK_MENU_ITEM (rate_48000), TRUE);

  stereo = gtk_check_menu_item_new_with_mnemonic ("Stereo");
  gtk_widget_set_name (stereo, "stereo");
  gtk_widget_show (stereo);
  gtk_container_add (GTK_CONTAINER (item8_menu), stereo);
  gtk_check_menu_item_set_active (GTK_CHECK_MENU_ITEM (stereo), TRUE);

  separator11 = gtk_separator_menu_item_new ();
  gtk_widget_set_name (separator11, "separator11");
  gtk_widget_show (separator11);
  gtk_container_add (GTK_CONTAINER (item8_menu), separator11);
  gtk_widget_set_sensitive (separator11, FALSE);

  z80 = gtk_check_menu_item_new_with_mnemonic ("Z80");
  gtk_widget_set_name (z80, "z80");
  gtk_widget_show (z80);
  gtk_container_add (GTK_CONTAINER (item8_menu), z80);
  gtk_check_menu_item_set_active (GTK_CHECK_MENU_ITEM (z80), TRUE);

  separator19 = gtk_separator_menu_item_new ();
  gtk_widget_set_name (separator19, "separator19");
  gtk_widget_show (separator19);
  gtk_container_add (GTK_CONTAINER (item8_menu), separator19);
  gtk_widget_set_sensitive (separator19, FALSE);

  ym2612 = gtk_check_menu_item_new_with_mnemonic ("YM2612");
  gtk_widget_set_name (ym2612, "ym2612");
  gtk_widget_show (ym2612);
  gtk_container_add (GTK_CONTAINER (item8_menu), ym2612);
  gtk_check_menu_item_set_active (GTK_CHECK_MENU_ITEM (ym2612), TRUE);

  ym2612_improved = gtk_check_menu_item_new_with_mnemonic ("YM2612 Improved");
  gtk_widget_set_name (ym2612_improved, "ym2612_improved");
  gtk_widget_show (ym2612_improved);
  gtk_container_add (GTK_CONTAINER (item8_menu), ym2612_improved);

  separator20 = gtk_separator_menu_item_new ();
  gtk_widget_set_name (separator20, "separator20");
  gtk_widget_show (separator20);
  gtk_container_add (GTK_CONTAINER (item8_menu), separator20);
  gtk_widget_set_sensitive (separator20, FALSE);

  dac = gtk_check_menu_item_new_with_mnemonic ("DAC");
  gtk_widget_set_name (dac, "dac");
  gtk_widget_show (dac);
  gtk_container_add (GTK_CONTAINER (item8_menu), dac);
  gtk_check_menu_item_set_active (GTK_CHECK_MENU_ITEM (dac), TRUE);

  dac_improved = gtk_check_menu_item_new_with_mnemonic ("DAC Improved");
  gtk_widget_set_name (dac_improved, "dac_improved");
  gtk_widget_show (dac_improved);
  gtk_container_add (GTK_CONTAINER (item8_menu), dac_improved);

  separator21 = gtk_separator_menu_item_new ();
  gtk_widget_set_name (separator21, "separator21");
  gtk_widget_show (separator21);
  gtk_container_add (GTK_CONTAINER (item8_menu), separator21);
  gtk_widget_set_sensitive (separator21, FALSE);

  psg = gtk_check_menu_item_new_with_mnemonic ("PSG");
  gtk_widget_set_name (psg, "psg");
  gtk_widget_show (psg);
  gtk_container_add (GTK_CONTAINER (item8_menu), psg);
  gtk_check_menu_item_set_active (GTK_CHECK_MENU_ITEM (psg), TRUE);

  psg_improved = gtk_check_menu_item_new_with_mnemonic ("PSG Improved");
  gtk_widget_set_name (psg_improved, "psg_improved");
  gtk_widget_show (psg_improved);
  gtk_container_add (GTK_CONTAINER (item8_menu), psg_improved);

  separator22 = gtk_separator_menu_item_new ();
  gtk_widget_set_name (separator22, "separator22");
  gtk_widget_show (separator22);
  gtk_container_add (GTK_CONTAINER (item8_menu), separator22);
  gtk_widget_set_sensitive (separator22, FALSE);

  pcm = gtk_check_menu_item_new_with_mnemonic ("PCM");
  gtk_widget_set_name (pcm, "pcm");
  gtk_widget_show (pcm);
  gtk_container_add (GTK_CONTAINER (item8_menu), pcm);
  gtk_check_menu_item_set_active (GTK_CHECK_MENU_ITEM (pcm), TRUE);

  pwm = gtk_check_menu_item_new_with_mnemonic ("PWM");
  gtk_widget_set_name (pwm, "pwm");
  gtk_widget_show (pwm);
  gtk_container_add (GTK_CONTAINER (item8_menu), pwm);
  gtk_check_menu_item_set_active (GTK_CHECK_MENU_ITEM (pwm), TRUE);

  separator23 = gtk_separator_menu_item_new ();
  gtk_widget_set_name (separator23, "separator23");
  gtk_widget_show (separator23);
  gtk_container_add (GTK_CONTAINER (item8_menu), separator23);
  gtk_widget_set_sensitive (separator23, FALSE);

  cdda = gtk_check_menu_item_new_with_mnemonic ("CDDA");
  gtk_widget_set_name (cdda, "cdda");
  gtk_widget_show (cdda);
  gtk_container_add (GTK_CONTAINER (item8_menu), cdda);
  gtk_check_menu_item_set_active (GTK_CHECK_MENU_ITEM (cdda), TRUE);

  separator12 = gtk_separator_menu_item_new ();
  gtk_widget_set_name (separator12, "separator12");
  gtk_widget_show (separator12);
  gtk_container_add (GTK_CONTAINER (item8_menu), separator12);
  gtk_widget_set_sensitive (separator12, FALSE);

  start_wav_dump = gtk_menu_item_new_with_mnemonic ("Start WAV Dump");
  gtk_widget_set_name (start_wav_dump, "start_wav_dump");
  gtk_widget_show (start_wav_dump);
  gtk_container_add (GTK_CONTAINER (item8_menu), start_wav_dump);
  gtk_widget_set_sensitive (start_wav_dump, FALSE);

  start_gym_dump = gtk_menu_item_new_with_mnemonic ("Start GYM Dump");
  gtk_widget_set_name (start_gym_dump, "start_gym_dump");
  gtk_widget_show (start_gym_dump);
  gtk_container_add (GTK_CONTAINER (item8_menu), start_gym_dump);

  item1 = gtk_image_menu_item_new_with_mnemonic ("Option");
  gtk_widget_set_name (item1, "item1");
  gtk_widget_show (item1);
  gtk_container_add (GTK_CONTAINER (menubar1), item1);

  image3317 = create_pixmap (gens_window, "package_settings.png");
  gtk_widget_set_name (image3317, "image3317");
  gtk_widget_show (image3317);
  gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (item1), image3317);

  item1_menu = gtk_menu_new ();
  gtk_widget_set_name (item1_menu, "item1_menu");
  gtk_menu_item_set_submenu (GTK_MENU_ITEM (item1), item1_menu);

  misc = gtk_image_menu_item_new_with_mnemonic ("General Options");
  gtk_widget_set_name (misc, "misc");
  gtk_widget_show (misc);
  gtk_container_add (GTK_CONTAINER (item1_menu), misc);

  image3318 = create_pixmap (gens_window, "ksysguard.png");
  gtk_widget_set_name (image3318, "image3318");
  gtk_widget_show (image3318);
  gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (misc), image3318);

  joypads = gtk_image_menu_item_new_with_mnemonic ("Joypads...");
  gtk_widget_set_name (joypads, "joypads");
  gtk_widget_show (joypads);
  gtk_container_add (GTK_CONTAINER (item1_menu), joypads);

  image3319 = create_pixmap (gens_window, "package_games.png");
  gtk_widget_set_name (image3319, "image3319");
  gtk_widget_show (image3319);
  gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (joypads), image3319);

  directories = gtk_image_menu_item_new_with_mnemonic ("Directories...");
  gtk_widget_set_name (directories, "directories");
  gtk_widget_show (directories);
  gtk_container_add (GTK_CONTAINER (item1_menu), directories);

  image3320 = create_pixmap (gens_window, "folder_slin_open.png");
  gtk_widget_set_name (image3320, "image3320");
  gtk_widget_show (image3320);
  gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (directories), image3320);

  bios_misc_files = gtk_image_menu_item_new_with_mnemonic ("Bios/Misc Files...");
  gtk_widget_set_name (bios_misc_files, "bios_misc_files");
  gtk_widget_show (bios_misc_files);
  gtk_container_add (GTK_CONTAINER (item1_menu), bios_misc_files);

  image3321 = create_pixmap (gens_window, "binary.png");
  gtk_widget_set_name (image3321, "image3321");
  gtk_widget_show (image3321);
  gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (bios_misc_files), image3321);

  separator13 = gtk_separator_menu_item_new ();
  gtk_widget_set_name (separator13, "separator13");
  gtk_widget_show (separator13);
  gtk_container_add (GTK_CONTAINER (item1_menu), separator13);
  gtk_widget_set_sensitive (separator13, FALSE);

  menu_sdl_test = gtk_image_menu_item_new_with_mnemonic ("SDL Sound Test");
  gtk_widget_set_name (menu_sdl_test, "menu_sdl_test");
  gtk_widget_show (menu_sdl_test);
  gtk_container_add (GTK_CONTAINER (item1_menu), menu_sdl_test);
  gtk_tooltips_set_tip (tooltips, menu_sdl_test, "Test to see if your sound is set up right!", NULL);

  image3322 = create_pixmap (gens_window, "package_settings.png");
  gtk_widget_set_name (image3322, "image3322");
  gtk_widget_show (image3322);
  gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (menu_sdl_test), image3322);

  separator26 = gtk_separator_menu_item_new ();
  gtk_widget_set_name (separator26, "separator26");
  gtk_widget_show (separator26);
  gtk_container_add (GTK_CONTAINER (item1_menu), separator26);
  gtk_widget_set_sensitive (separator26, FALSE);

  item10 = gtk_image_menu_item_new_with_mnemonic ("Current CD Drive");
  gtk_widget_set_name (item10, "item10");
  gtk_widget_show (item10);
  gtk_container_add (GTK_CONTAINER (item1_menu), item10);
  //gtk_widget_set_sensitive (item10, FALSE);

  image3323 = create_pixmap (gens_window, "cdrom2_unmount.png");
  gtk_widget_set_name (image3323, "image3323");
  gtk_widget_show (image3323);
  gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (item10), image3323);

  item9 = gtk_menu_item_new_with_mnemonic ("Sega CD SRAM Size");
  gtk_widget_set_name (item9, "item9");
  gtk_widget_show (item9);
  gtk_container_add (GTK_CONTAINER (item1_menu), item9);

  item9_menu = gtk_menu_new ();
  gtk_widget_set_name (item9_menu, "item9_menu");
  gtk_menu_item_set_submenu (GTK_MENU_ITEM (item9), item9_menu);

  none = gtk_radio_menu_item_new_with_mnemonic (none_group, "None");
  none_group = gtk_radio_menu_item_get_group (GTK_RADIO_MENU_ITEM (none));
  gtk_widget_set_name (none, "none");
  gtk_widget_show (none);
  gtk_container_add (GTK_CONTAINER (item9_menu), none);
  gtk_check_menu_item_set_active (GTK_CHECK_MENU_ITEM (none), TRUE);

  _8_kb = gtk_radio_menu_item_new_with_mnemonic (none_group, "8 Kb");
  none_group = gtk_radio_menu_item_get_group (GTK_RADIO_MENU_ITEM (_8_kb));
  gtk_widget_set_name (_8_kb, "_8_kb");
  gtk_widget_show (_8_kb);
  gtk_container_add (GTK_CONTAINER (item9_menu), _8_kb);
  gtk_check_menu_item_set_active (GTK_CHECK_MENU_ITEM (_8_kb), TRUE);

  _16_kb = gtk_radio_menu_item_new_with_mnemonic (none_group, "16 Kb");
  none_group = gtk_radio_menu_item_get_group (GTK_RADIO_MENU_ITEM (_16_kb));
  gtk_widget_set_name (_16_kb, "_16_kb");
  gtk_widget_show (_16_kb);
  gtk_container_add (GTK_CONTAINER (item9_menu), _16_kb);
  gtk_check_menu_item_set_active (GTK_CHECK_MENU_ITEM (_16_kb), TRUE);

  _32_kb = gtk_radio_menu_item_new_with_mnemonic (none_group, "32 Kb");
  none_group = gtk_radio_menu_item_get_group (GTK_RADIO_MENU_ITEM (_32_kb));
  gtk_widget_set_name (_32_kb, "_32_kb");
  gtk_widget_show (_32_kb);
  gtk_container_add (GTK_CONTAINER (item9_menu), _32_kb);
  gtk_check_menu_item_set_active (GTK_CHECK_MENU_ITEM (_32_kb), TRUE);

  _64_kb = gtk_radio_menu_item_new_with_mnemonic (none_group, "64 Kb");
  none_group = gtk_radio_menu_item_get_group (GTK_RADIO_MENU_ITEM (_64_kb));
  gtk_widget_set_name (_64_kb, "_64_kb");
  gtk_widget_show (_64_kb);
  gtk_container_add (GTK_CONTAINER (item9_menu), _64_kb);
  gtk_check_menu_item_set_active (GTK_CHECK_MENU_ITEM (_64_kb), TRUE);

  separator14 = gtk_separator_menu_item_new ();
  gtk_widget_set_name (separator14, "separator14");
  gtk_widget_show (separator14);
  gtk_container_add (GTK_CONTAINER (item1_menu), separator14);
  gtk_widget_set_sensitive (separator14, FALSE);

  load_config = gtk_image_menu_item_new_with_mnemonic ("Load config");
  gtk_widget_set_name (load_config, "load_config");
  gtk_widget_show (load_config);
  gtk_container_add (GTK_CONTAINER (item1_menu), load_config);

  image3324 = create_pixmap (gens_window, "folder_slin_open.png");
  gtk_widget_set_name (image3324, "image3324");
  gtk_widget_show (image3324);
  gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (load_config), image3324);

  save_config_as = gtk_image_menu_item_new_with_mnemonic ("Save config as");
  gtk_widget_set_name (save_config_as, "save_config_as");
  gtk_widget_show (save_config_as);
  gtk_container_add (GTK_CONTAINER (item1_menu), save_config_as);

  image3325 = gtk_image_new_from_stock ("gtk-save-as", GTK_ICON_SIZE_MENU);
  gtk_widget_set_name (image3325, "image3325");
  gtk_widget_show (image3325);
  gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (save_config_as), image3325);

  menuitem6 = gtk_image_menu_item_new_with_mnemonic ("_Help");
  gtk_widget_set_name (menuitem6, "menuitem6");
  gtk_widget_show (menuitem6);
  gtk_container_add (GTK_CONTAINER (menubar1), menuitem6);

  image3326 = gtk_image_new_from_stock ("gtk-help", GTK_ICON_SIZE_MENU);
  gtk_widget_set_name (image3326, "image3326");
  gtk_widget_show (image3326);
  gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (menuitem6), image3326);

  menuitem6_menu = gtk_menu_new ();
  gtk_widget_set_name (menuitem6_menu, "menuitem6_menu");
  gtk_menu_item_set_submenu (GTK_MENU_ITEM (menuitem6), menuitem6_menu);

  about = gtk_image_menu_item_new_with_mnemonic ("About");
  gtk_widget_set_name (about, "about");
  gtk_widget_show (about);
  gtk_container_add (GTK_CONTAINER (menuitem6_menu), about);

  image3327 = gtk_image_new_from_stock ("gtk-help", GTK_ICON_SIZE_MENU);
  gtk_widget_set_name (image3327, "image3327");
  gtk_widget_show (image3327);
  gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (about), image3327);

  g_signal_connect ((gpointer) gens_window, "delete_event",
                    G_CALLBACK (on_gens_window_delete_event),
                    NULL);
  g_signal_connect ((gpointer) gens_window, "destroy_event",
                    G_CALLBACK (on_gens_window_destroy_event),
                    NULL);
  g_signal_connect ((gpointer) open_rom, "activate",
                    G_CALLBACK (on_open_rom_activate),
                    NULL);
  g_signal_connect ((gpointer) boot_cd, "activate",
                    G_CALLBACK (on_boot_cd_activate),
                    NULL);
  g_signal_connect ((gpointer) netplay, "activate",
                    G_CALLBACK (on_netplay_activate),
                    NULL);
  g_signal_connect ((gpointer) close_rom, "activate",
                    G_CALLBACK (on_close_rom_activate),
                    NULL);
  g_signal_connect ((gpointer) game_genie, "activate",
                    G_CALLBACK (on_game_genie_activate),
                    NULL);
  g_signal_connect ((gpointer) load_state, "activate",
                    G_CALLBACK (on_load_state_activate),
                    NULL);
  g_signal_connect ((gpointer) save_state_as, "activate",
                    G_CALLBACK (on_save_state_as_activate),
                    NULL);
  g_signal_connect ((gpointer) quick_load, "activate",
                    G_CALLBACK (on_quick_load_activate),
                    NULL);
  g_signal_connect ((gpointer) quick_save, "activate",
                    G_CALLBACK (on_quick_save_activate),
                    NULL);
  g_signal_connect ((gpointer) change_state_slot0, "activate",
                    G_CALLBACK (on_change_state_slot0_activate),
                    NULL);
  g_signal_connect ((gpointer) change_state_slot1, "activate",
                    G_CALLBACK (on_change_state_slot1_activate),
                    NULL);
  g_signal_connect ((gpointer) change_state_slot2, "activate",
                    G_CALLBACK (on_change_state_slot2_activate),
                    NULL);
  g_signal_connect ((gpointer) change_state_slot3, "activate",
                    G_CALLBACK (on_change_state_slot3_activate),
                    NULL);
  g_signal_connect ((gpointer) change_state_slot4, "activate",
                    G_CALLBACK (on_change_state_slot4_activate),
                    NULL);
  g_signal_connect ((gpointer) change_state_slot5, "activate",
                    G_CALLBACK (on_change_state_slot5_activate),
                    NULL);
  g_signal_connect ((gpointer) change_state_slot6, "activate",
                    G_CALLBACK (on_change_state_slot6_activate),
                    NULL);
  g_signal_connect ((gpointer) change_state_slot7, "activate",
                    G_CALLBACK (on_change_state_slot7_activate),
                    NULL);
  g_signal_connect ((gpointer) change_state_slot8, "activate",
                    G_CALLBACK (on_change_state_slot8_activate),
                    NULL);
  g_signal_connect ((gpointer) change_state_slot9, "activate",
                    G_CALLBACK (on_change_state_slot9_activate),
                    NULL);
  g_signal_connect ((gpointer) quit, "activate",
                    G_CALLBACK (on_quit_activate),
                    NULL);
  g_signal_connect ((gpointer) full_screen, "activate",
                    G_CALLBACK (on_full_screen_activate),
                    NULL);
  g_signal_connect ((gpointer) vsync, "activate",
                    G_CALLBACK (on_vsync_activate),
                    NULL);
  g_signal_connect ((gpointer) stretch, "activate",
                    G_CALLBACK (on_stretch_activate),
                    NULL);
  g_signal_connect ((gpointer) opengl, "activate",
                    G_CALLBACK (on_opengl_activate),
                    NULL);
  g_signal_connect ((gpointer) _320x240, "activate",
                    G_CALLBACK (on_320x240_activate),
                    NULL);
  g_signal_connect ((gpointer) _640x480, "activate",
                    G_CALLBACK (on_640x480_activate),
                    NULL);
  g_signal_connect ((gpointer) _800x600, "activate",
                    G_CALLBACK (on_800x600_activate),
                    NULL);
  g_signal_connect ((gpointer) _1024x768, "activate",
                    G_CALLBACK (on_1024x768_activate),
                    NULL);
  g_signal_connect ((gpointer) custom, "activate",
                    G_CALLBACK (on_custom_activate),
                    NULL);
  g_signal_connect ((gpointer) bpp16, "activate",
                    G_CALLBACK (on_bpp16_activate),
                    NULL);
  g_signal_connect ((gpointer) bpp24, "activate",
                    G_CALLBACK (on_bpp24_activate),
                    NULL);
  g_signal_connect ((gpointer) bpp32, "activate",
                    G_CALLBACK (on_bpp32_activate),
                    NULL);
  g_signal_connect ((gpointer) color_adjust, "activate",
                    G_CALLBACK (on_color_adjust_activate),
                    NULL);
  g_signal_connect ((gpointer) normal, "activate",
                    G_CALLBACK (on_normal_activate),
                    NULL);
  g_signal_connect ((gpointer) _double, "activate",
                    G_CALLBACK (on_double_activate),
                    NULL);
  g_signal_connect ((gpointer) interpolated, "activate",
                    G_CALLBACK (on_interpolated_activate),
                    NULL);
  g_signal_connect ((gpointer) scanline, "activate",
                    G_CALLBACK (on_scanline_activate),
                    NULL);
  g_signal_connect ((gpointer) _50_scanline, "activate",
                    G_CALLBACK (on_50_scanline_activate),
                    NULL);
  g_signal_connect ((gpointer) _25_scanline, "activate",
                    G_CALLBACK (on_25_scanline_activate),
                    NULL);
  g_signal_connect ((gpointer) interpolated_scanline, "activate",
                    G_CALLBACK (on_interpolated_scanline_activate),
                    NULL);
  g_signal_connect ((gpointer) interpolated_50_scanline, "activate",
                    G_CALLBACK (on_interpolated_50_scanline_activate),
                    NULL);
  g_signal_connect ((gpointer) interpolated_25_scanline, "activate",
                    G_CALLBACK (on_interpolated_25_scanline_activate),
                    NULL);
  g_signal_connect ((gpointer) _2xsai_kreed, "activate",
                    G_CALLBACK (on_2xsai_kreed_activate),
                    NULL);
  g_signal_connect ((gpointer) _scale2x, "activate",
                    G_CALLBACK (on_scale2x_activate),
                    NULL);
  g_signal_connect ((gpointer) hq2x, "activate",
                    G_CALLBACK (on_hq2x_activate),
                    NULL);
  g_signal_connect ((gpointer) sprite_limit, "activate",
                    G_CALLBACK (on_sprite_limit_activate),
                    NULL);
  g_signal_connect ((gpointer) frame_auto_skip, "activate",
                    G_CALLBACK (on_frame_auto_skip_activate),
                    NULL);
  g_signal_connect ((gpointer) frame_0_skip, "activate",
                    G_CALLBACK (on_frame_0_skip_activate),
                    NULL);
  g_signal_connect ((gpointer) frame_1_skip, "activate",
                    G_CALLBACK (on_frame_1_skip_activate),
                    NULL);
  g_signal_connect ((gpointer) frame_2_skip, "activate",
                    G_CALLBACK (on_frame_2_skip_activate),
                    NULL);
  g_signal_connect ((gpointer) frame_3_skip, "activate",
                    G_CALLBACK (on_frame_3_skip_activate),
                    NULL);
  g_signal_connect ((gpointer) frame_4_skip, "activate",
                    G_CALLBACK (on_frame_4_skip_activate),
                    NULL);
  g_signal_connect ((gpointer) frame_5_skip, "activate",
                    G_CALLBACK (on_frame_5_skip_activate),
                    NULL);
  g_signal_connect ((gpointer) frame_6_skip, "activate",
                    G_CALLBACK (on_frame_6_skip_activate),
                    NULL);
  g_signal_connect ((gpointer) frame_7_skip, "activate",
                    G_CALLBACK (on_frame_7_skip_activate),
                    NULL);
  g_signal_connect ((gpointer) frame_8_skip, "activate",
                    G_CALLBACK (on_frame_8_skip_activate),
                    NULL);
  g_signal_connect ((gpointer) screen_shot, "activate",
                    G_CALLBACK (on_screen_shot_activate),
                    NULL);
  g_signal_connect ((gpointer) genesis_68000, "activate",
                    G_CALLBACK (on_genesis_68000_activate),
                    NULL);
  g_signal_connect ((gpointer) genesis_z80, "activate",
                    G_CALLBACK (on_genesis_z80_activate),
                    NULL);
  g_signal_connect ((gpointer) genesis_vdp, "activate",
                    G_CALLBACK (on_genesis_vdp_activate),
                    NULL);
  g_signal_connect ((gpointer) segacd_68000, "activate",
                    G_CALLBACK (on_segacd_68000_activate),
                    NULL);
  g_signal_connect ((gpointer) segacd_cdc, "activate",
                    G_CALLBACK (on_segacd_cdc_activate),
                    NULL);
  g_signal_connect ((gpointer) segacd_gfx, "activate",
                    G_CALLBACK (on_segacd_gfx_activate),
                    NULL);
  g_signal_connect ((gpointer) _32x_main_sh2, "activate",
                    G_CALLBACK (on_32x_main_sh2_activate),
                    NULL);
  g_signal_connect ((gpointer) _32x_sub_sh2, "activate",
                    G_CALLBACK (on_32x_sub_sh2_activate),
                    NULL);
  g_signal_connect ((gpointer) _32x_vdp, "activate",
                    G_CALLBACK (on_32x_vdp_activate),
                    NULL);
  g_signal_connect ((gpointer) auto_detect, "activate",
                    G_CALLBACK (on_auto_detect_activate),
                    NULL);
  g_signal_connect ((gpointer) japan_ntsc, "activate",
                    G_CALLBACK (on_japan_ntsc_activate),
                    NULL);
  g_signal_connect ((gpointer) usa_ntsc, "activate",
                    G_CALLBACK (on_usa_ntsc_activate),
                    NULL);
  g_signal_connect ((gpointer) europe_pal, "activate",
                    G_CALLBACK (on_europe_pal_activate),
                    NULL);
  g_signal_connect ((gpointer) japan_pal, "activate",
                    G_CALLBACK (on_japan_pal_activate),
                    NULL);
  g_signal_connect ((gpointer) detection_order_usa, "activate",
                    G_CALLBACK (on_detection_order_usa_activate),
                    NULL);
  g_signal_connect ((gpointer) detection_order_japan, "activate",
                    G_CALLBACK (on_detection_order_japan_activate),
                    NULL);
  g_signal_connect ((gpointer) detection_order_europe, "activate",
                    G_CALLBACK (on_detection_order_europe_activate),
                    NULL);
  g_signal_connect ((gpointer) hard_reset, "activate",
                    G_CALLBACK (on_hard_reset_activate),
                    NULL);
  g_signal_connect ((gpointer) reset_main_68000, "activate",
                    G_CALLBACK (on_reset_main_68000_activate),
                    NULL);
  g_signal_connect ((gpointer) reset_sub_68000, "activate",
                    G_CALLBACK (on_reset_sub_68000_activate),
                    NULL);
  g_signal_connect ((gpointer) reset_68000, "activate",
                    G_CALLBACK (on_reset_68000_activate),
                    NULL);
  g_signal_connect ((gpointer) reset_main_sh2, "activate",
                    G_CALLBACK (on_reset_main_sh2_activate),
                    NULL);
  g_signal_connect ((gpointer) reset_sub_sh2, "activate",
                    G_CALLBACK (on_reset_sub_sh2_activate),
                    NULL);
  g_signal_connect ((gpointer) reset_z80, "activate",
                    G_CALLBACK (on_reset_z80_activate),
                    NULL);
  g_signal_connect ((gpointer) perfect_synchro, "activate",
                    G_CALLBACK (on_perfect_synchro_activate),
                    NULL);
  g_signal_connect ((gpointer) enable_sound, "activate",
                    G_CALLBACK (on_enable_sound_activate),
                    NULL);
  g_signal_connect ((gpointer) rate_11025, "activate",
                    G_CALLBACK (on_rate_11025_activate),
                    NULL);
  g_signal_connect ((gpointer) rate_16000, "activate",
                    G_CALLBACK (on_rate_16000_activate),
                    NULL);
  g_signal_connect ((gpointer) rate_22050, "activate",
                    G_CALLBACK (on_rate_22050_activate),
                    NULL);
  g_signal_connect ((gpointer) rate_32000, "activate",
                    G_CALLBACK (on_rate_32000_activate),
                    NULL);
  g_signal_connect ((gpointer) rate_44100, "activate",
                    G_CALLBACK (on_rate_44100_activate),
                    NULL);
  g_signal_connect ((gpointer) rate_48000, "activate",
                    G_CALLBACK (on_rate_48000_activate),
                    NULL);
  g_signal_connect ((gpointer) stereo, "activate",
                    G_CALLBACK (on_stereo_activate),
                    NULL);
  g_signal_connect ((gpointer) z80, "activate",
                    G_CALLBACK (on_z80_activate),
                    NULL);
  g_signal_connect ((gpointer) ym2612, "activate",
                    G_CALLBACK (on_ym2612_activate),
                    NULL);
  g_signal_connect ((gpointer) ym2612_improved, "activate",
                    G_CALLBACK (on_ym2612_improved_activate),
                    NULL);
  g_signal_connect ((gpointer) dac, "activate",
                    G_CALLBACK (on_dac_activate),
                    NULL);
  g_signal_connect ((gpointer) dac_improved, "activate",
                    G_CALLBACK (on_dac_improved_activate),
                    NULL);
  g_signal_connect ((gpointer) psg, "activate",
                    G_CALLBACK (on_psg_activate),
                    NULL);
  g_signal_connect ((gpointer) psg_improved, "activate",
                    G_CALLBACK (on_psg_improved_activate),
                    NULL);
  g_signal_connect ((gpointer) pcm, "activate",
                    G_CALLBACK (on_pcm_activate),
                    NULL);
  g_signal_connect ((gpointer) pwm, "activate",
                    G_CALLBACK (on_pwm_activate),
                    NULL);
  g_signal_connect ((gpointer) cdda, "activate",
                    G_CALLBACK (on_cdda_activate),
                    NULL);
  g_signal_connect ((gpointer) start_wav_dump, "activate",
                    G_CALLBACK (on_start_wav_dump_activate),
                    NULL);
  g_signal_connect ((gpointer) start_gym_dump, "activate",
                    G_CALLBACK (on_start_gym_dump_activate),
                    NULL);
  g_signal_connect ((gpointer) misc, "activate",
                    G_CALLBACK (on_misc_activate),
                    NULL);
  g_signal_connect ((gpointer) joypads, "activate",
                    G_CALLBACK (on_joypads_activate),
                    NULL);
  g_signal_connect ((gpointer) directories, "activate",
                    G_CALLBACK (on_directories_activate),
                    NULL);
  g_signal_connect ((gpointer) bios_misc_files, "activate",
                    G_CALLBACK (on_bios_misc_files_activate),
                    NULL);
  g_signal_connect ((gpointer) item10, "activate",
                    G_CALLBACK (on_item10_activate),
                    NULL);
  g_signal_connect ((gpointer) menu_sdl_test, "activate",
                    G_CALLBACK (on_sdl_test_activate),
                    NULL);
  g_signal_connect ((gpointer) none, "activate",
                    G_CALLBACK (on_none_activate),
                    NULL);
  g_signal_connect ((gpointer) _8_kb, "activate",
                    G_CALLBACK (on_8_kb_activate),
                    NULL);
  g_signal_connect ((gpointer) _16_kb, "activate",
                    G_CALLBACK (on_16_kb_activate),
                    NULL);
  g_signal_connect ((gpointer) _32_kb, "activate",
                    G_CALLBACK (on_32_kb_activate),
                    NULL);
  g_signal_connect ((gpointer) _64_kb, "activate",
                    G_CALLBACK (on_64_kb_activate),
                    NULL);
  g_signal_connect ((gpointer) load_config, "activate",
                    G_CALLBACK (on_load_config_activate),
                    NULL);
  g_signal_connect ((gpointer) save_config_as, "activate",
                    G_CALLBACK (on_save_config_as_activate),
                    NULL);
  g_signal_connect ((gpointer) about, "activate",
                    G_CALLBACK (on_about_activate),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (gens_window, gens_window, "gens_window");
  GLADE_HOOKUP_OBJECT (gens_window, vbox1, "vbox1");
  GLADE_HOOKUP_OBJECT (gens_window, handlebox1, "handlebox1");
  GLADE_HOOKUP_OBJECT (gens_window, menubar1, "menubar1");
  GLADE_HOOKUP_OBJECT (gens_window, item15, "item15");
  GLADE_HOOKUP_OBJECT (gens_window, image3295, "image3295");
  GLADE_HOOKUP_OBJECT (gens_window, item15_menu, "item15_menu");
  GLADE_HOOKUP_OBJECT (gens_window, open_rom, "open_rom");
  GLADE_HOOKUP_OBJECT (gens_window, image3296, "image3296");
  GLADE_HOOKUP_OBJECT (gens_window, boot_cd, "boot_cd");
  GLADE_HOOKUP_OBJECT (gens_window, image3297, "image3297");
  GLADE_HOOKUP_OBJECT (gens_window, netplay, "netplay");
  GLADE_HOOKUP_OBJECT (gens_window, image3298, "image3298");
  GLADE_HOOKUP_OBJECT (gens_window, rom_history, "rom_history");
  GLADE_HOOKUP_OBJECT (gens_window, image3299, "image3299");
  GLADE_HOOKUP_OBJECT (gens_window, close_rom, "close_rom");
  GLADE_HOOKUP_OBJECT (gens_window, image3300, "image3300");
  GLADE_HOOKUP_OBJECT (gens_window, separatormenuitem1, "separatormenuitem1");
  GLADE_HOOKUP_OBJECT (gens_window, game_genie, "game_genie");
  GLADE_HOOKUP_OBJECT (gens_window, image3301, "image3301");
  GLADE_HOOKUP_OBJECT (gens_window, separator2, "separator2");
  GLADE_HOOKUP_OBJECT (gens_window, load_state, "load_state");
  GLADE_HOOKUP_OBJECT (gens_window, image3302, "image3302");
  GLADE_HOOKUP_OBJECT (gens_window, save_state_as, "save_state_as");
  GLADE_HOOKUP_OBJECT (gens_window, image3303, "image3303");
  GLADE_HOOKUP_OBJECT (gens_window, quick_load, "quick_load");
  GLADE_HOOKUP_OBJECT (gens_window, image3304, "image3304");
  GLADE_HOOKUP_OBJECT (gens_window, quick_save, "quick_save");
  GLADE_HOOKUP_OBJECT (gens_window, image3305, "image3305");
  GLADE_HOOKUP_OBJECT (gens_window, change_state1, "change_state1");
  GLADE_HOOKUP_OBJECT (gens_window, image3306, "image3306");
  GLADE_HOOKUP_OBJECT (gens_window, change_state1_menu, "change_state1_menu");
  GLADE_HOOKUP_OBJECT (gens_window, change_state_slot0, "change_state_slot0");
  GLADE_HOOKUP_OBJECT (gens_window, change_state_slot1, "change_state_slot1");
  GLADE_HOOKUP_OBJECT (gens_window, change_state_slot2, "change_state_slot2");
  GLADE_HOOKUP_OBJECT (gens_window, change_state_slot3, "change_state_slot3");
  GLADE_HOOKUP_OBJECT (gens_window, change_state_slot4, "change_state_slot4");
  GLADE_HOOKUP_OBJECT (gens_window, change_state_slot5, "change_state_slot5");
  GLADE_HOOKUP_OBJECT (gens_window, change_state_slot6, "change_state_slot6");
  GLADE_HOOKUP_OBJECT (gens_window, change_state_slot7, "change_state_slot7");
  GLADE_HOOKUP_OBJECT (gens_window, change_state_slot8, "change_state_slot8");
  GLADE_HOOKUP_OBJECT (gens_window, change_state_slot9, "change_state_slot9");
  GLADE_HOOKUP_OBJECT (gens_window, separator16, "separator16");
  GLADE_HOOKUP_OBJECT (gens_window, quit, "quit");
  GLADE_HOOKUP_OBJECT (gens_window, image3307, "image3307");
  GLADE_HOOKUP_OBJECT (gens_window, item3, "item3");
  GLADE_HOOKUP_OBJECT (gens_window, image3308, "image3308");
  GLADE_HOOKUP_OBJECT (gens_window, item3_menu, "item3_menu");
  GLADE_HOOKUP_OBJECT (gens_window, full_screen, "full_screen");
  GLADE_HOOKUP_OBJECT (gens_window, image3309, "image3309");
  GLADE_HOOKUP_OBJECT (gens_window, vsync, "vsync");
  GLADE_HOOKUP_OBJECT (gens_window, stretch, "stretch");
  GLADE_HOOKUP_OBJECT (gens_window, separator17, "separator17");
  GLADE_HOOKUP_OBJECT (gens_window, opengl, "opengl");
  GLADE_HOOKUP_OBJECT (gens_window, opengl_resolution, "opengl_resolution");
  GLADE_HOOKUP_OBJECT (gens_window, opengl_resolution_menu, "opengl_resolution_menu");
  GLADE_HOOKUP_OBJECT (gens_window, _320x240, "_320x240");
  GLADE_HOOKUP_OBJECT (gens_window, _640x480, "_640x480");
  GLADE_HOOKUP_OBJECT (gens_window, _800x600, "_800x600");
  GLADE_HOOKUP_OBJECT (gens_window, _1024x768, "_1024x768");
  GLADE_HOOKUP_OBJECT (gens_window, custom, "custom");
  GLADE_HOOKUP_OBJECT (gens_window, bits_per_pixel1, "bits_per_pixel1");
  GLADE_HOOKUP_OBJECT (gens_window, bits_per_pixel1_menu, "bits_per_pixel1_menu");
  GLADE_HOOKUP_OBJECT (gens_window, bpp16, "bpp16");
  GLADE_HOOKUP_OBJECT (gens_window, bpp24, "bpp24");
  GLADE_HOOKUP_OBJECT (gens_window, bpp32, "bpp32");
  GLADE_HOOKUP_OBJECT (gens_window, separator18, "separator18");
  GLADE_HOOKUP_OBJECT (gens_window, color_adjust, "color_adjust");
  GLADE_HOOKUP_OBJECT (gens_window, image3310, "image3310");
  GLADE_HOOKUP_OBJECT (gens_window, item4, "item4");
  GLADE_HOOKUP_OBJECT (gens_window, image3311, "image3311");
  GLADE_HOOKUP_OBJECT (gens_window, item4_menu, "item4_menu");
  GLADE_HOOKUP_OBJECT (gens_window, normal, "normal");
  GLADE_HOOKUP_OBJECT (gens_window, _double, "_double");
  GLADE_HOOKUP_OBJECT (gens_window, interpolated, "interpolated");
  GLADE_HOOKUP_OBJECT (gens_window, scanline, "scanline");
  GLADE_HOOKUP_OBJECT (gens_window, _50_scanline, "_50_scanline");
  GLADE_HOOKUP_OBJECT (gens_window, _25_scanline, "_25_scanline");
  GLADE_HOOKUP_OBJECT (gens_window, interpolated_scanline, "interpolated_scanline");
  GLADE_HOOKUP_OBJECT (gens_window, interpolated_50_scanline, "interpolated_50_scanline");
  GLADE_HOOKUP_OBJECT (gens_window, interpolated_25_scanline, "interpolated_25_scanline");
  GLADE_HOOKUP_OBJECT (gens_window, _2xsai_kreed, "_2xsai_kreed");
  GLADE_HOOKUP_OBJECT (gens_window, _scale2x, "_scale2x");
  GLADE_HOOKUP_OBJECT (gens_window, hq2x, "hq2x");
  GLADE_HOOKUP_OBJECT (gens_window, separator4, "separator4");
  GLADE_HOOKUP_OBJECT (gens_window, sprite_limit, "sprite_limit");
  GLADE_HOOKUP_OBJECT (gens_window, separator5, "separator5");
  GLADE_HOOKUP_OBJECT (gens_window, item5, "item5");
  GLADE_HOOKUP_OBJECT (gens_window, image3312, "image3312");
  GLADE_HOOKUP_OBJECT (gens_window, item5_menu, "item5_menu");
  GLADE_HOOKUP_OBJECT (gens_window, frame_auto_skip, "frame_auto_skip");
  GLADE_HOOKUP_OBJECT (gens_window, frame_0_skip, "frame_0_skip");
  GLADE_HOOKUP_OBJECT (gens_window, frame_1_skip, "frame_1_skip");
  GLADE_HOOKUP_OBJECT (gens_window, frame_2_skip, "frame_2_skip");
  GLADE_HOOKUP_OBJECT (gens_window, frame_3_skip, "frame_3_skip");
  GLADE_HOOKUP_OBJECT (gens_window, frame_4_skip, "frame_4_skip");
  GLADE_HOOKUP_OBJECT (gens_window, frame_5_skip, "frame_5_skip");
  GLADE_HOOKUP_OBJECT (gens_window, frame_6_skip, "frame_6_skip");
  GLADE_HOOKUP_OBJECT (gens_window, frame_7_skip, "frame_7_skip");
  GLADE_HOOKUP_OBJECT (gens_window, frame_8_skip, "frame_8_skip");
  GLADE_HOOKUP_OBJECT (gens_window, separator15, "separator15");
  GLADE_HOOKUP_OBJECT (gens_window, screen_shot, "screen_shot");
  GLADE_HOOKUP_OBJECT (gens_window, image3313, "image3313");
  GLADE_HOOKUP_OBJECT (gens_window, menuitem3, "menuitem3");
  GLADE_HOOKUP_OBJECT (gens_window, image3314, "image3314");
  GLADE_HOOKUP_OBJECT (gens_window, menuitem3_menu, "menuitem3_menu");
  GLADE_HOOKUP_OBJECT (gens_window, item6, "item6");
  GLADE_HOOKUP_OBJECT (gens_window, item6_menu, "item6_menu");
  GLADE_HOOKUP_OBJECT (gens_window, genesis_68000, "genesis_68000");
  GLADE_HOOKUP_OBJECT (gens_window, genesis_z80, "genesis_z80");
  GLADE_HOOKUP_OBJECT (gens_window, genesis_vdp, "genesis_vdp");
  GLADE_HOOKUP_OBJECT (gens_window, segacd_68000, "segacd_68000");
  GLADE_HOOKUP_OBJECT (gens_window, segacd_cdc, "segacd_cdc");
  GLADE_HOOKUP_OBJECT (gens_window, segacd_gfx, "segacd_gfx");
  GLADE_HOOKUP_OBJECT (gens_window, _32x_main_sh2, "_32x_main_sh2");
  GLADE_HOOKUP_OBJECT (gens_window, _32x_sub_sh2, "_32x_sub_sh2");
  GLADE_HOOKUP_OBJECT (gens_window, _32x_vdp, "_32x_vdp");
  GLADE_HOOKUP_OBJECT (gens_window, separator6, "separator6");
  GLADE_HOOKUP_OBJECT (gens_window, country, "country");
  GLADE_HOOKUP_OBJECT (gens_window, country_menu, "country_menu");
  GLADE_HOOKUP_OBJECT (gens_window, auto_detect, "auto_detect");
  GLADE_HOOKUP_OBJECT (gens_window, japan_ntsc, "japan_ntsc");
  GLADE_HOOKUP_OBJECT (gens_window, usa_ntsc, "usa_ntsc");
  GLADE_HOOKUP_OBJECT (gens_window, europe_pal, "europe_pal");
  GLADE_HOOKUP_OBJECT (gens_window, japan_pal, "japan_pal");
  GLADE_HOOKUP_OBJECT (gens_window, separator9, "separator9");
  GLADE_HOOKUP_OBJECT (gens_window, item7, "item7");
  GLADE_HOOKUP_OBJECT (gens_window, item7_menu, "item7_menu");
  GLADE_HOOKUP_OBJECT (gens_window, detection_order_usa, "detection_order_usa");
  GLADE_HOOKUP_OBJECT (gens_window, detection_order_japan, "detection_order_japan");
  GLADE_HOOKUP_OBJECT (gens_window, detection_order_europe, "detection_order_europe");
  GLADE_HOOKUP_OBJECT (gens_window, separator7, "separator7");
  GLADE_HOOKUP_OBJECT (gens_window, hard_reset, "hard_reset");
  GLADE_HOOKUP_OBJECT (gens_window, image3315, "image3315");
  GLADE_HOOKUP_OBJECT (gens_window, reset_main_68000, "reset_main_68000");
  GLADE_HOOKUP_OBJECT (gens_window, reset_sub_68000, "reset_sub_68000");
  GLADE_HOOKUP_OBJECT (gens_window, reset_68000, "reset_68000");
  GLADE_HOOKUP_OBJECT (gens_window, reset_main_sh2, "reset_main_sh2");
  GLADE_HOOKUP_OBJECT (gens_window, reset_sub_sh2, "reset_sub_sh2");
  GLADE_HOOKUP_OBJECT (gens_window, reset_z80, "reset_z80");
  GLADE_HOOKUP_OBJECT (gens_window, separator8, "separator8");
  GLADE_HOOKUP_OBJECT (gens_window, perfect_synchro, "perfect_synchro");
  GLADE_HOOKUP_OBJECT (gens_window, item8, "item8");
  GLADE_HOOKUP_OBJECT (gens_window, image3316, "image3316");
  GLADE_HOOKUP_OBJECT (gens_window, item8_menu, "item8_menu");
  GLADE_HOOKUP_OBJECT (gens_window, enable_sound, "enable_sound");
  GLADE_HOOKUP_OBJECT (gens_window, separator10, "separator10");
  GLADE_HOOKUP_OBJECT (gens_window, rate, "rate");
  GLADE_HOOKUP_OBJECT (gens_window, rate_menu, "rate_menu");
  GLADE_HOOKUP_OBJECT (gens_window, rate_11025, "rate_11025");
  GLADE_HOOKUP_OBJECT (gens_window, rate_16000, "rate_16000");
  GLADE_HOOKUP_OBJECT (gens_window, rate_22050, "rate_22050");
  GLADE_HOOKUP_OBJECT (gens_window, rate_32000, "rate_32000");
  GLADE_HOOKUP_OBJECT (gens_window, rate_44100, "rate_44100");
  GLADE_HOOKUP_OBJECT (gens_window, rate_48000, "rate_48000");
  GLADE_HOOKUP_OBJECT (gens_window, stereo, "stereo");
  GLADE_HOOKUP_OBJECT (gens_window, separator11, "separator11");
  GLADE_HOOKUP_OBJECT (gens_window, z80, "z80");
  GLADE_HOOKUP_OBJECT (gens_window, separator19, "separator19");
  GLADE_HOOKUP_OBJECT (gens_window, ym2612, "ym2612");
  GLADE_HOOKUP_OBJECT (gens_window, ym2612_improved, "ym2612_improved");
  GLADE_HOOKUP_OBJECT (gens_window, separator20, "separator20");
  GLADE_HOOKUP_OBJECT (gens_window, dac, "dac");
  GLADE_HOOKUP_OBJECT (gens_window, dac_improved, "dac_improved");
  GLADE_HOOKUP_OBJECT (gens_window, separator21, "separator21");
  GLADE_HOOKUP_OBJECT (gens_window, psg, "psg");
  GLADE_HOOKUP_OBJECT (gens_window, psg_improved, "psg_improved");
  GLADE_HOOKUP_OBJECT (gens_window, separator22, "separator22");
  GLADE_HOOKUP_OBJECT (gens_window, pcm, "pcm");
  GLADE_HOOKUP_OBJECT (gens_window, pwm, "pwm");
  GLADE_HOOKUP_OBJECT (gens_window, separator23, "separator23");
  GLADE_HOOKUP_OBJECT (gens_window, cdda, "cdda");
  GLADE_HOOKUP_OBJECT (gens_window, separator12, "separator12");
  GLADE_HOOKUP_OBJECT (gens_window, start_wav_dump, "start_wav_dump");
  GLADE_HOOKUP_OBJECT (gens_window, start_gym_dump, "start_gym_dump");
  GLADE_HOOKUP_OBJECT (gens_window, item1, "item1");
  GLADE_HOOKUP_OBJECT (gens_window, image3317, "image3317");
  GLADE_HOOKUP_OBJECT (gens_window, item1_menu, "item1_menu");
  GLADE_HOOKUP_OBJECT (gens_window, misc, "misc");
  GLADE_HOOKUP_OBJECT (gens_window, image3318, "image3318");
  GLADE_HOOKUP_OBJECT (gens_window, joypads, "joypads");
  GLADE_HOOKUP_OBJECT (gens_window, image3319, "image3319");
  GLADE_HOOKUP_OBJECT (gens_window, directories, "directories");
  GLADE_HOOKUP_OBJECT (gens_window, image3320, "image3320");
  GLADE_HOOKUP_OBJECT (gens_window, bios_misc_files, "bios_misc_files");
  GLADE_HOOKUP_OBJECT (gens_window, image3321, "image3321");
  GLADE_HOOKUP_OBJECT (gens_window, separator13, "separator13");
  GLADE_HOOKUP_OBJECT (gens_window, menu_sdl_test, "menu_sdl_test");
  GLADE_HOOKUP_OBJECT (gens_window, image3322, "image3322");
  GLADE_HOOKUP_OBJECT (gens_window, separator26, "separator26");
  GLADE_HOOKUP_OBJECT (gens_window, item10, "item10");
  GLADE_HOOKUP_OBJECT (gens_window, image3323, "image3323");
  GLADE_HOOKUP_OBJECT (gens_window, item9, "item9");
  GLADE_HOOKUP_OBJECT (gens_window, item9_menu, "item9_menu");
  GLADE_HOOKUP_OBJECT (gens_window, none, "none");
  GLADE_HOOKUP_OBJECT (gens_window, _8_kb, "_8_kb");
  GLADE_HOOKUP_OBJECT (gens_window, _16_kb, "_16_kb");
  GLADE_HOOKUP_OBJECT (gens_window, _32_kb, "_32_kb");
  GLADE_HOOKUP_OBJECT (gens_window, _64_kb, "_64_kb");
  GLADE_HOOKUP_OBJECT (gens_window, separator14, "separator14");
  GLADE_HOOKUP_OBJECT (gens_window, load_config, "load_config");
  GLADE_HOOKUP_OBJECT (gens_window, image3324, "image3324");
  GLADE_HOOKUP_OBJECT (gens_window, save_config_as, "save_config_as");
  GLADE_HOOKUP_OBJECT (gens_window, image3325, "image3325");
  GLADE_HOOKUP_OBJECT (gens_window, menuitem6, "menuitem6");
  GLADE_HOOKUP_OBJECT (gens_window, image3326, "image3326");
  GLADE_HOOKUP_OBJECT (gens_window, menuitem6_menu, "menuitem6_menu");
  GLADE_HOOKUP_OBJECT (gens_window, about, "about");
  GLADE_HOOKUP_OBJECT (gens_window, image3327, "image3327");
  GLADE_HOOKUP_OBJECT_NO_REF (gens_window, tooltips, "tooltips");
  Network_Create_Window(gens_window);

  gtk_window_add_accel_group (GTK_WINDOW (gens_window), accel_group);

  return gens_window;
}

GtkWidget*
create_about (void)
{
  GtkWidget *about;
  GdkPixbuf *about_icon_pixbuf;
  GtkWidget *dialog_vbox1;
  GtkWidget *vbox2;
  GtkWidget *hbox1;
  GtkWidget *image1;
  GtkWidget *label1;
  GtkWidget *frame1;
  GtkWidget *credit;
  GtkWidget *dialog_action_area1;
  GtkWidget *okbutton1;

  about = gtk_dialog_new ();
  gtk_widget_set_name (about, "about");
  gtk_container_set_border_width (GTK_CONTAINER (about), 5);
  gtk_window_set_title (GTK_WINDOW (about), "About Gens");
  gtk_window_set_position (GTK_WINDOW (about), GTK_WIN_POS_CENTER);
  gtk_window_set_modal (GTK_WINDOW (about), TRUE);
  gtk_window_set_resizable (GTK_WINDOW (about), FALSE);
  about_icon_pixbuf = create_pixbuf ("Gens2.ico");
  if (about_icon_pixbuf)
    {
      gtk_window_set_icon (GTK_WINDOW (about), about_icon_pixbuf);
      g_object_unref (about_icon_pixbuf);
    }
  gtk_window_set_type_hint (GTK_WINDOW (about), GDK_WINDOW_TYPE_HINT_DIALOG);
  gtk_dialog_set_has_separator (GTK_DIALOG (about), FALSE);

  dialog_vbox1 = GTK_DIALOG (about)->vbox;
  gtk_widget_set_name (dialog_vbox1, "dialog_vbox1");
  gtk_widget_show (dialog_vbox1);

  vbox2 = gtk_vbox_new (FALSE, 5);
  gtk_widget_set_name (vbox2, "vbox2");
  gtk_widget_show (vbox2);
  gtk_box_pack_start (GTK_BOX (dialog_vbox1), vbox2, TRUE, TRUE, 0);
  gtk_container_set_border_width (GTK_CONTAINER (vbox2), 5);

  hbox1 = gtk_hbox_new (FALSE, 0);
  gtk_widget_set_name (hbox1, "hbox1");
  gtk_widget_show (hbox1);
  gtk_box_pack_start (GTK_BOX (vbox2), hbox1, TRUE, TRUE, 0);

  image1 = create_pixmap (about, "gens_small.png");
  gtk_widget_set_name (image1, "image1");
  gtk_widget_show (image1);
  gtk_box_pack_start (GTK_BOX (hbox1), image1, TRUE, TRUE, 0);

  label1 = gtk_label_new ("<b><i>Gens for Linux\nversion 2.15.5</i></b>\n\nSega Genesis / Megadrive,\nSega CD / Mega CD,\nSega 32X emulator");
  gtk_widget_set_name (label1, "label1");
  gtk_widget_show (label1);
  gtk_box_pack_start (GTK_BOX (hbox1), label1, FALSE, FALSE, 0);
  gtk_label_set_use_markup (GTK_LABEL (label1), TRUE);
  gtk_label_set_justify (GTK_LABEL (label1), GTK_JUSTIFY_CENTER);

  frame1 = gtk_frame_new (NULL);
  gtk_widget_set_name (frame1, "frame1");
  gtk_widget_show (frame1);
  gtk_box_pack_start (GTK_BOX (vbox2), frame1, FALSE, FALSE, 0);
  gtk_container_set_border_width (GTK_CONTAINER (frame1), 5);
  gtk_frame_set_shadow_type (GTK_FRAME (frame1), GTK_SHADOW_NONE);

  credit = gtk_label_new ("(c) 1999-2002 by St\303\251phane Dallongeville\n(c) 2003-2004 by St\303\251phane Akhoun\n\nUse the Gens forum for support\nHomepage : http://ubuntuforums.org/showthread.php?t=290008");
  gtk_widget_set_name (credit, "credit");
  gtk_widget_show (credit);
  gtk_container_add (GTK_CONTAINER (frame1), credit);

  dialog_action_area1 = GTK_DIALOG (about)->action_area;
  gtk_widget_set_name (dialog_action_area1, "dialog_action_area1");
  gtk_widget_show (dialog_action_area1);

  okbutton1 = gtk_button_new_from_stock ("gtk-ok");
  gtk_widget_set_name (okbutton1, "okbutton1");
  gtk_widget_show (okbutton1);
  gtk_dialog_add_action_widget (GTK_DIALOG (about), okbutton1, GTK_RESPONSE_OK);
  GTK_WIDGET_SET_FLAGS (okbutton1, GTK_CAN_DEFAULT);
  gtk_button_set_relief (GTK_BUTTON (okbutton1), GTK_RELIEF_NONE);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (about, about, "about");
  GLADE_HOOKUP_OBJECT_NO_REF (about, dialog_vbox1, "dialog_vbox1");
  GLADE_HOOKUP_OBJECT (about, vbox2, "vbox2");
  GLADE_HOOKUP_OBJECT (about, hbox1, "hbox1");
  GLADE_HOOKUP_OBJECT (about, image1, "image1");
  GLADE_HOOKUP_OBJECT (about, label1, "label1");
  GLADE_HOOKUP_OBJECT (about, frame1, "frame1");
  GLADE_HOOKUP_OBJECT (about, credit, "credit");
  GLADE_HOOKUP_OBJECT_NO_REF (about, dialog_action_area1, "dialog_action_area1");
  GLADE_HOOKUP_OBJECT (about, okbutton1, "okbutton1");

  return about;
}

GtkWidget*
create_game_genie (void)
{
  GtkWidget *game_genie;
  GdkPixbuf *game_genie_icon_pixbuf;
  GtkWidget *vbox3;
  GtkWidget *frame2;
  GtkWidget *label4;
  GtkWidget *label3;
  GtkWidget *vbox4;
  GtkWidget *table1;
  GtkWidget *label5;
  GtkWidget *label6;
  GtkWidget *code;
  GtkWidget *name;
  GtkWidget *buttonGGAddCode;
  GtkWidget *alignment13;
  GtkWidget *hbox29;
  GtkWidget *image199;
  GtkWidget *label73;
  GtkWidget *hbox2;
  GtkWidget *scrolledwindow1;
  GtkWidget *ggListCode;
  GtkWidget *hbox33;
  GtkWidget *buttonGGDelete;
  GtkWidget *buttonGGDesactivate;
  GtkWidget *alignment12;
  GtkWidget *hbox28;
  GtkWidget *image198;
  GtkWidget *label72;
  GtkWidget *button4;
  GtkWidget *buttonGGCancel;
  GtkWidget *buttonGGOK;

  game_genie = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_widget_set_name (game_genie, "game_genie");
  gtk_container_set_border_width (GTK_CONTAINER (game_genie), 5);
  gtk_window_set_title (GTK_WINDOW (game_genie), "Game genie");
  gtk_window_set_position (GTK_WINDOW (game_genie), GTK_WIN_POS_CENTER);
  gtk_window_set_modal (GTK_WINDOW (game_genie), TRUE);
  game_genie_icon_pixbuf = create_pixbuf ("Gens2.ico");
  if (game_genie_icon_pixbuf)
    {
      gtk_window_set_icon (GTK_WINDOW (game_genie), game_genie_icon_pixbuf);
      g_object_unref (game_genie_icon_pixbuf);
    }
  gtk_window_set_type_hint (GTK_WINDOW (game_genie), GDK_WINDOW_TYPE_HINT_DIALOG);

  vbox3 = gtk_vbox_new (FALSE, 5);
  gtk_widget_set_name (vbox3, "vbox3");
  gtk_widget_show (vbox3);
  gtk_container_add (GTK_CONTAINER (game_genie), vbox3);

  frame2 = gtk_frame_new (NULL);
  gtk_widget_set_name (frame2, "frame2");
  gtk_widget_show (frame2);
  gtk_box_pack_start (GTK_BOX (vbox3), frame2, FALSE, TRUE, 0);
  gtk_frame_set_shadow_type (GTK_FRAME (frame2), GTK_SHADOW_NONE);

  label4 = gtk_label_new ("Both Game Genie code and Patch code are supported.\nHighlight a code to activate it.\nSyntax for Game Genie code : XXXX-XXXX\nSyntax for Patch code : XXXXXX-YYYY (address-data)");
  gtk_widget_set_name (label4, "label4");
  gtk_widget_show (label4);
  gtk_container_add (GTK_CONTAINER (frame2), label4);
  gtk_label_set_use_markup (GTK_LABEL (label4), TRUE);
  gtk_misc_set_alignment (GTK_MISC (label4), 0.02, 0);

  label3 = gtk_label_new ("<i><b>Informations about GG/Patch codes</b></i>");
  gtk_widget_set_name (label3, "label3");
  gtk_widget_show (label3);
  gtk_frame_set_label_widget (GTK_FRAME (frame2), label3);
  gtk_label_set_use_markup (GTK_LABEL (label3), TRUE);

  vbox4 = gtk_vbox_new (FALSE, 0);
  gtk_widget_set_name (vbox4, "vbox4");
  gtk_widget_show (vbox4);
  gtk_box_pack_start (GTK_BOX (vbox3), vbox4, FALSE, TRUE, 0);

  table1 = gtk_table_new (2, 3, FALSE);
  gtk_widget_set_name (table1, "table1");
  gtk_widget_show (table1);
  gtk_box_pack_start (GTK_BOX (vbox4), table1, FALSE, TRUE, 0);
  gtk_table_set_col_spacings (GTK_TABLE (table1), 10);

  label5 = gtk_label_new ("Code");
  gtk_widget_set_name (label5, "label5");
  gtk_widget_show (label5);
  gtk_table_attach (GTK_TABLE (table1), label5, 0, 1, 0, 1,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_misc_set_alignment (GTK_MISC (label5), 0, 0.5);

  label6 = gtk_label_new ("Name");
  gtk_widget_set_name (label6, "label6");
  gtk_widget_show (label6);
  gtk_table_attach (GTK_TABLE (table1), label6, 0, 1, 1, 2,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_misc_set_alignment (GTK_MISC (label6), 0, 0.5);

  code = gtk_entry_new ();
  gtk_widget_set_name (code, "code");
  gtk_widget_show (code);
  gtk_table_attach (GTK_TABLE (table1), code, 1, 2, 0, 1,
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_entry_set_max_length (GTK_ENTRY (code), 11);
  gtk_entry_set_text (GTK_ENTRY (code), "XXXX-XXXX");
  gtk_entry_set_has_frame (GTK_ENTRY (code), FALSE);

  name = gtk_entry_new ();
  gtk_widget_set_name (name, "name");
  gtk_widget_show (name);
  gtk_table_attach (GTK_TABLE (table1), name, 1, 2, 1, 2,
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_entry_set_has_frame (GTK_ENTRY (name), FALSE);

  buttonGGAddCode = gtk_button_new ();
  gtk_widget_set_name (buttonGGAddCode, "buttonGGAddCode");
  gtk_widget_show (buttonGGAddCode);
  gtk_table_attach (GTK_TABLE (table1), buttonGGAddCode, 2, 3, 0, 1,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_button_set_relief (GTK_BUTTON (buttonGGAddCode), GTK_RELIEF_NONE);

  alignment13 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_set_name (alignment13, "alignment13");
  gtk_widget_show (alignment13);
  gtk_container_add (GTK_CONTAINER (buttonGGAddCode), alignment13);

  hbox29 = gtk_hbox_new (FALSE, 2);
  gtk_widget_set_name (hbox29, "hbox29");
  gtk_widget_show (hbox29);
  gtk_container_add (GTK_CONTAINER (alignment13), hbox29);

  image199 = gtk_image_new_from_stock ("gtk-add", GTK_ICON_SIZE_BUTTON);
  gtk_widget_set_name (image199, "image199");
  gtk_widget_show (image199);
  gtk_box_pack_start (GTK_BOX (hbox29), image199, FALSE, FALSE, 0);

  label73 = gtk_label_new_with_mnemonic ("Add code");
  gtk_widget_set_name (label73, "label73");
  gtk_widget_show (label73);
  gtk_box_pack_start (GTK_BOX (hbox29), label73, FALSE, FALSE, 0);

  hbox2 = gtk_hbox_new (FALSE, 0);
  gtk_widget_set_name (hbox2, "hbox2");
  gtk_widget_show (hbox2);
  gtk_box_pack_start (GTK_BOX (vbox3), hbox2, TRUE, TRUE, 0);

  scrolledwindow1 = gtk_scrolled_window_new (NULL, NULL);
  gtk_widget_set_name (scrolledwindow1, "scrolledwindow1");
  gtk_widget_show (scrolledwindow1);
  gtk_box_pack_start (GTK_BOX (hbox2), scrolledwindow1, TRUE, TRUE, 0);
  gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (scrolledwindow1), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);

  ggListCode = gtk_tree_view_new ();
  gtk_widget_set_name (ggListCode, "ggListCode");
  gtk_widget_show (ggListCode);
  gtk_container_add (GTK_CONTAINER (scrolledwindow1), ggListCode);
  gtk_tree_view_set_reorderable (GTK_TREE_VIEW (ggListCode), TRUE);

  hbox33 = gtk_hbox_new (FALSE, 0);
  gtk_widget_set_name (hbox33, "hbox33");
  gtk_widget_show (hbox33);
  gtk_box_pack_start (GTK_BOX (vbox3), hbox33, FALSE, FALSE, 0);

  buttonGGDelete = gtk_button_new_from_stock ("gtk-delete");
  gtk_widget_set_name (buttonGGDelete, "buttonGGDelete");
  gtk_widget_show (buttonGGDelete);
  gtk_box_pack_start (GTK_BOX (hbox33), buttonGGDelete, FALSE, FALSE, 0);
  gtk_button_set_relief (GTK_BUTTON (buttonGGDelete), GTK_RELIEF_NONE);

  buttonGGDesactivate = gtk_button_new ();
  gtk_widget_set_name (buttonGGDesactivate, "buttonGGDesactivate");
  gtk_widget_show (buttonGGDesactivate);
  gtk_box_pack_start (GTK_BOX (hbox33), buttonGGDesactivate, FALSE, FALSE, 0);
  gtk_button_set_relief (GTK_BUTTON (buttonGGDesactivate), GTK_RELIEF_NONE);

  alignment12 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_set_name (alignment12, "alignment12");
  gtk_widget_show (alignment12);
  gtk_container_add (GTK_CONTAINER (buttonGGDesactivate), alignment12);

  hbox28 = gtk_hbox_new (FALSE, 2);
  gtk_widget_set_name (hbox28, "hbox28");
  gtk_widget_show (hbox28);
  gtk_container_add (GTK_CONTAINER (alignment12), hbox28);

  image198 = gtk_image_new_from_stock ("gtk-remove", GTK_ICON_SIZE_BUTTON);
  gtk_widget_set_name (image198, "image198");
  gtk_widget_show (image198);
  gtk_box_pack_start (GTK_BOX (hbox28), image198, FALSE, FALSE, 0);

  label72 = gtk_label_new_with_mnemonic ("Desactivate all codes");
  gtk_widget_set_name (label72, "label72");
  gtk_widget_show (label72);
  gtk_box_pack_start (GTK_BOX (hbox28), label72, FALSE, FALSE, 0);

  button4 = gtk_button_new_from_stock ("gtk-help");
  gtk_widget_set_name (button4, "button4");
  gtk_widget_show (button4);
  gtk_box_pack_start (GTK_BOX (hbox33), button4, FALSE, FALSE, 0);
  gtk_button_set_relief (GTK_BUTTON (button4), GTK_RELIEF_NONE);

  buttonGGCancel = gtk_button_new_from_stock ("gtk-cancel");
  gtk_widget_set_name (buttonGGCancel, "buttonGGCancel");
  gtk_widget_show (buttonGGCancel);
  gtk_box_pack_start (GTK_BOX (hbox33), buttonGGCancel, FALSE, FALSE, 0);
  gtk_button_set_relief (GTK_BUTTON (buttonGGCancel), GTK_RELIEF_NONE);

  buttonGGOK = gtk_button_new_from_stock ("gtk-ok");
  gtk_widget_set_name (buttonGGOK, "buttonGGOK");
  gtk_widget_show (buttonGGOK);
  gtk_box_pack_start (GTK_BOX (hbox33), buttonGGOK, FALSE, FALSE, 0);
  gtk_button_set_relief (GTK_BUTTON (buttonGGOK), GTK_RELIEF_NONE);

  g_signal_connect ((gpointer) buttonGGAddCode, "clicked",
                    G_CALLBACK (on_buttonGGAddCode_clicked),
                    NULL);
  g_signal_connect ((gpointer) buttonGGDelete, "clicked",
                    G_CALLBACK (on_buttonGGDelete_clicked),
                    NULL);
  g_signal_connect ((gpointer) buttonGGDesactivate, "clicked",
                    G_CALLBACK (on_buttonGGDesactivate_clicked),
                    NULL);
  g_signal_connect_swapped ((gpointer) buttonGGCancel, "clicked",
                            G_CALLBACK (gtk_widget_destroy),
                            GTK_OBJECT (game_genie));
  g_signal_connect ((gpointer) buttonGGOK, "clicked",
                    G_CALLBACK (on_buttonGGOK_clicked),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (game_genie, game_genie, "game_genie");
  GLADE_HOOKUP_OBJECT (game_genie, vbox3, "vbox3");
  GLADE_HOOKUP_OBJECT (game_genie, frame2, "frame2");
  GLADE_HOOKUP_OBJECT (game_genie, label4, "label4");
  GLADE_HOOKUP_OBJECT (game_genie, label3, "label3");
  GLADE_HOOKUP_OBJECT (game_genie, vbox4, "vbox4");
  GLADE_HOOKUP_OBJECT (game_genie, table1, "table1");
  GLADE_HOOKUP_OBJECT (game_genie, label5, "label5");
  GLADE_HOOKUP_OBJECT (game_genie, label6, "label6");
  GLADE_HOOKUP_OBJECT (game_genie, code, "code");
  GLADE_HOOKUP_OBJECT (game_genie, name, "name");
  GLADE_HOOKUP_OBJECT (game_genie, buttonGGAddCode, "buttonGGAddCode");
  GLADE_HOOKUP_OBJECT (game_genie, alignment13, "alignment13");
  GLADE_HOOKUP_OBJECT (game_genie, hbox29, "hbox29");
  GLADE_HOOKUP_OBJECT (game_genie, image199, "image199");
  GLADE_HOOKUP_OBJECT (game_genie, label73, "label73");
  GLADE_HOOKUP_OBJECT (game_genie, hbox2, "hbox2");
  GLADE_HOOKUP_OBJECT (game_genie, scrolledwindow1, "scrolledwindow1");
  GLADE_HOOKUP_OBJECT (game_genie, ggListCode, "ggListCode");
  GLADE_HOOKUP_OBJECT (game_genie, hbox33, "hbox33");
  GLADE_HOOKUP_OBJECT (game_genie, buttonGGDelete, "buttonGGDelete");
  GLADE_HOOKUP_OBJECT (game_genie, buttonGGDesactivate, "buttonGGDesactivate");
  GLADE_HOOKUP_OBJECT (game_genie, alignment12, "alignment12");
  GLADE_HOOKUP_OBJECT (game_genie, hbox28, "hbox28");
  GLADE_HOOKUP_OBJECT (game_genie, image198, "image198");
  GLADE_HOOKUP_OBJECT (game_genie, label72, "label72");
  GLADE_HOOKUP_OBJECT (game_genie, button4, "button4");
  GLADE_HOOKUP_OBJECT (game_genie, buttonGGCancel, "buttonGGCancel");
  GLADE_HOOKUP_OBJECT (game_genie, buttonGGOK, "buttonGGOK");

  return game_genie;
}

GtkWidget*
create_color_adjust (void)
{
  GtkWidget *color_adjust;
  GdkPixbuf *color_adjust_icon_pixbuf;
  GtkWidget *vbox16;
  GtkWidget *hbox5;
  GtkWidget *vbox8;
  GtkWidget *table2;
  GtkWidget *label10;
  GtkWidget *label11;
  GtkWidget *contrast;
  GtkWidget *brightness;
  GtkWidget *hbox7;
  GtkWidget *greyscale;
  GtkWidget *invert;
  GtkWidget *hbox32;
  GtkWidget *buttonColorDefault;
  GtkWidget *alignment3;
  GtkWidget *hbox6;
  GtkWidget *image4;
  GtkWidget *label9;
  GtkWidget *buttonColorApply;
  GtkWidget *buttonColorClose;

  color_adjust = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_widget_set_name (color_adjust, "color_adjust");
  gtk_widget_set_size_request (color_adjust, 320, 160);
  gtk_container_set_border_width (GTK_CONTAINER (color_adjust), 5);
  gtk_window_set_title (GTK_WINDOW (color_adjust), "Color adjustment");
  gtk_window_set_position (GTK_WINDOW (color_adjust), GTK_WIN_POS_CENTER);
  gtk_window_set_modal (GTK_WINDOW (color_adjust), TRUE);
  gtk_window_set_resizable (GTK_WINDOW (color_adjust), FALSE);
  color_adjust_icon_pixbuf = create_pixbuf ("Gens2.ico");
  if (color_adjust_icon_pixbuf)
    {
      gtk_window_set_icon (GTK_WINDOW (color_adjust), color_adjust_icon_pixbuf);
      g_object_unref (color_adjust_icon_pixbuf);
    }

  vbox16 = gtk_vbox_new (FALSE, 5);
  gtk_widget_set_name (vbox16, "vbox16");
  gtk_widget_show (vbox16);
  gtk_container_add (GTK_CONTAINER (color_adjust), vbox16);

  hbox5 = gtk_hbox_new (FALSE, 5);
  gtk_widget_set_name (hbox5, "hbox5");
  gtk_widget_show (hbox5);
  gtk_box_pack_start (GTK_BOX (vbox16), hbox5, TRUE, TRUE, 0);

  vbox8 = gtk_vbox_new (FALSE, 5);
  gtk_widget_set_name (vbox8, "vbox8");
  gtk_widget_show (vbox8);
  gtk_box_pack_start (GTK_BOX (hbox5), vbox8, TRUE, TRUE, 0);

  table2 = gtk_table_new (2, 2, FALSE);
  gtk_widget_set_name (table2, "table2");
  gtk_widget_show (table2);
  gtk_box_pack_start (GTK_BOX (vbox8), table2, TRUE, FALSE, 0);
  gtk_table_set_row_spacings (GTK_TABLE (table2), 5);
  gtk_table_set_col_spacings (GTK_TABLE (table2), 5);

  label10 = gtk_label_new ("Contrast");
  gtk_widget_set_name (label10, "label10");
  gtk_widget_show (label10);
  gtk_table_attach (GTK_TABLE (table2), label10, 0, 1, 0, 1,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_misc_set_alignment (GTK_MISC (label10), 0, 0.5);

  label11 = gtk_label_new ("Brightness");
  gtk_widget_set_name (label11, "label11");
  gtk_widget_show (label11);
  gtk_table_attach (GTK_TABLE (table2), label11, 0, 1, 1, 2,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_misc_set_alignment (GTK_MISC (label11), 0, 0.5);

  contrast = gtk_hscale_new (GTK_ADJUSTMENT (gtk_adjustment_new (0, -100, 100, 1, 0, 0)));
  gtk_widget_set_name (contrast, "contrast");
  gtk_widget_show (contrast);
  gtk_table_attach (GTK_TABLE (table2), contrast, 1, 2, 0, 1,
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL),
                    (GtkAttachOptions) (GTK_FILL), 0, 0);
  gtk_scale_set_value_pos (GTK_SCALE (contrast), GTK_POS_RIGHT);
  gtk_scale_set_digits (GTK_SCALE (contrast), 0);

  brightness = gtk_hscale_new (GTK_ADJUSTMENT (gtk_adjustment_new (0, -100, 100, 1, 0, 0)));
  gtk_widget_set_name (brightness, "brightness");
  gtk_widget_show (brightness);
  gtk_table_attach (GTK_TABLE (table2), brightness, 1, 2, 1, 2,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (GTK_FILL), 0, 0);
  gtk_scale_set_value_pos (GTK_SCALE (brightness), GTK_POS_RIGHT);
  gtk_scale_set_digits (GTK_SCALE (brightness), 0);

  hbox7 = gtk_hbox_new (TRUE, 0);
  gtk_widget_set_name (hbox7, "hbox7");
  gtk_widget_show (hbox7);
  gtk_box_pack_start (GTK_BOX (vbox8), hbox7, FALSE, TRUE, 0);

  greyscale = gtk_check_button_new_with_mnemonic ("Greyscale");
  gtk_widget_set_name (greyscale, "greyscale");
  gtk_widget_show (greyscale);
  gtk_box_pack_start (GTK_BOX (hbox7), greyscale, FALSE, FALSE, 0);
  gtk_button_set_relief (GTK_BUTTON (greyscale), GTK_RELIEF_NONE);

  invert = gtk_check_button_new_with_mnemonic ("Invert");
  gtk_widget_set_name (invert, "invert");
  gtk_widget_show (invert);
  gtk_box_pack_start (GTK_BOX (hbox7), invert, FALSE, FALSE, 0);
  gtk_button_set_relief (GTK_BUTTON (invert), GTK_RELIEF_NONE);

  hbox32 = gtk_hbox_new (TRUE, 0);
  gtk_widget_set_name (hbox32, "hbox32");
  gtk_widget_show (hbox32);
  gtk_box_pack_start (GTK_BOX (vbox16), hbox32, FALSE, FALSE, 0);

  buttonColorDefault = gtk_button_new ();
  gtk_widget_set_name (buttonColorDefault, "buttonColorDefault");
  gtk_widget_show (buttonColorDefault);
  gtk_box_pack_start (GTK_BOX (hbox32), buttonColorDefault, FALSE, FALSE, 0);
  gtk_button_set_relief (GTK_BUTTON (buttonColorDefault), GTK_RELIEF_NONE);

  alignment3 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_set_name (alignment3, "alignment3");
  gtk_widget_show (alignment3);
  gtk_container_add (GTK_CONTAINER (buttonColorDefault), alignment3);

  hbox6 = gtk_hbox_new (FALSE, 2);
  gtk_widget_set_name (hbox6, "hbox6");
  gtk_widget_show (hbox6);
  gtk_container_add (GTK_CONTAINER (alignment3), hbox6);

  image4 = gtk_image_new_from_stock ("gtk-preferences", GTK_ICON_SIZE_BUTTON);
  gtk_widget_set_name (image4, "image4");
  gtk_widget_show (image4);
  gtk_box_pack_start (GTK_BOX (hbox6), image4, FALSE, FALSE, 0);

  label9 = gtk_label_new_with_mnemonic ("_Default");
  gtk_widget_set_name (label9, "label9");
  gtk_widget_show (label9);
  gtk_box_pack_start (GTK_BOX (hbox6), label9, FALSE, FALSE, 0);

  buttonColorApply = gtk_button_new_from_stock ("gtk-apply");
  gtk_widget_set_name (buttonColorApply, "buttonColorApply");
  gtk_widget_show (buttonColorApply);
  gtk_box_pack_start (GTK_BOX (hbox32), buttonColorApply, FALSE, FALSE, 0);
  gtk_button_set_relief (GTK_BUTTON (buttonColorApply), GTK_RELIEF_NONE);

  buttonColorClose = gtk_button_new_from_stock ("gtk-close");
  gtk_widget_set_name (buttonColorClose, "buttonColorClose");
  gtk_widget_show (buttonColorClose);
  gtk_box_pack_start (GTK_BOX (hbox32), buttonColorClose, FALSE, FALSE, 0);
  gtk_button_set_relief (GTK_BUTTON (buttonColorClose), GTK_RELIEF_NONE);

  g_signal_connect ((gpointer) buttonColorDefault, "clicked",
                    G_CALLBACK (on_buttonColorDefault_clicked),
                    NULL);
  g_signal_connect ((gpointer) buttonColorApply, "clicked",
                    G_CALLBACK (on_buttonColorApply_clicked),
                    NULL);
  g_signal_connect ((gpointer) buttonColorClose, "clicked",
                    G_CALLBACK (on_buttonColorClose_clicked),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (color_adjust, color_adjust, "color_adjust");
  GLADE_HOOKUP_OBJECT (color_adjust, vbox16, "vbox16");
  GLADE_HOOKUP_OBJECT (color_adjust, hbox5, "hbox5");
  GLADE_HOOKUP_OBJECT (color_adjust, vbox8, "vbox8");
  GLADE_HOOKUP_OBJECT (color_adjust, table2, "table2");
  GLADE_HOOKUP_OBJECT (color_adjust, label10, "label10");
  GLADE_HOOKUP_OBJECT (color_adjust, label11, "label11");
  GLADE_HOOKUP_OBJECT (color_adjust, contrast, "contrast");
  GLADE_HOOKUP_OBJECT (color_adjust, brightness, "brightness");
  GLADE_HOOKUP_OBJECT (color_adjust, hbox7, "hbox7");
  GLADE_HOOKUP_OBJECT (color_adjust, greyscale, "greyscale");
  GLADE_HOOKUP_OBJECT (color_adjust, invert, "invert");
  GLADE_HOOKUP_OBJECT (color_adjust, hbox32, "hbox32");
  GLADE_HOOKUP_OBJECT (color_adjust, buttonColorDefault, "buttonColorDefault");
  GLADE_HOOKUP_OBJECT (color_adjust, alignment3, "alignment3");
  GLADE_HOOKUP_OBJECT (color_adjust, hbox6, "hbox6");
  GLADE_HOOKUP_OBJECT (color_adjust, image4, "image4");
  GLADE_HOOKUP_OBJECT (color_adjust, label9, "label9");
  GLADE_HOOKUP_OBJECT (color_adjust, buttonColorApply, "buttonColorApply");
  GLADE_HOOKUP_OBJECT (color_adjust, buttonColorClose, "buttonColorClose");

  return color_adjust;
}

GtkWidget*
create_general_option (void)
{
  GtkWidget *general_option;
  GdkPixbuf *general_option_icon_pixbuf;
  GtkWidget *vbox9;
  GtkWidget *frame3;
  GtkWidget *table3;
  GtkWidget *autoFixChecksum;
  GtkWidget *fastBlur;
  GtkWidget *autoPause;
  GtkWidget *showCDLED;
  GtkWidget *label12;
  GtkWidget *frame4;
  GtkWidget *table4;
  GtkWidget *fpsEnable;
  GtkWidget *fpsTransparency;
  GtkWidget *fpsDoubleSized;
  GtkWidget *hbox10;
  GtkWidget *fpsWhite;
  GSList *fpsWhite_group = NULL;
  GtkWidget *image2826;
  GtkWidget *fpsBlue;
  GtkWidget *image2827;
  GtkWidget *fpsGreen;
  GtkWidget *image2828;
  GtkWidget *fpsRed;
  GtkWidget *image2829;
  GtkWidget *label13;
  GtkWidget *frame5;
  GtkWidget *table5;
  GtkWidget *messageEnable;
  GtkWidget *messageDoubleSized;
  GtkWidget *hbox9;
  GtkWidget *messageWhite;
  GSList *messageWhite_group = NULL;
  GtkWidget *image2830;
  GtkWidget *messageBlue;
  GtkWidget *image2831;
  GtkWidget *messageGreen;
  GtkWidget *image2832;
  GtkWidget *messageRed;
  GtkWidget *image2833;
  GtkWidget *messageTransparency;
  GtkWidget *label14;
  GtkWidget *frame6;
  GtkWidget *hbox11;
  GtkWidget *label16;
  GtkWidget *vbox15;
  GtkWidget *table13;
  GtkWidget *miscPink;
  GSList *miscPink_group = NULL;
  GtkWidget *image2839;
  GtkWidget *miscYellow;
  GtkWidget *image2840;
  GtkWidget *miscWhite;
  GtkWidget *image2841;
  GtkWidget *miscRed;
  GtkWidget *image2838;
  GtkWidget *miscLightBlue;
  GtkWidget *image2837;
  GtkWidget *miscGreen;
  GtkWidget *image2836;
  GtkWidget *miscBlue;
  GtkWidget *image2835;
  GtkWidget *miscBlack;
  GtkWidget *image2834;
  GtkWidget *label15;
  GtkWidget *hbox8;
  GtkWidget *buttonOptionHelp;
  GtkWidget *buttonOptionCancel;
  GtkWidget *buttonOptionOK;

  general_option = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_widget_set_name (general_option, "general_option");
  gtk_container_set_border_width (GTK_CONTAINER (general_option), 5);
  gtk_window_set_title (GTK_WINDOW (general_option), "General Option");
  gtk_window_set_position (GTK_WINDOW (general_option), GTK_WIN_POS_CENTER);
  gtk_window_set_modal (GTK_WINDOW (general_option), TRUE);
  gtk_window_set_resizable (GTK_WINDOW (general_option), FALSE);
  general_option_icon_pixbuf = create_pixbuf ("Gens2.ico");
  if (general_option_icon_pixbuf)
    {
      gtk_window_set_icon (GTK_WINDOW (general_option), general_option_icon_pixbuf);
      g_object_unref (general_option_icon_pixbuf);
    }

  vbox9 = gtk_vbox_new (FALSE, 5);
  gtk_widget_set_name (vbox9, "vbox9");
  gtk_widget_show (vbox9);
  gtk_container_add (GTK_CONTAINER (general_option), vbox9);

  frame3 = gtk_frame_new (NULL);
  gtk_widget_set_name (frame3, "frame3");
  gtk_widget_show (frame3);
  gtk_box_pack_start (GTK_BOX (vbox9), frame3, FALSE, TRUE, 0);
  gtk_container_set_border_width (GTK_CONTAINER (frame3), 5);
  gtk_frame_set_shadow_type (GTK_FRAME (frame3), GTK_SHADOW_NONE);

  table3 = gtk_table_new (2, 2, FALSE);
  gtk_widget_set_name (table3, "table3");
  gtk_widget_show (table3);
  gtk_container_add (GTK_CONTAINER (frame3), table3);
  gtk_table_set_col_spacings (GTK_TABLE (table3), 47);

  autoFixChecksum = gtk_check_button_new_with_mnemonic ("Auto Fix Checksum");
  gtk_widget_set_name (autoFixChecksum, "autoFixChecksum");
  gtk_widget_show (autoFixChecksum);
  gtk_table_attach (GTK_TABLE (table3), autoFixChecksum, 0, 1, 0, 1,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_container_set_border_width (GTK_CONTAINER (autoFixChecksum), 5);
  gtk_button_set_relief (GTK_BUTTON (autoFixChecksum), GTK_RELIEF_NONE);

  fastBlur = gtk_check_button_new_with_mnemonic ("Fast Blur");
  gtk_widget_set_name (fastBlur, "fastBlur");
  gtk_widget_show (fastBlur);
  gtk_table_attach (GTK_TABLE (table3), fastBlur, 0, 1, 1, 2,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_container_set_border_width (GTK_CONTAINER (fastBlur), 5);
  gtk_button_set_relief (GTK_BUTTON (fastBlur), GTK_RELIEF_NONE);

  autoPause = gtk_check_button_new_with_mnemonic ("Auto Pause");
  gtk_widget_set_name (autoPause, "autoPause");
  gtk_widget_show (autoPause);
  gtk_table_attach (GTK_TABLE (table3), autoPause, 1, 2, 0, 1,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_container_set_border_width (GTK_CONTAINER (autoPause), 5);
  gtk_button_set_relief (GTK_BUTTON (autoPause), GTK_RELIEF_NONE);

  showCDLED = gtk_check_button_new_with_mnemonic ("Show Sega-CD LED");
  gtk_widget_set_name (showCDLED, "showCDLED");
  gtk_widget_show (showCDLED);
  gtk_table_attach (GTK_TABLE (table3), showCDLED, 1, 2, 1, 2,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_container_set_border_width (GTK_CONTAINER (showCDLED), 5);
  gtk_button_set_relief (GTK_BUTTON (showCDLED), GTK_RELIEF_NONE);

  label12 = gtk_label_new ("<i><b>System</b></i>");
  gtk_widget_set_name (label12, "label12");
  gtk_widget_show (label12);
  gtk_frame_set_label_widget (GTK_FRAME (frame3), label12);
  gtk_label_set_use_markup (GTK_LABEL (label12), TRUE);

  frame4 = gtk_frame_new (NULL);
  gtk_widget_set_name (frame4, "frame4");
  gtk_widget_show (frame4);
  gtk_box_pack_start (GTK_BOX (vbox9), frame4, FALSE, TRUE, 0);
  gtk_container_set_border_width (GTK_CONTAINER (frame4), 5);
  gtk_frame_set_shadow_type (GTK_FRAME (frame4), GTK_SHADOW_NONE);

  table4 = gtk_table_new (2, 2, FALSE);
  gtk_widget_set_name (table4, "table4");
  gtk_widget_show (table4);
  gtk_container_add (GTK_CONTAINER (frame4), table4);
  gtk_table_set_col_spacings (GTK_TABLE (table4), 91);

  fpsEnable = gtk_check_button_new_with_mnemonic ("Enable");
  gtk_widget_set_name (fpsEnable, "fpsEnable");
  gtk_widget_show (fpsEnable);
  gtk_table_attach (GTK_TABLE (table4), fpsEnable, 0, 1, 0, 1,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_container_set_border_width (GTK_CONTAINER (fpsEnable), 5);
  gtk_button_set_relief (GTK_BUTTON (fpsEnable), GTK_RELIEF_NONE);

  fpsTransparency = gtk_check_button_new_with_mnemonic ("Transparency");
  gtk_widget_set_name (fpsTransparency, "fpsTransparency");
  gtk_widget_show (fpsTransparency);
  gtk_table_attach (GTK_TABLE (table4), fpsTransparency, 0, 1, 1, 2,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_container_set_border_width (GTK_CONTAINER (fpsTransparency), 5);
  gtk_button_set_relief (GTK_BUTTON (fpsTransparency), GTK_RELIEF_NONE);

  fpsDoubleSized = gtk_check_button_new_with_mnemonic ("Double Sized");
  gtk_widget_set_name (fpsDoubleSized, "fpsDoubleSized");
  gtk_widget_show (fpsDoubleSized);
  gtk_table_attach (GTK_TABLE (table4), fpsDoubleSized, 1, 2, 0, 1,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_container_set_border_width (GTK_CONTAINER (fpsDoubleSized), 5);
  gtk_button_set_relief (GTK_BUTTON (fpsDoubleSized), GTK_RELIEF_NONE);

  hbox10 = gtk_hbox_new (FALSE, 0);
  gtk_widget_set_name (hbox10, "hbox10");
  gtk_widget_show (hbox10);
  gtk_table_attach (GTK_TABLE (table4), hbox10, 1, 2, 1, 2,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (GTK_FILL), 0, 0);

  fpsWhite = gtk_radio_button_new (NULL);
  gtk_widget_set_name (fpsWhite, "fpsWhite");
  gtk_widget_show (fpsWhite);
  gtk_box_pack_start (GTK_BOX (hbox10), fpsWhite, FALSE, FALSE, 0);
  gtk_container_set_border_width (GTK_CONTAINER (fpsWhite), 5);
  gtk_button_set_relief (GTK_BUTTON (fpsWhite), GTK_RELIEF_NONE);
  gtk_radio_button_set_group (GTK_RADIO_BUTTON (fpsWhite), fpsWhite_group);
  fpsWhite_group = gtk_radio_button_get_group (GTK_RADIO_BUTTON (fpsWhite));
  gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (fpsWhite), TRUE);

  image2826 = create_pixmap (general_option, "bitmap1.png");
  gtk_widget_set_name (image2826, "image2826");
  gtk_widget_show (image2826);
  gtk_container_add (GTK_CONTAINER (fpsWhite), image2826);

  fpsBlue = gtk_radio_button_new (NULL);
  gtk_widget_set_name (fpsBlue, "fpsBlue");
  gtk_widget_show (fpsBlue);
  gtk_box_pack_start (GTK_BOX (hbox10), fpsBlue, FALSE, FALSE, 0);
  gtk_container_set_border_width (GTK_CONTAINER (fpsBlue), 5);
  gtk_button_set_relief (GTK_BUTTON (fpsBlue), GTK_RELIEF_NONE);
  gtk_radio_button_set_group (GTK_RADIO_BUTTON (fpsBlue), fpsWhite_group);
  fpsWhite_group = gtk_radio_button_get_group (GTK_RADIO_BUTTON (fpsBlue));

  image2827 = create_pixmap (general_option, "bmp00000.png");
  gtk_widget_set_name (image2827, "image2827");
  gtk_widget_show (image2827);
  gtk_container_add (GTK_CONTAINER (fpsBlue), image2827);

  fpsGreen = gtk_radio_button_new (NULL);
  gtk_widget_set_name (fpsGreen, "fpsGreen");
  gtk_widget_show (fpsGreen);
  gtk_box_pack_start (GTK_BOX (hbox10), fpsGreen, FALSE, FALSE, 0);
  gtk_container_set_border_width (GTK_CONTAINER (fpsGreen), 5);
  gtk_button_set_relief (GTK_BUTTON (fpsGreen), GTK_RELIEF_NONE);
  gtk_radio_button_set_group (GTK_RADIO_BUTTON (fpsGreen), fpsWhite_group);
  fpsWhite_group = gtk_radio_button_get_group (GTK_RADIO_BUTTON (fpsGreen));

  image2828 = create_pixmap (general_option, "bmp00001.png");
  gtk_widget_set_name (image2828, "image2828");
  gtk_widget_show (image2828);
  gtk_container_add (GTK_CONTAINER (fpsGreen), image2828);

  fpsRed = gtk_radio_button_new (NULL);
  gtk_widget_set_name (fpsRed, "fpsRed");
  gtk_widget_show (fpsRed);
  gtk_box_pack_start (GTK_BOX (hbox10), fpsRed, FALSE, FALSE, 0);
  gtk_container_set_border_width (GTK_CONTAINER (fpsRed), 5);
  gtk_button_set_relief (GTK_BUTTON (fpsRed), GTK_RELIEF_NONE);
  gtk_radio_button_set_group (GTK_RADIO_BUTTON (fpsRed), fpsWhite_group);
  fpsWhite_group = gtk_radio_button_get_group (GTK_RADIO_BUTTON (fpsRed));

  image2829 = create_pixmap (general_option, "bmp00002.png");
  gtk_widget_set_name (image2829, "image2829");
  gtk_widget_show (image2829);
  gtk_container_add (GTK_CONTAINER (fpsRed), image2829);

  label13 = gtk_label_new ("<i><b>Frame Per Second</b></i>");
  gtk_widget_set_name (label13, "label13");
  gtk_widget_show (label13);
  gtk_frame_set_label_widget (GTK_FRAME (frame4), label13);
  gtk_label_set_use_markup (GTK_LABEL (label13), TRUE);

  frame5 = gtk_frame_new (NULL);
  gtk_widget_set_name (frame5, "frame5");
  gtk_widget_show (frame5);
  gtk_box_pack_start (GTK_BOX (vbox9), frame5, FALSE, TRUE, 0);
  gtk_container_set_border_width (GTK_CONTAINER (frame5), 5);
  gtk_frame_set_shadow_type (GTK_FRAME (frame5), GTK_SHADOW_NONE);

  table5 = gtk_table_new (2, 2, FALSE);
  gtk_widget_set_name (table5, "table5");
  gtk_widget_show (table5);
  gtk_container_add (GTK_CONTAINER (frame5), table5);
  gtk_table_set_col_spacings (GTK_TABLE (table5), 91);

  messageEnable = gtk_check_button_new_with_mnemonic ("Enable");
  gtk_widget_set_name (messageEnable, "messageEnable");
  gtk_widget_show (messageEnable);
  gtk_table_attach (GTK_TABLE (table5), messageEnable, 0, 1, 0, 1,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_container_set_border_width (GTK_CONTAINER (messageEnable), 5);
  gtk_button_set_relief (GTK_BUTTON (messageEnable), GTK_RELIEF_NONE);
  gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (messageEnable), TRUE);

  messageDoubleSized = gtk_check_button_new_with_mnemonic ("Double Sized");
  gtk_widget_set_name (messageDoubleSized, "messageDoubleSized");
  gtk_widget_show (messageDoubleSized);
  gtk_table_attach (GTK_TABLE (table5), messageDoubleSized, 1, 2, 0, 1,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_container_set_border_width (GTK_CONTAINER (messageDoubleSized), 5);
  gtk_button_set_relief (GTK_BUTTON (messageDoubleSized), GTK_RELIEF_NONE);

  hbox9 = gtk_hbox_new (FALSE, 0);
  gtk_widget_set_name (hbox9, "hbox9");
  gtk_widget_show (hbox9);
  gtk_table_attach (GTK_TABLE (table5), hbox9, 1, 2, 1, 2,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (GTK_FILL), 0, 0);

  messageWhite = gtk_radio_button_new (NULL);
  gtk_widget_set_name (messageWhite, "messageWhite");
  gtk_widget_show (messageWhite);
  gtk_box_pack_start (GTK_BOX (hbox9), messageWhite, FALSE, FALSE, 0);
  gtk_container_set_border_width (GTK_CONTAINER (messageWhite), 5);
  gtk_button_set_relief (GTK_BUTTON (messageWhite), GTK_RELIEF_NONE);
  gtk_radio_button_set_group (GTK_RADIO_BUTTON (messageWhite), messageWhite_group);
  messageWhite_group = gtk_radio_button_get_group (GTK_RADIO_BUTTON (messageWhite));
  gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (messageWhite), TRUE);

  image2830 = create_pixmap (general_option, "bitmap1.png");
  gtk_widget_set_name (image2830, "image2830");
  gtk_widget_show (image2830);
  gtk_container_add (GTK_CONTAINER (messageWhite), image2830);

  messageBlue = gtk_radio_button_new (NULL);
  gtk_widget_set_name (messageBlue, "messageBlue");
  gtk_widget_show (messageBlue);
  gtk_box_pack_start (GTK_BOX (hbox9), messageBlue, FALSE, FALSE, 0);
  gtk_container_set_border_width (GTK_CONTAINER (messageBlue), 5);
  gtk_button_set_relief (GTK_BUTTON (messageBlue), GTK_RELIEF_NONE);
  gtk_radio_button_set_group (GTK_RADIO_BUTTON (messageBlue), messageWhite_group);
  messageWhite_group = gtk_radio_button_get_group (GTK_RADIO_BUTTON (messageBlue));

  image2831 = create_pixmap (general_option, "bmp00000.png");
  gtk_widget_set_name (image2831, "image2831");
  gtk_widget_show (image2831);
  gtk_container_add (GTK_CONTAINER (messageBlue), image2831);

  messageGreen = gtk_radio_button_new (NULL);
  gtk_widget_set_name (messageGreen, "messageGreen");
  gtk_widget_show (messageGreen);
  gtk_box_pack_start (GTK_BOX (hbox9), messageGreen, FALSE, FALSE, 0);
  gtk_container_set_border_width (GTK_CONTAINER (messageGreen), 5);
  gtk_button_set_relief (GTK_BUTTON (messageGreen), GTK_RELIEF_NONE);
  gtk_radio_button_set_group (GTK_RADIO_BUTTON (messageGreen), messageWhite_group);
  messageWhite_group = gtk_radio_button_get_group (GTK_RADIO_BUTTON (messageGreen));

  image2832 = create_pixmap (general_option, "bmp00001.png");
  gtk_widget_set_name (image2832, "image2832");
  gtk_widget_show (image2832);
  gtk_container_add (GTK_CONTAINER (messageGreen), image2832);

  messageRed = gtk_radio_button_new (NULL);
  gtk_widget_set_name (messageRed, "messageRed");
  gtk_widget_show (messageRed);
  gtk_box_pack_start (GTK_BOX (hbox9), messageRed, FALSE, FALSE, 0);
  gtk_container_set_border_width (GTK_CONTAINER (messageRed), 5);
  gtk_button_set_relief (GTK_BUTTON (messageRed), GTK_RELIEF_NONE);
  gtk_radio_button_set_group (GTK_RADIO_BUTTON (messageRed), messageWhite_group);
  messageWhite_group = gtk_radio_button_get_group (GTK_RADIO_BUTTON (messageRed));

  image2833 = create_pixmap (general_option, "bmp00002.png");
  gtk_widget_set_name (image2833, "image2833");
  gtk_widget_show (image2833);
  gtk_container_add (GTK_CONTAINER (messageRed), image2833);

  messageTransparency = gtk_check_button_new_with_mnemonic ("Transparency");
  gtk_widget_set_name (messageTransparency, "messageTransparency");
  gtk_widget_show (messageTransparency);
  gtk_table_attach (GTK_TABLE (table5), messageTransparency, 0, 1, 1, 2,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_container_set_border_width (GTK_CONTAINER (messageTransparency), 5);
  gtk_button_set_relief (GTK_BUTTON (messageTransparency), GTK_RELIEF_NONE);
  gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (messageTransparency), TRUE);

  label14 = gtk_label_new ("<i><b>Message</b></i>");
  gtk_widget_set_name (label14, "label14");
  gtk_widget_show (label14);
  gtk_frame_set_label_widget (GTK_FRAME (frame5), label14);
  gtk_label_set_use_markup (GTK_LABEL (label14), TRUE);

  frame6 = gtk_frame_new (NULL);
  gtk_widget_set_name (frame6, "frame6");
  gtk_widget_show (frame6);
  gtk_box_pack_start (GTK_BOX (vbox9), frame6, FALSE, TRUE, 0);
  gtk_container_set_border_width (GTK_CONTAINER (frame6), 5);
  gtk_frame_set_shadow_type (GTK_FRAME (frame6), GTK_SHADOW_NONE);

  hbox11 = gtk_hbox_new (FALSE, 102);
  gtk_widget_set_name (hbox11, "hbox11");
  gtk_widget_show (hbox11);
  gtk_container_add (GTK_CONTAINER (frame6), hbox11);
  gtk_container_set_border_width (GTK_CONTAINER (hbox11), 5);

  label16 = gtk_label_new ("Intro effect color");
  gtk_widget_set_name (label16, "label16");
  gtk_widget_show (label16);
  gtk_box_pack_start (GTK_BOX (hbox11), label16, FALSE, FALSE, 0);

  vbox15 = gtk_vbox_new (FALSE, 0);
  gtk_widget_set_name (vbox15, "vbox15");
  gtk_widget_show (vbox15);
  gtk_box_pack_start (GTK_BOX (hbox11), vbox15, TRUE, TRUE, 0);

  table13 = gtk_table_new (2, 4, FALSE);
  gtk_widget_set_name (table13, "table13");
  gtk_widget_show (table13);
  gtk_box_pack_start (GTK_BOX (vbox15), table13, TRUE, TRUE, 0);

  miscPink = gtk_radio_button_new (NULL);
  gtk_widget_set_name (miscPink, "miscPink");
  gtk_widget_show (miscPink);
  gtk_table_attach (GTK_TABLE (table13), miscPink, 1, 2, 1, 2,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_container_set_border_width (GTK_CONTAINER (miscPink), 5);
  gtk_button_set_relief (GTK_BUTTON (miscPink), GTK_RELIEF_NONE);
  gtk_radio_button_set_group (GTK_RADIO_BUTTON (miscPink), miscPink_group);
  miscPink_group = gtk_radio_button_get_group (GTK_RADIO_BUTTON (miscPink));

  image2839 = create_pixmap (general_option, "bmp00005.png");
  gtk_widget_set_name (image2839, "image2839");
  gtk_widget_show (image2839);
  gtk_container_add (GTK_CONTAINER (miscPink), image2839);

  miscYellow = gtk_radio_button_new (NULL);
  gtk_widget_set_name (miscYellow, "miscYellow");
  gtk_widget_show (miscYellow);
  gtk_table_attach (GTK_TABLE (table13), miscYellow, 2, 3, 1, 2,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_container_set_border_width (GTK_CONTAINER (miscYellow), 5);
  gtk_button_set_relief (GTK_BUTTON (miscYellow), GTK_RELIEF_NONE);
  gtk_radio_button_set_group (GTK_RADIO_BUTTON (miscYellow), miscPink_group);
  miscPink_group = gtk_radio_button_get_group (GTK_RADIO_BUTTON (miscYellow));

  image2840 = create_pixmap (general_option, "bmp00006.png");
  gtk_widget_set_name (image2840, "image2840");
  gtk_widget_show (image2840);
  gtk_container_add (GTK_CONTAINER (miscYellow), image2840);

  miscWhite = gtk_radio_button_new (NULL);
  gtk_widget_set_name (miscWhite, "miscWhite");
  gtk_widget_show (miscWhite);
  gtk_table_attach (GTK_TABLE (table13), miscWhite, 3, 4, 1, 2,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_container_set_border_width (GTK_CONTAINER (miscWhite), 5);
  gtk_button_set_relief (GTK_BUTTON (miscWhite), GTK_RELIEF_NONE);
  gtk_radio_button_set_group (GTK_RADIO_BUTTON (miscWhite), miscPink_group);
  miscPink_group = gtk_radio_button_get_group (GTK_RADIO_BUTTON (miscWhite));

  image2841 = create_pixmap (general_option, "bitmap1.png");
  gtk_widget_set_name (image2841, "image2841");
  gtk_widget_show (image2841);
  gtk_container_add (GTK_CONTAINER (miscWhite), image2841);

  miscRed = gtk_radio_button_new (NULL);
  gtk_widget_set_name (miscRed, "miscRed");
  gtk_widget_show (miscRed);
  gtk_table_attach (GTK_TABLE (table13), miscRed, 0, 1, 1, 2,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_container_set_border_width (GTK_CONTAINER (miscRed), 5);
  gtk_button_set_relief (GTK_BUTTON (miscRed), GTK_RELIEF_NONE);
  gtk_radio_button_set_group (GTK_RADIO_BUTTON (miscRed), miscPink_group);
  miscPink_group = gtk_radio_button_get_group (GTK_RADIO_BUTTON (miscRed));

  image2838 = create_pixmap (general_option, "bmp00002.png");
  gtk_widget_set_name (image2838, "image2838");
  gtk_widget_show (image2838);
  gtk_container_add (GTK_CONTAINER (miscRed), image2838);

  miscLightBlue = gtk_radio_button_new (NULL);
  gtk_widget_set_name (miscLightBlue, "miscLightBlue");
  gtk_widget_show (miscLightBlue);
  gtk_table_attach (GTK_TABLE (table13), miscLightBlue, 3, 4, 0, 1,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_container_set_border_width (GTK_CONTAINER (miscLightBlue), 5);
  gtk_button_set_relief (GTK_BUTTON (miscLightBlue), GTK_RELIEF_NONE);
  gtk_radio_button_set_group (GTK_RADIO_BUTTON (miscLightBlue), miscPink_group);
  miscPink_group = gtk_radio_button_get_group (GTK_RADIO_BUTTON (miscLightBlue));

  image2837 = create_pixmap (general_option, "bmp00004.png");
  gtk_widget_set_name (image2837, "image2837");
  gtk_widget_show (image2837);
  gtk_container_add (GTK_CONTAINER (miscLightBlue), image2837);

  miscGreen = gtk_radio_button_new (NULL);
  gtk_widget_set_name (miscGreen, "miscGreen");
  gtk_widget_show (miscGreen);
  gtk_table_attach (GTK_TABLE (table13), miscGreen, 2, 3, 0, 1,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_container_set_border_width (GTK_CONTAINER (miscGreen), 5);
  gtk_button_set_relief (GTK_BUTTON (miscGreen), GTK_RELIEF_NONE);
  gtk_radio_button_set_group (GTK_RADIO_BUTTON (miscGreen), miscPink_group);
  miscPink_group = gtk_radio_button_get_group (GTK_RADIO_BUTTON (miscGreen));

  image2836 = create_pixmap (general_option, "bmp00001.png");
  gtk_widget_set_name (image2836, "image2836");
  gtk_widget_show (image2836);
  gtk_container_add (GTK_CONTAINER (miscGreen), image2836);

  miscBlue = gtk_radio_button_new (NULL);
  gtk_widget_set_name (miscBlue, "miscBlue");
  gtk_widget_show (miscBlue);
  gtk_table_attach (GTK_TABLE (table13), miscBlue, 1, 2, 0, 1,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_container_set_border_width (GTK_CONTAINER (miscBlue), 5);
  gtk_button_set_relief (GTK_BUTTON (miscBlue), GTK_RELIEF_NONE);
  gtk_radio_button_set_group (GTK_RADIO_BUTTON (miscBlue), miscPink_group);
  miscPink_group = gtk_radio_button_get_group (GTK_RADIO_BUTTON (miscBlue));

  image2835 = create_pixmap (general_option, "bmp00000.png");
  gtk_widget_set_name (image2835, "image2835");
  gtk_widget_show (image2835);
  gtk_container_add (GTK_CONTAINER (miscBlue), image2835);

  miscBlack = gtk_radio_button_new (NULL);
  gtk_widget_set_name (miscBlack, "miscBlack");
  gtk_widget_show (miscBlack);
  gtk_table_attach (GTK_TABLE (table13), miscBlack, 0, 1, 0, 1,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_container_set_border_width (GTK_CONTAINER (miscBlack), 5);
  gtk_button_set_relief (GTK_BUTTON (miscBlack), GTK_RELIEF_NONE);
  gtk_radio_button_set_group (GTK_RADIO_BUTTON (miscBlack), miscPink_group);
  miscPink_group = gtk_radio_button_get_group (GTK_RADIO_BUTTON (miscBlack));
  gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (miscBlack), TRUE);

  image2834 = create_pixmap (general_option, "bmp00003.png");
  gtk_widget_set_name (image2834, "image2834");
  gtk_widget_show (image2834);
  gtk_container_add (GTK_CONTAINER (miscBlack), image2834);

  label15 = gtk_label_new ("<i><b>Miscellaneous options</b></i>");
  gtk_widget_set_name (label15, "label15");
  gtk_widget_show (label15);
  gtk_frame_set_label_widget (GTK_FRAME (frame6), label15);
  gtk_label_set_use_markup (GTK_LABEL (label15), TRUE);

  hbox8 = gtk_hbox_new (TRUE, 0);
  gtk_widget_set_name (hbox8, "hbox8");
  gtk_widget_show (hbox8);
  gtk_box_pack_start (GTK_BOX (vbox9), hbox8, FALSE, TRUE, 0);
  gtk_container_set_border_width (GTK_CONTAINER (hbox8), 5);

  buttonOptionHelp = gtk_button_new_from_stock ("gtk-help");
  gtk_widget_set_name (buttonOptionHelp, "buttonOptionHelp");
  gtk_widget_show (buttonOptionHelp);
  gtk_box_pack_start (GTK_BOX (hbox8), buttonOptionHelp, FALSE, FALSE, 0);
  gtk_button_set_relief (GTK_BUTTON (buttonOptionHelp), GTK_RELIEF_NONE);

  buttonOptionCancel = gtk_button_new_from_stock ("gtk-cancel");
  gtk_widget_set_name (buttonOptionCancel, "buttonOptionCancel");
  gtk_widget_show (buttonOptionCancel);
  gtk_box_pack_start (GTK_BOX (hbox8), buttonOptionCancel, FALSE, FALSE, 0);
  gtk_button_set_relief (GTK_BUTTON (buttonOptionCancel), GTK_RELIEF_NONE);

  buttonOptionOK = gtk_button_new_from_stock ("gtk-ok");
  gtk_widget_set_name (buttonOptionOK, "buttonOptionOK");
  gtk_widget_show (buttonOptionOK);
  gtk_box_pack_start (GTK_BOX (hbox8), buttonOptionOK, FALSE, FALSE, 0);
  gtk_button_set_relief (GTK_BUTTON (buttonOptionOK), GTK_RELIEF_NONE);

  g_signal_connect_swapped ((gpointer) buttonOptionCancel, "clicked",
                            G_CALLBACK (gtk_widget_destroy),
                            GTK_OBJECT (general_option));
  g_signal_connect ((gpointer) buttonOptionOK, "clicked",
                    G_CALLBACK (on_buttonOptionOK_clicked),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (general_option, general_option, "general_option");
  GLADE_HOOKUP_OBJECT (general_option, vbox9, "vbox9");
  GLADE_HOOKUP_OBJECT (general_option, frame3, "frame3");
  GLADE_HOOKUP_OBJECT (general_option, table3, "table3");
  GLADE_HOOKUP_OBJECT (general_option, autoFixChecksum, "autoFixChecksum");
  GLADE_HOOKUP_OBJECT (general_option, fastBlur, "fastBlur");
  GLADE_HOOKUP_OBJECT (general_option, autoPause, "autoPause");
  GLADE_HOOKUP_OBJECT (general_option, showCDLED, "showCDLED");
  GLADE_HOOKUP_OBJECT (general_option, label12, "label12");
  GLADE_HOOKUP_OBJECT (general_option, frame4, "frame4");
  GLADE_HOOKUP_OBJECT (general_option, table4, "table4");
  GLADE_HOOKUP_OBJECT (general_option, fpsEnable, "fpsEnable");
  GLADE_HOOKUP_OBJECT (general_option, fpsTransparency, "fpsTransparency");
  GLADE_HOOKUP_OBJECT (general_option, fpsDoubleSized, "fpsDoubleSized");
  GLADE_HOOKUP_OBJECT (general_option, hbox10, "hbox10");
  GLADE_HOOKUP_OBJECT (general_option, fpsWhite, "fpsWhite");
  GLADE_HOOKUP_OBJECT (general_option, image2826, "image2826");
  GLADE_HOOKUP_OBJECT (general_option, fpsBlue, "fpsBlue");
  GLADE_HOOKUP_OBJECT (general_option, image2827, "image2827");
  GLADE_HOOKUP_OBJECT (general_option, fpsGreen, "fpsGreen");
  GLADE_HOOKUP_OBJECT (general_option, image2828, "image2828");
  GLADE_HOOKUP_OBJECT (general_option, fpsRed, "fpsRed");
  GLADE_HOOKUP_OBJECT (general_option, image2829, "image2829");
  GLADE_HOOKUP_OBJECT (general_option, label13, "label13");
  GLADE_HOOKUP_OBJECT (general_option, frame5, "frame5");
  GLADE_HOOKUP_OBJECT (general_option, table5, "table5");
  GLADE_HOOKUP_OBJECT (general_option, messageEnable, "messageEnable");
  GLADE_HOOKUP_OBJECT (general_option, messageDoubleSized, "messageDoubleSized");
  GLADE_HOOKUP_OBJECT (general_option, hbox9, "hbox9");
  GLADE_HOOKUP_OBJECT (general_option, messageWhite, "messageWhite");
  GLADE_HOOKUP_OBJECT (general_option, image2830, "image2830");
  GLADE_HOOKUP_OBJECT (general_option, messageBlue, "messageBlue");
  GLADE_HOOKUP_OBJECT (general_option, image2831, "image2831");
  GLADE_HOOKUP_OBJECT (general_option, messageGreen, "messageGreen");
  GLADE_HOOKUP_OBJECT (general_option, image2832, "image2832");
  GLADE_HOOKUP_OBJECT (general_option, messageRed, "messageRed");
  GLADE_HOOKUP_OBJECT (general_option, image2833, "image2833");
  GLADE_HOOKUP_OBJECT (general_option, messageTransparency, "messageTransparency");
  GLADE_HOOKUP_OBJECT (general_option, label14, "label14");
  GLADE_HOOKUP_OBJECT (general_option, frame6, "frame6");
  GLADE_HOOKUP_OBJECT (general_option, hbox11, "hbox11");
  GLADE_HOOKUP_OBJECT (general_option, label16, "label16");
  GLADE_HOOKUP_OBJECT (general_option, vbox15, "vbox15");
  GLADE_HOOKUP_OBJECT (general_option, table13, "table13");
  GLADE_HOOKUP_OBJECT (general_option, miscPink, "miscPink");
  GLADE_HOOKUP_OBJECT (general_option, image2839, "image2839");
  GLADE_HOOKUP_OBJECT (general_option, miscYellow, "miscYellow");
  GLADE_HOOKUP_OBJECT (general_option, image2840, "image2840");
  GLADE_HOOKUP_OBJECT (general_option, miscWhite, "miscWhite");
  GLADE_HOOKUP_OBJECT (general_option, image2841, "image2841");
  GLADE_HOOKUP_OBJECT (general_option, miscRed, "miscRed");
  GLADE_HOOKUP_OBJECT (general_option, image2838, "image2838");
  GLADE_HOOKUP_OBJECT (general_option, miscLightBlue, "miscLightBlue");
  GLADE_HOOKUP_OBJECT (general_option, image2837, "image2837");
  GLADE_HOOKUP_OBJECT (general_option, miscGreen, "miscGreen");
  GLADE_HOOKUP_OBJECT (general_option, image2836, "image2836");
  GLADE_HOOKUP_OBJECT (general_option, miscBlue, "miscBlue");
  GLADE_HOOKUP_OBJECT (general_option, image2835, "image2835");
  GLADE_HOOKUP_OBJECT (general_option, miscBlack, "miscBlack");
  GLADE_HOOKUP_OBJECT (general_option, image2834, "image2834");
  GLADE_HOOKUP_OBJECT (general_option, label15, "label15");
  GLADE_HOOKUP_OBJECT (general_option, hbox8, "hbox8");
  GLADE_HOOKUP_OBJECT (general_option, buttonOptionHelp, "buttonOptionHelp");
  GLADE_HOOKUP_OBJECT (general_option, buttonOptionCancel, "buttonOptionCancel");
  GLADE_HOOKUP_OBJECT (general_option, buttonOptionOK, "buttonOptionOK");

  return general_option;
}

GtkWidget*
create_controllers_settings (void)
{
  GtkWidget *controllers_settings;
  GdkPixbuf *controllers_settings_icon_pixbuf;
  GtkWidget *table6;
  GtkWidget *frame7;
  GtkWidget *vbox10;
  GtkWidget *hbox14;
  GtkWidget *label20;
  GtkWidget *port1;
  GtkWidget *menu9;
  GtkWidget *item13;
  GtkWidget *item14;
  GtkWidget *table7;
  GtkWidget *label21;
  GtkWidget *label22;
  GtkWidget *label23;
  GtkWidget *label24;
  GtkWidget *buttonRedef1;
  GtkWidget *alignment4;
  GtkWidget *hbox15;
  GtkWidget *image23;
  GtkWidget *label25;
  GtkWidget *buttonRedef1B;
  GtkWidget *alignment5;
  GtkWidget *hbox16;
  GtkWidget *image24;
  GtkWidget *label26;
  GtkWidget *buttonRedef1C;
  GtkWidget *alignment6;
  GtkWidget *hbox17;
  GtkWidget *image25;
  GtkWidget *label27;
  GtkWidget *buttonRedef1D;
  GtkWidget *alignment7;
  GtkWidget *hbox18;
  GtkWidget *image26;
  GtkWidget *label28;
  GtkWidget *padp1;
  GtkWidget *menu1;
  GtkWidget *item11;
  GtkWidget *item12;
  GtkWidget *padp1b;
  GtkWidget *menu2;
  GtkWidget *menuitem7;
  GtkWidget *menuitem8;
  GtkWidget *padp1c;
  GtkWidget *menu3;
  GtkWidget *menuitem9;
  GtkWidget *menuitem10;
  GtkWidget *padp1d;
  GtkWidget *menu4;
  GtkWidget *menuitem11;
  GtkWidget *menuitem12;
  GtkWidget *label17;
  GtkWidget *frame8;
  GtkWidget *label19;
  GtkWidget *label18;
  GtkWidget *frame9;
  GtkWidget *vbox11;
  GtkWidget *hbox19;
  GtkWidget *label29;
  GtkWidget *port2;
  GtkWidget *menu10;
  GtkWidget *menuitem21;
  GtkWidget *menuitem22;
  GtkWidget *table8;
  GtkWidget *label30;
  GtkWidget *label31;
  GtkWidget *label32;
  GtkWidget *label33;
  GtkWidget *buttonRedef2;
  GtkWidget *alignment8;
  GtkWidget *hbox20;
  GtkWidget *image27;
  GtkWidget *label34;
  GtkWidget *buttonRedef2B;
  GtkWidget *alignment9;
  GtkWidget *hbox21;
  GtkWidget *image28;
  GtkWidget *label35;
  GtkWidget *buttonRedef2C;
  GtkWidget *alignment10;
  GtkWidget *hbox22;
  GtkWidget *image29;
  GtkWidget *label36;
  GtkWidget *buttonRedef2D;
  GtkWidget *alignment11;
  GtkWidget *hbox23;
  GtkWidget *image30;
  GtkWidget *label37;
  GtkWidget *padp2;
  GtkWidget *menu5;
  GtkWidget *menuitem13;
  GtkWidget *menuitem14;
  GtkWidget *padp2b;
  GtkWidget *menu6;
  GtkWidget *menuitem15;
  GtkWidget *menuitem16;
  GtkWidget *padp2c;
  GtkWidget *menu7;
  GtkWidget *menuitem17;
  GtkWidget *menuitem18;
  GtkWidget *padp2d;
  GtkWidget *menu8;
  GtkWidget *menuitem19;
  GtkWidget *menuitem20;
  GtkWidget *label38;
  GtkWidget *vbox12;
  GtkWidget *frame10;
  GtkWidget *keyEcho;
  GtkWidget *settingKeys;
  GtkWidget *hbox24;
  GtkWidget *button23;
  GtkWidget *buttonControlSetOK;

  controllers_settings = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_widget_set_name (controllers_settings, "controllers_settings");
  gtk_container_set_border_width (GTK_CONTAINER (controllers_settings), 5);
  gtk_widget_set_events (controllers_settings, GDK_KEY_PRESS_MASK);
  gtk_window_set_title (GTK_WINDOW (controllers_settings), "Controllers Settings");
  gtk_window_set_position (GTK_WINDOW (controllers_settings), GTK_WIN_POS_CENTER);
  gtk_window_set_modal (GTK_WINDOW (controllers_settings), TRUE);
  gtk_window_set_resizable (GTK_WINDOW (controllers_settings), FALSE);
  controllers_settings_icon_pixbuf = create_pixbuf ("Gens2.ico");
  if (controllers_settings_icon_pixbuf)
    {
      gtk_window_set_icon (GTK_WINDOW (controllers_settings), controllers_settings_icon_pixbuf);
      g_object_unref (controllers_settings_icon_pixbuf);
    }

  table6 = gtk_table_new (2, 2, FALSE);
  gtk_widget_set_name (table6, "table6");
  gtk_widget_show (table6);
  gtk_container_add (GTK_CONTAINER (controllers_settings), table6);
  gtk_container_set_border_width (GTK_CONTAINER (table6), 5);
  gtk_table_set_row_spacings (GTK_TABLE (table6), 5);
  gtk_table_set_col_spacings (GTK_TABLE (table6), 5);

  frame7 = gtk_frame_new (NULL);
  gtk_widget_set_name (frame7, "frame7");
  gtk_widget_show (frame7);
  gtk_table_attach (GTK_TABLE (table6), frame7, 0, 1, 0, 1,
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL),
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL), 0, 0);
  gtk_container_set_border_width (GTK_CONTAINER (frame7), 5);
  gtk_frame_set_shadow_type (GTK_FRAME (frame7), GTK_SHADOW_NONE);

  vbox10 = gtk_vbox_new (FALSE, 0);
  gtk_widget_set_name (vbox10, "vbox10");
  gtk_widget_show (vbox10);
  gtk_container_add (GTK_CONTAINER (frame7), vbox10);

  hbox14 = gtk_hbox_new (FALSE, 5);
  gtk_widget_set_name (hbox14, "hbox14");
  gtk_widget_show (hbox14);
  gtk_box_pack_start (GTK_BOX (vbox10), hbox14, TRUE, TRUE, 0);

  label20 = gtk_label_new ("Controller connected:");
  gtk_widget_set_name (label20, "label20");
  gtk_widget_show (label20);
  gtk_box_pack_start (GTK_BOX (hbox14), label20, FALSE, FALSE, 0);

  port1 = gtk_option_menu_new ();
  gtk_widget_set_name (port1, "port1");
  gtk_widget_show (port1);
  gtk_box_pack_start (GTK_BOX (hbox14), port1, FALSE, FALSE, 0);

  menu9 = gtk_menu_new ();
  gtk_widget_set_name (menu9, "menu9");

  item13 = gtk_menu_item_new_with_mnemonic ("pad");
  gtk_widget_set_name (item13, "item13");
  gtk_widget_show (item13);
  gtk_container_add (GTK_CONTAINER (menu9), item13);

  item14 = gtk_menu_item_new_with_mnemonic ("teamplayer");
  gtk_widget_set_name (item14, "item14");
  gtk_widget_show (item14);
  gtk_container_add (GTK_CONTAINER (menu9), item14);

  gtk_option_menu_set_menu (GTK_OPTION_MENU (port1), menu9);

  table7 = gtk_table_new (4, 3, FALSE);
  gtk_widget_set_name (table7, "table7");
  gtk_widget_show (table7);
  gtk_box_pack_start (GTK_BOX (vbox10), table7, TRUE, TRUE, 0);
  gtk_table_set_col_spacings (GTK_TABLE (table7), 10);

  label21 = gtk_label_new ("Player 1");
  gtk_widget_set_name (label21, "label21");
  gtk_widget_show (label21);
  gtk_table_attach (GTK_TABLE (table7), label21, 0, 1, 0, 1,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_misc_set_alignment (GTK_MISC (label21), 0, 0.5);

  label22 = gtk_label_new ("Player 1-B");
  gtk_widget_set_name (label22, "label22");
  gtk_widget_show (label22);
  gtk_table_attach (GTK_TABLE (table7), label22, 0, 1, 1, 2,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_misc_set_alignment (GTK_MISC (label22), 0, 0.5);

  label23 = gtk_label_new ("Player 1-C");
  gtk_widget_set_name (label23, "label23");
  gtk_widget_show (label23);
  gtk_table_attach (GTK_TABLE (table7), label23, 0, 1, 2, 3,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_misc_set_alignment (GTK_MISC (label23), 0, 0.5);

  label24 = gtk_label_new ("Player 1-D");
  gtk_widget_set_name (label24, "label24");
  gtk_widget_show (label24);
  gtk_table_attach (GTK_TABLE (table7), label24, 0, 1, 3, 4,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_misc_set_alignment (GTK_MISC (label24), 0, 0.5);

  buttonRedef1 = gtk_button_new ();
  gtk_widget_set_name (buttonRedef1, "buttonRedef1");
  gtk_widget_show (buttonRedef1);
  gtk_table_attach (GTK_TABLE (table7), buttonRedef1, 2, 3, 0, 1,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_button_set_relief (GTK_BUTTON (buttonRedef1), GTK_RELIEF_NONE);

  alignment4 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_set_name (alignment4, "alignment4");
  gtk_widget_show (alignment4);
  gtk_container_add (GTK_CONTAINER (buttonRedef1), alignment4);

  hbox15 = gtk_hbox_new (FALSE, 2);
  gtk_widget_set_name (hbox15, "hbox15");
  gtk_widget_show (hbox15);
  gtk_container_add (GTK_CONTAINER (alignment4), hbox15);

  image23 = gtk_image_new_from_stock ("gtk-bold", GTK_ICON_SIZE_BUTTON);
  gtk_widget_set_name (image23, "image23");
  gtk_widget_show (image23);
  gtk_box_pack_start (GTK_BOX (hbox15), image23, FALSE, FALSE, 0);

  label25 = gtk_label_new_with_mnemonic ("Redefine Keys");
  gtk_widget_set_name (label25, "label25");
  gtk_widget_show (label25);
  gtk_box_pack_start (GTK_BOX (hbox15), label25, FALSE, FALSE, 0);

  buttonRedef1B = gtk_button_new ();
  gtk_widget_set_name (buttonRedef1B, "buttonRedef1B");
  gtk_widget_show (buttonRedef1B);
  gtk_table_attach (GTK_TABLE (table7), buttonRedef1B, 2, 3, 1, 2,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_button_set_relief (GTK_BUTTON (buttonRedef1B), GTK_RELIEF_NONE);

  alignment5 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_set_name (alignment5, "alignment5");
  gtk_widget_show (alignment5);
  gtk_container_add (GTK_CONTAINER (buttonRedef1B), alignment5);

  hbox16 = gtk_hbox_new (FALSE, 2);
  gtk_widget_set_name (hbox16, "hbox16");
  gtk_widget_show (hbox16);
  gtk_container_add (GTK_CONTAINER (alignment5), hbox16);

  image24 = gtk_image_new_from_stock ("gtk-bold", GTK_ICON_SIZE_BUTTON);
  gtk_widget_set_name (image24, "image24");
  gtk_widget_show (image24);
  gtk_box_pack_start (GTK_BOX (hbox16), image24, FALSE, FALSE, 0);

  label26 = gtk_label_new_with_mnemonic ("Redefine Keys");
  gtk_widget_set_name (label26, "label26");
  gtk_widget_show (label26);
  gtk_box_pack_start (GTK_BOX (hbox16), label26, FALSE, FALSE, 0);

  buttonRedef1C = gtk_button_new ();
  gtk_widget_set_name (buttonRedef1C, "buttonRedef1C");
  gtk_widget_show (buttonRedef1C);
  gtk_table_attach (GTK_TABLE (table7), buttonRedef1C, 2, 3, 2, 3,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_button_set_relief (GTK_BUTTON (buttonRedef1C), GTK_RELIEF_NONE);

  alignment6 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_set_name (alignment6, "alignment6");
  gtk_widget_show (alignment6);
  gtk_container_add (GTK_CONTAINER (buttonRedef1C), alignment6);

  hbox17 = gtk_hbox_new (FALSE, 2);
  gtk_widget_set_name (hbox17, "hbox17");
  gtk_widget_show (hbox17);
  gtk_container_add (GTK_CONTAINER (alignment6), hbox17);

  image25 = gtk_image_new_from_stock ("gtk-bold", GTK_ICON_SIZE_BUTTON);
  gtk_widget_set_name (image25, "image25");
  gtk_widget_show (image25);
  gtk_box_pack_start (GTK_BOX (hbox17), image25, FALSE, FALSE, 0);

  label27 = gtk_label_new_with_mnemonic ("Redefine Keys");
  gtk_widget_set_name (label27, "label27");
  gtk_widget_show (label27);
  gtk_box_pack_start (GTK_BOX (hbox17), label27, FALSE, FALSE, 0);

  buttonRedef1D = gtk_button_new ();
  gtk_widget_set_name (buttonRedef1D, "buttonRedef1D");
  gtk_widget_show (buttonRedef1D);
  gtk_table_attach (GTK_TABLE (table7), buttonRedef1D, 2, 3, 3, 4,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_button_set_relief (GTK_BUTTON (buttonRedef1D), GTK_RELIEF_NONE);

  alignment7 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_set_name (alignment7, "alignment7");
  gtk_widget_show (alignment7);
  gtk_container_add (GTK_CONTAINER (buttonRedef1D), alignment7);

  hbox18 = gtk_hbox_new (FALSE, 2);
  gtk_widget_set_name (hbox18, "hbox18");
  gtk_widget_show (hbox18);
  gtk_container_add (GTK_CONTAINER (alignment7), hbox18);

  image26 = gtk_image_new_from_stock ("gtk-bold", GTK_ICON_SIZE_BUTTON);
  gtk_widget_set_name (image26, "image26");
  gtk_widget_show (image26);
  gtk_box_pack_start (GTK_BOX (hbox18), image26, FALSE, FALSE, 0);

  label28 = gtk_label_new_with_mnemonic ("Redefine Keys");
  gtk_widget_set_name (label28, "label28");
  gtk_widget_show (label28);
  gtk_box_pack_start (GTK_BOX (hbox18), label28, FALSE, FALSE, 0);

  padp1 = gtk_option_menu_new ();
  gtk_widget_set_name (padp1, "padp1");
  gtk_widget_show (padp1);
  gtk_table_attach (GTK_TABLE (table7), padp1, 1, 2, 0, 1,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);

  menu1 = gtk_menu_new ();
  gtk_widget_set_name (menu1, "menu1");

  item11 = gtk_menu_item_new_with_mnemonic ("3 buttons");
  gtk_widget_set_name (item11, "item11");
  gtk_widget_show (item11);
  gtk_container_add (GTK_CONTAINER (menu1), item11);

  item12 = gtk_menu_item_new_with_mnemonic ("6 buttons");
  gtk_widget_set_name (item12, "item12");
  gtk_widget_show (item12);
  gtk_container_add (GTK_CONTAINER (menu1), item12);

  gtk_option_menu_set_menu (GTK_OPTION_MENU (padp1), menu1);

  padp1b = gtk_option_menu_new ();
  gtk_widget_set_name (padp1b, "padp1b");
  gtk_widget_show (padp1b);
  gtk_table_attach (GTK_TABLE (table7), padp1b, 1, 2, 1, 2,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);

  menu2 = gtk_menu_new ();
  gtk_widget_set_name (menu2, "menu2");

  menuitem7 = gtk_menu_item_new_with_mnemonic ("3 buttons");
  gtk_widget_set_name (menuitem7, "menuitem7");
  gtk_widget_show (menuitem7);
  gtk_container_add (GTK_CONTAINER (menu2), menuitem7);

  menuitem8 = gtk_menu_item_new_with_mnemonic ("6 buttons");
  gtk_widget_set_name (menuitem8, "menuitem8");
  gtk_widget_show (menuitem8);
  gtk_container_add (GTK_CONTAINER (menu2), menuitem8);

  gtk_option_menu_set_menu (GTK_OPTION_MENU (padp1b), menu2);

  padp1c = gtk_option_menu_new ();
  gtk_widget_set_name (padp1c, "padp1c");
  gtk_widget_show (padp1c);
  gtk_table_attach (GTK_TABLE (table7), padp1c, 1, 2, 2, 3,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);

  menu3 = gtk_menu_new ();
  gtk_widget_set_name (menu3, "menu3");

  menuitem9 = gtk_menu_item_new_with_mnemonic ("3 buttons");
  gtk_widget_set_name (menuitem9, "menuitem9");
  gtk_widget_show (menuitem9);
  gtk_container_add (GTK_CONTAINER (menu3), menuitem9);

  menuitem10 = gtk_menu_item_new_with_mnemonic ("6 buttons");
  gtk_widget_set_name (menuitem10, "menuitem10");
  gtk_widget_show (menuitem10);
  gtk_container_add (GTK_CONTAINER (menu3), menuitem10);

  gtk_option_menu_set_menu (GTK_OPTION_MENU (padp1c), menu3);

  padp1d = gtk_option_menu_new ();
  gtk_widget_set_name (padp1d, "padp1d");
  gtk_widget_show (padp1d);
  gtk_table_attach (GTK_TABLE (table7), padp1d, 1, 2, 3, 4,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);

  menu4 = gtk_menu_new ();
  gtk_widget_set_name (menu4, "menu4");

  menuitem11 = gtk_menu_item_new_with_mnemonic ("3 buttons");
  gtk_widget_set_name (menuitem11, "menuitem11");
  gtk_widget_show (menuitem11);
  gtk_container_add (GTK_CONTAINER (menu4), menuitem11);

  menuitem12 = gtk_menu_item_new_with_mnemonic ("6 buttons");
  gtk_widget_set_name (menuitem12, "menuitem12");
  gtk_widget_show (menuitem12);
  gtk_container_add (GTK_CONTAINER (menu4), menuitem12);

  gtk_option_menu_set_menu (GTK_OPTION_MENU (padp1d), menu4);

  label17 = gtk_label_new ("<i><b>Port 1</b></i>");
  gtk_widget_set_name (label17, "label17");
  gtk_widget_show (label17);
  gtk_frame_set_label_widget (GTK_FRAME (frame7), label17);
  gtk_label_set_use_markup (GTK_LABEL (label17), TRUE);

  frame8 = gtk_frame_new (NULL);
  gtk_widget_set_name (frame8, "frame8");
  gtk_widget_show (frame8);
  gtk_table_attach (GTK_TABLE (table6), frame8, 1, 2, 0, 1,
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL),
                    (GtkAttachOptions) (GTK_FILL), 0, 0);
  gtk_container_set_border_width (GTK_CONTAINER (frame8), 5);
  gtk_frame_set_shadow_type (GTK_FRAME (frame8), GTK_SHADOW_NONE);

  label19 = gtk_label_new ("Player 1-B 1-C and 1-D are enabled only if a teamplayer\nis connected to port 1.\n\nPlayer 2-B 2-C and 2-D are enabled only if a teamplayer\nis connected to port 2.\n\nOnly a few games support teamplayer (games which\nhave 4 players support), so don't forget to use the\n\"load config\" and \"save config\" possibility :)");
  gtk_widget_set_name (label19, "label19");
  gtk_widget_show (label19);
  gtk_container_add (GTK_CONTAINER (frame8), label19);

  label18 = gtk_label_new ("<i><b>Note</b></i>");
  gtk_widget_set_name (label18, "label18");
  gtk_widget_show (label18);
  gtk_frame_set_label_widget (GTK_FRAME (frame8), label18);
  gtk_label_set_use_markup (GTK_LABEL (label18), TRUE);

  frame9 = gtk_frame_new (NULL);
  gtk_widget_set_name (frame9, "frame9");
  gtk_widget_show (frame9);
  gtk_table_attach (GTK_TABLE (table6), frame9, 0, 1, 1, 2,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL), 0, 0);
  gtk_container_set_border_width (GTK_CONTAINER (frame9), 5);
  gtk_frame_set_shadow_type (GTK_FRAME (frame9), GTK_SHADOW_NONE);

  vbox11 = gtk_vbox_new (FALSE, 0);
  gtk_widget_set_name (vbox11, "vbox11");
  gtk_widget_show (vbox11);
  gtk_container_add (GTK_CONTAINER (frame9), vbox11);

  hbox19 = gtk_hbox_new (FALSE, 5);
  gtk_widget_set_name (hbox19, "hbox19");
  gtk_widget_show (hbox19);
  gtk_box_pack_start (GTK_BOX (vbox11), hbox19, TRUE, TRUE, 0);

  label29 = gtk_label_new ("Controller connected:");
  gtk_widget_set_name (label29, "label29");
  gtk_widget_show (label29);
  gtk_box_pack_start (GTK_BOX (hbox19), label29, FALSE, FALSE, 0);

  port2 = gtk_option_menu_new ();
  gtk_widget_set_name (port2, "port2");
  gtk_widget_show (port2);
  gtk_box_pack_start (GTK_BOX (hbox19), port2, FALSE, FALSE, 0);

  menu10 = gtk_menu_new ();
  gtk_widget_set_name (menu10, "menu10");

  menuitem21 = gtk_menu_item_new_with_mnemonic ("pad");
  gtk_widget_set_name (menuitem21, "menuitem21");
  gtk_widget_show (menuitem21);
  gtk_container_add (GTK_CONTAINER (menu10), menuitem21);

  menuitem22 = gtk_menu_item_new_with_mnemonic ("teamplayer");
  gtk_widget_set_name (menuitem22, "menuitem22");
  gtk_widget_show (menuitem22);
  gtk_container_add (GTK_CONTAINER (menu10), menuitem22);

  gtk_option_menu_set_menu (GTK_OPTION_MENU (port2), menu10);

  table8 = gtk_table_new (4, 3, FALSE);
  gtk_widget_set_name (table8, "table8");
  gtk_widget_show (table8);
  gtk_box_pack_start (GTK_BOX (vbox11), table8, TRUE, TRUE, 0);
  gtk_table_set_col_spacings (GTK_TABLE (table8), 10);

  label30 = gtk_label_new ("Player 2");
  gtk_widget_set_name (label30, "label30");
  gtk_widget_show (label30);
  gtk_table_attach (GTK_TABLE (table8), label30, 0, 1, 0, 1,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_misc_set_alignment (GTK_MISC (label30), 0, 0.5);

  label31 = gtk_label_new ("Player 2-B");
  gtk_widget_set_name (label31, "label31");
  gtk_widget_show (label31);
  gtk_table_attach (GTK_TABLE (table8), label31, 0, 1, 1, 2,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_misc_set_alignment (GTK_MISC (label31), 0, 0.5);

  label32 = gtk_label_new ("Player 2-C");
  gtk_widget_set_name (label32, "label32");
  gtk_widget_show (label32);
  gtk_table_attach (GTK_TABLE (table8), label32, 0, 1, 2, 3,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_misc_set_alignment (GTK_MISC (label32), 0, 0.5);

  label33 = gtk_label_new ("Player 2-D");
  gtk_widget_set_name (label33, "label33");
  gtk_widget_show (label33);
  gtk_table_attach (GTK_TABLE (table8), label33, 0, 1, 3, 4,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_misc_set_alignment (GTK_MISC (label33), 0, 0.5);

  buttonRedef2 = gtk_button_new ();
  gtk_widget_set_name (buttonRedef2, "buttonRedef2");
  gtk_widget_show (buttonRedef2);
  gtk_table_attach (GTK_TABLE (table8), buttonRedef2, 2, 3, 0, 1,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_button_set_relief (GTK_BUTTON (buttonRedef2), GTK_RELIEF_NONE);

  alignment8 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_set_name (alignment8, "alignment8");
  gtk_widget_show (alignment8);
  gtk_container_add (GTK_CONTAINER (buttonRedef2), alignment8);

  hbox20 = gtk_hbox_new (FALSE, 2);
  gtk_widget_set_name (hbox20, "hbox20");
  gtk_widget_show (hbox20);
  gtk_container_add (GTK_CONTAINER (alignment8), hbox20);

  image27 = gtk_image_new_from_stock ("gtk-bold", GTK_ICON_SIZE_BUTTON);
  gtk_widget_set_name (image27, "image27");
  gtk_widget_show (image27);
  gtk_box_pack_start (GTK_BOX (hbox20), image27, FALSE, FALSE, 0);

  label34 = gtk_label_new_with_mnemonic ("Redefine Keys");
  gtk_widget_set_name (label34, "label34");
  gtk_widget_show (label34);
  gtk_box_pack_start (GTK_BOX (hbox20), label34, FALSE, FALSE, 0);

  buttonRedef2B = gtk_button_new ();
  gtk_widget_set_name (buttonRedef2B, "buttonRedef2B");
  gtk_widget_show (buttonRedef2B);
  gtk_table_attach (GTK_TABLE (table8), buttonRedef2B, 2, 3, 1, 2,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_button_set_relief (GTK_BUTTON (buttonRedef2B), GTK_RELIEF_NONE);

  alignment9 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_set_name (alignment9, "alignment9");
  gtk_widget_show (alignment9);
  gtk_container_add (GTK_CONTAINER (buttonRedef2B), alignment9);

  hbox21 = gtk_hbox_new (FALSE, 2);
  gtk_widget_set_name (hbox21, "hbox21");
  gtk_widget_show (hbox21);
  gtk_container_add (GTK_CONTAINER (alignment9), hbox21);

  image28 = gtk_image_new_from_stock ("gtk-bold", GTK_ICON_SIZE_BUTTON);
  gtk_widget_set_name (image28, "image28");
  gtk_widget_show (image28);
  gtk_box_pack_start (GTK_BOX (hbox21), image28, FALSE, FALSE, 0);

  label35 = gtk_label_new_with_mnemonic ("Redefine Keys");
  gtk_widget_set_name (label35, "label35");
  gtk_widget_show (label35);
  gtk_box_pack_start (GTK_BOX (hbox21), label35, FALSE, FALSE, 0);

  buttonRedef2C = gtk_button_new ();
  gtk_widget_set_name (buttonRedef2C, "buttonRedef2C");
  gtk_widget_show (buttonRedef2C);
  gtk_table_attach (GTK_TABLE (table8), buttonRedef2C, 2, 3, 2, 3,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_button_set_relief (GTK_BUTTON (buttonRedef2C), GTK_RELIEF_NONE);

  alignment10 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_set_name (alignment10, "alignment10");
  gtk_widget_show (alignment10);
  gtk_container_add (GTK_CONTAINER (buttonRedef2C), alignment10);

  hbox22 = gtk_hbox_new (FALSE, 2);
  gtk_widget_set_name (hbox22, "hbox22");
  gtk_widget_show (hbox22);
  gtk_container_add (GTK_CONTAINER (alignment10), hbox22);

  image29 = gtk_image_new_from_stock ("gtk-bold", GTK_ICON_SIZE_BUTTON);
  gtk_widget_set_name (image29, "image29");
  gtk_widget_show (image29);
  gtk_box_pack_start (GTK_BOX (hbox22), image29, FALSE, FALSE, 0);

  label36 = gtk_label_new_with_mnemonic ("Redefine Keys");
  gtk_widget_set_name (label36, "label36");
  gtk_widget_show (label36);
  gtk_box_pack_start (GTK_BOX (hbox22), label36, FALSE, FALSE, 0);

  buttonRedef2D = gtk_button_new ();
  gtk_widget_set_name (buttonRedef2D, "buttonRedef2D");
  gtk_widget_show (buttonRedef2D);
  gtk_table_attach (GTK_TABLE (table8), buttonRedef2D, 2, 3, 3, 4,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_button_set_relief (GTK_BUTTON (buttonRedef2D), GTK_RELIEF_NONE);

  alignment11 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_set_name (alignment11, "alignment11");
  gtk_widget_show (alignment11);
  gtk_container_add (GTK_CONTAINER (buttonRedef2D), alignment11);

  hbox23 = gtk_hbox_new (FALSE, 2);
  gtk_widget_set_name (hbox23, "hbox23");
  gtk_widget_show (hbox23);
  gtk_container_add (GTK_CONTAINER (alignment11), hbox23);

  image30 = gtk_image_new_from_stock ("gtk-bold", GTK_ICON_SIZE_BUTTON);
  gtk_widget_set_name (image30, "image30");
  gtk_widget_show (image30);
  gtk_box_pack_start (GTK_BOX (hbox23), image30, FALSE, FALSE, 0);

  label37 = gtk_label_new_with_mnemonic ("Redefine Keys");
  gtk_widget_set_name (label37, "label37");
  gtk_widget_show (label37);
  gtk_box_pack_start (GTK_BOX (hbox23), label37, FALSE, FALSE, 0);

  padp2 = gtk_option_menu_new ();
  gtk_widget_set_name (padp2, "padp2");
  gtk_widget_show (padp2);
  gtk_table_attach (GTK_TABLE (table8), padp2, 1, 2, 0, 1,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);

  menu5 = gtk_menu_new ();
  gtk_widget_set_name (menu5, "menu5");

  menuitem13 = gtk_menu_item_new_with_mnemonic ("3 buttons");
  gtk_widget_set_name (menuitem13, "menuitem13");
  gtk_widget_show (menuitem13);
  gtk_container_add (GTK_CONTAINER (menu5), menuitem13);

  menuitem14 = gtk_menu_item_new_with_mnemonic ("6 buttons");
  gtk_widget_set_name (menuitem14, "menuitem14");
  gtk_widget_show (menuitem14);
  gtk_container_add (GTK_CONTAINER (menu5), menuitem14);

  gtk_option_menu_set_menu (GTK_OPTION_MENU (padp2), menu5);

  padp2b = gtk_option_menu_new ();
  gtk_widget_set_name (padp2b, "padp2b");
  gtk_widget_show (padp2b);
  gtk_table_attach (GTK_TABLE (table8), padp2b, 1, 2, 1, 2,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);

  menu6 = gtk_menu_new ();
  gtk_widget_set_name (menu6, "menu6");

  menuitem15 = gtk_menu_item_new_with_mnemonic ("3 buttons");
  gtk_widget_set_name (menuitem15, "menuitem15");
  gtk_widget_show (menuitem15);
  gtk_container_add (GTK_CONTAINER (menu6), menuitem15);

  menuitem16 = gtk_menu_item_new_with_mnemonic ("6 buttons");
  gtk_widget_set_name (menuitem16, "menuitem16");
  gtk_widget_show (menuitem16);
  gtk_container_add (GTK_CONTAINER (menu6), menuitem16);

  gtk_option_menu_set_menu (GTK_OPTION_MENU (padp2b), menu6);

  padp2c = gtk_option_menu_new ();
  gtk_widget_set_name (padp2c, "padp2c");
  gtk_widget_show (padp2c);
  gtk_table_attach (GTK_TABLE (table8), padp2c, 1, 2, 2, 3,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);

  menu7 = gtk_menu_new ();
  gtk_widget_set_name (menu7, "menu7");

  menuitem17 = gtk_menu_item_new_with_mnemonic ("3 buttons");
  gtk_widget_set_name (menuitem17, "menuitem17");
  gtk_widget_show (menuitem17);
  gtk_container_add (GTK_CONTAINER (menu7), menuitem17);

  menuitem18 = gtk_menu_item_new_with_mnemonic ("6 buttons");
  gtk_widget_set_name (menuitem18, "menuitem18");
  gtk_widget_show (menuitem18);
  gtk_container_add (GTK_CONTAINER (menu7), menuitem18);

  gtk_option_menu_set_menu (GTK_OPTION_MENU (padp2c), menu7);

  padp2d = gtk_option_menu_new ();
  gtk_widget_set_name (padp2d, "padp2d");
  gtk_widget_show (padp2d);
  gtk_table_attach (GTK_TABLE (table8), padp2d, 1, 2, 3, 4,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);

  menu8 = gtk_menu_new ();
  gtk_widget_set_name (menu8, "menu8");

  menuitem19 = gtk_menu_item_new_with_mnemonic ("3 buttons");
  gtk_widget_set_name (menuitem19, "menuitem19");
  gtk_widget_show (menuitem19);
  gtk_container_add (GTK_CONTAINER (menu8), menuitem19);

  menuitem20 = gtk_menu_item_new_with_mnemonic ("6 buttons");
  gtk_widget_set_name (menuitem20, "menuitem20");
  gtk_widget_show (menuitem20);
  gtk_container_add (GTK_CONTAINER (menu8), menuitem20);

  gtk_option_menu_set_menu (GTK_OPTION_MENU (padp2d), menu8);

  label38 = gtk_label_new ("<i><b>Port 2</b></i>");
  gtk_widget_set_name (label38, "label38");
  gtk_widget_show (label38);
  gtk_frame_set_label_widget (GTK_FRAME (frame9), label38);
  gtk_label_set_use_markup (GTK_LABEL (label38), TRUE);

  vbox12 = gtk_vbox_new (FALSE, 0);
  gtk_widget_set_name (vbox12, "vbox12");
  gtk_widget_show (vbox12);
  gtk_table_attach (GTK_TABLE (table6), vbox12, 1, 2, 1, 2,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (GTK_FILL), 0, 0);

  frame10 = gtk_frame_new (NULL);
  gtk_widget_set_name (frame10, "frame10");
  gtk_widget_show (frame10);
  gtk_box_pack_start (GTK_BOX (vbox12), frame10, TRUE, TRUE, 0);
  gtk_container_set_border_width (GTK_CONTAINER (frame10), 5);
  gtk_frame_set_shadow_type (GTK_FRAME (frame10), GTK_SHADOW_NONE);

  keyEcho = gtk_label_new ("");
  gtk_widget_set_name (keyEcho, "keyEcho");
  gtk_widget_show (keyEcho);
  gtk_container_add (GTK_CONTAINER (frame10), keyEcho);

  settingKeys = gtk_label_new ("<i><b>Setting keys</b></i>");
  gtk_widget_set_name (settingKeys, "settingKeys");
  gtk_widget_show (settingKeys);
  gtk_frame_set_label_widget (GTK_FRAME (frame10), settingKeys);
  gtk_label_set_use_markup (GTK_LABEL (settingKeys), TRUE);

  hbox24 = gtk_hbox_new (FALSE, 0);
  gtk_widget_set_name (hbox24, "hbox24");
  gtk_widget_show (hbox24);
  gtk_box_pack_start (GTK_BOX (vbox12), hbox24, FALSE, TRUE, 0);

  button23 = gtk_button_new_from_stock ("gtk-help");
  gtk_widget_set_name (button23, "button23");
  gtk_widget_show (button23);
  gtk_box_pack_start (GTK_BOX (hbox24), button23, FALSE, FALSE, 0);
  gtk_button_set_relief (GTK_BUTTON (button23), GTK_RELIEF_NONE);

  buttonControlSetOK = gtk_button_new_from_stock ("gtk-ok");
  gtk_widget_set_name (buttonControlSetOK, "buttonControlSetOK");
  gtk_widget_show (buttonControlSetOK);
  gtk_box_pack_start (GTK_BOX (hbox24), buttonControlSetOK, FALSE, FALSE, 0);
  gtk_button_set_relief (GTK_BUTTON (buttonControlSetOK), GTK_RELIEF_NONE);

  g_signal_connect ((gpointer) buttonControlSetOK, "clicked",
                    G_CALLBACK (on_buttonControlSetOK_clicked),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (controllers_settings, controllers_settings, "controllers_settings");
  GLADE_HOOKUP_OBJECT (controllers_settings, table6, "table6");
  GLADE_HOOKUP_OBJECT (controllers_settings, frame7, "frame7");
  GLADE_HOOKUP_OBJECT (controllers_settings, vbox10, "vbox10");
  GLADE_HOOKUP_OBJECT (controllers_settings, hbox14, "hbox14");
  GLADE_HOOKUP_OBJECT (controllers_settings, label20, "label20");
  GLADE_HOOKUP_OBJECT (controllers_settings, port1, "port1");
  GLADE_HOOKUP_OBJECT (controllers_settings, menu9, "menu9");
  GLADE_HOOKUP_OBJECT (controllers_settings, item13, "item13");
  GLADE_HOOKUP_OBJECT (controllers_settings, item14, "item14");
  GLADE_HOOKUP_OBJECT (controllers_settings, table7, "table7");
  GLADE_HOOKUP_OBJECT (controllers_settings, label21, "label21");
  GLADE_HOOKUP_OBJECT (controllers_settings, label22, "label22");
  GLADE_HOOKUP_OBJECT (controllers_settings, label23, "label23");
  GLADE_HOOKUP_OBJECT (controllers_settings, label24, "label24");
  GLADE_HOOKUP_OBJECT (controllers_settings, buttonRedef1, "buttonRedef1");
  GLADE_HOOKUP_OBJECT (controllers_settings, alignment4, "alignment4");
  GLADE_HOOKUP_OBJECT (controllers_settings, hbox15, "hbox15");
  GLADE_HOOKUP_OBJECT (controllers_settings, image23, "image23");
  GLADE_HOOKUP_OBJECT (controllers_settings, label25, "label25");
  GLADE_HOOKUP_OBJECT (controllers_settings, buttonRedef1B, "buttonRedef1B");
  GLADE_HOOKUP_OBJECT (controllers_settings, alignment5, "alignment5");
  GLADE_HOOKUP_OBJECT (controllers_settings, hbox16, "hbox16");
  GLADE_HOOKUP_OBJECT (controllers_settings, image24, "image24");
  GLADE_HOOKUP_OBJECT (controllers_settings, label26, "label26");
  GLADE_HOOKUP_OBJECT (controllers_settings, buttonRedef1C, "buttonRedef1C");
  GLADE_HOOKUP_OBJECT (controllers_settings, alignment6, "alignment6");
  GLADE_HOOKUP_OBJECT (controllers_settings, hbox17, "hbox17");
  GLADE_HOOKUP_OBJECT (controllers_settings, image25, "image25");
  GLADE_HOOKUP_OBJECT (controllers_settings, label27, "label27");
  GLADE_HOOKUP_OBJECT (controllers_settings, buttonRedef1D, "buttonRedef1D");
  GLADE_HOOKUP_OBJECT (controllers_settings, alignment7, "alignment7");
  GLADE_HOOKUP_OBJECT (controllers_settings, hbox18, "hbox18");
  GLADE_HOOKUP_OBJECT (controllers_settings, image26, "image26");
  GLADE_HOOKUP_OBJECT (controllers_settings, label28, "label28");
  GLADE_HOOKUP_OBJECT (controllers_settings, padp1, "padp1");
  GLADE_HOOKUP_OBJECT (controllers_settings, menu1, "menu1");
  GLADE_HOOKUP_OBJECT (controllers_settings, item11, "item11");
  GLADE_HOOKUP_OBJECT (controllers_settings, item12, "item12");
  GLADE_HOOKUP_OBJECT (controllers_settings, padp1b, "padp1b");
  GLADE_HOOKUP_OBJECT (controllers_settings, menu2, "menu2");
  GLADE_HOOKUP_OBJECT (controllers_settings, menuitem7, "menuitem7");
  GLADE_HOOKUP_OBJECT (controllers_settings, menuitem8, "menuitem8");
  GLADE_HOOKUP_OBJECT (controllers_settings, padp1c, "padp1c");
  GLADE_HOOKUP_OBJECT (controllers_settings, menu3, "menu3");
  GLADE_HOOKUP_OBJECT (controllers_settings, menuitem9, "menuitem9");
  GLADE_HOOKUP_OBJECT (controllers_settings, menuitem10, "menuitem10");
  GLADE_HOOKUP_OBJECT (controllers_settings, padp1d, "padp1d");
  GLADE_HOOKUP_OBJECT (controllers_settings, menu4, "menu4");
  GLADE_HOOKUP_OBJECT (controllers_settings, menuitem11, "menuitem11");
  GLADE_HOOKUP_OBJECT (controllers_settings, menuitem12, "menuitem12");
  GLADE_HOOKUP_OBJECT (controllers_settings, label17, "label17");
  GLADE_HOOKUP_OBJECT (controllers_settings, frame8, "frame8");
  GLADE_HOOKUP_OBJECT (controllers_settings, label19, "label19");
  GLADE_HOOKUP_OBJECT (controllers_settings, label18, "label18");
  GLADE_HOOKUP_OBJECT (controllers_settings, frame9, "frame9");
  GLADE_HOOKUP_OBJECT (controllers_settings, vbox11, "vbox11");
  GLADE_HOOKUP_OBJECT (controllers_settings, hbox19, "hbox19");
  GLADE_HOOKUP_OBJECT (controllers_settings, label29, "label29");
  GLADE_HOOKUP_OBJECT (controllers_settings, port2, "port2");
  GLADE_HOOKUP_OBJECT (controllers_settings, menu10, "menu10");
  GLADE_HOOKUP_OBJECT (controllers_settings, menuitem21, "menuitem21");
  GLADE_HOOKUP_OBJECT (controllers_settings, menuitem22, "menuitem22");
  GLADE_HOOKUP_OBJECT (controllers_settings, table8, "table8");
  GLADE_HOOKUP_OBJECT (controllers_settings, label30, "label30");
  GLADE_HOOKUP_OBJECT (controllers_settings, label31, "label31");
  GLADE_HOOKUP_OBJECT (controllers_settings, label32, "label32");
  GLADE_HOOKUP_OBJECT (controllers_settings, label33, "label33");
  GLADE_HOOKUP_OBJECT (controllers_settings, buttonRedef2, "buttonRedef2");
  GLADE_HOOKUP_OBJECT (controllers_settings, alignment8, "alignment8");
  GLADE_HOOKUP_OBJECT (controllers_settings, hbox20, "hbox20");
  GLADE_HOOKUP_OBJECT (controllers_settings, image27, "image27");
  GLADE_HOOKUP_OBJECT (controllers_settings, label34, "label34");
  GLADE_HOOKUP_OBJECT (controllers_settings, buttonRedef2B, "buttonRedef2B");
  GLADE_HOOKUP_OBJECT (controllers_settings, alignment9, "alignment9");
  GLADE_HOOKUP_OBJECT (controllers_settings, hbox21, "hbox21");
  GLADE_HOOKUP_OBJECT (controllers_settings, image28, "image28");
  GLADE_HOOKUP_OBJECT (controllers_settings, label35, "label35");
  GLADE_HOOKUP_OBJECT (controllers_settings, buttonRedef2C, "buttonRedef2C");
  GLADE_HOOKUP_OBJECT (controllers_settings, alignment10, "alignment10");
  GLADE_HOOKUP_OBJECT (controllers_settings, hbox22, "hbox22");
  GLADE_HOOKUP_OBJECT (controllers_settings, image29, "image29");
  GLADE_HOOKUP_OBJECT (controllers_settings, label36, "label36");
  GLADE_HOOKUP_OBJECT (controllers_settings, buttonRedef2D, "buttonRedef2D");
  GLADE_HOOKUP_OBJECT (controllers_settings, alignment11, "alignment11");
  GLADE_HOOKUP_OBJECT (controllers_settings, hbox23, "hbox23");
  GLADE_HOOKUP_OBJECT (controllers_settings, image30, "image30");
  GLADE_HOOKUP_OBJECT (controllers_settings, label37, "label37");
  GLADE_HOOKUP_OBJECT (controllers_settings, padp2, "padp2");
  GLADE_HOOKUP_OBJECT (controllers_settings, menu5, "menu5");
  GLADE_HOOKUP_OBJECT (controllers_settings, menuitem13, "menuitem13");
  GLADE_HOOKUP_OBJECT (controllers_settings, menuitem14, "menuitem14");
  GLADE_HOOKUP_OBJECT (controllers_settings, padp2b, "padp2b");
  GLADE_HOOKUP_OBJECT (controllers_settings, menu6, "menu6");
  GLADE_HOOKUP_OBJECT (controllers_settings, menuitem15, "menuitem15");
  GLADE_HOOKUP_OBJECT (controllers_settings, menuitem16, "menuitem16");
  GLADE_HOOKUP_OBJECT (controllers_settings, padp2c, "padp2c");
  GLADE_HOOKUP_OBJECT (controllers_settings, menu7, "menu7");
  GLADE_HOOKUP_OBJECT (controllers_settings, menuitem17, "menuitem17");
  GLADE_HOOKUP_OBJECT (controllers_settings, menuitem18, "menuitem18");
  GLADE_HOOKUP_OBJECT (controllers_settings, padp2d, "padp2d");
  GLADE_HOOKUP_OBJECT (controllers_settings, menu8, "menu8");
  GLADE_HOOKUP_OBJECT (controllers_settings, menuitem19, "menuitem19");
  GLADE_HOOKUP_OBJECT (controllers_settings, menuitem20, "menuitem20");
  GLADE_HOOKUP_OBJECT (controllers_settings, label38, "label38");
  GLADE_HOOKUP_OBJECT (controllers_settings, vbox12, "vbox12");
  GLADE_HOOKUP_OBJECT (controllers_settings, frame10, "frame10");
  GLADE_HOOKUP_OBJECT (controllers_settings, keyEcho, "keyEcho");
  GLADE_HOOKUP_OBJECT (controllers_settings, settingKeys, "settingKeys");
  GLADE_HOOKUP_OBJECT (controllers_settings, hbox24, "hbox24");
  GLADE_HOOKUP_OBJECT (controllers_settings, button23, "button23");
  GLADE_HOOKUP_OBJECT (controllers_settings, buttonControlSetOK, "buttonControlSetOK");

  return controllers_settings;
}

GtkWidget*
create_directories_configuration (void)
{
  GtkWidget *directories_configuration;
  GdkPixbuf *directories_configuration_icon_pixbuf;
  GtkWidget *vbox13;
  GtkWidget *frame11;
  GtkWidget *table9;
  GtkWidget *label42;
  GtkWidget *label43;
  GtkWidget *label44;
  GtkWidget *label45;
  GtkWidget *label46;
  GtkWidget *label47;
  GtkWidget *label48;
  GtkWidget *label49;
  GtkWidget *statesDir;
  GtkWidget *sramDir;
  GtkWidget *bramDir;
  GtkWidget *wavDir;
  GtkWidget *gymDir;
  GtkWidget *screenshotDir;
  GtkWidget *patDir;
  GtkWidget *ipsDir;
  GtkWidget *buttonStatesDir;
  GtkWidget *alignment23;
  GtkWidget *hbox43;
  GtkWidget *image2818;
  GtkWidget *label83;
  GtkWidget *buttonSramDir;
  GtkWidget *alignment24;
  GtkWidget *hbox44;
  GtkWidget *image2819;
  GtkWidget *label84;
  GtkWidget *buttonBramDir;
  GtkWidget *alignment25;
  GtkWidget *hbox45;
  GtkWidget *image2820;
  GtkWidget *label85;
  GtkWidget *buttonWavDir;
  GtkWidget *alignment26;
  GtkWidget *hbox46;
  GtkWidget *image2821;
  GtkWidget *label86;
  GtkWidget *buttonGymDir;
  GtkWidget *alignment27;
  GtkWidget *hbox47;
  GtkWidget *image2822;
  GtkWidget *label87;
  GtkWidget *buttonScreenshotDir;
  GtkWidget *alignment28;
  GtkWidget *hbox48;
  GtkWidget *image2823;
  GtkWidget *label88;
  GtkWidget *buttonPatDir;
  GtkWidget *alignment29;
  GtkWidget *hbox49;
  GtkWidget *image2824;
  GtkWidget *label89;
  GtkWidget *buttonIpsDir;
  GtkWidget *alignment30;
  GtkWidget *hbox50;
  GtkWidget *image2825;
  GtkWidget *label90;
  GtkWidget *label41;
  GtkWidget *hbox25;
  GtkWidget *button25;
  GtkWidget *button26;
  GtkWidget *buttonDirOK;

  directories_configuration = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_widget_set_name (directories_configuration, "directories_configuration");
  gtk_widget_set_size_request (directories_configuration, 400, -1);
  gtk_container_set_border_width (GTK_CONTAINER (directories_configuration), 5);
  gtk_window_set_title (GTK_WINDOW (directories_configuration), "Directories Configuration");
  gtk_window_set_position (GTK_WINDOW (directories_configuration), GTK_WIN_POS_CENTER);
  directories_configuration_icon_pixbuf = create_pixbuf ("Gens2.ico");
  if (directories_configuration_icon_pixbuf)
    {
      gtk_window_set_icon (GTK_WINDOW (directories_configuration), directories_configuration_icon_pixbuf);
      g_object_unref (directories_configuration_icon_pixbuf);
    }

  vbox13 = gtk_vbox_new (FALSE, 5);
  gtk_widget_set_name (vbox13, "vbox13");
  gtk_widget_show (vbox13);
  gtk_container_add (GTK_CONTAINER (directories_configuration), vbox13);
  gtk_container_set_border_width (GTK_CONTAINER (vbox13), 5);

  frame11 = gtk_frame_new (NULL);
  gtk_widget_set_name (frame11, "frame11");
  gtk_widget_show (frame11);
  gtk_box_pack_start (GTK_BOX (vbox13), frame11, TRUE, TRUE, 0);
  gtk_container_set_border_width (GTK_CONTAINER (frame11), 5);
  gtk_frame_set_shadow_type (GTK_FRAME (frame11), GTK_SHADOW_NONE);

  table9 = gtk_table_new (8, 3, FALSE);
  gtk_widget_set_name (table9, "table9");
  gtk_widget_show (table9);
  gtk_container_add (GTK_CONTAINER (frame11), table9);
  gtk_container_set_border_width (GTK_CONTAINER (table9), 5);
  gtk_table_set_row_spacings (GTK_TABLE (table9), 5);
  gtk_table_set_col_spacings (GTK_TABLE (table9), 5);

  label42 = gtk_label_new ("Save State");
  gtk_widget_set_name (label42, "label42");
  gtk_widget_show (label42);
  gtk_table_attach (GTK_TABLE (table9), label42, 0, 1, 0, 1,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_misc_set_alignment (GTK_MISC (label42), 0, 0.5);

  label43 = gtk_label_new ("Sram backup");
  gtk_widget_set_name (label43, "label43");
  gtk_widget_show (label43);
  gtk_table_attach (GTK_TABLE (table9), label43, 0, 1, 1, 2,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_misc_set_alignment (GTK_MISC (label43), 0, 0.5);

  label44 = gtk_label_new ("Bram backup");
  gtk_widget_set_name (label44, "label44");
  gtk_widget_show (label44);
  gtk_table_attach (GTK_TABLE (table9), label44, 0, 1, 2, 3,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_misc_set_alignment (GTK_MISC (label44), 0, 0.5);

  label45 = gtk_label_new ("Wave dump");
  gtk_widget_set_name (label45, "label45");
  gtk_widget_show (label45);
  gtk_table_attach (GTK_TABLE (table9), label45, 0, 1, 3, 4,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_misc_set_alignment (GTK_MISC (label45), 0, 0.5);

  label46 = gtk_label_new ("Gym dump");
  gtk_widget_set_name (label46, "label46");
  gtk_widget_show (label46);
  gtk_table_attach (GTK_TABLE (table9), label46, 0, 1, 4, 5,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_misc_set_alignment (GTK_MISC (label46), 0, 0.5);

  label47 = gtk_label_new ("Screenshot");
  gtk_widget_set_name (label47, "label47");
  gtk_widget_show (label47);
  gtk_table_attach (GTK_TABLE (table9), label47, 0, 1, 5, 6,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_misc_set_alignment (GTK_MISC (label47), 0, 0.5);

  label48 = gtk_label_new ("Pat patch");
  gtk_widget_set_name (label48, "label48");
  gtk_widget_show (label48);
  gtk_table_attach (GTK_TABLE (table9), label48, 0, 1, 6, 7,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_misc_set_alignment (GTK_MISC (label48), 0, 0.5);

  label49 = gtk_label_new ("Ips patch");
  gtk_widget_set_name (label49, "label49");
  gtk_widget_show (label49);
  gtk_table_attach (GTK_TABLE (table9), label49, 0, 1, 7, 8,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_misc_set_alignment (GTK_MISC (label49), 0, 0.5);

  statesDir = gtk_entry_new ();
  gtk_widget_set_name (statesDir, "statesDir");
  gtk_widget_show (statesDir);
  gtk_table_attach (GTK_TABLE (table9), statesDir, 1, 2, 0, 1,
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_entry_set_has_frame (GTK_ENTRY (statesDir), FALSE);

  sramDir = gtk_entry_new ();
  gtk_widget_set_name (sramDir, "sramDir");
  gtk_widget_show (sramDir);
  gtk_table_attach (GTK_TABLE (table9), sramDir, 1, 2, 1, 2,
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_entry_set_has_frame (GTK_ENTRY (sramDir), FALSE);

  bramDir = gtk_entry_new ();
  gtk_widget_set_name (bramDir, "bramDir");
  gtk_widget_show (bramDir);
  gtk_table_attach (GTK_TABLE (table9), bramDir, 1, 2, 2, 3,
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_entry_set_has_frame (GTK_ENTRY (bramDir), FALSE);

  wavDir = gtk_entry_new ();
  gtk_widget_set_name (wavDir, "wavDir");
  gtk_widget_show (wavDir);
  gtk_table_attach (GTK_TABLE (table9), wavDir, 1, 2, 3, 4,
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_entry_set_has_frame (GTK_ENTRY (wavDir), FALSE);

  gymDir = gtk_entry_new ();
  gtk_widget_set_name (gymDir, "gymDir");
  gtk_widget_show (gymDir);
  gtk_table_attach (GTK_TABLE (table9), gymDir, 1, 2, 4, 5,
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_entry_set_has_frame (GTK_ENTRY (gymDir), FALSE);

  screenshotDir = gtk_entry_new ();
  gtk_widget_set_name (screenshotDir, "screenshotDir");
  gtk_widget_show (screenshotDir);
  gtk_table_attach (GTK_TABLE (table9), screenshotDir, 1, 2, 5, 6,
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_entry_set_has_frame (GTK_ENTRY (screenshotDir), FALSE);

  patDir = gtk_entry_new ();
  gtk_widget_set_name (patDir, "patDir");
  gtk_widget_show (patDir);
  gtk_table_attach (GTK_TABLE (table9), patDir, 1, 2, 6, 7,
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_entry_set_has_frame (GTK_ENTRY (patDir), FALSE);

  ipsDir = gtk_entry_new ();
  gtk_widget_set_name (ipsDir, "ipsDir");
  gtk_widget_show (ipsDir);
  gtk_table_attach (GTK_TABLE (table9), ipsDir, 1, 2, 7, 8,
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_entry_set_has_frame (GTK_ENTRY (ipsDir), FALSE);

  buttonStatesDir = gtk_button_new ();
  gtk_widget_set_name (buttonStatesDir, "buttonStatesDir");
  gtk_widget_show (buttonStatesDir);
  gtk_table_attach (GTK_TABLE (table9), buttonStatesDir, 2, 3, 0, 1,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_button_set_relief (GTK_BUTTON (buttonStatesDir), GTK_RELIEF_NONE);

  alignment23 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_set_name (alignment23, "alignment23");
  gtk_widget_show (alignment23);
  gtk_container_add (GTK_CONTAINER (buttonStatesDir), alignment23);

  hbox43 = gtk_hbox_new (FALSE, 2);
  gtk_widget_set_name (hbox43, "hbox43");
  gtk_widget_show (hbox43);
  gtk_container_add (GTK_CONTAINER (alignment23), hbox43);

  image2818 = create_pixmap (directories_configuration, "binary.png");
  gtk_widget_set_name (image2818, "image2818");
  gtk_widget_show (image2818);
  gtk_box_pack_start (GTK_BOX (hbox43), image2818, FALSE, FALSE, 0);

  label83 = gtk_label_new_with_mnemonic ("Change");
  gtk_widget_set_name (label83, "label83");
  gtk_widget_show (label83);
  gtk_box_pack_start (GTK_BOX (hbox43), label83, FALSE, FALSE, 0);

  buttonSramDir = gtk_button_new ();
  gtk_widget_set_name (buttonSramDir, "buttonSramDir");
  gtk_widget_show (buttonSramDir);
  gtk_table_attach (GTK_TABLE (table9), buttonSramDir, 2, 3, 1, 2,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_button_set_relief (GTK_BUTTON (buttonSramDir), GTK_RELIEF_NONE);

  alignment24 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_set_name (alignment24, "alignment24");
  gtk_widget_show (alignment24);
  gtk_container_add (GTK_CONTAINER (buttonSramDir), alignment24);

  hbox44 = gtk_hbox_new (FALSE, 2);
  gtk_widget_set_name (hbox44, "hbox44");
  gtk_widget_show (hbox44);
  gtk_container_add (GTK_CONTAINER (alignment24), hbox44);

  image2819 = create_pixmap (directories_configuration, "binary.png");
  gtk_widget_set_name (image2819, "image2819");
  gtk_widget_show (image2819);
  gtk_box_pack_start (GTK_BOX (hbox44), image2819, FALSE, FALSE, 0);

  label84 = gtk_label_new_with_mnemonic ("Change");
  gtk_widget_set_name (label84, "label84");
  gtk_widget_show (label84);
  gtk_box_pack_start (GTK_BOX (hbox44), label84, FALSE, FALSE, 0);

  buttonBramDir = gtk_button_new ();
  gtk_widget_set_name (buttonBramDir, "buttonBramDir");
  gtk_widget_show (buttonBramDir);
  gtk_table_attach (GTK_TABLE (table9), buttonBramDir, 2, 3, 2, 3,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_button_set_relief (GTK_BUTTON (buttonBramDir), GTK_RELIEF_NONE);

  alignment25 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_set_name (alignment25, "alignment25");
  gtk_widget_show (alignment25);
  gtk_container_add (GTK_CONTAINER (buttonBramDir), alignment25);

  hbox45 = gtk_hbox_new (FALSE, 2);
  gtk_widget_set_name (hbox45, "hbox45");
  gtk_widget_show (hbox45);
  gtk_container_add (GTK_CONTAINER (alignment25), hbox45);

  image2820 = create_pixmap (directories_configuration, "binary.png");
  gtk_widget_set_name (image2820, "image2820");
  gtk_widget_show (image2820);
  gtk_box_pack_start (GTK_BOX (hbox45), image2820, FALSE, FALSE, 0);

  label85 = gtk_label_new_with_mnemonic ("Change");
  gtk_widget_set_name (label85, "label85");
  gtk_widget_show (label85);
  gtk_box_pack_start (GTK_BOX (hbox45), label85, FALSE, FALSE, 0);

  buttonWavDir = gtk_button_new ();
  gtk_widget_set_name (buttonWavDir, "buttonWavDir");
  gtk_widget_show (buttonWavDir);
  gtk_table_attach (GTK_TABLE (table9), buttonWavDir, 2, 3, 3, 4,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_button_set_relief (GTK_BUTTON (buttonWavDir), GTK_RELIEF_NONE);

  alignment26 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_set_name (alignment26, "alignment26");
  gtk_widget_show (alignment26);
  gtk_container_add (GTK_CONTAINER (buttonWavDir), alignment26);

  hbox46 = gtk_hbox_new (FALSE, 2);
  gtk_widget_set_name (hbox46, "hbox46");
  gtk_widget_show (hbox46);
  gtk_container_add (GTK_CONTAINER (alignment26), hbox46);

  image2821 = create_pixmap (directories_configuration, "binary.png");
  gtk_widget_set_name (image2821, "image2821");
  gtk_widget_show (image2821);
  gtk_box_pack_start (GTK_BOX (hbox46), image2821, FALSE, FALSE, 0);

  label86 = gtk_label_new_with_mnemonic ("Change");
  gtk_widget_set_name (label86, "label86");
  gtk_widget_show (label86);
  gtk_box_pack_start (GTK_BOX (hbox46), label86, FALSE, FALSE, 0);

  buttonGymDir = gtk_button_new ();
  gtk_widget_set_name (buttonGymDir, "buttonGymDir");
  gtk_widget_show (buttonGymDir);
  gtk_table_attach (GTK_TABLE (table9), buttonGymDir, 2, 3, 4, 5,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_button_set_relief (GTK_BUTTON (buttonGymDir), GTK_RELIEF_NONE);

  alignment27 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_set_name (alignment27, "alignment27");
  gtk_widget_show (alignment27);
  gtk_container_add (GTK_CONTAINER (buttonGymDir), alignment27);

  hbox47 = gtk_hbox_new (FALSE, 2);
  gtk_widget_set_name (hbox47, "hbox47");
  gtk_widget_show (hbox47);
  gtk_container_add (GTK_CONTAINER (alignment27), hbox47);

  image2822 = create_pixmap (directories_configuration, "binary.png");
  gtk_widget_set_name (image2822, "image2822");
  gtk_widget_show (image2822);
  gtk_box_pack_start (GTK_BOX (hbox47), image2822, FALSE, FALSE, 0);

  label87 = gtk_label_new_with_mnemonic ("Change");
  gtk_widget_set_name (label87, "label87");
  gtk_widget_show (label87);
  gtk_box_pack_start (GTK_BOX (hbox47), label87, FALSE, FALSE, 0);

  buttonScreenshotDir = gtk_button_new ();
  gtk_widget_set_name (buttonScreenshotDir, "buttonScreenshotDir");
  gtk_widget_show (buttonScreenshotDir);
  gtk_table_attach (GTK_TABLE (table9), buttonScreenshotDir, 2, 3, 5, 6,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_button_set_relief (GTK_BUTTON (buttonScreenshotDir), GTK_RELIEF_NONE);

  alignment28 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_set_name (alignment28, "alignment28");
  gtk_widget_show (alignment28);
  gtk_container_add (GTK_CONTAINER (buttonScreenshotDir), alignment28);

  hbox48 = gtk_hbox_new (FALSE, 2);
  gtk_widget_set_name (hbox48, "hbox48");
  gtk_widget_show (hbox48);
  gtk_container_add (GTK_CONTAINER (alignment28), hbox48);

  image2823 = create_pixmap (directories_configuration, "binary.png");
  gtk_widget_set_name (image2823, "image2823");
  gtk_widget_show (image2823);
  gtk_box_pack_start (GTK_BOX (hbox48), image2823, FALSE, FALSE, 0);

  label88 = gtk_label_new_with_mnemonic ("Change");
  gtk_widget_set_name (label88, "label88");
  gtk_widget_show (label88);
  gtk_box_pack_start (GTK_BOX (hbox48), label88, FALSE, FALSE, 0);

  buttonPatDir = gtk_button_new ();
  gtk_widget_set_name (buttonPatDir, "buttonPatDir");
  gtk_widget_show (buttonPatDir);
  gtk_table_attach (GTK_TABLE (table9), buttonPatDir, 2, 3, 6, 7,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_button_set_relief (GTK_BUTTON (buttonPatDir), GTK_RELIEF_NONE);

  alignment29 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_set_name (alignment29, "alignment29");
  gtk_widget_show (alignment29);
  gtk_container_add (GTK_CONTAINER (buttonPatDir), alignment29);

  hbox49 = gtk_hbox_new (FALSE, 2);
  gtk_widget_set_name (hbox49, "hbox49");
  gtk_widget_show (hbox49);
  gtk_container_add (GTK_CONTAINER (alignment29), hbox49);

  image2824 = create_pixmap (directories_configuration, "binary.png");
  gtk_widget_set_name (image2824, "image2824");
  gtk_widget_show (image2824);
  gtk_box_pack_start (GTK_BOX (hbox49), image2824, FALSE, FALSE, 0);

  label89 = gtk_label_new_with_mnemonic ("Change");
  gtk_widget_set_name (label89, "label89");
  gtk_widget_show (label89);
  gtk_box_pack_start (GTK_BOX (hbox49), label89, FALSE, FALSE, 0);

  buttonIpsDir = gtk_button_new ();
  gtk_widget_set_name (buttonIpsDir, "buttonIpsDir");
  gtk_widget_show (buttonIpsDir);
  gtk_table_attach (GTK_TABLE (table9), buttonIpsDir, 2, 3, 7, 8,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_button_set_relief (GTK_BUTTON (buttonIpsDir), GTK_RELIEF_NONE);

  alignment30 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_set_name (alignment30, "alignment30");
  gtk_widget_show (alignment30);
  gtk_container_add (GTK_CONTAINER (buttonIpsDir), alignment30);

  hbox50 = gtk_hbox_new (FALSE, 2);
  gtk_widget_set_name (hbox50, "hbox50");
  gtk_widget_show (hbox50);
  gtk_container_add (GTK_CONTAINER (alignment30), hbox50);

  image2825 = create_pixmap (directories_configuration, "binary.png");
  gtk_widget_set_name (image2825, "image2825");
  gtk_widget_show (image2825);
  gtk_box_pack_start (GTK_BOX (hbox50), image2825, FALSE, FALSE, 0);

  label90 = gtk_label_new_with_mnemonic ("Change");
  gtk_widget_set_name (label90, "label90");
  gtk_widget_show (label90);
  gtk_box_pack_start (GTK_BOX (hbox50), label90, FALSE, FALSE, 0);

  label41 = gtk_label_new ("<i><b>Configure directories</b></i>");
  gtk_widget_set_name (label41, "label41");
  gtk_widget_show (label41);
  gtk_frame_set_label_widget (GTK_FRAME (frame11), label41);
  gtk_label_set_use_markup (GTK_LABEL (label41), TRUE);

  hbox25 = gtk_hbox_new (TRUE, 0);
  gtk_widget_set_name (hbox25, "hbox25");
  gtk_widget_show (hbox25);
  gtk_box_pack_start (GTK_BOX (vbox13), hbox25, FALSE, TRUE, 0);

  button25 = gtk_button_new_from_stock ("gtk-help");
  gtk_widget_set_name (button25, "button25");
  gtk_widget_show (button25);
  gtk_box_pack_start (GTK_BOX (hbox25), button25, FALSE, FALSE, 0);
  gtk_button_set_relief (GTK_BUTTON (button25), GTK_RELIEF_NONE);

  button26 = gtk_button_new_from_stock ("gtk-cancel");
  gtk_widget_set_name (button26, "button26");
  gtk_widget_show (button26);
  gtk_box_pack_start (GTK_BOX (hbox25), button26, FALSE, FALSE, 0);
  gtk_button_set_relief (GTK_BUTTON (button26), GTK_RELIEF_NONE);

  buttonDirOK = gtk_button_new_from_stock ("gtk-ok");
  gtk_widget_set_name (buttonDirOK, "buttonDirOK");
  gtk_widget_show (buttonDirOK);
  gtk_box_pack_start (GTK_BOX (hbox25), buttonDirOK, FALSE, FALSE, 0);
  gtk_button_set_relief (GTK_BUTTON (buttonDirOK), GTK_RELIEF_NONE);

  g_signal_connect_swapped ((gpointer) button26, "clicked",
                            G_CALLBACK (gtk_widget_destroy),
                            GTK_OBJECT (directories_configuration));
  g_signal_connect ((gpointer) buttonDirOK, "clicked",
                    G_CALLBACK (on_buttonDirOK_clicked),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (directories_configuration, directories_configuration, "directories_configuration");
  GLADE_HOOKUP_OBJECT (directories_configuration, vbox13, "vbox13");
  GLADE_HOOKUP_OBJECT (directories_configuration, frame11, "frame11");
  GLADE_HOOKUP_OBJECT (directories_configuration, table9, "table9");
  GLADE_HOOKUP_OBJECT (directories_configuration, label42, "label42");
  GLADE_HOOKUP_OBJECT (directories_configuration, label43, "label43");
  GLADE_HOOKUP_OBJECT (directories_configuration, label44, "label44");
  GLADE_HOOKUP_OBJECT (directories_configuration, label45, "label45");
  GLADE_HOOKUP_OBJECT (directories_configuration, label46, "label46");
  GLADE_HOOKUP_OBJECT (directories_configuration, label47, "label47");
  GLADE_HOOKUP_OBJECT (directories_configuration, label48, "label48");
  GLADE_HOOKUP_OBJECT (directories_configuration, label49, "label49");
  GLADE_HOOKUP_OBJECT (directories_configuration, statesDir, "statesDir");
  GLADE_HOOKUP_OBJECT (directories_configuration, sramDir, "sramDir");
  GLADE_HOOKUP_OBJECT (directories_configuration, bramDir, "bramDir");
  GLADE_HOOKUP_OBJECT (directories_configuration, wavDir, "wavDir");
  GLADE_HOOKUP_OBJECT (directories_configuration, gymDir, "gymDir");
  GLADE_HOOKUP_OBJECT (directories_configuration, screenshotDir, "screenshotDir");
  GLADE_HOOKUP_OBJECT (directories_configuration, patDir, "patDir");
  GLADE_HOOKUP_OBJECT (directories_configuration, ipsDir, "ipsDir");
  GLADE_HOOKUP_OBJECT (directories_configuration, buttonStatesDir, "buttonStatesDir");
  GLADE_HOOKUP_OBJECT (directories_configuration, alignment23, "alignment23");
  GLADE_HOOKUP_OBJECT (directories_configuration, hbox43, "hbox43");
  GLADE_HOOKUP_OBJECT (directories_configuration, image2818, "image2818");
  GLADE_HOOKUP_OBJECT (directories_configuration, label83, "label83");
  GLADE_HOOKUP_OBJECT (directories_configuration, buttonSramDir, "buttonSramDir");
  GLADE_HOOKUP_OBJECT (directories_configuration, alignment24, "alignment24");
  GLADE_HOOKUP_OBJECT (directories_configuration, hbox44, "hbox44");
  GLADE_HOOKUP_OBJECT (directories_configuration, image2819, "image2819");
  GLADE_HOOKUP_OBJECT (directories_configuration, label84, "label84");
  GLADE_HOOKUP_OBJECT (directories_configuration, buttonBramDir, "buttonBramDir");
  GLADE_HOOKUP_OBJECT (directories_configuration, alignment25, "alignment25");
  GLADE_HOOKUP_OBJECT (directories_configuration, hbox45, "hbox45");
  GLADE_HOOKUP_OBJECT (directories_configuration, image2820, "image2820");
  GLADE_HOOKUP_OBJECT (directories_configuration, label85, "label85");
  GLADE_HOOKUP_OBJECT (directories_configuration, buttonWavDir, "buttonWavDir");
  GLADE_HOOKUP_OBJECT (directories_configuration, alignment26, "alignment26");
  GLADE_HOOKUP_OBJECT (directories_configuration, hbox46, "hbox46");
  GLADE_HOOKUP_OBJECT (directories_configuration, image2821, "image2821");
  GLADE_HOOKUP_OBJECT (directories_configuration, label86, "label86");
  GLADE_HOOKUP_OBJECT (directories_configuration, buttonGymDir, "buttonGymDir");
  GLADE_HOOKUP_OBJECT (directories_configuration, alignment27, "alignment27");
  GLADE_HOOKUP_OBJECT (directories_configuration, hbox47, "hbox47");
  GLADE_HOOKUP_OBJECT (directories_configuration, image2822, "image2822");
  GLADE_HOOKUP_OBJECT (directories_configuration, label87, "label87");
  GLADE_HOOKUP_OBJECT (directories_configuration, buttonScreenshotDir, "buttonScreenshotDir");
  GLADE_HOOKUP_OBJECT (directories_configuration, alignment28, "alignment28");
  GLADE_HOOKUP_OBJECT (directories_configuration, hbox48, "hbox48");
  GLADE_HOOKUP_OBJECT (directories_configuration, image2823, "image2823");
  GLADE_HOOKUP_OBJECT (directories_configuration, label88, "label88");
  GLADE_HOOKUP_OBJECT (directories_configuration, buttonPatDir, "buttonPatDir");
  GLADE_HOOKUP_OBJECT (directories_configuration, alignment29, "alignment29");
  GLADE_HOOKUP_OBJECT (directories_configuration, hbox49, "hbox49");
  GLADE_HOOKUP_OBJECT (directories_configuration, image2824, "image2824");
  GLADE_HOOKUP_OBJECT (directories_configuration, label89, "label89");
  GLADE_HOOKUP_OBJECT (directories_configuration, buttonIpsDir, "buttonIpsDir");
  GLADE_HOOKUP_OBJECT (directories_configuration, alignment30, "alignment30");
  GLADE_HOOKUP_OBJECT (directories_configuration, hbox50, "hbox50");
  GLADE_HOOKUP_OBJECT (directories_configuration, image2825, "image2825");
  GLADE_HOOKUP_OBJECT (directories_configuration, label90, "label90");
  GLADE_HOOKUP_OBJECT (directories_configuration, label41, "label41");
  GLADE_HOOKUP_OBJECT (directories_configuration, hbox25, "hbox25");
  GLADE_HOOKUP_OBJECT (directories_configuration, button25, "button25");
  GLADE_HOOKUP_OBJECT (directories_configuration, button26, "button26");
  GLADE_HOOKUP_OBJECT (directories_configuration, buttonDirOK, "buttonDirOK");

  return directories_configuration;
}

GtkWidget*
create_bios_files (void)
{
  GtkWidget *bios_files;
  GdkPixbuf *bios_files_icon_pixbuf;
  GtkWidget *vbox14;
  GtkWidget *frame12;
  GtkWidget *hbox27;
  GtkWidget *label59;
  GtkWidget *hbox30;
  GtkWidget *genesisBios;
  GtkWidget *buttonGenesisBios;
  GtkWidget *alignment14;
  GtkWidget *hbox34;
  GtkWidget *image2809;
  GtkWidget *label74;
  GtkWidget *label58;
  GtkWidget *frame13;
  GtkWidget *table10;
  GtkWidget *label62;
  GtkWidget *label63;
  GtkWidget *buttonM68000;
  GtkWidget *alignment15;
  GtkWidget *hbox35;
  GtkWidget *image2810;
  GtkWidget *label94;
  GtkWidget *buttonMSH2;
  GtkWidget *alignment16;
  GtkWidget *hbox36;
  GtkWidget *image2811;
  GtkWidget *label76;
  GtkWidget *buttonSSH2;
  GtkWidget *alignment17;
  GtkWidget *hbox37;
  GtkWidget *image2812;
  GtkWidget *label77;
  GtkWidget *M68000;
  GtkWidget *MSH2;
  GtkWidget *SSH2;
  GtkWidget *label61;
  GtkWidget *label60;
  GtkWidget *frame14;
  GtkWidget *table11;
  GtkWidget *label64;
  GtkWidget *label65;
  GtkWidget *label66;
  GtkWidget *buttonUSABios;
  GtkWidget *alignment18;
  GtkWidget *hbox38;
  GtkWidget *image2813;
  GtkWidget *label78;
  GtkWidget *buttonEURBios;
  GtkWidget *alignment19;
  GtkWidget *hbox39;
  GtkWidget *image2814;
  GtkWidget *label79;
  GtkWidget *buttonJAPBios;
  GtkWidget *alignment20;
  GtkWidget *hbox40;
  GtkWidget *image2815;
  GtkWidget *label80;
  GtkWidget *USAbios;
  GtkWidget *EURbios;
  GtkWidget *JAPbios;
  GtkWidget *label67;
  GtkWidget *frame15;
  GtkWidget *table12;
  GtkWidget *label68;
  GtkWidget *label69;
  GtkWidget *buttonCGOffline;
  GtkWidget *alignment21;
  GtkWidget *hbox41;
  GtkWidget *image2816;
  GtkWidget *label81;
  GtkWidget *buttonManual;
  GtkWidget *alignment22;
  GtkWidget *hbox42;
  GtkWidget *image2817;
  GtkWidget *label82;
  GtkWidget *CGOffline;
  GtkWidget *manual;
  GtkWidget *label71;
  GtkWidget *hbox26;
  GtkWidget *button46;
  GtkWidget *button47;
  GtkWidget *buttonCfgBios;

  bios_files = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_widget_set_name (bios_files, "bios_files");
  gtk_widget_set_size_request (bios_files, 400, -1);
  gtk_container_set_border_width (GTK_CONTAINER (bios_files), 5);
  gtk_window_set_title (GTK_WINDOW (bios_files), "Configure bios files");
  gtk_window_set_position (GTK_WINDOW (bios_files), GTK_WIN_POS_CENTER);
  bios_files_icon_pixbuf = create_pixbuf ("Gens2.ico");
  if (bios_files_icon_pixbuf)
    {
      gtk_window_set_icon (GTK_WINDOW (bios_files), bios_files_icon_pixbuf);
      g_object_unref (bios_files_icon_pixbuf);
    }

  vbox14 = gtk_vbox_new (FALSE, 10);
  gtk_widget_set_name (vbox14, "vbox14");
  gtk_widget_show (vbox14);
  gtk_container_add (GTK_CONTAINER (bios_files), vbox14);
  gtk_container_set_border_width (GTK_CONTAINER (vbox14), 5);

  frame12 = gtk_frame_new (NULL);
  gtk_widget_set_name (frame12, "frame12");
  gtk_widget_show (frame12);
  gtk_box_pack_start (GTK_BOX (vbox14), frame12, TRUE, TRUE, 0);
  gtk_container_set_border_width (GTK_CONTAINER (frame12), 5);
  gtk_frame_set_shadow_type (GTK_FRAME (frame12), GTK_SHADOW_NONE);

  hbox27 = gtk_hbox_new (FALSE, 5);
  gtk_widget_set_name (hbox27, "hbox27");
  gtk_widget_show (hbox27);
  gtk_container_add (GTK_CONTAINER (frame12), hbox27);
  gtk_container_set_border_width (GTK_CONTAINER (hbox27), 5);

  label59 = gtk_label_new ("Genesis");
  gtk_widget_set_name (label59, "label59");
  gtk_widget_show (label59);
  gtk_box_pack_start (GTK_BOX (hbox27), label59, FALSE, TRUE, 0);
  gtk_widget_set_size_request (label59, 75, -1);

  hbox30 = gtk_hbox_new (FALSE, 0);
  gtk_widget_set_name (hbox30, "hbox30");
  gtk_widget_show (hbox30);
  gtk_box_pack_start (GTK_BOX (hbox27), hbox30, TRUE, TRUE, 0);

  genesisBios = gtk_entry_new ();
  gtk_widget_set_name (genesisBios, "genesisBios");
  gtk_widget_show (genesisBios);
  gtk_box_pack_start (GTK_BOX (hbox30), genesisBios, TRUE, TRUE, 0);
  gtk_entry_set_has_frame (GTK_ENTRY (genesisBios), FALSE);

  buttonGenesisBios = gtk_button_new ();
  gtk_widget_set_name (buttonGenesisBios, "buttonGenesisBios");
  gtk_widget_show (buttonGenesisBios);
  gtk_box_pack_start (GTK_BOX (hbox30), buttonGenesisBios, FALSE, FALSE, 0);
  gtk_button_set_relief (GTK_BUTTON (buttonGenesisBios), GTK_RELIEF_NONE);

  alignment14 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_set_name (alignment14, "alignment14");
  gtk_widget_show (alignment14);
  gtk_container_add (GTK_CONTAINER (buttonGenesisBios), alignment14);

  hbox34 = gtk_hbox_new (FALSE, 2);
  gtk_widget_set_name (hbox34, "hbox34");
  gtk_widget_show (hbox34);
  gtk_container_add (GTK_CONTAINER (alignment14), hbox34);

  image2809 = create_pixmap (bios_files, "binary.png");
  gtk_widget_set_name (image2809, "image2809");
  gtk_widget_show (image2809);
  gtk_box_pack_start (GTK_BOX (hbox34), image2809, FALSE, FALSE, 0);

  label74 = gtk_label_new_with_mnemonic ("Change");
  gtk_widget_set_name (label74, "label74");
  gtk_widget_show (label74);
  gtk_box_pack_start (GTK_BOX (hbox34), label74, FALSE, FALSE, 0);

  label58 = gtk_label_new ("<i><b>Configure Genesis bios file</b></i>");
  gtk_widget_set_name (label58, "label58");
  gtk_widget_show (label58);
  gtk_frame_set_label_widget (GTK_FRAME (frame12), label58);
  gtk_label_set_use_markup (GTK_LABEL (label58), TRUE);

  frame13 = gtk_frame_new (NULL);
  gtk_widget_set_name (frame13, "frame13");
  gtk_widget_show (frame13);
  gtk_box_pack_start (GTK_BOX (vbox14), frame13, TRUE, TRUE, 0);
  gtk_container_set_border_width (GTK_CONTAINER (frame13), 5);
  gtk_frame_set_shadow_type (GTK_FRAME (frame13), GTK_SHADOW_NONE);

  table10 = gtk_table_new (3, 3, FALSE);
  gtk_widget_set_name (table10, "table10");
  gtk_widget_show (table10);
  gtk_container_add (GTK_CONTAINER (frame13), table10);
  gtk_container_set_border_width (GTK_CONTAINER (table10), 5);
  gtk_table_set_row_spacings (GTK_TABLE (table10), 5);
  gtk_table_set_col_spacings (GTK_TABLE (table10), 5);

  label62 = gtk_label_new ("Master SH2");
  gtk_widget_set_name (label62, "label62");
  gtk_widget_show (label62);
  gtk_table_attach (GTK_TABLE (table10), label62, 0, 1, 1, 2,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_widget_set_size_request (label62, 75, -1);
  gtk_misc_set_alignment (GTK_MISC (label62), 0, 0.5);

  label63 = gtk_label_new ("Slave SH2");
  gtk_widget_set_name (label63, "label63");
  gtk_widget_show (label63);
  gtk_table_attach (GTK_TABLE (table10), label63, 0, 1, 2, 3,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_misc_set_alignment (GTK_MISC (label63), 0, 0.5);

  buttonM68000 = gtk_button_new ();
  gtk_widget_set_name (buttonM68000, "buttonM68000");
  gtk_widget_show (buttonM68000);
  gtk_table_attach (GTK_TABLE (table10), buttonM68000, 2, 3, 0, 1,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_button_set_relief (GTK_BUTTON (buttonM68000), GTK_RELIEF_NONE);

  alignment15 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_set_name (alignment15, "alignment15");
  gtk_widget_show (alignment15);
  gtk_container_add (GTK_CONTAINER (buttonM68000), alignment15);

  hbox35 = gtk_hbox_new (FALSE, 2);
  gtk_widget_set_name (hbox35, "hbox35");
  gtk_widget_show (hbox35);
  gtk_container_add (GTK_CONTAINER (alignment15), hbox35);

  image2810 = create_pixmap (bios_files, "binary.png");
  gtk_widget_set_name (image2810, "image2810");
  gtk_widget_show (image2810);
  gtk_box_pack_start (GTK_BOX (hbox35), image2810, FALSE, FALSE, 0);

  label94 = gtk_label_new_with_mnemonic ("Change");
  gtk_widget_set_name (label94, "label94");
  gtk_widget_show (label94);
  gtk_box_pack_start (GTK_BOX (hbox35), label94, FALSE, FALSE, 0);

  buttonMSH2 = gtk_button_new ();
  gtk_widget_set_name (buttonMSH2, "buttonMSH2");
  gtk_widget_show (buttonMSH2);
  gtk_table_attach (GTK_TABLE (table10), buttonMSH2, 2, 3, 1, 2,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_button_set_relief (GTK_BUTTON (buttonMSH2), GTK_RELIEF_NONE);

  alignment16 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_set_name (alignment16, "alignment16");
  gtk_widget_show (alignment16);
  gtk_container_add (GTK_CONTAINER (buttonMSH2), alignment16);

  hbox36 = gtk_hbox_new (FALSE, 2);
  gtk_widget_set_name (hbox36, "hbox36");
  gtk_widget_show (hbox36);
  gtk_container_add (GTK_CONTAINER (alignment16), hbox36);

  image2811 = create_pixmap (bios_files, "binary.png");
  gtk_widget_set_name (image2811, "image2811");
  gtk_widget_show (image2811);
  gtk_box_pack_start (GTK_BOX (hbox36), image2811, FALSE, FALSE, 0);

  label76 = gtk_label_new_with_mnemonic ("Change");
  gtk_widget_set_name (label76, "label76");
  gtk_widget_show (label76);
  gtk_box_pack_start (GTK_BOX (hbox36), label76, FALSE, FALSE, 0);

  buttonSSH2 = gtk_button_new ();
  gtk_widget_set_name (buttonSSH2, "buttonSSH2");
  gtk_widget_show (buttonSSH2);
  gtk_table_attach (GTK_TABLE (table10), buttonSSH2, 2, 3, 2, 3,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_button_set_relief (GTK_BUTTON (buttonSSH2), GTK_RELIEF_NONE);

  alignment17 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_set_name (alignment17, "alignment17");
  gtk_widget_show (alignment17);
  gtk_container_add (GTK_CONTAINER (buttonSSH2), alignment17);

  hbox37 = gtk_hbox_new (FALSE, 2);
  gtk_widget_set_name (hbox37, "hbox37");
  gtk_widget_show (hbox37);
  gtk_container_add (GTK_CONTAINER (alignment17), hbox37);

  image2812 = create_pixmap (bios_files, "binary.png");
  gtk_widget_set_name (image2812, "image2812");
  gtk_widget_show (image2812);
  gtk_box_pack_start (GTK_BOX (hbox37), image2812, FALSE, FALSE, 0);

  label77 = gtk_label_new_with_mnemonic ("Change");
  gtk_widget_set_name (label77, "label77");
  gtk_widget_show (label77);
  gtk_box_pack_start (GTK_BOX (hbox37), label77, FALSE, FALSE, 0);

  M68000 = gtk_entry_new ();
  gtk_widget_set_name (M68000, "M68000");
  gtk_widget_show (M68000);
  gtk_table_attach (GTK_TABLE (table10), M68000, 1, 2, 0, 1,
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_entry_set_has_frame (GTK_ENTRY (M68000), FALSE);

  MSH2 = gtk_entry_new ();
  gtk_widget_set_name (MSH2, "MSH2");
  gtk_widget_show (MSH2);
  gtk_table_attach (GTK_TABLE (table10), MSH2, 1, 2, 1, 2,
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_entry_set_has_frame (GTK_ENTRY (MSH2), FALSE);

  SSH2 = gtk_entry_new ();
  gtk_widget_set_name (SSH2, "SSH2");
  gtk_widget_show (SSH2);
  gtk_table_attach (GTK_TABLE (table10), SSH2, 1, 2, 2, 3,
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_entry_set_has_frame (GTK_ENTRY (SSH2), FALSE);

  label61 = gtk_label_new ("M68000");
  gtk_widget_set_name (label61, "label61");
  gtk_widget_show (label61);
  gtk_table_attach (GTK_TABLE (table10), label61, 0, 1, 0, 1,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_misc_set_alignment (GTK_MISC (label61), 0, 0.5);

  label60 = gtk_label_new ("<i><b>Configure 32X bios files</b></i>");
  gtk_widget_set_name (label60, "label60");
  gtk_widget_show (label60);
  gtk_frame_set_label_widget (GTK_FRAME (frame13), label60);
  gtk_label_set_use_markup (GTK_LABEL (label60), TRUE);

  frame14 = gtk_frame_new (NULL);
  gtk_widget_set_name (frame14, "frame14");
  gtk_widget_show (frame14);
  gtk_box_pack_start (GTK_BOX (vbox14), frame14, TRUE, TRUE, 0);
  gtk_container_set_border_width (GTK_CONTAINER (frame14), 5);
  gtk_frame_set_shadow_type (GTK_FRAME (frame14), GTK_SHADOW_NONE);

  table11 = gtk_table_new (3, 3, FALSE);
  gtk_widget_set_name (table11, "table11");
  gtk_widget_show (table11);
  gtk_container_add (GTK_CONTAINER (frame14), table11);
  gtk_container_set_border_width (GTK_CONTAINER (table11), 5);
  gtk_table_set_row_spacings (GTK_TABLE (table11), 5);
  gtk_table_set_col_spacings (GTK_TABLE (table11), 5);

  label64 = gtk_label_new ("USA");
  gtk_widget_set_name (label64, "label64");
  gtk_widget_show (label64);
  gtk_table_attach (GTK_TABLE (table11), label64, 0, 1, 0, 1,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_misc_set_alignment (GTK_MISC (label64), 0, 0.5);

  label65 = gtk_label_new ("Europe");
  gtk_widget_set_name (label65, "label65");
  gtk_widget_show (label65);
  gtk_table_attach (GTK_TABLE (table11), label65, 0, 1, 1, 2,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_widget_set_size_request (label65, 75, -1);
  gtk_misc_set_alignment (GTK_MISC (label65), 0, 0.5);

  label66 = gtk_label_new ("Japan");
  gtk_widget_set_name (label66, "label66");
  gtk_widget_show (label66);
  gtk_table_attach (GTK_TABLE (table11), label66, 0, 1, 2, 3,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_misc_set_alignment (GTK_MISC (label66), 0, 0.5);

  buttonUSABios = gtk_button_new ();
  gtk_widget_set_name (buttonUSABios, "buttonUSABios");
  gtk_widget_show (buttonUSABios);
  gtk_table_attach (GTK_TABLE (table11), buttonUSABios, 2, 3, 0, 1,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_button_set_relief (GTK_BUTTON (buttonUSABios), GTK_RELIEF_NONE);

  alignment18 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_set_name (alignment18, "alignment18");
  gtk_widget_show (alignment18);
  gtk_container_add (GTK_CONTAINER (buttonUSABios), alignment18);

  hbox38 = gtk_hbox_new (FALSE, 2);
  gtk_widget_set_name (hbox38, "hbox38");
  gtk_widget_show (hbox38);
  gtk_container_add (GTK_CONTAINER (alignment18), hbox38);

  image2813 = create_pixmap (bios_files, "binary.png");
  gtk_widget_set_name (image2813, "image2813");
  gtk_widget_show (image2813);
  gtk_box_pack_start (GTK_BOX (hbox38), image2813, FALSE, FALSE, 0);

  label78 = gtk_label_new_with_mnemonic ("Change");
  gtk_widget_set_name (label78, "label78");
  gtk_widget_show (label78);
  gtk_box_pack_start (GTK_BOX (hbox38), label78, FALSE, FALSE, 0);

  buttonEURBios = gtk_button_new ();
  gtk_widget_set_name (buttonEURBios, "buttonEURBios");
  gtk_widget_show (buttonEURBios);
  gtk_table_attach (GTK_TABLE (table11), buttonEURBios, 2, 3, 1, 2,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_button_set_relief (GTK_BUTTON (buttonEURBios), GTK_RELIEF_NONE);

  alignment19 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_set_name (alignment19, "alignment19");
  gtk_widget_show (alignment19);
  gtk_container_add (GTK_CONTAINER (buttonEURBios), alignment19);

  hbox39 = gtk_hbox_new (FALSE, 2);
  gtk_widget_set_name (hbox39, "hbox39");
  gtk_widget_show (hbox39);
  gtk_container_add (GTK_CONTAINER (alignment19), hbox39);

  image2814 = create_pixmap (bios_files, "binary.png");
  gtk_widget_set_name (image2814, "image2814");
  gtk_widget_show (image2814);
  gtk_box_pack_start (GTK_BOX (hbox39), image2814, FALSE, FALSE, 0);

  label79 = gtk_label_new_with_mnemonic ("Change");
  gtk_widget_set_name (label79, "label79");
  gtk_widget_show (label79);
  gtk_box_pack_start (GTK_BOX (hbox39), label79, FALSE, FALSE, 0);

  buttonJAPBios = gtk_button_new ();
  gtk_widget_set_name (buttonJAPBios, "buttonJAPBios");
  gtk_widget_show (buttonJAPBios);
  gtk_table_attach (GTK_TABLE (table11), buttonJAPBios, 2, 3, 2, 3,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_button_set_relief (GTK_BUTTON (buttonJAPBios), GTK_RELIEF_NONE);

  alignment20 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_set_name (alignment20, "alignment20");
  gtk_widget_show (alignment20);
  gtk_container_add (GTK_CONTAINER (buttonJAPBios), alignment20);

  hbox40 = gtk_hbox_new (FALSE, 2);
  gtk_widget_set_name (hbox40, "hbox40");
  gtk_widget_show (hbox40);
  gtk_container_add (GTK_CONTAINER (alignment20), hbox40);

  image2815 = create_pixmap (bios_files, "binary.png");
  gtk_widget_set_name (image2815, "image2815");
  gtk_widget_show (image2815);
  gtk_box_pack_start (GTK_BOX (hbox40), image2815, FALSE, FALSE, 0);

  label80 = gtk_label_new_with_mnemonic ("Change");
  gtk_widget_set_name (label80, "label80");
  gtk_widget_show (label80);
  gtk_box_pack_start (GTK_BOX (hbox40), label80, FALSE, FALSE, 0);

  USAbios = gtk_entry_new ();
  gtk_widget_set_name (USAbios, "USAbios");
  gtk_widget_show (USAbios);
  gtk_table_attach (GTK_TABLE (table11), USAbios, 1, 2, 0, 1,
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_entry_set_has_frame (GTK_ENTRY (USAbios), FALSE);

  EURbios = gtk_entry_new ();
  gtk_widget_set_name (EURbios, "EURbios");
  gtk_widget_show (EURbios);
  gtk_table_attach (GTK_TABLE (table11), EURbios, 1, 2, 1, 2,
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_entry_set_has_frame (GTK_ENTRY (EURbios), FALSE);

  JAPbios = gtk_entry_new ();
  gtk_widget_set_name (JAPbios, "JAPbios");
  gtk_widget_show (JAPbios);
  gtk_table_attach (GTK_TABLE (table11), JAPbios, 1, 2, 2, 3,
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_entry_set_has_frame (GTK_ENTRY (JAPbios), FALSE);

  label67 = gtk_label_new ("<i><b>Configure Sega CD bios files</b></i>");
  gtk_widget_set_name (label67, "label67");
  gtk_widget_show (label67);
  gtk_frame_set_label_widget (GTK_FRAME (frame14), label67);
  gtk_label_set_use_markup (GTK_LABEL (label67), TRUE);

  frame15 = gtk_frame_new (NULL);
  gtk_widget_set_name (frame15, "frame15");
  gtk_widget_show (frame15);
  gtk_box_pack_start (GTK_BOX (vbox14), frame15, TRUE, TRUE, 0);
  gtk_container_set_border_width (GTK_CONTAINER (frame15), 5);
  gtk_frame_set_shadow_type (GTK_FRAME (frame15), GTK_SHADOW_NONE);

  table12 = gtk_table_new (2, 3, FALSE);
  gtk_widget_set_name (table12, "table12");
  gtk_widget_show (table12);
  gtk_container_add (GTK_CONTAINER (frame15), table12);
  gtk_container_set_border_width (GTK_CONTAINER (table12), 5);
  gtk_table_set_row_spacings (GTK_TABLE (table12), 5);
  gtk_table_set_col_spacings (GTK_TABLE (table12), 5);

  label68 = gtk_label_new ("CGOffline");
  gtk_widget_set_name (label68, "label68");
  gtk_widget_show (label68);
  gtk_table_attach (GTK_TABLE (table12), label68, 0, 1, 0, 1,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_widget_set_size_request (label68, 75, -1);
  gtk_misc_set_alignment (GTK_MISC (label68), 0, 0.5);

  label69 = gtk_label_new ("Manual");
  gtk_widget_set_name (label69, "label69");
  gtk_widget_show (label69);
  gtk_table_attach (GTK_TABLE (table12), label69, 0, 1, 1, 2,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_misc_set_alignment (GTK_MISC (label69), 0, 0.5);

  buttonCGOffline = gtk_button_new ();
  gtk_widget_set_name (buttonCGOffline, "buttonCGOffline");
  gtk_widget_show (buttonCGOffline);
  gtk_table_attach (GTK_TABLE (table12), buttonCGOffline, 2, 3, 0, 1,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_button_set_relief (GTK_BUTTON (buttonCGOffline), GTK_RELIEF_NONE);

  alignment21 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_set_name (alignment21, "alignment21");
  gtk_widget_show (alignment21);
  gtk_container_add (GTK_CONTAINER (buttonCGOffline), alignment21);

  hbox41 = gtk_hbox_new (FALSE, 2);
  gtk_widget_set_name (hbox41, "hbox41");
  gtk_widget_show (hbox41);
  gtk_container_add (GTK_CONTAINER (alignment21), hbox41);

  image2816 = create_pixmap (bios_files, "binary.png");
  gtk_widget_set_name (image2816, "image2816");
  gtk_widget_show (image2816);
  gtk_box_pack_start (GTK_BOX (hbox41), image2816, FALSE, FALSE, 0);

  label81 = gtk_label_new_with_mnemonic ("Change");
  gtk_widget_set_name (label81, "label81");
  gtk_widget_show (label81);
  gtk_box_pack_start (GTK_BOX (hbox41), label81, FALSE, FALSE, 0);

  buttonManual = gtk_button_new ();
  gtk_widget_set_name (buttonManual, "buttonManual");
  gtk_widget_show (buttonManual);
  gtk_table_attach (GTK_TABLE (table12), buttonManual, 2, 3, 1, 2,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_button_set_relief (GTK_BUTTON (buttonManual), GTK_RELIEF_NONE);

  alignment22 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_set_name (alignment22, "alignment22");
  gtk_widget_show (alignment22);
  gtk_container_add (GTK_CONTAINER (buttonManual), alignment22);

  hbox42 = gtk_hbox_new (FALSE, 2);
  gtk_widget_set_name (hbox42, "hbox42");
  gtk_widget_show (hbox42);
  gtk_container_add (GTK_CONTAINER (alignment22), hbox42);

  image2817 = create_pixmap (bios_files, "binary.png");
  gtk_widget_set_name (image2817, "image2817");
  gtk_widget_show (image2817);
  gtk_box_pack_start (GTK_BOX (hbox42), image2817, FALSE, FALSE, 0);

  label82 = gtk_label_new_with_mnemonic ("Change");
  gtk_widget_set_name (label82, "label82");
  gtk_widget_show (label82);
  gtk_box_pack_start (GTK_BOX (hbox42), label82, FALSE, FALSE, 0);

  CGOffline = gtk_entry_new ();
  gtk_widget_set_name (CGOffline, "CGOffline");
  gtk_widget_show (CGOffline);
  gtk_table_attach (GTK_TABLE (table12), CGOffline, 1, 2, 0, 1,
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_entry_set_has_frame (GTK_ENTRY (CGOffline), FALSE);

  manual = gtk_entry_new ();
  gtk_widget_set_name (manual, "manual");
  gtk_widget_show (manual);
  gtk_table_attach (GTK_TABLE (table12), manual, 1, 2, 1, 2,
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_entry_set_has_frame (GTK_ENTRY (manual), FALSE);

  label71 = gtk_label_new ("<i><b>Configure misc file</b></i>");
  gtk_widget_set_name (label71, "label71");
  gtk_widget_show (label71);
  gtk_frame_set_label_widget (GTK_FRAME (frame15), label71);
  gtk_label_set_use_markup (GTK_LABEL (label71), TRUE);

  hbox26 = gtk_hbox_new (TRUE, 0);
  gtk_widget_set_name (hbox26, "hbox26");
  gtk_widget_show (hbox26);
  gtk_box_pack_start (GTK_BOX (vbox14), hbox26, FALSE, TRUE, 0);

  button46 = gtk_button_new_from_stock ("gtk-help");
  gtk_widget_set_name (button46, "button46");
  gtk_widget_show (button46);
  gtk_box_pack_start (GTK_BOX (hbox26), button46, FALSE, FALSE, 0);
  gtk_button_set_relief (GTK_BUTTON (button46), GTK_RELIEF_NONE);

  button47 = gtk_button_new_from_stock ("gtk-cancel");
  gtk_widget_set_name (button47, "button47");
  gtk_widget_show (button47);
  gtk_box_pack_start (GTK_BOX (hbox26), button47, FALSE, FALSE, 0);
  gtk_button_set_relief (GTK_BUTTON (button47), GTK_RELIEF_NONE);

  buttonCfgBios = gtk_button_new_from_stock ("gtk-ok");
  gtk_widget_set_name (buttonCfgBios, "buttonCfgBios");
  gtk_widget_show (buttonCfgBios);
  gtk_box_pack_start (GTK_BOX (hbox26), buttonCfgBios, FALSE, FALSE, 0);
  gtk_button_set_relief (GTK_BUTTON (buttonCfgBios), GTK_RELIEF_NONE);

  g_signal_connect_swapped ((gpointer) button47, "clicked",
                            G_CALLBACK (gtk_widget_destroy),
                            GTK_OBJECT (bios_files));
  g_signal_connect ((gpointer) buttonCfgBios, "clicked",
                    G_CALLBACK (on_buttonCfgBios_clicked),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (bios_files, bios_files, "bios_files");
  GLADE_HOOKUP_OBJECT (bios_files, vbox14, "vbox14");
  GLADE_HOOKUP_OBJECT (bios_files, frame12, "frame12");
  GLADE_HOOKUP_OBJECT (bios_files, hbox27, "hbox27");
  GLADE_HOOKUP_OBJECT (bios_files, label59, "label59");
  GLADE_HOOKUP_OBJECT (bios_files, hbox30, "hbox30");
  GLADE_HOOKUP_OBJECT (bios_files, genesisBios, "genesisBios");
  GLADE_HOOKUP_OBJECT (bios_files, buttonGenesisBios, "buttonGenesisBios");
  GLADE_HOOKUP_OBJECT (bios_files, alignment14, "alignment14");
  GLADE_HOOKUP_OBJECT (bios_files, hbox34, "hbox34");
  GLADE_HOOKUP_OBJECT (bios_files, image2809, "image2809");
  GLADE_HOOKUP_OBJECT (bios_files, label74, "label74");
  GLADE_HOOKUP_OBJECT (bios_files, label58, "label58");
  GLADE_HOOKUP_OBJECT (bios_files, frame13, "frame13");
  GLADE_HOOKUP_OBJECT (bios_files, table10, "table10");
  GLADE_HOOKUP_OBJECT (bios_files, label62, "label62");
  GLADE_HOOKUP_OBJECT (bios_files, label63, "label63");
  GLADE_HOOKUP_OBJECT (bios_files, buttonM68000, "buttonM68000");
  GLADE_HOOKUP_OBJECT (bios_files, alignment15, "alignment15");
  GLADE_HOOKUP_OBJECT (bios_files, hbox35, "hbox35");
  GLADE_HOOKUP_OBJECT (bios_files, image2810, "image2810");
  GLADE_HOOKUP_OBJECT (bios_files, label94, "label94");
  GLADE_HOOKUP_OBJECT (bios_files, buttonMSH2, "buttonMSH2");
  GLADE_HOOKUP_OBJECT (bios_files, alignment16, "alignment16");
  GLADE_HOOKUP_OBJECT (bios_files, hbox36, "hbox36");
  GLADE_HOOKUP_OBJECT (bios_files, image2811, "image2811");
  GLADE_HOOKUP_OBJECT (bios_files, label76, "label76");
  GLADE_HOOKUP_OBJECT (bios_files, buttonSSH2, "buttonSSH2");
  GLADE_HOOKUP_OBJECT (bios_files, alignment17, "alignment17");
  GLADE_HOOKUP_OBJECT (bios_files, hbox37, "hbox37");
  GLADE_HOOKUP_OBJECT (bios_files, image2812, "image2812");
  GLADE_HOOKUP_OBJECT (bios_files, label77, "label77");
  GLADE_HOOKUP_OBJECT (bios_files, M68000, "M68000");
  GLADE_HOOKUP_OBJECT (bios_files, MSH2, "MSH2");
  GLADE_HOOKUP_OBJECT (bios_files, SSH2, "SSH2");
  GLADE_HOOKUP_OBJECT (bios_files, label61, "label61");
  GLADE_HOOKUP_OBJECT (bios_files, label60, "label60");
  GLADE_HOOKUP_OBJECT (bios_files, frame14, "frame14");
  GLADE_HOOKUP_OBJECT (bios_files, table11, "table11");
  GLADE_HOOKUP_OBJECT (bios_files, label64, "label64");
  GLADE_HOOKUP_OBJECT (bios_files, label65, "label65");
  GLADE_HOOKUP_OBJECT (bios_files, label66, "label66");
  GLADE_HOOKUP_OBJECT (bios_files, buttonUSABios, "buttonUSABios");
  GLADE_HOOKUP_OBJECT (bios_files, alignment18, "alignment18");
  GLADE_HOOKUP_OBJECT (bios_files, hbox38, "hbox38");
  GLADE_HOOKUP_OBJECT (bios_files, image2813, "image2813");
  GLADE_HOOKUP_OBJECT (bios_files, label78, "label78");
  GLADE_HOOKUP_OBJECT (bios_files, buttonEURBios, "buttonEURBios");
  GLADE_HOOKUP_OBJECT (bios_files, alignment19, "alignment19");
  GLADE_HOOKUP_OBJECT (bios_files, hbox39, "hbox39");
  GLADE_HOOKUP_OBJECT (bios_files, image2814, "image2814");
  GLADE_HOOKUP_OBJECT (bios_files, label79, "label79");
  GLADE_HOOKUP_OBJECT (bios_files, buttonJAPBios, "buttonJAPBios");
  GLADE_HOOKUP_OBJECT (bios_files, alignment20, "alignment20");
  GLADE_HOOKUP_OBJECT (bios_files, hbox40, "hbox40");
  GLADE_HOOKUP_OBJECT (bios_files, image2815, "image2815");
  GLADE_HOOKUP_OBJECT (bios_files, label80, "label80");
  GLADE_HOOKUP_OBJECT (bios_files, USAbios, "USAbios");
  GLADE_HOOKUP_OBJECT (bios_files, EURbios, "EURbios");
  GLADE_HOOKUP_OBJECT (bios_files, JAPbios, "JAPbios");
  GLADE_HOOKUP_OBJECT (bios_files, label67, "label67");
  GLADE_HOOKUP_OBJECT (bios_files, frame15, "frame15");
  GLADE_HOOKUP_OBJECT (bios_files, table12, "table12");
  GLADE_HOOKUP_OBJECT (bios_files, label68, "label68");
  GLADE_HOOKUP_OBJECT (bios_files, label69, "label69");
  GLADE_HOOKUP_OBJECT (bios_files, buttonCGOffline, "buttonCGOffline");
  GLADE_HOOKUP_OBJECT (bios_files, alignment21, "alignment21");
  GLADE_HOOKUP_OBJECT (bios_files, hbox41, "hbox41");
  GLADE_HOOKUP_OBJECT (bios_files, image2816, "image2816");
  GLADE_HOOKUP_OBJECT (bios_files, label81, "label81");
  GLADE_HOOKUP_OBJECT (bios_files, buttonManual, "buttonManual");
  GLADE_HOOKUP_OBJECT (bios_files, alignment22, "alignment22");
  GLADE_HOOKUP_OBJECT (bios_files, hbox42, "hbox42");
  GLADE_HOOKUP_OBJECT (bios_files, image2817, "image2817");
  GLADE_HOOKUP_OBJECT (bios_files, label82, "label82");
  GLADE_HOOKUP_OBJECT (bios_files, CGOffline, "CGOffline");
  GLADE_HOOKUP_OBJECT (bios_files, manual, "manual");
  GLADE_HOOKUP_OBJECT (bios_files, label71, "label71");
  GLADE_HOOKUP_OBJECT (bios_files, hbox26, "hbox26");
  GLADE_HOOKUP_OBJECT (bios_files, button46, "button46");
  GLADE_HOOKUP_OBJECT (bios_files, button47, "button47");
  GLADE_HOOKUP_OBJECT (bios_files, buttonCfgBios, "buttonCfgBios");

  return bios_files;
}

GtkWidget*
create_msgbox (void)
{
  GtkWidget *msgbox;
  GdkPixbuf *msgbox_icon_pixbuf;
  GtkWidget *dialog_vbox2;
  GtkWidget *hbox31;
  GtkWidget *image1504;
  GtkWidget *labelToDisplay;
  GtkWidget *dialog_action_area2;
  GtkWidget *okbutton2;

  msgbox = gtk_dialog_new ();
  gtk_widget_set_name (msgbox, "msgbox");
  gtk_widget_set_size_request (msgbox, 300, 120);
  gtk_window_set_title (GTK_WINDOW (msgbox), "Warning");
  gtk_window_set_position (GTK_WINDOW (msgbox), GTK_WIN_POS_CENTER);
  gtk_window_set_modal (GTK_WINDOW (msgbox), TRUE);
  gtk_window_set_resizable (GTK_WINDOW (msgbox), FALSE);
  msgbox_icon_pixbuf = create_pixbuf ("Gens2.ico");
  if (msgbox_icon_pixbuf)
    {
      gtk_window_set_icon (GTK_WINDOW (msgbox), msgbox_icon_pixbuf);
      g_object_unref (msgbox_icon_pixbuf);
    }
  gtk_window_set_type_hint (GTK_WINDOW (msgbox), GDK_WINDOW_TYPE_HINT_DIALOG);
  gtk_dialog_set_has_separator (GTK_DIALOG (msgbox), FALSE);

  dialog_vbox2 = GTK_DIALOG (msgbox)->vbox;
  gtk_widget_set_name (dialog_vbox2, "dialog_vbox2");
  gtk_widget_show (dialog_vbox2);

  hbox31 = gtk_hbox_new (FALSE, 5);
  gtk_widget_set_name (hbox31, "hbox31");
  gtk_widget_show (hbox31);
  gtk_box_pack_start (GTK_BOX (dialog_vbox2), hbox31, TRUE, FALSE, 0);
  gtk_container_set_border_width (GTK_CONTAINER (hbox31), 5);

  image1504 = gtk_image_new_from_stock ("gtk-dialog-warning", GTK_ICON_SIZE_DIALOG);
  gtk_widget_set_name (image1504, "image1504");
  gtk_widget_show (image1504);
  gtk_box_pack_start (GTK_BOX (hbox31), image1504, FALSE, FALSE, 0);

  labelToDisplay = gtk_label_new ("label75");
  gtk_widget_set_name (labelToDisplay, "labelToDisplay");
  gtk_widget_show (labelToDisplay);
  gtk_box_pack_start (GTK_BOX (hbox31), labelToDisplay, FALSE, FALSE, 0);
  gtk_label_set_justify (GTK_LABEL (labelToDisplay), GTK_JUSTIFY_CENTER);
  gtk_label_set_line_wrap (GTK_LABEL (labelToDisplay), TRUE);

  dialog_action_area2 = GTK_DIALOG (msgbox)->action_area;
  gtk_widget_set_name (dialog_action_area2, "dialog_action_area2");
  gtk_widget_show (dialog_action_area2);

  okbutton2 = gtk_button_new_from_stock ("gtk-ok");
  gtk_widget_set_name (okbutton2, "okbutton2");
  gtk_widget_show (okbutton2);
  gtk_dialog_add_action_widget (GTK_DIALOG (msgbox), okbutton2, GTK_RESPONSE_OK);
  GTK_WIDGET_SET_FLAGS (okbutton2, GTK_CAN_DEFAULT);
  gtk_button_set_relief (GTK_BUTTON (okbutton2), GTK_RELIEF_NONE);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (msgbox, msgbox, "msgbox");
  GLADE_HOOKUP_OBJECT_NO_REF (msgbox, dialog_vbox2, "dialog_vbox2");
  GLADE_HOOKUP_OBJECT (msgbox, hbox31, "hbox31");
  GLADE_HOOKUP_OBJECT (msgbox, image1504, "image1504");
  GLADE_HOOKUP_OBJECT (msgbox, labelToDisplay, "labelToDisplay");
  GLADE_HOOKUP_OBJECT_NO_REF (msgbox, dialog_action_area2, "dialog_action_area2");
  GLADE_HOOKUP_OBJECT (msgbox, okbutton2, "okbutton2");

  return msgbox;
}

GtkWidget*
create_opengl_resolution_custom (void)
{
  GtkWidget *opengl_resolution_custom;
  GtkWidget *vbox17;
  GtkWidget *frame16;
  GtkWidget *alignment31;
  GtkWidget *table14;
  GtkWidget *label92;
  GtkWidget *label93;
  GtkObject *spinbutton4_adj;
  GtkWidget *spinbutton4;
  GtkObject *spinbutton5_adj;
  GtkWidget *spinbutton5;
  GtkWidget *label91;
  GtkWidget *hbox51;
  GtkWidget *glres_cancel_button;
  GtkWidget *glres_ok_button;

  opengl_resolution_custom = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_widget_set_name (opengl_resolution_custom, "opengl_resolution_custom");
  gtk_container_set_border_width (GTK_CONTAINER (opengl_resolution_custom), 5);
  gtk_window_set_title (GTK_WINDOW (opengl_resolution_custom), "Set resolution");
  gtk_window_set_modal (GTK_WINDOW (opengl_resolution_custom), TRUE);
  gtk_window_set_resizable (GTK_WINDOW (opengl_resolution_custom), FALSE);

  vbox17 = gtk_vbox_new (FALSE, 5);
  gtk_widget_set_name (vbox17, "vbox17");
  gtk_widget_show (vbox17);
  gtk_container_add (GTK_CONTAINER (opengl_resolution_custom), vbox17);

  frame16 = gtk_frame_new (NULL);
  gtk_widget_set_name (frame16, "frame16");
  gtk_widget_show (frame16);
  gtk_box_pack_start (GTK_BOX (vbox17), frame16, TRUE, TRUE, 0);
  gtk_frame_set_shadow_type (GTK_FRAME (frame16), GTK_SHADOW_NONE);

  alignment31 = gtk_alignment_new (0.5, 0.5, 1, 1);
  gtk_widget_set_name (alignment31, "alignment31");
  gtk_widget_show (alignment31);
  gtk_container_add (GTK_CONTAINER (frame16), alignment31);
  gtk_alignment_set_padding (GTK_ALIGNMENT (alignment31), 0, 0, 12, 0);

  table14 = gtk_table_new (2, 2, FALSE);
  gtk_widget_set_name (table14, "table14");
  gtk_widget_show (table14);
  gtk_container_add (GTK_CONTAINER (alignment31), table14);
  gtk_table_set_row_spacings (GTK_TABLE (table14), 5);
  gtk_table_set_col_spacings (GTK_TABLE (table14), 5);

  label92 = gtk_label_new ("Width");
  gtk_widget_set_name (label92, "label92");
  gtk_widget_show (label92);
  gtk_table_attach (GTK_TABLE (table14), label92, 0, 1, 0, 1,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_misc_set_alignment (GTK_MISC (label92), 0, 0.5);

  label93 = gtk_label_new ("Height");
  gtk_widget_set_name (label93, "label93");
  gtk_widget_show (label93);
  gtk_table_attach (GTK_TABLE (table14), label93, 0, 1, 1, 2,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_misc_set_alignment (GTK_MISC (label93), 0, 0.5);

  spinbutton4_adj = gtk_adjustment_new (1, 0, 9999, 1, 10, 10);
  spinbutton4 = gtk_spin_button_new (GTK_ADJUSTMENT (spinbutton4_adj), 1, 0);
  gtk_widget_set_name (spinbutton4, "spinbutton4");
  gtk_widget_show (spinbutton4);
  gtk_table_attach (GTK_TABLE (table14), spinbutton4, 1, 2, 0, 1,
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);

  spinbutton5_adj = gtk_adjustment_new (1, 0, 9999, 1, 10, 10);
  spinbutton5 = gtk_spin_button_new (GTK_ADJUSTMENT (spinbutton5_adj), 1, 0);
  gtk_widget_set_name (spinbutton5, "spinbutton5");
  gtk_widget_show (spinbutton5);
  gtk_table_attach (GTK_TABLE (table14), spinbutton5, 1, 2, 1, 2,
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);

  label91 = gtk_label_new ("<b><i>OpenGL Resolution</i></b>");
  gtk_widget_set_name (label91, "label91");
  gtk_widget_show (label91);
  gtk_frame_set_label_widget (GTK_FRAME (frame16), label91);
  gtk_label_set_use_markup (GTK_LABEL (label91), TRUE);

  hbox51 = gtk_hbox_new (TRUE, 5);
  gtk_widget_set_name (hbox51, "hbox51");
  gtk_widget_show (hbox51);
  gtk_box_pack_start (GTK_BOX (vbox17), hbox51, TRUE, TRUE, 0);

  glres_cancel_button = gtk_button_new_from_stock ("gtk-cancel");
  gtk_widget_set_name (glres_cancel_button, "glres_cancel_button");
  gtk_widget_show (glres_cancel_button);
  gtk_box_pack_start (GTK_BOX (hbox51), glres_cancel_button, FALSE, FALSE, 0);
  gtk_button_set_relief (GTK_BUTTON (glres_cancel_button), GTK_RELIEF_NONE);

  glres_ok_button = gtk_button_new_from_stock ("gtk-ok");
  gtk_widget_set_name (glres_ok_button, "glres_ok_button");
  gtk_widget_show (glres_ok_button);
  gtk_box_pack_start (GTK_BOX (hbox51), glres_ok_button, FALSE, FALSE, 0);
  gtk_button_set_relief (GTK_BUTTON (glres_ok_button), GTK_RELIEF_NONE);

  g_signal_connect ((gpointer) opengl_resolution_custom, "show",
                    G_CALLBACK (on_opengl_resolution_custom_show),
                    NULL);
  g_signal_connect_swapped ((gpointer) glres_cancel_button, "clicked",
                            G_CALLBACK (gtk_widget_destroy),
                            GTK_OBJECT (opengl_resolution_custom));
  g_signal_connect ((gpointer) glres_ok_button, "clicked",
                    G_CALLBACK (on_glres_ok_button_clicked),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (opengl_resolution_custom, opengl_resolution_custom, "opengl_resolution_custom");
  GLADE_HOOKUP_OBJECT (opengl_resolution_custom, vbox17, "vbox17");
  GLADE_HOOKUP_OBJECT (opengl_resolution_custom, frame16, "frame16");
  GLADE_HOOKUP_OBJECT (opengl_resolution_custom, alignment31, "alignment31");
  GLADE_HOOKUP_OBJECT (opengl_resolution_custom, table14, "table14");
  GLADE_HOOKUP_OBJECT (opengl_resolution_custom, label92, "label92");
  GLADE_HOOKUP_OBJECT (opengl_resolution_custom, label93, "label93");
  GLADE_HOOKUP_OBJECT (opengl_resolution_custom, spinbutton4, "spinbutton4");
  GLADE_HOOKUP_OBJECT (opengl_resolution_custom, spinbutton5, "spinbutton5");
  GLADE_HOOKUP_OBJECT (opengl_resolution_custom, label91, "label91");
  GLADE_HOOKUP_OBJECT (opengl_resolution_custom, hbox51, "hbox51");
  GLADE_HOOKUP_OBJECT (opengl_resolution_custom, glres_cancel_button, "glres_cancel_button");
  GLADE_HOOKUP_OBJECT (opengl_resolution_custom, glres_ok_button, "glres_ok_button");

  return opengl_resolution_custom;
}

GtkWidget*
create_sdl_test (void)
{
  GtkWidget *sdl_test;
  GdkPixbuf *sdl_test_icon_pixbuf;
  GtkWidget *frame17;
  GtkWidget *alignment32;
  GtkWidget *vbox19;
  GtkWidget *label99;
  GtkWidget *hbox57;
  GtkWidget *label100;
  GtkWidget *sdltest_status;
  GtkWidget *hbuttonbox1;
  GtkWidget *sdlok;
  GtkWidget *RunTest;
  GtkWidget *alignment33;
  GtkWidget *hbox58;
  GtkWidget *image3294;
  GtkWidget *label102;
  GtkWidget *label98;

  sdl_test = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_widget_set_name (sdl_test, "sdl_test");
  gtk_widget_set_size_request (sdl_test, 315, 190);
  gtk_container_set_border_width (GTK_CONTAINER (sdl_test), 2);
  gtk_window_set_title (GTK_WINDOW (sdl_test), "SDL Sound Test");
  gtk_window_set_position (GTK_WINDOW (sdl_test), GTK_WIN_POS_CENTER_ALWAYS);
  gtk_window_set_resizable (GTK_WINDOW (sdl_test), FALSE);
  sdl_test_icon_pixbuf = create_pixbuf ("Gens2.ico");
  if (sdl_test_icon_pixbuf)
    {
      gtk_window_set_icon (GTK_WINDOW (sdl_test), sdl_test_icon_pixbuf);
      g_object_unref (sdl_test_icon_pixbuf);
    }

  frame17 = gtk_frame_new (NULL);
  gtk_widget_set_name (frame17, "frame17");
  gtk_widget_show (frame17);
  gtk_container_add (GTK_CONTAINER (sdl_test), frame17);
  gtk_widget_set_size_request (frame17, 304, 167);
  gtk_frame_set_shadow_type (GTK_FRAME (frame17), GTK_SHADOW_NONE);

  alignment32 = gtk_alignment_new (0.5, 0.5, 1, 1);
  gtk_widget_set_name (alignment32, "alignment32");
  gtk_widget_show (alignment32);
  gtk_container_add (GTK_CONTAINER (frame17), alignment32);
  gtk_alignment_set_padding (GTK_ALIGNMENT (alignment32), 0, 0, 16, 0);

  vbox19 = gtk_vbox_new (FALSE, 0);
  gtk_widget_set_name (vbox19, "vbox19");
  gtk_widget_show (vbox19);
  gtk_container_add (GTK_CONTAINER (alignment32), vbox19);

  label99 = gtk_label_new ("This is merely a simple SDL Sound Test that determines whether or not SDL is installed correctly.  It basically tries to initialize the sound system and kill it exactly 5 times.  If your computer cannot execute these correctly, you will fail the sound test.");
  gtk_widget_set_name (label99, "label99");
  gtk_widget_show (label99);
  gtk_box_pack_start (GTK_BOX (vbox19), label99, FALSE, FALSE, 0);
  gtk_widget_set_size_request (label99, 279, 103);
  gtk_label_set_line_wrap (GTK_LABEL (label99), TRUE);
  gtk_misc_set_alignment (GTK_MISC (label99), 0, 0);
  gtk_misc_set_padding (GTK_MISC (label99), 10, 0);

  hbox57 = gtk_hbox_new (FALSE, 21);
  gtk_widget_set_name (hbox57, "hbox57");
  gtk_widget_show (hbox57);
  gtk_box_pack_start (GTK_BOX (vbox19), hbox57, TRUE, TRUE, 0);

  label100 = gtk_label_new ("Status: ");
  gtk_widget_set_name (label100, "label100");
  gtk_widget_show (label100);
  gtk_box_pack_start (GTK_BOX (hbox57), label100, FALSE, FALSE, 0);

  sdltest_status = gtk_label_new ("N/A");
  gtk_widget_set_name (sdltest_status, "sdltest_status");
  gtk_widget_show (sdltest_status);
  gtk_box_pack_start (GTK_BOX (hbox57), sdltest_status, FALSE, FALSE, 0);

  hbuttonbox1 = gtk_hbutton_box_new ();
  gtk_widget_set_name (hbuttonbox1, "hbuttonbox1");
  gtk_widget_show (hbuttonbox1);
  gtk_box_pack_start (GTK_BOX (vbox19), hbuttonbox1, TRUE, TRUE, 0);
  gtk_button_box_set_layout (GTK_BUTTON_BOX (hbuttonbox1), GTK_BUTTONBOX_SPREAD);

  sdlok = gtk_button_new_from_stock ("gtk-ok");
  gtk_widget_set_name (sdlok, "sdlok");
  gtk_widget_show (sdlok);
  gtk_container_add (GTK_CONTAINER (hbuttonbox1), sdlok);
  GTK_WIDGET_SET_FLAGS (sdlok, GTK_CAN_DEFAULT);

  RunTest = gtk_button_new ();
  gtk_widget_set_name (RunTest, "RunTest");
  gtk_widget_show (RunTest);
  gtk_container_add (GTK_CONTAINER (hbuttonbox1), RunTest);
  GTK_WIDGET_SET_FLAGS (RunTest, GTK_CAN_DEFAULT);

  alignment33 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_set_name (alignment33, "alignment33");
  gtk_widget_show (alignment33);
  gtk_container_add (GTK_CONTAINER (RunTest), alignment33);

  hbox58 = gtk_hbox_new (FALSE, 2);
  gtk_widget_set_name (hbox58, "hbox58");
  gtk_widget_show (hbox58);
  gtk_container_add (GTK_CONTAINER (alignment33), hbox58);

  image3294 = gtk_image_new_from_stock ("gtk-properties", GTK_ICON_SIZE_BUTTON);
  gtk_widget_set_name (image3294, "image3294");
  gtk_widget_show (image3294);
  gtk_box_pack_start (GTK_BOX (hbox58), image3294, FALSE, FALSE, 0);

  label102 = gtk_label_new_with_mnemonic ("Run Test");
  gtk_widget_set_name (label102, "label102");
  gtk_widget_show (label102);
  gtk_box_pack_start (GTK_BOX (hbox58), label102, FALSE, FALSE, 0);

  label98 = gtk_label_new ("");
  gtk_widget_set_name (label98, "label98");
  gtk_widget_show (label98);
  gtk_frame_set_label_widget (GTK_FRAME (frame17), label98);
  gtk_label_set_use_markup (GTK_LABEL (label98), TRUE);

  g_signal_connect ((gpointer) sdlok, "clicked",
                    G_CALLBACK (on_sdlok_clicked),
                    NULL);
  g_signal_connect ((gpointer) RunTest, "clicked",
                    G_CALLBACK (on_RunTest_clicked),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (sdl_test, sdl_test, "sdl_test");
  GLADE_HOOKUP_OBJECT (sdl_test, frame17, "frame17");
  GLADE_HOOKUP_OBJECT (sdl_test, alignment32, "alignment32");
  GLADE_HOOKUP_OBJECT (sdl_test, vbox19, "vbox19");
  GLADE_HOOKUP_OBJECT (sdl_test, label99, "label99");
  GLADE_HOOKUP_OBJECT (sdl_test, hbox57, "hbox57");
  GLADE_HOOKUP_OBJECT (sdl_test, label100, "label100");
  GLADE_HOOKUP_OBJECT (sdl_test, sdltest_status, "sdltest_status");
  GLADE_HOOKUP_OBJECT (sdl_test, hbuttonbox1, "hbuttonbox1");
  GLADE_HOOKUP_OBJECT (sdl_test, sdlok, "sdlok");
  GLADE_HOOKUP_OBJECT (sdl_test, RunTest, "RunTest");
  GLADE_HOOKUP_OBJECT (sdl_test, alignment33, "alignment33");
  GLADE_HOOKUP_OBJECT (sdl_test, hbox58, "hbox58");
  GLADE_HOOKUP_OBJECT (sdl_test, image3294, "image3294");
  GLADE_HOOKUP_OBJECT (sdl_test, label102, "label102");
  GLADE_HOOKUP_OBJECT (sdl_test, label98, "label98");

  return sdl_test;
}

GtkWidget*
create_cdrom_window (void)
{
  GtkWidget *cdrom_window;
  GdkPixbuf *cdrom_window_icon_pixbuf;
  GtkWidget *vbox18;
  GtkWidget *frame17;
  GtkWidget *hbox52;
  GtkWidget *label95;
  GtkWidget *hbox53;
  GtkWidget *cd_drive;
  GtkWidget *button_cddrive;
  GtkWidget *alignment32;
  GtkWidget *hbox54;
  GtkWidget *image3354;
  GtkWidget *label96;
  GtkWidget *label97;
  GtkWidget *frame18;
  GtkWidget *alignment33;
  GtkWidget *hbox64;
  GtkWidget *label99;
  GtkWidget *comboboxentry1;
  GtkWidget *label98;
  GtkWidget *hbox63;
  GtkWidget *button58;
  GtkWidget *button59;

  cdrom_window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_widget_set_name (cdrom_window, "cdrom_window");
  gtk_widget_set_size_request (cdrom_window, 400, -1);
  gtk_container_set_border_width (GTK_CONTAINER (cdrom_window), 5);
  gtk_window_set_title (GTK_WINDOW (cdrom_window), "Select CDRom drive");
  gtk_window_set_position (GTK_WINDOW (cdrom_window), GTK_WIN_POS_CENTER);
  cdrom_window_icon_pixbuf = create_pixbuf ("Gens2.ico");
  if (cdrom_window_icon_pixbuf)
    {
      gtk_window_set_icon (GTK_WINDOW (cdrom_window), cdrom_window_icon_pixbuf);
      g_object_unref (cdrom_window_icon_pixbuf);
    }

  vbox18 = gtk_vbox_new (FALSE, 10);
  gtk_widget_set_name (vbox18, "vbox18");
  gtk_widget_show (vbox18);
  gtk_container_add (GTK_CONTAINER (cdrom_window), vbox18);
  gtk_container_set_border_width (GTK_CONTAINER (vbox18), 5);

  frame17 = gtk_frame_new (NULL);
  gtk_widget_set_name (frame17, "frame17");
  gtk_widget_show (frame17);
  gtk_box_pack_start (GTK_BOX (vbox18), frame17, TRUE, TRUE, 0);
  gtk_container_set_border_width (GTK_CONTAINER (frame17), 5);
  gtk_frame_set_shadow_type (GTK_FRAME (frame17), GTK_SHADOW_NONE);

  hbox52 = gtk_hbox_new (FALSE, 5);
  gtk_widget_set_name (hbox52, "hbox52");
  gtk_widget_show (hbox52);
  gtk_container_add (GTK_CONTAINER (frame17), hbox52);
  gtk_container_set_border_width (GTK_CONTAINER (hbox52), 5);

  label95 = gtk_label_new ("CD drive");
  gtk_widget_set_name (label95, "label95");
  gtk_widget_show (label95);
  gtk_box_pack_start (GTK_BOX (hbox52), label95, FALSE, FALSE, 0);

  hbox53 = gtk_hbox_new (FALSE, 0);
  gtk_widget_set_name (hbox53, "hbox53");
  gtk_widget_show (hbox53);
  gtk_box_pack_start (GTK_BOX (hbox52), hbox53, TRUE, TRUE, 0);

  cd_drive = gtk_entry_new ();
  gtk_widget_set_name (cd_drive, "cd_drive");
  gtk_widget_show (cd_drive);
  gtk_box_pack_start (GTK_BOX (hbox53), cd_drive, TRUE, TRUE, 0);
  gtk_entry_set_has_frame (GTK_ENTRY (cd_drive), FALSE);

  button_cddrive = gtk_button_new ();
  gtk_widget_set_name (button_cddrive, "button_cddrive");
  gtk_widget_show (button_cddrive);
  gtk_box_pack_start (GTK_BOX (hbox53), button_cddrive, FALSE, FALSE, 0);
  gtk_button_set_relief (GTK_BUTTON (button_cddrive), GTK_RELIEF_NONE);

  alignment32 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_set_name (alignment32, "alignment32");
  gtk_widget_show (alignment32);
  gtk_container_add (GTK_CONTAINER (button_cddrive), alignment32);

  hbox54 = gtk_hbox_new (FALSE, 2);
  gtk_widget_set_name (hbox54, "hbox54");
  gtk_widget_show (hbox54);
  gtk_container_add (GTK_CONTAINER (alignment32), hbox54);

  image3354 = create_pixmap (cdrom_window, "binary.png");
  gtk_widget_set_name (image3354, "image3354");
  gtk_widget_show (image3354);
  gtk_box_pack_start (GTK_BOX (hbox54), image3354, FALSE, FALSE, 0);

  label96 = gtk_label_new_with_mnemonic ("Change");
  gtk_widget_set_name (label96, "label96");
  gtk_widget_show (label96);
  gtk_box_pack_start (GTK_BOX (hbox54), label96, FALSE, FALSE, 0);

  label97 = gtk_label_new ("Typical values are <i>/dev/cdrom</i> or <i>/dev/hdc </i>");
  gtk_widget_set_name (label97, "label97");
  gtk_widget_show (label97);
  gtk_frame_set_label_widget (GTK_FRAME (frame17), label97);
  gtk_label_set_use_markup (GTK_LABEL (label97), TRUE);

  frame18 = gtk_frame_new (NULL);
  gtk_widget_set_name (frame18, "frame18");
  gtk_widget_show (frame18);
  gtk_box_pack_start (GTK_BOX (vbox18), frame18, TRUE, TRUE, 0);
  gtk_frame_set_shadow_type (GTK_FRAME (frame18), GTK_SHADOW_NONE);

  alignment33 = gtk_alignment_new (0.5, 0.5, 1, 1);
  gtk_widget_set_name (alignment33, "alignment33");
  gtk_widget_show (alignment33);
  gtk_container_add (GTK_CONTAINER (frame18), alignment33);
  gtk_alignment_set_padding (GTK_ALIGNMENT (alignment33), 0, 0, 12, 0);

  hbox64 = gtk_hbox_new (FALSE, 84);
  gtk_widget_set_name (hbox64, "hbox64");
  gtk_widget_show (hbox64);
  gtk_container_add (GTK_CONTAINER (alignment33), hbox64);

  label99 = gtk_label_new ("You may need to restart Gens");
  gtk_widget_set_name (label99, "label99");
  gtk_widget_show (label99);
  gtk_box_pack_start (GTK_BOX (hbox64), label99, FALSE, FALSE, 0);

  comboboxentry1 = gtk_combo_box_entry_new_text ();
  gtk_widget_set_name (comboboxentry1, "comboboxentry1");
  gtk_widget_show (comboboxentry1);
  gtk_box_pack_start (GTK_BOX (hbox64), comboboxentry1, TRUE, TRUE, 0);
  gtk_combo_box_append_text (GTK_COMBO_BOX (comboboxentry1), "0 (auto)");
  gtk_combo_box_append_text (GTK_COMBO_BOX (comboboxentry1), "1");
  gtk_combo_box_append_text (GTK_COMBO_BOX (comboboxentry1), "2");
  gtk_combo_box_append_text (GTK_COMBO_BOX (comboboxentry1), "4");
  gtk_combo_box_append_text (GTK_COMBO_BOX (comboboxentry1), "8");
  gtk_combo_box_append_text (GTK_COMBO_BOX (comboboxentry1), "10");
  gtk_combo_box_append_text (GTK_COMBO_BOX (comboboxentry1), "12");
  gtk_combo_box_append_text (GTK_COMBO_BOX (comboboxentry1), "20 (default)");
  gtk_combo_box_append_text (GTK_COMBO_BOX (comboboxentry1), "32");
  gtk_combo_box_append_text (GTK_COMBO_BOX (comboboxentry1), "36");
  gtk_combo_box_append_text (GTK_COMBO_BOX (comboboxentry1), "40");
  gtk_combo_box_append_text (GTK_COMBO_BOX (comboboxentry1), "48");
  gtk_combo_box_append_text (GTK_COMBO_BOX (comboboxentry1), "50");
  gtk_combo_box_append_text (GTK_COMBO_BOX (comboboxentry1), "52");
  gtk_combo_box_set_active  (GTK_COMBO_BOX (comboboxentry1), Ritorna_Vel());

  label98 = gtk_label_new ("CDROM speed manual selection");
  gtk_widget_set_name (label98, "label98");
  gtk_widget_show (label98);
  gtk_frame_set_label_widget (GTK_FRAME (frame18), label98);
  gtk_label_set_use_markup (GTK_LABEL (label98), TRUE);

  hbox63 = gtk_hbox_new (TRUE, 0);
  gtk_widget_set_name (hbox63, "hbox63");
  gtk_widget_show (hbox63);
  gtk_box_pack_start (GTK_BOX (vbox18), hbox63, FALSE, TRUE, 0);

  button58 = gtk_button_new_from_stock ("gtk-cancel");
  gtk_widget_set_name (button58, "button58");
  gtk_widget_show (button58);
  gtk_box_pack_start (GTK_BOX (hbox63), button58, FALSE, FALSE, 0);
  gtk_button_set_relief (GTK_BUTTON (button58), GTK_RELIEF_NONE);

  button59 = gtk_button_new_from_stock ("gtk-ok");
  gtk_widget_set_name (button59, "button59");
  gtk_widget_show (button59);
  gtk_box_pack_start (GTK_BOX (hbox63), button59, FALSE, FALSE, 0);
  gtk_button_set_relief (GTK_BUTTON (button59), GTK_RELIEF_NONE);

  g_signal_connect_swapped ((gpointer) button58, "clicked",
                            G_CALLBACK (gtk_widget_destroy),
                            GTK_OBJECT (cdrom_window));
  g_signal_connect ((gpointer) button59, "clicked",
                    G_CALLBACK (on_buttonokcd_clicked),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (cdrom_window, cdrom_window, "cdrom_window");
  GLADE_HOOKUP_OBJECT (cdrom_window, vbox18, "vbox18");
  GLADE_HOOKUP_OBJECT (cdrom_window, frame17, "frame17");
  GLADE_HOOKUP_OBJECT (cdrom_window, hbox52, "hbox52");
  GLADE_HOOKUP_OBJECT (cdrom_window, label95, "label95");
  GLADE_HOOKUP_OBJECT (cdrom_window, hbox53, "hbox53");
  GLADE_HOOKUP_OBJECT (cdrom_window, cd_drive, "cd_drive");
  GLADE_HOOKUP_OBJECT (cdrom_window, button_cddrive, "button_cddrive");
  GLADE_HOOKUP_OBJECT (cdrom_window, alignment32, "alignment32");
  GLADE_HOOKUP_OBJECT (cdrom_window, hbox54, "hbox54");
  GLADE_HOOKUP_OBJECT (cdrom_window, image3354, "image3354");
  GLADE_HOOKUP_OBJECT (cdrom_window, label96, "label96");
  GLADE_HOOKUP_OBJECT (cdrom_window, label97, "label97");
  GLADE_HOOKUP_OBJECT (cdrom_window, frame18, "frame18");
  GLADE_HOOKUP_OBJECT (cdrom_window, alignment33, "alignment33");
  GLADE_HOOKUP_OBJECT (cdrom_window, hbox64, "hbox64");
  GLADE_HOOKUP_OBJECT (cdrom_window, label99, "label99");
  GLADE_HOOKUP_OBJECT (cdrom_window, comboboxentry1, "comboboxentry1");
  GLADE_HOOKUP_OBJECT (cdrom_window, label98, "label98");
  GLADE_HOOKUP_OBJECT (cdrom_window, hbox63, "hbox63");
  GLADE_HOOKUP_OBJECT (cdrom_window, button58, "button58");
  GLADE_HOOKUP_OBJECT (cdrom_window, button59, "button59");

  return cdrom_window;
}


