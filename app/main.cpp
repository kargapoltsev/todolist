#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

struct Task
{
    std::string title;
    bool done = false;
};

using Tasks = std::vector<Task>;

std::string trim(std::string const& str) {
    const auto first = str.find_first_not_of(' ');
    if (first == std::string_view::npos) {
        return {};
    }
    const auto last = str.find_last_not_of(' ');
    return str.substr(first, last - first + 1);
}

int main()
{
    Tasks tasks;

    tasks.push_back({ "Some task", false });
    tasks.push_back({ "Other task", false });
    tasks.push_back({ "Done task", true });

    std::string error;

    char command;
    while (true) {
        if (tasks.empty())
            std::cout << "[TODO list is empty]" << std::endl;

        for (size_t i = 0; i < tasks.size(); ++i)
            std::cout << "[" << i << "] (" << (tasks[i].done ? "X" : " ") << ") " << tasks[i].title  << std::endl;
        
        std::cout << std::endl;

        if (!error.empty()) {
            std::cout << "Error: " << error << "\n" << std::endl;
            error.clear();
        }

        std::cout << "Enter command:" << std::endl;
        std::cout << "a [name] - add new task" << std::endl;
        std::cout << "r [task index, max " << tasks.size() << "] - remove the task" << std::endl;
        std::cout << "d [task index, max " << tasks.size() << "] - done/reopen the task" << std::endl;
        std::cout << "c - remove done tasks" << std::endl;
        std::cout << "q - quit" << std::endl;

        std::cout << ": ";
        std::cin >> command;

        switch (command)
        {
        case 'q':
            return 0;

        case 'a':
        {
            std::string taskName;
            getline(std::cin, taskName);
            if (!taskName.empty())
                tasks.push_back({ trim(taskName), false });
            else {
                error = "Empty task name";
            }

            break;
        }

        case 'r':
        {
            if (tasks.empty())
                break;

            size_t i;
            std::cin >> i;
            if (i < 0 || i > tasks.size() - 1) {
                std::stringstream ss;
                ss << "Incorrect index - " << i;
                error = ss.str();
                break;
            }

            tasks.erase(std::next(tasks.begin(), i));
            tasks.shrink_to_fit();
            break;
        }
        case 'd':
        {
            if (tasks.empty())
                break;

            size_t i;
            std::cin >> i;
            if (i < 0 || i > tasks.size() - 1) {
                std::stringstream ss;
                ss << "Incorrect index - " << i;
                error = ss.str();
                break;
            }

            tasks[i].done = !tasks[i].done;
            break;
        }
        case 'c':
        {
            auto it = std::remove_if(tasks.begin(), tasks.end(), [](Task const& t) { return t.done; });
            tasks.erase(it, tasks.end());
            break;
        }

        default: ;
        }

        system("cls");
    }
}
