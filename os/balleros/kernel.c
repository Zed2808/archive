#if !defined(__cplusplus)
#include <stdbool.h> /* C doesn't have booleans by default. */
#endif
#include <stddef.h>
#include <stdint.h>

/*
 * Check if the compiler thinks if we are targeting the wrong operating
 * system.
 */
#if defined(__linux__)
#error "You are not using a cross-compiler, you will most certainly run into trouble"
#endif

/* This tutorial will only work for the 32-bit ix86 targets. */
#if !defined(__i386__)
#error "This tutorial needs to be compiled with an ix86-elf compiler"
#endif

/* Hardware text mode color constants. */
enum vga_color {
	COLOR_BLACK = 0,
	COLOR_BLUE = 1,
	COLOR_GREEN = 2,
	COLOR_CYAN = 3,
	COLOR_RED = 4,
	COLOR_MAGENTA = 5,
	COLOR_BROWN = 6,
	COLOR_LIGHT_GREY = 7,
	COLOR_DARK_GREY = 8,
	COLOR_LIGHT_BLUE = 9,
	COLOR_LIGHT_GREEN = 10,
	COLOR_LIGHT_CYAN = 11,
	COLOR_LIGHT_RED = 12,
	COLOR_LIGHT_MAGENTA = 13,
	COLOR_LIGHT_BROWN = 14,
	COLOR_WHITE = 15,
};

uint8_t make_color(enum vga_color fg, enum vga_color bg) {
	return fg | bg << 4;
}

uint16_t make_vgaentry(char c, uint8_t color) {
	uint16_t c16 = c;
	uint16_t color16 = color;
	return c16 | color16 << 8;
}

size_t strlen(const char* str) {
	size_t ret = 0;
	while (str[ret] != 0 )
		ret++;
	return ret;
}

static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 25;

size_t terminal_row;
size_t terminal_column;
uint8_t terminal_color;
uint16_t* terminal_buffer;

void terminal_initialize() {
	terminal_row = 0;
	terminal_column = 0;
	terminal_color = make_color(COLOR_LIGHT_GREY, COLOR_BLACK);
	terminal_buffer = (uint16_t*) 0xB8000;
	for ( size_t y = 0; y < VGA_HEIGHT; y++ ) {
		for ( size_t x = 0; x < VGA_WIDTH; x++ ) {
			const size_t index = y * VGA_WIDTH + x;
			terminal_buffer[index] = make_vgaentry(' ', terminal_color);
		}
	}
}

void terminal_setcolor(uint8_t color) {
	terminal_color = color;
}

void terminal_putentryat(char c, uint8_t color, size_t x, size_t y) {
	const size_t index = y * VGA_WIDTH + x;
	terminal_buffer[index] = make_vgaentry(c, color);
}

void terminal_putchar(char c) {
	terminal_putentryat(c, terminal_color, terminal_column, terminal_row);
	if ( ++terminal_column == VGA_WIDTH ) {
		terminal_column = 0;
		if ( ++terminal_row == VGA_HEIGHT ) {
			terminal_row = 0;
		}
	}
}

void terminal_writestring(const char* data) {
	size_t datalen = strlen(data);
	for ( size_t i = 0; i < datalen; i++ ) {
		if ( data[i] == '\n' ) {
			terminal_column = 0;
			++terminal_row;
		} else {
			terminal_putchar(data[i]);
		}
	}
}

void terminal_setcoords(size_t y, size_t x) {
	terminal_row = y;
	terminal_column = x;
}

void terminal_drawbear(size_t y, size_t x) {
	// Light brown
	terminal_setcoords(y+1, x+1);
	terminal_setcolor(make_color(COLOR_MAGENTA, COLOR_LIGHT_BROWN));
	terminal_writestring("  ");
	terminal_setcoords(y+1, x+11);
	terminal_setcolor(make_color(COLOR_MAGENTA, COLOR_LIGHT_BROWN));
	terminal_writestring("  ");
	terminal_setcoords(y+2, x+1);
	terminal_setcolor(make_color(COLOR_MAGENTA, COLOR_LIGHT_BROWN));
	terminal_writestring("            ");
	terminal_setcoords(y+3, x+3);
	terminal_setcolor(make_color(COLOR_MAGENTA, COLOR_LIGHT_BROWN));
	terminal_writestring("        ");
	terminal_setcoords(y+4, x+3);
	terminal_setcolor(make_color(COLOR_MAGENTA, COLOR_LIGHT_BROWN));
	terminal_writestring("        ");
	terminal_setcoords(y+5, x+2);
	terminal_setcolor(make_color(COLOR_MAGENTA, COLOR_LIGHT_BROWN));
	terminal_writestring("          ");
	terminal_setcoords(y+6, x+2);
	terminal_setcolor(make_color(COLOR_MAGENTA, COLOR_LIGHT_BROWN));
	terminal_writestring("          ");
	terminal_setcoords(y+7, x+2);
	terminal_setcolor(make_color(COLOR_MAGENTA, COLOR_LIGHT_BROWN));
	terminal_writestring("          ");
	terminal_setcoords(y+8, x+3);
	terminal_setcolor(make_color(COLOR_MAGENTA, COLOR_LIGHT_BROWN));
	terminal_writestring("        ");
	// Black
	terminal_setcoords(y, x+1);
	terminal_setcolor(make_color(COLOR_MAGENTA, COLOR_BLACK));
	terminal_writestring("  ");
	terminal_setcoords(y, x+11);
	terminal_setcolor(make_color(COLOR_MAGENTA, COLOR_BLACK));
	terminal_writestring("  ");
	terminal_setcoords(y+1, x);
	terminal_setcolor(make_color(COLOR_MAGENTA, COLOR_BLACK));
	terminal_writestring(" ");
	terminal_setcoords(y+1, x+3);
	terminal_setcolor(make_color(COLOR_MAGENTA, COLOR_BLACK));
	terminal_writestring(" ");
	terminal_setcoords(y+1, x+5);
	terminal_setcolor(make_color(COLOR_MAGENTA, COLOR_BLACK));
	terminal_writestring("    ");
	terminal_setcoords(y+1, x+10);
	terminal_setcolor(make_color(COLOR_MAGENTA, COLOR_BLACK));
	terminal_writestring(" ");
	terminal_setcoords(y+1, x+13);
	terminal_setcolor(make_color(COLOR_MAGENTA, COLOR_BLACK));
	terminal_writestring(" ");
	terminal_setcoords(y+2, x);
	terminal_setcolor(make_color(COLOR_MAGENTA, COLOR_BLACK));
	terminal_writestring(" ");
	terminal_setcoords(y+2, x+3);
	terminal_setcolor(make_color(COLOR_MAGENTA, COLOR_BLACK));
	terminal_writestring("  ");
	terminal_setcoords(y+2, x+9);
	terminal_setcolor(make_color(COLOR_MAGENTA, COLOR_BLACK));
	terminal_writestring("  ");
	terminal_setcoords(y+2, x+13);
	terminal_setcolor(make_color(COLOR_MAGENTA, COLOR_BLACK));
	terminal_writestring(" ");
	terminal_setcoords(y+3, x+1);
	terminal_setcolor(make_color(COLOR_MAGENTA, COLOR_BLACK));
	terminal_writestring("  ");
	terminal_setcoords(y+3, x+11);
	terminal_setcolor(make_color(COLOR_MAGENTA, COLOR_BLACK));
	terminal_writestring("  ");
	terminal_setcoords(y+4, x+2);
	terminal_setcolor(make_color(COLOR_MAGENTA, COLOR_BLACK));
	terminal_writestring(" ");
	terminal_setcoords(y+4, x+11);
	terminal_setcolor(make_color(COLOR_MAGENTA, COLOR_BLACK));
	terminal_writestring(" ");
	terminal_setcoords(y+5, x+1);
	terminal_setcolor(make_color(COLOR_MAGENTA, COLOR_BLACK));
	terminal_writestring(" ");
	terminal_setcoords(y+5, x+5);
	terminal_setcolor(make_color(COLOR_MAGENTA, COLOR_BLACK));
	terminal_writestring(" ");
	terminal_setcoords(y+5, x+9);
	terminal_setcolor(make_color(COLOR_MAGENTA, COLOR_BLACK));
	terminal_writestring(" ");
	terminal_setcoords(y+5, x+12);
	terminal_setcolor(make_color(COLOR_MAGENTA, COLOR_BLACK));
	terminal_writestring(" ");
	terminal_setcoords(y+6, x+1);
	terminal_setcolor(make_color(COLOR_MAGENTA, COLOR_BLACK));
	terminal_writestring(" ");
	terminal_setcoords(y+6, x+4);
	terminal_setcolor(make_color(COLOR_MAGENTA, COLOR_BLACK));
	terminal_writestring("  ");
	terminal_setcoords(y+6, x+8);
	terminal_setcolor(make_color(COLOR_MAGENTA, COLOR_BLACK));
	terminal_writestring("  ");
	terminal_setcoords(y+6, x+12);
	terminal_setcolor(make_color(COLOR_MAGENTA, COLOR_BLACK));
	terminal_writestring(" ");
	terminal_setcoords(y+7, x+1);
	terminal_setcolor(make_color(COLOR_MAGENTA, COLOR_BLACK));
	terminal_writestring(" ");
	terminal_setcoords(y+7, x+12);
	terminal_setcolor(make_color(COLOR_MAGENTA, COLOR_BLACK));
	terminal_writestring(" ");
	terminal_setcoords(y+8, x+2);
	terminal_setcolor(make_color(COLOR_MAGENTA, COLOR_BLACK));
	terminal_writestring(" ");
	terminal_setcoords(y+8, x+11);
	terminal_setcolor(make_color(COLOR_MAGENTA, COLOR_BLACK));
	terminal_writestring(" ");
	terminal_setcoords(y+9, x+3);
	terminal_setcolor(make_color(COLOR_MAGENTA, COLOR_BLACK));
	terminal_writestring("        ");
	// Light magenta
	terminal_setcoords(y+2, x+2);
	terminal_setcolor(make_color(COLOR_MAGENTA, COLOR_LIGHT_MAGENTA));
	terminal_writestring(" ");
	terminal_setcoords(y+2, x+11);
	terminal_setcolor(make_color(COLOR_MAGENTA, COLOR_LIGHT_MAGENTA));
	terminal_writestring(" ");
	terminal_setcoords(y+6, x+3);
	terminal_setcolor(make_color(COLOR_MAGENTA, COLOR_LIGHT_MAGENTA));
	terminal_writestring(" ");
	terminal_setcoords(y+6, x+10);
	terminal_setcolor(make_color(COLOR_MAGENTA, COLOR_LIGHT_MAGENTA));
	terminal_writestring(" ");
	// White
	terminal_setcoords(y+5, x+4);
	terminal_setcolor(make_color(COLOR_MAGENTA, COLOR_WHITE));
	terminal_writestring(" ");
	terminal_setcoords(y+5, x+8);
	terminal_setcolor(make_color(COLOR_MAGENTA, COLOR_WHITE));
	terminal_writestring(" ");
}

#if defined(__cplusplus)
extern "C" /* Use C linkage for kernel_main. */
#endif
void kernel_main() {
	terminal_initialize();
	for ( size_t i = 0; i < (VGA_HEIGHT * VGA_WIDTH); i++ ) {
		terminal_setcolor(make_color(COLOR_LIGHT_BROWN, COLOR_MAGENTA));
		terminal_writestring(" ");
	}
	terminal_setcoords(1, 30);
	terminal_writestring("Welcome to BallerOS!");
	terminal_setcoords(14, 29);
	terminal_writestring("I hope you like BALLS!");
	terminal_drawbear(3, 33);

	terminal_setcoords(22, 0);
	terminal_setcolor(make_color(COLOR_WHITE, COLOR_MAGENTA));
	terminal_writestring("Line 1!\nLine 2!\nCheck out those newlines!");
}
