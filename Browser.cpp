#include <iostream>
#include <string>
#include <vector>
#include <stack>

typedef std::vector<std::string> VecOfStrings;
typedef std::stack<std::string> StackOfStrings;

std::string readNewURL() {
    std::string URL;
    std::cin >> URL;
    return URL;
}

void executeCommand( VecOfStrings& history,  std::string& URL, StackOfStrings& forwardedPages) {
    
    if (URL == "/back")
    {
        if (history.size() >= 1)
        {
           
            forwardedPages.push(history[history.size() - 1]);
            history.pop_back();
           
        }
        if (history.empty())
        {
            std::cout << "You are at homepage!" << std::endl;
        }
        else
        {
           
            std::cout << "Current URL: " << history[history.size() - 1] << std::endl;
        }
       
    }
    else if(URL == "/forward")
    {
        if (forwardedPages.empty())
        {
            std::cout << "No next URLs" << std::endl;
        }
        else
        {
            std::cout << "Current URL: " << forwardedPages.top() << std::endl;
            forwardedPages.pop();
        }
        
    }
    else
    {
        history.push_back(URL);
        std::cout << "Current URL: " << URL << std::endl;
    }

}

int main()
{
    std::string URL = readNewURL();

    VecOfStrings history;
    StackOfStrings forwardedPages;
    while (URL!="end")
    {
        executeCommand(history, URL, forwardedPages);
        URL = readNewURL();
    }



    return 0;
}
