
/*
 * @copyright
 *
 *  Copyright 2014 Neo Natura
 *
 *  This file is part of the Share Library.
 *  (https://github.com/neonatura/share)
 *        
 *  The Share Library is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version. 
 *
 *  The Share Library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with The Share Library.  If not, see <http://www.gnu.org/licenses/>.
 *
 *  @endcopyright
 */

#define LUA_CORE
#include "sexe.h"
#include <stdio.h>

static FILE *sexe_stdin;
static FILE *sexe_stdout;
static FILE *sexe_stderr;
static FILE *sexe_null;

FILE *get_sexe_null(void)
{
	if (!sexe_null) {
		sexe_null = fopen("/dev/null", "rb+");
	}
	return (sexe_null);
}

void set_sexe_stdin(FILE *in)
{
	sexe_stdin = in;
}

void set_sexe_stdout(FILE *out)
{
	sexe_stdout = out;
}

void set_sexe_stderr(FILE *err)
{
	sexe_stderr = err;
}

FILE *get_sexe_stdin(void)
{
	if (!sexe_stdin)
		return (get_sexe_null());
	return (sexe_stdin);
}

FILE *get_sexe_stdout(void)
{
	if (!sexe_stdout)
		return (get_sexe_null());
	return (sexe_stdout);
}

FILE *get_sexe_stderr(void)
{
	if (!sexe_stderr)
		return (get_sexe_null());
	return (sexe_stderr);
}


