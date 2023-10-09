// сырой код, выяснить как подобрать длину подчеркивания стр 22
package main

import "fmt"

func main(){
    
    var r, c int;
    var k= 1;
    var i= 1;
    var j= 1;

    fmt.Scan(&r, &c);
    
    fmt.Print(" ", "\t", "|\t",);
    
    for k = 1; k < c+1; k++{
        fmt.Print(k, " \t");
    }
    fmt.Printf("\n");

    for k = 1; k < c*9; k++{ // ВОТ ЗДЕСЬ СКОЛЬКО ВЫВОДИТЬ ЗНАКОВ
        fmt.Printf("-");
    }
    fmt.Printf("\n");

    for i = 1; i <= r; i++{
         fmt.Print(i, "\t", "|\t");
         for j = 1; j <= c; j++{ 
            fmt.Print(i*j, " \t");
         }
        fmt.Printf("\n");
    }
}
