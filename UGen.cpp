#include <iostream>
#include <random>
#include <string>
#include <ctime>
#include <algorithm>
#include <unistd.h>

using namespace std;

#define reset "\033[0m"
#define clear_screen "\033[2J\033[H"
#define blinking_mode "\033[5m"

#define red "\033[31m"

int input;

void shell_prompt() {
    cout << "╚══> " << blinking_mode << reset;
}

void menu() {
    cout << red;

    cout << R"(
 ██╗   ██╗ ██████╗ ███████╗███╗   ██╗
 ██║   ██║██╔════╝ ██╔════╝████╗  ██║
 ██║   ██║██║  ███╗█████╗  ██╔██╗ ██║
 ██║   ██║██║   ██║██╔══╝  ██║╚██╗██║
 ╚██████╔╝╚██████╔╝███████╗██║ ╚████║
  ╚═════╝  ╚═════╝ ╚══════╝╚═╝  ╚═══╝
)" << endl;

    cout << "╔═══════════════════════════════════╗\n";
    cout << "║                                   ║\n";
    cout << "║       ,        ,                  ║\n";
    cout << "║      /(        )`                 ║\n";
    cout << "║      \\ \\___   / |                 ║\n";
    cout << "║      /- _  `-/  '                 ║\n";
    cout << "║     (/\\/ \\ \\   /\\                 ║\n";
    cout << "║     / /   | `    \\                ║\n";
    cout << "║     O O   ) /    |                ║\n";
    cout << "║     `-^--'`<     '                ║\n";
    cout << "║    (_.)  _  )   /                 ║\n";
    cout << "║     `.___/`    /                  ║\n";
    cout << "║       `-----' /                   ║\n";
    cout << "║                                   ║\n";
    cout << "║                                   ║\n";
    cout << "╚═══════════════════════════════════╝\n";

    cout << reset;
}
namespace Gen {

    static constexpr const char* DEFAULT_CHARSET = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
    "!@#$%^&*()-_=+[{]}\\|;:'\",<.>/?`~_";
    static default_random_engine random{static_cast<unsigned>(time(0))};
    static mt19937 random_generator(random());

    string generate(size_t length, const string& charset = "") {
        string str = charset.empty() ? string(DEFAULT_CHARSET) : charset;

        while(length > str.length()) str += str;

        shuffle(str.begin(), str.end(), random_generator);

        return str.substr(0, length);
    }
}

int main() {

    string random_string;

    cout << clear_screen;
    menu();
    cout << "Welcome to UGen, a C++ coded Open-Source software designed to secure the user with a strong password.\n";
    cout << "You may not distribute or modify code unless granted permission to.\n";
    cout << "0x16000 on GitHub all rights reserved, Rheinland-Pfalz, Germany\n";
    cout << "Licensed under the GNU General Public License 3.0, see: https://www.gnu.org/licenses/gpl-3.0.html for more.\n\n";

    cout << "Choose password length (1-18):\n";
    shell_prompt();
    cin >> input;

    if (input >= 1 && input <= 18) {
        random_string = Gen::generate(input);
        string category = (input < 8) ? "short" : "long";
        cout << "Generated " << category << " password: " << random_string << "\n";
    } else {
        cout << "Invalid value or maximum reached.\n";
    }
    
    return 0;
}
