/*
Copyright 2019 Josh Johnson

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once


#define MATRIX_ROW_PINS \
    { F0, C7, C6, B6, E6}
#define MATRIX_COL_PINS \
    { F4, F1, D5, D3 }

/* COL2ROW, ROW2COL*/
#define DIODE_DIRECTION COL2ROW

#define MOUSEKEY_DELAY          0
#define MOUSEKEY_INTERVAL       16
#define MOUSEKEY_TIME_TO_MAX    0
#define MOUSEKEY_MAX_SPEED      5
#define MOUSEKEY_WHEEL_MAX_SPEED 2
#define MOUSEKEY_WHEEL_TIME_TO_MAX 0
#define TAPPING_TERM 100