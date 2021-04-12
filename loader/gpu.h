
#pragma once
#include <stdbool.h>
#include <stdint.h>

#define GPU_DISPLAY_H256 0
#define GPU_DISPLAY_H320 1
#define GPU_DISPLAY_H512 2
#define GPU_DISPLAY_H640 3

#define GPU_DISPLAY_V240 (0 << 2)
#define GPU_DISPLAY_V480 (1 << 2)

#define GPU_DISPLAY_NTSC (0 << 3)
#define GPU_DISPLAY_PAL  (1 << 3)

#define GPU_DISPLAY_15BPP (0 << 4)
#define GPU_DISPLAY_24BPP (1 << 4)

#define GPU_DISPLAY_INTERLACED (1 << 5)

struct gpu_point {
	uint16_t x;
	uint16_t y;
};

struct gpu_tex_rect {
	struct gpu_point pos;
	struct gpu_point texcoord;
	struct gpu_point clut;
	uint32_t color;
	uint16_t width;
	uint16_t height;
	uint8_t semi_transp;
	uint8_t raw_tex;
};

struct gpu_tex_poly {
	struct gpu_point vertex[4];
	struct gpu_point texcoord[4];
	struct gpu_point clut;
	struct gpu_point texpage;
	uint32_t color;
	uint8_t vertex_count;
	uint8_t semi_transp;
	uint8_t raw_tex;
};

void gpu_reset(void);

bool gpu_is_pal(void);

void gpu_display_enable(void);

void gpu_display_disable(void);

void gpu_display_mode(uint32_t mode);

void gpu_fill_rectangle(uint16_t x, uint16_t y, uint16_t width, uint16_t height, uint32_t rgb);

void gpu_copy_rectangle(uint16_t src_x, uint16_t src_y, uint16_t dest_x, uint16_t dest_y, uint16_t width, uint16_t height);

void gpu_draw_tex_rect(const struct gpu_tex_rect * rect);

void gpu_draw_tex_poly(const struct gpu_tex_poly * poly);

void gpu_set_drawing_area(uint_fast16_t x, uint_fast16_t y, uint_fast16_t width, uint_fast16_t height);

void gpu_flush_cache(void);

void gpu_set_hrange(uint_fast16_t x1, uint_fast16_t x2);

void gpu_set_vrange(uint_fast16_t y1, uint_fast16_t y2);

void gpu_init_bios(bool pal);