#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <list>
#include <algorithm>

#include <cctype>
#include <time.h>
#include <unistd.h>

using namespace std;

enum Type {
    NUM,
    OP,
};

union Content {
    int num;
    char op;
    Content() {}
    Content(int n) : num(n) {}
    Content(char o) : op(o) {}
};

// 后缀表达式列表中的元素
struct Element {
    Type type;
    Content content;

    Element() {}
    Element(Type t, Content c):
        type(t), content(c) {}
};

// 后缀表达式类
class Suffix {
    // 使用列表存储后缀表达式元素
    list<Element> eles;
    // 结果
    int result;
    // 是否已经计算
    bool cached;
    // 是否为有效后缀表达式
    bool isvalid;

    // 添加元素
    void _add(Element& ele) {
        cached = false;
        eles.push_back(ele); 
    }

    // 计算后缀表达式的结果
    void _caculate() {
        stack<int> st;
        for(auto ele : eles) {
            if (ele.type == NUM) {
                st.push(ele.content.num);
            } else {
                int a, b;
                if (st.empty()) {
                    cached = true;
                    isvalid = false;
                    return;
                }
                b = st.top();
                st.pop();
                if (st.empty()) {
                    cached = true;
                    isvalid = false;
                    return;
                }
                a = st.top();
                st.pop();
                switch (ele.content.op) {
                case '+': a += b; break;
                case '-': a -= b; break;
                case '*': a *= b; break;
                case '/':
                    if (b == 0 || a % b != 0) {
                        cached = true;
                        isvalid = false;	
                        return;
                    }
                    a /= b; break;
                }
                st.push(a);
            }
        }
        if (st.size() != 1) {
            cached = true;
            isvalid = false;
            return;
        }
        cached = true;
        isvalid = true;
        result = st.top();
    }
public:
    // 添加后缀表达式元素，分别使用int和char重载方法
    void add(int num) {
        Element ele(NUM, num); 
        _add(ele);
    }

    bool validate_numbers(int a, int b, int c, int d) {
        vector<int> temp_1 = {a, b, c, d};
        vector<int> temp_2;
        for(auto ele : eles) {
            if (ele.type == NUM) {
                temp_2.push_back(ele.content.num); 
            } 
        }
        if (temp_2.size() != temp_1.size()) {
            return false; 
        }
        sort(temp_1.begin(), temp_1.end());
        sort(temp_2.begin(), temp_2.end());
        for(int i = 0; i < temp_1.size(); ++i) {
            if (temp_1[i] != temp_2[i]) {
                return false; 
            }
        }
        return true;
    }

    void add(char op) {
        Element ele(OP, op); 
        _add(ele);
    }

    // 获得后缀表达式的结果
    int get_result() {
        if (!cached) 
            _caculate();
        return result;
    }

    // 是否为有效后缀表达式
    bool is_valid() {
        if (!cached) 
            _caculate();
        return isvalid;
    }

    // 输出后缀表达式
    void print() {
        for(auto it = eles.begin(); it != eles.end(); ++it) {
            if (it->type == NUM) {
                cout << it->content.num << " "; 
            } else {
                cout << it->content.op<< " "; 
            }
        }
        cout << endl;
    }

    void print_as_infix() {
        typedef pair<string, int> Expr;
        stack<Expr> st;
        for(auto ele : eles) {
            if (ele.type == NUM) {
                st.push(Expr(to_string(ele.content.num), 1));
            } else {
                Expr a = st.top();
                st.pop(); 
                Expr b = st.top();
                st.pop(); 
                int level = 0;
                if (ele.content.op == '+' || ele.content.op == '-') {
                    level = 0; 
                } else {
                    level = 1; 
                }
                if (a.second < level) {
                    a.first = "(" + a.first + ")";
                }
                if (b.second < level) {
                    b.first = "(" + b.first + ")";
                }
                Expr c(b.first + ele.content.op + a.first, level);
                st.push(c);
            }
        }
        cout << st.top().first << endl;
    }
};

// 扫描器
class Scanner {
    string source;
    int idx;
public:
    static const char END = '\n';

    Scanner(string src):
        source(src),
        idx(0) {
    }

    char get_next() {
        char result;
        do {
            if (idx >= source.length()) {
                return END; 
            }
            result = source[idx++];
        } while (isblank(result));
        return result;
    }
};

// 解析器，将输入的中缀表达式转化为后缀表达式
class Parser {
    Scanner& scanner;
    Suffix sfx;
    char head;

    int match(char ch) {
        if (head == ch) {
            head = scanner.get_next(); 
            return 0;
        }
        return -1;
    }

    int expr() {
        if (term() != 0)
            return -1;
        char op;
        while ((op = head) == '+' || op == '-') {
            head = scanner.get_next();
            if (term() != 0)
                return -1;
            sfx.add(op);
        }
        return 0;
    }

    int term() {
        if (factor() != 0)
            return -1;
        char op;
        while ((op = head) == '*' || op == '/') {
            head = scanner.get_next();
            if (factor() != 0)
                return -1;
            sfx.add(op);
        }
        return 0;
    }

    int factor() {
        string str;
        if (isdigit(head)) {
            while(isdigit(head)) {
                str += head;
                head = scanner.get_next(); 
            }
            sfx.add(stoi(str));
        } else {
            if (match('(') != 0)
                return -1;
            if (expr() != 0)
                return -1;
            if (match(')') != 0)
                return -1;
        }
        return 0;
    }

public:
    Parser(Scanner &scanner):
        scanner(scanner) {}

    Suffix parser() {
        int ret = 0;
        if (Scanner::END != (head = scanner.get_next())) {
            ret = expr(); 
        }
        if (ret == -1 || head != Scanner::END) {
            cout << "Syntax error at:" << head << endl; 
            return Suffix();
        }
        return sfx;
    }
};

// 生成器，根据输入的四个数按序列生成后缀表达式
class Generator {
    vector<int> numbers;
    vector<int> operators;
    vector<Element> eles;

    static bool eles_cmp(const Element a, const Element b) {
        if (a.type == OP && b.type == OP) 
            return a.content.op < b.content.op;
        if (a.type == OP)
            return false;
        if (b.type == OP)
            return true;
        return a.content.num < b.content.num;
    }

    // 下一个操作符集合
    bool next_ops() {
        int total = 0;
        for(int i = 0; i < operators.size(); ++i) {
            total += operators[i];
        }
        if (total == 3 * operators.size())
            return false;
        ++operators[operators.size() - 1];
        int last = -1;
        for(int i = operators.size() - 1; i >= 1; --i) {
            if (operators[i] / 4 != 0) {
                last = i - 1;
                operators[i-1] += operators[i] / 4;
                operators[i] %= 4;
            } 
        }
        if (last != -1) {
            for(int i = last + 1; i < operators.size(); ++i) {
                operators[i] = operators[i-1]; 
            }
        }
        set_up();
        return true;
    }

    // 下一个排列
    bool next_perm() {
        return next_permutation(eles.begin(), eles.end(), eles_cmp); 
    }

    // 根据新的操作符集合生成新的排列
    void set_up() {
        for(int i = 0; i < numbers.size(); ++i) {
            eles[i] = Element(NUM, numbers[i]); 
        }
        for(int i = 0; i < operators.size(); ++i) {
            char op;
            switch(operators[i]) {
            case 0: op = '+'; break; 
            case 1: op = '-'; break; 
            case 2: op = '*'; break; 
            case 3: op = '/'; break; 
            }
            eles[i + numbers.size()] = Element(OP, op); 
        }
        sort(eles.begin(), eles.end(), eles_cmp); 
    }

public:
    Generator(int a, int b, int c, int d) :
              numbers(vector<int>(4)),
              operators(vector<int>(3, 0)),
              eles(vector<Element>(7)) {
        numbers[0] = a;
        numbers[1] = b;
        numbers[2] = c;
        numbers[3] = d;
        set_up();
    }

    // 下一个序列
    bool next() {
        if (!next_perm()) {
            if (!next_ops()) {
                return false; 
            }
        } 
        return true;
    }

    // 构建后缀表达式
    Suffix construct() {
        Suffix sfx;
        for(int i = 0; i < eles.size(); ++i) {
            if (eles[i].type == NUM) {
                sfx.add(eles[i].content.num); 
            } else {
                sfx.add(eles[i].content.op);
            }
        }
        return sfx;
    }
};

class Game {
    int gen_rand() {
        return 1 + rand() % 10;
    }

    pair<bool, Suffix> is_no_solution(int a, int b, int c, int d) {
        Generator generator(a, b, c, d);
        Suffix sfx;
        do {
            sfx = generator.construct();
            if (!sfx.is_valid()) {
                continue; 
            }
            if (sfx.get_result() == 24) {
                // sfx.print_as_infix();
                return pair<bool, Suffix>(false, sfx);
            }
        } while(generator.next());
        return pair<bool, Suffix>(true, sfx);
    }

    void print_numbers(int a, int b, int c, int d) {
        cout << "Four numbers: " << a << " " << b << " " << c << " " << d << endl; 
        cout << "Give me your solution: ";
    }

    void print_win() {
        cout << "Congratulations! Your answer is right!" << endl; 
    }

    void print_lose() {
        cout << "Sorry. Your answer is wrong." << endl; 
    }

    bool judge_input(const string& input, int a, int b, int c, int d) {
        Scanner scanner(input);    
        Parser parser(scanner);
        Suffix sfx = parser.parser();
        if (!sfx.is_valid()) {
            cout << "Error: Syntax error." << endl; 
            return false;
        }
        if (!sfx.validate_numbers(a, b, c, d)) {
            cout << "You are not using right numbers" << endl; 
            return false;
        }
        return sfx.get_result() == 24;
    }

    void print_dot() {
        for(int i = 0; i < 3; ++i) {
            cout << "." << flush;
            usleep(500000);
        }
        cout << endl;
    }

    int round() {
        cout << "Starting a new round" << flush;
        print_dot();
        cout << "Generating numbers" << flush;
        print_dot();
        int a, b, c, d;
        srand(time(NULL));
        a = gen_rand();
        b = gen_rand();
        c = gen_rand();
        d = gen_rand();
        pair<bool, Suffix> ret = is_no_solution(a, b, c, d);
        bool is_no = ret.first;
        print_numbers(a, b, c, d);
        string input;
        int start_time = time(NULL);
        int score = 100;
        getline(cin, input);
        if (input == "NO" || input == "No" || input == "no") {
            if (is_no) {
                print_win(); 
                score -= (time(NULL) - start_time); 
            } else {
                print_lose();
                cout << "One solution is: "; 
                ret.second.print_as_infix();
                cout << endl;
                score = 0;
            }
        } else if (judge_input(input, a, b, c, d)) {
            print_win();
            score -= (time(NULL) - start_time); 
        } else {
            print_lose();
            if (!is_no) {
                cout << "One solution is: "; 
                ret.second.print_as_infix();
                cout << endl;
            }
            score = 0;
        }
        return max(0, score);
    }

public:
    void loop() {
        int i = 0;
        double score = 0;
        while(i++ < 3) {
            cout << "---------------" << "Round " << i << "---------------" << endl;
            int s = round(); 
            cout << "Score of this round is: " << s << endl << endl;
            score += s;
            usleep(1000000);
        }
        score /= 3;
        cout << "Average score is " << score << endl;
    }
};

int main()
{
    Game game;
    game.loop();
    return 0;
}
