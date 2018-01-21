
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

#include "sexe.h"


static int _lbase_abs(lua_State *L)
{
  double d = lua_tonumber(L, 1);
  lua_pushnumber(L, fabs(d));
  return (1); /* (1) math 'absolute' of arg */
}

static int _lbase_ceil(lua_State *L)
{
  double d = lua_tonumber(L, 1);
  lua_pushnumber(L, ceil(d));
  return 1; /* math 'ceil' of arg */
}

static int _lbase_clamp(lua_State *L)
{
  double d = lua_tonumber(L, 1);
  double min = lua_tonumber(L, 2);
  double max = lua_tonumber(L, 3);
  if (d > max) d = max;
  if (d < min) d = min;
  lua_pushnumber(L, d);
  return 1; /* math 'clamp' of arg */
}

static int _lbase_floor(lua_State *L)
{
  double d = lua_tonumber(L, 1);
  lua_pushnumber(L, floor(d));
  return 1; /* math 'floor' of arg */
}

static int _lbase_max(lua_State *L)
{
  double d1 = lua_tonumber(L, 1);
  double d2 = lua_tonumber(L, 2);
  lua_pushnumber(L, d1 > d2 ? d1 : d2);
  return 1; /* math 'max' of arg */
}

static int _lbase_min(lua_State *L)
{
  double d1 = lua_tonumber(L, 1);
  double d2 = lua_tonumber(L, 2);
  lua_pushnumber(L, d1 < d2 ? d1 : d2);
  return 1; /* math 'min' of arg */
}

static int _lbase_mod(lua_State *L)
{
  double d = lua_tonumber(L, 1);
  double m = lua_tonumber(L, 2);
  if (m == 0) {
    lua_pushnumber(L, 0);
  } else {
    lua_pushnumber(L, (double)((int)d % (int)m));
  }
  return 1; /* math 'mod' of arg */
}

static int _lbase_pow(lua_State *L)
{
  double d = lua_tonumber(L, 1);
  double m = lua_tonumber(L, 2);
  lua_pushnumber(L, pow(d, m));
  return 1; /* math 'pow' of arg */
}

static int _lbase_random(lua_State *L)
{
  double d = (double)(shrand() & 0xFFFFFFFF);
  lua_pushnumber(L, d);
  return 1; /* math 'random' integral */
}

static int _lbase_round(lua_State *L)
{
  double d = lua_tonumber(L, 1);
  lua_pushnumber(L, round(d));
  return 1; /* math 'round' of arg */
}

static int _lbase_sign(lua_State *L)
{
  double d = lua_tonumber(L, 1);
  double ret_num;

  if (d == 0) {
    lua_pushnumber(L, d);
  } else {
    lua_pushnumber(L, d > 0 ? 1 : -1);
  }
  return (1); /* (1) math 'sign' of number arg */
}

static int _lbase_sqrt(lua_State *L)
{
  double d = lua_tonumber(L, 1);
  lua_pushnumber(L, sqrt(d));
  return 1; /* math 'sqrt' of arg */
}

static const luaL_Reg sexe_math_funcs[] = {
  {"abs", _lbase_abs},
  {"ceil", _lbase_ceil},
  {"clamp", _lbase_clamp},
  {"floor", _lbase_floor},
  {"max", _lbase_max},
  {"min", _lbase_min},
  {"mod", _lbase_mod},
  {"pow", _lbase_pow},
  {"random", _lbase_random},
  {"round", _lbase_round},
  {"sign", _lbase_sign},
  {"sqrt", _lbase_sqrt}
};
#define MAX_SEXE_MATH_FUNCTIONS 12

void sexe_math_init(lua_State *L)
{
  int i;

  for (i = 0; i < MAX_SEXE_MATH_FUNCTIONS; i++) {
    lua_pushcfunction(L, sexe_math_funcs[i].func);
    lua_setglobal(L, sexe_math_funcs[i].name);
  }

}


