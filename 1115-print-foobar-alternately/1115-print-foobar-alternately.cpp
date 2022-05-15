class FooBar {
private:
    int n_;
    mutex m_;
    bool foo_next_;
    condition_variable cv_;

public:
    FooBar(int n) : n_(n), foo_next_{true} {}

    void foo(function<void()> printFoo) {
        for (int i = 0; i < n_; i++) {
            unique_lock<mutex> lg(m_);
            cv_.wait(lg, [this] { return foo_next_; });
        	printFoo(); // printFoo() outputs "foo". Do not change or remove this line.
            foo_next_ = false;
            cv_.notify_one();
        }
    }

    void bar(function<void()> printBar) {
        for (int i = 0; i < n_; i++) {
            unique_lock<mutex> lg(m_);
            cv_.wait(lg, [this] { return !foo_next_; });
        	printBar(); // printBar() outputs "bar". Do not change or remove this line.
            foo_next_ = true;
            cv_.notify_one();
        }
    }
};