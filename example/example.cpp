#include"csvg.h"
int main() {
    my_svg_cpp::svg svg;
    //add shapes
    svg.add_rect(50, 50, 150, 100, my_svg_cpp::svg_color(255, 0, 0), my_svg_cpp::svg_color(0, 0, 0), 2);
    svg.add_circle(200, 200, 50, my_svg_cpp::svg_color(0, 255, 0), my_svg_cpp::svg_color(0, 0, 0), 2);
    svg.add_text("Hello, SVG!", 100, 140, my_svg_cpp::svg_color(0, 0, 0));
    //creat SVG files
    svg.output("example.svg");
    puts("SVG file 'example.svg' created successfully!");
    return 0;
}
