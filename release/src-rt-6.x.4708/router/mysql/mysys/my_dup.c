/* Copyright (c) 2000, 2001, 2004, 2006, 2007 MySQL AB

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; version 2 of the License.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA */

#include "mysys_priv.h"
#include "mysys_err.h"
#include <my_dir.h>
#include <errno.h>
#if defined(__WIN__)
#include <share.h>
#endif

	/* Open a file */

File my_dup(File file, myf MyFlags)
{
  File fd;
  const char *filename;
  DBUG_ENTER("my_dup");
  DBUG_PRINT("my",("file: %d  MyFlags: %d", file, MyFlags));
  fd = dup(file);
  filename= (((uint) file < my_file_limit) ?
	     my_file_info[(int) file].name : "Unknown");
  DBUG_RETURN(my_register_filename(fd, filename, FILE_BY_DUP,
				   EE_FILENOTFOUND, MyFlags));
} /* my_open */
