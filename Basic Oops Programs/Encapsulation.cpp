    #include<iostream>
    #include<conio.h>

    using namespace std;

    class Encapsulation{
        private:
        int x;

        public:

        void set(int a)
        {
            x = a;
        }

        int get()
        {
            return x;
        }
    };

    int main(){
        Encapsulation obj;
        obj.set(5);
        cout << obj.get();
        getch();
        return 0;
    }