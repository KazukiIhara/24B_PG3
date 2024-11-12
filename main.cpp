#include <iostream>
#include <vector>
#include <memory>
#include <cmath>
#include <numbers>

class IShape {
public:
	virtual void Size() = 0;
	virtual void Draw() = 0;
protected:
	float area = 0.0f;
};

class Circle: public IShape {
public:
	Circle(double radius) : radius(radius) {}

	void Size() override {
		area = std::numbers::pi_v<float> * radius * radius;
	}

	void Draw() override {
		std::cout << "Circle Area: " << area << std::endl;
	}

private:
	float radius;  // 半径
};

class Rectangle: public IShape {
public:
	Rectangle(float width, float height) : width(width), height(height) {}

	void Size() override {
		area = width * height;
	}

	void Draw() override {
		std::cout << "Rectangle Area: " << area << std::endl;
	}

private:
	float width, height;
};

int main() {
	std::vector<std::shared_ptr<IShape>> shapes;
	shapes.push_back(std::make_shared<Circle>(5.0));
	shapes.push_back(std::make_shared<Rectangle>(4.0, 6.0));

	for (auto& shape : shapes) {
		shape->Size();
		shape->Draw();
	}

	return 0;
}