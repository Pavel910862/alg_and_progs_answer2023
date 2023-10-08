package main

import "fmt"
    
func main() {

    var x int;
    var count = 0;
    
    fmt.Scan(&x);

    for x != 1{
        if x%2==0{
            x = x/2;
            count +=1;
        }else{
            x = 3*x+1;
            count +=1;
        }
    }
    fmt.Println(count);
}
