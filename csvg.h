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
			template<class number=unsigned int>
			struct text_rotate{
				number deg,x,y;
				text_rotate(number d=0,number xi=0,number yi=0){
					deg=d;x=xi;y=yi;
				}
				std::string RotateToString()const{
					return std::string(" transform=\"rotate("+std::to_string(deg)+" "+std::to_string(x)+","+std::to_string(y)+")\" ");
				}
			};
		protected:
			std::vector<std::string> v;
		public:
			void output(const char* const name="Untitled.svg",unsigned int width=100,unsigned int height=100)const{
				std::ofstream out(name,std::ios::out);
				out<<"<svg width=\""<<std::to_string(width)<<"\%\" height=\""<<std::to_string(height)<<"\%\" version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\">\n";
				for(unsigned int i=0,j=v.size();i<j;i++)out<<v[i];
				out<<"</svg>";
			}
			void add(const char* const s){
				v.push_back(std::string(s));
			}
			void add(std::string s){
				v.push_back(s);
			}
			template<class number=unsigned int>
			void add_text(const char* const s,const number x=0,const number y=0,const svg_color col=svg_color()){
				std::string str("<text x=\""+std::to_string(x)+"\" y=\""+std::to_string(y)+"\" fill=\""+col.ColorToString()+"\">");
				str+=s;str+="</text>\n";
				v.push_back(str);
			}
			template<class number=unsigned int,class num=unsigned int>
			void add_text(const char* const s,const text_rotate<num> tr,const number x=0,const number y=0,const svg_color col=svg_color()){
				std::string str("<text x=\""+std::to_string(x)+"\" y=\""+std::to_string(y)+"\" "+tr.RotateToString()+"fill=\""+col.ColorToString()+"\">");
				str+=s;str+="</text>\n";
				v.push_back(str);
			}
			template<class number=unsigned int>
			void add_text(const std::string s,const number x=0,const number y=0,const svg_color col=svg_color()){
				std::string str("<text x=\""+std::to_string(x)+"\" y=\""+std::to_string(y)+"\" fill=\""+col.ColorToString()+"\">"+s+"</text>\n");
				v.push_back(str);
			}
			template<class number=unsigned int,class num=unsigned int>
			void add_text(const std::string s,const text_rotate<num> tr,const number x=0,const number y=0,const svg_color col=svg_color()){
				std::string str("<text x=\""+std::to_string(x)+"\" y=\""+std::to_string(y)+"\" "+tr.RotateToString()+"fill=\""+col.ColorToString()+"\">"+s+"</text>\n");
				v.push_back(str);
			}
			template<class number=unsigned int>
			void add_line(const number x1=0,const number y1=0,const number x2=0,const number y2=0,const svg_color col=svg_color(),const number width=1,const char* const linecap=0){
				std::string s("<line x1=\""+std::to_string(x1)+"\" y1=\""+std::to_string(y1)+"\" x2=\""+std::to_string(x2)+"\" y2=\""+std::to_string(y2)+"\" style=\"stroke:"+col.ColorToString()+";stroke-width:"+std::to_string(width));
				if(linecap){
					s+=";stroke-linecap:";s+=linecap;
				}
				s+="\"/>\n";
				v.push_back(s);
			}
			template<class number=unsigned int>
			void add_circle(const number x=0,const number y=0,const number r=1,const svg_color fill=svg_color(),const svg_color edge=svg_color(),const number width=1){
				v.push_back(std::string("<circle cx=\""+std::to_string(x)+"\" cy=\""+std::to_string(y)+"\" r=\""+std::to_string(r)+"\" stroke-width=\""+std::to_string(width)+"\" stroke=\""+edge.ColorToString()+"\" fill=\""+fill.ColorToString()+"\"/>\n"));
			}
			template<class number=unsigned int>
			void add_ellipse(const number x=0,const number y=0,const number rx=1,const number ry=1,const svg_color fill=svg_color(),const svg_color edge=svg_color(),const number width=1){
				v.push_back(std::string("<ellipse cx=\""+std::to_string(x)+"\" cy=\""+std::to_string(y)+"\" rx=\""+std::to_string(rx)+"\" ry=\""+std::to_string(ry)+"\" stroke-width=\""+std::to_string(width)+"\" stroke=\""+edge.ColorToString()+"\" fill=\""+fill.ColorToString()+"\"/>\n"));
			}
			template<class number=unsigned int>
			void add_rect(const number x1=0,const number y1=0,const number x2=0,const number y2=0,const svg_color fill=svg_color(),const svg_color edge=svg_color(),const number width=1){
				v.push_back(std::string("<rect x=\""+std::to_string(x1)+"\" y=\""+std::to_string(y1)+"\" width=\""+std::to_string(x2-x1)+"\" height=\""+std::to_string(y2-y1)+"\" style=\"fill:"+fill.ColorToString()+";stroke:"+edge.ColorToString()+";stroke-width:"+std::to_string(width)+"\"/>\n"));
			}
	};
}
