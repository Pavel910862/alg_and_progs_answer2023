// костыли, зато решил, причесать после
//Printf печатате с отступами %-4 выравнивание по левому краю
//Print без %d
package main

import "fmt"

func main() {

	var r, c int
	var k = 1
	var i = 1
	var j = 1

	fmt.Scan(&r, &c)

	fmt.Print("    ", "|")

	for k = 1; k < c+1; k++ {
		fmt.Printf("%4d", k)
	}
	fmt.Printf("\n")
	fmt.Printf("   ")

	for k = 1; k < c*4+3; k++ {
		fmt.Printf("-")
	}
	fmt.Printf("\n")

	for i = 1; i <= r; i++ {
		fmt.Printf("%4d", i)
		fmt.Print("|")
		for j = 1; j <= c; j++ {
			fmt.Printf("%4d", i*j)
		}
		fmt.Printf("\n")
	}

}
