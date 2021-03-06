OpenGL ES 2.0 渲染管线
===

## OpenGL 渲染管线流程

Opengl es 2.0实现了可编程的图形管线，比起1.x的固定管线要复杂和灵活很多，
由两部分规范组成：Opengl es 2.0 API规范和Opengl es着色语言规范。

下图是Opengl es 2.0渲染管线，阴影部分是opengl es 2.0的可编程阶段。

![OpenGL Graphics Pipeline](./src/OpenGL_Graphics_Pipeline.png)

## 渲染管线着色器以及各个阶段 

### 1. 顶点着色器(VertexShader)

顶点着色器对顶点实现了一种通用的可编程方法。
顶点着色器的输入数据由下面组成：

* `Attributes`：使用顶点数组封装每个顶点的数据，一般用于每个顶点都各不相同的变量，如顶点位置、颜色等。
* `Uniforms`：顶点着色器使用的常量数据，不能被着色器修改，一般用于对同一组顶点组成的单个3D物体中所有顶点都相同的变量，如当前光源的位置。
* `Samplers`：这个是可选的，一种特殊的uniforms，表示顶点着色器使用的纹理。
* `Shader Program`：顶点着色器的源码或可执行文件，描述了将对顶点执行的操作。

顶点着色器的输出数据是`varying`变量，在图元光栅化阶段，这些`varying`值为每个生成的片元进行计算，并将结果作为片元着色器的输入数据。
从分配给每个顶点的原始`varying`值来为每个片元生成一个`varying`值的机制叫做插值。

顶点着色器数据的输入和输出可以参考下图：

![OpenGL Vertex SHader](./src/OpenGL_Vertex_Shader.png)

顶点着色器可用于传统的基于顶点的操作，例如：
基于矩阵变换位置，进行光照计算来生成每个顶点的颜色，生成或者变换纹理坐标。
另外因为顶点着色器是由应用程序指定的，所以你可以用来进行任意自定义的顶点变换。
下面是一个用openGL ES着色器语言编写的顶点着色器源码，
这个顶点着色器使用一个`position`和跟它相关联的`color`数据作为输入数据，
通过一个4×4矩阵变换位置，然后输出变换后的位置和颜色数据。

```
// uniforms used by the vertex shader
uniform mat4 u_mvpMatrix; // matrix to convert P from model
// space to normalized device space.

// attributes input to the vertex shader
attribute vec4 a_position; // position value
attribute vec4 a_color; // input vertex color

// varying variables – input to the fragment shader
varying vec4 v_color; // output vertex color

void main()
{
    v_color = a_color;
    gl_Position = u_mvpMatrix * a_position;
}
```

* 第2行代码定义了一个`uniform`变量`u_mvpMatrix`，`mat4`表示4×4浮点数矩阵，该变量存储了组合模型视图和投影矩阵。
* 第6和7行代码定义了顶点着色器的输入数据：`Attributes`，`vec4`表示包含了4个浮点数的向量，`a_position`是顶点位置属性，`a_color`是顶点颜色属性。
* 第10行代码定义了`varying`类型的变量`v_color`，`varying`是用于从顶点着色器传递到片元着色器的变量，`v_color`是顶点着色器的输出数据，存储了每个顶点的颜色。
* 第12到17行的`main`函数是顶点着色器和片元着色器的入口，第15行读取了顶点着色器输入属性中`a_color`的值，并把它赋值给输出数据`v_color`，
* 第16行的`gl_Position`是内置的`varying`变量，不需要声明，顶点着色器必须把变换后的位置赋值给它。

### 2.图元装配(Primitive Assembly)

顶点着色器之后，渲染流水线的下一个阶段是图元装配，图元是一个能用openGL ES绘图命令绘制的几何体，
绘图命令指定了一组顶点属性，描述了图元的几何形状和图元类型。顶点着色器使用这些顶点属性计算顶点的位置、颜色以及纹理坐标，这样才能传到片元着色器。

在图元装配阶段，这些着色器处理过的顶点被组装到一个个独立的几何图元中，
例如:
* 三角形
* 线
* 点精灵

对于每个图元，必须确定它是否位于视椎体内(3维空间显示在屏幕上的可见区域)，
如果图元部分在视椎体中，需要进行裁剪，如果图元全部在视椎体外，则直接丢弃图元。
裁剪之后，顶点位置转换成了屏幕坐标。背面剔除操作也会执行，它根据图元是正面还是背面，如果是背面则丢弃该图元。经过裁剪和背面剔除操作后，就进入渲染流水线的下一个阶段：光栅化。

### 3. 光栅化(Rasterization)

光栅化阶段把图元转换成片元集合，之后会提交给片元着色器处理，这些片元集合表示可以被绘制到屏幕的像素。

如下图所示：

![OpenGL Rasterization Stage](./src/OpenGL_ES_Rasterization_Stage.png)
 
### 4. 片元着色器(FragmentShader)

片元着色器对片元实现了一种通用的可编程方法，它对光栅化阶段产生的每个片元进行操作，需要的输入数据如下：
* `Varying variables`：顶点着色器输出的`varying`变量经过光栅化插值计算后产生的作用于每个片元的值。
* `Uniforms`：片元着色器使用的常量数据
* `Samplers`：一种特殊的`uniforms`，表示片元着色器使用的纹理。
* `Shader Program`：片元着色器的源码或可执行文件，描述了将对片元执行的操作。

片元着色器也可以丢弃片元或者为片元生成一个颜色值，保存到内置变量`gl_FragColor`。
光栅化阶段产生的颜色、深度、模板和屏幕坐标(Xw, Yw)成为流水线中pre-fragment阶段(FragmentShader之后)的输入。

如下图：

![OpenGL_Fragment_Shader](./src/OpenGL_Fragment_Shader.png)

下面是一个简单的片元着色器源码，可以跟上面的顶点着色器源码结合绘制一个高洛德着色的三角形。

```
precision mediump float;

varying vec4 v_color; // input vertex color from vertex shader

void main(void)
{
    gl_FragColor = v_color;
}
```

* 第1行代码设置默认的精度修饰符，有`highp、mediump、lowp`，这个后面再详细解释。
* 第3行代码定义了片元着色器的输入数据，顶点着色器必须赋值给片元着色器一组一样的`varying`变量。注意：`gl_FragColor`是片元着色器唯一的输出。
* 第9行代码把输入数据`v_color`赋值给`gl_FragColor`。

### 5. 逐个片元操作阶段(Per-Fragment Operations)

片元着色器之后就是逐个片元操作阶段，包括一系列的测试阶段。
一个光栅化阶段产生的具有屏幕坐标(Xw, Yw)的片元，只能修改framebuffer(帧缓冲)中位置在(Xw, Yw)的像素。

下图是Opengl es 2.0逐片元操作的过程：

![OpenGL_Pre-Fragment_Operations](./src/OpenGL_Pre-Fragment_Operations.png)

* `Pixel ownership test`：像素所有权测试决定framebuffer中某一个(Xw, Yw)位置的像素是否属于当前Opengl ES的context，比如：如果一个Opengl ES帧缓冲窗口被其他窗口遮住了，窗口系统将决定被遮住的像素不属于当前Opengl ES的context，因此也就不会被显示。
* `Scissor test`：裁剪测试决定位置为(Xw, Yw)的片元是否位于裁剪矩形内，如果不在，则被丢弃。
* `Stencil and depth tests`：模板和深度测试传入片元的模板和深度值，决定是否丢弃片元。
* `Blending`：将新产生的片元颜色值和framebuffer中某个(Xw, Yw)位置存储的颜色值进行混合。
* `Dithering`：抖动可以用来最大限度的减少使用有限精度存储颜色值到framebuffer的工件。

逐片元操作之后，片元要么被丢弃，要么一个片元的颜色，深度或者模板值被写入到framebuffer的(Xw, Yw)位置，
不过是否真的会写入还得依赖于`write masks`启用与否。`write masks`能更好的控制颜色、深度和模板值写入到合适的缓冲区。例如：颜色缓冲区中的write mask可以被设置成没有红色值写入到颜色缓冲区。

另外，OpenGL ES 2.0提供从framebuffer中获取像素的接口，不过需要记住的是像素只能从颜色缓冲区读回，深度和模板值不能读回。

注意：OpenGL ES 2.0的Per-Fragment Operations已经不再支持Alpha test 和 LogicOp了，这两个步骤在 OpenGL 2.0 和 OpenGL ES 1.x中是存在的。Alpha test 阶段不再需要的原因是片元着色器可以丢弃片元，所以可以在片元着色器中执行Alpha test。 LogicOp因为很少使用，所以不再支持了。