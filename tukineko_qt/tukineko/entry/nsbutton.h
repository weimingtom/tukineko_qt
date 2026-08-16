#ifndef NSBUTTON_H
#define NSBUTTON_H

class NsButton
{
public:
    NsButton(int no, int x, int y, int width, int height, int u, int v);
    virtual ~NsButton();

    int no;
    int x;
    int y;
    int width;
    int height;
    int u;
    int v;
};

#endif // NSBUTTON_H
