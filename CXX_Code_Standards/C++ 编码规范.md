# C++ 项目编码指南

<!-- TOC -->

- [C++ 项目编码指南](#c-项目编码指南)
    - [背景](#背景)
    - [命名约定](#命名约定)
    - [代码排版](#代码排版)
        - [缩进](#缩进)
        - [间隔](#间隔)
        - [大括号](#大括号)
        - [注释](#注释)
    - [头文件与源文件](#头文件与源文件)
        - [防止多重包含的方法](#防止多重包含的方法)
        - [减少头文件依赖的方法](#减少头文件依赖的方法)
        - [包含文件的名称及顺序](#包含文件的名称及顺序)
    - [作用域](#作用域)
        - [命名空间](#命名空间)
        - [全局变量](#全局变量)
    - [类](#类)
        - [成员函数约定](#成员函数约定)
        - [成员变量约定](#成员变量约定)
        - [特殊成员函数](#特殊成员函数)
        - [继承与组合](#继承与组合)
        - [友元](#友元)
    - [函数](#函数)
        - [使用内联函数提高函数的执行速度](#使用内联函数提高函数的执行速度)
        - [控制函数规模](#控制函数规模)
        - [函数指针](#函数指针)

<!-- /TOC -->

## 背景

C++具有很多强大的语言特性，但这种强大，不可避免地导致它的复杂，而复杂性会使得项目代码容易出现Bug，以致于难以阅读和维护。本指南的目的是详细阐述如何进行C++编码来规避其复杂性，使得代码在有效使用C++特性的同时还易于阅读和管理。因此，我们需要增强代码一致性，通过统一的一致性规则增强代码的可读性。

---

## 命名约定

函数命名、变量命名、文件命名应具有描述性，合理的命名可以减少注释的使用，增加代码的可读性。因此需要遵守以下的约定：

1. 命名空间名、类名、结构体类型名、枚举类型名采用大写首字母的名词进行命名，命名中的其他单词首字母必须使用大写字母，**不得使用下划线进行分割**，如：`using namespace CGL`，使用`FileOperator`而不是`fileoperator`或者`File_Openrator`等。
2. 函数名、变量名采用小写首字母的名词进行命名，命名中的各单词采用单下划线进行分割，命名中的各单词均采用小写首字母，如：`void open_file()`和`file_operator`等。
3. 宏、枚举值、常量名采用全大写字母进行命名，各单词之间采用下划线进行分割，如`INT_MAX`，`STACK_OVER_FLOW`等。

针对变量和函数出现的位置需要遵守如下约定：

4. 类中的私有变量，私有函数，保护函数，保护变量，必须以下划线开头，接2.中的规则。如：`_save_path`，全局变量采用`global_`前缀进行修饰。
5. 类中的对可设置的变量的存取函数，在2.的基础上，使用`set`前缀对需要设置的变量进行修饰，对需要取得变量，将下划线去掉。如：对于成员变量`_time`，`set_time()`、`time()`等。
6. 在5.的基础上，类中的只读变量的取函数不需要使用`get`前缀进行修饰。

对类型进行重命名的命名约定：

7. 当我们使用`typedef`或者`using`对命名空间或者类型进行重命名时，我们要求重新的命名需要遵循1.的规则。示例如下：
```
using TriMesh = CGL::Mesh<3>;
// 等价于
typedef CGL::Mesh<3> TriMesh;
```

对使用模版的类或者函数的命名约定：

7. `typename`之后的类型名应当遵循1.的规则，对于输入常数的模版，该常数的命名遵循3.的规则。示例如下：
```
template<typename ValType, int NUM>
class Normal
{
    ...
};
```

对于头文件源文件的命名约定：

8. 头文件使用该文件的模块名进行命名，要么是命名空间名，要么是类名；源文件使用对应头文件的名称，对于存放内联函数实现的源文件添加后缀`_Inline`，举例：
```
ClassA的头文件名称为：ClassA.h
ClassA的源文件名称为：ClassA.cpp
ClassA的内联函数源文件名称为: ClassA_Inline.cpp
```

---

## 代码排版

统一的排版可以减少合并代码时碰到的问题，还能够使代码美观。我们的风格是**宽松**，而不是紧凑，因此我们这里规定了诸如大括号换行，功能段落应当使用空行进行间隔。

所有代码文件，必须使用UTF-8格式进行保存。代码查看建议字体为：`Courier New`，字体大小自行设置不作要求。

编码风格我们希望尽可能与STL、Boost等标准库的风格相衔接，而又有所区别，所以我们对类的声明风格进行了区别，而不是使用STL等标准库的风格。

与此同时，我们希望如果自行实现某个容器，需要能够与标准库函数能够衔接使用，即需要实现分配器、迭代器等类型，以及如`clear()`、`size()`等标准库函数都拥有的含义。

C++最强大的功能之一就是模板，我们希望摈弃C的一些思想，对于算法以及容器推荐使用模版进行抽象化。在后面我们对模板进行专门的规定。

### 缩进

在缩进方面，我们需要遵守如下约定：
1. Tab符占4个空格，且将Tab符转换为空格。如此在各种平台上的编辑器上查看代码，代码格式都不会发生变化。
2. 1行代码的长度尽可能不要超过80个字符(超出几个到十几个也是可以的)，如果明显超过110个字符且该行可分割，需要进行换行，同一句代码换行之后应当与首行保持4个空格的缩进，示例如下：
```
if (!OpenMesh::IO::write_mesh(mesh, "output.obj"))
{
    std::cerr << "Cannot write mesh to file 'output.off', So you need check your code." << std::endl;
    return 1;
}
// 应当如下换行：
if (!OpenMesh::IO::write_mesh(mesh, "output.obj"))
{
    std::cerr <<
            "Cannot write mesh to file 'output.off', So you need check your code." << std::endl;
    return 1;
}
```
3. 一个文件的缩进层级应当是：最外层为namespace，然后是class或者function，举例如下：
```
#ifndef OPENMESH_MESHCHECKER_HH
#define OPENMESH_MESHCHECKER_HH

#include <OpenMesh/Core/System/config.h>
#include <OpenMesh/Core/System/omstream.hh>
#include <OpenMesh/Core/Utils/GenProg.hh>
#include <OpenMesh/Core/Mesh/Attributes.hh>
#include <ostream>

namespace OpenMesh 
{
    namespace Utils 
    {
       
        /** Check integrity of mesh.
         *
         *  This class provides several functions to check the integrity of a mesh.
         */
        template <class Mesh>
        class MeshCheckerT
        {
        public:

            /// constructor
            MeshCheckerT(const Mesh& _mesh) : mesh_(_mesh) {}

            /// destructor
            ~MeshCheckerT() {}

            /// what should be checked?
            enum CheckTargets
            {
                CHECK_EDGES = 1,
                CHECK_VERTICES = 2,
                CHECK_FACES = 4,
                CHECK_ALL = 255
            };

            /// check it, return true iff ok
            bool check(unsigned int _targets = CHECK_ALL,
                std::ostream&  _os = omerr());

        private:

            bool is_deleted(typename Mesh::VertexHandle _vh)
            {
                return (mesh_.has_vertex_status() ? mesh_.status(_vh).deleted() : false);
            }

            bool is_deleted(typename Mesh::EdgeHandle _eh)
            {
                return (mesh_.has_edge_status() ? mesh_.status(_eh).deleted() : false);
            }

            bool is_deleted(typename Mesh::FaceHandle _fh)
            {
                return (mesh_.has_face_status() ? mesh_.status(_fh).deleted() : false);
            }

            // ref to mesh
            const Mesh&  mesh_;
        };
    } // namespace Utils
} // namespace OpenMesh

#if defined(OM_INCLUDE_TEMPLATES) && !defined(OPENMESH_MESHCHECKER_C)
#define OPENMESH_MESHCHECKER_TEMPLATES
#include "MeshCheckerT.cc"
#endif

#endif // OPENMESH_MESHCHECKER_HH defined
```
4. `public`和`private`应当和`class`关键字同缩进，实例如上。
5. **宏指令不需要缩进**。宏指令能以`const`，`enum`，`inline`来代替时，则不应当使用宏指令。

### 间隔

在函数、变量等声明或使用的地方，我们要求使用空格间隔变量和运算符：
1. 二元运算符、三目运算符的字符前后都要有**一个空格**进行间隔，如：`x = 1 + 2`， `flag == true ? "Yes" : "No"`，`vaild(object) && flag`等。
2. 无论是在声明还是在调用，函数的第二个参数开始，每个参数前需要**一个空格**进行间隔，如： `mesh.add_vertex(Mesh::Point(-1, -1, 1))`等。
3. 类的构造函数初始化列表，`:`前后需**一个空格**进行间隔，之后各个参数均需在参数前添加一个空格进行间隔，示例：
4. `if`，`else if`，`while`，`for`，`catch`，`switch`等关键字之后，需要使用**一个空格**进行间隔。
5. 清除每一行最后无用的空格，如：`int x;...`有三个多余的空格，则需要清除掉。
6. 函数作用域中，使用**一个空行**将相对独立的操作隔开，例如：
```
// add face 1
face_vhandles.push_back(vhandle[2]);
face_vhandles.push_back(vhandle[1]);
face_vhandles.push_back(vhandle[5]);
face_vhandles.push_back(vhandle[6]);
mesh.add_face(face_vhandles);
face_vhandles.clear();

// add face 2
face_vhandles.push_back(vhandle[3]);
face_vhandles.push_back(vhandle[2]);
face_vhandles.push_back(vhandle[6]);
face_vhandles.push_back(vhandle[7]);
mesh.add_face(face_vhandles);
face_vhandles.clear();
```
7. 宏指令段之间需要空行间隔，单条宏指令不必间隔。例如：
```
#ifndef OPENMESH_MESHCHECKER_HH
#define OPENMESH_MESHCHECKER_HH

#if defined(OM_INCLUDE_TEMPLATES) && !defined(OPENMESH_MESHCHECKER_C)
#define OPENMESH_MESHCHECKER_TEMPLATES
#include "MeshCheckerT.cc"
#endif

#endif // OPENMESH_MESHCHECKER_HH defined
```
### 大括号

对括号的安排有两派：换行和不换行。在这里，我们约定：
1. 对所有大括号进行换行，除非大括号之中没有代码。如：`~MeshCheckerT() {}`。
2. 使用大括号将函数划分多个互不干扰的作用域，即一个函数中使用`if`、`for`等代码块进行功能划分，如果一个函数有太多代码块，需要考虑拆分或者总结逻辑，抽出一个通用算法来优化函数结构。
3. 尽可能减少`else if`的使用，过多的分支会使阅读代码的人迷惑。
4. 对于`if`或者`for`语句中只有一行代码，则不应当使用大括号。即：
```
if(enable == true)
    machine_operator();
//而不是写作：
if(enable == true)
{
    machine_operator();
}
```

### 注释

1. 我们约定，除非需要通过注释生成文档，否则须使用`//`注释，无论是单行还是多行注释。
2. 如果能通过代码表达功能，则就不需要再添加额外的注释进行解释。
3. 在复杂算法的实现上，需要给出完成的实现过程，通过注释是无法全部完成，可以将注释写在其他格式的文件中，在实现代码出给出文件路径。
4. 每个函数之前需要使用注释模版，来注释函数的功能，函数注释模板添加到头文件中，源文件.cpp中不需要添加。
5. 类的注释模板不需要讲其中的成员函数和成员变量列举，成员函数和成员变量的注释写在紧靠成员函数和成员变量的位置，同样的，也只需要将注释写在头文件中，实现文件中写具体的注释辅助理解实现。
6. 我们建议，段落注释以及行注释尽可能对齐，比如:
```
namespace OpenMesh          // BEGIN_NS_OPENMESH
{
    namespace Subdivider    // BEGIN_NS_DECIMATER
    {
        namespace Uniform   // BEGIN_NS_DECIMATER
        {
            ....
```
> 对于格式问题，我们会给出VS开发环境下的配置文件，只需一键导入即可。

---

## 头文件与源文件

通常每个`.cpp`都有一个对应的`.h`头文件，(单元测试代码以及只包含`main()`的源文件不需要)。正确使用头文件可领代码在可读性、文件大小和性能上大为改观。下面的规则可以使你避免使用头文件的麻烦：

### 防止多重包含的方法

为保证唯一性，所有头文件都应该使用`#define`防止头文件被多重包含，命名格式为：
```
<PROJECT>_<PATH>_<FILE>_H
```
其中，`path` 应当基于其所在项目目录的相对路径，比如：ClassA的位置在项目目录` D:\programs\Application` 的头文件 `src\utils\ClassA.h` 中，则应当使用下面的方式进行保护：
```
#ifndef APPLICATION_SRC_UTILS_CLASSA_H
#define APPLICATION_SRC_UTILS_CLASSA_H
.....
#endif // APPLICATION_SRC_UTILS_CLASSA_H
```
> 注意：目录或者文件命名时注意不要使用空格，文件使用最能概括文件的方式，下面命名约定一章会有讲述。

### 减少头文件依赖的方法

众所周知，C++使用的C的头文件包含方式，即当出现 `#include` 则会将整个文件插入到当前使用该指令的文件中，因此，当一个头文件被包含的同时也会引入了一项新的依赖，只要改头文件被修改，代码就需要重新编译。如果你的头文件包含了其他的头文件，这些其他的头文件的改变都会使你的头文件的代码重新编译。因此，我们第一个减少头文件依赖的方法是**尽可能不要包含本头文件用不到的头文件**，另外一个是使用**前置声明**的方法，减少头文件的 `#include` 的数量。

使用前置声明而不用 `#include` 的条件：
1. 定义的类的类型非Type的子类;
2. 非静态数据成员类型声明为Type*或者Type&;
3. 参数、返回类型为Type的函数只是声明(但不实现函数);
满足上面三个条件就可以使用前置声明取代`#include`，用法示例如下：
```
#ifndef APPLICATION_SRC_UTILS_CLASSA_H
#define APPLICATION_SRC_UTILS_CLASSA_H

/** Example Code Start **/

class Date;

class DateVerifier
{
public:
    bool check(Date& date);
    Date generateValidDate(int seed);
private:
    Date *_validDate;
}

/** Example Code End **/

#endif // APPLICATION_SRC_UTILS_CLASSA_H
```

> 注意：以上代码中，私有成员_validDate的类型仅为指示说明，而在后面的规定中，所有指针类型必须强制使用C++ 智能指针。与头文件不同的是，由于.cpp文件中无论如何都得使用类的定义部分，自然也就会包含若干头文件，而无法使用前置声明使.cpp文件避免依赖。即：**禁止在.cpp文件中使用前置声明**。

### 包含文件的名称及顺序

对于头文件，我们需要按照以下次序进行包含：
+ C Library.h
+ C++ Library.h
+ Other C++ Library.h
+ Program C++ Library.h

举例，Application项目目录中，所有项目代码在src目录下，存在一个base/log.h文件，则该文件的包含顺序如下：
```
#include <stdio.h>
#include <windows.h>
#include <vector>
#include <string>
#include <boost/timer/timer.hpp>
#include "server.h"
```
上面代码中，第一行和第二行是C的函数库，第三行和第四行是C++的STL库，第五行是Boost的timer库，第六行是Application的server函数库。其中，本工程的头文件需要用引号`""`而不是用尖括号`<>`。

对于源文件，我们要求与头文件略微不同的是，需要将本文件最依赖的头文件放到最前面，比如log类的实现文件，需要如下写法：
+ Log Class.h
+ C Library.h
+ C++ Library.h
+ Other C++ Library.h
+ Program Other C++ Library.h

如果某一类库包含多个，则按照`#include`之后的字母序进行排列，例如：
```
#include <sys/types.h>
#include <unistd.h>
#include <hash_map>
#include <vector>
#include "base/basictypes.h"
#include "base/commandlineflags.h"
#include "foo/public/bar.h
```

---

## 作用域

C++拥有作用域这个概念，我们可以通过作用域将逻辑代码细分成几个部分，提高代码可读性。

### 命名空间

在这里，我们约定：
1. 对每一个类和函数使用命名空间进行分类，这样我们便可以防止全局作用域std中的其他函数出现冲突。
2. 命名空间代表着模块功能的划分，尽可能减少嵌套层次，如出现：`A::B::C::D::ClassA`代表着模块功能划分可能存在问题，需要重构。
3. 禁止使用`using namespace std`的写法使用命名空间，需要使用某个命名空间的函数或类型时，在其所在的作用域内，使用`using std::cos`的写法来使用函数，使用`using Mesh = OpenMesh::TriMesh`的方法来使用类型。尽可能使用命名空间的作用域，比如限定在一个类中，或者一个函数中来使用：
```
Normal<double, 3> calNormal(int v)
{
    using std::cos;
    ....
}
```

### 全局变量

在这里，我们要求**尽可能不要使用全局变量**，这其中一个原因是我们对全局变量的析构顺序并不清楚。如有必要，我们需要明确该全局变量何时构造，何时析构。

全局作用域中，我们约定可以使用`using`对类型进行重命名，且我们提倡这样做，使用
```
using TriMesh = CGData::Mesh::TriMesh;
```
可以有效提高代码可读性。

---

## 类

类中的分类及顺序，应当为`public`在先，其次`private`，最后`protected`。如果没有，可不写。

在C++中，我们建议如果别的函数库需要，否则不应当自定义结构体。如：STL的仿函数是一个重载括号运算符的结构体，Vulkan的很多对象是结构体。

### 成员函数约定

无论是公有还是私有函数，顺序应当为`static`在先，其次为存取函数，其次为其他函数。各种函数按照字典序进行排序。应当遵循的其他规则有：
1. 尽可能使用`const`修饰函数，如果函数的功能在执行过程中不会改变类成员则需要在函数后加`const`**限定符**，比如`get`函数：
```
void get_time() const 
{
    return _time;
}
```
2. 尽可能函数的输入变量使用`const`修饰，如果该变量既代表输入变量也代表着输出变量，则不能用`const`进行修饰。

### 成员变量约定

成员变量的类型需要进行约定：
1. 某一些成员变量可以通过类型推导关键字`decltype`推导的类型作为参数，但这会带来一个问题，成员变量的初始化依赖着被推导的变量的声明，所以我们禁止在成员变量中使用类型推导关键字`decltype`：
```
// 下面这种写法是通不过编译的，但举例不应在这使用decltype
class A
{
private:
    std::queue<int, vector<int>, decltype(lambda_func)> _que;
}
```
2. 我们建议对成员变量的类型使用`using`重命名且需在`public`，重命名方法按照类型命名方法约定。例如：
```
template<int SIZE>
class Mesh
{
public:
    using Point = PointType<SIZE>;
    ...
};
```

### 特殊成员函数

特殊成员函数有：构造函数、析构函数、复制构造函数、移动构造函数、重载的运算符函数等，我们约定：
1. 对所有的类必须自行实现构造函数、析构函数、复制构造函数、移动构造函数，防止编译器自动生成不符合我们定义的函数。如果该类定义不能进行复制或者移动应当将复制构造函数或者移动函数使用`= delete;`表示不能调用：
```
class Mesh
{
public:
    Mesh(const Mesh& mesh) = delete;    // 复制构造函数
    Mesh(const Mesh&& mesh) = delete;   // 移动构造函数
};
```
2. 对于具有数学计算性质的类，我们建议实现重载运算符函数，以符合数学公式的形态。但针对重载运算符函数需要**重点测试**。
3. 对于赋值运算符的重载，须返回`*this`的引用，如：
```
String& String::operator=(const String& str)
{
    ....
    return *this;
}
```
4. 对于单参数的构造函数，建议使用`explict`进行修饰。

### 继承与组合

1. 继承不能滥用，我们要求，除非能够表示A是B的一种，才能够出现A继承B。其他情况使用**组合**而非继承。
2. 继承只能使用public继承。
3. 多继承是很少用到的，但用到时应当是只有一个基类，其他都为Interface。

### 友元

允许合理使用友元，比如ObjReader中，可以让Obj对象成为ObjReader的友元，即在Obj对象中定义友元:
```
class Obj
{
public:
    friend class ObjReader;
    ...
};

class ObjReader
{
public:
    // use Obj    
}
```
我们建议，友元类定义在同一个头文件中，这样方便进行查找。

---

## 函数

### 使用内联函数提高函数的执行速度

`inline`关键字可以指示修饰的函数成为内联函数，当编译器进行编译时，该函数将会被展开，而不是进入函数调用栈。优点是当函数体比较短小且经常被调用时，能够使目标代码更加高效。例如存取函数，最大值最小值函数。

使用的`inline`的规则是：
1. 函数体内容不要超过10行。
2. 对于析构和构造函数不应当使用该关键字。
3. 函数体中包含循环或者switch语句的函数不应当使用该关键字。
其实，即使函数被声明为内联函数也不一定就是内联函数，如虚函数以及递归函数。是否将声明的内联函数编译成真正的内联函数是由编译器决定的。

### 控制函数规模

尽可能减少函数的行数，对于某个函数的功能，通过将一些较复杂的过程抽象成另外一个函数等方法，将开放给其他模块的函数的细节进行屏蔽，让查看该函数的开发者更过的关注其功能。但不可过多将函数分割，过犹不及是需要重视的原则。

### 函数指针

除非其他必须使用的函数库需要使用函数指针，否则不应当定义函数指针来进行使用。在之后的推荐特性中，我们应当使用**lambda表达式**来代替函数指针的使用。

---

本规范只规定了最基本的一些风格和注意事项，但仅凭这些是没办法让每个人实现高效且风格一致的代码实现，接下来的 modern C++ 介绍中，将讲述**C++ 11/14**的特性，**C++ 17**的部分特性，以及C++的**模板元编程**。由于我们的编码是在Windows的Visual Stdio IDE下进行的，因此我们的特性介绍是紧跟MSVC的。

最后，任何一份好的代码，并不是一成不变的，它需要不断进行重构和优化，模块之间也是应当进行拆分优化整合等步骤，甚至为了实现新的方法，将会推倒重构。C++ 在不断变化，要求着我们也应当不断进步才能掌握。

**鉴于本人水平有限，该规范需要大家的讨论和修正。**

参考文献：
1. Google - C++编码规范
2. 华为 C++语言编程规范
3. 腾讯 C++编码规范