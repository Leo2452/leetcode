class Foo {
private:
    bool done_1_{false};
    bool done_2_{false};
    mutex m_;
    condition_variable cv_;    
public:    
    Foo() {}

    void first(function<void()> printFirst) {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        done_1_ = true;
        cv_.notify_all();
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex> lock(m_);
        cv_.wait(lock, [this] { return done_1_; });
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        done_2_ = true;
        cv_.notify_all();
    }

    void third(function<void()> printThird) {
        unique_lock<mutex> lock(m_);
        cv_.wait(lock, [this] { return done_2_; });
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};