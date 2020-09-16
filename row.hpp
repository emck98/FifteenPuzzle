#ifndef ROW_HPP
#define ROW_HPP

class Row {
    private:
        int first;
        int second;
        int third;
        int fourth;

    public:
        Row();
        Row(int a, int b, int c, int d);
        void printRow();

};

char intToChar(int tile);
void printBorder();

#endif 