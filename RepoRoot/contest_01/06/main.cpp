package main
import (
    "fmt"
    "os"
    )
    
func main() {
    
    var count, five_th, one_th, five_h, two_h, one_h int64;
    var ost_five_th, ost_one_th, ost_five_h, ost_two_h int64;
    
    fmt.Fscan(os.Stdin, &count);
    five_th = count / 5000;
    ost_five_th = count % 5000;
   
    one_th = ost_five_th / 1000;    
    ost_one_th = ost_five_th % 1000;
    
    five_h = ost_one_th / 500;   
    ost_five_h = ost_one_th % 500;
   
    two_h = ost_five_h / 200;    
    ost_two_h = ost_five_h % 200;
    
    one_h = ost_two_h / 100;
    
    fmt.Println(five_th, " ", one_th, " ",  five_h, " ", two_h, " ", one_h);
}
