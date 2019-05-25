#include <iostream>
enum type {a,b,c};

struct A
{
    virtual type get();
    int getId()const;
    void set(const int, A&);
    virtual ~A();
    private:
    int id;
};
A::~A()
{
}

int A::getId()const
{
    return id;
}
void A::set(const int numb, A& oth)
{
    if(get() == 2)
    {
        std::cout<<"Admin";
        oth.id = numb;
    }
    else
    {
        std::cout<<"not admin";
    }
}

type A::get()
{
    return a;
}

struct B : public A
{
    type get() override;
};

type B::get()
{
    return b;
}

struct C : public B
{
    type get() override;
};

type C::get()
{
    return c;
}

int main()
{
    A a;
    std::cout<<a.get()<<'\n';
    B b;
    std::cout<<b.get()<<'\n';
    C c;    
    std::cout<<c.get()<<'\n';
    b.set(3, a);
    std::cout<<a.getId()<<'\n';
    c.set(5, a);
    std::cout<<a.getId()<<'\n';
    c.set(6, b);
    std::cout<<b.getId()<<'\n';
}
