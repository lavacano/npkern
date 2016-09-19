
#include "stypes.h"

/* (c) copyright fenugrec 2016
 * GPLv3
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */



/* built-in EEPROM read function in stock ROM */
/* this assumes the compiler ABI matches the stock ROM, i.e. input args in r4, r5 */
static void (*builtin_eep_read16)(uint8_t addr, uint16_t *dest) = 0;


void eep_read16(uint8_t addr, uint16_t *dest) {
	if (builtin_eep_read16 == 0) return;
	builtin_eep_read16(addr, dest);
	return;
}

//set the address of the ROM's eeprom_read function
void eep_setptr(void *newaddr) {
	builtin_eep_read16 = newaddr;
	return;
}
