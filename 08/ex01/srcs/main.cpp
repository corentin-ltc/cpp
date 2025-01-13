#include <Span.hpp>

using std::endl;
using std::cout;

int main(void)
{
    Span span(15000);

    try
    {
        for (int i = 0; i < 15000; i++)
            span.addNumber(i);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    cout << "Shortest span = " << span.shortestSpan() << endl;
    cout << "Longest span = " << span.longestSpan() << endl;

    Span span2(1500);
    try
    {
        span2.addNumber(14);
        span2.addNumber(18);
        span2.addNumber(52);
        span2.addNumber(3);
        span2.addNumber(0);
        span2.addNumbers(18, 89);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    cout << "Shortest span = " << span2.shortestSpan() << endl;
    cout << "Longest span = " << span2.longestSpan() << endl;

    span2 = span;

    cout << "Shortest span = " << span2.shortestSpan() << endl;
    cout << "Longest span = " << span2.longestSpan() << endl;
}