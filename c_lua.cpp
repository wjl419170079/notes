
// 注册C函数
// ps:	# 字符串化操作（将变量名转化成字符串）	## 连接字符串
// lua_register(L, fname, f);
#define RegisterLuaFunction(fname) lua_register(L, #fname, L_##fname)

// save delete
#define SAFE_DELETE(p) if((p)) {delete (p); (p) = 0;}
#define SAFE_DELETE_ARRAY(p) if((p)) {delete [](p); (p) = 0;}

// 单例模式
#define SINGLETON_MODE(ClassName)\
    static ClassName &GetInstance()\
{\
    static ClassName s_##ClassName;\
    return s_##ClassName;\
}

// 命名空间
#define NS_A_BEGIN namespace A {
#define NS_A_END }
#define USING_NS_A using namespace A;

// 命名空间
#define NS_BEGIN(NAME) namespace #NAME {
#define NS_END(NAME) }
#define USING_NS(NAME) using namespace #NAME;

// 在C++中使用C文件（告诉编译器用C模式进行编译，因为C++支持重载，函数名会加入参数类型，导致"无法解析的外部符号"）
extern "C" {
    #include "lua.h"
}

// #pragma warning 启用和禁用warning
// 开发人员可以使用 #pragma 指令将警告作为错误处理；还可以启用或禁用警告，如下面的示例所示：
// 1.将一个warning作为一个错误
#pragma warning (error: 6260)
// 2.将一个warning禁用掉
#pragma warning (disable: 6011) 
// 3.将一个被禁用的warning启用
#pragma warning (enable: 6011)

// 表示链接ws2_32.lib这个库。ws2_32.dll是Windows Sockets应用程序接口
#pragma comment(lib, "ws2_32.lib")
// 表示链接winmm.lib这个库。winmm.dll是Windows多媒体相关应用程序接口，用于低档的音频和游戏手柄。
#pragma comment(lib, "winmm.lib")

// 宏定义变长参数
#define CHECK1(x, ...) if (!(x)) { printf(__VA_ARGS__); }