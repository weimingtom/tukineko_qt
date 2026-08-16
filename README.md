# tukineko_qt
[Very WIP, Unfinished] My some tukineko qt ports, using AI coding, unfinished, DO NOT USE

## Ref
* tukineko_qt_v10.7z, by Codebuddy CN Auto (may be minimax or deepseek-v3)     
* tukineko_cpp_v1.7z, by Codebuddy CN Deepseek-v4-Flash  
* tukineko_qt_cpp17_v1.7z, by Trae Kimi K2.6  
* tukineko_qt_ver2_v2.7z, by Trae Kimi K2.6  

## Qt version under Windows 11
* qt-opensource-windows-x86-mingw492-5.6.1-1.exe  

## Qt development environment for Ubuntu  
* After Ubuntu 20.04, like Ubuntu 25.04  
sudo apt install gcc g++ cmake make qtcreator qtbase5-dev  
* Ubuntu 20.04 or before, like Ubuntu 20.04  
sudo apt install gcc g++ cmake make qtcreator qt5-default   

## weibo record
```
算了，看来ai转换出来的qt c++代码还是很难编译的，需要耐心慢慢整理才行。
另外，ubuntu20装qt5比较容易（qt5-default），
不过也只是装其中比较重要的模块，有一些比较复杂的qt5模块是缺少的

我测试过用codebuddy生成的qt c++ cmake工程可以成功用xubuntu 20.04
编译运行——但目前我只知道xubuntu 20.04可以很容易apt install qt5-default，
其他诸如ubuntu 25.04则无法轻松安装qt5，所以我优先用xubuntu 20.04，
或者等以后有时间研究怎么从源码编译安装qt5 ​​​​​​

tukineko qt研究，现在可以用qt5编译和运行ai转换生成的qt5代码（需要改），
但因为ai生成代码把很多底层逻辑都改了（甚至还跑不了），
所以我还需要重新把代码再写一遍，所以这个开源项目的进度不如pygame版快 ​​​

最近研究qt5的心得（以前搞过公司项目，但当时没仔细想）：
其一，Q_OBJECT只能放在class的开头，不能放在末尾，
也不能放在左大括号的同一行；
其二Q_OBJECT和其他qt特定关键词（例如slot）会触发创建moc_生成文件，
不过我觉得qt的编译器很迷，如果去掉Q_OBJECT宏来消除class的qt特性，
会编译失败，需要全部代码重新编译（可能和qmake生成makefile的机制
有关，我猜的），我暂时没有很好的方法解决，不过这种情况很少见，
一般不会去删Q_OBJECT宏

tukineko qt移植。现在的进度是我把secmd和sfcmd的类加进pro文件了
（还差三个cmd文件夹），不过我现在还只是写stub插桩函数，
还要另外花时间一个个类的逻辑核对，所以我估计最快也要年底才能
大概跑出效果（现在也能跑只是个没有输出的窗口）。
另外我之前说qt编译器很迷，有可能是我的用法有问题，
有可能我要在必要的时候重新执行qmake才能正常编译，
qt creator有这个功能可以执行

其实如果能把tukineko移植到qt5，那么用ai或者手工移植到
cocos2d-x都不会太难，我可能到时候会顺便做出来——
当然qt版目前的移植进度可能连20%都没有 ​​​

我测试过，如果是Xubuntu 25.04的话，如果要用qt5写代码，
除了装gcc g++ cmake make以外，
只要再装qtcreator和qtbase5-dev就可以了，
qtbase5-dev就相当于以前的qt5-default，
或者可能以前的qt5-default就包含了qtbase5-dev，
只是后来这个包消失了（可能在ubuntu 20之后），
所以只能用qtbase5-dev这个apt包安装qt5

tukineko qt移植。现在还差一个包的command类未写，
写完就可以一个个类慢慢改了 ​​​

tukineko qt移植，终于把所有文件的插桩函数都写好了，
准备开始填代码进去，别问为什么不用ai，
因为我用了ai但没有成功把所有文件都填好（只是生成一些插桩但没有实现代码），
想想还是算了，还是不要为难ai去处理一百多个文件，我自己写就好 ​​​

tukineko qt移植。填写了sfecmd包和vfecmd包的类实现代码。暂时没有太大的问题，
有些ai生成的方法缺失了或者访问范围不对，我暂时随便改一下。
一些QString的成员变量我暂时写成值传递变量而不是指针，等以后跑不起来再改，
因为ai是这样改的，我就暂时先不管这个问题了，等出问题再看 ​​​

tukineko qt移植，我把command类的代码改了一下，包含所有command类头文件到NSParser类中，
但还没填完command类和nsparser类的实现。我最初的想法是，把tukineko分成两部分，
一部分是nsparser，和UI无关，可以通过纯CLI空转运行，另一部分是nscripter，
需要UI实现才能运行。所以我当前目标是先跑通nsparser

tukineko qt研究。对，qt5是有一个问题，叫：unknown type name 'QMetaObject'，
参考：Qt5 头文件中加入Q_OBJECT出错，这个问题是因为修改pro文件时可能会导致编译错误，
需要清除全部clean all才能正常编译 ​​​​（补注：后来发现是因为pro文件写错，
把.cpp写成.h就会出现这种QMetaObject错误） ​​​

tukineko qt研究。我用ai又转换了一次（上次是codebuddy+minimax，
这次是trae+kimi），可以跑起来（生成的代码我还要改了很久），
但还是不能进入游戏，还是缺一些代码。所以我目前有两个qt移植版本 ​​​

写了几天qt，我明白了，很多高手说C++不好，其实主要是说C++的写法
太繁琐和容易产生bug（例如不小心跳出作用域析构了但你以为它还能运行），
其实这两个问题都有解决方法，第二个问题的话，你不能不检查就复制
别人的代码（例如别人的代码作用域和你代码的作用域不同导致bug）；
而第一个问题其实和C是一样的，只是C++要写的东西更多（甚至包括
用于编译器语法检查的代码而非运行期的代码），这个问题只能依赖于
你相信C++的严谨检查是有用的——当然它也有时候检查不出问题

我想搞完tukineko qt（其实现在已经做得差不多，还差一些
command类未填完），就去研究jaty68k移植到c++（qt）
（用AI移植，如下图），然后剩下的时间就专门研究
kirikiroid2lite的插件移植问题（用AI解决）

我搞明白为什么用AI把Java或者C井的代码转成qt时，字符串变量
会从指针变成QString值传递（补注：这里说错，应该是字符串
参数通过QString引用传递）——因为qt的QString是支持null的，
即便它不是指针，它有一个方法叫isNull()就是用来判断是否未初始化 ​​​​

然后我发现AI把一些旧的qt写法都搞出来了，例如foreach(类型 条目, 变量)，
这个非标准宏等价于for (类型 条目 : 变量)这种c++11语法，编译器会
推荐用后面c++11 for语法，而不应该用foreach宏——当然qt自己还另外
搞了一套数据结构模板，不用STL的，那些喜欢用STL的人估计会抓狂，
AI也是用qt的动态数组容器而不用STL的
````
