
// 对象类型
// 1. 自动对象（跳出作用域就销毁）
// 2. 局部静态对象（函数结束后依然存在）
// 统计函数被调用次数
#include <iostream>
using namespace std;
size_t count_calls()
{
    static size_t ctr = 0;
    return ++ctr;
}

int main()
{
    for (size_t i = 0; i != 10; ++i)
        cout << count_calls() << endl;
    return 0;
}

// 3. 值传递：对参数的修改不会影响实参
// 4. 引用传递：最好使用引用类型而不是指针类型，使用引用可以避免拷贝（某些类类型不支持拷贝）
// 5. 当不需要改变对象时，最好定义为常引用
// 6. 使用引用新参可以返回额外信息
// 6. auto decltype