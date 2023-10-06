package main
import (
    "fmt"
    "math"
    )
    
func main() {
    
    var per_y, top, dub float64;
    per_y = 0.5 * 365;
    top = (per_y / 32); 
    dub = (per_y / 20); 
    fmt.Println(per_y, " ", math.Ceil(top), " ", math.Ceil(dub));
}
