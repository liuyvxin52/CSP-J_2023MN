//13.
    union U{
        bool flag1, flag2, flag3, flag4, flag5;
        signed   short a;
        unsigned short b;
        enum E{
            CardA = 0, CardB = 1,
            CardC = 2, CardD = 142857
        } e;
    } u;
//非运行代码，请自行编写环境