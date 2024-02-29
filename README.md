# csvg: C++ SVG Creation Library

`csvg`是一个轻量级的C++库，用于在C++程序中创建和输出SVG（Scalable Vector Graphics）文件。它提供了一个简单的API来添加各种SVG元素，如文本、线条、形状等，并将它们输出到一个SVG文件中。

## 安装/Installation

`csvg`是一个头文件库，无需安装即可使用。只需下载并将`csvg.h`包含到您的C++项目中。

`csvg` is a header file library, which means no compilation is required. Simply download and include the `csvg.h` file in your C++ project.

## 使用方法/Usage

1. **包含头文件/Include the Header File**:
   ```cpp
   #include "csvg.h"
   ```

2. **创建SVG对象/Create an SVG Object**:
   ```cpp
   my_svg_cpp::svg svg;
   ```

3. **添加SVG元素/Add SVG Elements**:
   ```cpp
   // 添加矩形 Add rectangle
   svg.add_rect(50, 50, 150, 100, my_svg_cpp::svg_color(255, 0, 0), my_svg_cpp::svg_color(0, 0, 0), 2);
   
   // 添加圆形 Add circle
   svg.add_circle(200, 200, 50, my_svg_cpp::svg_color(0, 255, 0), my_svg_cpp::svg_color(0, 0, 0), 2);
   
   // 添加文本 Add text
   svg.add_text("Hello, SVG!", 100, 140, my_svg_cpp::svg_color(0, 0, 0));
   ```

更多用法见文件夹`example`中的示例文件。

See the files in folder `example` for more usage.

4. **输出SVG文件/Output SVG File**：
   ```cpp
   svg.output("output.svg");
   ```

## 示例/Example

下面是一个简单的示例程序，它创建了一个包含文本、矩形和圆形的SVG文件。

Below is a simple example program that creates an SVG file containing text, a rectangle, and a circle.

```cpp
#include "csvg.h"

int main() {
    my_svg_cpp::svg svg;

    // 添加元素 Add elements
    svg.add_rect(50, 50, 150, 100, my_svg_cpp::svg_color(255, 0, 0), my_svg_cpp::svg_color(0, 0, 0), 2);
    svg.add_circle(200, 200, 50, my_svg_cpp::svg_color(0, 255, 0), my_svg_cpp::svg_color(0, 0, 0), 2);
    svg.add_text("Hello, SVG!", 100, 140, my_svg_cpp::svg_color(0, 0, 0));

    // 输出SVG文件 Output SVG file
    svg.output("example.svg");

    puts("SVG file 'example.svg' created successfully!");

    return 0;
}
```

## License

本项目采用**CC BY-SA 4.0**知识共享许可协议。如需了解该协议，请查阅[https://creativecommons.org/licenses/by-sa/4.0/deed.zh-hans](https://creativecommons.org/licenses/by-sa/4.0/deed.zh-hans)\
This work is licensed under CC BY-SA 4.0. To view a copy of this license, visit [http://creativecommons.org/licenses/by-sa/4.0/](http://creativecommons.org/licenses/by-sa/4.0/)
