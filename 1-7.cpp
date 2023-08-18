//7.
int a[] = {5, 4, 3, 2, 1};
auto p = a + 3;
auto q = &p;
 (*q) ++;
auto k = *p;
//非运行代码，请自行编写环境