#include"csvg.h"
using namespace my_svg_cpp;
int main(){
	svg x;
	x.add_ellipse(100.0,100.0,49.5,49.5,svg_color(0,102,102),svg_color(0,128,255),4.0);
	x.add_rect(75,80,125,120,svg_color(0,128,255),svg_color(102,204,255),3);
	x.add_line(10,10,10,110,svg_color(238,0,0),4,"round");
	x.add_line(175,10,175,110,svg_color(238,0,0),2);
	x.add_circle(100,100,5,svg_color(0,102,102),svg_color(102,204,255));
	x.add_text("Hello world!",30,25,svg_color(0,128,255));
	x.add_text("hello svg",svg::text_rotate<unsigned int>(15,240,120),30,200,svg_color(0,128,255));
	x.add_line(30,190,180,140,svg_color(0,102,102));
	x.output("Hello.svg");
	puts("\"Hello.svg\" created successfully!");
	return 0;
}
