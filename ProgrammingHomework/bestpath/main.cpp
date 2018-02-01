#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iterator>

#include <stdlib.h>
using namespace std;

#define WINDOWS

const int MAX_INT = 0x7FFFFFFF;
const string airline_filename = "airline.txt";
const string train_filename = "train.txt";

// 图的边结构体
struct Edge {
    int from;
    int to;
    int edge;
    int weight;

    Edge() {}
    Edge(int f, int t, int e, int w) :
        from(f),
        to(t),
        edge(e),
        weight(w) {}
};

// 图类，提供添加点，添加边以及查询等操作，用于使用最短路算法
class Graph {
    map<int, Edge> map_edges;
    map<int, vector<int>> map_in_edges;
    map<int, vector<int>> map_out_edges;

public:
    // 添加点
    void add_vertex(int v) {
        if (map_in_edges.find(v) == map_in_edges.end()) {
            map_in_edges[v] = vector<int>(); 
        } 
    }

    // 添加边
    void add_edge(int e, int a, int b, int w) {
        map_edges[e] = Edge(a, b, e, w); 
        map_out_edges[a].push_back(e);
        map_in_edges[b].push_back(e);
    }

    // 获取对应节点的所有入边
    vector<int>& get_in_edges(int v) {
        return map_in_edges[v];
    }

    // 获取对应节点的所有出边
    vector<int>& get_out_edges(int v) {
        return map_out_edges[v]; 
    }

    // 根据边的编号获取边的结构体内容
    Edge get_edge(int e) {
        return map_edges[e]; 
    }

    // 获得图的边的个数
    int get_size() {
        return map_in_edges.size();
    }
};

// 核心函数，用于求图的两点之间的最短路，详见算法详解
vector<int> dijkstra_edges(Graph &graph, int begin, int end) {
    int size = graph.get_size();
    vector<int> d(size, MAX_INT);
    vector<int> pre(size, -1);
    set<int> s;
    set<int> q;
    for(int i = 0; i < size; ++i) {
        q.insert(i); 
    }
    d[begin] = 0;

    while(!q.empty()) {
        int temp = MAX_INT;
        int u = -1;
        for(int i : q) {
            if (temp > d[i]) {
                temp = d[i];             
                u = i;
            }
        }
        if (u == -1) {
            break; 
        }
        q.erase(u);
        s.insert(u);
        auto edges = graph.get_out_edges(u);
        for(int e : edges) {
            Edge edge = graph.get_edge(e);
            if (d[edge.to] > d[u] + edge.weight) {
                d[edge.to] = d[u] + edge.weight;
                pre[edge.to] = edge.edge;
            }
        }
    }

    vector<int> path;
    int start = end;
    while(start != -1 && start != begin) {
        path.push_back(pre[start]);     
        start = graph.get_edge(pre[start]).from;
    }
    reverse(path.begin(), path.end());
    return path;
}

// 每条航线／铁路线路的结构体
struct Route {
    // 用于表示该路线是火车还是飞机 
    string tag; // airline or train
    // 航班号／列车号
    string code;
    // 出发城市
    string from_city;
    // 到达城市
    string to_city;
    // 等待时间
    int wait;
    // 行程时间
    int time;
    // 花费
    double cost;

    Route() {}
    Route(string &tag, string &code, string &from,
          string &to, int w, int t, double c) :
        tag(tag),
        code(code),
        from_city(from),
        to_city(to),
        wait(w),
        time(t),
        cost(c) {}
    // 输出该行程信息
    void print() {
        if (tag == "train") {
            cout << "火车"; 
        } else if (tag == "airline") {
            cout << "飞机";
        }
        cout << "\t"; 
        cout << code << "\t"; 
        cout << from_city << "\t"; 
        cout << to_city << "\t"; 
        cout << wait << "\t"; 
        cout << time << "\t"; 
        cout << cost << endl;
    }
};

// 包含所有航线的类
class Routes {
    // 图的边权重类型enum，包括
    // 以时间作为边权重
    // 以花费作为边权重
    // 以换乘数作为边权重，及每条边的权重都为1
    enum Weight {
        TIME,
        COST,
        TRANS
    };

    map<string, int> map_city_name_id;
    map<int, string> map_city_id_name;
    map<int, Route> map_id_route;
    map<string, int> map_code_id_route;

    // 添加城市
    void _add_city(const string &city) {
        if (map_city_name_id.find(city) == map_city_name_id.end()) {
            map_city_name_id[city] = map_city_name_id.size(); 
            map_city_id_name[map_city_name_id.size()] = city;
        }
    }

    // 根据要求建图：时间／花费／换乘
    void _construct_graph(Graph &graph, int by) {
        for(auto kv : map_city_id_name) {
            graph.add_vertex(kv.first);
        }
        for(auto kv : map_id_route) {
            int weight;
            // 根据不同要求定义权重
            switch(by) {
            case TIME: weight = kv.second.wait + kv.second.time; break;
            case COST: weight = kv.second.cost * 100; break;
            case TRANS: weight = 1; 
            }
            graph.add_edge(kv.first,
                           map_city_name_id[kv.second.from_city],
                           map_city_name_id[kv.second.to_city],
                           weight);
        }
    }

public:
    // 根据城市名字获取城市的id
    int get_city_id(const string &city) {
        if (map_city_name_id.find(city) == map_city_name_id.end()) {
            return -1; 
        }
        return map_city_name_id[city];
    }

    // 添加航线/火车线路
    void add_route(const Route &route) {
        _add_city(route.from_city);
        _add_city(route.to_city);
        map_code_id_route[route.code] = map_id_route.size();
        map_id_route[map_id_route.size()] = route;
    }

    void del_route(const string &code) {
        int id = map_code_id_route[code];
        map_code_id_route.erase(code);
        map_id_route.erase(id);
    }

    bool does_route_exist(const string &code) {
        if (map_code_id_route.find(code) == map_code_id_route.end()) {
            return false; 
        }
        return true;
    }

    Route get_route_by_code(const string &code) {
        int id = map_code_id_route[code];  
        return map_id_route[id];
    }

    // 根据耗费时间建图
    void construct_graph_by_time(Graph &graph) {
        _construct_graph(graph, TIME); 
    }

    // 根据花费建图
    void construct_graph_by_cost(Graph &graph) {
        _construct_graph(graph, COST); 
    }

    // 根据换乘数建图
    void construct_graph_by_trans(Graph &graph) {
        _construct_graph(graph, TRANS); 
    }

    // 获取求得最短路后的路径
    void get_path(const vector<int>& edges, vector<Route>& path) {
        for(auto e : edges) {
            path.push_back(map_id_route[e]); 
        }
    }

    // 列出所有路径
    void list_all() {
        for (auto kv : map_id_route) {
            kv.second.print(); 
        }
    }

    vector<Route> get_all_route() {
        vector<Route> ret;
        for (auto kv : map_id_route) {
            ret.push_back(kv.second);
        }
        return ret;
    }

    // 列出所有城市
    void list_cities() {
        for (auto kv : map_city_id_name) {
            cout << kv.second << " "; 
        } 
        cout << endl;
    }
};

// 文件读取解析类
class Reader {
    // 输入文件流
    ifstream infile;
    Routes &routes;
    // tag, 表明是飞机还是火车
    string tag;
     
    // 解析每一行内容
    void parse(string line) {
        vector<string> tokens;
        istringstream iss(line);
        copy(istream_iterator<string>(iss),
             istream_iterator<string>(),
             back_inserter(tokens));
        if (tokens.size() != 6)
            return;
        string code = tokens[0];
        string from = tokens[1];
        string to = tokens[2];
        int wait = stoi(tokens[3]); 
        int time = stoi(tokens[4]);
        double cost = stod(tokens[5]);
        routes.add_route(Route(
                    tag, code, from, to,
                    wait, time, cost));
    }

public:
    // 读取文件
    void read() {
        string line;
        getline(infile, line);
        while(getline(infile, line)) {
            parse(line); 
        }
    }

    Reader(Routes& routes, const string &infile_name, string tag) :
        infile(infile_name.c_str(), ios::in),
        routes(routes),
        tag(tag) {}
    ~Reader() {
        infile.close(); 
    }
};

class Writer {
    Routes &routes;
    ofstream outfile_airline;
    ofstream outfile_train;

    string gen_line(const Route &route) {
        string ret;
        ret += route.code + '\t';
        ret += route.from_city + '\t';
        ret += route.to_city + '\t';
        ret += to_string(route.wait) + '\t';
        ret += to_string(route.time) + '\t';
        ret += to_string(route.cost) + '\t';
        ret += "\n";
        return ret;
    }

public:
    Writer(Routes &routes, const string &airline_filename, const string &train_filename) :
        routes(routes),
        outfile_airline(airline_filename.c_str(), ios::out),
        outfile_train(train_filename.c_str(), ios::out) {}

    ~Writer() {
        outfile_airline.close();
        outfile_train.close();
    }

    void write() {
        string airline_to_write;
        string train_to_write;
        for(auto route : routes.get_all_route())  {
            if (route.tag == "airline") {
                airline_to_write += gen_line(route); 
            } else if (route.tag == "train") {
                train_to_write += gen_line(route); 
            }
        }
        string header = "班号\t出发地\t到达地\t等待时间\t时间\t花费\n";
        outfile_airline << header;
        outfile_airline << airline_to_write << flush;
        outfile_train << header;
        outfile_train << train_to_write << flush;
    }
};

class Login;

// 用户类
class User {
    friend class Login;

    // 用户的类型，包括管理员、普通用户
    // admin / user / visitor
    string tag;
    string name;
    string password;
public:
    User () {}
    User(const string &tag,
         const string &name,
         const string &password) :
        tag(tag),
        name(name),
        password(password) {}
    // 获取该用户的用户名
    string get_name() {
        return name; 
    }

    // 获取该用户的类型
    string get_tag() {
        return tag; 
    }

    // 验证密码
    bool validate(const string &passwd) {
        if (passwd == password) {
            return true; 
        } 
        return false;
    }

protected:
    // 重设密码
    void reset_password(const string &new_password) {
        password = new_password; 
    }
};

// 登陆类
class Login {
    map <string, User> map_name_user;
public:
    Login() {
        // 初始化默认用户，管理员admin，普通用户kevin
        map_name_user.insert(pair<string, User>("admin", User("admin", "admin", "123456")));
        map_name_user.insert(pair<string, User>("kevin", User("user", "kevin", "abcdef")));
    }
    
    // 验证用户名和密码是否匹配
    bool validate(string name, string password) {
        if (map_name_user.find(name) == map_name_user.end()) {
            return false; 
        }
        return map_name_user[name].validate(password);
    }

    // 根据用户名获取某个用户的类型
    string get_tag(string name) {
        return map_name_user[name].get_tag(); 
    }
};

// 主类，包含题目要求的各种逻辑
class Main {
    Routes &routes;
    Login &login;

    // 根据建好的图获取最短路
    void _get_path(Graph &graph, vector<Route> &path, int from_city_id, int to_city_id) {
        auto edges = dijkstra_edges(graph, from_city_id, to_city_id);
        routes.get_path(edges, path);
    }

    // 输出路径
    void _print_path(const vector<Route>& path) {
        for(auto route : path) {
            route.print(); 
        }
    }

    // 最少时间
    void _least_time (int from_city_id, int to_city_id) {
        Graph graph; 
        vector<Route> path;
        routes.construct_graph_by_time(graph);
        _get_path(graph, path, from_city_id, to_city_id);
        cout << "以下换乘耗时最少：" << endl;
        _print_path(path);
    }

    // 最少花费
    void _least_cost (int from_city_id, int to_city_id) {
        Graph graph; 
        vector<Route> path;
        routes.construct_graph_by_cost(graph);
        _get_path(graph, path, from_city_id, to_city_id);
        cout << "以下换乘花费最少：" << endl;
        _print_path(path);
    }

    // 最少换乘
    void _least_trans (int from_city_id, int to_city_id) {
        Graph graph; 
        vector<Route> path;
        routes.construct_graph_by_trans(graph);
        _get_path(graph, path, from_city_id, to_city_id);
        cout << "以下换乘换乘最少：" << endl;
        _print_path(path);
    }

public:
    Main(Routes &routes, Login &login) :
        routes(routes),
        login(login) {}

    // 查询目标城市的最佳到达路径
    void _find_path() {
        cout << "请在以下城市进行选择:" << endl;
        routes.list_cities();
        string from_city, to_city;  
        cout << "出发城市：";
        cin >> from_city;
        cout << "到达城市：";
        cin >> to_city;

        int from_city_id, to_city_id;
        // 判断输入的城市是否存在
        if ((from_city_id = routes.get_city_id(from_city)) == -1) {
            cout << "错误：" << from_city_id << " 不存在!" << endl;
            return;
        }
        if ((to_city_id = routes.get_city_id(to_city)) == -1) {
            cout << "错误：" << to_city_id << " 不存在!" << endl;
            return;
        }
        // 输出每种要求的换乘方案
        _least_trans(from_city_id, to_city_id);
        _least_cost(from_city_id, to_city_id);
        _least_time(from_city_id, to_city_id);
    }

    // 添加路径
    void _add_route() {
        string code;
        string tag;
        string from_city;
        string to_city;
        int wait;
        int time;
        double cost;
        cout << "1.飞机\n2.火车" << endl;
        int choice;
        cout << "你的选择：";
        cin >> choice;
        if (choice == 1) {
            tag = "airline"; 
        } else if (choice == 2) {
            tag = "train"; 
        } else {
            cout << "选择错误！" << endl;
            return; 
        }
        cout << "航班号／列车号：";
        cin >> code;
        if (routes.does_route_exist(code)) {
            cout << "对应航班号／列车号已经存在，添加失败!" << endl;
            return;
        }
        cout << "出发城市：";
        cin >> from_city;
        cout << "到达城市：";
        cin >> to_city;
        cout << "等待时间：";
        cin >> wait;
        cout << "行驶时间：";
        cin >> time;
        cout << "花费：";
        cin >> cost;
        Route route(tag, code, from_city, to_city, wait, time, cost);
        routes.add_route(route);
        return;
    }

    // 删除路径
    void _del_route() {
        string code;
        cout << "你需要删除的航班号／列车号：";
        cin >> code;
        if (!routes.does_route_exist(code)) {
            cout << "该航班／列车不存在！删除失败。" << endl;
            return;
        }
        routes.del_route(code);
        cout << "删除成功！" << endl;
    }

    // 管理员界面，包括列出所有路径、添加路径、删除路径、保存修改
    bool _admin() {
        cout << "你是管理员。请在下列选项中选择一项：" << endl;
        int choice;
        cout << "1.列出所有路径" << endl;
        cout << "2.添加路径" << endl;
        cout << "3.删除路径" << endl;
        cout << "4.保存修改" << endl;
        cout << "0.退出登陆" << endl;
        cout << "你的选择：";
        cin >> choice;
        switch(choice) {
        case 0: return false; break; 
        case 1: routes.list_all(); break; 
        case 2: _add_route(); break; 
        case 3: _del_route(); break; 
        case 4:
            Writer writer(routes, airline_filename, train_filename);
            writer.write();
            break; 
        }
        return true; 
    }

    // 普通用户界面，包括列出所有路径、查询路径
    bool _user() {
        cout << "你是普通用户。请在下列选项中选择一项：" << endl;
        int choice;
        cout << "1.列出所有路径" << endl;
        cout << "2.查询路径" << endl;
        cout << "0.退出登陆" << endl;
        cout << "你的选择：";
        cin >> choice;
        switch(choice) {
        case 1: routes.list_all(); break;
        case 2: _find_path(); break;
        case 0: return false; break;
        }
        return true;
    }

    // 游客路径，包括列出所有路径
    bool _visitor() {
        cout << "你是游客。请在下列选项中选择一项：" << endl;
        int choice;
        cout << "1.列出所有路径" << endl;
        cout << "0.返回登陆" << endl;
        cout << "你的选择：";
        cin >> choice;
        switch(choice) {
        case 1: routes.list_all(); break;
        case 0: return false; break;
        }
        return true;
    }

    // 登陆系统
    void _login_system() {
        string name, password;
        cout << "提示：" << endl;
        cout << "管理员  \t用户名:admin\t密码:123456" << endl;
        cout << "普通用户\t用户名:kevin\t密码:abcdef" << endl;
        cout << "-------------------------" << endl;
        cout << "用户名：";
        cin >> name;
        cout << "密码：";
        cin >> password;
        if (!login.validate(name, password)) {
            cout << "登陆失败！用户名不存在或者密码错误。" << endl;
            return; 
        }
        cout << "登录成功！" << endl;
        string tag = login.get_tag(name);
        if (tag == "admin") {
            while (_admin()) {
#ifdef WINDOWS
                system("pause");
                system("cls");
#endif
            }
        } else if (tag == "user") {
            while (_user()) {
#ifdef WINDOWS
                system("pause");
                system("cls");
#endif
            }
        }
    }


    void run() {
        while(true) {
            cout << "1.登陆系统" << endl;
            cout << "2.游客访问" << endl;
            int choice;
            cout << "你的选择： ";
            cin >> choice;
            switch(choice) {
            case 1: _login_system(); break; 
            case 2:
                while(_visitor()) {
#ifdef WINDOWS
                    system("pause");
                    system("cls");
#endif
                }; break;
            }
        }
    }
};


// 初始化routes
void init_routes(Routes &routes, const string& airline_filename, const string &train_filename) {
    Reader airline_reader(routes, airline_filename, string("airline"));
    Reader train_reader(routes, train_filename, string("train"));
    airline_reader.read();
    train_reader.read();
}

int main() {
    Routes routes;
    init_routes(routes, airline_filename, train_filename);
    Login login;
    Main main(routes, login);
    main.run(); 
    return 0; 
}

