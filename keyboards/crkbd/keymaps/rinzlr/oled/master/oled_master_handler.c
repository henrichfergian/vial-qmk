/* Copyright 2022 Jose Pablo Ramirez <jp.ramangulo@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
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

#include "rinzlr.h"
#include "indicators.h"

extern uint8_t logged_row, logged_col;
extern uint32_t oled_timer;
extern const uint8_t key_frame[4];

static uint32_t frame_limiter;

void oled_render_layer_state(void) {
    int current_layer_idx = get_highest_layer(layer_state | default_layer_state);
    static int current_frame = 0;
    static bool first_run = 1;

    if(first_run){
        first_run = 0;
        char clear[ANIM_SIZE] = {0};
        memset(clear, 0, ANIM_SIZE);
        oled_write_raw_P(clear, ANIM_SIZE);
        frame_limiter = timer_read();
        return;
    }

    if (timer_elapsed(frame_limiter) < 12) {
        return;
    }

    frame_limiter = timer_read();

    if(current_frame < key_frame[current_layer_idx]){
        current_frame = (current_frame + 1) % IDLE_FRAMES;
        change_frame_up(current_frame);
    }else  if(current_frame > key_frame[current_layer_idx]) {
        current_frame = (current_frame - 1) % IDLE_FRAMES;
        change_frame_down(IDLE_FRAMES - current_frame - 1);
    }

}

void render_master_oled() {
    if (timer_elapsed32(oled_timer) > CUSTOM_OLED_TIMEOUT) {
        oled_off();
        return;
    }

    oled_on();

    /* Render the layar state */
    oled_render_layer_state();

    /* Move cursor bellow the graphic */
    oled_set_cursor(0, 12);

    /* Print logged col and row
     * Format: 00x00
     */
    char logged_matrix[9] = {0};
    sprintf(logged_matrix, "%02dx%02d", logged_col, logged_row);

    /* Write a separator char: ◆,
     * make sure to add a NULL terminator otherwise strlen could fail
     */
    static const char PROGMEM separator[] = {4, 4, 4, 4, 4, 0};
    oled_write(separator, false);

    /* Write logged matrix position */
    oled_write(logged_matrix, false);

    /* Write another separator */
    oled_write(separator, false);

    /* Write scanrate */
    oled_write(get_u16_str(get_matrix_scan_rate(), ' '), false);
}
