#include <iostream>
#include <string>
//Инкапсуляция
//Агрегация
//Композиция


//Формирование класса
class Name_of_class;// - объявление класса

class Name_of_class {
	//внутри скобок - тело класса.
	//тут хранятся свойства и поведения объектов




	//каждый член класса может пользоваться другим членом класса вне зависимости от его нахождения



	//хранящиеся здесь элементы доступны всем клиентам класса,
	//Наследникам класса, и клиентам наследника
public:
	//обычно в этой зоне оставляют только методы класса

	Name_of_class() {
		SetEven(2);
		even_ = 2;
	}

	//конструктор применил делегацию работы
	//для передачи прав на создание и заполнение своего поля
	//конструктору поля
	Name_of_class(int newNum):even_(newNum) //поле само себя заполняет
	{
		if (even_ % 2 == 1) {
			throw 1;
		}
	}
	//делегация на поля применяется для возможности работы с универсальной
	//инициализацией через {} и является единственным способом заполнить
	//поля которые являются ссылками и неинициализированными константами



	void Some_work() {
		std::cout << "I am happy!\n";
	}

	int GetEven() {
		return even_;
	}
	void SetEven(int newNum) {
		if (newNum % 2 == 0) {
			even_ = newNum;
		}
		else {
			throw 1;
		}
	}


	//хранящиеся здесь элементы доступны только членам класса,
	//дружественным классам и функциям и членам классов наследников
protected:



	//хранящиеся здесь элементы доступны только членам класса,
	//дружественным классам и функциям
private:
	int even_;//создаем поле класса


};//определение класса

void Ex();


int main() {
	system("chcp 1251>nul");
	int n, m;

	Name_of_class obj;//создали экземпляр класса с именем obj
	obj.Some_work(); //вывод на экран
	
	obj.SetEven(8);
	std::cout << obj.GetEven() << '\n';
	Name_of_class obj2{10};
	std::cout << obj2.GetEven() << '\n';
	obj2.SetEven(4);
	std::cout << obj2.GetEven() << '\n';

	Ex();


	return 0;
}

class Day {
public:
	Day() :units_(0){}
	Day(int days) :units_(days) {
		if (units_ < 0) {
			throw 1;
		}
	}

	int Days() {
		return units_;
	}

	void Days(const Day& obj) {
		this->units_ = obj.units_;
	}

	void AddDays(const Day& obj) {//создали универсальную ссылку для работы с любым объектом который может использоваться как Day
		this->units_ += obj.units_;
	}

private:
	int units_;
};

class Month {
public:
	Month() :units_(0){}
	Month(int month) :units_(month) {
		if (units_ < 0) {
			throw 1;
	}
	}
	Month( Day days) {
		units_ = days.Days()/30;
	}

	int Months() {
		return units_;
	}

	void Months(const Month& obj) {
		units_ += obj.units_;
	}
	void AddMonth(const Month& obj) {
		units_ += obj.units_;
	}
private:
	int units_;
};
// this-> специальный указатель позволяющий обратится через себя к полям объекта
void Ex() {
	Day day;
	day.Days(6);
}

class Year {
public:
	Year() :units_(0) {}
	Year(int year) :units_(year) {
		if (units_ < 0) {
			throw 1;
		}
	}

	
	Year(Day days) {
		units_ = days.Days() / 365;
	}


	Year(Month month) {
		units_ = month.Months() / 12;
	}

	int Years() {
		return units_;
	}

	void Years(const Year& obj) {
		units_ += obj.units_;
	}
	void AddYears(const Year& obj) {
		units_ += obj.units_;
	}
private:
	int units_;
};

class Date {
public:
	//тут будут правила класса - даты

private:
	Day day_;
	Month month_;
	Year year_;
};//данный класс собирает внутри себя объекты других классов на правах композиции

//композиция - способ формирования при котором внешний объект несет ответственность за вложенные объекты
//вложенные объекты прекратят существование вместе с внешним объектом

/*
композиция - способ связи полей класса с его объектом при котором поле является неотемлемой
частью объекта без которого невозможна работа. При композиции объект в который сложены композиционные поля несет 
ответственность за время жизни этих полей.

Агрегация - способ связи полей класса с его объектом при котором поле является легко заменяемой
частью класса. Отсутствие агрегационного компонента не ведет к проблемам в жизненном цикле хранящего данное поле объекта.
При агрегации хранящий объект не несет ответственности за время жизни хранимого на правах агрегации поля.
*/