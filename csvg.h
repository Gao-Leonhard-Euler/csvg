#include<cstdlib>
#include<cstring>
#include<fstream>
#include<vector>
#include<string>
namespace my_svg_cpp{
	struct svg_color{
		uint8_t r,g,b;
		svg_color(uint8_t red=0,uint8_t green=0,uint8_t blue=0){
			r=red;g=green;b=blue;
		}
		std::string ColorToString()const{
			std::string s("#");
			s+=((r>>4)&15)+(((r>>4)&15)>9?'a'-10:'0');
			s+=(r&15)+((r&15)>9?'a'-10:'0');
			s+=((g>>4)&15)+(((g>>4)&15)>9?'a'-10:'0');
			s+=(g&15)+((g&15)>9?'a'-10:'0');
			s+=((b>>4)&15)+(((b>>4)&15)>9?'a'-10:'0');
			s+=(b&15)+((b&15)>9?'a'-10:'0');
			return s;
		}
	};
	class svg{
		public:
			struct text_rotate{
				uint16_t deg;int x,y;
				text_rotate(uint16_t d=0,int xi=0,int yi=0){
					deg=d;x=xi;y=yi;
				}
				std::string RotateToString()const{
					return std::string(" transform=\"rotate("+std::to_string(deg)+" "+std::to_string(x)+","+std::to_string(y)+")\" ");
				}
			};
		protected:
			std::vector<std::string> v,filter;
		public:
			void output(const char* const name="Untitled.svg")const{
				std::ofstream out(name,std::ios::out);
				out<<"<svg width=\"100\%\" height=\"100\%\" version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\">\n";
				for(int i=0,j=v.size();i<j;i++)out<<v[i];
				out<<"</svg>";
			}
			void add(const char* const s){
				v.push_back(std::string(s));
			}
			void add(std::string s){
				v.push_back(s);
			}
			void add_text(const char* const s,const unsigned int x=0,const unsigned int y=0,const svg_color col=svg_color()){
				std::string str("<text x=\""+std::to_string(x)+"\" y=\""+std::to_string(y)+"\" fill=\""+col.ColorToString()+"\">");
				str+=s;str+="</text>\n";
				v.push_back(str);
			}
			void add_text(const char* const s,const text_rotate tr,const unsigned int x=0,const unsigned int y=0,const svg_color col=svg_color()){
				std::string str("<text x=\""+std::to_string(x)+"\" y=\""+std::to_string(y)+"\" "+tr.RotateToString()+"fill=\""+col.ColorToString()+"\">");
				str+=s;str+="</text>\n";
				v.push_back(str);
			}
			void add_text(const std::string s,const unsigned int x=0,const unsigned int y=0,const svg_color col=svg_color()){
				std::string str("<text x=\""+std::to_string(x)+"\" y=\""+std::to_string(y)+"\" fill=\""+col.ColorToString()+"\">"+s+"</text>\n");
				v.push_back(str);
			}
			void add_text(const std::string s,const text_rotate tr,const unsigned int x=0,const unsigned int y=0,const svg_color col=svg_color()){
				std::string str("<text x=\""+std::to_string(x)+"\" y=\""+std::to_string(y)+"\" "+tr.RotateToString()+"fill=\""+col.ColorToString()+"\">"+s+"</text>\n");
				v.push_back(str);
			}
			void add_line(const unsigned int x1=0,const unsigned int y1=0,const unsigned int x2=0,const unsigned int y2=0,const svg_color col=svg_color(),const unsigned int width=1,const char* const linecap=0){
				std::string s("<line x1=\""+std::to_string(x1)+"\" y1=\""+std::to_string(y1)+"\" x2=\""+std::to_string(x2)+"\" y2=\""+std::to_string(y2)+"\" style=\"stroke:"+col.ColorToString()+";stroke-width:"+std::to_string(width));
				if(linecap){
					s+=";stroke-linecap:";s+=linecap;
				}
				s+="\"/>\n";
				v.push_back(s);
			}
			void add_circle(const unsigned int x=0,const unsigned int y=0,const unsigned int r=1,const svg_color fill=svg_color(),const svg_color edge=svg_color(),const unsigned int width=1){
				v.push_back(std::string("<circle cx=\""+std::to_string(x)+"\" cy=\""+std::to_string(y)+"\" r=\""+std::to_string(r)+"\" stroke-width=\""+std::to_string(width)+"\" stroke=\""+edge.ColorToString()+"\" fill=\""+fill.ColorToString()+"\"/>\n"));
			}
			void add_ellipse(const unsigned int x=0,const unsigned int y=0,const unsigned int rx=1,const unsigned int ry=1,const svg_color fill=svg_color(),const svg_color edge=svg_color(),const unsigned int width=1){
				v.push_back(std::string("<ellipse cx=\""+std::to_string(x)+"\" cy=\""+std::to_string(y)+"\" rx=\""+std::to_string(rx)+"\" ry=\""+std::to_string(ry)+"\" stroke-width=\""+std::to_string(width)+"\" stroke=\""+edge.ColorToString()+"\" fill=\""+fill.ColorToString()+"\"/>\n"));
			}
			void add_rect(const unsigned int x1=0,const unsigned int y1=0,const unsigned int x2=0,const unsigned int y2=0,const svg_color fill=svg_color(),const svg_color edge=svg_color(),const unsigned int width=1){
				v.push_back(std::string("<rect x=\""+std::to_string(x1)+"\" y=\""+std::to_string(y1)+"\" width=\""+std::to_string(x2-x1)+"\" height=\""+std::to_string(y2-y1)+"\" style=\"fill:"+fill.ColorToString()+";stroke:"+edge.ColorToString()+";stroke-width:"+std::to_string(width)+"\"/>\n"));
			}
	};
}
