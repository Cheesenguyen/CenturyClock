#include <stdint.h>
#include "../inc/ecall.h"


void ECALL_100(uint32_t position, uint32_t color){
    // giải mã tọa độ từ position
    uint16_t x = (position >> 16) & 0xFFFF;
    uint16_t y = position & 0xFFFF;          // hàng

    // Giải mã màu từ color (0x00RRGGBB)
    uint8_t r = (color >> 16) & 0xFF;
    uint8_t g = (color >> 8) & 0xFF;
    uint8_t b = color & 0xFF;

    // Giới hạn terminal mặc định: 120x40 (có thể chỉnh)
    if (x >= 120 || y >= 40) {
        return; // bỏ qua pixel ngoài màn hình
    }

    // In pixel tại (x,y)
    // Trình tự: lưu vị trí -> nhảy -> in màu -> reset -> khôi phục
    printf("\033[s"); // save cursor
    printf("\033[%u;%uH", y + 1, x + 1); // move cursor (1-based)
    printf("\033[48;2;%u;%u;%um█\033[0m", r, g, b); // set background color + block
    printf("\033[u"); // restore cursor

}

