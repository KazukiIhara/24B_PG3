#include <memory>

#include <iostream>

template <typename Type>
class Compare {
public:
    Compare(Type a, Type b) : value1(a), value2(b) {}

    Type Min() const {
        return (value1 < value2) ? value1 : value2;
    }

private:
    Type value1;
    Type value2;
};

int main() {
    // int 型のインスタンス
    Compare<int> intCompare1(3, 5);
    Compare<int> intCompare2(10, 2);

    // float 型のインスタンス
    Compare<float> floatCompare1(3.5f, 7.8f);
    Compare<float> floatCompare2(9.1f, 1.4f);

    // double 型のインスタンス
    Compare<double> doubleCompare1(4.2, 2.3);
    Compare<double> doubleCompare2(8.5, 10.1);

    // Min関数の結果を表示
    std::cout << "intCompare1.Min(): " << intCompare1.Min() << std::endl;
    std::cout << "intCompare2.Min(): " << intCompare2.Min() << std::endl;
    std::cout << "floatCompare1.Min(): " << floatCompare1.Min() << std::endl;
    std::cout << "floatCompare2.Min(): " << floatCompare2.Min() << std::endl;
    std::cout << "doubleCompare1.Min(): " << doubleCompare1.Min() << std::endl;
    std::cout << "doubleCompare2.Min(): " << doubleCompare2.Min() << std::endl;

    return 0;
}
