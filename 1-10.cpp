//10.
    int cnt = 0;
     for(int i = 1;i <= n; i++){
         for(int j = 1;j <= n;j += i){
             for(int k = 1;k <= n;k += j){
                ++ cnt;
             }
         }
     }
//此为非运行代码，请自行编写环境