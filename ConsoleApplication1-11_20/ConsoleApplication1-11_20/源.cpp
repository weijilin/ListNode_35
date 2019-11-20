#define _CRT_SECURE_NO_WARNINGS 1
#if 0
// 菱形虚拟继承
class B
{
public:
	void TestFunc()
	{}

public:
	int _b;
};

class C1 : virtual public B
{
public:
	int _c1;
};

class C2 : virtual public B
{
public:
	int _c2;
};


class D : public C1, public C2
{
public:
	int _d;
};

int main()
{
	// 24
	cout << sizeof(D) << endl;

	D  d;
	d._b = 1;

	d._c1 = 2;
	d._c2 = 3;
	d._d = 4;

	C1& c1 = d;
	c1._b = 5;

	C2& c2 = d;
	c2._b = 6;

	return 0;
}
#endif

#if 0
class Base1
{
public:
	int _b1;
};

class Base2
{
public:
	int _b2;
};

class Derive : public Base1, public Base2
{
public:
	int _d;
};

int main()
{
	// A. p1 == p2 == p3
	// B. p1 < p2 < p3
	// C. p1 == p3 != p2
	// D. p1 != p2 != p3

	Derive d;
	Base1* p1 = &d;
	Base2* p2 = &d;
	Derive* p3 = &d;

	return 0;
}
#endif


#if 0
// 普通人
class Person
{
public:
	virtual void BuyTicket()
	{
		cout << "全价票" << endl;
	}

protected:
	string _name;
	string _gender;
	string _job;
	int _age;
};

class Student : public Person
{
public:
	void BuyTicket()
	{
		cout << "半价票" << endl;
	}

protected:
	int _stuId;
	double _score;
};

class soldier : public Person
{
public:
	virtual void BuyTicket()
	{
		cout << "军人优先" << endl;
	}
};


// 在程序运行时，根据基类引用实际引用的对象，选择调用对应类的虚函数
void TestBuyTicket(Person& p)
{
	p.BuyTicket();
}

// 如果多态的实现条件没有完全满足，全部调用基类的虚函数

int main()
{
	Person p;
	Student st;
	soldier so;

	TestBuyTicket(p);
	TestBuyTicket(st);
	TestBuyTicket(so);
	return 0;
}
#endif