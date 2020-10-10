#ifndef LOGIC_H
#define LOGIC_H

class Element 
{
protected:
    bool input[2];
    bool output;
    bool isFirst;
    

public:
    Element();
    bool getOutput();
    void setInput(bool input);
    virtual bool produceOutput() = 0;

};


class And: public Element
{
    bool produceOutput() override;
};


class Or: public Element
{
    bool produceOutput() override;
};


class Scheme
{
private:
    const int n;
    Element *logics[10];
    bool output;
    short int path[10][10];

public:
    Scheme();
    ~Scheme();
    bool doStep();
    bool getOutput();
    void genNewInput();
    

};
#endif // LOGIC_H