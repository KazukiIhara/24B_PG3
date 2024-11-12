#include <iostream>
#include <vector>
#include <memory>

class Animal {
public:
    virtual void makeSound() const = 0;
    virtual ~Animal() = default;
};

class Dog : public Animal {
public:
    void makeSound() const override {
        std::cout << "ワンワン" << std::endl;
    }
};

class Cat : public Animal {
public:
    void makeSound() const override {
        std::cout << "ニャーニャー" << std::endl;
    }
};

class Cow : public Animal {
public:
    void makeSound() const override {
        std::cout << "モーモー" << std::endl;
    }
};

int main() {
    std::vector<std::unique_ptr<Animal>> animals;
    animals.push_back(std::make_unique<Dog>());
    animals.push_back(std::make_unique<Cat>());
    animals.push_back(std::make_unique<Cow>());

    for (const auto& animal : animals) {
        animal->makeSound();
    }

    return 0;
}