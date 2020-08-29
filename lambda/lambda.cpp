// Lambda Learn
// lambda form: 
// [captured variable](parameters) mutable/exception -> returnType {}
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <functional>

class UnNamedLocalFunction {
private:
    int localvar_;
public:
    UnNamedLocalFunction(int var) : localvar_(var) {}

    bool operator()(int var) {
        return var == this->localvar_;
    }
};

class X {
private:
    int x_, y_;
public:
    X(int x, int y) : x_(x), y_(y) {}
    int operator()(int a) {
        return a;
    }

    int f() {
        // 成员函数 f()
        // 对于 [=], [&] lambda exp 可以直接使用 this
        return [&]() -> int {
            // X::operator()(this->x_, (*this).y_)
            return operator()(this->x_ + y_);
        }();
    }

    int ff() {
        return [this]() {
            return this->x_;
        }();
    }
};

class Person {
public:
    std::string firstname;
    std::string lastname;
};

int main() {

    // lambda 1 隐式返回类型
    []{
        std::cout << "Hello, Lambda1!" << std::endl;
    }();

    // lambda 2
    auto lambda2 = []() {
        std::cout << "Hello, Lambda2!" << std::endl;
    };
    lambda2();

    std::cout << "lambda 3 mutable keyword" << std::endl;
    int id = 0;
    // 如果没有 mutable 会报错: cannot assign to a variable captured by copy in a non-mutable lambda
    auto f = [id]()mutable {
        std::cout << "id = " << id << std::endl;
        ++id;
    };
    id = 42;
    // 值传递的 lambda, 变量更改后不会受影响
    f(); // 0
    f(); // 1
    f(); // 2
    std::cout << id << std::endl; // 42
    // lambda 3 相当于

    // class Func {
    // private:
    //     int id_;
    // public:
    //     void operator() {
    //         std::cout << "id: " << id_ << std::endl;
    //         ++id_;
    //     };
    // };
    // Func f;

    int id1 = 0;
    auto f1 = [&id1]() {
        std::cout << "id1 = " << id1 << std::endl;
        ++id1;
    };

    id1 = 42;
    // 引用传递，会使用修改后(id1 = 42)的值
    f1(); // 42
    f1(); // 43
    f1(); // 44
    std::cout << id1 << std::endl; // 45

    int id2 = 0;
    auto f2 = [&id2](int &param) {
        std::cout << "id2 = " << id2 << std::endl;
        ++id2;
        ++param;
        std::cout << "param = " << param << std::endl;
        static int x = 5;
        return id2;
    };
    int param = 1;
    f2(param);
    std::cout << "param = " << param << std::endl; // 2

    std::cout << "[=] 默认以值传递的方式获取外部变量";
    std::cout << "[&] 默认以引用传递的方式获取外部变量" << std::endl;
    auto f3 = [&]() {
        std::cout << "id = "    << id    << std::endl; // id    = 42
        std::cout << "id1 = "   << id1   << std::endl; // id1   = 45
        std::cout << "id2 = "   << id2   << std::endl; // id2   = 1
        std::cout << "param = " << param << std::endl; // param = 2
    };
    f3();

    // 一部分引用传递，一部分值传递
    std::cout << "id = " << id << std::endl;
    auto f4 = [=, &id]() {
        std::cout << "id = "    << id    << std::endl; // id    = 42
        ++id;
        std::cout << "id1 = "   << id1   << std::endl; // id1   = 45
        std::cout << "id2 = "   << id2   << std::endl; // id2   = 1
        std::cout << "param = " << param << std::endl; // param = 2
    };
    f4();

    std::cout << "id = " << id << std::endl;
    auto f5 = [&, id]() {
        std::cout << "id = "    << id    << std::endl; // id    = 42
        std::cout << "id1 = "   << id1   << std::endl; // id1   = 45
        std::cout << "id2 = "   << id2   << std::endl; // id2   = 1
        std::cout << "param = " << param << std::endl; // param = 2
    };
    f5();

    // this 指针
    X x(1, 2);
    std::cout << "x.f() = "  << x.f()  << std::endl; // x.f() = 3
    std::cout << "x.ff() = " << x.ff() << std::endl; // x.ff() = 1

    // lambda1 和 lambda_unnamed 等于 UnNmaedLocalFunction
    int to_be_found = 5;
    auto lambda1 = [to_be_found](int val) {
        return val == to_be_found;
    };

    bool b1 = lambda1(5); // 1
    UnNamedLocalFunction lambda_unnamed(to_be_found);
    bool b2 = lambda_unnamed(5); // 1
    std::cout << b1 << " " << b2 << std::endl;

    auto ll1 = [](int x) -> int {
        return x + 10;
    };

    // lambda 匿名函数
    std::function<int(int x)> ll = [](int x) -> float {
        return x + 10.0;
    };
    std::cout << ll(1) << std::endl;

    // decltype + lambda
    // 比大小
    std::function<bool(const Person &p1, const Person &p2)> cmp = [](const Person &p1, const Person &p2) {
        return p1.lastname < p2.lastname;
    };

    std::set<Person, decltype(cmp)> col(cmp);

    std::vector<int> vec{5, 28, 50, 83, 70, 590, 245, 59, 24};
    int a = 30, b = 100;
    vec.erase(std::remove_if(vec.begin(), vec.end(), [a, b](int n) {
        return a < n && n < b;
    }), vec.end());

    std::for_each(vec.begin(), vec.end(), [](int i) {
        std::cout << i << " ";
    });
}