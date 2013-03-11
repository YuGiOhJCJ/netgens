# Copyright 2013 YuGiOhJCJ
#
# This file is part of Netgens.
#
# Netgens is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# Netgens is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with Netgens.  If not, see <http://www.gnu.org/licenses/>.
AC_INIT([netgens], [2.12])
AM_INIT_AUTOMAKE
AM_PROG_CC_C_O
AC_CHECK_LIB([SDL], [SDL_Init], [], [AC_MSG_ERROR([cannot find the SDL library, go to http://www.libsdl.org/])])
AC_CHECK_LIB([SDL_net], [SDLNet_Init], [], [AC_MSG_ERROR([cannot find the SDL_net library, go to http://www.libsdl.org/])])
AC_CHECK_LIB([gtk-x11-2.0], [gtk_init], [], [AC_MSG_ERROR([cannot find the gtk-x11-2.0 library, go to http://www.gtk.org/])])
AC_CHECK_LIB([GL], [glEnable], [], [AC_MSG_ERROR([cannot find the GL library, go to http://mesa3d.sourceforge.net/])])
AC_CHECK_PROG([HAVE_PKG_CONFIG],[pkg-config],[yes])
AC_CHECK_PROG([HAVE_NASM],[nasm],[yes])
if test "x$HAVE_PKG_CONFIG" != xyes; then
	AC_MSG_ERROR([cannot find the pkg-config program, go to http://www.freedesktop.org/])
fi
if test "x$HAVE_NASM" != xyes; then
	AC_MSG_ERROR([cannot find the nasm program, go to http://www.nasm.us/])
fi
AC_SUBST([SDL_CFLAGS], [`pkg-config sdl --cflags`])
AC_SUBST([GTK_CFLAGS], [`pkg-config gtk+-x11-2.0 --cflags`])
AC_SUBST([GL_CFLAGS], [`pkg-config gl --cflags`])
AC_SUBST([SDL_LIBS], [`pkg-config sdl --libs`])
AC_SUBST([GTK_LIBS], [`pkg-config gtk+-x11-2.0 --libs`])
AC_SUBST([GL_LIBS], [`pkg-config gl --libs`])
AC_SUBST([SDLNET_LIBS], [-lSDL_net])
AC_CONFIG_FILES([Makefile
	pixmaps/Makefile
	src/gens/Makefile
	src/Makefile
	src/starscream/main68k/Makefile
	src/starscream/Makefile
	src/starscream/sub68k/Makefile])
AC_OUTPUT
