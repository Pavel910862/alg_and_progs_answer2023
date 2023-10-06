package main
import (
    "fmt"
    "os"
)

func main() {
    
    var a, b float32;
    fmt.Fscan(os.Stdin, &a);
    fmt.Fscan(os.Stdin, &b);
    var c = a * b;
    fmt.Println(c);
}
