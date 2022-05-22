# include <iostream>
# include <cassert>
# include <memory>
# include <vector>

# include <thread>
# include <mutex>


struct B 
{
    virtual void bar() 
    { 
        std::cout << "B::bar\n"; 
    }

    virtual ~B() = default;
};

struct D : B
{
    D() 
    { 
        std::cout << "D::D\n";
    }

    ~D() 
    { 
        std::cout << "D::~D\n";
    }

    virtual void bar() override
    { 
        std::cout << "D::bar\n"; 
    }

};

// unique_ptr �ĺ�������ֵ(����std::move)�����ý�����
std::unique_ptr<D> pass_through(std::unique_ptr<D> p)
{
    p->bar();
    return p;
}


void test_01()
{
    std::unique_ptr<D>  p = std::make_unique<D>();  // p ռ�� D
    std::unique_ptr<D>  q = pass_through(std::move(p));
    assert(!p);
       
    q->bar();
}


void test_02()
{
    std::cout << "Runtime polymorphism demo\n";


    std::unique_ptr<B> p = std::make_unique<D>();    // ����ָ��ָ���������
    p->bar();                                       // �����virtual ����


    // ����ָ����Էŵ�  ������
    std::vector<std::unique_ptr<B>> vec;
    vec.push_back(std::make_unique<D>());
    vec.push_back(std::move(p));

}



struct Base
{
    Base() { std::cout << "  Base::Base()\n"; }
    ~Base() { std::cout << "  Base::~Base()\n";}
};

struct Derived : public Base
{
    Derived() { std::cout << "  Derived::Derived()\n"; }
    ~Derived() { std::cout << "  Derived::~Derived()\n"; }
};

void thr(std::shared_ptr<Base> p)
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::shared_ptr<Base> lp = p; // �̰߳�ȫ����Ȼ��������� use_count
    {
        static std::mutex io_mutex;
        std::lock_guard<std::mutex> lk(io_mutex);
        std::cout << "local pointer in a thread:\n"
            << "  lp.get() = " << lp.get()
            << ", lp.use_count() = " << lp.use_count() << '\n';
    }
}



void test_03()
{
    std::shared_ptr<Base> p = std::make_shared<Derived>();
    std::cout << "  p.get() = " << p.get() << ", p.use_count() = " << p.use_count() << '\n';
    std::thread t1(thr, p), t2(thr, p), t3(thr, p);

    p.reset(); 
    std::cout << "  p.get() = " << p.get() << ", p.use_count() = " << p.use_count() << '\n';
    t1.join(); t2.join(); t3.join();
    std::cout << "All threads completed, the last one deleted Derived\n";
}

int main()
{
    test_01();
    
    test_02();
    
    test_03(); 
}

