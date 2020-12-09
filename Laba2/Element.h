#pragma once
class Element
{
public:
    Element();
    bool getOutput();
    void setInput(bool input);
    virtual bool produceOutput() = 0;


protected:
    bool input[2];
    bool output;
    bool isFirst;
};

