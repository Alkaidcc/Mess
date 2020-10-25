/*
Filename		:1.cpp
Date			:2020/10/16 12:26:04
Author			:ZZC
Description     :申明一个Computer类，其中包含CPU、ROM、CDROM
*/
#include <iostream>
using namespace std;

enum CPU_Rank{P1 = 1, P2,P3,P4,P5,P6,P7};

class CPU
{
private:
    CPU_Rank rank;
    int frequency;
    double volt;

public:
    CPU();
    CPU(CPU_Rank r, int f, double v);
    CPU(CPU& c);
    ~CPU();
    void run(){cout << "CPU RUN" << endl;}
    void stop(){cout << "CPU STOP" << endl;}
};
CPU::CPU(){}
CPU::CPU(CPU_Rank r, int f, double v)
{
    rank = r;
    frequency = f;
    volt = v;
    cout << "CPU构造函数" << endl;
}
CPU::~CPU()
{
    cout << "CPU析构函数" << endl;
}
CPU::CPU(CPU& c){
    rank = c.rank;
    frequency = c.frequency;
    volt = c.volt;
    cout << "CPU拷贝函数" << endl;
}

class ROM
{
private:
    string brand;
    int frequency;
    string standard;
public:
    ROM();
    ROM(string b, int f, string s);
    ROM(ROM& r);
    ~ROM();
    void run(){cout << "ROM RUN" << endl;}
    void stop(){cout << "ROM STOP" << endl;}
};
ROM::ROM(string b, int f, string s)
{
    brand = b;
    frequency = f;
    standard = s;
    cout << "RAM构造函数" << endl;
}
ROM::ROM(){}
ROM::~ROM()
{
    cout << "RAM析构函数" << endl;
}
ROM::ROM(ROM& r){
    brand = r.brand;
    frequency = r.frequency;
    standard = r.standard;
    cout << "RAM拷贝函数" << endl;
}

class CDROM
{
private:
    string model;
    string type;
    string brand;

public:
    CDROM();
    CDROM(string m, string t, string b);
    CDROM(CDROM& cd);
    ~CDROM();
    void run(){cout << "CDROM RUN" << endl;}
    void stop(){cout << "CDROM STOP" << endl;}
};
CDROM::CDROM(){}
CDROM::CDROM(string m, string t, string b)
{
    model = m;
    type = t;
    brand = b;
    cout << "CDROM构造函数" << endl;
}
CDROM::~CDROM()
{
    cout << "CDROM析构函数" << endl;
}
CDROM::CDROM(CDROM& cd){
    model = cd.model;
    type = cd.type;
    brand = cd.brand;
    cout << "CDROM拷贝函数" << endl;
}

class Computer
{
private:
    CPU my_cpu;
    ROM my_rom;
    CDROM my_cdrom;
public:
    Computer();
    Computer(CPU c, ROM r, CDROM cd):my_cpu(c),my_rom(r),my_cdrom(cd){
        cout << "Computer构造函数" << endl;
    }
    Computer(Computer& com);
    ~Computer();
    void run();
    void stop();
};
Computer::Computer(){}

Computer::~Computer()
{
    cout << "Computer析构函数" << endl;
}

Computer::Computer(Computer& com){
    my_cpu = com.my_cpu;
    my_rom = com.my_rom;
    my_cdrom = com.my_cdrom;
    cout << "Computer拷贝函数" << endl;
}

void Computer::run(){
    my_cpu.run();
    my_rom.run();
    my_cdrom.run();
}

void Computer::stop(){
    my_cpu.stop();
    my_rom.stop();
    my_cdrom.stop();
}

int main(){
    CPU a(P1, 1800, 1.65);
    a.run();
    a.stop();
    cout << "**************" << endl;
    ROM b("samsung", 2666, "DDR4");
    b.run();
    b.stop();
    cout << "**************" << endl;
    CDROM c("AXD001","DVD-RW","Acer");
    c.run();
    c.stop();
    cout << "**************" << endl;
    Computer computer(a,b,c);
    computer.run();
    computer.stop();
    cout << "**************" << endl;
    system("pause");
    return 0;
}