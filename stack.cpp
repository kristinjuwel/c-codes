#include <iostream>
#include <stack>
using namespace std;
class lab
{
public:
    int user_input;
    int my_stack[50], x = 50, top = -1;
    void pusher(int user_input)
    {
        if (top >= x - 1)
            cout << "stack overflow" << endl;
        else
        {
            top++;
            my_stack[top] = user_input;
        }
    };
    void popper()
    {
        if (top <= -1)
            cout << "stack underflow" << endl;
        else
        {
            cout << "Element popped: " << my_stack[top] << endl;
            top--;
        }
    }
    void topper()
    {
        cout << "Top: " << my_stack[top] << endl;
    }
    void empty()
    {
        if (top >= 0)
        {
            cout << " Stack elements: ";
            for (int i = top; i >= 0; i--)
                cout << my_stack[i] << " ";
            cout << endl;
        }
        else
            cout << "empty stack" << endl;
    }
};
int main()
{
    lab i;
    int c_input, user_input;
    cout << "1.) Push an integer" << endl;
    cout << "2.) Pop the stack" << endl;
    cout << "3.) Show top of stack" << endl;
    cout << "4.) Check if empty" << endl;
    cout << "5.) Exit" << endl;
    do
    {
        cout << "Input choice: ";
        cin >> c_input;
        switch (c_input)
        {
        case 1:
        {
            cout << "Input number: ";
            cin >> user_input;
            i.pusher(user_input);
            break;
        }
        case 2:
        {
            i.popper();
            break;
        }
        case 3:
        {
            i.topper();
            break;
        }
        case 4:
        {
            i.empty();
            break;
        }
        case 5:
        {
            cout << " EXIT " << endl;
            break;
        }
        default:
        {
            cout << " Invalid Choice " << endl;
        }
        }
    } while (c_input != 5);
    return 0;
};
